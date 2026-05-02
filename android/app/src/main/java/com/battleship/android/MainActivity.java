package com.battleship.android;

import org.libsdl.app.SDLActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.provider.DocumentsContract;
import android.util.Log;
import android.widget.Toast;
import android.app.AlertDialog;
import java.io.File;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.concurrent.CountDownLatch;
import androidx.documentfile.provider.DocumentFile;

import android.view.View;
import android.view.KeyEvent;
import android.content.pm.ActivityInfo;
import android.os.Build;
import androidx.core.view.WindowCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.core.view.WindowInsetsControllerCompat;

public class MainActivity extends SDLActivity {
static {
    System.loadLibrary("BattleShip");
}

// ===== Constants / Prefs =====
private static final String PREFS = "com.battleship.android.prefs";
private static final String KEY_USER_FOLDER_URI = "user_folder_uri";
private static final String TAG = "MainActivity";
private static final int REQ_PICK_FOLDER = 1001;
private static final int REQ_PICK_BATTLESHIP_O2R    = 1002;

// ===== State =====
SharedPreferences preferences;
private static final CountDownLatch setupLatch = new CountDownLatch(1);
private Uri userFolderUri; // Persisted SAF tree URI

// ===== Save dir / engine root (must match SDL_AndroidGetExternalStoragePath) =====
public static String getSaveDir() {
    Context ctx = SDLActivity.getContext();
    File ext = ctx.getExternalFilesDir(null);
    File root = ext != null ? ext : ctx.getFilesDir();
    if (!root.exists()) root.mkdirs();
    Log.i(TAG, "getSaveDir -> " + root.getAbsolutePath());
    return root.getAbsolutePath();
}

/**
 * Same root as {@code Ship::Context::GetAppDirectoryPath()} / {@code SDL_AndroidGetExternalStoragePath}
 * on Android. Native code looks here for {@code BattleShip.o2r}, not {@link Context#getFilesDir()}.
 */
private File getEngineStorageDir() {
    File ext = getExternalFilesDir(null);
    return ext != null ? ext : getFilesDir();
}

private Uri getUserFolderUri() {
    String s = preferences.getString(KEY_USER_FOLDER_URI, null);
    return (s != null) ? Uri.parse(s) : null;
}

private void setUserFolderUri(Uri uri) {
    preferences.edit().putString(KEY_USER_FOLDER_URI, uri != null ? uri.toString() : null).apply();
}

private String getUserFolderPath() {
    if (userFolderUri == null) return null;
    try {
        String treeId = DocumentsContract.getTreeDocumentId(userFolderUri);
        // Check if it's external storage
        if (treeId.startsWith("primary:")) {
            String relativePath = treeId.substring("primary:".length());
            File externalStorage = Environment.getExternalStorageDirectory();
            return new File(externalStorage, relativePath).getAbsolutePath();
        }
        Log.w(TAG, "Could not extract path from URI: " + userFolderUri);
        return null;
    } catch (Exception e) {
        Log.e(TAG, "Error extracting path from URI", e);
        return null;
    }
}

private void syncModsFromUserFolder() {
    try {
        DocumentFile userRoot = DocumentFile.fromTreeUri(this, userFolderUri);
        if (userRoot == null) return;

        DocumentFile userModsFolder = userRoot.findFile("mods");
        if (userModsFolder == null || !userModsFolder.isDirectory()) {
            Log.i(TAG, "No mods folder found in user directory");
            return;
        }

        // Prefer external app-specific storage so the engine (which uses SDL_AndroidGetExternalStoragePath)
        // can discover mods at /Android/data/<pkg>/files/mods. Fallback to internal if external is unavailable.
        File targetRoot = getExternalFilesDir(null);
        if (targetRoot == null) {
            Log.w(TAG, "External files dir is null, falling back to internal files dir for mods");
            targetRoot = getFilesDir();
        }
        File targetModsFolder = new File(targetRoot, "mods");
        if (!targetModsFolder.exists()) {
            targetModsFolder.mkdirs();
        }

        // Clear existing mods in target storage first
        clearDirectory(targetModsFolder);

        // Copy all files from user mods folder to target mods folder
        copyModsRecursively(userModsFolder, targetModsFolder);
        Log.i(TAG, "Mods synced from user folder to: " + targetModsFolder.getAbsolutePath());
    } catch (Exception e) {
        Log.e(TAG, "Error syncing mods from user folder", e);
    }
}

private void clearDirectory(File dir) {
    if (dir.exists() && dir.isDirectory()) {
        File[] files = dir.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.isDirectory()) {
                    clearDirectory(file);
                }
                file.delete();
            }
        }
    }
}

