#ifndef _RELOC_DATA_H_
#define _RELOC_DATA_H_

/*
 * reloc_data.h — AUTO-GENERATED. Run tools/generate_reloc_stubs.py to
 * regenerate after updating tools/reloc_data_symbols.us.txt or after
 * adding new decomp sources that reference `ll*` linker symbols.
 *
 * Every symbol in tools/reloc_data_symbols.us.txt (vendored from
 * ssb-decomp-re) is mirrored here as a #define holding the real
 * numeric value, so downstream tools (generate_yamls.py,
 * generate_reloc_table.py) always see the full name table even if
 * the individual symbol isn't referenced from src/ directly.
 *
 * Any `ll*` name referenced by src/ but missing from the table is
 * emitted as `((intptr_t)0)` with a trailing STUBBED marker so it
 * can be grep'd and triaged later — search the file for 'STUBBED'.
 *
 * Each symbol is emitted as a `#define` (rather than `extern intptr_t`)
 * so it works as a compile-time integer constant inside file-scope
 * struct initialisers, which C11 does not allow for external variables.
 */

#include <stdint.h>

/* 4230 symbols from the vendored table, 1770 extra stubs from src/. */

#define llRelocFileCount ((intptr_t)2132)
#define llMNCommonFileID ((intptr_t)0)
#define llMNMainFileID ((intptr_t)1)
#define llMN1PFileID ((intptr_t)2)
#define llMNIndexFileID ((intptr_t)3)
#define llMNOptionFileID ((intptr_t)4)
#define llMNDataFileID ((intptr_t)5)
#define llMNVSModeFileID ((intptr_t)6)
#define llMNVSOptionsFileID ((intptr_t)7)
#define llMNVSItemSwitchFileID ((intptr_t)8)
#define llMNMessageFileID ((intptr_t)9)
#define llSC1PChallengerFileID ((intptr_t)10)
#define llSC1PIntroFileID ((intptr_t)11)
#define llCharacterNamesFileID ((intptr_t)12)
#define llBonusPictureFileID ((intptr_t)13)
#define llBonusPicturePlatformFileID ((intptr_t)14)
#define llMNScreenAdjustFileID ((intptr_t)15)
#define llMNCharactersFileID ((intptr_t)16)
#define llMNPlayersCommonFileID ((intptr_t)17)
#define llMNPlayersGameModesFileID ((intptr_t)18)
#define llMNPlayersPortraitsFileID ((intptr_t)19)
#define llFTEmblemSpritesFileID ((intptr_t)20)
#define llMNSelectCommonFileID ((intptr_t)21)
#define llMNPlayersSpotlightFileID ((intptr_t)22)
#define llMNPlayers1PModeFileID ((intptr_t)23)
#define llMNPlayersDifficultyFileID ((intptr_t)24)
#define llFTStocksZakoFileID ((intptr_t)25)
#define llGRWallpaperTrainingBlackFileID ((intptr_t)26)
#define llGRWallpaperTrainingYellowFileID ((intptr_t)27)
#define llGRWallpaperTrainingBlueFileID ((intptr_t)28)
#define ll_29_FileID ((intptr_t)29)
#define llMNMapsFileID ((intptr_t)30)
#define llMNVSRecordMainFileID ((intptr_t)31)
#define llMNDataCommonFileID ((intptr_t)32)
#define llMNCommonFontsFileID ((intptr_t)33)
#define llMNVSResultsFileID ((intptr_t)34)
#define llFTEmblemModelsFileID ((intptr_t)35)
#define llIFCommonDigitsFileID ((intptr_t)36)
#define llIFCommonAnnounceCommonFileID ((intptr_t)37)
#define llIFCommonPlayerTagsFileID ((intptr_t)38)
#define ll_39_FileID ((intptr_t)39)
#define llLBTransitionAeroplaneFileID ((intptr_t)40)
#define llLBTransitionCheckFileID ((intptr_t)41)
#define llLBTransitionGakubuthiFileID ((intptr_t)42)
#define llLBTransitionKannonFileID ((intptr_t)43)
#define llLBTransitionStarFileID ((intptr_t)44)
#define llLBTransitionSudare1FileID ((intptr_t)45)
#define llLBTransitionSudare2FileID ((intptr_t)46)
#define ll_47_FileID ((intptr_t)47)
#define llLBTransitionBlockFileID ((intptr_t)48)
#define llLBTransitionRotScaleFileID ((intptr_t)49)
#define llLBTransitionCurtainFileID ((intptr_t)50)
#define llLBTransitionCameraFileID ((intptr_t)51)
#define llMVCommonFileID ((intptr_t)52)
#define llMVOpeningPortraitsSet1FileID ((intptr_t)53)
#define llMVOpeningPortraitsSet2FileID ((intptr_t)54)
#define llMVOpeningRunFileID ((intptr_t)55)
#define llMVOpeningRoomScene1FileID ((intptr_t)56)
#define llMVOpeningRoomScene2FileID ((intptr_t)57)
#define llMVOpeningRoomScene3FileID ((intptr_t)58)
#define llMVOpeningRoomScene4FileID ((intptr_t)59)
#define llMVOpeningRunMainFileID ((intptr_t)60)
#define llMVOpeningNewcomers1FileID ((intptr_t)61)
#define llMVOpeningNewcomers2FileID ((intptr_t)62)
#define llMVOpeningRoomTransitionFileID ((intptr_t)63)
#define llMVOpeningJungleFileID ((intptr_t)64)
#define llMVOpeningCommonFileID ((intptr_t)65)
#define llMVOpeningClashWallpaperFileID ((intptr_t)66)
#define llMVOpeningYosterFileID ((intptr_t)67)
#define llMVOpeningCliffFileID ((intptr_t)68)
#define llMVOpeningStandoffFileID ((intptr_t)69)
#define llMVOpeningStandoffWallpaperFileID ((intptr_t)70)
#define llMVOpeningYamabukiFileID ((intptr_t)71)
#define llMVOpeningClashFightersFileID ((intptr_t)72)
#define llMVOpeningSectorFileID ((intptr_t)73)
#define llMVOpeningSectorWallpaperFileID ((intptr_t)74)
#define llMVOpeningRunCrashFileID ((intptr_t)75)
#define llMVEndingFileID ((intptr_t)76)
#define llMNBackupClearFileID ((intptr_t)77)
#define llMNBackupClearHeaderOptionFileID ((intptr_t)78)
#define llMN1PContinueFileID ((intptr_t)79)
#define llSC1PStageClear1FileID ((intptr_t)80)
#define llSC1PStageClear2FileID ((intptr_t)81)
#define llIFCommonGameStatusFileID ((intptr_t)82)
#define llEFCommonEffects1FileID ((intptr_t)83)
#define llEFCommonEffects2FileID ((intptr_t)84)
#define llEFCommonEffects3FileID ((intptr_t)85)
#define ll_86_FileID ((intptr_t)86)
#define llIFCommonItemFileID ((intptr_t)87)
#define llStageDreamLandFileID ((intptr_t)88)
#define llStageZebesFileID ((intptr_t)89)
#define llMVOpeningRoomWallpaperFileID ((intptr_t)90)
#define ll_91_FileID ((intptr_t)91)
#define llStageJungleFileID ((intptr_t)92)
#define llStageYoshiFileID ((intptr_t)93)
#define llStagePokemonFileID ((intptr_t)94)
#define llStageCastleFileID ((intptr_t)95)
#define ll_96_FileID ((intptr_t)96)
#define ll_97_FileID ((intptr_t)97)
#define ll_98_FileID ((intptr_t)98)
#define llStageSectorFileID ((intptr_t)99)
#define ll_100_FileID ((intptr_t)100)
#define ll_101_FileID ((intptr_t)101)
#define ll_102_FileID ((intptr_t)102)
#define ll_103_FileID ((intptr_t)103)
#define ll_104_FileID ((intptr_t)104)
#define ll_105_FileID ((intptr_t)105)
#define ll_106_FileID ((intptr_t)106)
#define ll_107_FileID ((intptr_t)107)
#define ll_108_FileID ((intptr_t)108)
#define ll_109_FileID ((intptr_t)109)
#define ll_110_FileID ((intptr_t)110)
#define ll_111_FileID ((intptr_t)111)
#define ll_112_FileID ((intptr_t)112)
#define ll_113_FileID ((intptr_t)113)
#define ll_114_FileID ((intptr_t)114)
#define ll_115_FileID ((intptr_t)115)
#define ll_116_FileID ((intptr_t)116)
#define ll_117_FileID ((intptr_t)117)
#define ll_118_FileID ((intptr_t)118)
#define ll_119_FileID ((intptr_t)119)
#define ll_120_FileID ((intptr_t)120)
#define ll_121_FileID ((intptr_t)121)
#define ll_122_FileID ((intptr_t)122)
#define ll_123_FileID ((intptr_t)123)
#define ll_124_FileID ((intptr_t)124)
#define ll_125_FileID ((intptr_t)125)
#define ll_126_FileID ((intptr_t)126)
#define ll_127_FileID ((intptr_t)127)
#define ll_128_FileID ((intptr_t)128)
#define ll_129_FileID ((intptr_t)129)
#define ll_130_FileID ((intptr_t)130)
#define ll_131_FileID ((intptr_t)131)
#define ll_132_FileID ((intptr_t)132)
#define ll_133_FileID ((intptr_t)133)
#define ll_134_FileID ((intptr_t)134)
#define ll_135_FileID ((intptr_t)135)
#define llBonus2CommonFileID ((intptr_t)136)
#define ll_137_FileID ((intptr_t)137)
#define ll_138_FileID ((intptr_t)138)
#define ll_139_FileID ((intptr_t)139)
#define ll_140_FileID ((intptr_t)140)
#define ll_141_FileID ((intptr_t)141)
#define ll_142_FileID ((intptr_t)142)
#define ll_143_FileID ((intptr_t)143)
#define ll_144_FileID ((intptr_t)144)
#define ll_145_FileID ((intptr_t)145)
#define ll_146_FileID ((intptr_t)146)
#define ll_147_FileID ((intptr_t)147)
#define ll_148_FileID ((intptr_t)148)
#define ll_149_FileID ((intptr_t)149)
#define ll_150_FileID ((intptr_t)150)
#define llSC1PStageClear3FileID ((intptr_t)151)
#define ll_152_FileID ((intptr_t)152)
#define ll_153_FileID ((intptr_t)153)
#define ll_154_FileID ((intptr_t)154)
#define ll_155_FileID ((intptr_t)155)
#define ll_156_FileID ((intptr_t)156)
#define ll_157_FileID ((intptr_t)157)
#define ll_158_FileID ((intptr_t)158)
#define ll_159_FileID ((intptr_t)159)
#define ll_160_FileID ((intptr_t)160)
#define llFoxSpecial3FileID ((intptr_t)161)
#define ll_162_FileID ((intptr_t)162)
#define llFTManagerCommonFileID ((intptr_t)163)
#define llIFCommonPlayerDamageFileID ((intptr_t)164)
#define llIFCommonTimerFileID ((intptr_t)165)
#define llIFCommonPlayerFileID ((intptr_t)166)
#define llMNTitleFileID ((intptr_t)167)
#define llMNTitleFireAnimFileID ((intptr_t)168)
#define llMNNoControllerFileID ((intptr_t)169)
#define llMNCongraKirbyBottomFileID ((intptr_t)170)
#define llMNCongraKirbyTopFileID ((intptr_t)171)
#define llMNCongraYoshiBottomFileID ((intptr_t)172)
#define llMNCongraYoshiTopFileID ((intptr_t)173)
#define llMNCongraPikachuBottomFileID ((intptr_t)174)
#define llMNCongraPikachuTopFileID ((intptr_t)175)
#define llMNCongraSamusBottomFileID ((intptr_t)176)
#define llMNCongraSamusTopFileID ((intptr_t)177)
#define llMNCongraLinkBottomFileID ((intptr_t)178)
#define llMNCongraLinkTopFileID ((intptr_t)179)
#define llMNCongraPurinBottomFileID ((intptr_t)180)
#define llMNCongraPurinTopFileID ((intptr_t)181)
#define llMNCongraCaptainBottomFileID ((intptr_t)182)
#define llMNCongraCaptainTopFileID ((intptr_t)183)
#define llMNCongraDonkeyBottomFileID ((intptr_t)184)
#define llMNCongraDonkeyTopFileID ((intptr_t)185)
#define llMNCongraMarioBottomFileID ((intptr_t)186)
#define llMNCongraMarioTopFileID ((intptr_t)187)
#define llMNCongraLuigiBottomFileID ((intptr_t)188)
#define llMNCongraLuigiTopFileID ((intptr_t)189)
#define llMNCongraFoxBottomFileID ((intptr_t)190)
#define llMNCongraFoxTopFileID ((intptr_t)191)
#define llMNCongraNessBottomFileID ((intptr_t)192)
#define llMNCongraNessTopFileID ((intptr_t)193)
#define llN64LogoFileID ((intptr_t)194)
#define llSCStaffrollFileID ((intptr_t)195)
#define llMNSoundTestFileID ((intptr_t)196)
#define llIFCommonBattlePauseFileID ((intptr_t)197)
#define llSCExplainGraphicsFileID ((intptr_t)198)
#define llSYKseg1ValidateFileID ((intptr_t)199)
#define llSYSignValidateFileID ((intptr_t)200)
#define ll_201_FileID ((intptr_t)201)
#define llMarioMainMotionFileID ((intptr_t)202)
#define llMarioMainFileID ((intptr_t)203)
#define llMarioSpecial1FileID ((intptr_t)204)
#define llMMarioMainMotionFileID ((intptr_t)205)
#define llMMarioMainFileID ((intptr_t)206)
#define llNMarioMainFileID ((intptr_t)207)
#define llFoxMainMotionFileID ((intptr_t)208)
#define llFoxMainFileID ((intptr_t)209)
#define llFoxSpecial1FileID ((intptr_t)210)
#define llNFoxMainFileID ((intptr_t)211)
#define llDonkeyMainMotionFileID ((intptr_t)212)
#define llDonkeyMainFileID ((intptr_t)213)
#define llNDonkeyMainFileID ((intptr_t)214)
#define llGDonkeyMainFileID ((intptr_t)215)
#define llSamusMainMotionFileID ((intptr_t)216)
#define llSamusMainFileID ((intptr_t)217)
#define llSamusSpecial1FileID ((intptr_t)218)
#define llNSamusMainFileID ((intptr_t)219)
#define llLuigiMainMotionFileID ((intptr_t)220)
#define llLuigiMainFileID ((intptr_t)221)
#define llLuigiSpecial1FileID ((intptr_t)222)
#define llNLuigiMainFileID ((intptr_t)223)
#define llLinkMainMotionFileID ((intptr_t)224)
#define llLinkMainFileID ((intptr_t)225)
#define llLinkSpecial1FileID ((intptr_t)226)
#define llNLinkMainFileID ((intptr_t)227)
#define llKirbyMainMotionFileID ((intptr_t)228)
#define llKirbyMainFileID ((intptr_t)229)
#define ll_230_FileID ((intptr_t)230)
#define llNKirbyMainFileID ((intptr_t)231)
#define llPurinMainMotionFileID ((intptr_t)232)
#define llPurinMainFileID ((intptr_t)233)
#define llNPurinMainFileID ((intptr_t)234)
#define llCaptainMainMotionFileID ((intptr_t)235)
#define llCaptainMainFileID ((intptr_t)236)
#define llNCaptainMainFileID ((intptr_t)237)
#define llNessMainMotionFileID ((intptr_t)238)
#define llNessMainFileID ((intptr_t)239)
#define llNessSpecial1FileID ((intptr_t)240)
#define llNNessMainFileID ((intptr_t)241)
#define llPikachuMainMotionFileID ((intptr_t)242)
#define llPikachuMainFileID ((intptr_t)243)
#define llPikachuSpecial1FileID ((intptr_t)244)
#define llNPikachuMainFileID ((intptr_t)245)
#define llYoshiMainMotionFileID ((intptr_t)246)
#define llYoshiMainFileID ((intptr_t)247)
#define llNYoshiMainFileID ((intptr_t)248)
#define llBossMainMotionFileID ((intptr_t)249)
#define llBossMainFileID ((intptr_t)250)
#define llITCommonDataFileID ((intptr_t)251)
#define llSCExplainMainFileID ((intptr_t)252)
#define ll_253_FileID ((intptr_t)253)
#define llSC1PTrainingModeFileID ((intptr_t)254)
#define llGRPupupuMapFileID ((intptr_t)255)
#define llGRPupupuSmallMapFileID ((intptr_t)256)
#define llGRZebesMapFileID ((intptr_t)257)
#define llGRPupupuTestMapFileID ((intptr_t)258)
#define llGRCastleMapFileID ((intptr_t)259)
#define llGRInishieMapFileID ((intptr_t)260)
#define llGRJungleMapFileID ((intptr_t)261)
#define llGRSectorMapFileID ((intptr_t)262)
#define llGRYosterMapFileID ((intptr_t)263)
#define llGRYamabukiMapFileID ((intptr_t)264)
#define llGRHyruleMapFileID ((intptr_t)265)
#define llGRLastMapFileID ((intptr_t)266)
#define llGRExplainMapFileID ((intptr_t)267)
#define llGRZakoMapFileID ((intptr_t)268)
#define llGRMetalMapFileID ((intptr_t)269)
#define llGRYosterSmallMapFileID ((intptr_t)270)
#define llGRBonus1MarioMapFileID ((intptr_t)271)
#define llGRBonus1FoxMapFileID ((intptr_t)272)
#define llGRBonus1DonkeyMapFileID ((intptr_t)273)
#define llGRBonus1SamusMapFileID ((intptr_t)274)
#define llGRBonus1LuigiMapFileID ((intptr_t)275)
#define llGRBonus1LinkMapFileID ((intptr_t)276)
#define llGRBonus1YoshiMapFileID ((intptr_t)277)
#define llGRBonus1CaptainMapFileID ((intptr_t)278)
#define llGRBonus1KirbyMapFileID ((intptr_t)279)
#define llGRBonus1PikachuMapFileID ((intptr_t)280)
#define llGRBonus1PurinMapFileID ((intptr_t)281)
#define llGRBonus1NessMapFileID ((intptr_t)282)
#define llGRBonus2MarioMapFileID ((intptr_t)283)
#define llGRBonus2FoxMapFileID ((intptr_t)284)
#define llGRBonus2DonkeyMapFileID ((intptr_t)285)
#define llGRBonus2SamusMapFileID ((intptr_t)286)
#define llGRBonus2LuigiMapFileID ((intptr_t)287)
#define llGRBonus2LinkMapFileID ((intptr_t)288)
#define llGRBonus2YoshiMapFileID ((intptr_t)289)
#define llGRBonus2CaptainMapFileID ((intptr_t)290)
#define llGRBonus2KirbyMapFileID ((intptr_t)291)
#define llGRBonus2PikachuMapFileID ((intptr_t)292)
#define llGRBonus2PurinMapFileID ((intptr_t)293)
#define llGRBonus2NessMapFileID ((intptr_t)294)
#define llGRBonus3MapFileID ((intptr_t)295)
#define llMarioModelFileID ((intptr_t)296)
#define llMarioSpecial3FileID ((intptr_t)297)
#define llMarioShieldPoseFileID ((intptr_t)298)
#define ll_299_FileID ((intptr_t)299)
#define llMMarioModelFileID ((intptr_t)300)
#define llNMarioModelFileID ((intptr_t)301)
#define ll_302_FileID ((intptr_t)302)
#define llNFoxModelFileID ((intptr_t)303)
#define llNYoshiModelFileID ((intptr_t)304)
#define llNKirbyModelFileID ((intptr_t)305)
#define llNPurinModelFileID ((intptr_t)306)
#define llNPikachuModelFileID ((intptr_t)307)
#define llNDonkeyModelFileID ((intptr_t)308)
#define llNSamusModelFileID ((intptr_t)309)
#define llNLinkModelFileID ((intptr_t)310)
#define llNCaptainModelFileID ((intptr_t)311)
#define llNNessModelFileID ((intptr_t)312)
#define llFoxModelFileID ((intptr_t)313)
#define llFoxShieldPoseFileID ((intptr_t)314)
#define ll_315_FileID ((intptr_t)315)
#define llFoxSpecial4FileID ((intptr_t)316)
#define llDonkeyModelFileID ((intptr_t)317)
#define llDonkeyShieldPoseFileID ((intptr_t)318)
#define llDkIconFileID ((intptr_t)319)
#define llSamusModelFileID ((intptr_t)320)
#define llSamusSpecial3FileID ((intptr_t)321)
#define llSamusShieldPoseFileID ((intptr_t)322)
#define llLuigiModelFileID ((intptr_t)323)
#define llLinkModelFileID ((intptr_t)324)
#define llLinkSpecial3FileID ((intptr_t)325)
#define ll_326_FileID ((intptr_t)326)
#define llLinkShieldPoseFileID ((intptr_t)327)
#define llKirbyModelFileID ((intptr_t)328)
#define llKirbyShieldPoseFileID ((intptr_t)329)
#define llPurinModelFileID ((intptr_t)330)
#define llPurinShieldPoseFileID ((intptr_t)331)
#define llCaptainModelFileID ((intptr_t)332)
#define llCaptainSpecial3FileID ((intptr_t)333)
#define llCaptainShieldPoseFileID ((intptr_t)334)
#define llNessModelFileID ((intptr_t)335)
#define llNessSpecial3FileID ((intptr_t)336)
#define llNessShieldPoseFileID ((intptr_t)337)
#define llYoshiModelFileID ((intptr_t)338)
#define llYoshiSpecial3FileID ((intptr_t)339)
#define llYoshiShieldPoseFileID ((intptr_t)340)
#define llPikachuModelFileID ((intptr_t)341)
#define llPikachuSpecial3FileID ((intptr_t)342)
#define llPikachuShieldPoseFileID ((intptr_t)343)
#define llBossModelFileID ((intptr_t)344)
#define llMasterHandIconFileID ((intptr_t)345)
#define llFoxSpecial2FileID ((intptr_t)346)
#define llPikachuSpecial2FileID ((intptr_t)347)
#define llKirbySpecial2FileID ((intptr_t)348)
#define llSamusSpecial2FileID ((intptr_t)349)
#define llCaptainSpecial2FileID ((intptr_t)350)
#define llPurinSpecial2FileID ((intptr_t)351)
#define llNessSpecial2FileID ((intptr_t)352)
#define llLinkSpecial2FileID ((intptr_t)353)
#define llYoshiSpecial2FileID ((intptr_t)354)
#define llDonkeySpecial2FileID ((intptr_t)355)
#define llMarioSpecial2FileID ((intptr_t)356)
#define ll_357_FileID ((intptr_t)357)
#define ll_358_FileID ((intptr_t)358)
#define ll_359_FileID ((intptr_t)359)
#define ll_360_FileID ((intptr_t)360)
#define ll_361_FileID ((intptr_t)361)
#define ll_362_FileID ((intptr_t)362)
#define ll_363_FileID ((intptr_t)363)
#define ll_364_FileID ((intptr_t)364)
#define ll_365_FileID ((intptr_t)365)
#define ll_366_FileID ((intptr_t)366)
#define ll_367_FileID ((intptr_t)367)
#define ll_368_FileID ((intptr_t)368)
#define ll_369_FileID ((intptr_t)369)
#define ll_370_FileID ((intptr_t)370)
#define ll_371_FileID ((intptr_t)371)
#define ll_372_FileID ((intptr_t)372)
#define ll_373_FileID ((intptr_t)373)
#define ll_374_FileID ((intptr_t)374)
#define ll_375_FileID ((intptr_t)375)
#define ll_376_FileID ((intptr_t)376)
#define ll_377_FileID ((intptr_t)377)
#define ll_378_FileID ((intptr_t)378)
#define ll_379_FileID ((intptr_t)379)
#define ll_380_FileID ((intptr_t)380)
#define ll_381_FileID ((intptr_t)381)
#define ll_382_FileID ((intptr_t)382)
#define ll_383_FileID ((intptr_t)383)
#define ll_384_FileID ((intptr_t)384)
#define ll_385_FileID ((intptr_t)385)
#define ll_386_FileID ((intptr_t)386)
#define ll_387_FileID ((intptr_t)387)
#define ll_388_FileID ((intptr_t)388)
#define ll_389_FileID ((intptr_t)389)
#define ll_390_FileID ((intptr_t)390)
#define ll_391_FileID ((intptr_t)391)
#define ll_392_FileID ((intptr_t)392)
#define ll_393_FileID ((intptr_t)393)
#define ll_394_FileID ((intptr_t)394)
#define ll_395_FileID ((intptr_t)395)
#define ll_396_FileID ((intptr_t)396)
#define ll_397_FileID ((intptr_t)397)
#define ll_398_FileID ((intptr_t)398)
#define ll_399_FileID ((intptr_t)399)
#define ll_400_FileID ((intptr_t)400)
#define ll_401_FileID ((intptr_t)401)
#define ll_402_FileID ((intptr_t)402)
#define ll_403_FileID ((intptr_t)403)
#define ll_404_FileID ((intptr_t)404)
#define ll_405_FileID ((intptr_t)405)
#define ll_406_FileID ((intptr_t)406)
#define ll_407_FileID ((intptr_t)407)
#define ll_408_FileID ((intptr_t)408)
#define ll_409_FileID ((intptr_t)409)
#define ll_410_FileID ((intptr_t)410)
#define ll_411_FileID ((intptr_t)411)
#define ll_412_FileID ((intptr_t)412)
#define ll_413_FileID ((intptr_t)413)
#define ll_414_FileID ((intptr_t)414)
#define ll_415_FileID ((intptr_t)415)
#define ll_416_FileID ((intptr_t)416)
#define ll_417_FileID ((intptr_t)417)
#define ll_418_FileID ((intptr_t)418)
#define ll_419_FileID ((intptr_t)419)
#define ll_420_FileID ((intptr_t)420)
#define ll_421_FileID ((intptr_t)421)
#define ll_422_FileID ((intptr_t)422)
#define ll_423_FileID ((intptr_t)423)
#define ll_424_FileID ((intptr_t)424)
#define ll_425_FileID ((intptr_t)425)
#define ll_426_FileID ((intptr_t)426)
#define ll_427_FileID ((intptr_t)427)
#define ll_428_FileID ((intptr_t)428)
#define ll_429_FileID ((intptr_t)429)
#define ll_430_FileID ((intptr_t)430)
#define ll_431_FileID ((intptr_t)431)
#define ll_432_FileID ((intptr_t)432)
#define ll_433_FileID ((intptr_t)433)
#define ll_434_FileID ((intptr_t)434)
#define ll_435_FileID ((intptr_t)435)
#define ll_436_FileID ((intptr_t)436)
#define ll_437_FileID ((intptr_t)437)
#define ll_438_FileID ((intptr_t)438)
#define ll_439_FileID ((intptr_t)439)
#define ll_440_FileID ((intptr_t)440)
#define ll_441_FileID ((intptr_t)441)
#define ll_442_FileID ((intptr_t)442)
#define ll_443_FileID ((intptr_t)443)
#define ll_444_FileID ((intptr_t)444)
#define ll_445_FileID ((intptr_t)445)
#define ll_446_FileID ((intptr_t)446)
#define ll_447_FileID ((intptr_t)447)
#define ll_448_FileID ((intptr_t)448)
#define ll_449_FileID ((intptr_t)449)
#define ll_450_FileID ((intptr_t)450)
#define ll_451_FileID ((intptr_t)451)
#define ll_452_FileID ((intptr_t)452)
#define ll_453_FileID ((intptr_t)453)
#define ll_454_FileID ((intptr_t)454)
#define ll_455_FileID ((intptr_t)455)
#define ll_456_FileID ((intptr_t)456)
#define ll_457_FileID ((intptr_t)457)
#define ll_458_FileID ((intptr_t)458)
#define ll_459_FileID ((intptr_t)459)
#define ll_460_FileID ((intptr_t)460)
#define ll_461_FileID ((intptr_t)461)
#define ll_462_FileID ((intptr_t)462)
#define ll_463_FileID ((intptr_t)463)
#define ll_464_FileID ((intptr_t)464)
#define ll_465_FileID ((intptr_t)465)
#define ll_466_FileID ((intptr_t)466)
#define ll_467_FileID ((intptr_t)467)
#define ll_468_FileID ((intptr_t)468)
#define ll_469_FileID ((intptr_t)469)
#define ll_470_FileID ((intptr_t)470)
#define ll_471_FileID ((intptr_t)471)
#define ll_472_FileID ((intptr_t)472)
#define ll_473_FileID ((intptr_t)473)
#define ll_474_FileID ((intptr_t)474)
#define ll_475_FileID ((intptr_t)475)
#define ll_476_FileID ((intptr_t)476)
#define ll_477_FileID ((intptr_t)477)
#define ll_478_FileID ((intptr_t)478)
#define ll_479_FileID ((intptr_t)479)
#define ll_480_FileID ((intptr_t)480)
#define ll_481_FileID ((intptr_t)481)
#define ll_482_FileID ((intptr_t)482)
#define ll_483_FileID ((intptr_t)483)
#define ll_484_FileID ((intptr_t)484)
#define ll_485_FileID ((intptr_t)485)
#define ll_486_FileID ((intptr_t)486)
#define ll_487_FileID ((intptr_t)487)
#define ll_488_FileID ((intptr_t)488)
#define ll_489_FileID ((intptr_t)489)
#define ll_490_FileID ((intptr_t)490)
#define ll_491_FileID ((intptr_t)491)
#define ll_492_FileID ((intptr_t)492)
#define ll_493_FileID ((intptr_t)493)
#define ll_494_FileID ((intptr_t)494)
#define ll_495_FileID ((intptr_t)495)
#define ll_496_FileID ((intptr_t)496)
#define ll_497_FileID ((intptr_t)497)
#define ll_498_FileID ((intptr_t)498)
#define llFTMarioAnimWaitFileID ((intptr_t)499)
#define ll_500_FileID ((intptr_t)500)
#define ll_501_FileID ((intptr_t)501)
#define ll_502_FileID ((intptr_t)502)
#define ll_503_FileID ((intptr_t)503)
#define ll_504_FileID ((intptr_t)504)
#define ll_505_FileID ((intptr_t)505)
#define ll_506_FileID ((intptr_t)506)
#define ll_507_FileID ((intptr_t)507)
#define ll_508_FileID ((intptr_t)508)
#define ll_509_FileID ((intptr_t)509)
#define ll_510_FileID ((intptr_t)510)
#define ll_511_FileID ((intptr_t)511)
#define ll_512_FileID ((intptr_t)512)
#define ll_513_FileID ((intptr_t)513)
#define ll_514_FileID ((intptr_t)514)
#define ll_515_FileID ((intptr_t)515)
#define ll_516_FileID ((intptr_t)516)
#define ll_517_FileID ((intptr_t)517)
#define ll_518_FileID ((intptr_t)518)
#define ll_519_FileID ((intptr_t)519)
#define ll_520_FileID ((intptr_t)520)
#define ll_521_FileID ((intptr_t)521)
#define ll_522_FileID ((intptr_t)522)
#define ll_523_FileID ((intptr_t)523)
#define ll_524_FileID ((intptr_t)524)
#define ll_525_FileID ((intptr_t)525)
#define ll_526_FileID ((intptr_t)526)
#define ll_527_FileID ((intptr_t)527)
#define ll_528_FileID ((intptr_t)528)
#define ll_529_FileID ((intptr_t)529)
#define ll_530_FileID ((intptr_t)530)
#define ll_531_FileID ((intptr_t)531)
#define ll_532_FileID ((intptr_t)532)
#define ll_533_FileID ((intptr_t)533)
#define ll_534_FileID ((intptr_t)534)
#define ll_535_FileID ((intptr_t)535)
#define ll_536_FileID ((intptr_t)536)
#define ll_537_FileID ((intptr_t)537)
#define ll_538_FileID ((intptr_t)538)
#define ll_539_FileID ((intptr_t)539)
#define ll_540_FileID ((intptr_t)540)
#define ll_541_FileID ((intptr_t)541)
#define ll_542_FileID ((intptr_t)542)
#define llFTMarioAnimDownBounceDFileID ((intptr_t)543)
#define ll_544_FileID ((intptr_t)544)
#define llFTMarioAnimDownStandDFileID ((intptr_t)545)
#define ll_546_FileID ((intptr_t)546)
#define ll_547_FileID ((intptr_t)547)
#define ll_548_FileID ((intptr_t)548)
#define ll_549_FileID ((intptr_t)549)
#define ll_550_FileID ((intptr_t)550)
#define ll_551_FileID ((intptr_t)551)
#define ll_552_FileID ((intptr_t)552)
#define ll_553_FileID ((intptr_t)553)
#define ll_554_FileID ((intptr_t)554)
#define ll_555_FileID ((intptr_t)555)
#define ll_556_FileID ((intptr_t)556)
#define ll_557_FileID ((intptr_t)557)
#define ll_558_FileID ((intptr_t)558)
#define ll_559_FileID ((intptr_t)559)
#define ll_560_FileID ((intptr_t)560)
#define ll_561_FileID ((intptr_t)561)
#define ll_562_FileID ((intptr_t)562)
#define ll_563_FileID ((intptr_t)563)
#define ll_564_FileID ((intptr_t)564)
#define ll_565_FileID ((intptr_t)565)
#define ll_566_FileID ((intptr_t)566)
#define ll_567_FileID ((intptr_t)567)
#define ll_568_FileID ((intptr_t)568)
#define ll_569_FileID ((intptr_t)569)
#define ll_570_FileID ((intptr_t)570)
#define ll_571_FileID ((intptr_t)571)
#define ll_572_FileID ((intptr_t)572)
#define ll_573_FileID ((intptr_t)573)
#define ll_574_FileID ((intptr_t)574)
#define ll_575_FileID ((intptr_t)575)
#define ll_576_FileID ((intptr_t)576)
#define ll_577_FileID ((intptr_t)577)
#define ll_578_FileID ((intptr_t)578)
#define ll_579_FileID ((intptr_t)579)
#define ll_580_FileID ((intptr_t)580)
#define ll_581_FileID ((intptr_t)581)
#define ll_582_FileID ((intptr_t)582)
#define ll_583_FileID ((intptr_t)583)
#define ll_584_FileID ((intptr_t)584)
#define ll_585_FileID ((intptr_t)585)
#define ll_586_FileID ((intptr_t)586)
#define ll_587_FileID ((intptr_t)587)
#define ll_588_FileID ((intptr_t)588)
#define ll_589_FileID ((intptr_t)589)
#define ll_590_FileID ((intptr_t)590)
#define ll_591_FileID ((intptr_t)591)
#define ll_592_FileID ((intptr_t)592)
#define ll_593_FileID ((intptr_t)593)
#define ll_594_FileID ((intptr_t)594)
#define ll_595_FileID ((intptr_t)595)
#define ll_596_FileID ((intptr_t)596)
#define ll_597_FileID ((intptr_t)597)
#define ll_598_FileID ((intptr_t)598)
#define ll_599_FileID ((intptr_t)599)
#define ll_600_FileID ((intptr_t)600)
#define ll_601_FileID ((intptr_t)601)
#define ll_602_FileID ((intptr_t)602)
#define ll_603_FileID ((intptr_t)603)
#define ll_604_FileID ((intptr_t)604)
#define ll_605_FileID ((intptr_t)605)
#define ll_606_FileID ((intptr_t)606)
#define ll_607_FileID ((intptr_t)607)
#define ll_608_FileID ((intptr_t)608)
#define ll_609_FileID ((intptr_t)609)
#define ll_610_FileID ((intptr_t)610)
#define ll_611_FileID ((intptr_t)611)
#define ll_612_FileID ((intptr_t)612)
#define ll_613_FileID ((intptr_t)613)
#define ll_614_FileID ((intptr_t)614)
#define ll_615_FileID ((intptr_t)615)
#define ll_616_FileID ((intptr_t)616)
#define ll_617_FileID ((intptr_t)617)
#define ll_618_FileID ((intptr_t)618)
#define ll_619_FileID ((intptr_t)619)
#define ll_620_FileID ((intptr_t)620)
#define ll_621_FileID ((intptr_t)621)
#define ll_622_FileID ((intptr_t)622)
#define ll_623_FileID ((intptr_t)623)
#define ll_624_FileID ((intptr_t)624)
#define ll_625_FileID ((intptr_t)625)
#define ll_626_FileID ((intptr_t)626)
#define ll_627_FileID ((intptr_t)627)
#define ll_628_FileID ((intptr_t)628)
#define ll_629_FileID ((intptr_t)629)
#define ll_630_FileID ((intptr_t)630)
#define ll_631_FileID ((intptr_t)631)
#define ll_632_FileID ((intptr_t)632)
#define ll_633_FileID ((intptr_t)633)
#define ll_634_FileID ((intptr_t)634)
#define ll_635_FileID ((intptr_t)635)
#define ll_636_FileID ((intptr_t)636)
#define ll_637_FileID ((intptr_t)637)
#define ll_638_FileID ((intptr_t)638)
#define ll_639_FileID ((intptr_t)639)
#define ll_640_FileID ((intptr_t)640)
#define ll_641_FileID ((intptr_t)641)
#define ll_642_FileID ((intptr_t)642)
#define ll_643_FileID ((intptr_t)643)
#define ll_644_FileID ((intptr_t)644)
#define ll_645_FileID ((intptr_t)645)
#define ll_646_FileID ((intptr_t)646)
#define ll_647_FileID ((intptr_t)647)
#define ll_648_FileID ((intptr_t)648)
#define ll_649_FileID ((intptr_t)649)
#define ll_650_FileID ((intptr_t)650)
#define ll_651_FileID ((intptr_t)651)
#define ll_652_FileID ((intptr_t)652)
#define ll_653_FileID ((intptr_t)653)
#define ll_654_FileID ((intptr_t)654)
#define ll_655_FileID ((intptr_t)655)
#define ll_656_FileID ((intptr_t)656)
#define ll_657_FileID ((intptr_t)657)
#define ll_658_FileID ((intptr_t)658)
#define ll_659_FileID ((intptr_t)659)
#define ll_660_FileID ((intptr_t)660)
#define ll_661_FileID ((intptr_t)661)
#define ll_662_FileID ((intptr_t)662)
#define ll_663_FileID ((intptr_t)663)
#define ll_664_FileID ((intptr_t)664)
#define ll_665_FileID ((intptr_t)665)
#define ll_666_FileID ((intptr_t)666)
#define ll_667_FileID ((intptr_t)667)
#define ll_668_FileID ((intptr_t)668)
#define ll_669_FileID ((intptr_t)669)
#define ll_670_FileID ((intptr_t)670)
#define ll_671_FileID ((intptr_t)671)
#define ll_672_FileID ((intptr_t)672)
#define ll_673_FileID ((intptr_t)673)
#define ll_674_FileID ((intptr_t)674)
#define ll_675_FileID ((intptr_t)675)
#define ll_676_FileID ((intptr_t)676)
#define ll_677_FileID ((intptr_t)677)
#define ll_678_FileID ((intptr_t)678)
#define ll_679_FileID ((intptr_t)679)
#define ll_680_FileID ((intptr_t)680)
#define ll_681_FileID ((intptr_t)681)
#define ll_682_FileID ((intptr_t)682)
#define ll_683_FileID ((intptr_t)683)
#define ll_684_FileID ((intptr_t)684)
#define ll_685_FileID ((intptr_t)685)
#define ll_686_FileID ((intptr_t)686)
#define ll_687_FileID ((intptr_t)687)
#define ll_688_FileID ((intptr_t)688)
#define ll_689_FileID ((intptr_t)689)
#define ll_690_FileID ((intptr_t)690)
#define ll_691_FileID ((intptr_t)691)
#define ll_692_FileID ((intptr_t)692)
#define ll_693_FileID ((intptr_t)693)
#define ll_694_FileID ((intptr_t)694)
#define ll_695_FileID ((intptr_t)695)
#define ll_696_FileID ((intptr_t)696)
#define ll_697_FileID ((intptr_t)697)
#define ll_698_FileID ((intptr_t)698)
#define ll_699_FileID ((intptr_t)699)
#define ll_700_FileID ((intptr_t)700)
#define ll_701_FileID ((intptr_t)701)
#define ll_702_FileID ((intptr_t)702)
#define ll_703_FileID ((intptr_t)703)
#define ll_704_FileID ((intptr_t)704)
#define ll_705_FileID ((intptr_t)705)
#define ll_706_FileID ((intptr_t)706)
#define ll_707_FileID ((intptr_t)707)
#define ll_708_FileID ((intptr_t)708)
#define ll_709_FileID ((intptr_t)709)
#define ll_710_FileID ((intptr_t)710)
#define ll_711_FileID ((intptr_t)711)
#define ll_712_FileID ((intptr_t)712)
#define ll_713_FileID ((intptr_t)713)
#define ll_714_FileID ((intptr_t)714)
#define ll_715_FileID ((intptr_t)715)
#define ll_716_FileID ((intptr_t)716)
#define ll_717_FileID ((intptr_t)717)
#define ll_718_FileID ((intptr_t)718)
#define ll_719_FileID ((intptr_t)719)
#define ll_720_FileID ((intptr_t)720)
#define ll_721_FileID ((intptr_t)721)
#define ll_722_FileID ((intptr_t)722)
#define ll_723_FileID ((intptr_t)723)
#define ll_724_FileID ((intptr_t)724)
#define ll_725_FileID ((intptr_t)725)
#define ll_726_FileID ((intptr_t)726)
#define ll_727_FileID ((intptr_t)727)
#define ll_728_FileID ((intptr_t)728)
#define ll_729_FileID ((intptr_t)729)
#define ll_730_FileID ((intptr_t)730)
#define ll_731_FileID ((intptr_t)731)
#define ll_732_FileID ((intptr_t)732)
#define ll_733_FileID ((intptr_t)733)
#define ll_734_FileID ((intptr_t)734)
#define ll_735_FileID ((intptr_t)735)
#define ll_736_FileID ((intptr_t)736)
#define ll_737_FileID ((intptr_t)737)
#define ll_738_FileID ((intptr_t)738)
#define ll_739_FileID ((intptr_t)739)
#define ll_740_FileID ((intptr_t)740)
#define ll_741_FileID ((intptr_t)741)
#define ll_742_FileID ((intptr_t)742)
#define ll_743_FileID ((intptr_t)743)
#define ll_744_FileID ((intptr_t)744)
#define ll_745_FileID ((intptr_t)745)
#define ll_746_FileID ((intptr_t)746)
#define ll_747_FileID ((intptr_t)747)
#define ll_748_FileID ((intptr_t)748)
#define ll_749_FileID ((intptr_t)749)
#define ll_750_FileID ((intptr_t)750)
#define ll_751_FileID ((intptr_t)751)
#define ll_752_FileID ((intptr_t)752)
#define ll_753_FileID ((intptr_t)753)
#define ll_754_FileID ((intptr_t)754)
#define ll_755_FileID ((intptr_t)755)
#define ll_756_FileID ((intptr_t)756)
#define ll_757_FileID ((intptr_t)757)
#define ll_758_FileID ((intptr_t)758)
#define ll_759_FileID ((intptr_t)759)
#define ll_760_FileID ((intptr_t)760)
#define ll_761_FileID ((intptr_t)761)
#define ll_762_FileID ((intptr_t)762)
#define ll_763_FileID ((intptr_t)763)
#define ll_764_FileID ((intptr_t)764)
#define ll_765_FileID ((intptr_t)765)
#define ll_766_FileID ((intptr_t)766)
#define ll_767_FileID ((intptr_t)767)
#define ll_768_FileID ((intptr_t)768)
#define ll_769_FileID ((intptr_t)769)
#define ll_770_FileID ((intptr_t)770)
#define ll_771_FileID ((intptr_t)771)
#define ll_772_FileID ((intptr_t)772)
#define ll_773_FileID ((intptr_t)773)
#define ll_774_FileID ((intptr_t)774)
#define ll_775_FileID ((intptr_t)775)
#define ll_776_FileID ((intptr_t)776)
#define ll_777_FileID ((intptr_t)777)
#define ll_778_FileID ((intptr_t)778)
#define ll_779_FileID ((intptr_t)779)
#define ll_780_FileID ((intptr_t)780)
#define ll_781_FileID ((intptr_t)781)
#define ll_782_FileID ((intptr_t)782)
#define ll_783_FileID ((intptr_t)783)
#define ll_784_FileID ((intptr_t)784)
#define ll_785_FileID ((intptr_t)785)
#define ll_786_FileID ((intptr_t)786)
#define ll_787_FileID ((intptr_t)787)
#define ll_788_FileID ((intptr_t)788)
#define ll_789_FileID ((intptr_t)789)
#define ll_790_FileID ((intptr_t)790)
#define ll_791_FileID ((intptr_t)791)
#define ll_792_FileID ((intptr_t)792)
#define ll_793_FileID ((intptr_t)793)
#define ll_794_FileID ((intptr_t)794)
#define ll_795_FileID ((intptr_t)795)
#define ll_796_FileID ((intptr_t)796)
#define ll_797_FileID ((intptr_t)797)
#define ll_798_FileID ((intptr_t)798)
#define ll_799_FileID ((intptr_t)799)
#define ll_800_FileID ((intptr_t)800)
#define ll_801_FileID ((intptr_t)801)
#define ll_802_FileID ((intptr_t)802)
#define ll_803_FileID ((intptr_t)803)
#define ll_804_FileID ((intptr_t)804)
#define ll_805_FileID ((intptr_t)805)
#define ll_806_FileID ((intptr_t)806)
#define ll_807_FileID ((intptr_t)807)
#define ll_808_FileID ((intptr_t)808)
#define ll_809_FileID ((intptr_t)809)
#define ll_810_FileID ((intptr_t)810)
#define ll_811_FileID ((intptr_t)811)
#define ll_812_FileID ((intptr_t)812)
#define ll_813_FileID ((intptr_t)813)
#define ll_814_FileID ((intptr_t)814)
#define ll_815_FileID ((intptr_t)815)
#define ll_816_FileID ((intptr_t)816)
#define ll_817_FileID ((intptr_t)817)
#define ll_818_FileID ((intptr_t)818)
#define ll_819_FileID ((intptr_t)819)
#define ll_820_FileID ((intptr_t)820)
#define ll_821_FileID ((intptr_t)821)
#define ll_822_FileID ((intptr_t)822)
#define ll_823_FileID ((intptr_t)823)
#define ll_824_FileID ((intptr_t)824)
#define ll_825_FileID ((intptr_t)825)
#define ll_826_FileID ((intptr_t)826)
#define ll_827_FileID ((intptr_t)827)
#define ll_828_FileID ((intptr_t)828)
#define ll_829_FileID ((intptr_t)829)
#define ll_830_FileID ((intptr_t)830)
#define ll_831_FileID ((intptr_t)831)
#define ll_832_FileID ((intptr_t)832)
#define ll_833_FileID ((intptr_t)833)
#define ll_834_FileID ((intptr_t)834)
#define ll_835_FileID ((intptr_t)835)
#define ll_836_FileID ((intptr_t)836)
#define ll_837_FileID ((intptr_t)837)
#define ll_838_FileID ((intptr_t)838)
#define ll_839_FileID ((intptr_t)839)
#define ll_840_FileID ((intptr_t)840)
#define ll_841_FileID ((intptr_t)841)
#define ll_842_FileID ((intptr_t)842)
#define ll_843_FileID ((intptr_t)843)
#define ll_844_FileID ((intptr_t)844)
#define ll_845_FileID ((intptr_t)845)
#define ll_846_FileID ((intptr_t)846)
#define ll_847_FileID ((intptr_t)847)
#define ll_848_FileID ((intptr_t)848)
#define ll_849_FileID ((intptr_t)849)
#define ll_850_FileID ((intptr_t)850)
#define ll_851_FileID ((intptr_t)851)
#define ll_852_FileID ((intptr_t)852)
#define ll_853_FileID ((intptr_t)853)
#define ll_854_FileID ((intptr_t)854)
#define ll_855_FileID ((intptr_t)855)
#define ll_856_FileID ((intptr_t)856)
#define ll_857_FileID ((intptr_t)857)
#define ll_858_FileID ((intptr_t)858)
#define ll_859_FileID ((intptr_t)859)
#define ll_860_FileID ((intptr_t)860)
#define ll_861_FileID ((intptr_t)861)
#define ll_862_FileID ((intptr_t)862)
#define ll_863_FileID ((intptr_t)863)
#define ll_864_FileID ((intptr_t)864)
#define ll_865_FileID ((intptr_t)865)
#define ll_866_FileID ((intptr_t)866)
#define ll_867_FileID ((intptr_t)867)
#define ll_868_FileID ((intptr_t)868)
#define ll_869_FileID ((intptr_t)869)
#define ll_870_FileID ((intptr_t)870)
#define ll_871_FileID ((intptr_t)871)
#define ll_872_FileID ((intptr_t)872)
#define ll_873_FileID ((intptr_t)873)
#define ll_874_FileID ((intptr_t)874)
#define ll_875_FileID ((intptr_t)875)
#define ll_876_FileID ((intptr_t)876)
#define ll_877_FileID ((intptr_t)877)
#define ll_878_FileID ((intptr_t)878)
#define ll_879_FileID ((intptr_t)879)
#define ll_880_FileID ((intptr_t)880)
#define ll_881_FileID ((intptr_t)881)
#define ll_882_FileID ((intptr_t)882)
#define ll_883_FileID ((intptr_t)883)
#define ll_884_FileID ((intptr_t)884)
#define ll_885_FileID ((intptr_t)885)
#define ll_886_FileID ((intptr_t)886)
#define ll_887_FileID ((intptr_t)887)
#define ll_888_FileID ((intptr_t)888)
#define ll_889_FileID ((intptr_t)889)
#define ll_890_FileID ((intptr_t)890)
#define ll_891_FileID ((intptr_t)891)
#define ll_892_FileID ((intptr_t)892)
#define ll_893_FileID ((intptr_t)893)
#define ll_894_FileID ((intptr_t)894)
#define ll_895_FileID ((intptr_t)895)
#define ll_896_FileID ((intptr_t)896)
#define ll_897_FileID ((intptr_t)897)
#define ll_898_FileID ((intptr_t)898)
#define ll_899_FileID ((intptr_t)899)
#define ll_900_FileID ((intptr_t)900)
#define ll_901_FileID ((intptr_t)901)
#define ll_902_FileID ((intptr_t)902)
#define ll_903_FileID ((intptr_t)903)
#define ll_904_FileID ((intptr_t)904)
#define ll_905_FileID ((intptr_t)905)
#define ll_906_FileID ((intptr_t)906)
#define ll_907_FileID ((intptr_t)907)
#define ll_908_FileID ((intptr_t)908)
#define ll_909_FileID ((intptr_t)909)
#define ll_910_FileID ((intptr_t)910)
#define ll_911_FileID ((intptr_t)911)
#define ll_912_FileID ((intptr_t)912)
#define ll_913_FileID ((intptr_t)913)
#define ll_914_FileID ((intptr_t)914)
#define ll_915_FileID ((intptr_t)915)
#define ll_916_FileID ((intptr_t)916)
#define ll_917_FileID ((intptr_t)917)
#define ll_918_FileID ((intptr_t)918)
#define ll_919_FileID ((intptr_t)919)
#define ll_920_FileID ((intptr_t)920)
#define ll_921_FileID ((intptr_t)921)
#define ll_922_FileID ((intptr_t)922)
#define ll_923_FileID ((intptr_t)923)
#define ll_924_FileID ((intptr_t)924)
#define ll_925_FileID ((intptr_t)925)
#define ll_926_FileID ((intptr_t)926)
#define ll_927_FileID ((intptr_t)927)
#define ll_928_FileID ((intptr_t)928)
#define ll_929_FileID ((intptr_t)929)
#define ll_930_FileID ((intptr_t)930)
#define ll_931_FileID ((intptr_t)931)
#define ll_932_FileID ((intptr_t)932)
#define ll_933_FileID ((intptr_t)933)
#define ll_934_FileID ((intptr_t)934)
#define ll_935_FileID ((intptr_t)935)
#define ll_936_FileID ((intptr_t)936)
#define ll_937_FileID ((intptr_t)937)
#define ll_938_FileID ((intptr_t)938)
#define ll_939_FileID ((intptr_t)939)
#define ll_940_FileID ((intptr_t)940)
#define ll_941_FileID ((intptr_t)941)
#define ll_942_FileID ((intptr_t)942)
#define ll_943_FileID ((intptr_t)943)
#define ll_944_FileID ((intptr_t)944)
#define ll_945_FileID ((intptr_t)945)
#define ll_946_FileID ((intptr_t)946)
#define ll_947_FileID ((intptr_t)947)
#define ll_948_FileID ((intptr_t)948)
#define ll_949_FileID ((intptr_t)949)
#define ll_950_FileID ((intptr_t)950)
#define ll_951_FileID ((intptr_t)951)
#define ll_952_FileID ((intptr_t)952)
#define ll_953_FileID ((intptr_t)953)
#define ll_954_FileID ((intptr_t)954)
#define ll_955_FileID ((intptr_t)955)
#define ll_956_FileID ((intptr_t)956)
#define ll_957_FileID ((intptr_t)957)
#define ll_958_FileID ((intptr_t)958)
#define ll_959_FileID ((intptr_t)959)
#define ll_960_FileID ((intptr_t)960)
#define ll_961_FileID ((intptr_t)961)
#define ll_962_FileID ((intptr_t)962)
#define ll_963_FileID ((intptr_t)963)
#define ll_964_FileID ((intptr_t)964)
#define ll_965_FileID ((intptr_t)965)
#define ll_966_FileID ((intptr_t)966)
#define ll_967_FileID ((intptr_t)967)
#define ll_968_FileID ((intptr_t)968)
#define ll_969_FileID ((intptr_t)969)
#define ll_970_FileID ((intptr_t)970)
#define ll_971_FileID ((intptr_t)971)
#define ll_972_FileID ((intptr_t)972)
#define ll_973_FileID ((intptr_t)973)
#define ll_974_FileID ((intptr_t)974)
#define ll_975_FileID ((intptr_t)975)
#define ll_976_FileID ((intptr_t)976)
#define ll_977_FileID ((intptr_t)977)
#define ll_978_FileID ((intptr_t)978)
#define ll_979_FileID ((intptr_t)979)
#define ll_980_FileID ((intptr_t)980)
#define ll_981_FileID ((intptr_t)981)
#define ll_982_FileID ((intptr_t)982)
#define ll_983_FileID ((intptr_t)983)
#define ll_984_FileID ((intptr_t)984)
#define ll_985_FileID ((intptr_t)985)
#define ll_986_FileID ((intptr_t)986)
#define ll_987_FileID ((intptr_t)987)
#define ll_988_FileID ((intptr_t)988)
#define ll_989_FileID ((intptr_t)989)
#define ll_990_FileID ((intptr_t)990)
#define ll_991_FileID ((intptr_t)991)
#define ll_992_FileID ((intptr_t)992)
#define ll_993_FileID ((intptr_t)993)
#define ll_994_FileID ((intptr_t)994)
#define ll_995_FileID ((intptr_t)995)
#define ll_996_FileID ((intptr_t)996)
#define ll_997_FileID ((intptr_t)997)
#define ll_998_FileID ((intptr_t)998)
#define ll_999_FileID ((intptr_t)999)
#define ll_1000_FileID ((intptr_t)1000)
#define ll_1001_FileID ((intptr_t)1001)
#define ll_1002_FileID ((intptr_t)1002)
#define ll_1003_FileID ((intptr_t)1003)
#define ll_1004_FileID ((intptr_t)1004)
#define ll_1005_FileID ((intptr_t)1005)
#define ll_1006_FileID ((intptr_t)1006)
#define ll_1007_FileID ((intptr_t)1007)
#define ll_1008_FileID ((intptr_t)1008)
#define ll_1009_FileID ((intptr_t)1009)
#define ll_1010_FileID ((intptr_t)1010)
#define ll_1011_FileID ((intptr_t)1011)
#define ll_1012_FileID ((intptr_t)1012)
#define ll_1013_FileID ((intptr_t)1013)
#define ll_1014_FileID ((intptr_t)1014)
#define ll_1015_FileID ((intptr_t)1015)
#define ll_1016_FileID ((intptr_t)1016)
#define ll_1017_FileID ((intptr_t)1017)
#define ll_1018_FileID ((intptr_t)1018)
#define ll_1019_FileID ((intptr_t)1019)
#define ll_1020_FileID ((intptr_t)1020)
#define ll_1021_FileID ((intptr_t)1021)
#define ll_1022_FileID ((intptr_t)1022)
#define ll_1023_FileID ((intptr_t)1023)
#define ll_1024_FileID ((intptr_t)1024)
#define ll_1025_FileID ((intptr_t)1025)
#define ll_1026_FileID ((intptr_t)1026)
#define ll_1027_FileID ((intptr_t)1027)
#define ll_1028_FileID ((intptr_t)1028)
#define ll_1029_FileID ((intptr_t)1029)
#define ll_1030_FileID ((intptr_t)1030)
#define ll_1031_FileID ((intptr_t)1031)
#define ll_1032_FileID ((intptr_t)1032)
#define ll_1033_FileID ((intptr_t)1033)
#define ll_1034_FileID ((intptr_t)1034)
#define ll_1035_FileID ((intptr_t)1035)
#define ll_1036_FileID ((intptr_t)1036)
#define ll_1037_FileID ((intptr_t)1037)
#define ll_1038_FileID ((intptr_t)1038)
#define ll_1039_FileID ((intptr_t)1039)
#define ll_1040_FileID ((intptr_t)1040)
#define ll_1041_FileID ((intptr_t)1041)
#define ll_1042_FileID ((intptr_t)1042)
#define ll_1043_FileID ((intptr_t)1043)
#define ll_1044_FileID ((intptr_t)1044)
#define ll_1045_FileID ((intptr_t)1045)
#define ll_1046_FileID ((intptr_t)1046)
#define ll_1047_FileID ((intptr_t)1047)
#define ll_1048_FileID ((intptr_t)1048)
#define ll_1049_FileID ((intptr_t)1049)
#define ll_1050_FileID ((intptr_t)1050)
#define ll_1051_FileID ((intptr_t)1051)
#define ll_1052_FileID ((intptr_t)1052)
#define ll_1053_FileID ((intptr_t)1053)
#define ll_1054_FileID ((intptr_t)1054)
#define ll_1055_FileID ((intptr_t)1055)
#define ll_1056_FileID ((intptr_t)1056)
#define ll_1057_FileID ((intptr_t)1057)
#define ll_1058_FileID ((intptr_t)1058)
#define ll_1059_FileID ((intptr_t)1059)
#define ll_1060_FileID ((intptr_t)1060)
#define ll_1061_FileID ((intptr_t)1061)
#define ll_1062_FileID ((intptr_t)1062)
#define ll_1063_FileID ((intptr_t)1063)
#define ll_1064_FileID ((intptr_t)1064)
#define ll_1065_FileID ((intptr_t)1065)
#define ll_1066_FileID ((intptr_t)1066)
#define ll_1067_FileID ((intptr_t)1067)
#define ll_1068_FileID ((intptr_t)1068)
#define ll_1069_FileID ((intptr_t)1069)
#define ll_1070_FileID ((intptr_t)1070)
#define ll_1071_FileID ((intptr_t)1071)
#define ll_1072_FileID ((intptr_t)1072)
#define ll_1073_FileID ((intptr_t)1073)
#define ll_1074_FileID ((intptr_t)1074)
#define ll_1075_FileID ((intptr_t)1075)
#define ll_1076_FileID ((intptr_t)1076)
#define ll_1077_FileID ((intptr_t)1077)
#define ll_1078_FileID ((intptr_t)1078)
#define ll_1079_FileID ((intptr_t)1079)
#define ll_1080_FileID ((intptr_t)1080)
#define ll_1081_FileID ((intptr_t)1081)
#define ll_1082_FileID ((intptr_t)1082)
#define ll_1083_FileID ((intptr_t)1083)
#define ll_1084_FileID ((intptr_t)1084)
#define ll_1085_FileID ((intptr_t)1085)
#define ll_1086_FileID ((intptr_t)1086)
#define ll_1087_FileID ((intptr_t)1087)
#define ll_1088_FileID ((intptr_t)1088)
#define ll_1089_FileID ((intptr_t)1089)
#define ll_1090_FileID ((intptr_t)1090)
#define ll_1091_FileID ((intptr_t)1091)
#define ll_1092_FileID ((intptr_t)1092)
#define ll_1093_FileID ((intptr_t)1093)
#define ll_1094_FileID ((intptr_t)1094)
#define ll_1095_FileID ((intptr_t)1095)
#define ll_1096_FileID ((intptr_t)1096)
#define ll_1097_FileID ((intptr_t)1097)
#define ll_1098_FileID ((intptr_t)1098)
#define ll_1099_FileID ((intptr_t)1099)
#define ll_1100_FileID ((intptr_t)1100)
#define ll_1101_FileID ((intptr_t)1101)
#define ll_1102_FileID ((intptr_t)1102)
#define ll_1103_FileID ((intptr_t)1103)
#define ll_1104_FileID ((intptr_t)1104)
#define ll_1105_FileID ((intptr_t)1105)
#define ll_1106_FileID ((intptr_t)1106)
#define ll_1107_FileID ((intptr_t)1107)
#define ll_1108_FileID ((intptr_t)1108)
#define ll_1109_FileID ((intptr_t)1109)
#define ll_1110_FileID ((intptr_t)1110)
#define ll_1111_FileID ((intptr_t)1111)
#define ll_1112_FileID ((intptr_t)1112)
#define ll_1113_FileID ((intptr_t)1113)
#define ll_1114_FileID ((intptr_t)1114)
#define ll_1115_FileID ((intptr_t)1115)
#define ll_1116_FileID ((intptr_t)1116)
#define ll_1117_FileID ((intptr_t)1117)
#define ll_1118_FileID ((intptr_t)1118)
#define ll_1119_FileID ((intptr_t)1119)
#define ll_1120_FileID ((intptr_t)1120)
#define ll_1121_FileID ((intptr_t)1121)
#define ll_1122_FileID ((intptr_t)1122)
#define ll_1123_FileID ((intptr_t)1123)
#define ll_1124_FileID ((intptr_t)1124)
#define ll_1125_FileID ((intptr_t)1125)
#define ll_1126_FileID ((intptr_t)1126)
#define ll_1127_FileID ((intptr_t)1127)
#define ll_1128_FileID ((intptr_t)1128)
#define ll_1129_FileID ((intptr_t)1129)
#define ll_1130_FileID ((intptr_t)1130)
#define ll_1131_FileID ((intptr_t)1131)
#define ll_1132_FileID ((intptr_t)1132)
#define ll_1133_FileID ((intptr_t)1133)
#define ll_1134_FileID ((intptr_t)1134)
#define ll_1135_FileID ((intptr_t)1135)
#define ll_1136_FileID ((intptr_t)1136)
#define ll_1137_FileID ((intptr_t)1137)
#define ll_1138_FileID ((intptr_t)1138)
#define ll_1139_FileID ((intptr_t)1139)
#define ll_1140_FileID ((intptr_t)1140)
#define ll_1141_FileID ((intptr_t)1141)
#define ll_1142_FileID ((intptr_t)1142)
#define ll_1143_FileID ((intptr_t)1143)
#define ll_1144_FileID ((intptr_t)1144)
#define ll_1145_FileID ((intptr_t)1145)
#define ll_1146_FileID ((intptr_t)1146)
#define ll_1147_FileID ((intptr_t)1147)
#define ll_1148_FileID ((intptr_t)1148)
#define ll_1149_FileID ((intptr_t)1149)
#define ll_1150_FileID ((intptr_t)1150)
#define ll_1151_FileID ((intptr_t)1151)
#define ll_1152_FileID ((intptr_t)1152)
#define ll_1153_FileID ((intptr_t)1153)
#define ll_1154_FileID ((intptr_t)1154)
#define ll_1155_FileID ((intptr_t)1155)
#define ll_1156_FileID ((intptr_t)1156)
#define ll_1157_FileID ((intptr_t)1157)
#define ll_1158_FileID ((intptr_t)1158)
#define ll_1159_FileID ((intptr_t)1159)
#define ll_1160_FileID ((intptr_t)1160)
#define ll_1161_FileID ((intptr_t)1161)
#define ll_1162_FileID ((intptr_t)1162)
#define ll_1163_FileID ((intptr_t)1163)
#define ll_1164_FileID ((intptr_t)1164)
#define ll_1165_FileID ((intptr_t)1165)
#define ll_1166_FileID ((intptr_t)1166)
#define ll_1167_FileID ((intptr_t)1167)
#define ll_1168_FileID ((intptr_t)1168)
#define ll_1169_FileID ((intptr_t)1169)
#define ll_1170_FileID ((intptr_t)1170)
#define ll_1171_FileID ((intptr_t)1171)
#define ll_1172_FileID ((intptr_t)1172)
#define ll_1173_FileID ((intptr_t)1173)
#define ll_1174_FileID ((intptr_t)1174)
#define ll_1175_FileID ((intptr_t)1175)
#define ll_1176_FileID ((intptr_t)1176)
#define ll_1177_FileID ((intptr_t)1177)
#define ll_1178_FileID ((intptr_t)1178)
#define ll_1179_FileID ((intptr_t)1179)
#define ll_1180_FileID ((intptr_t)1180)
#define ll_1181_FileID ((intptr_t)1181)
#define ll_1182_FileID ((intptr_t)1182)
#define ll_1183_FileID ((intptr_t)1183)
#define ll_1184_FileID ((intptr_t)1184)
#define ll_1185_FileID ((intptr_t)1185)
#define ll_1186_FileID ((intptr_t)1186)
#define ll_1187_FileID ((intptr_t)1187)
#define ll_1188_FileID ((intptr_t)1188)
#define ll_1189_FileID ((intptr_t)1189)
#define ll_1190_FileID ((intptr_t)1190)
#define ll_1191_FileID ((intptr_t)1191)
#define ll_1192_FileID ((intptr_t)1192)
#define ll_1193_FileID ((intptr_t)1193)
#define ll_1194_FileID ((intptr_t)1194)
#define ll_1195_FileID ((intptr_t)1195)
#define ll_1196_FileID ((intptr_t)1196)
#define ll_1197_FileID ((intptr_t)1197)
#define ll_1198_FileID ((intptr_t)1198)
#define ll_1199_FileID ((intptr_t)1199)
#define ll_1200_FileID ((intptr_t)1200)
#define ll_1201_FileID ((intptr_t)1201)
#define ll_1202_FileID ((intptr_t)1202)
#define ll_1203_FileID ((intptr_t)1203)
#define ll_1204_FileID ((intptr_t)1204)
#define ll_1205_FileID ((intptr_t)1205)
#define ll_1206_FileID ((intptr_t)1206)
#define ll_1207_FileID ((intptr_t)1207)
#define ll_1208_FileID ((intptr_t)1208)
#define ll_1209_FileID ((intptr_t)1209)
#define ll_1210_FileID ((intptr_t)1210)
#define ll_1211_FileID ((intptr_t)1211)
#define ll_1212_FileID ((intptr_t)1212)
#define ll_1213_FileID ((intptr_t)1213)
#define ll_1214_FileID ((intptr_t)1214)
#define ll_1215_FileID ((intptr_t)1215)
#define ll_1216_FileID ((intptr_t)1216)
#define ll_1217_FileID ((intptr_t)1217)
#define ll_1218_FileID ((intptr_t)1218)
#define ll_1219_FileID ((intptr_t)1219)
#define ll_1220_FileID ((intptr_t)1220)
#define ll_1221_FileID ((intptr_t)1221)
#define ll_1222_FileID ((intptr_t)1222)
#define ll_1223_FileID ((intptr_t)1223)
#define ll_1224_FileID ((intptr_t)1224)
#define ll_1225_FileID ((intptr_t)1225)
#define ll_1226_FileID ((intptr_t)1226)
#define ll_1227_FileID ((intptr_t)1227)
#define ll_1228_FileID ((intptr_t)1228)
#define ll_1229_FileID ((intptr_t)1229)
#define ll_1230_FileID ((intptr_t)1230)
#define ll_1231_FileID ((intptr_t)1231)
#define ll_1232_FileID ((intptr_t)1232)
#define ll_1233_FileID ((intptr_t)1233)
#define ll_1234_FileID ((intptr_t)1234)
#define ll_1235_FileID ((intptr_t)1235)
#define ll_1236_FileID ((intptr_t)1236)
#define ll_1237_FileID ((intptr_t)1237)
#define ll_1238_FileID ((intptr_t)1238)
#define ll_1239_FileID ((intptr_t)1239)
#define ll_1240_FileID ((intptr_t)1240)
#define ll_1241_FileID ((intptr_t)1241)
#define ll_1242_FileID ((intptr_t)1242)
#define ll_1243_FileID ((intptr_t)1243)
#define ll_1244_FileID ((intptr_t)1244)
#define ll_1245_FileID ((intptr_t)1245)
#define ll_1246_FileID ((intptr_t)1246)
#define ll_1247_FileID ((intptr_t)1247)
#define ll_1248_FileID ((intptr_t)1248)
#define ll_1249_FileID ((intptr_t)1249)
#define ll_1250_FileID ((intptr_t)1250)
#define ll_1251_FileID ((intptr_t)1251)
#define ll_1252_FileID ((intptr_t)1252)
#define ll_1253_FileID ((intptr_t)1253)
#define ll_1254_FileID ((intptr_t)1254)
#define ll_1255_FileID ((intptr_t)1255)
#define ll_1256_FileID ((intptr_t)1256)
#define ll_1257_FileID ((intptr_t)1257)
#define ll_1258_FileID ((intptr_t)1258)
#define ll_1259_FileID ((intptr_t)1259)
#define ll_1260_FileID ((intptr_t)1260)
#define ll_1261_FileID ((intptr_t)1261)
#define ll_1262_FileID ((intptr_t)1262)
#define ll_1263_FileID ((intptr_t)1263)
#define ll_1264_FileID ((intptr_t)1264)
#define ll_1265_FileID ((intptr_t)1265)
#define ll_1266_FileID ((intptr_t)1266)
#define ll_1267_FileID ((intptr_t)1267)
#define ll_1268_FileID ((intptr_t)1268)
#define ll_1269_FileID ((intptr_t)1269)
#define ll_1270_FileID ((intptr_t)1270)
#define ll_1271_FileID ((intptr_t)1271)
#define ll_1272_FileID ((intptr_t)1272)
#define ll_1273_FileID ((intptr_t)1273)
#define ll_1274_FileID ((intptr_t)1274)
#define ll_1275_FileID ((intptr_t)1275)
#define ll_1276_FileID ((intptr_t)1276)
#define ll_1277_FileID ((intptr_t)1277)
#define ll_1278_FileID ((intptr_t)1278)
#define ll_1279_FileID ((intptr_t)1279)
#define ll_1280_FileID ((intptr_t)1280)
#define ll_1281_FileID ((intptr_t)1281)
#define ll_1282_FileID ((intptr_t)1282)
#define ll_1283_FileID ((intptr_t)1283)
#define ll_1284_FileID ((intptr_t)1284)
#define ll_1285_FileID ((intptr_t)1285)
#define ll_1286_FileID ((intptr_t)1286)
#define ll_1287_FileID ((intptr_t)1287)
#define ll_1288_FileID ((intptr_t)1288)
#define ll_1289_FileID ((intptr_t)1289)
#define ll_1290_FileID ((intptr_t)1290)
#define ll_1291_FileID ((intptr_t)1291)
#define ll_1292_FileID ((intptr_t)1292)
#define ll_1293_FileID ((intptr_t)1293)
#define ll_1294_FileID ((intptr_t)1294)
#define ll_1295_FileID ((intptr_t)1295)
#define ll_1296_FileID ((intptr_t)1296)
#define ll_1297_FileID ((intptr_t)1297)
#define ll_1298_FileID ((intptr_t)1298)
#define ll_1299_FileID ((intptr_t)1299)
#define ll_1300_FileID ((intptr_t)1300)
#define ll_1301_FileID ((intptr_t)1301)
#define ll_1302_FileID ((intptr_t)1302)
#define ll_1303_FileID ((intptr_t)1303)
#define ll_1304_FileID ((intptr_t)1304)
#define ll_1305_FileID ((intptr_t)1305)
#define ll_1306_FileID ((intptr_t)1306)
#define ll_1307_FileID ((intptr_t)1307)
#define ll_1308_FileID ((intptr_t)1308)
#define ll_1309_FileID ((intptr_t)1309)
#define ll_1310_FileID ((intptr_t)1310)
#define ll_1311_FileID ((intptr_t)1311)
#define ll_1312_FileID ((intptr_t)1312)
#define ll_1313_FileID ((intptr_t)1313)
#define ll_1314_FileID ((intptr_t)1314)
#define ll_1315_FileID ((intptr_t)1315)
#define ll_1316_FileID ((intptr_t)1316)
#define ll_1317_FileID ((intptr_t)1317)
#define ll_1318_FileID ((intptr_t)1318)
#define ll_1319_FileID ((intptr_t)1319)
#define ll_1320_FileID ((intptr_t)1320)
#define ll_1321_FileID ((intptr_t)1321)
#define ll_1322_FileID ((intptr_t)1322)
#define ll_1323_FileID ((intptr_t)1323)
#define ll_1324_FileID ((intptr_t)1324)
#define ll_1325_FileID ((intptr_t)1325)
#define ll_1326_FileID ((intptr_t)1326)
#define ll_1327_FileID ((intptr_t)1327)
#define ll_1328_FileID ((intptr_t)1328)
#define ll_1329_FileID ((intptr_t)1329)
#define ll_1330_FileID ((intptr_t)1330)
#define ll_1331_FileID ((intptr_t)1331)
#define ll_1332_FileID ((intptr_t)1332)
#define ll_1333_FileID ((intptr_t)1333)
#define ll_1334_FileID ((intptr_t)1334)
#define ll_1335_FileID ((intptr_t)1335)
#define ll_1336_FileID ((intptr_t)1336)
#define ll_1337_FileID ((intptr_t)1337)
#define ll_1338_FileID ((intptr_t)1338)
#define ll_1339_FileID ((intptr_t)1339)
#define ll_1340_FileID ((intptr_t)1340)
#define ll_1341_FileID ((intptr_t)1341)
#define ll_1342_FileID ((intptr_t)1342)
#define ll_1343_FileID ((intptr_t)1343)
#define ll_1344_FileID ((intptr_t)1344)
#define ll_1345_FileID ((intptr_t)1345)
#define ll_1346_FileID ((intptr_t)1346)
#define ll_1347_FileID ((intptr_t)1347)
#define ll_1348_FileID ((intptr_t)1348)
#define ll_1349_FileID ((intptr_t)1349)
#define ll_1350_FileID ((intptr_t)1350)
#define ll_1351_FileID ((intptr_t)1351)
#define ll_1352_FileID ((intptr_t)1352)
#define ll_1353_FileID ((intptr_t)1353)
#define ll_1354_FileID ((intptr_t)1354)
#define ll_1355_FileID ((intptr_t)1355)
#define ll_1356_FileID ((intptr_t)1356)
#define ll_1357_FileID ((intptr_t)1357)
#define ll_1358_FileID ((intptr_t)1358)
#define ll_1359_FileID ((intptr_t)1359)
#define ll_1360_FileID ((intptr_t)1360)
#define ll_1361_FileID ((intptr_t)1361)
#define ll_1362_FileID ((intptr_t)1362)
#define ll_1363_FileID ((intptr_t)1363)
#define ll_1364_FileID ((intptr_t)1364)
#define ll_1365_FileID ((intptr_t)1365)
#define ll_1366_FileID ((intptr_t)1366)
#define ll_1367_FileID ((intptr_t)1367)
#define ll_1368_FileID ((intptr_t)1368)
#define ll_1369_FileID ((intptr_t)1369)
#define ll_1370_FileID ((intptr_t)1370)
#define ll_1371_FileID ((intptr_t)1371)
#define ll_1372_FileID ((intptr_t)1372)
#define ll_1373_FileID ((intptr_t)1373)
#define ll_1374_FileID ((intptr_t)1374)
#define ll_1375_FileID ((intptr_t)1375)
#define ll_1376_FileID ((intptr_t)1376)
#define ll_1377_FileID ((intptr_t)1377)
#define ll_1378_FileID ((intptr_t)1378)
#define ll_1379_FileID ((intptr_t)1379)
#define ll_1380_FileID ((intptr_t)1380)
#define ll_1381_FileID ((intptr_t)1381)
#define ll_1382_FileID ((intptr_t)1382)
#define ll_1383_FileID ((intptr_t)1383)
#define ll_1384_FileID ((intptr_t)1384)
#define ll_1385_FileID ((intptr_t)1385)
#define ll_1386_FileID ((intptr_t)1386)
#define ll_1387_FileID ((intptr_t)1387)
#define ll_1388_FileID ((intptr_t)1388)
#define ll_1389_FileID ((intptr_t)1389)
#define ll_1390_FileID ((intptr_t)1390)
#define ll_1391_FileID ((intptr_t)1391)
#define ll_1392_FileID ((intptr_t)1392)
#define ll_1393_FileID ((intptr_t)1393)
#define ll_1394_FileID ((intptr_t)1394)
#define ll_1395_FileID ((intptr_t)1395)
#define ll_1396_FileID ((intptr_t)1396)
#define ll_1397_FileID ((intptr_t)1397)
#define ll_1398_FileID ((intptr_t)1398)
#define ll_1399_FileID ((intptr_t)1399)
#define ll_1400_FileID ((intptr_t)1400)
#define ll_1401_FileID ((intptr_t)1401)
#define ll_1402_FileID ((intptr_t)1402)
#define ll_1403_FileID ((intptr_t)1403)
#define ll_1404_FileID ((intptr_t)1404)
#define ll_1405_FileID ((intptr_t)1405)
#define ll_1406_FileID ((intptr_t)1406)
#define ll_1407_FileID ((intptr_t)1407)
#define ll_1408_FileID ((intptr_t)1408)
#define ll_1409_FileID ((intptr_t)1409)
#define ll_1410_FileID ((intptr_t)1410)
#define ll_1411_FileID ((intptr_t)1411)
#define ll_1412_FileID ((intptr_t)1412)
#define ll_1413_FileID ((intptr_t)1413)
#define ll_1414_FileID ((intptr_t)1414)
#define ll_1415_FileID ((intptr_t)1415)
#define ll_1416_FileID ((intptr_t)1416)
#define ll_1417_FileID ((intptr_t)1417)
#define ll_1418_FileID ((intptr_t)1418)
#define ll_1419_FileID ((intptr_t)1419)
#define ll_1420_FileID ((intptr_t)1420)
#define ll_1421_FileID ((intptr_t)1421)
#define ll_1422_FileID ((intptr_t)1422)
#define ll_1423_FileID ((intptr_t)1423)
#define ll_1424_FileID ((intptr_t)1424)
#define ll_1425_FileID ((intptr_t)1425)
#define ll_1426_FileID ((intptr_t)1426)
#define ll_1427_FileID ((intptr_t)1427)
#define ll_1428_FileID ((intptr_t)1428)
#define ll_1429_FileID ((intptr_t)1429)
#define ll_1430_FileID ((intptr_t)1430)
#define ll_1431_FileID ((intptr_t)1431)
#define ll_1432_FileID ((intptr_t)1432)
#define ll_1433_FileID ((intptr_t)1433)
#define ll_1434_FileID ((intptr_t)1434)
#define ll_1435_FileID ((intptr_t)1435)
#define ll_1436_FileID ((intptr_t)1436)
#define ll_1437_FileID ((intptr_t)1437)
#define ll_1438_FileID ((intptr_t)1438)
#define ll_1439_FileID ((intptr_t)1439)
#define ll_1440_FileID ((intptr_t)1440)
#define ll_1441_FileID ((intptr_t)1441)
#define ll_1442_FileID ((intptr_t)1442)
#define ll_1443_FileID ((intptr_t)1443)
#define ll_1444_FileID ((intptr_t)1444)
#define ll_1445_FileID ((intptr_t)1445)
#define ll_1446_FileID ((intptr_t)1446)
#define ll_1447_FileID ((intptr_t)1447)
#define ll_1448_FileID ((intptr_t)1448)
#define ll_1449_FileID ((intptr_t)1449)
#define ll_1450_FileID ((intptr_t)1450)
#define ll_1451_FileID ((intptr_t)1451)
#define ll_1452_FileID ((intptr_t)1452)
#define ll_1453_FileID ((intptr_t)1453)
#define ll_1454_FileID ((intptr_t)1454)
#define ll_1455_FileID ((intptr_t)1455)
#define ll_1456_FileID ((intptr_t)1456)
#define ll_1457_FileID ((intptr_t)1457)
#define ll_1458_FileID ((intptr_t)1458)
#define ll_1459_FileID ((intptr_t)1459)
#define ll_1460_FileID ((intptr_t)1460)
#define ll_1461_FileID ((intptr_t)1461)
#define ll_1462_FileID ((intptr_t)1462)
#define ll_1463_FileID ((intptr_t)1463)
#define ll_1464_FileID ((intptr_t)1464)
#define ll_1465_FileID ((intptr_t)1465)
#define ll_1466_FileID ((intptr_t)1466)
#define ll_1467_FileID ((intptr_t)1467)
#define ll_1468_FileID ((intptr_t)1468)
#define ll_1469_FileID ((intptr_t)1469)
#define ll_1470_FileID ((intptr_t)1470)
#define ll_1471_FileID ((intptr_t)1471)
#define ll_1472_FileID ((intptr_t)1472)
#define ll_1473_FileID ((intptr_t)1473)
#define ll_1474_FileID ((intptr_t)1474)
#define ll_1475_FileID ((intptr_t)1475)
#define ll_1476_FileID ((intptr_t)1476)
#define ll_1477_FileID ((intptr_t)1477)
#define ll_1478_FileID ((intptr_t)1478)
#define ll_1479_FileID ((intptr_t)1479)
#define ll_1480_FileID ((intptr_t)1480)
#define ll_1481_FileID ((intptr_t)1481)
#define ll_1482_FileID ((intptr_t)1482)
#define ll_1483_FileID ((intptr_t)1483)
#define ll_1484_FileID ((intptr_t)1484)
#define ll_1485_FileID ((intptr_t)1485)
#define ll_1486_FileID ((intptr_t)1486)
#define ll_1487_FileID ((intptr_t)1487)
#define ll_1488_FileID ((intptr_t)1488)
#define ll_1489_FileID ((intptr_t)1489)
#define ll_1490_FileID ((intptr_t)1490)
#define ll_1491_FileID ((intptr_t)1491)
#define ll_1492_FileID ((intptr_t)1492)
#define ll_1493_FileID ((intptr_t)1493)
#define ll_1494_FileID ((intptr_t)1494)
#define ll_1495_FileID ((intptr_t)1495)
#define ll_1496_FileID ((intptr_t)1496)
#define ll_1497_FileID ((intptr_t)1497)
#define ll_1498_FileID ((intptr_t)1498)
#define ll_1499_FileID ((intptr_t)1499)
#define ll_1500_FileID ((intptr_t)1500)
#define ll_1501_FileID ((intptr_t)1501)
#define ll_1502_FileID ((intptr_t)1502)
#define ll_1503_FileID ((intptr_t)1503)
#define ll_1504_FileID ((intptr_t)1504)
#define ll_1505_FileID ((intptr_t)1505)
#define ll_1506_FileID ((intptr_t)1506)
#define ll_1507_FileID ((intptr_t)1507)
#define ll_1508_FileID ((intptr_t)1508)
#define ll_1509_FileID ((intptr_t)1509)
#define ll_1510_FileID ((intptr_t)1510)
#define ll_1511_FileID ((intptr_t)1511)
#define ll_1512_FileID ((intptr_t)1512)
#define ll_1513_FileID ((intptr_t)1513)
#define ll_1514_FileID ((intptr_t)1514)
#define ll_1515_FileID ((intptr_t)1515)
#define ll_1516_FileID ((intptr_t)1516)
#define ll_1517_FileID ((intptr_t)1517)
#define ll_1518_FileID ((intptr_t)1518)
#define ll_1519_FileID ((intptr_t)1519)
#define ll_1520_FileID ((intptr_t)1520)
#define ll_1521_FileID ((intptr_t)1521)
#define ll_1522_FileID ((intptr_t)1522)
#define ll_1523_FileID ((intptr_t)1523)
#define ll_1524_FileID ((intptr_t)1524)
#define ll_1525_FileID ((intptr_t)1525)
#define ll_1526_FileID ((intptr_t)1526)
#define ll_1527_FileID ((intptr_t)1527)
#define ll_1528_FileID ((intptr_t)1528)
#define ll_1529_FileID ((intptr_t)1529)
#define ll_1530_FileID ((intptr_t)1530)
#define ll_1531_FileID ((intptr_t)1531)
#define ll_1532_FileID ((intptr_t)1532)
#define ll_1533_FileID ((intptr_t)1533)
#define ll_1534_FileID ((intptr_t)1534)
#define ll_1535_FileID ((intptr_t)1535)
#define ll_1536_FileID ((intptr_t)1536)
#define ll_1537_FileID ((intptr_t)1537)
#define ll_1538_FileID ((intptr_t)1538)
#define ll_1539_FileID ((intptr_t)1539)
#define ll_1540_FileID ((intptr_t)1540)
#define ll_1541_FileID ((intptr_t)1541)
#define ll_1542_FileID ((intptr_t)1542)
#define ll_1543_FileID ((intptr_t)1543)
#define ll_1544_FileID ((intptr_t)1544)
#define ll_1545_FileID ((intptr_t)1545)
#define ll_1546_FileID ((intptr_t)1546)
#define ll_1547_FileID ((intptr_t)1547)
#define ll_1548_FileID ((intptr_t)1548)
#define ll_1549_FileID ((intptr_t)1549)
#define ll_1550_FileID ((intptr_t)1550)
#define ll_1551_FileID ((intptr_t)1551)
#define ll_1552_FileID ((intptr_t)1552)
#define ll_1553_FileID ((intptr_t)1553)
#define ll_1554_FileID ((intptr_t)1554)
#define ll_1555_FileID ((intptr_t)1555)
#define ll_1556_FileID ((intptr_t)1556)
#define ll_1557_FileID ((intptr_t)1557)
#define ll_1558_FileID ((intptr_t)1558)
#define ll_1559_FileID ((intptr_t)1559)
#define ll_1560_FileID ((intptr_t)1560)
#define ll_1561_FileID ((intptr_t)1561)
#define ll_1562_FileID ((intptr_t)1562)
#define ll_1563_FileID ((intptr_t)1563)
#define ll_1564_FileID ((intptr_t)1564)
#define ll_1565_FileID ((intptr_t)1565)
#define ll_1566_FileID ((intptr_t)1566)
#define ll_1567_FileID ((intptr_t)1567)
#define ll_1568_FileID ((intptr_t)1568)
#define ll_1569_FileID ((intptr_t)1569)
#define ll_1570_FileID ((intptr_t)1570)
#define ll_1571_FileID ((intptr_t)1571)
#define ll_1572_FileID ((intptr_t)1572)
#define ll_1573_FileID ((intptr_t)1573)
#define ll_1574_FileID ((intptr_t)1574)
#define ll_1575_FileID ((intptr_t)1575)
#define ll_1576_FileID ((intptr_t)1576)
#define ll_1577_FileID ((intptr_t)1577)
#define ll_1578_FileID ((intptr_t)1578)
#define ll_1579_FileID ((intptr_t)1579)
#define ll_1580_FileID ((intptr_t)1580)
#define ll_1581_FileID ((intptr_t)1581)
#define ll_1582_FileID ((intptr_t)1582)
#define ll_1583_FileID ((intptr_t)1583)
#define ll_1584_FileID ((intptr_t)1584)
#define ll_1585_FileID ((intptr_t)1585)
#define ll_1586_FileID ((intptr_t)1586)
#define ll_1587_FileID ((intptr_t)1587)
#define ll_1588_FileID ((intptr_t)1588)
#define ll_1589_FileID ((intptr_t)1589)
#define ll_1590_FileID ((intptr_t)1590)
#define ll_1591_FileID ((intptr_t)1591)
#define ll_1592_FileID ((intptr_t)1592)
#define ll_1593_FileID ((intptr_t)1593)
#define ll_1594_FileID ((intptr_t)1594)
#define ll_1595_FileID ((intptr_t)1595)
#define ll_1596_FileID ((intptr_t)1596)
#define ll_1597_FileID ((intptr_t)1597)
#define ll_1598_FileID ((intptr_t)1598)
#define ll_1599_FileID ((intptr_t)1599)
#define ll_1600_FileID ((intptr_t)1600)
#define ll_1601_FileID ((intptr_t)1601)
#define ll_1602_FileID ((intptr_t)1602)
#define ll_1603_FileID ((intptr_t)1603)
#define ll_1604_FileID ((intptr_t)1604)
#define ll_1605_FileID ((intptr_t)1605)
#define ll_1606_FileID ((intptr_t)1606)
#define ll_1607_FileID ((intptr_t)1607)
#define ll_1608_FileID ((intptr_t)1608)
#define ll_1609_FileID ((intptr_t)1609)
#define ll_1610_FileID ((intptr_t)1610)
#define ll_1611_FileID ((intptr_t)1611)
#define ll_1612_FileID ((intptr_t)1612)
#define ll_1613_FileID ((intptr_t)1613)
#define ll_1614_FileID ((intptr_t)1614)
#define ll_1615_FileID ((intptr_t)1615)
#define ll_1616_FileID ((intptr_t)1616)
#define ll_1617_FileID ((intptr_t)1617)
#define ll_1618_FileID ((intptr_t)1618)
#define ll_1619_FileID ((intptr_t)1619)
#define ll_1620_FileID ((intptr_t)1620)
#define ll_1621_FileID ((intptr_t)1621)
#define ll_1622_FileID ((intptr_t)1622)
#define ll_1623_FileID ((intptr_t)1623)
#define ll_1624_FileID ((intptr_t)1624)
#define ll_1625_FileID ((intptr_t)1625)
#define ll_1626_FileID ((intptr_t)1626)
#define ll_1627_FileID ((intptr_t)1627)
#define ll_1628_FileID ((intptr_t)1628)
#define ll_1629_FileID ((intptr_t)1629)
#define ll_1630_FileID ((intptr_t)1630)
#define ll_1631_FileID ((intptr_t)1631)
#define ll_1632_FileID ((intptr_t)1632)
#define ll_1633_FileID ((intptr_t)1633)
#define ll_1634_FileID ((intptr_t)1634)
#define ll_1635_FileID ((intptr_t)1635)
#define ll_1636_FileID ((intptr_t)1636)
#define ll_1637_FileID ((intptr_t)1637)
#define ll_1638_FileID ((intptr_t)1638)
#define ll_1639_FileID ((intptr_t)1639)
#define ll_1640_FileID ((intptr_t)1640)
#define ll_1641_FileID ((intptr_t)1641)
#define ll_1642_FileID ((intptr_t)1642)
#define ll_1643_FileID ((intptr_t)1643)
#define ll_1644_FileID ((intptr_t)1644)
#define ll_1645_FileID ((intptr_t)1645)
#define ll_1646_FileID ((intptr_t)1646)
#define ll_1647_FileID ((intptr_t)1647)
#define ll_1648_FileID ((intptr_t)1648)
#define ll_1649_FileID ((intptr_t)1649)
#define ll_1650_FileID ((intptr_t)1650)
#define ll_1651_FileID ((intptr_t)1651)
#define ll_1652_FileID ((intptr_t)1652)
#define ll_1653_FileID ((intptr_t)1653)
#define ll_1654_FileID ((intptr_t)1654)
#define ll_1655_FileID ((intptr_t)1655)
#define ll_1656_FileID ((intptr_t)1656)
#define ll_1657_FileID ((intptr_t)1657)
#define ll_1658_FileID ((intptr_t)1658)
#define ll_1659_FileID ((intptr_t)1659)
#define ll_1660_FileID ((intptr_t)1660)
#define ll_1661_FileID ((intptr_t)1661)
#define ll_1662_FileID ((intptr_t)1662)
#define ll_1663_FileID ((intptr_t)1663)
#define ll_1664_FileID ((intptr_t)1664)
#define ll_1665_FileID ((intptr_t)1665)
#define ll_1666_FileID ((intptr_t)1666)
#define ll_1667_FileID ((intptr_t)1667)
#define ll_1668_FileID ((intptr_t)1668)
#define ll_1669_FileID ((intptr_t)1669)
#define ll_1670_FileID ((intptr_t)1670)
#define ll_1671_FileID ((intptr_t)1671)
#define ll_1672_FileID ((intptr_t)1672)
#define ll_1673_FileID ((intptr_t)1673)
#define ll_1674_FileID ((intptr_t)1674)
#define ll_1675_FileID ((intptr_t)1675)
#define ll_1676_FileID ((intptr_t)1676)
#define ll_1677_FileID ((intptr_t)1677)
#define ll_1678_FileID ((intptr_t)1678)
#define ll_1679_FileID ((intptr_t)1679)
#define ll_1680_FileID ((intptr_t)1680)
#define ll_1681_FileID ((intptr_t)1681)
#define ll_1682_FileID ((intptr_t)1682)
#define ll_1683_FileID ((intptr_t)1683)
#define ll_1684_FileID ((intptr_t)1684)
#define ll_1685_FileID ((intptr_t)1685)
#define ll_1686_FileID ((intptr_t)1686)
#define ll_1687_FileID ((intptr_t)1687)
#define ll_1688_FileID ((intptr_t)1688)
#define ll_1689_FileID ((intptr_t)1689)
#define ll_1690_FileID ((intptr_t)1690)
#define ll_1691_FileID ((intptr_t)1691)
#define ll_1692_FileID ((intptr_t)1692)
#define ll_1693_FileID ((intptr_t)1693)
#define ll_1694_FileID ((intptr_t)1694)
#define ll_1695_FileID ((intptr_t)1695)
#define ll_1696_FileID ((intptr_t)1696)
#define ll_1697_FileID ((intptr_t)1697)
#define ll_1698_FileID ((intptr_t)1698)
#define ll_1699_FileID ((intptr_t)1699)
#define ll_1700_FileID ((intptr_t)1700)
#define ll_1701_FileID ((intptr_t)1701)
#define ll_1702_FileID ((intptr_t)1702)
#define ll_1703_FileID ((intptr_t)1703)
#define ll_1704_FileID ((intptr_t)1704)
#define ll_1705_FileID ((intptr_t)1705)
#define ll_1706_FileID ((intptr_t)1706)
#define ll_1707_FileID ((intptr_t)1707)
#define ll_1708_FileID ((intptr_t)1708)
#define ll_1709_FileID ((intptr_t)1709)
#define ll_1710_FileID ((intptr_t)1710)
#define ll_1711_FileID ((intptr_t)1711)
#define ll_1712_FileID ((intptr_t)1712)
#define ll_1713_FileID ((intptr_t)1713)
#define ll_1714_FileID ((intptr_t)1714)
#define ll_1715_FileID ((intptr_t)1715)
#define ll_1716_FileID ((intptr_t)1716)
#define ll_1717_FileID ((intptr_t)1717)
#define ll_1718_FileID ((intptr_t)1718)
#define ll_1719_FileID ((intptr_t)1719)
#define ll_1720_FileID ((intptr_t)1720)
#define ll_1721_FileID ((intptr_t)1721)
#define ll_1722_FileID ((intptr_t)1722)
#define ll_1723_FileID ((intptr_t)1723)
#define ll_1724_FileID ((intptr_t)1724)
#define ll_1725_FileID ((intptr_t)1725)
#define ll_1726_FileID ((intptr_t)1726)
#define ll_1727_FileID ((intptr_t)1727)
#define ll_1728_FileID ((intptr_t)1728)
#define ll_1729_FileID ((intptr_t)1729)
#define ll_1730_FileID ((intptr_t)1730)
#define ll_1731_FileID ((intptr_t)1731)
#define ll_1732_FileID ((intptr_t)1732)
#define ll_1733_FileID ((intptr_t)1733)
#define ll_1734_FileID ((intptr_t)1734)
#define ll_1735_FileID ((intptr_t)1735)
#define ll_1736_FileID ((intptr_t)1736)
#define ll_1737_FileID ((intptr_t)1737)
#define ll_1738_FileID ((intptr_t)1738)
#define ll_1739_FileID ((intptr_t)1739)
#define ll_1740_FileID ((intptr_t)1740)
#define ll_1741_FileID ((intptr_t)1741)
#define ll_1742_FileID ((intptr_t)1742)
#define ll_1743_FileID ((intptr_t)1743)
#define ll_1744_FileID ((intptr_t)1744)
#define ll_1745_FileID ((intptr_t)1745)
#define ll_1746_FileID ((intptr_t)1746)
#define ll_1747_FileID ((intptr_t)1747)
#define ll_1748_FileID ((intptr_t)1748)
#define ll_1749_FileID ((intptr_t)1749)
#define ll_1750_FileID ((intptr_t)1750)
#define ll_1751_FileID ((intptr_t)1751)
#define ll_1752_FileID ((intptr_t)1752)
#define ll_1753_FileID ((intptr_t)1753)
#define ll_1754_FileID ((intptr_t)1754)
#define ll_1755_FileID ((intptr_t)1755)
#define ll_1756_FileID ((intptr_t)1756)
#define ll_1757_FileID ((intptr_t)1757)
#define ll_1758_FileID ((intptr_t)1758)
#define ll_1759_FileID ((intptr_t)1759)
#define ll_1760_FileID ((intptr_t)1760)
#define ll_1761_FileID ((intptr_t)1761)
#define ll_1762_FileID ((intptr_t)1762)
#define ll_1763_FileID ((intptr_t)1763)
#define ll_1764_FileID ((intptr_t)1764)
#define ll_1765_FileID ((intptr_t)1765)
#define ll_1766_FileID ((intptr_t)1766)
#define ll_1767_FileID ((intptr_t)1767)
#define ll_1768_FileID ((intptr_t)1768)
#define ll_1769_FileID ((intptr_t)1769)
#define ll_1770_FileID ((intptr_t)1770)
#define ll_1771_FileID ((intptr_t)1771)
#define ll_1772_FileID ((intptr_t)1772)
#define ll_1773_FileID ((intptr_t)1773)
#define ll_1774_FileID ((intptr_t)1774)
#define ll_1775_FileID ((intptr_t)1775)
#define ll_1776_FileID ((intptr_t)1776)
#define ll_1777_FileID ((intptr_t)1777)
#define ll_1778_FileID ((intptr_t)1778)
#define ll_1779_FileID ((intptr_t)1779)
#define ll_1780_FileID ((intptr_t)1780)
#define ll_1781_FileID ((intptr_t)1781)
#define ll_1782_FileID ((intptr_t)1782)
#define ll_1783_FileID ((intptr_t)1783)
#define ll_1784_FileID ((intptr_t)1784)
#define ll_1785_FileID ((intptr_t)1785)
#define ll_1786_FileID ((intptr_t)1786)
#define ll_1787_FileID ((intptr_t)1787)
#define ll_1788_FileID ((intptr_t)1788)
#define ll_1789_FileID ((intptr_t)1789)
#define ll_1790_FileID ((intptr_t)1790)
#define ll_1791_FileID ((intptr_t)1791)
#define ll_1792_FileID ((intptr_t)1792)
#define ll_1793_FileID ((intptr_t)1793)
#define ll_1794_FileID ((intptr_t)1794)
#define ll_1795_FileID ((intptr_t)1795)
#define ll_1796_FileID ((intptr_t)1796)
#define ll_1797_FileID ((intptr_t)1797)
#define ll_1798_FileID ((intptr_t)1798)
#define ll_1799_FileID ((intptr_t)1799)
#define ll_1800_FileID ((intptr_t)1800)
#define ll_1801_FileID ((intptr_t)1801)
#define ll_1802_FileID ((intptr_t)1802)
#define ll_1803_FileID ((intptr_t)1803)
#define ll_1804_FileID ((intptr_t)1804)
#define ll_1805_FileID ((intptr_t)1805)
#define ll_1806_FileID ((intptr_t)1806)
#define ll_1807_FileID ((intptr_t)1807)
#define ll_1808_FileID ((intptr_t)1808)
#define ll_1809_FileID ((intptr_t)1809)
#define ll_1810_FileID ((intptr_t)1810)
#define ll_1811_FileID ((intptr_t)1811)
#define ll_1812_FileID ((intptr_t)1812)
#define ll_1813_FileID ((intptr_t)1813)
#define ll_1814_FileID ((intptr_t)1814)
#define ll_1815_FileID ((intptr_t)1815)
#define ll_1816_FileID ((intptr_t)1816)
#define ll_1817_FileID ((intptr_t)1817)
#define ll_1818_FileID ((intptr_t)1818)
#define ll_1819_FileID ((intptr_t)1819)
#define ll_1820_FileID ((intptr_t)1820)
#define ll_1821_FileID ((intptr_t)1821)
#define ll_1822_FileID ((intptr_t)1822)
#define ll_1823_FileID ((intptr_t)1823)
#define ll_1824_FileID ((intptr_t)1824)
#define ll_1825_FileID ((intptr_t)1825)
#define ll_1826_FileID ((intptr_t)1826)
#define ll_1827_FileID ((intptr_t)1827)
#define ll_1828_FileID ((intptr_t)1828)
#define ll_1829_FileID ((intptr_t)1829)
#define ll_1830_FileID ((intptr_t)1830)
#define ll_1831_FileID ((intptr_t)1831)
#define ll_1832_FileID ((intptr_t)1832)
#define ll_1833_FileID ((intptr_t)1833)
#define ll_1834_FileID ((intptr_t)1834)
#define ll_1835_FileID ((intptr_t)1835)
#define ll_1836_FileID ((intptr_t)1836)
#define ll_1837_FileID ((intptr_t)1837)
#define ll_1838_FileID ((intptr_t)1838)
#define ll_1839_FileID ((intptr_t)1839)
#define ll_1840_FileID ((intptr_t)1840)
#define ll_1841_FileID ((intptr_t)1841)
#define ll_1842_FileID ((intptr_t)1842)
#define ll_1843_FileID ((intptr_t)1843)
#define ll_1844_FileID ((intptr_t)1844)
#define ll_1845_FileID ((intptr_t)1845)
#define ll_1846_FileID ((intptr_t)1846)
#define ll_1847_FileID ((intptr_t)1847)
#define ll_1848_FileID ((intptr_t)1848)
#define ll_1849_FileID ((intptr_t)1849)
#define ll_1850_FileID ((intptr_t)1850)
#define ll_1851_FileID ((intptr_t)1851)
#define ll_1852_FileID ((intptr_t)1852)
#define ll_1853_FileID ((intptr_t)1853)
#define ll_1854_FileID ((intptr_t)1854)
#define ll_1855_FileID ((intptr_t)1855)
#define ll_1856_FileID ((intptr_t)1856)
#define ll_1857_FileID ((intptr_t)1857)
#define ll_1858_FileID ((intptr_t)1858)
#define ll_1859_FileID ((intptr_t)1859)
#define ll_1860_FileID ((intptr_t)1860)
#define ll_1861_FileID ((intptr_t)1861)
#define ll_1862_FileID ((intptr_t)1862)
#define ll_1863_FileID ((intptr_t)1863)
#define ll_1864_FileID ((intptr_t)1864)
#define ll_1865_FileID ((intptr_t)1865)
#define ll_1866_FileID ((intptr_t)1866)
#define ll_1867_FileID ((intptr_t)1867)
#define ll_1868_FileID ((intptr_t)1868)
#define ll_1869_FileID ((intptr_t)1869)
#define ll_1870_FileID ((intptr_t)1870)
#define ll_1871_FileID ((intptr_t)1871)
#define ll_1872_FileID ((intptr_t)1872)
#define ll_1873_FileID ((intptr_t)1873)
#define ll_1874_FileID ((intptr_t)1874)
#define ll_1875_FileID ((intptr_t)1875)
#define ll_1876_FileID ((intptr_t)1876)
#define ll_1877_FileID ((intptr_t)1877)
#define ll_1878_FileID ((intptr_t)1878)
#define ll_1879_FileID ((intptr_t)1879)
#define ll_1880_FileID ((intptr_t)1880)
#define ll_1881_FileID ((intptr_t)1881)
#define ll_1882_FileID ((intptr_t)1882)
#define ll_1883_FileID ((intptr_t)1883)
#define ll_1884_FileID ((intptr_t)1884)
#define ll_1885_FileID ((intptr_t)1885)
#define ll_1886_FileID ((intptr_t)1886)
#define ll_1887_FileID ((intptr_t)1887)
#define ll_1888_FileID ((intptr_t)1888)
#define ll_1889_FileID ((intptr_t)1889)
#define ll_1890_FileID ((intptr_t)1890)
#define ll_1891_FileID ((intptr_t)1891)
#define ll_1892_FileID ((intptr_t)1892)
#define ll_1893_FileID ((intptr_t)1893)
#define ll_1894_FileID ((intptr_t)1894)
#define ll_1895_FileID ((intptr_t)1895)
#define ll_1896_FileID ((intptr_t)1896)
#define ll_1897_FileID ((intptr_t)1897)
#define ll_1898_FileID ((intptr_t)1898)
#define ll_1899_FileID ((intptr_t)1899)
#define ll_1900_FileID ((intptr_t)1900)
#define ll_1901_FileID ((intptr_t)1901)
#define ll_1902_FileID ((intptr_t)1902)
#define ll_1903_FileID ((intptr_t)1903)
#define ll_1904_FileID ((intptr_t)1904)
#define ll_1905_FileID ((intptr_t)1905)
#define ll_1906_FileID ((intptr_t)1906)
#define ll_1907_FileID ((intptr_t)1907)
#define ll_1908_FileID ((intptr_t)1908)
#define ll_1909_FileID ((intptr_t)1909)
#define ll_1910_FileID ((intptr_t)1910)
#define ll_1911_FileID ((intptr_t)1911)
#define ll_1912_FileID ((intptr_t)1912)
#define ll_1913_FileID ((intptr_t)1913)
#define ll_1914_FileID ((intptr_t)1914)
#define ll_1915_FileID ((intptr_t)1915)
#define ll_1916_FileID ((intptr_t)1916)
#define ll_1917_FileID ((intptr_t)1917)
#define ll_1918_FileID ((intptr_t)1918)
#define ll_1919_FileID ((intptr_t)1919)
#define ll_1920_FileID ((intptr_t)1920)
#define ll_1921_FileID ((intptr_t)1921)
#define ll_1922_FileID ((intptr_t)1922)
#define ll_1923_FileID ((intptr_t)1923)
#define ll_1924_FileID ((intptr_t)1924)
#define ll_1925_FileID ((intptr_t)1925)
#define ll_1926_FileID ((intptr_t)1926)
#define ll_1927_FileID ((intptr_t)1927)
#define ll_1928_FileID ((intptr_t)1928)
#define ll_1929_FileID ((intptr_t)1929)
#define ll_1930_FileID ((intptr_t)1930)
#define ll_1931_FileID ((intptr_t)1931)
#define ll_1932_FileID ((intptr_t)1932)
#define ll_1933_FileID ((intptr_t)1933)
#define ll_1934_FileID ((intptr_t)1934)
#define ll_1935_FileID ((intptr_t)1935)
#define ll_1936_FileID ((intptr_t)1936)
#define ll_1937_FileID ((intptr_t)1937)
#define ll_1938_FileID ((intptr_t)1938)
#define ll_1939_FileID ((intptr_t)1939)
#define ll_1940_FileID ((intptr_t)1940)
#define ll_1941_FileID ((intptr_t)1941)
#define ll_1942_FileID ((intptr_t)1942)
#define ll_1943_FileID ((intptr_t)1943)
#define ll_1944_FileID ((intptr_t)1944)
#define ll_1945_FileID ((intptr_t)1945)
#define ll_1946_FileID ((intptr_t)1946)
#define ll_1947_FileID ((intptr_t)1947)
#define ll_1948_FileID ((intptr_t)1948)
#define ll_1949_FileID ((intptr_t)1949)
#define ll_1950_FileID ((intptr_t)1950)
#define ll_1951_FileID ((intptr_t)1951)
#define ll_1952_FileID ((intptr_t)1952)
#define ll_1953_FileID ((intptr_t)1953)
#define ll_1954_FileID ((intptr_t)1954)
#define ll_1955_FileID ((intptr_t)1955)
#define ll_1956_FileID ((intptr_t)1956)
#define ll_1957_FileID ((intptr_t)1957)
#define ll_1958_FileID ((intptr_t)1958)
#define ll_1959_FileID ((intptr_t)1959)
#define ll_1960_FileID ((intptr_t)1960)
#define ll_1961_FileID ((intptr_t)1961)
#define ll_1962_FileID ((intptr_t)1962)
#define ll_1963_FileID ((intptr_t)1963)
#define ll_1964_FileID ((intptr_t)1964)
#define ll_1965_FileID ((intptr_t)1965)
#define ll_1966_FileID ((intptr_t)1966)
#define ll_1967_FileID ((intptr_t)1967)
#define ll_1968_FileID ((intptr_t)1968)
#define ll_1969_FileID ((intptr_t)1969)
#define ll_1970_FileID ((intptr_t)1970)
#define ll_1971_FileID ((intptr_t)1971)
#define ll_1972_FileID ((intptr_t)1972)
#define ll_1973_FileID ((intptr_t)1973)
#define ll_1974_FileID ((intptr_t)1974)
#define ll_1975_FileID ((intptr_t)1975)
#define ll_1976_FileID ((intptr_t)1976)
#define ll_1977_FileID ((intptr_t)1977)
#define ll_1978_FileID ((intptr_t)1978)
#define ll_1979_FileID ((intptr_t)1979)
#define ll_1980_FileID ((intptr_t)1980)
#define ll_1981_FileID ((intptr_t)1981)
#define ll_1982_FileID ((intptr_t)1982)
#define ll_1983_FileID ((intptr_t)1983)
#define ll_1984_FileID ((intptr_t)1984)
#define ll_1985_FileID ((intptr_t)1985)
#define ll_1986_FileID ((intptr_t)1986)
#define ll_1987_FileID ((intptr_t)1987)
#define ll_1988_FileID ((intptr_t)1988)
#define ll_1989_FileID ((intptr_t)1989)
#define ll_1990_FileID ((intptr_t)1990)
#define ll_1991_FileID ((intptr_t)1991)
#define ll_1992_FileID ((intptr_t)1992)
#define ll_1993_FileID ((intptr_t)1993)
#define ll_1994_FileID ((intptr_t)1994)
#define ll_1995_FileID ((intptr_t)1995)
#define ll_1996_FileID ((intptr_t)1996)
#define ll_1997_FileID ((intptr_t)1997)
#define ll_1998_FileID ((intptr_t)1998)
#define ll_1999_FileID ((intptr_t)1999)
#define ll_2000_FileID ((intptr_t)2000)
#define ll_2001_FileID ((intptr_t)2001)
#define ll_2002_FileID ((intptr_t)2002)
#define ll_2003_FileID ((intptr_t)2003)
#define ll_2004_FileID ((intptr_t)2004)
#define ll_2005_FileID ((intptr_t)2005)
#define ll_2006_FileID ((intptr_t)2006)
#define ll_2007_FileID ((intptr_t)2007)
#define ll_2008_FileID ((intptr_t)2008)
#define ll_2009_FileID ((intptr_t)2009)
#define ll_2010_FileID ((intptr_t)2010)
#define ll_2011_FileID ((intptr_t)2011)
#define ll_2012_FileID ((intptr_t)2012)
#define ll_2013_FileID ((intptr_t)2013)
#define ll_2014_FileID ((intptr_t)2014)
#define ll_2015_FileID ((intptr_t)2015)
#define ll_2016_FileID ((intptr_t)2016)
#define ll_2017_FileID ((intptr_t)2017)
#define ll_2018_FileID ((intptr_t)2018)
#define ll_2019_FileID ((intptr_t)2019)
#define ll_2020_FileID ((intptr_t)2020)
#define ll_2021_FileID ((intptr_t)2021)
#define ll_2022_FileID ((intptr_t)2022)
#define ll_2023_FileID ((intptr_t)2023)
#define ll_2024_FileID ((intptr_t)2024)
#define ll_2025_FileID ((intptr_t)2025)
#define ll_2026_FileID ((intptr_t)2026)
#define ll_2027_FileID ((intptr_t)2027)
#define ll_2028_FileID ((intptr_t)2028)
#define ll_2029_FileID ((intptr_t)2029)
#define ll_2030_FileID ((intptr_t)2030)
#define ll_2031_FileID ((intptr_t)2031)
#define ll_2032_FileID ((intptr_t)2032)
#define ll_2033_FileID ((intptr_t)2033)
#define ll_2034_FileID ((intptr_t)2034)
#define ll_2035_FileID ((intptr_t)2035)
#define ll_2036_FileID ((intptr_t)2036)
#define ll_2037_FileID ((intptr_t)2037)
#define ll_2038_FileID ((intptr_t)2038)
#define ll_2039_FileID ((intptr_t)2039)
#define ll_2040_FileID ((intptr_t)2040)
#define ll_2041_FileID ((intptr_t)2041)
#define ll_2042_FileID ((intptr_t)2042)
#define ll_2043_FileID ((intptr_t)2043)
#define ll_2044_FileID ((intptr_t)2044)
#define ll_2045_FileID ((intptr_t)2045)
#define ll_2046_FileID ((intptr_t)2046)
#define ll_2047_FileID ((intptr_t)2047)
#define ll_2048_FileID ((intptr_t)2048)
#define ll_2049_FileID ((intptr_t)2049)
#define ll_2050_FileID ((intptr_t)2050)
#define ll_2051_FileID ((intptr_t)2051)
#define ll_2052_FileID ((intptr_t)2052)
#define ll_2053_FileID ((intptr_t)2053)
#define ll_2054_FileID ((intptr_t)2054)
#define ll_2055_FileID ((intptr_t)2055)
#define ll_2056_FileID ((intptr_t)2056)
#define ll_2057_FileID ((intptr_t)2057)
#define ll_2058_FileID ((intptr_t)2058)
#define ll_2059_FileID ((intptr_t)2059)
#define ll_2060_FileID ((intptr_t)2060)
#define ll_2061_FileID ((intptr_t)2061)
#define ll_2062_FileID ((intptr_t)2062)
#define ll_2063_FileID ((intptr_t)2063)
#define ll_2064_FileID ((intptr_t)2064)
#define ll_2065_FileID ((intptr_t)2065)
#define ll_2066_FileID ((intptr_t)2066)
#define ll_2067_FileID ((intptr_t)2067)
#define ll_2068_FileID ((intptr_t)2068)
#define ll_2069_FileID ((intptr_t)2069)
#define ll_2070_FileID ((intptr_t)2070)
#define ll_2071_FileID ((intptr_t)2071)
#define ll_2072_FileID ((intptr_t)2072)
#define ll_2073_FileID ((intptr_t)2073)
#define ll_2074_FileID ((intptr_t)2074)
#define ll_2075_FileID ((intptr_t)2075)
#define ll_2076_FileID ((intptr_t)2076)
#define ll_2077_FileID ((intptr_t)2077)
#define ll_2078_FileID ((intptr_t)2078)
#define ll_2079_FileID ((intptr_t)2079)
#define ll_2080_FileID ((intptr_t)2080)
#define ll_2081_FileID ((intptr_t)2081)
#define ll_2082_FileID ((intptr_t)2082)
#define ll_2083_FileID ((intptr_t)2083)
#define ll_2084_FileID ((intptr_t)2084)
#define ll_2085_FileID ((intptr_t)2085)
#define ll_2086_FileID ((intptr_t)2086)
#define ll_2087_FileID ((intptr_t)2087)
#define ll_2088_FileID ((intptr_t)2088)
#define ll_2089_FileID ((intptr_t)2089)
#define ll_2090_FileID ((intptr_t)2090)
#define ll_2091_FileID ((intptr_t)2091)
#define ll_2092_FileID ((intptr_t)2092)
#define ll_2093_FileID ((intptr_t)2093)
#define ll_2094_FileID ((intptr_t)2094)
#define ll_2095_FileID ((intptr_t)2095)
#define ll_2096_FileID ((intptr_t)2096)
#define ll_2097_FileID ((intptr_t)2097)
#define ll_2098_FileID ((intptr_t)2098)
#define ll_2099_FileID ((intptr_t)2099)
#define ll_2100_FileID ((intptr_t)2100)
#define ll_2101_FileID ((intptr_t)2101)
#define ll_2102_FileID ((intptr_t)2102)
#define ll_2103_FileID ((intptr_t)2103)
#define ll_2104_FileID ((intptr_t)2104)
#define ll_2105_FileID ((intptr_t)2105)
#define ll_2106_FileID ((intptr_t)2106)
#define ll_2107_FileID ((intptr_t)2107)
#define ll_2108_FileID ((intptr_t)2108)
#define ll_2109_FileID ((intptr_t)2109)
#define ll_2110_FileID ((intptr_t)2110)
#define ll_2111_FileID ((intptr_t)2111)
#define ll_2112_FileID ((intptr_t)2112)
#define ll_2113_FileID ((intptr_t)2113)
#define ll_2114_FileID ((intptr_t)2114)
#define ll_2115_FileID ((intptr_t)2115)
#define ll_2116_FileID ((intptr_t)2116)
#define ll_2117_FileID ((intptr_t)2117)
#define ll_2118_FileID ((intptr_t)2118)
#define ll_2119_FileID ((intptr_t)2119)
#define ll_2120_FileID ((intptr_t)2120)
#define ll_2121_FileID ((intptr_t)2121)
#define ll_2122_FileID ((intptr_t)2122)
#define ll_2123_FileID ((intptr_t)2123)
#define ll_2124_FileID ((intptr_t)2124)
#define ll_2125_FileID ((intptr_t)2125)
#define ll_2126_FileID ((intptr_t)2126)
#define ll_2127_FileID ((intptr_t)2127)
#define ll_2128_FileID ((intptr_t)2128)
#define ll_2129_FileID ((intptr_t)2129)
#define ll_2130_FileID ((intptr_t)2130)
#define ll_2131_FileID ((intptr_t)2131)
#define llMNCommonOptionTabLeftSprite ((intptr_t)488)
#define llMNCommonOptionTabMiddleSprite ((intptr_t)816)
#define llMNCommonOptionTabRightSprite ((intptr_t)1384)
#define llMNCommonFrameSprite ((intptr_t)5152)
#define llMNCommonOnTextJapSprite ((intptr_t)5568)
#define llMNCommonOffTextJapSprite ((intptr_t)5984)
#define llMNCommonAutoTextJapSprite ((intptr_t)6504)
#define llMNCommonDecalPaperSprite ((intptr_t)10800)
#define llMNCommonSmashLogoSprite ((intptr_t)12792)
#define llMNCommonFightBackgroundSprite ((intptr_t)46800)
#define llMNCommonOnTextSprite ((intptr_t)47128)
#define llMNCommonOffTextSprite ((intptr_t)47448)
#define llMNCommonSlashSprite ((intptr_t)47656)
#define llMNCommonGameModeTextSprite ((intptr_t)53824)
#define llMNCommonDigit0Sprite ((intptr_t)54032)
#define llMNCommonDigit1Sprite ((intptr_t)54240)
#define llMNCommonDigit2Sprite ((intptr_t)54448)
#define llMNCommonDigit3Sprite ((intptr_t)54656)
#define llMNCommonDigit4Sprite ((intptr_t)54864)
#define llMNCommonDigit5Sprite ((intptr_t)55072)
#define llMNCommonDigit6Sprite ((intptr_t)55280)
#define llMNCommonDigit7Sprite ((intptr_t)55488)
#define llMNCommonDigit8Sprite ((intptr_t)55696)
#define llMNCommonDigit9Sprite ((intptr_t)55904)
#define llMNCommonPercentageSprite ((intptr_t)56112)
#define llMNCommonInfinitySprite ((intptr_t)56392)
#define llMNCommonColonSprite ((intptr_t)56560)
#define llMNCommonArrowRSprite ((intptr_t)56720)
#define llMNCommonArrowLSprite ((intptr_t)56880)
#define llMNCommonAutoTextSprite ((intptr_t)57160)
#define llMNCommonSmashBrosCollageSprite ((intptr_t)98304)
#define llMNMain1PModeTextJapSprite ((intptr_t)1224)
#define llMNMainVsModeTextJapSprite ((intptr_t)2400)
#define llMNMainDataTextJapSprite ((intptr_t)3584)
#define llMNMainControllerIconSprite ((intptr_t)6544)
#define llMNMainConsoleIconSprite ((intptr_t)9504)
#define llMNMainDataIconSprite ((intptr_t)12464)
#define llMNMainModeSelectTextSprite ((intptr_t)16624)
#define llMNMainSettingsIconSprite ((intptr_t)19584)
#define llMNMainOptionTextJapSprite ((intptr_t)21248)
#define llMNMain1PModeTextSprite ((intptr_t)21872)
#define llMNMainVsModeTextSprite ((intptr_t)22496)
#define llMNMainDataTextSprite ((intptr_t)22912)
#define llMNMainControllerIconDarkSprite ((intptr_t)24648)
#define llMNMainConsoleIconDarkSprite ((intptr_t)26376)
#define llMNMainDataIconDarkSprite ((intptr_t)28104)
#define llMNMainDecalBarEdgeSprite ((intptr_t)29416)
#define llMNMainSmashLogoSprite ((intptr_t)31400)
#define llMNMainDecalBarMiddleSprite ((intptr_t)31800)
#define llMNMainSettingsIconDarkSprite ((intptr_t)33528)
#define llMNMainOptionTextSprite ((intptr_t)34040)
#define llMN1P1PGameTextJapSprite ((intptr_t)1224)
#define llMN1POptionTabSprite ((intptr_t)4360)
#define llMN1PTrainingModeTextJapSprite ((intptr_t)5656)
#define llMN1PBonus1PracticeTextJapSprite ((intptr_t)7672)
#define llMN1PBonus2PracticeTextJapSprite ((intptr_t)9688)
#define llMN1P1PGameTextSprite ((intptr_t)10792)
#define llMN1PControllerIconDarkSprite ((intptr_t)20728)
#define llMN1P1PTextSprite ((intptr_t)21304)
#define llMN1PTrainingModeTextSprite ((intptr_t)23240)
#define llMN1PBonus1PracticeTextSprite ((intptr_t)24360)
#define llMN1PBonus2PracticeTextSprite ((intptr_t)25480)
#define llMNIndexBubbleLeftSprite ((intptr_t)240)
#define llMNIndexBubbleMiddleSprite ((intptr_t)560)
#define llMNIndexBubbleRightSprite ((intptr_t)880)
#define llMNIndexCharactersTextJapSprite ((intptr_t)2664)
#define llMNIndexVsRecordTextJapSprite ((intptr_t)3720)
#define llMNIndexSoundTextJapSprite ((intptr_t)4776)
#define llMNIndexSoundTestTextJapSprite ((intptr_t)6312)
#define llMNIndexScreenAdjustTextJapSprite ((intptr_t)7368)
#define llMNIndexIndexTextSprite ((intptr_t)10144)
#define llMNIndexCharactersTextSprite ((intptr_t)11200)
#define llMNIndexVsRecordTextSprite ((intptr_t)12256)
#define llMNIndexSoundTextSprite ((intptr_t)13040)
#define llMNIndexTestTextSprite ((intptr_t)13552)
#define llMNIndexScreenAdjustTextSprite ((intptr_t)15240)
#define llMNIndexDataIconDarkSprite ((intptr_t)25176)
#define llMNOptionSoundTextJapSprite ((intptr_t)984)
#define llMNOptionStereoTextJapSprite ((intptr_t)1704)
#define llMNOptionMonoTextJapSprite ((intptr_t)2424)
#define llMNOptionFlashingTextJapSprite ((intptr_t)4080)
#define llMNOptionScreenAdjustTextJapSprite ((intptr_t)5504)
#define llMNOptionBackupClearTextJapSprite ((intptr_t)7408)
#define llMNOptionWarningTextSprite ((intptr_t)8632)
#define llMNOptionPhotosensitivityWarningTextJapSprite ((intptr_t)26800)
#define llMNOptionWarningIconSprite ((intptr_t)28632)
#define llMNOptionStereoTextSprite ((intptr_t)29176)
#define llMNOptionMonoTextSprite ((intptr_t)29608)
#define llMNOptionSoundTextSprite ((intptr_t)30248)
#define llMNOptionFlashingTextSprite ((intptr_t)31400)
#define llMNOptionScreenAdjustTextSprite ((intptr_t)33080)
#define llMNOptionBackupClearTextSprite ((intptr_t)34688)
#define llMNOptionOptionTextSprite ((intptr_t)37512)
#define llMNOptionSettingsIconDarkSprite ((intptr_t)47448)
#define llMNDataCharactersTextJapSprite ((intptr_t)1704)
#define llMNDataVSRecordTextJapSprite ((intptr_t)2760)
#define llMNDataSoundTestTextJapSprite ((intptr_t)4296)
#define llMNDataCharactersTextSprite ((intptr_t)5344)
#define llMNDataVSRecordTextSprite ((intptr_t)6400)
#define llMNDataSoundTestTextSprite ((intptr_t)7456)
#define llMNDataDataTextSprite ((intptr_t)9128)
#define llMNDataDataIconDarkSprite ((intptr_t)19064)
#define llMNVSModeVSStartTextJapSprite ((intptr_t)1344)
#define llMNVSModeBattleTextJapSprite ((intptr_t)2048)
#define llMNVSModeTimeBasedTextJapSprite ((intptr_t)2872)
#define llMNVSModeStockTextJapSprite ((intptr_t)3808)
#define llMNVSModeTeamTextJapSprite ((intptr_t)4512)
#define llMNVSModeTimeLimitTextJapSprite ((intptr_t)5456)
#define llMNVSModeRemaningPlayersTextJapSprite ((intptr_t)6640)
#define llMNVSModeMatchOptionsTextJapSprite ((intptr_t)8304)
#define llMNVSModeVSStartTextSprite ((intptr_t)9416)
#define llMNVSModeRulePeriodTextSprite ((intptr_t)10056)
#define llMNVSModeTimeTextSprite ((intptr_t)10464)
#define llMNVSModeStockTextSprite ((intptr_t)10880)
#define llMNVSModeTeamTextSprite ((intptr_t)11296)
#define llMNVSModeTimePeriodTextSprite ((intptr_t)11976)
#define llMNVSModeMinTextSprite ((intptr_t)12232)
#define llMNVSModeStockPeriodTextSprite ((intptr_t)12872)
#define llMNVSModeVSOptionsTextSprite ((intptr_t)14376)
#define llMNVSModeConsoleIconDarkSprite ((intptr_t)24240)
#define llMNVSModeVSTextSprite ((intptr_t)24856)
#define llMNVSOptionsHandicapTextJapSprite ((intptr_t)864)
#define llMNVSOptionsTeamAttackTextJapSprite ((intptr_t)2528)
#define llMNVSOptionsStageSelectTextJapSprite ((intptr_t)3952)
#define llMNVSOptionsDamageTextJapSprite ((intptr_t)5616)
#define llMNVSOptionsItemSwitchTextJapSprite ((intptr_t)7280)
#define llMNVSOptionsVSOptionsTextSprite ((intptr_t)9832)
#define llMNVSOptionsBubbleSprite ((intptr_t)13272)
#define llMNVSOptionsHandicapTextSprite ((intptr_t)13968)
#define llMNVSOptionsTeamAttackTextSprite ((intptr_t)14696)
#define llMNVSOptionsStageSelectTextSprite ((intptr_t)15608)
#define llMNVSOptionsItemSwitchTextSprite ((intptr_t)16328)
#define llMNVSOptionsDamageTextSprite ((intptr_t)16936)
#define llMNVSOptionsConsoleIconDarkSprite ((intptr_t)24416)
#define llMNVSItemSwitchLabelVSOptionsSprite ((intptr_t)2472)
#define llMNVSItemSwitchLabelItemSwitchSprite ((intptr_t)2848)
#define llMNVSItemSwitchAppearanceNoneSprite ((intptr_t)3304)
#define llMNVSItemSwitchAppearanceVeryLowSprite ((intptr_t)3752)
#define llMNVSItemSwitchAppearanceLowSprite ((intptr_t)3992)
#define llMNVSItemSwitchAppearanceMiddleSprite ((intptr_t)4304)
#define llMNVSItemSwitchAppearanceHighSprite ((intptr_t)4584)
#define llMNVSItemSwitchAppearanceVeryHighSprite ((intptr_t)5032)
#define llMNVSItemSwitchToggleOnSprite ((intptr_t)5256)
#define llMNVSItemSwitchToggleOffSprite ((intptr_t)5480)
#define llMNVSItemSwitchToggleSlashSprite ((intptr_t)5640)
#define llMNVSItemSwitchDecalButtonSprite ((intptr_t)13360)
#define llMNVSItemSwitchFrameSprite ((intptr_t)14664)
#define llMNVSItemSwitchItemListSprite ((intptr_t)24160)
#define llMNVSItemSwitchCursorSprite ((intptr_t)25512)
#define llMNVSItemSwitchAppearancePercentTextJapSprite ((intptr_t)26048)
#define llMNVSItemSwitchBeamSwordTextJapSprite ((intptr_t)26592)
#define llMNVSItemSwitchHomerunBatTextJapSprite ((intptr_t)27136)
#define llMNVSItemSwitchHammerTextJapSprite ((intptr_t)27680)
#define llMNVSItemSwitch0x6e40Sprite ((intptr_t)28224)
#define llMNVSItemSwitchHarisenTextJapSprite ((intptr_t)28768)
#define llMNVSItemSwitch0x7280Sprite ((intptr_t)29312)
#define llMNVSItemSwitchBombTrooperTextJapSprite ((intptr_t)29856)
#define llMNVSItemSwitchBumperTextJapSprite ((intptr_t)30400)
#define llMNVSItemSwitchShellTextJapSprite ((intptr_t)30944)
#define llMNVSItemSwitchMonsterBallTextJapSprite ((intptr_t)31488)
#define llMNVSItemSwitchLayGunTextJapSprite ((intptr_t)32032)
#define llMNVSItemSwitchFireFlowerTextJapSprite ((intptr_t)32576)
#define llMNVSItemSwitchStarRodTextJapSprite ((intptr_t)33120)
#define llMNVSItemSwitchMaximTomatoTextJapSprite ((intptr_t)33664)
#define llMNVSItemSwitchHeartTextJapSprite ((intptr_t)34208)
#define llMNVSItemSwitchStarTextJapSprite ((intptr_t)34752)
#define llMNVSItemSwitchMotionSensorBombTextJapSprite ((intptr_t)35736)
#define llMNVSItemSwitchVeryLowTextJapSprite ((intptr_t)36272)
#define llMNVSItemSwitchLowTextJapSprite ((intptr_t)36816)
#define llMNVSItemSwitchMiddleTextJapSprite ((intptr_t)37360)
#define llMNVSItemSwitchHighTextJapSprite ((intptr_t)37904)
#define llMNVSItemSwitchVeryHighTextJapSprite ((intptr_t)38448)
#define llMNVSItemSwitchNothingTextJapSprite ((intptr_t)38992)
#define llMNMessageUnlockLuigiSprite ((intptr_t)2528)
#define llMNMessageUnlockNessSprite ((intptr_t)4424)
#define llMNMessageUnlockCaptainSprite ((intptr_t)8016)
#define llMNMessageUnlockPurinSprite ((intptr_t)11864)
#define llMNMessageUnlockInishieSprite ((intptr_t)13400)
#define llMNMessageUnlockSoundTestSprite ((intptr_t)16768)
#define llMNMessageUnlockItemSwitchSprite ((intptr_t)20144)
#define llMNMessageDecalExclaimSprite ((intptr_t)21248)
#define llSC1PChallengerChallengerTextSprite ((intptr_t)504)
#define llSC1PChallengerApproachingTextSprite ((intptr_t)1160)
#define llSC1PChallengerWarningTextSprite ((intptr_t)2408)
#define llSC1PChallengerDecalExclaimSprite ((intptr_t)3504)
#define llSC1PIntroVSDecalSprite ((intptr_t)7952)
#define llSC1PIntroNumber1Sprite ((intptr_t)8216)
#define llSC1PIntroNumber2Sprite ((intptr_t)8472)
#define llSC1PIntroNumber3Sprite ((intptr_t)8728)
#define llSC1PIntroNumber4Sprite ((intptr_t)8984)
#define llSC1PIntroNumber5Sprite ((intptr_t)9240)
#define llSC1PIntroNumber6Sprite ((intptr_t)9496)
#define llSC1PIntroNumber7Sprite ((intptr_t)9752)
#define llSC1PIntroNumber8Sprite ((intptr_t)10008)
#define llSC1PIntroNumber9Sprite ((intptr_t)10264)
#define llSC1PIntroNumber10Sprite ((intptr_t)10680)
#define llSC1PIntroCrossSprite ((intptr_t)11096)
#define llSC1PIntroStageTextSprite ((intptr_t)11832)
#define llSC1PIntroBonusTextSprite ((intptr_t)12536)
#define llSC1PIntroFinalTextSprite ((intptr_t)13088)
#define llSC1PIntroBreakTheTargetsTextSprite ((intptr_t)15112)
#define llSC1PIntroBoardThePlatformsTextSprite ((intptr_t)17288)
#define llSC1PIntroRaceToTheFinishTextSprite ((intptr_t)19144)
#define llSC1PIntro0x5028Sprite ((intptr_t)20520)
#define llSC1PIntroDashSprite ((intptr_t)20712)
#define llSC1PIntroMetalMarioTextSprite ((intptr_t)21288)
#define llSC1PIntroMasterHandTextSprite ((intptr_t)21864)
#define llSC1PIntroGiantDKTextSprite ((intptr_t)22344)
#define llSC1PIntroFoxMcCloudTextSprite ((intptr_t)22920)
#define llSC1PIntroKirbyTeamVS8TextSprite ((intptr_t)23688)
#define llSC1PIntroMarioBrosTextSprite ((intptr_t)24264)
#define llSC1PIntroFightingPolygonTeamVS30TextSprite ((intptr_t)25592)
#define llSC1PIntroSamusAranTextSprite ((intptr_t)26168)
#define llSC1PIntroYoshiTeamVS18TextSprite ((intptr_t)26936)
#define llSC1PIntroVSTextSprite ((intptr_t)27128)
#define llSC1PIntroAllyTextSprite ((intptr_t)27416)
#define llSC1PIntroAllyText2Sprite ((intptr_t)27704)
#define llSC1PIntroFighterMarioCamAnimJoint ((intptr_t)27776)
#define llSC1PIntroFighterFoxCamAnimJoint ((intptr_t)27824)
#define llSC1PIntroFighterDonkeyCamAnimJoint ((intptr_t)27872)
#define llSC1PIntroFighterSamusCamAnimJoint ((intptr_t)27920)
#define llSC1PIntroFighterLuigiCamAnimJoint ((intptr_t)27968)
#define llSC1PIntroFighterLinkCamAnimJoint ((intptr_t)28016)
#define llSC1PIntroFighterYoshiCamAnimJoint ((intptr_t)28064)
#define llSC1PIntroFighterCaptainCamAnimJoint ((intptr_t)28112)
#define llSC1PIntroFighterKirbyCamAnimJoint ((intptr_t)28160)
#define llSC1PIntroFighterPikachuCamAnimJoint ((intptr_t)28208)
#define llSC1PIntroFighterPurinCamAnimJoint ((intptr_t)28256)
#define llSC1PIntroFighterNessCamAnimJoint ((intptr_t)28304)
#define llSC1PIntroStageKirbyCamAnimJoint ((intptr_t)28352)
#define llSC1PIntroStageSamusCamAnimJoint ((intptr_t)28496)
#define llSC1PIntroStageFoxCamAnimJoint ((intptr_t)28544)
#define llSC1PIntroStagePikachuCamAnimJoint ((intptr_t)28592)
#define llSC1PIntroStageLinkCamAnimJoint ((intptr_t)28640)
#define llSC1PIntroStageYoshiCamAnimJoint ((intptr_t)28400)
#define llSC1PIntroStageBossCamAnimJoint ((intptr_t)28448)
#define llSC1PIntroStageDonkeyCamAnimJoint ((intptr_t)28688)
#define llSC1PIntroStageMarioCamAnimJoint ((intptr_t)28736)
#define llSC1PIntroStageMMarioCamAnimJoint ((intptr_t)28784)
#define llSC1PIntroStageZakoCamAnimJoint ((intptr_t)28832)
#define llSC1PIntroLinkMarkerSprite ((intptr_t)29136)
#define llSC1PIntroYoshiMarkerSprite ((intptr_t)29472)
#define llSC1PIntroFoxMarkerSprite ((intptr_t)29808)
#define llSC1PIntroMarioBrosMarkerSprite ((intptr_t)30144)
#define llSC1PIntroPikachuMarkerSprite ((intptr_t)30480)
#define llSC1PIntroDKMarkerSprite ((intptr_t)30816)
#define llSC1PIntroKirbyMarkerSprite ((intptr_t)31152)
#define llSC1PIntroSamusMarkerSprite ((intptr_t)31488)
#define llSC1PIntroMarioMarkerSprite ((intptr_t)31824)
#define llSC1PIntroExclamationMarkSprite ((intptr_t)32096)
#define llSC1PIntroBossMarkerSprite ((intptr_t)32368)
#define llSC1PIntroBonusMarkerSprite ((intptr_t)32576)
#define llSC1PIntroBannerTopSprite ((intptr_t)51352)
#define llSC1PIntroBannerBottomSprite ((intptr_t)60672)
#define llSC1PIntroSkySprite ((intptr_t)84976)
#define llCharacterNamesMarioSprite ((intptr_t)312)
#define llCharacterNamesFoxSprite ((intptr_t)600)
#define llCharacterNamesDonkeySprite ((intptr_t)888)
#define llCharacterNamesSamusSprite ((intptr_t)1272)
#define llCharacterNamesLuigiSprite ((intptr_t)1560)
#define llCharacterNamesLinkSprite ((intptr_t)1848)
#define llCharacterNamesYoshiSprite ((intptr_t)2136)
#define llCharacterNamesCaptainSprite ((intptr_t)2616)
#define llCharacterNamesKirbySprite ((intptr_t)3000)
#define llCharacterNamesPikachuSprite ((intptr_t)3384)
#define llCharacterNamesPurinSprite ((intptr_t)3960)
#define llCharacterNamesNessSprite ((intptr_t)4248)
#define llBonusPictureTargetSprite ((intptr_t)59776)
#define llBonusPictureRaceSprite ((intptr_t)108120)
#define llBonusPicturePlatformSprite ((intptr_t)160648)
#define llMNScreenAdjustInstructionSprite ((intptr_t)2328)
#define llMNScreenAdjustGuideSprite ((intptr_t)39072)
#define llMNCharactersLabelSprite ((intptr_t)1584)
#define llMNCharactersNameTagDefaultSprite ((intptr_t)4656)
#define llMNCharactersNameTagTallSprite ((intptr_t)10480)
#define llMNCharactersMarioNameSprite ((intptr_t)12184)
#define llMNCharactersFoxNameSprite ((intptr_t)13216)
#define llMNCharactersDonkeyNameSprite ((intptr_t)17040)
#define llMNCharactersSamusNameSprite ((intptr_t)18704)
#define llMNCharactersLuigiNameSprite ((intptr_t)20344)
#define llMNCharactersLinkNameSprite ((intptr_t)21400)
#define llMNCharactersYoshiNameSprite ((intptr_t)22776)
#define llMNCharactersCaptainNameSprite ((intptr_t)26664)
#define llMNCharactersKirbyNameSprite ((intptr_t)28232)
#define llMNCharactersPikachuNameSprite ((intptr_t)30248)
#define llMNCharactersPurinNameSprite ((intptr_t)33504)
#define llMNCharactersNessNameSprite ((intptr_t)34856)
#define llMNCharactersMarioStorySprite ((intptr_t)44200)
#define llMNCharactersFoxStorySprite ((intptr_t)53544)
#define llMNCharactersDonkeyStorySprite ((intptr_t)62888)
#define llMNCharactersSamusStorySprite ((intptr_t)72232)
#define llMNCharactersLuigiStorySprite ((intptr_t)81576)
#define llMNCharactersLinkStorySprite ((intptr_t)90920)
#define llMNCharactersYoshiStorySprite ((intptr_t)100264)
#define llMNCharactersCaptainStorySprite ((intptr_t)109608)
#define llMNCharactersKirbyStorySprite ((intptr_t)118952)
#define llMNCharactersPikachuStorySprite ((intptr_t)128296)
#define llMNCharactersPurinStorySprite ((intptr_t)137640)
#define llMNCharactersNessStorySprite ((intptr_t)146984)
#define llMNCharactersWorksWallpaperSprite ((intptr_t)151640)
#define llMNCharactersMarioWorksSprite ((intptr_t)154296)
#define llMNCharactersFoxWorksSprite ((intptr_t)156952)
#define llMNCharactersDonkeyWorksSprite ((intptr_t)159608)
#define llMNCharactersSamusWorksSprite ((intptr_t)162264)
#define llMNCharactersLuigiWorksSprite ((intptr_t)164920)
#define llMNCharactersLinkWorksSprite ((intptr_t)167576)
#define llMNCharactersYoshiWorksSprite ((intptr_t)170232)
#define llMNCharactersCaptainWorksSprite ((intptr_t)172888)
#define llMNCharactersKirbyWorksSprite ((intptr_t)175544)
#define llMNCharactersPikachuWorksSprite ((intptr_t)178200)
#define llMNCharactersPurinWorksSprite ((intptr_t)180856)
#define llMNCharactersNessWorksSprite ((intptr_t)183512)
#define llMNCharactersMotionSpecialHiInputSprite ((intptr_t)183720)
#define llMNCharactersMotionSpecialNInputSprite ((intptr_t)183928)
#define llMNCharactersMotionSpecialLwInputSprite ((intptr_t)184136)
#define llMNCharactersMarioSpecialHiNameSprite ((intptr_t)184456)
#define llMNCharactersFoxSpecialHiNameSprite ((intptr_t)184776)
#define llMNCharactersDonkeySpecialHiNameSprite ((intptr_t)185096)
#define llMNCharactersSamusSpecialHiNameSprite ((intptr_t)185416)
#define llMNCharactersLinkSpecialHiNameSprite ((intptr_t)185736)
#define llMNCharactersYoshiSpecialHiNameSprite ((intptr_t)186056)
#define llMNCharactersCaptainSpecialHiNameSprite ((intptr_t)186376)
#define llMNCharactersKirbySpecialHiNameSprite ((intptr_t)186696)
#define llMNCharactersPikachuSpecialHiNameSprite ((intptr_t)187016)
#define llMNCharactersPurinSpecialHiNameSprite ((intptr_t)187336)
#define llMNCharactersNessSpecialHiNameSprite ((intptr_t)187656)
#define llMNCharactersMarioSpecialNNameSprite ((intptr_t)187976)
#define llMNCharactersFoxSpecialNNameSprite ((intptr_t)188296)
#define llMNCharactersDonkeySpecialNNameSprite ((intptr_t)188616)
#define llMNCharactersSamusSpecialNNameSprite ((intptr_t)188936)
#define llMNCharactersLinkSpecialNNameSprite ((intptr_t)189256)
#define llMNCharactersYoshiSpecialNNameSprite ((intptr_t)189576)
#define llMNCharactersCaptainSpecialNNameSprite ((intptr_t)189896)
#define llMNCharactersKirbySpecialNNameSprite ((intptr_t)190272)
#define llMNCharactersPikachuSpecialNNameSprite ((intptr_t)190600)
#define llMNCharactersPurinSpecialNNameSprite ((intptr_t)190920)
#define llMNCharactersNessSpecialNNameSprite ((intptr_t)191240)
#define llMNCharactersMarioSpecialLwNameSprite ((intptr_t)191560)
#define llMNCharactersFoxSpecialLwNameSprite ((intptr_t)191880)
#define llMNCharactersDonkeySpecialLwNameSprite ((intptr_t)192200)
#define llMNCharactersSamusSpecialLwNameSprite ((intptr_t)192520)
#define llMNCharactersLuigiSpecialLwNameSprite ((intptr_t)192840)
#define llMNCharactersLinkSpecialLwNameSprite ((intptr_t)193160)
#define llMNCharactersYoshiSpecialLwNameSprite ((intptr_t)193480)
#define llMNCharactersCaptainSpecialLwNameSprite ((intptr_t)193800)
#define llMNCharactersKirbySpecialLwNameSprite ((intptr_t)194120)
#define llMNCharactersPikachuSpecialLwNameSprite ((intptr_t)194440)
#define llMNCharactersPurinSpecialLwNameSprite ((intptr_t)194760)
#define llMNCharactersNessSpecialLwNameSprite ((intptr_t)195080)
#define llMNCharactersStoryWallpaperSprite ((intptr_t)198792)
#define llMNPlayersCommonManTextSprite ((intptr_t)64)
#define llMNPlayersCommonComTextSprite ((intptr_t)208)
#define llMNPlayersCommonColon0TextSprite ((intptr_t)352)
#define llMNPlayersCommonColon1TextSprite ((intptr_t)496)
#define llMNPlayersCommonColon2TextSprite ((intptr_t)640)
#define llMNPlayersCommonColon3TextSprite ((intptr_t)784)
#define llMNPlayersCommonColon4TextSprite ((intptr_t)928)
#define llMNPlayersCommonPlayerTextSprite ((intptr_t)1112)
#define llMNPlayersCommon1TextSprite ((intptr_t)1248)
#define llMNPlayersCommon2TextSprite ((intptr_t)1392)
#define llMNPlayersCommon3TextSprite ((intptr_t)1536)
#define llMNPlayersCommon4TextSprite ((intptr_t)1680)
#define llMNPlayersCommon1PTextSprite ((intptr_t)2168)
#define llMNPlayersCommon2PTextSprite ((intptr_t)2648)
#define llMNPlayersCommon3PTextSprite ((intptr_t)3128)
#define llMNPlayersCommon4PTextSprite ((intptr_t)3608)
#define llMNPlayersCommonCPTextSprite ((intptr_t)4088)
#define llMNPlayersCommonHandicapTextSprite ((intptr_t)4360)
#define llMNPlayersCommonCPLevelTextSprite ((intptr_t)4632)
#define llMNPlayersCommonPushTextSprite ((intptr_t)4808)
#define llMNPlayersCommonStartTextSprite ((intptr_t)4984)
#define llMNPlayersCommonButtonTextSprite ((intptr_t)5160)
#define llMNPlayersCommonPressTextSprite ((intptr_t)5336)
#define llMNPlayersCommonMarioTextSprite ((intptr_t)6200)
#define llMNPlayersCommonLuigiTextSprite ((intptr_t)6936)
#define llMNPlayersCommonDKTextSprite ((intptr_t)8184)
#define llMNPlayersCommonSamusTextSprite ((intptr_t)9048)
#define llMNPlayersCommonFoxTextSprite ((intptr_t)9656)
#define llMNPlayersCommonKirbyTextSprite ((intptr_t)10472)
#define llMNPlayersCommonLinkTextSprite ((intptr_t)11168)
#define llMNPlayersCommonYoshiTextSprite ((intptr_t)11992)
#define llMNPlayersCommonPikachuTextSprite ((intptr_t)13048)
#define llMNPlayersCommonNessTextSprite ((intptr_t)13744)
#define llMNPlayersCommonCaptainFalconTextSprite ((intptr_t)14744)
#define llMNPlayersCommonJigglypuffTextSprite ((intptr_t)15800)
#define llMNPlayersCommonInfinityDarkSprite ((intptr_t)16112)
#define llMNPlayersCommonTimeSelectorSprite ((intptr_t)18608)
#define llMNPlayersCommonStockSelectorSprite ((intptr_t)21104)
#define llMNPlayersCommon0DarkSprite ((intptr_t)21384)
#define llMNPlayersCommon1DarkSprite ((intptr_t)21568)
#define llMNPlayersCommon2DarkSprite ((intptr_t)21848)
#define llMNPlayersCommon3DarkSprite ((intptr_t)22120)
#define llMNPlayersCommon4DarkSprite ((intptr_t)22392)
#define llMNPlayersCommon5DarkSprite ((intptr_t)22664)
#define llMNPlayersCommon6DarkSprite ((intptr_t)22936)
#define llMNPlayersCommon7DarkSprite ((intptr_t)23208)
#define llMNPlayersCommon8DarkSprite ((intptr_t)23480)
#define llMNPlayersCommon9DarkSprite ((intptr_t)23752)
#define llMNPlayersCommonHmnLabelSprite ((intptr_t)24648)
#define llMNPlayersCommonCPLabelSprite ((intptr_t)25544)
#define llMNPlayersCommonNALabelSprite ((intptr_t)26440)
#define llMNPlayersCommonCursorHandPointSprite ((intptr_t)28552)
#define llMNPlayersCommonCursorHandGrabSprite ((intptr_t)30440)
#define llMNPlayersCommonCursorHandHoverSprite ((intptr_t)33128)
#define llMNPlayersCommon1PTextGradientSprite ((intptr_t)33384)
#define llMNPlayersCommon2PTextGradientSprite ((intptr_t)33640)
#define llMNPlayersCommon3PTextGradientSprite ((intptr_t)33896)
#define llMNPlayersCommon4PTextGradientSprite ((intptr_t)34152)
#define llMNPlayersCommon1PPuckSprite ((intptr_t)36936)
#define llMNPlayersCommon2PPuckSprite ((intptr_t)39720)
#define llMNPlayersCommon3PPuckSprite ((intptr_t)42504)
#define llMNPlayersCommon4PPuckSprite ((intptr_t)45288)
#define llMNPlayersCommonCPPuckSprite ((intptr_t)48072)
#define llMNPlayersCommonSmashLogoCardLeftSprite ((intptr_t)52656)
#define llMNPlayersCommonSmashLogoCardRightSprite ((intptr_t)57248)
#define llMNPlayersCommonRedLabelSprite ((intptr_t)58312)
#define llMNPlayersCommonGreenLabelSprite ((intptr_t)59368)
#define llMNPlayersCommonBlueLabelSprite ((intptr_t)60424)
#define llMNPlayersCommonArrowLSprite ((intptr_t)60648)
#define llMNPlayersCommonArrowRSprite ((intptr_t)60872)
#define llMNPlayersCommonReadyToFightTextSprite ((intptr_t)62536)
#define llMNPlayersCommonReadyBannerSprite ((intptr_t)62768)
#define llMNPlayersCommonGateMan1PLUT ((intptr_t)66552)
#define llMNPlayersCommonGateMan2PLUT ((intptr_t)66592)
#define llMNPlayersCommonGateMan4PLUT ((intptr_t)66632)
#define llMNPlayersCommonGateMan3PLUT ((intptr_t)66672)
#define llMNPlayersCommonGateCom1PLUT ((intptr_t)70520)
#define llMNPlayersCommonGateCom2PLUT ((intptr_t)70560)
#define llMNPlayersCommonGateCom4PLUT ((intptr_t)70600)
#define llMNPlayersCommonGateCom3PLUT ((intptr_t)70640)
#define llMNPlayersCommonRedCardSprite ((intptr_t)66736)
#define llMNPlayersCommonGrayCardSprite ((intptr_t)70704)
#define llMNPlayersCommonBackButtonSprite ((intptr_t)71112)
#define llMNPlayersGameModesFreeForAllTextSprite ((intptr_t)640)
#define llMNPlayersGameModesTeamBattleTextSprite ((intptr_t)1248)
#define llMNPlayersGameModesTrainingModeTextSprite ((intptr_t)1880)
#define llMNPlayersGameModesBonus1BreakTheTargetsTextSprite ((intptr_t)3032)
#define llMNPlayersGameModesBonus2BoardThePlatformsTextSprite ((intptr_t)4184)
#define llMNPlayersPortraitsCrossSprite ((intptr_t)696)
#define llMNPlayersPortraitsWhiteSquareSprite ((intptr_t)1776)
#define llMNPlayersPortraitsPortraitQuestionMarkSprite ((intptr_t)3944)
#define llMNPlayersPortraitsBlackSquareSprite ((intptr_t)5072)
#define llMNPlayersPortraitsPortraitFireBgSprite ((intptr_t)9424)
#define llMNPlayersPortraitsMarioSprite ((intptr_t)18216)
#define llMNPlayersPortraitsLuigiSprite ((intptr_t)27000)
#define llMNPlayersPortraitsDonkeySprite ((intptr_t)35784)
#define llMNPlayersPortraitsSamusSprite ((intptr_t)44568)
#define llMNPlayersPortraitsFoxSprite ((intptr_t)53352)
#define llMNPlayersPortraitsKirbySprite ((intptr_t)62136)
#define llMNPlayersPortraitsLinkSprite ((intptr_t)70920)
#define llMNPlayersPortraitsYoshiSprite ((intptr_t)79704)
#define llMNPlayersPortraitsPikachuSprite ((intptr_t)88488)
#define llMNPlayersPortraitsNessSprite ((intptr_t)97272)
#define llMNPlayersPortraitsCaptainSprite ((intptr_t)106056)
#define llMNPlayersPortraitsPurinSprite ((intptr_t)114840)
#define llMNPlayersPortraitsCaptainShadowSprite ((intptr_t)123624)
#define llMNPlayersPortraitsLuigiShadowSprite ((intptr_t)132408)
#define llMNPlayersPortraitsNessShadowSprite ((intptr_t)141192)
#define llMNPlayersPortraitsPurinShadowSprite ((intptr_t)149976)
#define llFTEmblemSpritesMarioSprite ((intptr_t)1560)
#define llFTEmblemSpritesDonkeySprite ((intptr_t)3192)
#define llFTEmblemSpritesMetroidSprite ((intptr_t)4824)
#define llFTEmblemSpritesFoxSprite ((intptr_t)6456)
#define llFTEmblemSpritesKirbySprite ((intptr_t)8088)
#define llFTEmblemSpritesZeldaSprite ((intptr_t)9720)
#define llFTEmblemSpritesYoshiSprite ((intptr_t)11352)
#define llFTEmblemSpritesFZeroSprite ((intptr_t)12984)
#define llFTEmblemSpritesPMonstersSprite ((intptr_t)14616)
#define llFTEmblemSpritesMotherSprite ((intptr_t)16248)
#define llMNSelectCommonPlayersSpotlightMObjSub ((intptr_t)1032)
#define llMNSelectCommonStoneBackgroundSprite ((intptr_t)1088)
#define llMNSelectCommonPlayersSpotlightDObjDesc ((intptr_t)1384)
#define llMNPlayersSpotlightMObjSub ((intptr_t)1032)
#define llMNPlayersSpotlightDObjDesc ((intptr_t)1384)
#define llMNPlayers1PMode1PlayerGameTextSprite ((intptr_t)552)
#define llMNPlayers1PModeClosingParenthesisSprite ((intptr_t)712)
#define llMNPlayers1PModeOpeningParenthesisSprite ((intptr_t)872)
#define llMNPlayers1PModeLevelColonTextSprite ((intptr_t)1160)
#define llMNPlayers1PModeStockColonTextSprite ((intptr_t)1448)
#define llMNPlayers1PModeOptionOutlineSprite ((intptr_t)4616)
#define llMNPlayers1PModeBestTimeTextSprite ((intptr_t)4832)
#define llMNPlayers1PModeTotalBestTimeTextSprite ((intptr_t)5136)
#define llMNPlayers1PModeTargetsTextSprite ((intptr_t)5720)
#define llMNPlayers1PModePlatformsTextSprite ((intptr_t)6296)
#define llMNPlayers1PModeSmashLogoSprite ((intptr_t)6480)
#define llMNPlayers1PModeOptionTextSprite ((intptr_t)7880)
#define llMNPlayers1PModeSecSprite ((intptr_t)8008)
#define llMNPlayers1PModeCSecSprite ((intptr_t)8136)
#define llMNPlayers1PModeGateCPLUT ((intptr_t)12856)
#define llMNPlayers1PModeRedCardSprite ((intptr_t)12968)
#define llMNPlayersDifficultyEasyTextSprite ((intptr_t)152)
#define llMNPlayersDifficultyHardTextSprite ((intptr_t)376)
#define llMNPlayersDifficultyNormalTextSprite ((intptr_t)728)
#define llMNPlayersDifficultyVeryEasyTextSprite ((intptr_t)1080)
#define llMNPlayersDifficultyVeryHardTextSprite ((intptr_t)1432)
#define llFTStocksZakoSprite ((intptr_t)128)
#define llGRWallpaperTrainingBlackSprite ((intptr_t)132888)
#define llGRWallpaperTrainingYellowSprite ((intptr_t)132888)
#define llGRWallpaperTrainingBlueSprite ((intptr_t)132888)
#define ll_29_Digit0Sprite ((intptr_t)152)
#define ll_29_Digit1Sprite ((intptr_t)376)
#define ll_29_Digit2Sprite ((intptr_t)728)
#define ll_29_Digit3Sprite ((intptr_t)952)
#define ll_29_Digit4Sprite ((intptr_t)1304)
#define ll_29_Digit5Sprite ((intptr_t)1656)
#define ll_29_Digit6Sprite ((intptr_t)2008)
#define ll_29_Digit7Sprite ((intptr_t)2360)
#define ll_29_Digit8Sprite ((intptr_t)2712)
#define ll_29_Digit9Sprite ((intptr_t)3064)
#define ll_29_NoneTextSprite ((intptr_t)3672)
#define ll_29_MaximTomatoTextSprite ((intptr_t)5304)
#define ll_29_HeartTextSprite ((intptr_t)6040)
#define ll_29_StarTextSprite ((intptr_t)6648)
#define ll_29_BeamSwordTextSprite ((intptr_t)8024)
#define ll_29_HomerunBatTextSprite ((intptr_t)9400)
#define ll_29_FanTextSprite ((intptr_t)9880)
#define ll_29_StarRodTextSprite ((intptr_t)11000)
#define ll_29_RayGunTextSprite ((intptr_t)11864)
#define ll_29_FireFlowerTextSprite ((intptr_t)13240)
#define ll_29_HammerTextSprite ((intptr_t)14232)
#define ll_29_MotionSensorBombSprite ((intptr_t)16376)
#define ll_29_BobOmbTextSprite ((intptr_t)17368)
#define ll_29_BumperTextSprite ((intptr_t)18232)
#define ll_29_GreenShellTextSprite ((intptr_t)19608)
#define ll_29_RedShellTextSprite ((intptr_t)20728)
#define ll_29_PokeballTextSprite ((intptr_t)21848)
#define ll_29_OneSlashOneTextSprite ((intptr_t)22328)
#define ll_29_OneSlashTwoTextSprite ((intptr_t)22808)
#define ll_29_TwoSlashThreeTextSprite ((intptr_t)23416)
#define ll_29_OneSlashFourTextSprite ((intptr_t)23896)
#define ll_29_StandTextSprite ((intptr_t)24632)
#define ll_29_WalkTextSprite ((intptr_t)25368)
#define ll_29_EvadeTextSprite ((intptr_t)26104)
#define ll_29_JumpTextSprite ((intptr_t)26840)
#define ll_29_AttackTextSprite ((intptr_t)27704)
#define ll_29_OpeningBracketSprite ((intptr_t)27928)
#define ll_29_ClosingBracketSprite ((intptr_t)28152)
#define ll_29_PercentageSignSprite ((intptr_t)28504)
#define ll_29_DamageColonTextSprite ((intptr_t)29496)
#define ll_29_ComboColonTextSprite ((intptr_t)30360)
#define ll_29_EnemyColonTextSprite ((intptr_t)31224)
#define ll_29_SpeedColonTextSprite ((intptr_t)31960)
#define ll_29_NoneText2Sprite ((intptr_t)32656)
#define ll_29_MaximTomatoText2Sprite ((intptr_t)34296)
#define ll_29_HeartText2Sprite ((intptr_t)35032)
#define ll_29_StarText2Sprite ((intptr_t)35640)
#define ll_29_BeamSwordText2Sprite ((intptr_t)36936)
#define ll_29_HomerunBatText2Sprite ((intptr_t)38232)
#define ll_29_FanText2Sprite ((intptr_t)38688)
#define ll_29_StarRodText2Sprite ((intptr_t)39688)
#define ll_29_RayGunText2Sprite ((intptr_t)40504)
#define ll_29_FireFlowerText2Sprite ((intptr_t)41752)
#define ll_29_HammerText2Sprite ((intptr_t)42744)
#define ll_29_MotionSensorBomb2Sprite ((intptr_t)44336)
#define ll_29_BobOmbText2Sprite ((intptr_t)45400)
#define ll_29_BumperText2Sprite ((intptr_t)46392)
#define ll_29_GreenShellText2Sprite ((intptr_t)47640)
#define ll_29_RedShellText2Sprite ((intptr_t)48632)
#define ll_29_PokeballText2Sprite ((intptr_t)49568)
#define ll_29_OneSlashOneText2Sprite ((intptr_t)50056)
#define ll_29_OneSlashTwoText2Sprite ((intptr_t)50536)
#define ll_29_TwoSlashThreeText2Sprite ((intptr_t)51016)
#define ll_29_OneSlashFourText2Sprite ((intptr_t)51496)
#define ll_29_StandText2Sprite ((intptr_t)52232)
#define ll_29_WalkText2Sprite ((intptr_t)52968)
#define ll_29_EvadeText2Sprite ((intptr_t)53664)
#define ll_29_JumpText2Sprite ((intptr_t)54408)
#define ll_29_AttackText2Sprite ((intptr_t)55272)
#define ll_29_CPColonTextSprite ((intptr_t)56208)
#define ll_29_ExitTextSprite ((intptr_t)57032)
#define ll_29_ItemColonTextSprite ((intptr_t)57968)
#define ll_29_RedSphereSprite ((intptr_t)59096)
#define ll_29_ResetTextSprite ((intptr_t)59912)
#define ll_29_SpeedTextSprite ((intptr_t)60848)
#define ll_29_ViewColonTextSprite ((intptr_t)61792)
#define ll_29_CloseUpTextSprite ((intptr_t)62856)
#define ll_29_NormalTextSprite ((intptr_t)63720)
#define ll_29_BoxTopSprite ((intptr_t)64272)
#define ll_29_BoxLeftSprite ((intptr_t)65632)
#define ll_29_BoxRightSprite ((intptr_t)66992)
#define ll_29_BoxBottomSprite ((intptr_t)67552)
#define ll_29_ArrowLSprite ((intptr_t)67728)
#define ll_29_ArrowRSprite ((intptr_t)67904)
#define ll_29_NoneTextJapSprite ((intptr_t)68200)
#define ll_29_MaximTomatoTextJapSprite ((intptr_t)68776)
#define ll_29_HeartTextJapSprite ((intptr_t)69352)
#define ll_29_StarTextJapSprite ((intptr_t)69736)
#define ll_29_BeamSwordTextJapSprite ((intptr_t)70216)
#define ll_29_HomerunBatTextJapSprite ((intptr_t)70792)
#define ll_29_FanTextJapSprite ((intptr_t)71176)
#define ll_29_StarRodTextJapSprite ((intptr_t)71752)
#define ll_29_RayGunTextJapSprite ((intptr_t)72136)
#define ll_29_FireFlowerTextJapSprite ((intptr_t)72712)
#define ll_29_HammerTextJapSprite ((intptr_t)73096)
#define ll_29_MotionSensorBombJapSprite ((intptr_t)73800)
#define ll_29_BobOmbTextJapSprite ((intptr_t)74184)
#define ll_29_BumperTextJapSprite ((intptr_t)74568)
#define ll_29_GreenShellTextJapSprite ((intptr_t)75144)
#define ll_29_RedShellTextJapSprite ((intptr_t)75624)
#define ll_29_PokeballTextJapSprite ((intptr_t)76200)
#define ll_29_OneSlashOneTextJapSprite ((intptr_t)76488)
#define ll_29_OneSlashTwoTextJapSprite ((intptr_t)76776)
#define ll_29_TwoSlashThreeTextJapSprite ((intptr_t)77064)
#define ll_29_OneSlashFourTextJapSprite ((intptr_t)77352)
#define ll_29_StandTextJapSprite ((intptr_t)77640)
#define ll_29_WalkTextJapSprite ((intptr_t)77928)
#define ll_29_EvadeTextJapSprite ((intptr_t)78312)
#define ll_29_JumpTextJapSprite ((intptr_t)78696)
#define ll_29_AttackTextJapSprite ((intptr_t)78984)
#define ll_29_EnemyStatusTextJapSprite ((intptr_t)79464)
#define ll_29_QuitTextJapSprite ((intptr_t)80232)
#define ll_29_ItemTextJapSprite ((intptr_t)80616)
#define ll_29_ResetTextJapSprite ((intptr_t)81000)
#define ll_29_SlowTextJapSprite ((intptr_t)81384)
#define ll_29_CameraTextJapSprite ((intptr_t)81768)
#define ll_29_NearTextJapSprite ((intptr_t)82056)
#define ll_29_NormalTextJapSprite ((intptr_t)82344)
#define llMNMapsPeachsCastleTextSprite ((intptr_t)504)
#define llMNMapsSectorZTextSprite ((intptr_t)1080)
#define llMNMapsCongoJungleTextSprite ((intptr_t)1656)
#define llMNMapsPlanetZebesTextSprite ((intptr_t)2232)
#define llMNMapsHyruleCastleTextSprite ((intptr_t)2832)
#define llMNMapsYoshisIslandTextSprite ((intptr_t)3416)
#define llMNMapsSaffronCityTextSprite ((intptr_t)3992)
#define llMNMapsMushroomKingdomTextSprite ((intptr_t)4568)
#define llMNMapsDreamLandTextSprite ((intptr_t)5144)
#define llMNMapsCursorSprite ((intptr_t)6840)
#define llMNMapsQuestionMarkSprite ((intptr_t)7640)
#define llMNMapsStageSelectTextSprite ((intptr_t)9888)
#define llMNMapsWoodenCircleSprite ((intptr_t)14400)
#define llMNMapsPlateRightSprite ((intptr_t)15464)
#define llMNMapsPlateMiddleSprite ((intptr_t)15720)
#define llMNMapsPlateLeftSprite ((intptr_t)16296)
#define llMNMapsPeachsCastleSprite ((intptr_t)19848)
#define llMNMapsSectorZSprite ((intptr_t)23400)
#define llMNMapsCongoJungleSprite ((intptr_t)26952)
#define llMNMapsPlanetZebesSprite ((intptr_t)30504)
#define llMNMapsHyruleCastleSprite ((intptr_t)34056)
#define llMNMapsYoshisIslandSprite ((intptr_t)37608)
#define llMNMapsSaffronCitySprite ((intptr_t)41160)
#define llMNMapsMushroomKingdomSprite ((intptr_t)44712)
#define llMNMapsDreamLandSprite ((intptr_t)48264)
#define llMNMapsTilesSprite ((intptr_t)50984)
#define llMNMapsRandomSmallSprite ((intptr_t)51984)
#define llMNMapsRandomBigSprite ((intptr_t)56880)
#define llMNVSRecordMainQuestionSprite ((intptr_t)112)
#define llMNVSRecordMainUnknownSprite ((intptr_t)360)
#define llMNVSRecordMainLabelTotalSprite ((intptr_t)600)
#define llMNVSRecordMainDigit0Sprite ((intptr_t)752)
#define llMNVSRecordMainDigit1Sprite ((intptr_t)912)
#define llMNVSRecordMainDigit2Sprite ((intptr_t)1072)
#define llMNVSRecordMainDigit3Sprite ((intptr_t)1232)
#define llMNVSRecordMainDigit4Sprite ((intptr_t)1392)
#define llMNVSRecordMainDigit5Sprite ((intptr_t)1552)
#define llMNVSRecordMainDigit6Sprite ((intptr_t)1712)
#define llMNVSRecordMainDigit7Sprite ((intptr_t)1872)
#define llMNVSRecordMainDigit8Sprite ((intptr_t)2032)
#define llMNVSRecordMainDigit9Sprite ((intptr_t)2192)
#define llMNVSRecordMainSymbolPointSprite ((intptr_t)2320)
#define llMNVSRecordMainLabelWinPercentSprite ((intptr_t)2568)
#define llMNVSRecordMainLabelKOsSprite ((intptr_t)2808)
#define llMNVSRecordMainLabelTKOSprite ((intptr_t)3048)
#define llMNVSRecordMainLabelSDPercentSprite ((intptr_t)3288)
#define llMNVSRecordMainLabelTimeSprite ((intptr_t)3600)
#define llMNVSRecordMainLabelUsePercentSprite ((intptr_t)3848)
#define llMNVSRecordMainLabelAvgSprite ((intptr_t)4104)
#define llMNVSRecordMainLabelKOdSprite ((intptr_t)4416)
#define llMNVSRecordMainSymbolSlashSprite ((intptr_t)4560)
#define llMNVSRecordMainUnknown1Sprite ((intptr_t)4888)
#define llMNVSRecordMainUnknown2Sprite ((intptr_t)5208)
#define llMNVSRecordMainBattleScoreSprite ((intptr_t)5584)
#define llMNVSRecordMainDownArrowsSprite ((intptr_t)5736)
#define llMNVSRecordMainSideArrowsSprite ((intptr_t)6056)
#define llMNVSRecordMainMarioIconBWSprite ((intptr_t)6424)
#define llMNVSRecordMainFoxIconBWSprite ((intptr_t)6808)
#define llMNVSRecordMainDonkeyIconBWSprite ((intptr_t)7336)
#define llMNVSRecordMainSamusIconBWSprite ((intptr_t)7816)
#define llMNVSRecordMainLuigiIconBWSprite ((intptr_t)8200)
#define llMNVSRecordMainYoshiIconBWSprite ((intptr_t)8568)
#define llMNVSRecordMainLinkIconBWSprite ((intptr_t)9072)
#define llMNVSRecordMainCaptainIconBWSprite ((intptr_t)9536)
#define llMNVSRecordMainNessIconBWSprite ((intptr_t)9880)
#define llMNVSRecordMainPurinIconBWSprite ((intptr_t)10184)
#define llMNVSRecordMainKirbyIconBWSprite ((intptr_t)10544)
#define llMNVSRecordMainPikachuIconBWSprite ((intptr_t)11056)
#define llMNVSRecordMainMarioIconColorSprite ((intptr_t)11544)
#define llMNVSRecordMainFoxIconColorSprite ((intptr_t)12024)
#define llMNVSRecordMainDonkeyIconColorSprite ((intptr_t)12696)
#define llMNVSRecordMainSamusIconColorSprite ((intptr_t)13368)
#define llMNVSRecordMainLuigiIconColorSprite ((intptr_t)13848)
#define llMNVSRecordMainYoshiIconColorSprite ((intptr_t)14328)
#define llMNVSRecordMainLinkIconColorSprite ((intptr_t)14904)
#define llMNVSRecordMainCaptainIconColorSprite ((intptr_t)15576)
#define llMNVSRecordMainNessIconColorSprite ((intptr_t)16056)
#define llMNVSRecordMainPurinIconColorSprite ((intptr_t)16536)
#define llMNVSRecordMainKirbyIconColorSprite ((intptr_t)17160)
#define llMNVSRecordMainPikachuIconColorSprite ((intptr_t)17832)
#define llMNVSRecordMainPortraitWallpaperSprite ((intptr_t)19760)
#define llMNVSRecordMainLabelSprite ((intptr_t)21544)
#define llMNVSRecordMainSymbolColonSprite ((intptr_t)21696)
#define llMNDataCommonDataHeaderSprite ((intptr_t)2880)
#define llMNDataCommonArrowLSprite ((intptr_t)3040)
#define llMNDataCommonArrowRSprite ((intptr_t)3200)
#define llMNCommonFontsLetterASprite ((intptr_t)64)
#define llMNCommonFontsLetterBSprite ((intptr_t)208)
#define llMNCommonFontsLetterCSprite ((intptr_t)352)
#define llMNCommonFontsLetterDSprite ((intptr_t)496)
#define llMNCommonFontsLetterESprite ((intptr_t)640)
#define llMNCommonFontsLetterFSprite ((intptr_t)784)
#define llMNCommonFontsLetterGSprite ((intptr_t)928)
#define llMNCommonFontsLetterHSprite ((intptr_t)1072)
#define llMNCommonFontsLetterISprite ((intptr_t)1216)
#define llMNCommonFontsLetterJSprite ((intptr_t)1360)
#define llMNCommonFontsLetterKSprite ((intptr_t)1504)
#define llMNCommonFontsLetterLSprite ((intptr_t)1648)
#define llMNCommonFontsLetterMSprite ((intptr_t)1792)
#define llMNCommonFontsLetterNSprite ((intptr_t)1936)
#define llMNCommonFontsLetterOSprite ((intptr_t)2080)
#define llMNCommonFontsLetterPSprite ((intptr_t)2224)
#define llMNCommonFontsLetterQSprite ((intptr_t)2368)
#define llMNCommonFontsLetterRSprite ((intptr_t)2512)
#define llMNCommonFontsLetterSSprite ((intptr_t)2656)
#define llMNCommonFontsLetterTSprite ((intptr_t)2800)
#define llMNCommonFontsLetterUSprite ((intptr_t)2944)
#define llMNCommonFontsLetterVSprite ((intptr_t)3088)
#define llMNCommonFontsLetterWSprite ((intptr_t)3232)
#define llMNCommonFontsLetterXSprite ((intptr_t)3376)
#define llMNCommonFontsLetterYSprite ((intptr_t)3520)
#define llMNCommonFontsLetterZSprite ((intptr_t)3664)
#define llMNCommonFontsSymbolApostropheSprite ((intptr_t)3792)
#define llMNCommonFontsSymbolPercentSprite ((intptr_t)3936)
#define llMNCommonFontsSymbolPeriodSprite ((intptr_t)4048)
#define llMNVSResultsTKOTextSprite ((intptr_t)856)
#define llMNVSResultsPlaceTextSprite ((intptr_t)2448)
#define llMNVSResultsKOsTextSprite ((intptr_t)3384)
#define llMNVSResultsPtsTextSprite ((intptr_t)4312)
#define llMNVSResults0x48c8Sprite ((intptr_t)18632)
#define llMNVSResults1PArrowSprite ((intptr_t)18920)
#define llMNVSResults2PArrowSprite ((intptr_t)19208)
#define llMNVSResults3PArrowSprite ((intptr_t)19496)
#define llMNVSResults4PArrowSprite ((intptr_t)19784)
#define llMNVSResultsWallpaperSprite ((intptr_t)54728)
#define llMNVSResultsWinnerSprite ((intptr_t)58016)
#define llFTEmblemModelsMarioMObjSub ((intptr_t)0)
#define llFTEmblemModelsMarioDObjDesc ((intptr_t)2448)
#define llFTEmblemModelsMarioMatAnimJoint ((intptr_t)2580)
#define llFTEmblemModelsFoxMObjSub ((intptr_t)6464)
#define llFTEmblemModelsFoxDObjDesc ((intptr_t)8656)
#define llFTEmblemModelsFoxMatAnimJoint ((intptr_t)8788)
#define llFTEmblemModelsDonkeyMObjSub ((intptr_t)2816)
#define llFTEmblemModelsDonkeyDObjDesc ((intptr_t)4936)
#define llFTEmblemModelsDonkeyMatAnimJoint ((intptr_t)5068)
#define llFTEmblemModelsMetroidMObjSub ((intptr_t)5232)
#define llFTEmblemModelsMetroidDObjDesc ((intptr_t)6240)
#define llFTEmblemModelsMetroidMatAnimJoint ((intptr_t)6372)
#define llFTEmblemModelsZeldaMObjSub ((intptr_t)8880)
#define llFTEmblemModelsZeldaDObjDesc ((intptr_t)9504)
#define llFTEmblemModelsZeldaMatAnimJoint ((intptr_t)9636)
#define llFTEmblemModelsYoshiMObjSub ((intptr_t)9872)
#define llFTEmblemModelsYoshiDObjDesc ((intptr_t)12048)
#define llFTEmblemModelsYoshiMatAnimJoint ((intptr_t)12180)
#define llFTEmblemModelsFZeroMObjSub ((intptr_t)12272)
#define llFTEmblemModelsFZeroDObjDesc ((intptr_t)14376)
#define llFTEmblemModelsFZeroMatAnimJoint ((intptr_t)14508)
#define llFTEmblemModelsKirbyMObjSub ((intptr_t)14592)
#define llFTEmblemModelsKirbyDObjDesc ((intptr_t)15976)
#define llFTEmblemModelsKirbyMatAnimJoint ((intptr_t)16108)
#define llFTEmblemModelsPMonstersMObjSub ((intptr_t)16192)
#define llFTEmblemModelsPMonstersDObjDesc ((intptr_t)18192)
#define llFTEmblemModelsPMonstersMatAnimJoint ((intptr_t)18324)
#define llFTEmblemModelsMotherMObjSub ((intptr_t)18496)
#define llFTEmblemModelsMotherDObjDesc ((intptr_t)23040)
#define llFTEmblemModelsMotherMatAnimJoint ((intptr_t)23172)
#define llIFCommonDigits0Sprite ((intptr_t)104)
#define llIFCommonDigits1Sprite ((intptr_t)280)
#define llIFCommonDigits2Sprite ((intptr_t)456)
#define llIFCommonDigits3Sprite ((intptr_t)632)
#define llIFCommonDigits4Sprite ((intptr_t)808)
#define llIFCommonDigits5Sprite ((intptr_t)984)
#define llIFCommonDigits6Sprite ((intptr_t)1160)
#define llIFCommonDigits7Sprite ((intptr_t)1336)
#define llIFCommonDigits8Sprite ((intptr_t)1512)
#define llIFCommonDigits9Sprite ((intptr_t)1688)
#define llIFCommonDigitsDashSprite ((intptr_t)1808)
#define llIFCommonDigitsCrossSprite ((intptr_t)2088)
#define llIFCommonDigitsColonSprite ((intptr_t)2264)
#define llIFCommonAnnounceCommonLetterASprite ((intptr_t)1504)
#define llIFCommonAnnounceCommonLetterBSprite ((intptr_t)2472)
#define llIFCommonAnnounceCommonLetterCSprite ((intptr_t)3456)
#define llIFCommonAnnounceCommonLetterDSprite ((intptr_t)4712)
#define llIFCommonAnnounceCommonLetterESprite ((intptr_t)5672)
#define llIFCommonAnnounceCommonLetterFSprite ((intptr_t)6656)
#define llIFCommonAnnounceCommonLetterGSprite ((intptr_t)7944)
#define llIFCommonAnnounceCommonLetterHSprite ((intptr_t)9224)
#define llIFCommonAnnounceCommonLetterISprite ((intptr_t)9912)
#define llIFCommonAnnounceCommonLetterJSprite ((intptr_t)10896)
#define llIFCommonAnnounceCommonLetterKSprite ((intptr_t)12184)
#define llIFCommonAnnounceCommonLetterLSprite ((intptr_t)13144)
#define llIFCommonAnnounceCommonLetterMSprite ((intptr_t)14720)
#define llIFCommonAnnounceCommonLetterNSprite ((intptr_t)16008)
#define llIFCommonAnnounceCommonLetterOSprite ((intptr_t)17584)
#define llIFCommonAnnounceCommonLetterPSprite ((intptr_t)18576)
#define llIFCommonAnnounceCommonLetterQSprite ((intptr_t)20240)
#define llIFCommonAnnounceCommonLetterRSprite ((intptr_t)21528)
#define llIFCommonAnnounceCommonLetterSSprite ((intptr_t)22512)
#define llIFCommonAnnounceCommonLetterTSprite ((intptr_t)23504)
#define llIFCommonAnnounceCommonLetterUSprite ((intptr_t)24792)
#define llIFCommonAnnounceCommonLetterVSprite ((intptr_t)26072)
#define llIFCommonAnnounceCommonLetterWSprite ((intptr_t)27648)
#define llIFCommonAnnounceCommonLetterXSprite ((intptr_t)28936)
#define llIFCommonAnnounceCommonLetterYSprite ((intptr_t)30216)
#define llIFCommonAnnounceCommonLetterZSprite ((intptr_t)31464)
#define llIFCommonAnnounceCommonSymbolExclaimSprite ((intptr_t)32152)
#define llIFCommonAnnounceCommonSymbolPeriodSprite ((intptr_t)32336)
#define llIFCommonPlayerTags1PSprite ((intptr_t)600)
#define llIFCommonPlayerTags2PSprite ((intptr_t)1272)
#define llIFCommonPlayerTags3PSprite ((intptr_t)1944)
#define llIFCommonPlayerTags4PSprite ((intptr_t)2616)
#define llIFCommonPlayerTagsCPSprite ((intptr_t)3288)
#define llIFCommonPlayerTagsAllySprite ((intptr_t)3768)
#define llLBTransitionAeroplaneDObjDesc ((intptr_t)46072)
#define llLBTransitionAeroplaneAnimJoint ((intptr_t)46864)
#define llLBTransitionCheckDObjDesc ((intptr_t)16000)
#define llLBTransitionCheckAnimJoint ((intptr_t)16440)
#define llLBTransitionGakubuthiDObjDesc ((intptr_t)3992)
#define llLBTransitionGakubuthiAnimJoint ((intptr_t)4124)
#define llLBTransitionKannonDObjDesc ((intptr_t)7936)
#define llLBTransitionKannonAnimJoint ((intptr_t)8112)
#define llLBTransitionStarDObjDesc ((intptr_t)9296)
#define llLBTransitionStarAnimJoint ((intptr_t)9428)
#define llLBTransitionSudare1DObjDesc ((intptr_t)29864)
#define llLBTransitionSudare1AnimJoint ((intptr_t)30304)
#define llLBTransitionSudare2DObjDesc ((intptr_t)16032)
#define llLBTransitionSudare2AnimJoint ((intptr_t)16208)
#define llLBTransitionBlockDObjDesc ((intptr_t)19992)
#define llLBTransitionBlockAnimJoint ((intptr_t)21356)
#define llLBTransitionRotScaleDObjDesc ((intptr_t)3992)
#define llLBTransitionRotScaleAnimJoint ((intptr_t)4124)
#define llLBTransitionCurtainDObjDesc ((intptr_t)31456)
#define llLBTransitionCurtainAnimJoint ((intptr_t)31896)
#define llLBTransitionCameraDObjDesc ((intptr_t)16272)
#define llLBTransitionCameraAnimJoint ((intptr_t)16712)
#define llMVCommonRoomBackgroundMObjSub ((intptr_t)17144)
#define llMVCommonRoomBackgroundDObjDesc ((intptr_t)32408)
#define llMVCommonRoomBackgroundMatAnimJoint ((intptr_t)34696)
#define llMVCommonRoomDeskDObjDesc ((intptr_t)36344)
#define llMVCommonRoomHazeDisplayList ((intptr_t)39160)
#define llMVCommonRoomBooksDObjDesc ((intptr_t)42744)
#define llMVCommonRoomBooksAnimJoint ((intptr_t)42928)
#define llMVCommonRoomPencilsDObjDesc ((intptr_t)44728)
#define llMVCommonRoomPencilsAnimJoint ((intptr_t)44912)
#define llMVCommonRoomLampDObjDesc ((intptr_t)48576)
#define llMVCommonRoomLampAnimJoint ((intptr_t)48800)
#define llMVCommonRoomTissuesDisplayList ((intptr_t)50832)
#define llMVCommonRoomTissuesAnimJoint ((intptr_t)51332)
#define llMVCommonRoomLogoMObjSub ((intptr_t)113760)
#define llMVCommonRoomLogoDObjDesc ((intptr_t)115880)
#define llMVCommonRoomLogoMatAnimJoint ((intptr_t)116012)
#define llMVCommonRoomSnapDObjDesc ((intptr_t)117352)
#define llMVCommonRoomSnapAnimJoint ((intptr_t)117488)
#define llMVCommonRoomCloseUpEffectAirMObjSub ((intptr_t)122016)
#define llMVCommonRoomCloseUpEffectAirDObjDesc ((intptr_t)122664)
#define llMVCommonRoomCloseUpEffectAirMatAnimJoint ((intptr_t)122840)
#define llMVCommonRoomCloseUpEffectAirAnimJoint ((intptr_t)122896)
#define llMVCommonRoomCloseUpEffectGroundMObjSub ((intptr_t)127224)
#define llMVCommonRoomCloseUpEffectGroundDObjDesc ((intptr_t)127600)
#define llMVCommonRoomCloseUpEffectGroundMatAnimJoint ((intptr_t)127732)
#define llMVCommonRoomCloseUpEffectGroundAnimJoint ((intptr_t)127792)
#define llMVCommonRoomBossShadowDisplayList ((intptr_t)128912)
#define llMVCommonRoomBossShadowAnimJoint ((intptr_t)129316)
#define llMVCommonRoomDeskGroundMObjSub ((intptr_t)132224)
#define llMVCommonRoomDeskGroundDObjDesc ((intptr_t)140352)
#define llMVCommonRoomDeskGroundMatAnimJoint ((intptr_t)140748)
#define llMVCommonRoomSpotlightMObjSub ((intptr_t)142480)
#define llMVCommonRoomSpotlightDisplayList ((intptr_t)142872)
#define llMVCommonRoomSpotlightMatAnimJoint ((intptr_t)143120)
#define llMVCommonRoomOutsideDisplayList ((intptr_t)147968)
#define llMVCommonRoomSunlightDisplayList ((intptr_t)149256)
#define llMVOpeningPortraitsSet1SamusSprite ((intptr_t)39264)
#define llMVOpeningPortraitsSet1MarioSprite ((intptr_t)78608)
#define llMVOpeningPortraitsSet1FoxSprite ((intptr_t)117952)
#define llMVOpeningPortraitsSet1PikachuSprite ((intptr_t)157296)
#define llMVOpeningPortraitsSet1CoverSprite ((intptr_t)176848)
#define llMVOpeningPortraitsSet2LinkSprite ((intptr_t)39264)
#define llMVOpeningPortraitsSet2KirbySprite ((intptr_t)78608)
#define llMVOpeningPortraitsSet2DonkeySprite ((intptr_t)117952)
#define llMVOpeningPortraitsSet2YoshiSprite ((intptr_t)157296)
#define llMVOpeningRunMarioAnimJoint ((intptr_t)4)
#define llMVOpeningRunFoxAnimJoint ((intptr_t)180)
#define llMVOpeningRunDonkeyAnimJoint ((intptr_t)292)
#define llMVOpeningRunSamusAnimJoint ((intptr_t)388)
#define llMVOpeningRunLinkAnimJoint ((intptr_t)548)
#define llMVOpeningRunYoshiAnimJoint ((intptr_t)820)
#define llMVOpeningRunKirbyAnimJoint ((intptr_t)932)
#define llMVOpeningRunPikachuAnimJoint ((intptr_t)1156)
#define llMVOpeningRunWallpaperSprite ((intptr_t)22688)
#define llMVOpeningRoomScene1CamAnimJoint ((intptr_t)0)
#define llMVOpeningRoomScene2CamAnimJoint ((intptr_t)0)
#define llMVOpeningRoomScene3CamAnimJoint ((intptr_t)0)
#define llMVOpeningRoomScene4CamAnimJoint ((intptr_t)0)
#define llMVOpeningRunMainCamAnimJoint ((intptr_t)0)
#define llMVOpeningNewcomers1PurinShowDisplayList ((intptr_t)23592)
#define llMVOpeningNewcomers1PurinAnimJoint ((intptr_t)24132)
#define llMVOpeningNewcomers1LuigiShowDisplayList ((intptr_t)116792)
#define llMVOpeningNewcomers1LuigiAnimJoint ((intptr_t)118420)
#define llMVOpeningNewcomers1PurinHiddenDisplayList ((intptr_t)132008)
#define llMVOpeningNewcomers1LuigiHiddenDisplayList ((intptr_t)166952)
#define llMVOpeningNewcomers2CaptainShowDisplayList ((intptr_t)115256)
#define llMVOpeningNewcomers2CaptainAnimJoint ((intptr_t)117204)
#define llMVOpeningNewcomers2NessShowDisplayList ((intptr_t)173128)
#define llMVOpeningNewcomers2NessAnimJoint ((intptr_t)174180)
#define llMVOpeningNewcomers2CaptainHiddenDisplayList ((intptr_t)218560)
#define llMVOpeningNewcomers2NessHiddenDisplayList ((intptr_t)244472)
#define llMVOpeningRoomTransitionOverlayDisplayList ((intptr_t)1440)
#define llMVOpeningRoomTransitionOverlayAnimJoint ((intptr_t)1812)
#define llMVOpeningRoomTransitionOutlineDisplayList ((intptr_t)3904)
#define llMVOpeningRoomTransitionOutlineAnimJoint ((intptr_t)4548)
#define llMVOpeningJungleCamAnimJoint ((intptr_t)0)
#define llMVOpeningCommonMarioCamAnimJoint ((intptr_t)0)
#define llMVOpeningCommonDonkeyCamAnimJoint ((intptr_t)48)
#define llMVOpeningCommonSamusCamAnimJoint ((intptr_t)96)
#define llMVOpeningCommonFoxCamAnimJoint ((intptr_t)144)
#define llMVOpeningCommonLinkCamAnimJoint ((intptr_t)192)
#define llMVOpeningCommonYoshiCamAnimJoint ((intptr_t)240)
#define llMVOpeningCommonPikachuCamAnimJoint ((intptr_t)288)
#define llMVOpeningCommonKirbyCamAnimJoint ((intptr_t)336)
#define llMVOpeningClashWallpaperCamAnimJoint ((intptr_t)19120)
#define llMVOpeningClashWallpaperLLMObjSub ((intptr_t)12368)
#define llMVOpeningClashWallpaperLLDisplayList ((intptr_t)12968)
#define llMVOpeningClashWallpaperLLMatAnimJoint ((intptr_t)13400)
#define llMVOpeningClashWallpaperLLAnimJoint ((intptr_t)14032)
#define llMVOpeningClashWallpaperLRMObjSub ((intptr_t)14048)
#define llMVOpeningClashWallpaperLRDisplayList ((intptr_t)14648)
#define llMVOpeningClashWallpaperLRMatAnimJoint ((intptr_t)15080)
#define llMVOpeningClashWallpaperLRAnimJoint ((intptr_t)15712)
#define llMVOpeningClashWallpaperULMObjSub ((intptr_t)15728)
#define llMVOpeningClashWallpaperULDisplayList ((intptr_t)16328)
#define llMVOpeningClashWallpaperULMatAnimJoint ((intptr_t)16768)
#define llMVOpeningClashWallpaperULAnimJoint ((intptr_t)17408)
#define llMVOpeningClashWallpaperURMObjSub ((intptr_t)17424)
#define llMVOpeningClashWallpaperURDisplayList ((intptr_t)18024)
#define llMVOpeningClashWallpaperURMatAnimJoint ((intptr_t)18464)
#define llMVOpeningClashWallpaperURAnimJoint ((intptr_t)19104)
#define llMVOpeningYosterNestDObjDesc ((intptr_t)38920)
#define llMVOpeningYosterGroundDObjDesc ((intptr_t)47504)
#define llMVOpeningYosterGroundAnimJoint ((intptr_t)49008)
#define llMVOpeningYosterCamAnimJoint ((intptr_t)51520)
#define llMVOpeningCliffHillsDObjDesc ((intptr_t)14240)
#define llMVOpeningCliffOcarinaDObjDesc ((intptr_t)26528)
#define llMVOpeningCliffOcarinaAnimJoint ((intptr_t)26704)
#define llMVOpeningCliffCamAnimJoint ((intptr_t)35088)
#define llMVOpeningStandoffGroundDisplayList ((intptr_t)7184)
#define llMVOpeningStandoffLightningMObjSub ((intptr_t)24896)
#define llMVOpeningStandoffLightningDObjDesc ((intptr_t)26960)
#define llMVOpeningStandoffLightningMatAnimJoint ((intptr_t)27576)
#define llMVOpeningStandoffLightningAnimJoint ((intptr_t)28000)
#define llMVOpeningStandoffCamAnimJoint ((intptr_t)29264)
#define llMVOpeningStandoffWallpaperSprite ((intptr_t)46336)
#define llMVOpeningYamabukiLegsDObjDesc ((intptr_t)38216)
#define llMVOpeningYamabukiLegsAnimJoint ((intptr_t)39104)
#define llMVOpeningYamabukiLegsShadowDObjDesc ((intptr_t)45744)
#define llMVOpeningYamabukiLegsShadowAnimJoint ((intptr_t)45968)
#define llMVOpeningYamabukiMBallDObjDesc ((intptr_t)51680)
#define llMVOpeningYamabukiMBallAnimJoint ((intptr_t)51904)
#define llMVOpeningYamabukiCamAnimJoint ((intptr_t)54064)
#define llMVOpeningYamabukiWallpaperSprite ((intptr_t)257624)
#define llMVOpeningClashFightersCamAnimJoint ((intptr_t)5184)
#define llMVOpeningSectorGreatFoxDObjDesc ((intptr_t)55328)
#define llMVOpeningSectorGreatFoxAnimJoint ((intptr_t)55824)
#define llMVOpeningSectorCamAnimJoint ((intptr_t)63904)
#define llMVOpeningSectorArwing0AnimJoint ((intptr_t)57616)
#define llMVOpeningSectorArwing1AnimJoint ((intptr_t)59664)
#define llMVOpeningSectorArwing2AnimJoint ((intptr_t)61888)
#define llMVOpeningSectorCockpitSprite ((intptr_t)248976)
#define llMVOpeningSectorWallpaperSprite ((intptr_t)158856)
#define llMVOpeningRunCrashMObjSub ((intptr_t)10920)
#define llMVOpeningRunCrashDObjDesc ((intptr_t)13816)
#define llMVOpeningRunCrashMatAnimJoint ((intptr_t)14080)
#define llMVEndingOperatorCamAnimJoint ((intptr_t)0)
#define llMNBackupClearHeaderBackupClearSprite ((intptr_t)2912)
#define llMNBackupClear0x11e0Sprite ((intptr_t)4576)
#define llMNBackupClear0x1770Sprite ((intptr_t)6000)
#define llMNBackupClear0x1b98Sprite ((intptr_t)7064)
#define llMNBackupClear0x2300Sprite ((intptr_t)8960)
#define llMNBackupClear0x2890Sprite ((intptr_t)10384)
#define llMNBackupClear0x2d30Sprite ((intptr_t)11568)
#define llMNBackupClear0x33b0Sprite ((intptr_t)13232)
#define llMNBackupClearOptionNewcomersSprite ((intptr_t)14848)
#define llMNBackupClearOption1PHighScoreSprite ((intptr_t)16464)
#define llMNBackupClearOptionVSRecordSprite ((intptr_t)18080)
#define llMNBackupClearOptionSubjectModeSprite ((intptr_t)19696)
#define llMNBackupClearOptionPrizeSprite ((intptr_t)21312)
#define llMNBackupClearOptionAllDataClearSprite ((intptr_t)22928)
#define llMNBackupClearOptionCircleSprite ((intptr_t)23992)
#define llMNBackupClearIsOkayTextSprite ((intptr_t)25544)
#define llMNBackupClearAreYouSureTextSprite ((intptr_t)27096)
#define llMNBackupClearOptionBonusStageTimeSprite ((intptr_t)28704)
#define llMNBackupClearOptionYesHighlightPalette ((intptr_t)29952)
#define llMNBackupClearOptionYesNotPalette ((intptr_t)29992)
#define llMNBackupClearOptionConfirmPalette ((intptr_t)30032)
#define llMNBackupClearOptionYesSprite ((intptr_t)30080)
#define llMNBackupClearOptionNoHighlightPalette ((intptr_t)31328)
#define llMNBackupClearOptionNoNotPalette ((intptr_t)31368)
#define llMNBackupClearOptionNoSprite ((intptr_t)31416)
#define llMNBackupClearHeaderOptionSprite ((intptr_t)2880)
#define llMN1PContinueContinueTextSprite ((intptr_t)6384)
#define llMN1PContinueYesTextSprite ((intptr_t)7688)
#define llMN1PContinueNoTextSprite ((intptr_t)8984)
#define llMN1PContinueCursorSprite ((intptr_t)11768)
#define llMN1PContinueRoomSprite ((intptr_t)123864)
#define llMN1PContinueSpotlightSprite ((intptr_t)137472)
#define llMN1PContinueShadowSprite ((intptr_t)140536)
#define llSC1PStageClear1StageTextSprite ((intptr_t)2520)
#define llSC1PStageClear1GameTextSprite ((intptr_t)4920)
#define llSC1PStageClear1ClearTextSprite ((intptr_t)7512)
#define llSC1PStageClear1SpecialBonusTextSprite ((intptr_t)8288)
#define llSC1PStageClear1ColonTextSprite ((intptr_t)8480)
#define llSC1PStageClear1TimerTextSprite ((intptr_t)9704)
#define llSC1PStageClear1DamageTextSprite ((intptr_t)11080)
#define llSC1PStageClear10x3028Sprite ((intptr_t)12328)
#define llSC1PStageClear10x30f8Sprite ((intptr_t)12536)
#define llSC1PStageClear10x31c8Sprite ((intptr_t)12744)
#define llSC1PStageClear1BonusBorderSprite ((intptr_t)42168)
#define llSC1PStageClear1ResultTextSprite ((intptr_t)44952)
#define llSC1PStageClear1TargetTextSprite ((intptr_t)46328)
#define llSC1PStageClear1BonusPageArrowSprite ((intptr_t)46760)
#define llSC1PStageClear1TimerDamageDigit0Sprite ((intptr_t)47112)
#define llSC1PStageClear1TimerDamageDigit1Sprite ((intptr_t)47464)
#define llSC1PStageClear1TimerDamageDigit2Sprite ((intptr_t)47816)
#define llSC1PStageClear1TimerDamageDigit3Sprite ((intptr_t)48168)
#define llSC1PStageClear1TimerDamageDigit4Sprite ((intptr_t)48520)
#define llSC1PStageClear1TimerDamageDigit5Sprite ((intptr_t)48872)
#define llSC1PStageClear1TimerDamageDigit6Sprite ((intptr_t)49224)
#define llSC1PStageClear1TimerDamageDigit7Sprite ((intptr_t)49576)
#define llSC1PStageClear1TimerDamageDigit8Sprite ((intptr_t)49928)
#define llSC1PStageClear1TimerDamageDigit9Sprite ((intptr_t)50280)
#define llSC1PStageClear1TextShadowSprite ((intptr_t)53704)
#define llSC1PStageClear1BonusTextSprite ((intptr_t)54080)
#define llSC1PStageClear1CheapShotTextSprite ((intptr_t)54568)
#define llSC1PStageClear1StarFinishTextSprite ((intptr_t)55048)
#define llSC1PStageClear1NoItemTextSprite ((intptr_t)55528)
#define llSC1PStageClear1ShieldBreakerTextSprite ((intptr_t)56008)
#define llSC1PStageClear1JudoWarriorTextSprite ((intptr_t)56488)
#define llSC1PStageClear1HawkTextSprite ((intptr_t)56968)
#define llSC1PStageClear1ShooterTextSprite ((intptr_t)57448)
#define llSC1PStageClear1HeavyDamageTextSprite ((intptr_t)57928)
#define llSC1PStageClear1AllVariationsTextSprite ((intptr_t)58408)
#define llSC1PStageClear1ItemStrikeTextSprite ((intptr_t)58888)
#define llSC1PStageClear1DoubleKOTextSprite ((intptr_t)59368)
#define llSC1PStageClear1TricksterTextSprite ((intptr_t)59848)
#define llSC1PStageClear1GiantImpactTextSprite ((intptr_t)60328)
#define llSC1PStageClear1SpeedsterTextSprite ((intptr_t)60808)
#define llSC1PStageClear1ItemThrowTextSprite ((intptr_t)61288)
#define llSC1PStageClear1TripleKOTextSprite ((intptr_t)61768)
#define llSC1PStageClear1LastChanceTextSprite ((intptr_t)62248)
#define llSC1PStageClear1PacifistTextSprite ((intptr_t)62728)
#define llSC1PStageClear1PerfectTextSprite ((intptr_t)63208)
#define llSC1PStageClear1NoMissTextSprite ((intptr_t)63688)
#define llSC1PStageClear1NoDamageTextSprite ((intptr_t)64168)
#define llSC1PStageClear1FullPowerTextSprite ((intptr_t)64648)
#define llSC1PStageClear1MewCatcherTextSprite ((intptr_t)65128)
#define llSC1PStageClear1StarClearTextSprite ((intptr_t)65608)
#define llSC1PStageClear1VegetarianTextSprite ((intptr_t)66088)
#define llSC1PStageClear1HeartThrobTextSprite ((intptr_t)66568)
#define llSC1PStageClear1ThrowDownTextSprite ((intptr_t)67048)
#define llSC1PStageClear1SmashManiaTextSprite ((intptr_t)67528)
#define llSC1PStageClear1SmashlessTextSprite ((intptr_t)68008)
#define llSC1PStageClear1SpecialMoveTextSprite ((intptr_t)68488)
#define llSC1PStageClear1SingleMoveTextSprite ((intptr_t)68968)
#define llSC1PStageClear1PokemonFinishTextSprite ((intptr_t)69448)
#define llSC1PStageClear1BoobyTrapTextSprite ((intptr_t)69928)
#define llSC1PStageClear1FighterStanceTextSprite ((intptr_t)70408)
#define llSC1PStageClear1MysticTextSprite ((intptr_t)70888)
#define llSC1PStageClear1CometMysticTextSprite ((intptr_t)71368)
#define llSC1PStageClear1AcidClearTextSprite ((intptr_t)71848)
#define llSC1PStageClear1BumperClearTextSprite ((intptr_t)72328)
#define llSC1PStageClear1TornadoClearTextSprite ((intptr_t)72808)
#define llSC1PStageClear1ArwingClearTextSprite ((intptr_t)73288)
#define llSC1PStageClear1CounterAttackTextSprite ((intptr_t)73768)
#define llSC1PStageClear1MeteorSmashTextSprite ((intptr_t)74248)
#define llSC1PStageClear1AerialTextSprite ((intptr_t)74728)
#define llSC1PStageClear1LastSecondTextSprite ((intptr_t)75208)
#define llSC1PStageClear1Lucky3TextSprite ((intptr_t)75688)
#define llSC1PStageClear1JackpotTextSprite ((intptr_t)76168)
#define llSC1PStageClear1YoshiRainbowTextSprite ((intptr_t)76648)
#define llSC1PStageClear1KirbyRanksTextSprite ((intptr_t)77128)
#define llSC1PStageClear1BrosCalamityTextSprite ((intptr_t)77608)
#define llSC1PStageClear1DKDefenderTextSprite ((intptr_t)78088)
#define llSC1PStageClear1DKPerfectTextSprite ((intptr_t)78568)
#define llSC1PStageClear1GoodFriendTextSprite ((intptr_t)79048)
#define llSC1PStageClear1TrueFriendTextSprite ((intptr_t)79528)
#define llSC1PStageClear1NoMissClearTextSprite ((intptr_t)80008)
#define llSC1PStageClear1NoDamageClearTextSprite ((intptr_t)80488)
#define llSC1PStageClear1SpeedKingTextSprite ((intptr_t)80968)
#define llSC1PStageClear1SpeedDemonTextSprite ((intptr_t)81448)
#define llSC1PStageClear1VeryEasyClearTextSprite ((intptr_t)81928)
#define llSC1PStageClear1EasyClearTextSprite ((intptr_t)82408)
#define llSC1PStageClear1NormalClearTextSprite ((intptr_t)82888)
#define llSC1PStageClear1HardClearTextSprite ((intptr_t)83368)
#define llSC1PStageClear1VeryHardClearTextSprite ((intptr_t)83848)
#define llSC1PStageClear2ScoreTextSprite ((intptr_t)1032)
#define llIFCommonGameStatusOrangeLetterGSprite ((intptr_t)19832)
#define llIFCommonGameStatusOrangeLetterOSprite ((intptr_t)42800)
#define llIFCommonGameStatusOrangeExclamationMarkSprite ((intptr_t)50032)
#define llIFCommonGameStatusBlueLetterTSprite ((intptr_t)58536)
#define llIFCommonGameStatusBlueLetterISprite ((intptr_t)63296)
#define llIFCommonGameStatusBlueLetterMSprite ((intptr_t)75744)
#define llIFCommonGameStatusBlueLetterESprite ((intptr_t)83168)
#define llIFCommonGameStatusBlueLetterUSprite ((intptr_t)93880)
#define llIFCommonGameStatusBlueLetterPSprite ((intptr_t)102376)
#define llIFCommonGameStatusBlueLetterSSprite ((intptr_t)112120)
#define llIFCommonGameStatusBlueLetterASprite ((intptr_t)122472)
#define llIFCommonGameStatusBlueLetterGSprite ((intptr_t)133000)
#define llIFCommonGameStatusRodSprite ((intptr_t)133520)
#define llIFCommonGameStatusFrameSprite ((intptr_t)137056)
#define llIFCommonGameStatusRodShadowSprite ((intptr_t)137336)
#define llIFCommonGameStatusLampRedDimSprite ((intptr_t)137552)
#define llIFCommonGameStatusLampYellowDimSprite ((intptr_t)137744)
#define llIFCommonGameStatusLampBlueDimSprite ((intptr_t)138152)
#define llIFCommonGameStatusLampRedLightSprite ((intptr_t)139560)
#define llIFCommonGameStatusLampYellowLightSprite ((intptr_t)140680)
#define llIFCommonGameStatusLampBlueLightSprite ((intptr_t)143128)
#define llIFCommonGameStatusLampRedContourSprite ((intptr_t)145960)
#define llIFCommonGameStatusLampYellowContourSprite ((intptr_t)149024)
#define llIFCommonGameStatusLampBlueContourSprite ((intptr_t)152208)
#define llEFCommonEffects1DamageSlashMObjSub ((intptr_t)29664)
#define llEFCommonEffects1DamageSlashDObjDesc ((intptr_t)30544)
#define llEFCommonEffects1DamageSlashAnimJoint ((intptr_t)30720)
#define llEFCommonEffects1DamageSlashMatAnimJoint ((intptr_t)30816)
#define llEFCommonEffects1ImpactWaveMObjSub ((intptr_t)31360)
#define llEFCommonEffects1ImpactWaveDObjDesc ((intptr_t)31784)
#define llEFCommonEffects1ImpactWaveAnimJoint ((intptr_t)32064)
#define llEFCommonEffects1ImpactWaveMatAnimJoint ((intptr_t)32160)
#define llEFCommonEffects1FlyOrbsDObjDesc ((intptr_t)32384)
#define llEFCommonEffects1FlyOrbsAnimJoint ((intptr_t)32576)
#define llEFCommonEffects1CommonSparkMObjSub ((intptr_t)36544)
#define llEFCommonEffects1CommonSparkDObjDesc ((intptr_t)36768)
#define llEFCommonEffects1CommonSparkAnimJoint ((intptr_t)36944)
#define llEFCommonEffects1CommonSparkMatAnimJoint ((intptr_t)37056)
#define llEFCommonEffects1DamageFlyMDustMObjSub ((intptr_t)51576)
#define llEFCommonEffects1DamageFlyMDustDObjDesc ((intptr_t)51912)
#define llEFCommonEffects1DamageFlyMDustAnimJoint ((intptr_t)51936)
#define llEFCommonEffects1DamageFlyMDustMatAnimJoint ((intptr_t)52032)
#define llEFCommonEffects1QuakeMag0AnimJoint ((intptr_t)52160)
#define llEFCommonEffects1QuakeMag1AnimJoint ((intptr_t)52256)
#define llEFCommonEffects1QuakeMag2AnimJoint ((intptr_t)52464)
#define llEFCommonEffects1QuakeMag3AnimJoint ((intptr_t)52672)
#define llEFCommonEffects2ShockSmallMObjSub ((intptr_t)5160)
#define llEFCommonEffects2ShockSmallDObjDesc ((intptr_t)5376)
#define llEFCommonEffects2ShockSmallMatAnimJoint ((intptr_t)5488)
#define llEFCommonEffects2FireSparkMObjSub ((intptr_t)7840)
#define llEFCommonEffects2FireSparkDObjDesc ((intptr_t)8256)
#define llEFCommonEffects2FireSparkAnimJoint ((intptr_t)8400)
#define llEFCommonEffects2FireSparkMatAnimJoint ((intptr_t)8560)
#define llEFCommonEffects2CatchSwirlMObjSub ((intptr_t)10080)
#define llEFCommonEffects2CatchSwirlDObjDesc ((intptr_t)8888)
#define llEFCommonEffects2CatchSwirlAnimJoint ((intptr_t)10400)
#define llEFCommonEffects2CatchSwirlMatAnimJoint ((intptr_t)10928)
#define llEFCommonEffects2ReflectBreakMObjSub ((intptr_t)13208)
#define llEFCommonEffects2ReflectBreakDObjDesc ((intptr_t)12152)
#define llEFCommonEffects2ReflectBreakAnimJoint ((intptr_t)13472)
#define llEFCommonEffects2ReflectBreakMatAnimJoint ((intptr_t)13728)
#define llEFCommonEffects2ShadowTextureImage ((intptr_t)14952)
#define llEFCommonEffects2DeadExplodeDefaultMObjSub ((intptr_t)21480)
#define llEFCommonEffects2DeadExplodeDefaultDObjDesc ((intptr_t)20232)
#define llEFCommonEffects2DeadExplodeDefaultAnimJoint ((intptr_t)21712)
#define llEFCommonEffects2DeadExplodeDefaultMatAnimJoint ((intptr_t)22640)
#define llEFCommonEffects2DeadExplode1MatAnimJoint ((intptr_t)22752)
#define llEFCommonEffects2DeadExplode2MatAnimJoint ((intptr_t)22528)
#define llEFCommonEffects2DeadExplode3MatAnimJoint ((intptr_t)22864)
#define llEFCommonEffects2DeadExplode4MatAnimJoint ((intptr_t)22640)
#define llEFCommonEffects2NessPKFlashMObjSub ((intptr_t)27904)
#define llEFCommonEffects2NessPKFlashDObjDesc ((intptr_t)27456)
#define llEFCommonEffects2NessPKFlashAnimJoint ((intptr_t)28048)
#define llEFCommonEffects2NessPKFlashMatAnimJoint ((intptr_t)28192)
#define llEFCommonEffects3MBallRaysMObjSub ((intptr_t)264)
#define llEFCommonEffects3MBallRaysDObjDesc ((intptr_t)1576)
#define llEFCommonEffects3MBallRaysAnimJoint ((intptr_t)1808)
#define llEFCommonEffects3MBallRaysMatAnimJoint ((intptr_t)2144)
#define llEFCommonEffects3RebirthHaloDObjDesc ((intptr_t)10944)
#define llEFCommonEffects3RebirthHaloAnimJoint ((intptr_t)11120)
#define llEFCommonEffects3ItemGetSwirlMObjSub ((intptr_t)11432)
#define llEFCommonEffects3ItemGetSwirlDObjDesc ((intptr_t)12656)
#define llEFCommonEffects3ItemGetSwirlAnimJoint ((intptr_t)12976)
#define llEFCommonEffects3ItemGetSwirlMatAnimJoint ((intptr_t)13456)
#define llIFCommonItemArrowSprite ((intptr_t)80)
#define llStageDreamLandSprite ((intptr_t)158856)
#define llStageZebesSprite ((intptr_t)158856)
#define llMVOpeningRoomWallpaperSprite ((intptr_t)158856)
#define ll_91_0x26c88Sprite ((intptr_t)158856)
#define llStageJungleSprite ((intptr_t)158856)
#define llStageYoshiSprite ((intptr_t)158856)
#define llStagePokemonSprite ((intptr_t)158856)
#define llStageCastleSprite ((intptr_t)158856)
#define ll_96_0x26c88Sprite ((intptr_t)158856)
#define ll_97_0x26c88Sprite ((intptr_t)158856)
#define ll_98_0x26c88Sprite ((intptr_t)158856)
#define llStageSectorSprite ((intptr_t)158856)
#define ll_119_0x26c88Sprite ((intptr_t)158856)
#define llBonus2CommonPlatformSmallDObjDesc ((intptr_t)15784)
#define llBonus2CommonPlatformSmallAnimJoint ((intptr_t)15968)
#define llBonus2CommonPlatformSmallMObjSub ((intptr_t)14112)
#define llBonus2CommonPlatformSmallMatAnimJoint ((intptr_t)16128)
#define llBonus2CommonPlatformMediumDObjDesc ((intptr_t)17880)
#define llBonus2CommonPlatformMediumAnimJoint ((intptr_t)18064)
#define llBonus2CommonPlatformMediumMObjSub ((intptr_t)16240)
#define llBonus2CommonPlatformMediumMatAnimJoint ((intptr_t)18224)
#define llBonus2CommonPlatformLargeDObjDesc ((intptr_t)19976)
#define llBonus2CommonPlatformLargeAnimJoint ((intptr_t)20160)
#define llBonus2CommonPlatformLargeMObjSub ((intptr_t)18336)
#define llBonus2CommonPlatformLargeMatAnimJoint ((intptr_t)20336)
#define llBonus2CommonBoardedPlatformSmallDObjDesc ((intptr_t)21792)
#define llBonus2CommonBoardedPlatformSmallAnimJoint ((intptr_t)21968)
#define llBonus2CommonBoardedPlatformMediumDObjDesc ((intptr_t)23424)
#define llBonus2CommonBoardedPlatformMediumAnimJoint ((intptr_t)23600)
#define llBonus2CommonBoardedPlatformLargeDObjDesc ((intptr_t)25056)
#define llBonus2CommonBoardedPlatformLargeAnimJoint ((intptr_t)25232)
#define llSC1PStageClear3PlatformSprite ((intptr_t)192)
#define llSC1PStageClear3TargetSprite ((intptr_t)464)
#define llFoxSpecial3_1B34_AnimJoint ((intptr_t)6964)
#define llFoxSpecial3_1B84_AnimJoint ((intptr_t)7044)
#define llFoxSpecial3EntryArwingDObjDesc ((intptr_t)11312)
#define llFoxSpecial3_2E74_AnimJoint ((intptr_t)11892)
#define llFoxSpecial3_2EB4_AnimJoint ((intptr_t)11956)
#define llFTManagerCommonShieldDObjDesc ((intptr_t)768)
#define llIFCommonPlayerDamageDigit0Sprite ((intptr_t)328)
#define llIFCommonPlayerDamageDigit1Sprite ((intptr_t)728)
#define llIFCommonPlayerDamageDigit2Sprite ((intptr_t)1280)
#define llIFCommonPlayerDamageDigit3Sprite ((intptr_t)1688)
#define llIFCommonPlayerDamageDigit4Sprite ((intptr_t)2240)
#define llIFCommonPlayerDamageDigit5Sprite ((intptr_t)2648)
#define llIFCommonPlayerDamageDigit6Sprite ((intptr_t)3200)
#define llIFCommonPlayerDamageDigit7Sprite ((intptr_t)3608)
#define llIFCommonPlayerDamageDigit8Sprite ((intptr_t)4160)
#define llIFCommonPlayerDamageDigit9Sprite ((intptr_t)4720)
#define llIFCommonPlayerDamageSymbolPercentSprite ((intptr_t)5208)
#define llIFCommonPlayerDamageSymbolHPSprite ((intptr_t)5592)
#define llIFCommonTimerDigit0Sprite ((intptr_t)312)
#define llIFCommonTimerDigit1Sprite ((intptr_t)552)
#define llIFCommonTimerDigit2Sprite ((intptr_t)936)
#define llIFCommonTimerDigit3Sprite ((intptr_t)1320)
#define llIFCommonTimerDigit4Sprite ((intptr_t)1704)
#define llIFCommonTimerDigit5Sprite ((intptr_t)2088)
#define llIFCommonTimerDigit6Sprite ((intptr_t)2472)
#define llIFCommonTimerDigit7Sprite ((intptr_t)2856)
#define llIFCommonTimerDigit8Sprite ((intptr_t)3240)
#define llIFCommonTimerDigit9Sprite ((intptr_t)3624)
#define llIFCommonTimerSymbolColonSprite ((intptr_t)3848)
#define llIFCommonTimerSymbolCrossSprite ((intptr_t)4120)
#define llIFCommonTimerSymbolUnderscoreSprite ((intptr_t)4240)
#define llIFCommonTimerSymbolSecSprite ((intptr_t)4416)
#define llIFCommonTimerSymbolCSecSprite ((intptr_t)4664)
#define llIFCommonPlayerArrowsDObjDesc ((intptr_t)392)
#define llIFCommonPlayerArrowsAnimJoint ((intptr_t)624)
#define llIFCommonPlayerMagnifyFrameImage ((intptr_t)712)
#define llIFCommonPlayerMagnifyDisplayList ((intptr_t)48)
#define llMNTitleLogoAnimCutoutSprite ((intptr_t)36808)
#define llMNTitleLogoAnimStrikeVSprite ((intptr_t)38888)
#define llMNTitleLogoAnimStrikeHSprite ((intptr_t)39752)
#define llMNTitleLogoAnimFullSprite ((intptr_t)48048)
#define llMNTitleBorderUpperSprite ((intptr_t)49672)
#define llMNTitleGradientSprite ((intptr_t)62072)
#define llMNTitleTMSprite ((intptr_t)62360)
#define llMNTitleCutoutSprite ((intptr_t)72072)
#define llMNTitleTMUnkSprite ((intptr_t)72360)
#define llMNTitleCopyrightSprite ((intptr_t)86816)
#define llMNTitlePressStartSprite ((intptr_t)88648)
#define llMNTitleSuperSprite ((intptr_t)91944)
#define llMNTitleSmashSprite ((intptr_t)148936)
#define llMNTitleBrosSprite ((intptr_t)151944)
#define llMNTitleLogoAnimJoint ((intptr_t)152016)
#define llMNTitleLabelsAnimJoint ((intptr_t)152400)
#define llMNTitlePressStartAnimJoint ((intptr_t)153808)
#define llMNTitleSlashAnimJoint ((intptr_t)155248)
#define llMNTitleSlashMatAnimJoint ((intptr_t)155488)
#define llMNTitleLogoDObjDesc ((intptr_t)155680)
#define llMNTitleLabelsDObjDesc ((intptr_t)155952)
#define llMNTitlePressStartDObjDesc ((intptr_t)156352)
#define llMNTitleSlashMObjSub ((intptr_t)165848)
#define llMNTitleSlashDObjDesc ((intptr_t)167336)
#define llMNTitleFireDObjDesc ((intptr_t)167600)
#define llMNTitleFireAnimJoint ((intptr_t)167952)
#define llMNTitleFireAnimFrame1Sprite ((intptr_t)4120)
#define llMNTitleFireAnimFrame2Sprite ((intptr_t)8312)
#define llMNTitleFireAnimFrame3Sprite ((intptr_t)12504)
#define llMNTitleFireAnimFrame4Sprite ((intptr_t)16696)
#define llMNTitleFireAnimFrame5Sprite ((intptr_t)20888)
#define llMNTitleFireAnimFrame6Sprite ((intptr_t)25080)
#define llMNTitleFireAnimFrame7Sprite ((intptr_t)29272)
#define llMNTitleFireAnimFrame8Sprite ((intptr_t)33464)
#define llMNTitleFireAnimFrame9Sprite ((intptr_t)37656)
#define llMNTitleFireAnimFrame10Sprite ((intptr_t)41848)
#define llMNTitleFireAnimFrame11Sprite ((intptr_t)46040)
#define llMNTitleFireAnimFrame12Sprite ((intptr_t)50232)
#define llMNTitleFireAnimFrame13Sprite ((intptr_t)54424)
#define llMNTitleFireAnimFrame14Sprite ((intptr_t)58616)
#define llMNTitleFireAnimFrame15Sprite ((intptr_t)62808)
#define llMNTitleFireAnimFrame16Sprite ((intptr_t)67000)
#define llMNTitleFireAnimFrame17Sprite ((intptr_t)71192)
#define llMNTitleFireAnimFrame18Sprite ((intptr_t)75384)
#define llMNTitleFireAnimFrame19Sprite ((intptr_t)79576)
#define llMNTitleFireAnimFrame20Sprite ((intptr_t)83768)
#define llMNTitleFireAnimFrame21Sprite ((intptr_t)87960)
#define llMNTitleFireAnimFrame22Sprite ((intptr_t)92152)
#define llMNTitleFireAnimFrame23Sprite ((intptr_t)96344)
#define llMNTitleFireAnimFrame24Sprite ((intptr_t)100536)
#define llMNTitleFireAnimFrame25Sprite ((intptr_t)104728)
#define llMNTitleFireAnimFrame26Sprite ((intptr_t)108920)
#define llMNTitleFireAnimFrame27Sprite ((intptr_t)113112)
#define llMNTitleFireAnimFrame28Sprite ((intptr_t)117304)
#define llMNTitleFireAnimFrame29Sprite ((intptr_t)121496)
#define llMNTitleFireAnimFrame30Sprite ((intptr_t)125688)
#define llMNNoControllerSprite ((intptr_t)33888)
#define llMNCongraKirbyBottomSprite ((intptr_t)132888)
#define llMNCongraKirbyTopSprite ((intptr_t)132888)
#define llMNCongraYoshiBottomSprite ((intptr_t)132888)
#define llMNCongraYoshiTopSprite ((intptr_t)132888)
#define llMNCongraPikachuBottomSprite ((intptr_t)132888)
#define llMNCongraPikachuTopSprite ((intptr_t)132888)
#define llMNCongraSamusBottomSprite ((intptr_t)132888)
#define llMNCongraSamusTopSprite ((intptr_t)132888)
#define llMNCongraLinkBottomSprite ((intptr_t)132888)
#define llMNCongraLinkTopSprite ((intptr_t)132888)
#define llMNCongraPurinBottomSprite ((intptr_t)132888)
#define llMNCongraPurinTopSprite ((intptr_t)132888)
#define llMNCongraCaptainBottomSprite ((intptr_t)132888)
#define llMNCongraCaptainTopSprite ((intptr_t)132888)
#define llMNCongraDonkeyBottomSprite ((intptr_t)132888)
#define llMNCongraDonkeyTopSprite ((intptr_t)132888)
#define llMNCongraMarioBottomSprite ((intptr_t)132888)
#define llMNCongraMarioTopSprite ((intptr_t)132888)
#define llMNCongraLuigiBottomSprite ((intptr_t)132888)
#define llMNCongraLuigiTopSprite ((intptr_t)132888)
#define llMNCongraFoxBottomSprite ((intptr_t)132888)
#define llMNCongraFoxTopSprite ((intptr_t)132888)
#define llMNCongraNessBottomSprite ((intptr_t)132888)
#define llMNCongraNessTopSprite ((intptr_t)132888)
#define llN64LogoSprite ((intptr_t)29632)
#define llSCStaffrollNameAndJobAUpperImage ((intptr_t)8)
#define llSCStaffrollNameAndJobALowerImage ((intptr_t)376)
#define llSCStaffrollNameAndJobBUpperImage ((intptr_t)536)
#define llSCStaffrollNameAndJobBLowerImage ((intptr_t)728)
#define llSCStaffrollNameAndJobCUpperImage ((intptr_t)920)
#define llSCStaffrollNameAndJobCLowerImage ((intptr_t)1112)
#define llSCStaffrollNameAndJobDUpperImage ((intptr_t)1272)
#define llSCStaffrollNameAndJobDLowerImage ((intptr_t)1640)
#define llSCStaffrollNameAndJobEUpperImage ((intptr_t)1832)
#define llSCStaffrollNameAndJobELowerImage ((intptr_t)2024)
#define llSCStaffrollNameAndJobFUpperImage ((intptr_t)2184)
#define llSCStaffrollNameAndJobFLowerImage ((intptr_t)2376)
#define llSCStaffrollNameAndJobGUpperImage ((intptr_t)2568)
#define llSCStaffrollNameAndJobGLowerImage ((intptr_t)2936)
#define llSCStaffrollNameAndJobHUpperImage ((intptr_t)3128)
#define llSCStaffrollNameAndJobHLowerImage ((intptr_t)3496)
#define llSCStaffrollNameAndJobIUpperImage ((intptr_t)3688)
#define llSCStaffrollNameAndJobILowerImage ((intptr_t)3880)
#define llSCStaffrollNameAndJobJUpperImage ((intptr_t)4072)
#define llSCStaffrollNameAndJobJLowerImage ((intptr_t)4264)
#define llSCStaffrollNameAndJobKUpperImage ((intptr_t)4488)
#define llSCStaffrollNameAndJobKLowerImage ((intptr_t)4856)
#define llSCStaffrollNameAndJobLUpperImage ((intptr_t)5048)
#define llSCStaffrollNameAndJobLLowerImage ((intptr_t)5240)
#define llSCStaffrollNameAndJobMUpperImage ((intptr_t)5432)
#define llSCStaffrollNameAndJobMLowerImage ((intptr_t)5800)
#define llSCStaffrollNameAndJobNUpperImage ((intptr_t)6104)
#define llSCStaffrollNameAndJobNLowerImage ((intptr_t)6472)
#define llSCStaffrollNameAndJobOUpperImage ((intptr_t)6632)
#define llSCStaffrollNameAndJobOLowerImage ((intptr_t)7000)
#define llSCStaffrollNameAndJobPUpperImage ((intptr_t)7304)
#define llSCStaffrollNameAndJobPLowerImage ((intptr_t)7496)
#define llSCStaffrollNameAndJobQUpperImage ((intptr_t)7688)
#define llSCStaffrollNameAndJobQLowerImage ((intptr_t)8056)
#define llSCStaffrollNameAndJobRUpperImage ((intptr_t)8248)
#define llSCStaffrollNameAndJobRLowerImage ((intptr_t)8440)
#define llSCStaffrollNameAndJobSUpperImage ((intptr_t)8600)
#define llSCStaffrollNameAndJobSLowerImage ((intptr_t)8792)
#define llSCStaffrollNameAndJobTUpperImage ((intptr_t)8952)
#define llSCStaffrollNameAndJobTLowerImage ((intptr_t)9144)
#define llSCStaffrollNameAndJobUUpperImage ((intptr_t)9336)
#define llSCStaffrollNameAndJobULowerImage ((intptr_t)9528)
#define llSCStaffrollNameAndJobVUpperImage ((intptr_t)9688)
#define llSCStaffrollNameAndJobVLowerImage ((intptr_t)10056)
#define llSCStaffrollNameAndJobWUpperImage ((intptr_t)10216)
#define llSCStaffrollNameAndJobWLowerImage ((intptr_t)10584)
#define llSCStaffrollNameAndJobXUpperImage ((intptr_t)10888)
#define llSCStaffrollNameAndJobXLowerImage ((intptr_t)11256)
#define llSCStaffrollNameAndJobYUpperImage ((intptr_t)11416)
#define llSCStaffrollNameAndJobYLowerImage ((intptr_t)11608)
#define llSCStaffrollNameAndJobZUpperImage ((intptr_t)11800)
#define llSCStaffrollNameAndJobZLowerImage ((intptr_t)12168)
#define llSCStaffrollNameAndJobCommaImage ((intptr_t)12312)
#define llSCStaffrollNameAndJobPeriodImage ((intptr_t)12408)
#define llSCStaffrollNameAndJobApostropheImage ((intptr_t)12472)
#define llSCStaffrollNameAndJob4Image ((intptr_t)12568)
#define llSCStaffrollTextBoxAUpperSprite ((intptr_t)12888)
#define llSCStaffrollTextBoxALowerSprite ((intptr_t)13072)
#define llSCStaffrollTextBoxBUpperSprite ((intptr_t)13288)
#define llSCStaffrollTextBoxBLowerSprite ((intptr_t)13488)
#define llSCStaffrollTextBoxCUpperSprite ((intptr_t)13704)
#define llSCStaffrollTextBoxCLowerSprite ((intptr_t)13888)
#define llSCStaffrollTextBoxDUpperSprite ((intptr_t)14104)
#define llSCStaffrollTextBoxDLowerSprite ((intptr_t)14304)
#define llSCStaffrollTextBoxEUpperSprite ((intptr_t)14520)
#define llSCStaffrollTextBoxELowerSprite ((intptr_t)14704)
#define llSCStaffrollTextBoxFUpperSprite ((intptr_t)14920)
#define llSCStaffrollTextBoxFLowerSprite ((intptr_t)15120)
#define llSCStaffrollTextBoxGUpperSprite ((intptr_t)15336)
#define llSCStaffrollTextBoxGLowerSprite ((intptr_t)15528)
#define llSCStaffrollTextBoxHUpperSprite ((intptr_t)15736)
#define llSCStaffrollTextBoxHLowerSprite ((intptr_t)15936)
#define llSCStaffrollTextBoxIUpperSprite ((intptr_t)16152)
#define llSCStaffrollTextBoxILowerSprite ((intptr_t)16352)
#define llSCStaffrollTextBoxJUpperSprite ((intptr_t)16568)
#define llSCStaffrollTextBoxJLowerSprite ((intptr_t)16776)
#define llSCStaffrollTextBoxKUpperSprite ((intptr_t)16984)
#define llSCStaffrollTextBoxKLowerSprite ((intptr_t)17184)
#define llSCStaffrollTextBoxLUpperSprite ((intptr_t)17400)
#define llSCStaffrollTextBoxLLowerSprite ((intptr_t)17600)
#define llSCStaffrollTextBoxMUpperSprite ((intptr_t)17816)
#define llSCStaffrollTextBoxMLowerSprite ((intptr_t)18000)
#define llSCStaffrollTextBoxNUpperSprite ((intptr_t)18216)
#define llSCStaffrollTextBoxNLowerSprite ((intptr_t)18400)
#define llSCStaffrollTextBoxOUpperSprite ((intptr_t)18616)
#define llSCStaffrollTextBoxOLowerSprite ((intptr_t)18800)
#define llSCStaffrollTextBoxPUpperSprite ((intptr_t)19016)
#define llSCStaffrollTextBoxPLowerSprite ((intptr_t)19208)
#define llSCStaffrollTextBoxQUpperSprite ((intptr_t)19416)
#define llSCStaffrollTextBoxQLowerSprite ((intptr_t)19608)
#define llSCStaffrollTextBoxRUpperSprite ((intptr_t)19816)
#define llSCStaffrollTextBoxRLowerSprite ((intptr_t)20000)
#define llSCStaffrollTextBoxSUpperSprite ((intptr_t)20216)
#define llSCStaffrollTextBoxSLowerSprite ((intptr_t)20400)
#define llSCStaffrollTextBoxTUpperSprite ((intptr_t)20616)
#define llSCStaffrollTextBoxTLowerSprite ((intptr_t)20816)
#define llSCStaffrollTextBoxUUpperSprite ((intptr_t)21032)
#define llSCStaffrollTextBoxULowerSprite ((intptr_t)21216)
#define llSCStaffrollTextBoxVUpperSprite ((intptr_t)21432)
#define llSCStaffrollTextBoxVLowerSprite ((intptr_t)21616)
#define llSCStaffrollTextBoxWUpperSprite ((intptr_t)21832)
#define llSCStaffrollTextBoxWLowerSprite ((intptr_t)22016)
#define llSCStaffrollTextBoxXUpperSprite ((intptr_t)22232)
#define llSCStaffrollTextBoxXLowerSprite ((intptr_t)22416)
#define llSCStaffrollTextBoxYUpperSprite ((intptr_t)22632)
#define llSCStaffrollTextBoxYLowerSprite ((intptr_t)22824)
#define llSCStaffrollTextBoxZUpperSprite ((intptr_t)23032)
#define llSCStaffrollTextBoxZLowerSprite ((intptr_t)23216)
#define llSCStaffrollTextBoxColonSprite ((intptr_t)23408)
#define llSCStaffrollTextBoxCommaSprite ((intptr_t)23552)
#define llSCStaffrollTextBoxPeriodSprite ((intptr_t)23696)
#define llSCStaffrollTextBoxDashSprite ((intptr_t)23832)
#define llSCStaffrollTextBox1Sprite ((intptr_t)24040)
#define llSCStaffrollTextBox2Sprite ((intptr_t)24248)
#define llSCStaffrollTextBox3Sprite ((intptr_t)24456)
#define llSCStaffrollTextBox4Sprite ((intptr_t)24664)
#define llSCStaffrollTextBox5Sprite ((intptr_t)24872)
#define llSCStaffrollTextBox6Sprite ((intptr_t)25080)
#define llSCStaffrollTextBox7Sprite ((intptr_t)25288)
#define llSCStaffrollTextBox8Sprite ((intptr_t)25496)
#define llSCStaffrollTextBox9Sprite ((intptr_t)25704)
#define llSCStaffrollTextBox0Sprite ((intptr_t)25912)
#define llSCStaffrollTextBoxQuoteSprite ((intptr_t)26048)
#define llSCStaffrollTextBoxAmpersSprite ((intptr_t)26264)
#define llSCStaffrollTextBoxSlashSprite ((intptr_t)26456)
#define llSCStaffrollTextBoxApostropheSprite ((intptr_t)26592)
#define llSCStaffrollTextBoxQuestionSprite ((intptr_t)26808)
#define llSCStaffrollTextBoxBracketOpenSprite ((intptr_t)27016)
#define llSCStaffrollTextBoxBracketCloseSprite ((intptr_t)27224)
#define llSCStaffrollTextBoxEAccentSprite ((intptr_t)27424)
#define llSCStaffrollCrosshairSprite ((intptr_t)27992)
#define llSCStaffrollTextBoxBracketLeftSprite ((intptr_t)28568)
#define llSCStaffrollInterpolation ((intptr_t)29444)
#define llSCStaffrollAnimJoint ((intptr_t)29496)
#define llSCStaffrollDObjDesc ((intptr_t)30912)
#define llSCStaffrollTextBoxBracketRightSprite ((intptr_t)29144)
#define llMNSoundTestMusicTextSprite ((intptr_t)1080)
#define llMNSoundTestSoundTextSprite ((intptr_t)2496)
#define llMNSoundTestVoiceTextSprite ((intptr_t)3656)
#define llMNSoundTestCapsuleRightSprite ((intptr_t)4408)
#define llMNSoundTestColonExitTextSprite ((intptr_t)4616)
#define llMNSoundTestColonFadeOutTextSprite ((intptr_t)4936)
#define llMNSoundTestColonPlayTextSprite ((intptr_t)5200)
#define llMNSoundTestSoundTestTextSprite ((intptr_t)7096)
#define llMNSoundTestStartButtonSprite ((intptr_t)7504)
#define llIFCommonBattlePausePlayerNum1PSprite ((intptr_t)120)
#define llIFCommonBattlePausePlayerNum2PSprite ((intptr_t)312)
#define llIFCommonBattlePausePlayerNum3PSprite ((intptr_t)504)
#define llIFCommonBattlePausePlayerNum4PSprite ((intptr_t)696)
#define llIFCommonBattlePauseDecalPauseSprite ((intptr_t)1080)
#define llIFCommonBattlePauseDecalPlusSprite ((intptr_t)1240)
#define llIFCommonBattlePauseDecalResetSprite ((intptr_t)1552)
#define llIFCommonBattlePauseDecalSmashBallSprite ((intptr_t)1752)
#define llIFCommonBattlePauseDecalRetrySprite ((intptr_t)2088)
#define llIFCommonBattlePauseDecalAButtonSprite ((intptr_t)2392)
#define llIFCommonBattlePauseDecalBButtonSprite ((intptr_t)2696)
#define llIFCommonBattlePauseDecalZTriggerSprite ((intptr_t)3032)
#define llIFCommonBattlePauseDecalRTriggerSprite ((intptr_t)3320)
#define llIFCommonBattlePauseDecalArrowsSprite ((intptr_t)5432)
#define llIFCommonBattlePauseDecalControlStickSprite ((intptr_t)6056)
#define llIFCommonBattlePauseDecalLTriggerSprite ((intptr_t)6344)
#define llSCExplainGraphicsStickMObjSub ((intptr_t)20520)
#define llSCExplainGraphicsStickDObjDesc ((intptr_t)21248)
#define llSCExplainGraphicsStickNeutralMatAnimJoint ((intptr_t)21392)
#define llSCExplainGraphicsStickHoldUpMatAnimJoint ((intptr_t)21440)
#define llSCExplainGraphicsStickTapUpMatAnimJoint ((intptr_t)21488)
#define llSCExplainGraphicsStickHoldForwardMatAnimJoint ((intptr_t)21552)
#define llSCExplainGraphicsStickTapForwardMatAnimJoint ((intptr_t)21584)
#define llSCExplainGraphicsTapSparkMObjSub ((intptr_t)23192)
#define llSCExplainGraphicsTapSparkDisplayList ((intptr_t)23400)
#define llSCExplainGraphicsTapSparkMatAnimJoint ((intptr_t)23584)
#define llSCExplainGraphicsSpecialMoveRGBDisplayList ((intptr_t)24128)
#define llSCExplainGraphicsDamage1Sprite ((intptr_t)27736)
#define llSCExplainGraphicsDamage2Sprite ((intptr_t)29400)
#define llSCExplainGraphicsDamage3Sprite ((intptr_t)31800)
#define llSCExplainGraphicsShieldSprite ((intptr_t)33304)
#define llSCExplainGraphicsStartFightingSprite ((intptr_t)35960)
#define llSCExplainGraphicsPlayerCountSprite ((intptr_t)37288)
#define llSCExplainGraphicsHereTextSprite ((intptr_t)38440)
#define llSCExplainGraphicsBannerSprite ((intptr_t)66144)
#define llSCExplainGraphicsTapTheStickSprite ((intptr_t)73568)
#define llSCExplainGraphicsJumpSprite ((intptr_t)76640)
#define llSCExplainGraphicsMidairJumpSprite ((intptr_t)79448)
#define llSCExplainGraphicsAttackSprite ((intptr_t)80368)
#define llSCExplainGraphicsPowerAttackSprite ((intptr_t)83016)
#define llSCExplainGraphicsSmashAttackSprite ((intptr_t)85552)
#define llSCExplainGraphicsKnockThemOffSprite ((intptr_t)89152)
#define llSCExplainGraphicsBUpGetBackSprite ((intptr_t)98272)
#define llSCExplainGraphicsSpecialMovesSprite ((intptr_t)107584)
#define llSCExplainGraphicsDodgeSprite ((intptr_t)109072)
#define llSCExplainGraphicsThrowEnemySprite ((intptr_t)111720)
#define llSCExplainGraphicsGrabItemsSprite ((intptr_t)112976)
#define llSCExplainGraphicsUseItemsSprite ((intptr_t)114352)
#define llSCExplainGraphicsThrowItemsSprite ((intptr_t)118048)
#define llSCExplainGraphicsAButtonSprite ((intptr_t)119608)
#define llSCExplainGraphicsBButtonSprite ((intptr_t)121160)
#define llSCExplainGraphicsZButtonSprite ((intptr_t)122712)
#define llSCExplainGraphicsPlusSymbolSprite ((intptr_t)122904)
#define llSYKseg1ValidateFunc ((intptr_t)0)
#define llSYKseg1ValidateNBytes ((intptr_t)48)
#define llSYSignValidateFunc ((intptr_t)0)
#define llSYSignValidateNBytes ((intptr_t)64)
#define llMarioMainFireballWeaponAttributes ((intptr_t)0)
#define llMarioSpecial1FireballWeaponAttributes ((intptr_t)0)
#define llFoxMainMotionLwReflectorFTSpecialColl ((intptr_t)6576)
#define llFoxSpecial1BlasterWeaponAttributes ((intptr_t)0)
#define llSamusMainBombWeaponAttributes ((intptr_t)12)
#define llSamusSpecial1ChargeShotWeaponAttributes ((intptr_t)0)
#define llLuigiSpecial1FireballWeaponAttributes ((intptr_t)0)
#define llLinkMainSpinAttackWeaponAttributes ((intptr_t)12)
#define llLinkMainBombItemAttributes ((intptr_t)64)
#define llLinkMainBombAttackEvents ((intptr_t)136)
#define llLinkMainBombBloatScales ((intptr_t)168)
#define llLinkSpecial1BoomerangWeaponAttributes ((intptr_t)0)
#define llKirbyMainMotionSpecialNFTKirbyCopy ((intptr_t)0)
#define llKirbyMainMotionftKirbyAttack100Effect ((intptr_t)4640)
#define llKirbyMainCutterWeaponAttributes ((intptr_t)8)
#define llCaptainMainMotionSpecialHiVec2h ((intptr_t)0)
#define llNessMainMotionAttackS4ReflectorFTSpecialColl ((intptr_t)4372)
#define llNessMainMotionLwAbsorbFTSpecialColl ((intptr_t)5844)
#define llNessMainPKThunderWeaponAttributes ((intptr_t)12)
#define llNessMainPKThunderTrailWeaponAttributes ((intptr_t)64)
#define llNessSpecial1PKFireWeaponAttributes ((intptr_t)0)
#define llNessSpecial1PKFireItemAttributes ((intptr_t)52)
#define llPikachuMainThunderHeadWeaponAttributes ((intptr_t)12)
#define llPikachuMainThunderTrailWeaponAttributes ((intptr_t)64)
#define llPikachuSpecial1ThunderJoltAirWeaponAttributes ((intptr_t)0)
#define llPikachuSpecial1ThunderJoltGroundWeaponAttributes ((intptr_t)52)
#define llYoshiMainEggThrowWeaponAttributes ((intptr_t)12)
#define llYoshiMainStarWeaponAttributes ((intptr_t)64)
#define llBossMainMotionBulletNormalWeaponAttributes ((intptr_t)1908)
#define llBossMainMotionBulletHardWeaponAttributes ((intptr_t)1960)
#define llITCommonDataContainerVelocitiesY ((intptr_t)0)
#define llITCommonDataCapsuleItemAttributes ((intptr_t)80)
#define llITCommonDataCapsuleAttackEvents ((intptr_t)152)
#define llITCommonDataTomatoItemAttributes ((intptr_t)184)
#define llITCommonDataHeartItemAttributes ((intptr_t)256)
#define llITCommonDataStarItemAttributes ((intptr_t)328)
#define llITCommonDataSwordItemAttributes ((intptr_t)400)
#define llITCommonDataBatItemAttributes ((intptr_t)472)
#define llITCommonDataHarisenItemAttributes ((intptr_t)544)
#define llITCommonDataLGunItemAttributes ((intptr_t)616)
#define llITCommonDataLGunAmmoWeaponAttributes ((intptr_t)688)
#define llITCommonDataFFlowerItemAttributes ((intptr_t)740)
#define llITCommonDataFFlowerFlameWeaponAttributes ((intptr_t)812)
#define llITCommonDataFFlowerFlameAngles ((intptr_t)864)
#define llITCommonDataHammerItemAttributes ((intptr_t)884)
#define llITCommonDataMSBombItemAttributes ((intptr_t)956)
#define llITCommonDataMSBombAttackEvents ((intptr_t)1028)
#define llITCommonDataBombHeiItemAttributes ((intptr_t)1060)
#define llITCommonDataBombHeiAttackEvents ((intptr_t)1132)
#define llITCommonDataStarRodItemAttributes ((intptr_t)1164)
#define llITCommonDataStarRodWeaponAttributes ((intptr_t)1236)
#define llITCommonDataStarRodSmashWeaponAttributes ((intptr_t)1288)
#define llITCommonDataGShellItemAttributes ((intptr_t)1340)
#define llITCommonDataRShellItemAttributes ((intptr_t)1412)
#define llITCommonDataBoxItemAttributes ((intptr_t)1484)
#define llITCommonDataBoxAttackEvents ((intptr_t)1556)
#define llITCommonDataTaruItemAttributes ((intptr_t)1588)
#define llITCommonDataTaruAttackEvents ((intptr_t)1660)
#define llITCommonDataMBallThrownFileHead ((intptr_t)1764)
#define llITCommonDataMBallItemAttributes ((intptr_t)1764)
#define llITCommonDataWarkItemAttributes ((intptr_t)1836)
#define llITCommonDataWarkRockWeaponAttributes ((intptr_t)1908)
#define llITCommonDataKabigonItemAttributes ((intptr_t)1960)
#define llITCommonDataTosakintoItemAttributes ((intptr_t)2032)
#define llITCommonDataMewItemAttributes ((intptr_t)2104)
#define llITCommonDataNyarsItemAttributes ((intptr_t)2176)
#define llITCommonDataNyarsCoinWeaponAttributes ((intptr_t)2248)
#define llITCommonDataLizardonItemAttributes ((intptr_t)2300)
#define llITCommonDataLizardonFlameWeaponAttributes ((intptr_t)2372)
#define llITCommonDataSpearItemAttributes ((intptr_t)2444)
#define llITCommonDataSpearSwarmWeaponAttributes ((intptr_t)2516)
#define llITCommonDataKamexItemAttributes ((intptr_t)2568)
#define llITCommonDataKamexHydroWeaponAttributes ((intptr_t)2640)
#define llITCommonDataMLuckyItemAttributes ((intptr_t)2692)
#define llITCommonDataEggItemAttributes ((intptr_t)2764)
#define llITCommonDataEggAttackEvents ((intptr_t)2836)
#define llITCommonDataStarmieItemAttributes ((intptr_t)2868)
#define llITCommonDataStarmieSwiftWeaponAttributes ((intptr_t)2940)
#define llITCommonDataSawamuraItemAttributes ((intptr_t)2992)
#define llITCommonDataDogasItemAttributes ((intptr_t)3064)
#define llITCommonDataDogasSmogWeaponAttributes ((intptr_t)3136)
#define llITCommonDataPippiItemAttributes ((intptr_t)3188)
#define llITCommonDataPippiSwarmWeaponAttributes ((intptr_t)3260)
#define llITCommonDataGBumperItemAttributes ((intptr_t)3312)
#define llITCommonDataHarisenDataStart ((intptr_t)8600)
#define llITCommonDataBombHeiDataStart ((intptr_t)13304)
#define llITCommonDataBombHeiWalkRightDisplayList ((intptr_t)13072)
#define llITCommonDataBombHeiWalkLeftDisplayList ((intptr_t)13504)
#define llITCommonDataBombHeiWalkMatAnimJoint ((intptr_t)13752)
#define llITCommonDataKirbyStarDObjDesc ((intptr_t)21592)
#define llITCommonDataShellDataStart ((intptr_t)24456)
#define llITCommonDataShellAnimJoint ((intptr_t)24600)
#define llITCommonDataShellMatAnimJoint ((intptr_t)24648)
#define llITCommonDataBoxDataStart ((intptr_t)26488)
#define llITCommonDataBoxEffectDisplayList ((intptr_t)26864)
#define llITCommonDataNBumperItemAttributes ((intptr_t)1692)
#define llITCommonDataNBumperDataStart ((intptr_t)30280)
#define llITCommonDataNBumperWaitMObjSub ((intptr_t)31288)
#define llITCommonDataNBumperWaitDisplayList ((intptr_t)31480)
#define llITCommonDataMBallThrownMObjSub ((intptr_t)37152)
#define llITCommonDataMBallDataStart ((intptr_t)37936)
#define llITCommonDataMBallThrownDObjDesc ((intptr_t)37936)
#define llITCommonDataMBallMatAnimJoint ((intptr_t)38176)
#define llITCommonDataMBallThrownLAnimJoint ((intptr_t)38368)
#define llITCommonDataMBallThrownRAnimJoint ((intptr_t)38544)
#define llITCommonDataMBallThrownLMatAnimJoint ((intptr_t)38720)
#define llITCommonDataMBallThrownRMatAnimJoint ((intptr_t)38928)
#define llITCommonDataWarkDataStart ((intptr_t)41280)
#define llITCommonDataWarkDisplayList ((intptr_t)42560)
#define llITCommonDataKabigonAnimJoint ((intptr_t)45400)
#define llITCommonDataTosakintoDataStart ((intptr_t)46856)
#define llITCommonDataTosakintoAnimJoint ((intptr_t)47052)
#define llITCommonDataTosakintoMatAnimJoint ((intptr_t)47372)
#define llITCommonDataMewDataStart ((intptr_t)48320)
#define llITCommonDataNyarsAnimJoint ((intptr_t)49456)
#define llITCommonDataLizardonDataStart ((intptr_t)54720)
#define llITCommonDataLizardonAnimJoint ((intptr_t)54872)
#define llITCommonDataLizardonMatAnimJoint ((intptr_t)54920)
#define llITCommonDataSpearDataStart ((intptr_t)57144)
#define llITCommonDataSpearAnimJoint ((intptr_t)57340)
#define llITCommonDataSpearMatAnimJoint ((intptr_t)57644)
#define llITCommonDataKamexDisplayList ((intptr_t)60768)
#define llITCommonDataKamexDataStart ((intptr_t)60000)
#define llITCommonDataStarmieDataStart ((intptr_t)70304)
#define llITCommonDataStarmieMatAnimJoint ((intptr_t)70456)
#define llITCommonDataDogasDataStart ((intptr_t)75808)
#define llITCommonDataDogasAnimJoint ((intptr_t)75996)
#define llITCommonDataLuckyDataStart ((intptr_t)65536)
#define llITCommonDataLuckyAnimJoint ((intptr_t)65724)
#define llITCommonDataSawamuraDataStart ((intptr_t)73536)
#define llITCommonDataSawamuraDisplayList ((intptr_t)74560)
#define llITCommonDataPippiDataStart ((intptr_t)79256)
#define llITCommonDataMonsterAnimBankStart ((intptr_t)79396)
#define llSCExplainMain0KeyEvent ((intptr_t)0)
#define llSCExplainMain1KeyEvent ((intptr_t)2516)
#define llSCExplainMain2KeyEvent ((intptr_t)5116)
#define llSCExplainMain3KeyEvent ((intptr_t)5120)
#define llSCExplainMainExplainPhase ((intptr_t)5124)
#define llSC1PTrainingModeDisplayLabelPosSpriteArray ((intptr_t)0)
#define llSC1PTrainingModeDisplayOptionSpriteArray ((intptr_t)32)
#define llSC1PTrainingModeMenuLabelPosSpriteArray ((intptr_t)188)
#define llSC1PTrainingModeMenuOptionSpriteArray ((intptr_t)316)
#define llSC1PTrainingMode0x10CPosSpriteArray ((intptr_t)268)
#define llSC1PTrainingMode0x1B8PosSpriteArray ((intptr_t)440)
#define llGRPupupuMapMapHeader ((intptr_t)20)
#define llGRPupupuMapWhispyEyesTransformKindsMObjSub ((intptr_t)3840)
#define llGRPupupuMapMapHead ((intptr_t)4336)
#define llGRPupupuMapWhispyEyesTransformKindsDObjDesc ((intptr_t)4336)
#define llGRPupupuMapWhispyMouthTransformKindsMObjSub ((intptr_t)5040)
#define llGRPupupuMapWhispyMouthTransformKindsDObjDesc ((intptr_t)6000)
#define llGRPupupuMapFlowersBackTransformKindsDObjDesc ((intptr_t)10880)
#define llGRPupupuMapFlowersFrontTransformKindsDObjDesc ((intptr_t)12792)
#define llGRPupupuMapWhispyEyesLeftTurnAnimJoint ((intptr_t)4512)
#define llGRPupupuMapWhispyEyesLeftTurnMatAnimJoint ((intptr_t)4576)
#define llGRPupupuMapWhispyEyesLeftBlinkAnimJoint ((intptr_t)4784)
#define llGRPupupuMapWhispyEyesRightTurnAnimJoint ((intptr_t)4640)
#define llGRPupupuMapWhispyEyesRightTurnMatAnimJoint ((intptr_t)4720)
#define llGRPupupuMapWhispyEyesRightBlinkAnimJoint ((intptr_t)4912)
#define llGRPupupuMapWhispyMouthLeftStretchAnimJoint ((intptr_t)6320)
#define llGRPupupuMapWhispyMouthLeftStretchMatAnimJoint ((intptr_t)6656)
#define llGRPupupuMapWhispyMouthLeftTurnAnimJoint ((intptr_t)7136)
#define llGRPupupuMapWhispyMouthLeftTurnMatAnimJoint ((intptr_t)7392)
#define llGRPupupuMapWhispyMouthLeftOpenAnimJoint ((intptr_t)7808)
#define llGRPupupuMapWhispyMouthLeftOpenMatAnimJoint ((intptr_t)8368)
#define llGRPupupuMapWhispyMouthLeftCloseAnimJoint ((intptr_t)8448)
#define llGRPupupuMapWhispyMouthLeftCloseMatAnimJoint ((intptr_t)8864)
#define llGRPupupuMapWhispyMouthRightStretchAnimJoint ((intptr_t)6720)
#define llGRPupupuMapWhispyMouthRightStretchMatAnimJoint ((intptr_t)7072)
#define llGRPupupuMapWhispyMouthRightTurnAnimJoint ((intptr_t)7472)
#define llGRPupupuMapWhispyMouthRightTurnMatAnimJoint ((intptr_t)7728)
#define llGRPupupuMapWhispyMouthRightOpenAnimJoint ((intptr_t)8944)
#define llGRPupupuMapWhispyMouthRightOpenMatAnimJoint ((intptr_t)9536)
#define llGRPupupuMapWhispyMouthRightCloseAnimJoint ((intptr_t)9616)
#define llGRPupupuMapWhispyMouthRightCloseMatAnimJoint ((intptr_t)10048)
#define llGRPupupuMapWhispyMouthLeftOpenTexture ((intptr_t)11232)
#define llGRPupupuMapWhispyMouthLeftBlowTexture ((intptr_t)11312)
#define llGRPupupuMapWhispyMouthLeftCloseTexture ((intptr_t)11392)
#define llGRPupupuMapWhispyMouthRightOpenTexture ((intptr_t)11472)
#define llGRPupupuMapWhispyMouthRightBlowTexture ((intptr_t)11552)
#define llGRPupupuMapWhispyMouthRightCloseTexture ((intptr_t)11632)
#define llGRPupupuMapWhispyEyesLeft0Texture ((intptr_t)13280)
#define llGRPupupuMapWhispyEyesLeft1Texture ((intptr_t)13392)
#define llGRPupupuMapWhispyEyesLeft2Texture ((intptr_t)13488)
#define llGRPupupuMapWhispyEyesRight0Texture ((intptr_t)13584)
#define llGRPupupuMapWhispyEyesRight1Texture ((intptr_t)13760)
#define llGRPupupuMapWhispyEyesRight2Texture ((intptr_t)13920)
#define llGRPupupuMapBrontoDObjDesc ((intptr_t)13240)
#define llGRPupupuMapBrontoLAnimJoint ((intptr_t)13376)
#define llGRPupupuMapBrontoLMatAnimJoint ((intptr_t)13536)
#define llGRPupupuMapBrontoMObjSub ((intptr_t)12784)
#define llGRPupupuMapBrontoRAnimJoint ((intptr_t)14048)
#define llGRPupupuMapBrontoRMatAnimJoint ((intptr_t)14240)
#define llGRPupupuMapDataStart ((intptr_t)7392)
#define llGRPupupuMapDededeDObjDesc ((intptr_t)16000)
#define llGRPupupuMapDededeFarAnimJoint ((intptr_t)16144)
#define llGRPupupuMapDededeNearAnimJoint ((intptr_t)16512)
#define llGRPupupuSmallMapMapHeader ((intptr_t)20)
#define llGRZebesMapMapHeader ((intptr_t)20)
#define llGRZebesMapAcidGRAttackColl ((intptr_t)188)
#define llGRZebesMapAcidMObjSub ((intptr_t)2240)
#define llGRZebesMapAcidDObjDesc ((intptr_t)2824)
#define llGRZebesMapAcidAnimJoint ((intptr_t)2960)
#define llGRZebesMapAcidMatAnimJoint ((intptr_t)3024)
#define llGRZebesMapDataStart ((intptr_t)23232)
#define llGRZebesMapRidleyAnimJoint ((intptr_t)53104)
#define llGRZebesMapRidleyDObjDesc ((intptr_t)52968)
#define llGRZebesMapRidleyMObjSub ((intptr_t)52368)
#define llGRZebesMapRidleyMatAnimJoint ((intptr_t)53296)
#define llGRZebesMapShipAnimJoint ((intptr_t)57008)
#define llGRZebesMapShipDObjDesc ((intptr_t)56872)
#define llGRZebesMapShipMObjSub ((intptr_t)56032)
#define llGRZebesMapShipMatAnimJoint ((intptr_t)57104)
#define llGRPupupuTestMapMapHeader ((intptr_t)20)
#define llGRCastleMapMapHeader ((intptr_t)20)
#define llGRCastleMapMapHead ((intptr_t)0)
#define llGRCastleMapDataStart ((intptr_t)10760)
#define llGRCastleMapLakituDObjDesc ((intptr_t)16664)
#define llGRCastleMapLakituRAnimJoint ((intptr_t)16928)
#define llGRCastleMapLakituLAnimJoint ((intptr_t)17264)
#define llGRInishieMapMapHeader ((intptr_t)20)
#define llGRInishieMapScaleDObjDesc ((intptr_t)896)
#define llGRInishieMapMapHead ((intptr_t)1520)
#define llGRInishieMapScaleRetractAnimJoint ((intptr_t)1844)
#define llGRInishieMapPowerBlockGRAttackColl ((intptr_t)188)
#define llGRInishieMapPakkunItemAttributes ((intptr_t)288)
#define llGRInishieMapPakkunAppearAnimJoint ((intptr_t)3272)
#define llGRInishieMapPakkunAppearMatAnimJoint ((intptr_t)3320)
#define llGRInishieMapPakkunDamagedMatAnimJoint ((intptr_t)3588)
#define llGRInishieMapPowerBlockItemAttributes ((intptr_t)216)
#define llGRInishieMapPowerBlockDataStart ((intptr_t)4600)
#define llGRInishieMapPowerBlockAnimJoint ((intptr_t)4744)
#define llGRJungleMapMapHeader ((intptr_t)20)
#define llGRJungleMapTaruCannThrowHitDesc ((intptr_t)188)
#define llGRJungleMapMapHead ((intptr_t)2712)
#define llGRJungleMapTaruCannDefaultAnimJoint ((intptr_t)2848)
#define llGRJungleMapTaruCannFillAnimJoint ((intptr_t)2920)
#define llGRJungleMapTaruCannShootAnimJoint ((intptr_t)3064)
#define llGRJungleMapBirdMObjSub ((intptr_t)62000)
#define llGRJungleMapBirdDObjDesc ((intptr_t)62464)
#define llGRJungleMapBirdAnimJoint ((intptr_t)62608)
#define llGRJungleMapBirdMatAnimJoint ((intptr_t)62736)
#define llGRJungleMapDataStart ((intptr_t)39032)
#define llGRSectorMapMapHeader ((intptr_t)20)
#define llGRSectorMapMapHead ((intptr_t)0)
#define llGRSectorMapArwingLaser2DWeaponAttributes ((intptr_t)188)
#define llGRSectorMapArwingLaser3DWeaponAttributes ((intptr_t)240)
#define llGRSectorMapArwing0SectorDesc ((intptr_t)0)
#define llGRSectorMapArwing1SectorDesc ((intptr_t)592)
#define llGRSectorMapArwing2SectorDesc ((intptr_t)1744)
#define llGRSectorMapArwing3SectorDesc ((intptr_t)992)
#define llGRSectorMapArwing4SectorDesc ((intptr_t)3344)
#define llGRSectorMapArwing5SectorDesc ((intptr_t)3760)
#define llGRSectorMapArwing6SectorDesc ((intptr_t)5392)
#define llGRSectorMapArwing7SectorDesc ((intptr_t)4560)
#define llGRSectorMapArwing0AnimJoint ((intptr_t)0)
#define llGRSectorMapArwing1AnimJoint ((intptr_t)7476)
#define llGRSectorMapArwing2AnimJoint ((intptr_t)7588)
#define llGRSectorMapArwing3AnimJoint ((intptr_t)7620)
#define llGRSectorMapArwing4AnimJoint ((intptr_t)7508)
#define llGRSectorMapArwing5AnimJoint ((intptr_t)7652)
#define llGRSectorMapDataStart ((intptr_t)34432)
#define llGRSectorMapRocketAnimJoint ((intptr_t)44464)
#define llGRSectorMapRocketDObjDesc ((intptr_t)44288)
#define llGRSectorMapShipDObjDesc ((intptr_t)46840)
#define llGRSectorMapShipLAnimJoint ((intptr_t)46976)
#define llGRSectorMapShipMObjSub ((intptr_t)46016)
#define llGRSectorMapShipMatAnimJoint ((intptr_t)47024)
#define llGRSectorMapShipRAnimJoint ((intptr_t)47072)
#define llGRYosterMapMapHeader ((intptr_t)20)
#define llGRYosterMapMapHead ((intptr_t)256)
#define llGRYosterMap_1E0_AnimJoint ((intptr_t)480)
#define llGRYosterMap_4B8_MObjSub ((intptr_t)1208)
#define llGRYosterMapCloudDisplayList ((intptr_t)1408)
#define llGRYosterMapCloudSolidMatAnimJoint ((intptr_t)1648)
#define llGRYosterMapCloudEvaporateMatAnimJoint ((intptr_t)1680)
#define llGRYosterMapBirdAnimJoint ((intptr_t)30832)
#define llGRYosterMapBirdDObjDesc ((intptr_t)30688)
#define llGRYosterMapBirdMObjSub ((intptr_t)30224)
#define llGRYosterMapBirdMatAnimJoint ((intptr_t)31056)
#define llGRYosterMapDataStart ((intptr_t)20088)
#define llGRYosterMapHeihoFastAnimJoint ((intptr_t)46304)
#define llGRYosterMapHeihoFastDObjDesc ((intptr_t)46168)
#define llGRYosterMapHeihoFastMObjSub ((intptr_t)45712)
#define llGRYosterMapHeihoFastMatAnimJoint ((intptr_t)46416)
#define llGRYosterMapHeihoFruitFastAnimJoint ((intptr_t)42544)
#define llGRYosterMapHeihoFruitFastDObjDesc ((intptr_t)42408)
#define llGRYosterMapHeihoFruitFastMObjSub ((intptr_t)41952)
#define llGRYosterMapHeihoFruitFastMatAnimJoint ((intptr_t)42656)
#define llGRYosterMapHeihoFruitSlowAnimJoint ((intptr_t)34816)
#define llGRYosterMapHeihoFruitSlowMObjSub ((intptr_t)33632)
#define llGRYosterMapHeihoFruitSlowLDObjDesc ((intptr_t)34088)
#define llGRYosterMapHeihoFruitSlowMatAnimJoint ((intptr_t)35120)
#define llGRYosterMapHeihoFruitSlowRDObjDesc ((intptr_t)34680)
#define llGRYosterMapHeihoSlowAnimJoint ((intptr_t)38768)
#define llGRYosterMapHeihoSlowDObjDesc ((intptr_t)38632)
#define llGRYosterMapHeihoSlowMObjSub ((intptr_t)38176)
#define llGRYosterMapHeihoSlowMatAnimJoint ((intptr_t)38896)
#define llGRYamabukiMapMapHeader ((intptr_t)20)
#define llGRYamabukiMapItemHead ((intptr_t)20)
#define llGRYamabukiMapGLuckyItemAttributes ((intptr_t)188)
#define llGRYamabukiMapMarumineItemAttributes ((intptr_t)260)
#define llGRYamabukiMapMarumineAttackEvents ((intptr_t)332)
#define llGRYamabukiMapPorygonItemAttributes ((intptr_t)364)
#define llGRYamabukiMapPorygonHitParties ((intptr_t)436)
#define llGRYamabukiMapHitokageItemAttributes ((intptr_t)508)
#define llGRYamabukiMapHitokageFlameWeaponAttributes ((intptr_t)580)
#define llGRYamabukiMapFushigibanaItemAttributes ((intptr_t)632)
#define llGRYamabukiMapFushigibanaHitParties ((intptr_t)704)
#define llGRYamabukiMapFushigibanaRazorWeaponAttributes ((intptr_t)776)
#define llGRYamabukiMapGateOpenAnimJoint ((intptr_t)2480)
#define llGRYamabukiMapGateCloseAnimJoint ((intptr_t)2592)
#define llGRYamabukiMapMapHead ((intptr_t)2208)
#define llGRYamabukiMapButterfreeAnimJoint ((intptr_t)39392)
#define llGRYamabukiMapButterfreeDObjDesc ((intptr_t)39256)
#define llGRYamabukiMapButterfreeMObjSub ((intptr_t)38800)
#define llGRYamabukiMapButterfreeMatAnimJoint ((intptr_t)40384)
#define llGRYamabukiMapDataStart ((intptr_t)27248)
#define llGRYamabukiMapFireAnimJoint ((intptr_t)51488)
#define llGRYamabukiMapFireDObjDesc ((intptr_t)51344)
#define llGRYamabukiMapFireMObjSub ((intptr_t)50880)
#define llGRYamabukiMapFireMatAnimJoint ((intptr_t)51680)
#define llGRYamabukiMapOnidrillAnimJoint ((intptr_t)58512)
#define llGRYamabukiMapOnidrillDObjDesc ((intptr_t)58368)
#define llGRYamabukiMapOnidrillMObjSub ((intptr_t)57904)
#define llGRYamabukiMapOnidrillMatAnimJoint ((intptr_t)58816)
#define llGRYamabukiMapPoppoAnimJoint ((intptr_t)65248)
#define llGRYamabukiMapPoppoDObjDesc ((intptr_t)65112)
#define llGRYamabukiMapPoppoMObjSub ((intptr_t)64656)
#define llGRYamabukiMapPoppoMatAnimJoint ((intptr_t)65488)
#define llGRHyruleMapMapHeader ((intptr_t)20)
#define llGRHyruleMapTwisterThrowHitDesc ((intptr_t)188)
#define llGRLastMapMapHeader ((intptr_t)0)
#define llGRLastMapFileHead ((intptr_t)19784)
#define llGRLastMapEffects0MObjSub ((intptr_t)34520)
#define llGRLastMapEffects0DObjDesc ((intptr_t)35168)
#define llGRLastMapAnims0AnimJoint ((intptr_t)35392)
#define llGRLastMapAnims0MatAnimJoint ((intptr_t)35920)
#define llGRLastMapEffects1MObjSub ((intptr_t)38832)
#define llGRLastMapEffects1DObjDesc ((intptr_t)41352)
#define llGRLastMapAnims1AnimJoint ((intptr_t)41792)
#define llGRLastMapAnims1MatAnimJoint ((intptr_t)45488)
#define llGRLastMapEffects2_0MObjSub ((intptr_t)54384)
#define llGRLastMapEffects2_0DObjDesc ((intptr_t)56720)
#define llGRLastMapEffects2_1MObjSub ((intptr_t)67464)
#define llGRLastMapEffects2_1DObjDesc ((intptr_t)70248)
#define llGRLastMapAnims2_0AnimJoint ((intptr_t)56944)
#define llGRLastMapAnims2_0MatAnimJoint ((intptr_t)57024)
#define llGRLastMapAnims2_1MatAnimJoint ((intptr_t)70688)
#define llGRLastMapEffects3_0MObjSub ((intptr_t)67464)
#define llGRLastMapEffects3_0DObjDesc ((intptr_t)70248)
#define llGRLastMapEffects3_1DObjDesc ((intptr_t)75864)
#define llGRLastMapAnims3_0MatAnimJoint ((intptr_t)71104)
#define llGRLastMapAnims3_1AnimJoint ((intptr_t)76000)
#define llGRExplainMapMapHeader ((intptr_t)0)
#define llGRZakoMapMapHeader ((intptr_t)20)
#define llGRMetalMapMapHeader ((intptr_t)20)
#define llGRYosterSmallMapMapHeader ((intptr_t)20)
#define llGRBonus1MarioMapMapHeader ((intptr_t)0)
#define llGRBonus1MarioMapTargetsStart ((intptr_t)7856)
#define llGRBonus1MarioMapTargetsDObjDesc ((intptr_t)8528)
#define llGRBonus1MarioMapTargetsAnimJoint ((intptr_t)9056)
#define llGRBonus1FoxMapMapHeader ((intptr_t)0)
#define llGRBonus1FoxMapTargetsStart ((intptr_t)8296)
#define llGRBonus1FoxMapTargetsDObjDesc ((intptr_t)9392)
#define llGRBonus1FoxMapTargetsAnimJoint ((intptr_t)9920)
#define llGRBonus1DonkeyMapMapHeader ((intptr_t)0)
#define llGRBonus1DonkeyMapTargetsStart ((intptr_t)7968)
#define llGRBonus1DonkeyMapTargetsDObjDesc ((intptr_t)8784)
#define llGRBonus1DonkeyMapTargetsAnimJoint ((intptr_t)9312)
#define llGRBonus1SamusMapMapHeader ((intptr_t)0)
#define llGRBonus1SamusMapTargetsStart ((intptr_t)6248)
#define llGRBonus1SamusMapTargetsDObjDesc ((intptr_t)6960)
#define llGRBonus1SamusMapTargetsAnimJoint ((intptr_t)7488)
#define llGRBonus1LuigiMapMapHeader ((intptr_t)0)
#define llGRBonus1LuigiMapTargetsStart ((intptr_t)7072)
#define llGRBonus1LuigiMapTargetsDObjDesc ((intptr_t)8224)
#define llGRBonus1LuigiMapTargetsAnimJoint ((intptr_t)8752)
#define llGRBonus1LinkMapMapHeader ((intptr_t)0)
#define llGRBonus1LinkMapTargetsStart ((intptr_t)9080)
#define llGRBonus1LinkMapTargetsDObjDesc ((intptr_t)10096)
#define llGRBonus1LinkMapTargetsAnimJoint ((intptr_t)10624)
#define llGRBonus1YoshiMapMapHeader ((intptr_t)0)
#define llGRBonus1YoshiMapTargetsStart ((intptr_t)11624)
#define llGRBonus1YoshiMapTargetsDObjDesc ((intptr_t)12944)
#define llGRBonus1YoshiMapTargetsAnimJoint ((intptr_t)13472)
#define llGRBonus1CaptainMapMapHeader ((intptr_t)0)
#define llGRBonus1CaptainMapTargetsStart ((intptr_t)6280)
#define llGRBonus1CaptainMapTargetsDObjDesc ((intptr_t)7024)
#define llGRBonus1CaptainMapTargetsAnimJoint ((intptr_t)7552)
#define llGRBonus1KirbyMapMapHeader ((intptr_t)0)
#define llGRBonus1KirbyMapTargetsStart ((intptr_t)8528)
#define llGRBonus1KirbyMapTargetsDObjDesc ((intptr_t)9488)
#define llGRBonus1KirbyMapTargetsAnimJoint ((intptr_t)10016)
#define llGRBonus1PikachuMapMapHeader ((intptr_t)0)
#define llGRBonus1PikachuMapTargetsStart ((intptr_t)9816)
#define llGRBonus1PikachuMapTargetsDObjDesc ((intptr_t)10864)
#define llGRBonus1PikachuMapTargetsAnimJoint ((intptr_t)11392)
#define llGRBonus1PurinMapMapHeader ((intptr_t)0)
#define llGRBonus1PurinMapTargetsStart ((intptr_t)8184)
#define llGRBonus1PurinMapTargetsDObjDesc ((intptr_t)9120)
#define llGRBonus1PurinMapTargetsAnimJoint ((intptr_t)9648)
#define llGRBonus1NessMapMapHeader ((intptr_t)0)
#define llGRBonus1NessMapTargetsStart ((intptr_t)10560)
#define llGRBonus1NessMapTargetsDObjDesc ((intptr_t)11872)
#define llGRBonus1NessMapTargetsAnimJoint ((intptr_t)12400)
#define llGRBonus2MarioMapMapHeader ((intptr_t)0)
#define llGRBonus2FoxMapMapHeader ((intptr_t)0)
#define llGRBonus2FoxMapBumpersDObjDesc ((intptr_t)57696)
#define llGRBonus2FoxMapBumpersAnimJoint ((intptr_t)58192)
#define llGRBonus2DonkeyMapMapHeader ((intptr_t)0)
#define llGRBonus2SamusMapMapHeader ((intptr_t)0)
#define llGRBonus2SamusMapBumpersDObjDesc ((intptr_t)10512)
#define llGRBonus2SamusMapBumpersAnimJoint ((intptr_t)10688)
#define llGRBonus2LuigiMapMapHeader ((intptr_t)0)
#define llGRBonus2LinkMapMapHeader ((intptr_t)0)
#define llGRBonus2YoshiMapMapHeader ((intptr_t)0)
#define llGRBonus2CaptainMapMapHeader ((intptr_t)0)
#define llGRBonus2KirbyMapMapHeader ((intptr_t)0)
#define llGRBonus2KirbyMapBumpersDObjDesc ((intptr_t)14624)
#define llGRBonus2KirbyMapBumpersAnimJoint ((intptr_t)14944)
#define llGRBonus2PikachuMapMapHeader ((intptr_t)0)
#define llGRBonus2PurinMapMapHeader ((intptr_t)0)
#define llGRBonus2PurinMapBumpersDObjDesc ((intptr_t)20448)
#define llGRBonus2PurinMapBumpersAnimJoint ((intptr_t)20768)
#define llGRBonus2NessMapMapHeader ((intptr_t)0)
#define llGRBonus2NessMapBumpersDObjDesc ((intptr_t)16352)
#define llGRBonus2NessMapBumpersAnimJoint ((intptr_t)16528)
#define llGRBonus3MapMapHeader ((intptr_t)0)
#define llGRBonus3MapMapHead ((intptr_t)0)
#define llGRBonus3MapItemHead ((intptr_t)0)
#define llGRBonus3MapBumpersDObjDesc ((intptr_t)0)
#define llGRBonus3MapTaruBombItemAttributes ((intptr_t)168)
#define llGRBonus3MapTaruBombAttackEvents ((intptr_t)240)
#define llGRBonus3MapBumpersAnimJoint ((intptr_t)272)
#define llGRBonus3MapTaruBombDataStart ((intptr_t)1928)
#define llGRBonus3MapTaruBombEffectDisplayList ((intptr_t)2208)
#define llMarioModelStockSprite ((intptr_t)29392)
#define llMarioModelFTEmblemSprite ((intptr_t)29896)
#define llMMarioModelStockSprite ((intptr_t)11520)
#define llMMarioModelFTEmblemSprite ((intptr_t)12024)
#define llFoxModelStockSprite ((intptr_t)31784)
#define llFoxModelFTEmblemSprite ((intptr_t)32264)
#define llDkIconStockSprite ((intptr_t)304)
#define llDkIconFTEmblemSprite ((intptr_t)760)
#define llSamusModelStockSprite ((intptr_t)58096)
#define llSamusModelFTEmblemSprite ((intptr_t)58632)
#define llLuigiModelStockSprite ((intptr_t)31960)
#define llLuigiModelFTEmblemSprite ((intptr_t)32456)
#define llLinkModelStockSprite ((intptr_t)73032)
#define llLinkModelFTEmblemSprite ((intptr_t)73512)
#define llKirbyModelStockSprite ((intptr_t)120288)
#define llKirbyModelFTEmblemSprite ((intptr_t)120792)
#define llPurinModelStockSprite ((intptr_t)31664)
#define llPurinModelFTEmblemSprite ((intptr_t)32152)
#define llCaptainModelStockSprite ((intptr_t)50856)
#define llCaptainModelFTEmblemSprite ((intptr_t)51272)
#define llCaptainSpecial3FalconPunchDObjDesc ((intptr_t)1888)
#define llCaptainSpecial3FalconPunchMObjSub ((intptr_t)1680)
#define llCaptainSpecial3FalconPunchMatAnimJoint ((intptr_t)2096)
#define llNessModelPKThunderTrailDObjDesc ((intptr_t)36944)
#define llNessModelPKThunderWaveMObjSub ((intptr_t)39024)
#define llNessModelPKThunderWaveDObjDesc ((intptr_t)39440)
#define llNessModelPKThunderWaveAnimJoint ((intptr_t)39616)
#define llNessModelPKThunderWaveMatAnimJoint ((intptr_t)39856)
#define llNessModelStockSprite ((intptr_t)49544)
#define llNessModelFTEmblemSprite ((intptr_t)50040)
#define llYoshiModelStockSprite ((intptr_t)43688)
#define llYoshiModelShieldDObjDesc ((intptr_t)43104)
#define llYoshiModelFTEmblemSprite ((intptr_t)44184)
#define llYoshiSpecial3EggLayDObjDesc ((intptr_t)2400)
#define llYoshiSpecial3EggLayBreakAnimJoint ((intptr_t)2544)
#define llYoshiSpecial3EggLayThrowAnimJoint ((intptr_t)2960)
#define llYoshiSpecial3EggLayWaitAnimJoint ((intptr_t)3504)
#define llPikachuModelThunderTrailMObjSub ((intptr_t)37920)
#define llPikachuModelThunderTrailDObjDesc ((intptr_t)38320)
#define llPikachuModelStockSprite ((intptr_t)39424)
#define llPikachuModelFTEmblemSprite ((intptr_t)39912)
#define llPikachuSpecial3ThunderJoltBAnimJoint ((intptr_t)6688)
#define llPikachuSpecial3ThunderJoltBMatAnimJoint ((intptr_t)6880)
#define llPikachuSpecial3ThunderJoltDObjDesc ((intptr_t)8792)
#define llPikachuSpecial3ThunderJoltMObjSub ((intptr_t)8352)
#define llPikachuSpecial3ThunderJoltAnimJoint ((intptr_t)8928)
#define llPikachuSpecial3ThunderJoltMatAnimJoint ((intptr_t)9040)
#define llMasterHandIconStockSprite ((intptr_t)192)
#define llMasterHandIconFTEmblemSprite ((intptr_t)696)
#define llFoxSpecial2ReflectorDObjDesc ((intptr_t)688)
#define llFoxSpecial2EntryArwingLAnimJoint ((intptr_t)1424)
#define llFoxSpecial2EntryArwingRAnimJoint ((intptr_t)2528)
#define llFoxSpecial2ReflectorStartAnimJoint ((intptr_t)832)
#define llFoxSpecial2ReflectorHitAnimJoint ((intptr_t)928)
#define llFoxSpecial2ReflectorEndAnimJoint ((intptr_t)1072)
#define llFoxSpecial2ReflectorLoopAnimJoint ((intptr_t)1216)
#define llPikachuSpecial2UnkMObjSub ((intptr_t)1600)
#define llPikachuSpecial2UnkDObjDesc ((intptr_t)2048)
#define llPikachuSpecial2UnkAnimJoint ((intptr_t)2192)
#define llPikachuSpecial2UnkMatAnimJoint ((intptr_t)2304)
#define llPikachuSpecial2ThunderShockMObjSub ((intptr_t)5024)
#define llPikachuSpecial2ThunderShockDObjDesc ((intptr_t)5696)
#define llPikachuSpecial2ThunderShock0AnimJoint ((intptr_t)5920)
#define llPikachuSpecial2ThunderShock1AnimJoint ((intptr_t)6224)
#define llPikachuSpecial2ThunderShock2AnimJoint ((intptr_t)6512)
#define llPikachuSpecial2ThunderShock0MatAnimJoint ((intptr_t)6784)
#define llPikachuSpecial2ThunderShock1MatAnimJoint ((intptr_t)6848)
#define llPikachuSpecial2ThunderShock2MatAnimJoint ((intptr_t)6928)
#define llKirbySpecial2VulcanJabDObjDesc ((intptr_t)2848)
#define llKirbySpecial2CutterUpDObjDesc ((intptr_t)4840)
#define llKirbySpecial2CutterUpAnimJoint ((intptr_t)5232)
#define llKirbySpecial2CutterDownDObjDesc ((intptr_t)9104)
#define llKirbySpecial2CutterDownAnimJoint ((intptr_t)9424)
#define llKirbySpecial2CutterDrawDObjDesc ((intptr_t)10376)
#define llKirbySpecial2CutterTrailDObjDesc ((intptr_t)3576)
#define llKirbySpecial2CutterTrailAnimJoint ((intptr_t)5104)
#define llKirbySpecial2EntryStarDObjDesc ((intptr_t)7592)
#define llKirbySpecial2EntryStarLAnimJoint ((intptr_t)7728)
#define llKirbySpecial2EntryStarRAnimJoint ((intptr_t)7840)
#define llSamusSpecial2GrappleBeamDObjDesc ((intptr_t)896)
#define llSamusSpecial2GrappleBeamMObjSub ((intptr_t)528)
#define llSamusSpecial2GrappleBeamAnimJoint ((intptr_t)1040)
#define llSamusSpecial2GrappleBeamMatAnimJoint ((intptr_t)1152)
#define llSamusSpecial2EntryPointDObjDesc ((intptr_t)2960)
#define llSamusSpecial2EntryPointAnimJoint ((intptr_t)3104)
#define llCaptainSpecial2FalconKickDObjDesc ((intptr_t)2824)
#define llCaptainSpecial2FalconKickMObjSub ((intptr_t)2400)
#define llCaptainSpecial2FalconKickAnimJoint ((intptr_t)2960)
#define llCaptainSpecial2FalconKickMatAnimJoint ((intptr_t)3072)
#define llCaptainSpecial2EntryCarDObjDesc ((intptr_t)24512)
#define llCaptainSpecial2_6200_AnimJoint ((intptr_t)25088)
#define llCaptainSpecial2_6518_AnimJoint ((intptr_t)25880)
#define llCaptainSpecial2_6598_AnimJoint ((intptr_t)26008)
#define llPurinSpecial2SingDObjDesc ((intptr_t)8496)
#define llPurinSpecial2SingMObjSub ((intptr_t)7200)
#define llPurinSpecial2SingAnimJoint ((intptr_t)8816)
#define llPurinSpecial2SingMatAnimJoint ((intptr_t)11632)
#define llNessSpecial2PsychicMagnetMObjSub ((intptr_t)2064)
#define llNessSpecial2PsychicMagnetDObjDesc ((intptr_t)2472)
#define llNessSpecial2PsychicMagnetAnimJoint ((intptr_t)2608)
#define llNessSpecial2PsychicMagnetMatAnimJoint ((intptr_t)2768)
#define llLinkSpecial2EntryWaveDObjDesc ((intptr_t)1016)
#define llLinkSpecial2EntryWaveMObjSub ((intptr_t)304)
#define llLinkSpecial2EntryWaveAnimJoint ((intptr_t)2112)
#define llLinkSpecial2EntryWaveMatAnimJoint ((intptr_t)2960)
#define llLinkSpecial2EntryBeamDObjDesc ((intptr_t)1976)
#define llLinkSpecial2EntryBeamMObjSub ((intptr_t)1264)
#define llLinkSpecial2EntryBeamAnimJoint ((intptr_t)2912)
#define llLinkSpecial2EntryBeamMatAnimJoint ((intptr_t)3056)
#define llLinkSpecial2SpinAttackDObjDesc ((intptr_t)4544)
#define llLinkSpecial2SpinAttackMObjSub ((intptr_t)4152)
#define llLinkSpecial2SpinAttackAnimJoint ((intptr_t)4688)
#define llLinkSpecial2SpinAttackMatAnimJoint ((intptr_t)4848)
#define llYoshiSpecial2EntryEggDObjDesc ((intptr_t)1328)
#define llYoshiSpecial2EntryEggMObjSub ((intptr_t)1120)
#define llYoshiSpecial2EntryEggAnimJoint ((intptr_t)1536)
#define llYoshiSpecial2EntryEggMatAnimJoint ((intptr_t)1920)
#define llDonkeySpecial2EntryTaruDObjDesc ((intptr_t)1992)
#define llDonkeySpecial2EntryTaruAnimJoint ((intptr_t)2128)
#define llMarioSpecial2EntryDokanDObjDesc ((intptr_t)1544)
#define llMarioSpecial2EntryDokanAnimJoint ((intptr_t)1728)