private void copyModsRecursively(DocumentFile sourceDir, File destDir) {
    try {
        DocumentFile[] files = sourceDir.listFiles();
        if (files == null) return;

        for (DocumentFile file : files) {
            String fileName = file.getName();
            if (fileName == null) continue;

            File destFile = new File(destDir, fileName);
            if (file.isDirectory()) {
                // Create directory and recurse
                destFile.mkdirs();
                copyModsRecursively(file, destFile);
            } else {
                // Copy file
                try (InputStream in = getContentResolver().openInputStream(file.getUri());
                     FileOutputStream out = new FileOutputStream(destFile)) {
                    byte[] buf = new byte[8192];
                    int r;
                    while ((r = in.read(buf)) != -1) { 
                        out.write(buf, 0, r); 
                    }
                    out.flush();
                    Log.i(TAG, "Copied mod file: " + fileName);
                } catch (IOException e) {
                    Log.e(TAG, "Failed to copy mod file: " + fileName, e);
                }
            }
        }
    } catch (Exception e) {
        Log.e(TAG, "Error in copyModsRecursively", e);
    }
}

// ===== Lifecycle =====
@Override
protected void onCreate(Bundle savedInstanceState) {
    preferences = getSharedPreferences(PREFS, Context.MODE_PRIVATE);
    userFolderUri = getUserFolderUri();

    super.onCreate(savedInstanceState);

    /* Immersive bars: cannot use PhoneWindow.getInsetsController() here — DecorView
     * is often still null until after layout/window focus. Defer + onWindowFocusChanged. */
    final View contentRoot = findViewById(android.R.id.content);
    if (contentRoot != null) {
        contentRoot.post(this::enableImmersiveMode);
    }

    // Seed engine storage (external app files dir) from APK assets when present
    seedInternalFromAssetsIfPresent();

    File engineRoot = getEngineStorageDir();
    File internalOnly = getFilesDir();
    File external = getExternalFilesDir(null);
    Log.i(TAG, "Engine storage (o2r path): " + engineRoot);
    Log.i(TAG, "Internal files dir: " + internalOnly);
    Log.i(TAG, "External files dir: " + external);

    // Check for BattleShip.o2r where native code reads it (engine root)
    File internalBattleShipO2r = new File(engineRoot, "BattleShip.o2r");

    // If not in engine dir, check if it exists in user's chosen folder and copy it
    if (!internalBattleShipO2r.exists() && userFolderUri != null) {
        DocumentFile userRoot = DocumentFile.fromTreeUri(this, userFolderUri);
        if (userRoot != null) {
            DocumentFile userBattleShipO2r = userRoot.findFile("BattleShip.o2r");
            if (userBattleShipO2r != null && userBattleShipO2r.exists()) {
                Log.i(TAG, "Found BattleShip.o2r in user folder, copying to internal storage");
                try (InputStream in = getContentResolver().openInputStream(userBattleShipO2r.getUri());
                     FileOutputStream out = new FileOutputStream(internalBattleShipO2r)) {
                    byte[] buf = new byte[8192];
                    int r;
                    while ((r = in.read(buf)) != -1) { 
                        out.write(buf, 0, r); 
                    }
                    out.flush();
                    out.getFD().sync();
                    Log.i(TAG, "BattleShip.o2r copied from user folder to internal storage");
                
} catch (IOException e) {
                    Log.e(TAG, "Failed to copy BattleShip.o2r from user folder", e);
                }
            }
        }
    }

    // Always sync mods folder from user's chosen folder to internal storage
    if (userFolderUri != null) {
        syncModsFromUserFolder();
    }

    // Now check if BattleShip.o2r exists in engine storage
    if (!internalBattleShipO2r.exists()) {
        Log.i(TAG, "BattleShip.o2r not found under engine storage. Prompting for folder.");
        if (userFolderUri == null) {
            // First time - need to select folder
            promptForUserFolder();
        } else {
            // Folder already selected but no ROM - show file not found dialog
            showPortraitDialog("BattleShip.o2r not found in selected folder",
                "Pick an existing BattleShip.o2r (generate on PC with the desktop build's ExtractAssets), or place it in the app folder.",
                DialogActivity.DIALOG_TYPE_FILE_NOT_FOUND);
        }
    } else {
        Log.i(TAG, "BattleShip.o2r found in engine storage, game should start normally.");
    }
    
    // Signal to C++ that setup is complete
    setupLatch.countDown();
}

public static void waitForSetupFromNative() {
    try { 
        setupLatch.await(); 
    } catch (InterruptedException ignored) {
        Log.w(TAG, "waitForSetupFromNative interrupted");
    }
}

// ===== Asset seeding (optional, safe if assets not present) =====
private boolean assetExists(String name) {
    try { 
        getAssets().open(name).close(); 
        return true; 
    } catch (IOException e) { 
        return false; 
    }
}

private boolean assetDirExists(String dir) {
    try { 
        String[] list = getAssets().list(dir); 
        return list != null && list.length > 0; 
    } catch (IOException e) { 
        return false; 
    }
}

private void migrateLegacyInternalFilesToEngineDir(File engineRoot) {
    final File legacy = getFilesDir();
    if (legacy.getAbsolutePath().equals(engineRoot.getAbsolutePath())) {
        return;
    }
    final String[] topFiles = {
        "BattleShip.o2r", "f3d.o2r", "ssb64.o2r", "gamecontrollerdb.txt", "controllerdb.txt"
    };
    for (String name : topFiles) {
        File src = new File(legacy, name);
        File dst = new File(engineRoot, name);
        if (!src.exists() || dst.exists()) {
            continue;
        }
        try (InputStream in = new FileInputStream(src);
             FileOutputStream out = new FileOutputStream(dst)) {
            byte[] buf = new byte[8192];
            int r;
            while ((r = in.read(buf)) != -1) {
                out.write(buf, 0, r);
            }
            out.flush();
            out.getFD().sync();
            Log.i(TAG, "Migrated " + name + " from internal files dir -> " + dst.getAbsolutePath());
        } catch (IOException e) {
            Log.e(TAG, "Failed to migrate " + name, e);
        }
    }
}

private void seedInternalFromAssetsIfPresent() {
    File engineRoot = getEngineStorageDir();
    if (!engineRoot.exists()) {
        engineRoot.mkdirs();
    }
    migrateLegacyInternalFilesToEngineDir(engineRoot);

    // Prefer the real name: gamecontrollerdb.txt (but accept controllerdb.txt asset if that's what you ship)
    File gcdb = new File(engineRoot, "gamecontrollerdb.txt");
    File cdb  = new File(engineRoot, "controllerdb.txt");
    if (!gcdb.exists() && !cdb.exists()) {
        if (assetExists("gamecontrollerdb.txt")) {
            copyAssetFile("gamecontrollerdb.txt", gcdb);
        } else if (assetExists("controllerdb.txt")) {
            copyAssetFile("controllerdb.txt", cdb);
        } else {
            Log.i(TAG, "No controller DB asset shipped.");
        }
    }

    File f3d = new File(engineRoot, "f3d.o2r");
    if (!f3d.exists() && assetExists("f3d.o2r")) {
        Log.i(TAG, "Copying f3d.o2r from assets to internal");
        copyAssetFile("f3d.o2r", f3d);
    }

    File battleShipPackaged = new File(engineRoot, "BattleShip.o2r");
    if (!battleShipPackaged.exists() && assetExists("BattleShip.o2r")) {
        Log.i(TAG, "Copying BattleShip.o2r from assets to internal");
        copyAssetFile("BattleShip.o2r", battleShipPackaged);
    }

    File ssb64Port = new File(engineRoot, "ssb64.o2r");
    Log.i(TAG, "Checking ssb64.o2r - exists in engine dir: " + ssb64Port.exists() + ", exists in assets: " + assetExists("ssb64.o2r"));
    if (!ssb64Port.exists() && assetExists("ssb64.o2r")) {
        Log.i(TAG, "Copying ssb64.o2r from assets to internal");
        copyAssetFile("ssb64.o2r", ssb64Port);
    } else if (!ssb64Port.exists()) {
        Log.w(TAG, "ssb64.o2r not found in assets - this might be expected for development builds");
        // List available assets for debugging
        try {
            String[] assets = getAssets().list("");
            Log.i(TAG, "Available assets:");
            for (String asset : assets) {
                Log.i(TAG, "  - " + asset);
            }
        } catch (IOException e) {
            Log.e(TAG, "Error listing assets", e);
        }
    }

    File modsDir = new File(engineRoot, "mods");
    if (!modsDir.exists() && assetDirExists("mods")) {
        copyAssetFolderRecursive("mods", modsDir);
    }
}