/* ll* symbols referenced by src/ but absent from the symbols table. */
#define llFTBossAnimAppearFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimChargeStart1FileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimChargeStart2FileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimDefaultFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimDrillFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimDyingFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimDyingStartFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimFlickFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimFlyFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimGunAimFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimGunDrawFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimGunShootFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimLanding2FileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimLaunchFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimPointFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimPointStartFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimPokeFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimPunch1FileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimPunch2FileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimPunch3FileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimPunchEndFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimShooFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimSlamFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimSlamStartFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimSlapFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimUnknown1FileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimUnknown6FileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTBossAnimWalkStartFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimAppearAirFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimAppearFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimAttackAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimAttackAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimAttackAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimAttackAirNFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimAttackAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimBlueFalcon1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimBlueFalcon2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCatchPullFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCatchingEnemyWhileDivingFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCeilingBonkFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimClangRecoilFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimClapsFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffAttackQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffAttackQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffAttackSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffAttackSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffClimbQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffClimbQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffClimbSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffClimbSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffEscapeQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffEscapeQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffEscapeSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffEscapeSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffQuickFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffSlowFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCliffWaitFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCrouchEndFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCrouchFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimCrouchIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamage2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamageAirFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamageFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamageFlyTopFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamageFlyX1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamageFlyX2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamageX1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamageX2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamageX3FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamaged1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamaged2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamaged3FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamaged4FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamaged5FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamaged6FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamaged7FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDamagedFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDashAttackFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDashFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDollFallFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDollRevivalFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDownAttackDFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDownAttackUFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDownBackDFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDownBackUFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDownForwardDFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDownForwardUFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDownSpecialAirFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimDownSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimEggLayFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimEggLayPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimEnterPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimExitPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimExitPipeWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFSmashHighFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFSmashLowFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFTiltHighFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFTiltLowFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFTiltMidHighFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFTiltMidLowFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFalconDiveEnd1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFalconDiveEnd2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFalconDiveFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFalconDivePulledFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFalconPunchAirFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFalconPunchGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFallAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFallFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFallSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFireFlowerShootAirFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimFireFlowerShootFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimHammerIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimHammerLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimHeavyItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimHeavyItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimItemDropFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimItemThrowAirSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimItemThrowAirSmashFFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimItemThrowAirSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimItemThrowDashFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimItemThrowSmashDFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimItemThrowSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimJab1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimJab2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimJab3FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimJabLoopEndFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimJabLoopFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimJabLoopStartFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimJumpAerialBFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimJumpAerialFFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimJumpBFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimJumpFFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimLandingAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimLandingAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimLandingAirXFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimLandingDownSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimLightItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimRollBFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimRollFFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimRunBrakeFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimRunFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimSelectedFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimShieldBreakFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimShieldDropFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimShieldOffFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimShieldOnFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimSleepFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimStarRodDashFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimStarRodNeutralFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimStarRodSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimStarRodTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimStunLandDFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimStunLandUFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimStunStartDFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimStunStartUFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimTauntFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimTechBFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimTechFFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimTechFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimTeeterFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimTeeterstartFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimThrowFFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimThrown1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimThrown2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimThrownDKFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimThrownDKPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimThrownMarioBrosFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimTurnRunFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimUSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimUTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimUnknownFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimVelocityXDownSpecialAirFileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimVictory1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimVictory2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimWalk1FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimWalk2FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimWalk3FileID ((intptr_t)0) /* STUBBED */
#define llFTCaptainAnimWalkEndFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimAppear1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimAppear2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimAttackAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimAttackAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimAttackAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimAttackAirNFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimAttackAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCargoAirThrowFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCargoLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCargoSlowWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCargoTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCargoVerySlowWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCargoWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCatchPullFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCeilingBonkFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimClangRecoilFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimClapsFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffAttackQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffAttackQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffAttackSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffAttackSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffClimbQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffClimbQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffClimbSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffClimbSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffEscapeQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffEscapeQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffEscapeSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffEscapeSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffQuickFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffSlowFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCliffWaitFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCrouchEndFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCrouchFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimCrouchIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamage2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamageAirFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamageFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamageFlyTopFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamageFlyX1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamageFlyX2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamageX1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamageX2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamageX3FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamaged1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamaged2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamaged3FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamaged4FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamaged5FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamaged6FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamaged7FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDamagedFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDashAttackFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDashFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDollFallFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDollPickUpFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDollRevivalFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDownAttackDFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDownAttackUFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDownBackDFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDownBackUFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDownForwardDFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimDownForwardUFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimEggLayFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimEggLayPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimEnterPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimExitPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimExitPipeWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFSmashHighFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFSmashLowFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFSmashMidHighFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFSmashMidLowFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFTiltHighFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFTiltLowFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFalconDivePulledFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFallAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFallFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFallSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFireFlowerShootAirFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimFireFlowerShootFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimGiantPunchAirFullyChargedPunchFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimGiantPunchAirLoopFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimGiantPunchAirLoopStartFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimGiantPunchGroundFullyChargedPunchFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimGiantPunchGroundLoopFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimGiantPunchGroundLoopStartFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimHammerIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimHammerLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimHandSlapEndFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimHandSlapLoopFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimHandSlapStartFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimHeavyItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimIntroFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimItemDropFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimItemThrowAirSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimItemThrowAirSmashFFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimItemThrowAirSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimItemThrowDashFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimItemThrowSmashDFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimItemThrowSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimJab1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimJab2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimJumpAerialBFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimJumpAerialFFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimJumpBFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimJumpFFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimLandingAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimLandingAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimLandingAirXFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimLightItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimRollBFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimRollFFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimRunBrakeFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimRunFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimSelectedFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimShieldBreakFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimShieldDropFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimShieldOffFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimShieldOnFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimSleepFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimSpinningKongAirFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimSpinningKongGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimStarRodDashFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimStarRodNeutralFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimStarRodSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimStarRodTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimStunLandDFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimStunLandUFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimStunStartDFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimStunStartUFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimTauntFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimTechBFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimTechFFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimTechFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimTeeterFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimTeeterstartFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimThrowFFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimThrown1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimThrown2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimThrownDKFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimThrownDKPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimThrownFoxFStartFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimThrownMarioBrosFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimTurnRunFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimUSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimUTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimUnknownFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimWalk1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimWalk2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimWalk3FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimWalkEndFileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimWin1FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimWin2FileID ((intptr_t)0) /* STUBBED */
#define llFTDonkeyAnimWin3FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimAppearFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimArwingFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimAttackAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimAttackAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimAttackAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimAttackAirNFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimAttackAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCatchPullFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCeilingBonkFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimClangRecoilFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimClapsFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffAttackQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffAttackQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffAttackSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffAttackSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffClimbQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffClimbQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffClimbSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffClimbSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffEscapeQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffEscapeQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffEscapeSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffEscapeSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffQuickFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffSlowFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCliffWaitFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCrouchEndFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCrouchFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimCrouchIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamage2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamageAirFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamageFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamageFlyTopFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamageFlyX1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamageFlyX2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamageX1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamageX2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamageX3FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamaged1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamaged2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamaged3FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamaged4FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamaged5FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamaged6FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamaged7FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDamagedFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDashAttackFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDashFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDollFallFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDollFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDollPickUpFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDollRevivalFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDownAttackDFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDownAttackUFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDownBackDFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDownBackUFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDownForwardDFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimDownForwardUFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimEggLayFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimEggLayPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimEnterPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimExitPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimExitPipeWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFTiltHighFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFTiltLowFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFTiltMidHighFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFTiltMidLowFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFalconDivePulledFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFallAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFallFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFallSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFireFlowerShootAirFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFireFlowerShootFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFireFoxAirFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFireFoxEndAirFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFireFoxEndGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFireFoxGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFireFoxStartAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimFireFoxStartGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimHammerIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimHammerLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimHeavyItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimHeavyItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimItemDropFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimItemThrowAirSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimItemThrowAirSmashFFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimItemThrowAirSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimItemThrowDashFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimItemThrowSmashDFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimItemThrowSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimJab1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimJab2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimJabLoopEndFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimJabLoopFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimJabLoopStartFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimJumpAerialBFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimJumpAerialFFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimJumpBFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimJumpFFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimLandingAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimLandingAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimLandingAirXFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimLandingWhileFireFoxAirFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimLaserAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimLaserFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimLightItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimPose1FrameFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimPoseBlaster2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimPosePostBlasterFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimReadyingFireFoxAirFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimReadyingFireFoxGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimReflectingFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimRollBFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimRollFFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimRunBrakeFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimRunFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimSelectedFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimShieldBreakFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimShieldDropFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimShieldOffFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimShieldOnFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimShineAirEndFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimShineFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimShineStartFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimShireStartAirFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimSleepFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimStarRodDashFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimStarRodNeutralFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimStarRodSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimStarRodTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimStunLandDFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimStunLandUFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimStunStartDFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimStunStartUFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimSwitchDirectionShineAirFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimSwitchDirectionShineFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimTauntFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimTechBFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimTechFFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimTechFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimTeeterFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimTeeterstartFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimThrowFFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimThrown1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimThrown2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimThrown3FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimThrownDKFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimThrownDKPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimThrownFoxBFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimThrownMarioBrosFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimTurnRunFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimUSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimUTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimUnknownFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimWalk1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimWalk2FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimWalk3FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimWalkEndFileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimWin1FileID ((intptr_t)0) /* STUBBED */
#define llFTFoxAnimWin2FileID ((intptr_t)0) /* STUBBED */
#define llFTGDonkeyAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimAttackAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimAttackAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimAttackAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimAttackAirNFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimAttackAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimBoomerangAirCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimBoomerangAirMissFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimBoomerangCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimBoomerangMissFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCatchPullFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCeilingBonkFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimChargePunchAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimChargePunchAirFullFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimChargePunchGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimChargePunchGroundFullFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimChargePunchStartGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimChargeShotAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimChargeShotStartFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimChargeStartAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimChargingFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimClangRecoilFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimClapsFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffAttackQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffAttackQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffAttackSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffAttackSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffClimbQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffClimbQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffClimbSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffClimbSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffEscapeQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffEscapeQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffEscapeSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffEscapeSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffQuickFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffSlowFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCliffWaitFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCrouchEndFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCrouchFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimCrouchIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDKStaringAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDKStaringGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamage2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamageAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamageFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamageFlyTopFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamageFlyX1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamageFlyX2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamageX1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamageX2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamageX3FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamaged1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamaged2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamaged3FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamaged4FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamaged5FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamaged6FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamaged7FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDamagedFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDashAttackFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDashFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDollFallFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDollPickUpFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDollRevivalFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDownAttackDFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDownAttackUFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDownBackDFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDownBackUFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDownForwardDFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimDownForwardUFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimEggLayFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimEggLayGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimEggLayPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimEggThrowAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimEggThrowEndAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimEggThrowGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimEnterPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimExitPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimExitPipeWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFTiltHighFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFTiltLowFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFalconDivePulledFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFalconPunchAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFalconPunchGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFallAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFallFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFallSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFinalCutterFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFinalCutterImpactFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFinalCutterLandFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFireFlowerShootAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimFireFlowerShootFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimForwardThrowFallFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimForwardThrowFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimForwardThrowRecoilFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimHammerIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimHammerLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimHeavyItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimHeavyItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimInhaleAbsorbFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimInhaleEndFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimInhaleGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimInhaleSpitFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimInhaleStartGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimInhaleStuffedFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimInhaleSwallowedFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimInhaleTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimIntro2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimIntroFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimIntroPoseFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimItemDropFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimItemThrowAirSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimItemThrowAirSmashFFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimItemThrowAirSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimItemThrowDashFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimItemThrowSmashDFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimItemThrowSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimJab1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimJab2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimJabLoopEndFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimJabLoopFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimJabLoopStartFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimJump2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimJump3FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimJump4FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimJump5FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimJump6FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimJumpBFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimJumpFFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimLandingAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimLandingAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimLandingAirXFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimLaserAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimLaserGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimLightItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimLuigiFireballAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimLuigiFireballGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimPKFireAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimPKFireGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimPose2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimPoseFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimRollBFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimRollFFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimRunBrakeFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimRunFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimSelectedFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimShieldBreakFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimShieldDropFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimShieldOffFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimShieldOnFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimShootingChargeShotAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimShootingChargeShotFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimSleepFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimStarRodDashFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimStarRodNeutralFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimStarRodSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimStarRodTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimStoneCancelFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimStoneGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimStoneStartAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimStoneStartGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimStunLandDFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimStunLandUFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimStunStartDFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimStunStartUFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimTauntFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimTechBFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimTechFFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimTechFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimTeeterFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimTeeterstartFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimThrown1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimThrown2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimThrown3FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimThrownDKFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimThrownDKPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimThrownFoxBFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimThrownMarioBrosFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimThunderJoltAirFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimThunderJoltGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimTurnRunFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimUSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimUTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimUnknownFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimWalk1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimWalk2FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimWalk3FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimWalkEndFileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimWin1FileID ((intptr_t)0) /* STUBBED */
#define llFTKirbyAnimWin2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimAppear1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimAppear2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimAttackAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimAttackAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimAttackAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimAttackAirNFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimAttackAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimBombAirFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimBombFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCatchPullFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCatchingBoomerangAirFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCatchingBoomerangFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCeilingBonkFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimClangRecoilFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimClaps2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimClapsFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffAttackQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffAttackQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffAttackSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffAttackSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffClimbQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffClimbQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffClimbSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffClimbSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffEscapeQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffEscapeQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffEscapeSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffEscapeSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffQuickFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffSlowFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCliffWaitFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCrouchEndFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCrouchFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimCrouchIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamage2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamageAirFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamageFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamageFlyTopFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamageFlyX1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamageFlyX2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamageX1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamageX2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamageX3FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamaged1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamaged2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamaged3FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamaged4FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamaged5FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamaged6FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamaged7FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDamagedFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDashAttackFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDashFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDollFallFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDollPickUpFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDollRevivalFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDownAttackDFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDownAttackUFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDownBackDFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDownBackUFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDownForwardDFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimDownForwardUFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimEggLayFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimEggLayPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimEnterPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimExitPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimExitPipeWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimFSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimFTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimFalconDivePulledFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimFallAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimFallFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimFallSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimFireFlowerShootAirFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimFireFlowerShootFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimHammerIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimHammerLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimHeavyItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimHeavyItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimIntroFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimItemDropFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimItemThrowAirSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimItemThrowAirSmashFFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimItemThrowAirSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimItemThrowDashFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimItemThrowSmashDFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimItemThrowSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimJab1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimJab2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimJab3FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimJabLoopEndFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimJabLoopFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimJabLoopStartFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimJumpAerialBFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimJumpAerialFFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimJumpBFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimJumpFFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimLandingAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimLandingAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimLandingAirXFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimLightItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimMissingBoomerangAirFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimMissingBoomerangFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimPoseAllyFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimPoseOpponentFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimPosePlayerFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimRollBFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimRollFFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimRunBrakeFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimRunFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimSelectedFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimShieldBreakFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimShieldDropFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimShieldOffFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimShieldOnFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimSleepFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimStarRodDashFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimStarRodNeutralFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimStarRodSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimStarRodTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimStunLandDFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimStunLandUFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimStunStartDFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimStunStartUFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimTauntFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimTechBFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimTechFFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimTechFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimTeeterFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimTeeterstartFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimThrowFFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimThrown1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimThrown2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimThrownDKFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimThrownDKPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimThrownFoxFStartFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimThrownMarioBrosFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimTurnRunFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimUSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimUTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimUpSpecialAirFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimUpSpecialEndGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimUpSpecialGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimWalk1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimWalk2FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimWalk3FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimWalkEndFileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimWin1FileID ((intptr_t)0) /* STUBBED */
#define llFTLinkAnimWin2FileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimDTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimDashAttackFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimDashFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimDollFallFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimDollRevivalFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimEggLayFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimFSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimFSmashHighFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimFSmashLowFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimFSmashMidHighFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimFSmashMidLowFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimPoseEnemyFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimPosePlayerFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimRunBrakeFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimSelectedFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimTauntFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimTurnRunFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimUnknownFileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimWin1FileID ((intptr_t)0) /* STUBBED */
#define llFTLuigiAnimWin2FileID ((intptr_t)0) /* STUBBED */
#define llFTMMarioAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimAppear1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimAppear2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimAttackAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimAttackAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimAttackAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimAttackAirNFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimAttackAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCatchPullFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCeilingBonkFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimClangRecoilFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimClapsFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffAttackQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffAttackQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffAttackSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffAttackSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffClimbQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffClimbQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffClimbSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffClimbSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffEscapeQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffEscapeQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffEscapeSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffEscapeSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffQuickFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffSlowFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCliffWaitFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCrouchEndFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCrouchFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimCrouchIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamage2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamageAirFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamageFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamageFlyTopFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamageFlyX1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamageFlyX2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamageX1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamageX2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamageX3FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamaged1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamaged2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamaged3FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamaged4FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamaged5FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamaged6FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamaged7FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDamagedFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDashAttackFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDashFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDollFallsFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDollPickUpFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDollRevivalFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDownAttackDFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDownAttackUFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDownBackDFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDownBackUFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDownForwardDFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimDownForwardUFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimEggLayPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimEnterPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimExitPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimExitPipeWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFSmashHighFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFSmashLowFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFSmashMidHighFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFSmashMidLowFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFTiltHighFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFTiltLowFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFalconDivePulledFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFallAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFallFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFallSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFireFlowerShootAirFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFireFlowerShootFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFireballAirFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimFireballGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimHammerIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimHammerLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimHeavyItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimHeavyItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimIntro2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimIntroFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimIntroVsKirbyFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimItemDropFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimItemThrowAirSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimItemThrowAirSmashFFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimItemThrowAirSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimItemThrowDashFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimItemThrowSmashDFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimItemThrowSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimJab1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimJab2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimJab3FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimJumpAerialBFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimJumpAerialFFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimJumpBFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimJumpFFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimLandingAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimLandingAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimLandingAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimLandingAirXFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimLightItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimMarioTornadoAirFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimMarioTornadoGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimPose2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimPoseFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimRollBFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimRollFFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimRunBrakeFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimRunFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimSelectedFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimShieldBreakFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimShieldDropFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimShieldOffFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimShieldOnFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimSleepFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimStarRodDashFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimStarRodNeutralFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimStarRodSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimStarRodTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimStunLandUFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimStunStartUFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimSuperJumpPunchAirFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimTauntFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimTechBFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimTechFFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimTechFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimTeeterFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimTeeterstartFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimThrowFFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimThrown1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimThrown2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimThrownDKFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimThrownDKPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimThrownMarioBrosFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimTurnRunFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimUSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimUTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimWalk1FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimWalk2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimWalk3FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimWalkEndFileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimWin2FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimWin3FileID ((intptr_t)0) /* STUBBED */
#define llFTMarioAnimWinBetaFileID ((intptr_t)0) /* STUBBED */
#define llFTNCaptainAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTNDonkeyAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTNFoxAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTNKirbyAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTNLinkAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTNMarioAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTNNessAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTNPikachuAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTNSamusAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTNYoshiAnimPose1PFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimAppear1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimAppear2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimAppearEndFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimAppearStart1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimAppearStart2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimAttackAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimAttackAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimAttackAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimAttackAirNFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimAttackAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCatchPullFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCeilingBonkFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimClangRecoilFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimClapsFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimClashingDuringPKTAFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffAttackQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffAttackQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffAttackSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffAttackSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffClimbQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffClimbQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffClimbSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffClimbSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffEscapeQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffEscapeQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffEscapeSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffEscapeSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffQuickFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffSlowFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCliffWaitFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCrouchEndFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCrouchFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimCrouchIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDKTAAirFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamage2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamageAirFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamageFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamageFlyTopFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamageFlyX1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamageFlyX2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamageX1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamageX2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamageX3FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamaged1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamaged2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamaged3FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamaged4FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamaged5FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamaged6FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDamaged7FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDashAttackFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDashFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDollFallFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDollRevivalFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDownAttackDFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDownAttackUFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDownBStartGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDownBackDFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDownBackUFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDownForwardDFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDownForwardUFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDownSpecialEndAirFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDownSpecialEndGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimDownSpecialStartAirFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimEggLayFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimEggLayPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimEnterPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimExitPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimExitPipeWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimFSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimFTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimFTiltHighFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimFTiltLowFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimFalconDivePulledFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimFallAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimFallFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimFallSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimFireFlowerShootAirFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimFireFlowerShootFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimHammerIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimHammerLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimHealingAirDownBFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimHealingDownBFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimHeavyItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimHeavyItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimItemDropFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimItemThrowAirSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimItemThrowAirSmashFFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimItemThrowAirSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimItemThrowDashFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimItemThrowSmashDFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimItemThrowSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimJab1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimJab2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimJab3FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimJumpAerialBFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimJumpAerialFFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimJumpBFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimJumpFFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimLandingAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimLandingAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimLandingAirXFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimLightItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimPKFireAirFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimPKFireGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimPKThunderAirFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimPKThunderEndAirFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimPKThunderEndFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimPKThunderStartAirFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimPKThunderStartGround1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimPKThunderStartGround2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimPosePlayerFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimRollBFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimRollFFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimRunBrakeFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimRunFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimSelectedFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimShieldBreakFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimShieldDropFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimShieldOffFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimShieldOnFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimSleepFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimStarRodDashFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimStarRodNeutralFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimStarRodSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimStarRodTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimStunLandDFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimStunLandUFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimStunStartDFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimStunStartUFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimTauntFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimTechBFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimTechFFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimTechFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimTeeterFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimTeeterstartFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimThrowFFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimThrown1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimThrown2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimThrownDKFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimThrownDKPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimThrownMarioBrosFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimTurnRunFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimUSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimUTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimWalk1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimWalk2FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimWalk3FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimWalkEndFileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimWin1FileID ((intptr_t)0) /* STUBBED */
#define llFTNessAnimWin2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimAppear1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimAppear2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimAttackAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimAttackAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimAttackAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimAttackAirNFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimAttackAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCatchPullFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCeilingBonkFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimClangRecoilFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimClapsFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffAttackQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffAttackQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffAttackSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffAttackSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffClimbQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffClimbQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffClimbSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffClimbSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffEscapeQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffEscapeQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffEscapeSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffEscapeSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffQuickFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffSlowFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCliffWaitFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCrouchEndFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCrouchFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimCrouchIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamage2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamageAirFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamageFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamageFlyTopFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamageFlyX1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamageFlyX2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamageX1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamageX2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamageX3FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamaged1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamaged2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamaged3FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamaged4FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamaged5FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamaged6FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamaged7FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDamagedFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDashAttackFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDashFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDollFallFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDollPickUpFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDollRevivalFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDownAttackDFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDownAttackUFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDownBackDFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDownBackUFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDownForwardDFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDownForwardUFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDownSpecialEndAirFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDownSpecialEndFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDownSpecialStartAirFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDownSpecialStartFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimDownSpecialThunderedAirFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimEggLayPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimEnterPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimExitPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimExitPipeWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimFSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimFTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimFTiltHighFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimFTiltLowFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimFalconDivePulledFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimFallAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimFallFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimFallSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimFireFlowerShootAirFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimFireFlowerShootFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimGettingThunderedFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimHammerIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimHammerLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimHeavyItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimHeavyItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimItemDropFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimItemThrowAirSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimItemThrowAirSmashFFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimItemThrowAirSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimItemThrowDashFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimItemThrowSmashDFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimItemThrowSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimJab1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimJumpAerialBFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimJumpAerialFFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimJumpBFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimJumpFFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimLandingAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimLandingAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimLandingAirXFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimLightItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimNeutralSpecialAirFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimNeutralSpecialGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimPoseAllyFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimPoseEnemyFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimPosePlayerFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimRollBFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimRollFFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimRunBrakeFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimRunFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimSelectedFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimShieldBreakFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimShieldDropFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimShieldOffFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimShieldOnFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimSleepFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimStarRodDashFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimStarRodNeutralFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimStarRodSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimStarRodTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimStunLandDFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimStunLandUFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimStunStartDFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimStunStartUFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimTauntFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimTechBFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimTechFFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimTechFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimTeeterFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimTeeterstartFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimThrowFFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimThrown1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimThrown2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimThrownDKFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimThrownDKPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimThrownMarioBrosFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimTurnRunFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimUSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimUTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimUnknown1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimUnknown2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimUpSpecialAirEndFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimUpSpecialEndFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimWalk1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimWalk2FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimWalk3FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimWalkEndFileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimWin1FileID ((intptr_t)0) /* STUBBED */
#define llFTPikachuAnimWin2FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimAppear1FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimAppear2FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimAttackAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimAttackAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimAttackAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimAttackAirNFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimAttackAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimBatDashFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimBatSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimCatchPullFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimCeilingBonkFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimCrouchFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimDSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimDTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimDamageFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimDashAttackFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimDashFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimDollFallFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimDollRevivalFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimEggLayFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimExitPipeWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimFSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimFTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimFTiltHighFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimFTiltLowFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimFallAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimFallFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimFallSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimFireFlowerShootFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimHeavyItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimHeavyItemThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimItemThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimItemThrowDashFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimJab1FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimJab2FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimJump2FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimJump3FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimJump4FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimJump5FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimJump6FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimJumpBFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimJumpFFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimJumpSquatFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimLandingAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimPassFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimPoundAirFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimPoundGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimRestAirFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimRollBFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimRollFFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimRunBrakeFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimRunFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimSelectedFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimShieldOffFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimShieldOnFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimSingAirFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimTauntFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimTechFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimTeeterFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimThrowFFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimThrownDKFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimThrownDKPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimTurnRunFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimUSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimUTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimUnknownFileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimWalk1FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimWalk2FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimWalk3FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimWin1FileID ((intptr_t)0) /* STUBBED */
#define llFTPurinAnimWin2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimAppear1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimAppear2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimAttackAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimAttackAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimAttackAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimAttackAirNFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimAttackAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimBombAirFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimBombFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCatchPullFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCeilingBonkFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimChargingNeutralSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimClangRecoilFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimClapsFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffAttackQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffAttackQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffAttackSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffAttackSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffClimbQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffClimbQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffClimbSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffClimbSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffEscapeQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffEscapeQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffEscapeSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffEscapeSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffQuickFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffSlowFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCliffWaitFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCrouchEndFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCrouchFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimCrouchIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamage2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamageAirFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamageFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamageFlyTopFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamageFlyX1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamageFlyX2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamageX1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamageX2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamageX3FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamaged1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamaged2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamaged3FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamaged4FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamaged5FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamaged6FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamaged7FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDamagedFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDashAttackFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDashFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDollFallFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDollPickUpFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDollRevivalFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDownAttackDFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDownAttackUFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDownBackDFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDownBackUFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDownForwardDFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimDownForwardUFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimEggLayFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimEggLayPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimEnterPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimExitPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimExitPipeWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFSmashHighFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFSmashLowFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFSmashMidHighFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFSmashMidLowFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFTiltHighFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFTiltLowFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFTiltMidHighFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFTiltMidLowFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFalconDivePulledFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFallAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFallFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFallSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFireFlowerShootAirFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimFireFlowerShootFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimHammerIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimHammerLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimHeavyItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimHeavyItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimIntroFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimItemDropFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimItemThrowAirSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimItemThrowAirSmashFFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimItemThrowAirSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimItemThrowDashFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimItemThrowSmashDFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimItemThrowSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimJab1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimJab2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimJumpAerialBFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimJumpAerialFFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimJumpBFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimJumpFFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimLandingAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimLandingAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimLandingAirXFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimLightItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimPoseEnemyFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimPosePlayerFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimRollBFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimRollFFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimRunBrakeFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimRunFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimScrewAttackAirFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimScrewAttackGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimSelectedFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimShieldBreakFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimShieldDropFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimShieldOffFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimShieldOnFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimShootingAirFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimShootingFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimSleepFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimStarRodDashFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimStarRodNeutralFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimStarRodSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimStarRodTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimStartingChargeShotAirFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimStartingChargeShotFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimStunLandDFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimStunLandUFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimStunStartDFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimStunStartUFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimTauntFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimTechBFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimTechFFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimTechFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimTeeterFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimTeeterstartFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimThrowFFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimThrown1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimThrown2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimThrown3FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimThrownDKFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimThrownDKPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimThrownFoxBFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimThrownFoxFStartFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimThrownMarioBrosFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimTurnRunFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimUSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimUTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimUnknownFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimWalk1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimWalk2FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimWalk3FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimWalkEndFileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimWin1FileID ((intptr_t)0) /* STUBBED */
#define llFTSamusAnimWin3FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimAppear1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimAppear2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimAttackAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimAttackAirDFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimAttackAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimAttackAirNFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimAttackAirUFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCatchPullFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCeilingBonkFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimClangRecoilFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffAttackQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffAttackQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffAttackSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffAttackSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffCatchFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffClimbQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffClimbQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffClimbSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffClimbSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffEscapeQuick1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffEscapeQuick2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffEscapeSlow1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffEscapeSlow2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffQuickFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffSlowFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCliffWaitFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCrouchEndFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCrouchFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimCrouchIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamage2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamageAirFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamageFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamageFlyTopFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamageFlyX1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamageFlyX2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamageX1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamageX2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamageX3FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamaged1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamaged2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamaged3FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamaged4FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamaged5FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamaged6FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamaged7FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDamagedFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDashAttackFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDashFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDollFallFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDollPickUpFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDollRevivalFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDownAttackDFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDownAttackUFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDownBackDFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDownBackUFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDownForwardDFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimDownForwardUFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimEggLayAirGrabInFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimEggLayAirGrabOutFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimEggLayFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimEggLayGrabbedSomeoneComingInAndSwallowingFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimEggLayGrabbedSomeoneStillGoingOutFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimEggLayPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimEggThrowAirFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimEggThrowGroundFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimEnterPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimExitPipeFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimExitPipeWalkFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimFSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimFSmashHighFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimFSmashLowFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimFTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimFTiltHighFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimFTiltLowFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimFalconDivePulledFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimFallAerialFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimFallFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimFallSpecialFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimFireFlowerShootAirFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimFireFlowerShootFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimGroundPoundAirFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimGroundPoundGroundStartFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimGroundPoundLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimHammerIdleFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimHammerLandingFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimHeavyItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimHeavyItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimIntroPoseFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimItemDropFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimItemThrowAirSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimItemThrowAirSmashFFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimItemThrowAirSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimItemThrowDashFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimItemThrowSmashBFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimItemThrowSmashDFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimItemThrowSmashUFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimJab1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimJab2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimJumpAerialBFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimJumpBFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimJumpFFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimLandingAirBFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimLandingAirFFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimLandingAirXFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimLightItemPickupFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimRollBFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimRollFFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimRunBrakeFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimRunFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimSelectedFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimShieldBreakFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimShieldDropFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimShieldOffFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimShieldOnFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimSleepFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimStarRodDashFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimStarRodNeutralFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimStarRodSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimStarRodTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimStunLandDFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimStunLandUFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimStunStartDFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimStunStartUFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimTauntFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimTeamPosesFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimTechBFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimTechFFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimTechFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimTeeterFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimTeeterstartFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimThrowBFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimThrowFFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimThrown1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimThrown2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimThrownDKFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimThrownDKPulledFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimThrownMarioBrosFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimTurnFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimTurnRunFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimUSmashFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimUTiltFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimUnknown10FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimUnknown1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimUnknown2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimUnknown3FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimUnknown4FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimUnknown5FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimUnknown6FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimUnknown7FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimUnknown8FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimUnknown9FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimWalk1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimWalk2FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimWalk3FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimWalkEndFileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimWin1FileID ((intptr_t)0) /* STUBBED */
#define llFTYoshiAnimWin2FileID ((intptr_t)0) /* STUBBED */
#define llMNTitleUnknownAnimJoint ((intptr_t)0) /* STUBBED */
#define llMNTitleUnknownDObjDesc ((intptr_t)0) /* STUBBED */

#endif /* _RELOC_DATA_H_ */