private void copyAssetFile(String assetName, File destFile) {
    try {
        File parent = destFile.getParentFile();
        if (parent != null && !parent.exists()) parent.mkdirs();

        try (InputStream in = getAssets().open(assetName);
             FileOutputStream out = new FileOutputStream(destFile)) {
            byte[] buffer = new byte[8192];
            int read;
            long total = 0;
            while ((read = in.read(buffer)) != -1) {
                out.write(buffer, 0, read);
                total += read;
            }
            out.flush();
            out.getFD().sync();
            Log.i(TAG, "Seeded asset " + assetName + " (" + total + " bytes) -> " + destFile.getAbsolutePath());
        }
    } catch (IOException e) {
        Log.e(TAG, "copyAssetFile failed for " + assetName, e);
    }
}

private void copyAssetFolderRecursive(String assetDir, File destDir) {
    try {
        if (!destDir.exists()) destDir.mkdirs();

        String[] kids = getAssets().list(assetDir);
        if (kids == null) return;

        for (String name : kids) {
            String assetPath = assetDir + "/" + name;
            String[] sub = getAssets().list(assetPath);
            if (sub != null && sub.length > 0) {
                copyAssetFolderRecursive(assetPath, new File(destDir, name));
            } else {
                copyAssetFile(assetPath, new File(destDir, name));
            }
        }
        Log.i(TAG, "Seeded asset dir " + assetDir + " -> " + destDir.getAbsolutePath());
    } catch (IOException e) {
        Log.e(TAG, "copyAssetFolderRecursive failed for " + assetDir, e);
    }
}

// ===== UI helpers =====
private void showPortraitDialog(String title, String message, int dialogType) {
    Intent intent = new Intent(this, DialogActivity.class);
    intent.putExtra(DialogActivity.EXTRA_TITLE, title);
    intent.putExtra(DialogActivity.EXTRA_MESSAGE, message);
    intent.putExtra(DialogActivity.EXTRA_DIALOG_TYPE, dialogType);
    intent.putExtra(DialogActivity.EXTRA_CANCELABLE, false);
    startActivityForResult(intent, dialogType);
}

private void showToast(String msg) {
    runOnUiThread(() -> Toast.makeText(this, msg, Toast.LENGTH_SHORT).show());
}

private void restartApp() {
    try {
        Intent i = getPackageManager().getLaunchIntentForPackage(getPackageName());
        if (i != null) {
            i.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_NEW_TASK);
            startActivity(i);
            finish();
            System.exit(0);
        }
    } catch (Exception e) {
        Log.e(TAG, "restartApp", e);
        showToast("Please restart the app manually");
    }
}

// ===== Folder / File pickers =====
private void promptForUserFolder() {
    showPortraitDialog("Choose Your Folder", 
        "Select a folder for your BattleShip.o2r file and mods location. This will be your main BattleShip folder where you can add mods and manage game files.",
        DialogActivity.DIALOG_TYPE_FOLDER_PROMPT);
}

public void openFolderPicker() {
    Intent i = new Intent(Intent.ACTION_OPEN_DOCUMENT_TREE);
    i.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION
        | Intent.FLAG_GRANT_WRITE_URI_PERMISSION
        | Intent.FLAG_GRANT_PERSISTABLE_URI_PERMISSION
        | Intent.FLAG_GRANT_PREFIX_URI_PERMISSION);
    startActivityForResult(i, REQ_PICK_FOLDER);
}

public void openFilePickerForBattleShipO2r() {
    Intent i = new Intent(Intent.ACTION_OPEN_DOCUMENT);
    i.setType("*/*");
    i.addCategory(Intent.CATEGORY_OPENABLE);
    i.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION
        | Intent.FLAG_GRANT_PERSISTABLE_URI_PERMISSION);
    startActivityForResult(i, REQ_PICK_BATTLESHIP_O2R);
}

// ===== Activity result =====
@Override
protected void onActivityResult(int requestCode, int resultCode, Intent data) {
    super.onActivityResult(requestCode, resultCode, data);

    Log.i(TAG, "onActivityResult: requestCode=" + requestCode + ", resultCode=" + resultCode);

    // Handle DialogActivity results
    if (requestCode == DialogActivity.DIALOG_TYPE_FOLDER_PROMPT && resultCode == DialogActivity.RESULT_FOLDER_PICKER) {
        Log.i(TAG, "Opening folder picker");
        openFolderPicker();
        return;
    }
    if (requestCode == DialogActivity.DIALOG_TYPE_FILE_NOT_FOUND) {
        if (resultCode == DialogActivity.RESULT_FILE_PICKER) {
            Log.i(TAG, "Opening file picker for BattleShip.o2r");
            openFilePickerForBattleShipO2r();
        }
        return;
    }
    if ((requestCode == DialogActivity.DIALOG_TYPE_COPY_COMPLETE || requestCode == DialogActivity.DIALOG_TYPE_FILE_READY) 
        && resultCode == DialogActivity.RESULT_RESTART) {
        restartApp();
        return;
    }

    // Handle file/folder picker results
    if (resultCode != RESULT_OK || data == null) return;

    if (requestCode == REQ_PICK_FOLDER) {
        handleFolderSelection(data.getData(), data.getFlags());
    } else if (requestCode == REQ_PICK_BATTLESHIP_O2R) {
        handleRomFileSelection(data.getData());
    }
}

// ===== Folder selection & copy (SAF) =====
private void handleFolderSelection(Uri treeUri, int returnedFlags) {
    if (treeUri == null) { 
        showToast("No folder selected."); 
        return; 
    }

    // Persist read/write — try returned flags; if 0, try explicit
    try {
        final int permsReturned = returnedFlags &
            (Intent.FLAG_GRANT_READ_URI_PERMISSION | Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
        if (permsReturned != 0) {
            getContentResolver().takePersistableUriPermission(treeUri, permsReturned);
        } else {
            getContentResolver().takePersistableUriPermission(treeUri,
                Intent.FLAG_GRANT_READ_URI_PERMISSION | Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
        }
    } catch (Exception e) {
        Log.w(TAG, "takePersistableUriPermission failed (continuing with transient perms): " + e);
    }

    setUserFolderUri(treeUri);
    userFolderUri = treeUri;
    showToast("Folder selected.");

    DocumentFile userRoot = DocumentFile.fromTreeUri(this, treeUri);
    if (userRoot == null) {
        showToast("Cannot access the selected folder.");
        return;
    }

    if (!verifyWritable(userRoot)) {
        showToast("Can't write there. Try Downloads or a folder you create under Internal storage.");
        return;
    }

    boolean anyCopied = copyFromBestSourceToSaf(userRoot);

    // Check if BattleShip.o2r exists in the user's chosen folder and copy it to internal storage
    DocumentFile battleShipO2rInUserFolder = userRoot.findFile("BattleShip.o2r");
    if (battleShipO2rInUserFolder != null && battleShipO2rInUserFolder.exists()) {
        // Copy BattleShip.o2r to internal storage
        File internalBattleShipO2r = new File(getEngineStorageDir(), "BattleShip.o2r");
        try (InputStream in = getContentResolver().openInputStream(battleShipO2rInUserFolder.getUri());
             FileOutputStream out = new FileOutputStream(internalBattleShipO2r)) {
            byte[] buf = new byte[8192];
            int r;
            while ((r = in.read(buf)) != -1) { 
                out.write(buf, 0, r); 
            }
            out.flush();
            out.getFD().sync();
            Log.i(TAG, "BattleShip.o2r copied from user folder to internal storage during folder selection");
            
            
// Also sync mods
            syncModsFromUserFolder();
            
            showToast("Files copied. Game should start now.");
        } catch (IOException e) {
            Log.e(TAG, "Failed to copy BattleShip.o2r during folder selection", e);
            showToast("Failed to copy BattleShip.o2r: " + e.getMessage());
        }
    } else {
        runOnUiThread(() -> showPortraitDialog("BattleShip.o2r not found in selected folder",
                "Pick an existing BattleShip.o2r (generate on PC with the desktop build's ExtractAssets), or place it in the app folder.",
            DialogActivity.DIALOG_TYPE_FILE_NOT_FOUND));
    }
}

private boolean verifyWritable(DocumentFile dir) {
    try {
        DocumentFile tmp = dir.createFile("application/octet-stream", ".saf_write_test");
        if (tmp == null) return false;
        OutputStream os = getContentResolver().openOutputStream(tmp.getUri(), "w");
        if (os == null) return false;
        os.write(1);
        os.flush();
        os.close();
        tmp.delete();
        return true;
    } catch (Exception e) {
        Log.w(TAG, "verifyWritable failed: " + e);
        return false;
    }
}

// Choose best source root:
// 1) Internal files dir
// 2) External files dir root (legacy)
// 3) External files dir /BattleShip (legacy leftover)
private File chooseBestSourceRoot() {
    File engine = getEngineStorageDir();
    File internal = getFilesDir();
    File external = getExternalFilesDir(null);
    File legacy = (external != null) ? new File(external, "BattleShip") : null;

    boolean hasEngine = hasAnyTarget(engine);
    boolean hasInternal = hasAnyTarget(internal);
    boolean hasExternal = external != null && hasAnyTarget(external);
    boolean hasLegacy   = legacy != null && hasAnyTarget(legacy);

    Log.i(TAG, "Source check -> engine=" + hasEngine + ", internal=" + hasInternal + ", external=" + hasExternal + ", legacy=" + hasLegacy);

    if (hasEngine) return engine;
    if (hasExternal) return external;
    if (hasInternal) return internal;
    if (hasLegacy)   return legacy;
    return engine;
}

private boolean hasAnyTarget(File root) {
    if (root == null) return false;
    if (new File(root, "gamecontrollerdb.txt").exists()) return true;
    if (new File(root, "controllerdb.txt").exists())     return true; // tolerate alt name
    if (new File(root, "BattleShip.o2r").exists())       return true;
    if (new File(root, "ssb64.o2r").exists())            return true;
    File mods = new File(root, "mods");
    return mods.exists() && mods.isDirectory() && mods.listFiles() != null && mods.listFiles().length > 0;
}

private boolean copyFromBestSourceToSaf(DocumentFile userRoot) {
    File srcRoot = chooseBestSourceRoot();
    Log.i(TAG, "Copying from srcRoot=" + srcRoot);
    int copied = 0;

    // gamecontrollerdb.txt (prefer this name), fall back to controllerdb.txt if that's what exists
    File gcdb = new File(srcRoot, "gamecontrollerdb.txt");
    File cdb  = new File(srcRoot, "controllerdb.txt");
    if (gcdb.exists()) { 
        if (copyFileToTree(gcdb, userRoot, "text/plain")) copied++; 
    } else if (cdb.exists()) { 
        if (copyFileToTree(cdb, userRoot, "text/plain")) copied++; 
    } else Log.w(TAG, "No controller DB at " + srcRoot);

    // ssb64.o2r
    File ssb64Port = new File(srcRoot, "ssb64.o2r");
    if (ssb64Port.exists()) { 
        if (copyFileToTree(ssb64Port, userRoot, "application/octet-stream")) copied++; 
    } else Log.w(TAG, "No ssb64.o2r at " + srcRoot);

    File mainO2r = new File(srcRoot, "BattleShip.o2r");
    if (mainO2r.exists()) {
        if (copyFileToTree(mainO2r, userRoot, "application/octet-stream")) copied++;
    } else Log.w(TAG, "No BattleShip.o2r at " + srcRoot);

    File f3d = new File(srcRoot, "f3d.o2r");
    if (f3d.exists()) {
        if (copyFileToTree(f3d, userRoot, "application/octet-stream")) copied++;
    } else Log.w(TAG, "No f3d.o2r at " + srcRoot);

    // mods
    File modsSrc = new File(srcRoot, "mods");
    if (modsSrc.exists() && modsSrc.isDirectory()) {
        if (copyFolderToTree(modsSrc, userRoot)) copied++;
    } else Log.w(TAG, "No mods folder at " + srcRoot);

    if (copied > 0) showToast("Copied " + copied + " item(s) to selected folder.");
    else showToast("Nothing copied. Make sure files exist in app storage.");
    return copied > 0;
}

// When user picks BattleShip.o2r via SAF, copy into engine storage (native reads from here) AND user folder (for persistence)
private void handleRomFileSelection(Uri selectedFileUri) {
    if (selectedFileUri == null) { 
        showToast("No BattleShip.o2r selected."); 
        return; 
    }

    File dest = new File(getEngineStorageDir(), "BattleShip.o2r");
    showToast("Copying BattleShip.o2r...");

    try (InputStream in = getContentResolver().openInputStream(selectedFileUri);
         FileOutputStream out = new FileOutputStream(dest)) {
        byte[] buf = new byte[8192];
        int r;
        long total = 0;
        while ((r = in.read(buf)) != -1) { 
            out.write(buf, 0, r); 
            total += r; 
        }
        out.flush();
        out.getFD().sync();
        Log.i(TAG, "BattleShip.o2r copied to engine storage (" + total + " bytes): " + dest.getAbsolutePath());

        // Also copy to user's selected folder if one exists
        if (userFolderUri != null) {
            DocumentFile userRoot = DocumentFile.fromTreeUri(this, userFolderUri);
            if (userRoot != null) {
                if (copyFileToTree(dest, userRoot, "application/octet-stream")) {
                    Log.i(TAG, "BattleShip.o2r also copied to user's selected folder");
                } else {
                    Log.w(TAG, "Failed to copy BattleShip.o2r to user's selected folder");
                }
            }
        }

        runOnUiThread(() -> showPortraitDialog("BattleShip.o2r ready",
            "BattleShip.o2r copied. Restart to load the game.",
            DialogActivity.DIALOG_TYPE_FILE_READY));
    } catch (IOException e) {
        Log.e(TAG, "handleRomFileSelection", e);
        showToast("Failed to copy BattleShip.o2r: " + e.getMessage());
    }
}

// ===== SAF copy helpers =====
private boolean copyFileToTree(File src, DocumentFile dstParent, String mimeGuess) {
    try {
        // Overwrite if present
        DocumentFile existing = findChild(dstParent, src.getName());
        if (existing != null && existing.isFile()) existing.delete();

        String mime = (mimeGuess != null) ? mimeGuess : guessMime(src.getName());
        DocumentFile dest = dstParent.createFile(mime, src.getName());
        if (dest == null) {
            Log.e(TAG, "Failed to create file in tree: " + src.getName());
            return false;
        }

        try (InputStream in = new FileInputStream(src);
             OutputStream out = getContentResolver().openOutputStream(dest.getUri(), "w")) {
            if (out == null) throw new IOException("Null OutputStream from resolver");
            byte[] buf = new byte[8192];
            int r;
            long total = 0;
            while ((r = in.read(buf)) != -1) {
                out.write(buf, 0, r);
                total += r;
            }
            out.flush();
            Log.i(TAG, "Wrote " + total + " bytes → " + dest.getUri());
        }
        Log.i(TAG, "Copied to SAF: " + src.getAbsolutePath() + " → " + dest.getUri());
        return true;
    } catch (IOException e) {
        Log.e(TAG, "copyFileToTree " + src.getName(), e);
        showToast("Failed copying " + src.getName());
        return false;
    }
}

// Returns true if any item was copied
private boolean copyFolderToTree(File srcDir, DocumentFile dstParent) {
    boolean any = false;
    DocumentFile dstDir = ensureDirectory(dstParent, srcDir.getName());
    if (dstDir == null) return false;

    File[] kids = srcDir.listFiles();
    if (kids == null) return false;

    for (File kid : kids) {
        if (kid.isDirectory()) {
            if (copyFolderToTree(kid, dstDir)) any = true;
        } else {
            if (copyFileToTree(kid, dstDir, guessMime(kid.getName()))) any = true;
        }
    }
    return any;
}

private DocumentFile ensureDirectory(DocumentFile parent, String name) {
    DocumentFile existing = findChild(parent, name);
    if (existing != null && existing.isDirectory()) return existing;
    if (existing != null) existing.delete();
    return parent.createDirectory(name);
}

private DocumentFile findChild(DocumentFile parent, String name) {
    for (DocumentFile f : parent.listFiles()) {
        if (name.equals(f.getName())) return f;
    }
    return null;
}

private String guessMime(String name) {
    String n = name.toLowerCase();
    if (n.endsWith(".txt"))  return "text/plain";
    if (n.endsWith(".json")) return "application/json";
    return "application/octet-stream";
}

private void enableImmersiveMode() {
    final View root = getWindow().getDecorView();
    if (root == null) {
        return;
    }
    WindowInsetsControllerCompat controller =
        WindowCompat.getInsetsController(getWindow(), root);
    if (controller == null) {
        return;
    }
    controller.hide(WindowInsetsCompat.Type.statusBars()
        | WindowInsetsCompat.Type.navigationBars());
    controller.setSystemBarsBehavior(
        WindowInsetsControllerCompat.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE);
    /* Legacy fallback for devices where Compat leaves visibility unchanged */
    if (Build.VERSION.SDK_INT < Build.VERSION_CODES.R) {
        root.setSystemUiVisibility(
            View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
            | View.SYSTEM_UI_FLAG_FULLSCREEN
            | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
            | View.SYSTEM_UI_FLAG_LAYOUT_STABLE
            | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
            | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN);
    }
}

@Override
public void onWindowFocusChanged(boolean hasFocus) {
    super.onWindowFocusChanged(hasFocus);
    if (hasFocus) {
        enableImmersiveMode();
    }
}

/**
 * Controller Select ({@link KeyEvent#KEYCODE_BUTTON_SELECT}) should open the same ImGui UI as ESC on the PC
 * port. SDL maps it to gamepad BACK, but Dear ImGui's SDL backend often never sees that input because Ship
 * already owns the {@code SDL_GameController} handle — so inject Escape into SDL's key path here.
 */
@Override
public boolean dispatchKeyEvent(KeyEvent event) {
    if (event.getKeyCode() == KeyEvent.KEYCODE_BUTTON_SELECT) {
        final int action = event.getAction();
        if (action == KeyEvent.ACTION_DOWN && event.getRepeatCount() == 0) {
            onNativeKeyDown(KeyEvent.KEYCODE_ESCAPE);
            return true;
        }
        if (action == KeyEvent.ACTION_UP) {
            onNativeKeyUp(KeyEvent.KEYCODE_ESCAPE);
            return true;
        }
    }
    return super.dispatchKeyEvent(event);
}

@Override
public void onBackPressed() {
    // Show confirmation dialog before exiting
    new AlertDialog.Builder(this)
        .setTitle("Exit Game")
        .setMessage("Are you sure you want to quit?")
        .setPositiveButton("Yes", (dialog, which) -> {
            // Exit the app
            finish();
            System.exit(0);
        })
        .setNegativeButton("No", (dialog, which) -> {
            // Dismiss dialog and continue playing
            dialog.dismiss();
        })
        .setCancelable(true)
        .show();
}

}