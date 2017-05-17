/*
Skin Control tattoo.cpp
By Neutrinobeam
*/

#include "tattoo.h"
#include <vector>

enum tatZone{
	torso = 0,
	head = 1,
	leftArm = 2,
	rightArm = 3,
	leftLeg = 4,
	rightLeg = 5,
	none = 6,
	hair_zone = 7
};

enum tatCollection{
	single = 0,
	multi = 1,
	beach = 2,
	business = 3,
	christ = 4,
	hipster = 5,
	lux = 6,
	lux2 = 7,
	hair_collect = 8
};

const std::vector< std::vector< std::vector< LPCSTR >>>tats = { // player type, zone, index
	{
		{ "mk_004", "mk_006", "mk_008", "mk_014", "mk_015", "mk_017", "mk_018", "mk_020" },
		{ "mk_003" },
		{ "mk_000", "mk_007", "mk_009", "mk_010", "mk_012", "mk_019" },
		{ "mk_001", "mk_005", "mk_013", "mk_016" },
		{ "mk_002" },
		{ "mk_011" },
		{}
	},
	{
		{ "fr_000", "fr_004", "fr_010", "fr_011", "fr_018", "fr_020", "fr_021", "fr_024", "fr_025", "fr_028", "fr_029", "fr_030", "fr_031", "fr_032", "fr_035", "fr_036", "fr_037", "fr_038", "fr_039" },
		{ "fr_005", "fr_013", "fr_014", "fr_022", "fr_033", "fr_034" },
		{ "fr_001", "fr_007", "fr_016", "fr_017", "fr_019" },
		{ "fr_006", "fr_008", "fr_009", "fr_012", "fr_023" },
		{ "fr_002", "fr_015", "fr_027" },
		{ "fr_003", "fr_026" },
		{}
	},
	{
		{ "tp_000", "tp_004", "tp_006", "tp_012", "tp_013", "tp_015", "tp_021", "tp_022", "tp_023", "tp_026", "tp_027", "tp_028", "tp_029", "tp_030", "tp_031", "tp_032", "tp_033" },
		{},
		{ "tp_001", "tp_003", "tp_016", "tp_017", "tp_018", "tp_024" },
		{ "tp_007", "tp_008", "tp_009", "tp_010", "tp_014", "tp_020" },
		{ "tp_002", "tp_011" },
		{ "tp_005", "tp_019", "tp_025" },
		{}
	},
	{
		{ "FM_Tat_Award_F_003", "FM_Tat_Award_F_004", "FM_Tat_Award_F_005", "FM_Tat_Award_F_008", "FM_Tat_Award_F_011", "FM_Tat_Award_F_012", "FM_Tat_Award_F_013", "FM_Tat_Award_F_014", "FM_Tat_Award_F_016", "FM_Tat_Award_F_017",
		"FM_Tat_Award_F_018", "FM_Tat_Award_F_019", "FM_Tat_F_004", "FM_Tat_F_009", "FM_Tat_F_010", "FM_Tat_F_011", "FM_Tat_F_012", "FM_Tat_F_013", "FM_Tat_F_016", "FM_Tat_F_019", "FM_Tat_F_020", "FM_Tat_F_024", "FM_Tat_F_025",
		"FM_Tat_F_029", "FM_Tat_F_030", "FM_Tat_F_034", "FM_Tat_F_036", "FM_Tat_F_044", "FM_Tat_F_045", "FM_Tat_F_046",
		"MP_Bea_F_Back_000", "MP_Bea_F_Back_001", "MP_Bea_F_Back_002", "MP_Bea_F_Chest_000", "MP_Bea_F_Chest_001", "MP_Bea_F_Chest_002",
		"MP_Buis_F_Back_000", "MP_Buis_F_Back_001", "MP_Buis_F_Chest_000", "MP_Buis_F_Chest_001", "MP_Buis_F_Chest_002", "MP_Buis_F_Stom_000", "MP_Buis_F_Stom_001", "MP_Buis_F_Stom_002", "MP_Female_Crew_Tat_000",
		"MP_Xmas2_F_Tat_005", "MP_Xmas2_F_Tat_006", "MP_Xmas2_F_Tat_009", "MP_Xmas2_F_Tat_011", "MP_Xmas2_F_Tat_013", "MP_Xmas2_F_Tat_015", "MP_Xmas2_F_Tat_016", "MP_Xmas2_F_Tat_017", "MP_Xmas2_F_Tat_018",
		"MP_Xmas2_F_Tat_019", "MP_Xmas2_F_Tat_028",
		"FM_Hip_F_Tat_000", "FM_Hip_F_Tat_002", "FM_Hip_F_Tat_006", "FM_Hip_F_Tat_011", "FM_Hip_F_Tat_012", "FM_Hip_F_Tat_013", "FM_Hip_F_Tat_024", "FM_Hip_F_Tat_025", "FM_Hip_F_Tat_029", "FM_Hip_F_Tat_030",
		"FM_Hip_F_Tat_031", "FM_Hip_F_Tat_032", "FM_Hip_F_Tat_033", "FM_Hip_F_Tat_035", "FM_Hip_F_Tat_041", "FM_Hip_F_Tat_046", "FM_Hip_F_Tat_047",
		"MP_LUXE_TAT_003_F", "MP_LUXE_TAT_006_F", "MP_LUXE_TAT_007_F", "MP_LUXE_TAT_008_F", "MP_LUXE_TAT_014_F", "MP_LUXE_TAT_015_F", "MP_LUXE_TAT_024_F",
		"MP_Luxe_Tat_002_F", "MP_Luxe_Tat_012_F", "MP_Luxe_Tat_022_F", "MP_Luxe_Tat_025_F", "MP_Luxe_Tat_027_F", "MP_Luxe_Tat_029_F" },
		{
		// "FM_F_Hair_003_a", "FM_F_Hair_003_b", "FM_F_Hair_003_c", "FM_F_Hair_003_d", "FM_F_Hair_003_e", "FM_F_Hair_005_a", "FM_F_Hair_005_b", "FM_F_Hair_005_c", "FM_F_Hair_005_d", "FM_F_Hair_005_e", "FM_F_Hair_006_a",
		//	"FM_F_Hair_006_b", "FM_F_Hair_006_c", "FM_F_Hair_006_d", "FM_F_Hair_006_e", "FM_F_Hair_013_a", "FM_F_Hair_013_b", "FM_F_Hair_013_c", "FM_F_Hair_013_d", "FM_F_Hair_013_e", "FM_F_Hair_014_a", "FM_F_Hair_014_b",
		//	"FM_F_Hair_014_c", "FM_F_Hair_014_d", "FM_F_Hair_014_e", "FM_F_Hair_long_a", "FM_F_Hair_long_b", "FM_F_Hair_long_c", "FM_F_Hair_long_d", "FM_F_Hair_long_e",
		"FM_Tat_Award_F_000", // "FM_Hair_Fuzz", "FM_Bus_F_Hair_a", "FM_Bus_F_Hair_b", "FM_Bus_F_Hair_c", "FM_Bus_F_Hair_d", "FM_Bus_F_Hair_e",
		"MP_Buis_F_Neck_000", "MP_Buis_F_Neck_001", "MP_Xmas2_M_Tat_007", "MP_Xmas2_M_Tat_024", "MP_Xmas2_M_Tat_025", "MP_Xmas2_M_Tat_029", "MP_Xmas2_F_Tat_007", "MP_Xmas2_F_Tat_024", "MP_Xmas2_F_Tat_025", "MP_Xmas2_F_Tat_029",
		//  "FM_Hip_F_Hair_000_a", "FM_Hip_F_Hair_000_b", "FM_Hip_F_Hair_000_c", "FM_Hip_F_Hair_000_d", "FM_Hip_F_Hair_000_e", "FM_F_Hair_017_a", "FM_F_Hair_017_b", "FM_F_Hair_017_c", "FM_F_Hair_017_d", "FM_F_Hair_017_e",
		//  "FM_F_Hair_020_a", "FM_F_Hair_020_b", "FM_F_Hair_020_c", "FM_F_Hair_020_d", "FM_F_Hair_020_e",
		"FM_Hip_F_Tat_005", "FM_Hip_F_Tat_021" },
		{ "FM_Tat_Award_F_001", "FM_Tat_Award_F_007", "FM_Tat_Award_F_015", "FM_Tat_F_005", "FM_Tat_F_006", "FM_Tat_F_015", "FM_Tat_F_031", "FM_Tat_F_041", "MP_Buis_F_LArm_000", "MP_Xmas2_F_Tat_000", "MP_Xmas2_F_Tat_010",
		"MP_Xmas2_F_Tat_012", "MP_Xmas2_F_Tat_020", "MP_Xmas2_F_Tat_021", "FM_Hip_F_Tat_003", "FM_Hip_F_Tat_007", "FM_Hip_F_Tat_015", "FM_Hip_F_Tat_016", "FM_Hip_F_Tat_026", "FM_Hip_F_Tat_027", "FM_Hip_F_Tat_028",
		"FM_Hip_F_Tat_034", "FM_Hip_F_Tat_037", "FM_Hip_F_Tat_039", "FM_Hip_F_Tat_043", "FM_Hip_F_Tat_048", "MP_LUXE_TAT_009_F", "MP_LUXE_TAT_020_F",
		"MP_Luxe_Tat_005_F", "MP_Luxe_Tat_016_F", "MP_Luxe_Tat_018_F", "MP_Luxe_Tat_028_F", "MP_Luxe_Tat_031_F" },
		{ "FM_Tat_Award_F_002", "FM_Tat_Award_F_010", "FM_Tat_F_001", "FM_Tat_F_003", "FM_Tat_F_014", "FM_Tat_F_018", "FM_Tat_F_027", "FM_Tat_F_028", "FM_Tat_F_038", "FM_Tat_F_047", "MP_Bea_F_RArm_001", "MP_Buis_F_RArm_000",
		"MP_Female_Crew_Tat_001", "MP_Xmas2_F_Tat_003", "MP_Xmas2_F_Tat_004", "MP_Xmas2_F_Tat_008", "MP_Xmas2_F_Tat_022", "MP_Xmas2_F_Tat_023", "MP_Xmas2_F_Tat_026", "MP_Xmas2_F_Tat_027", "FM_Hip_F_Tat_001", "FM_Hip_F_Tat_004",
		"FM_Hip_F_Tat_008", "FM_Hip_F_Tat_010", "FM_Hip_F_Tat_014", "FM_Hip_F_Tat_017", "FM_Hip_F_Tat_018", "FM_Hip_F_Tat_020", "FM_Hip_F_Tat_022", "FM_Hip_F_Tat_023", "FM_Hip_F_Tat_036", "FM_Hip_F_Tat_044", "FM_Hip_F_Tat_045",
		"MP_LUXE_TAT_004_F", "MP_LUXE_TAT_013_F", "MP_LUXE_TAT_019_F",
		"MP_Luxe_Tat_010_F", "MP_Luxe_Tat_017_F", "MP_Luxe_Tat_026_F", "MP_Luxe_Tat_030_F" },
		{ "FM_Tat_Award_F_009", "FM_Tat_F_002", "FM_Tat_F_008", "FM_Tat_F_021", "FM_Tat_F_023", "FM_Tat_F_026", "FM_Tat_F_032", "FM_Tat_F_033", "FM_Tat_F_035", "FM_Tat_F_037", "MP_Xmas2_F_Tat_001", "MP_Xmas2_F_Tat_002",
		"FM_Hip_F_Tat_009", "FM_Hip_F_Tat_019", "FM_Hip_F_Tat_040", "MP_LUXE_TAT_000_F",
		"MP_Luxe_Tat_011_F" },
		{ "FM_Tat_Award_F_006", "FM_Tat_F_007", "FM_Tat_F_017", "FM_Tat_F_022", "FM_Tat_F_039", "FM_Tat_F_040", "FM_Tat_F_042", "FM_Tat_F_043", "MP_Bea_F_RLeg_000", "MP_Buis_F_RLeg_000", "MP_Xmas2_F_Tat_014",
		"FM_Hip_F_Tat_038", "FM_Hip_F_Tat_042", "MP_LUXE_TAT_001_F",
		"MP_Luxe_Tat_023_F" },
		{ "NG_F_Hair_001", "NG_F_Hair_002", "NG_F_Hair_003", "NG_F_Hair_004", "NG_F_Hair_005",
		"NG_F_Hair_006", "NG_F_Hair_007", "NG_F_Hair_008", "NG_F_Hair_009", "NG_F_Hair_010", "NG_F_Hair_011", "NG_F_Hair_012", "NG_F_Hair_013", "NG_F_Hair_014", "NG_F_Hair_015", "NGBea_F_Hair_000", "NGBea_F_Hair_001",
		"NGBus_F_Hair_000", "NGBus_F_Hair_001", "NGHip_F_Hair_000", "NGHip_F_Hair_001", "NGInd_F_Hair_000" }
	},
	{
		{ "FM_Tat_Award_M_003", "FM_Tat_Award_M_004", "FM_Tat_Award_M_005", "FM_Tat_Award_M_008", "FM_Tat_Award_M_011", "FM_Tat_Award_M_012", "FM_Tat_Award_M_013", "FM_Tat_Award_M_014", "FM_Tat_Award_M_016",
		"FM_Tat_Award_M_017", "FM_Tat_Award_M_018", "FM_Tat_Award_M_019", "FM_Tat_M_004", "FM_Tat_M_009", "FM_Tat_M_010", "FM_Tat_M_011", "FM_Tat_M_012", "FM_Tat_M_013", "FM_Tat_M_016", "FM_Tat_M_019", "FM_Tat_M_020",
		"FM_Tat_M_024", "FM_Tat_M_025", "FM_Tat_M_029", "FM_Tat_M_030", "FM_Tat_M_034", "FM_Tat_M_036", "FM_Tat_M_044", "FM_Tat_M_045", "FM_Tat_M_046",
		"MP_Bea_M_Back_000", "MP_Bea_M_Chest_000", "MP_Bea_M_Chest_001", "MP_Bea_M_Stom_000", "MP_Bea_M_Stom_001", "MP_Bea_M_Stom_000", "MP_Buis_M_Back_000", "MP_Buis_M_Chest_000", "MP_Buis_M_Chest_001",
		"MP_Buis_M_Stomach_000", "MP_Male_Crew_Tat_000",
		"MP_Xmas2_M_Tat_005", "MP_Xmas2_M_Tat_006", "MP_Xmas2_M_Tat_009", "MP_Xmas2_M_Tat_011", "MP_Xmas2_M_Tat_013", "MP_Xmas2_M_Tat_015", "MP_Xmas2_M_Tat_016", "MP_Xmas2_M_Tat_017", "MP_Xmas2_M_Tat_018",
		"MP_Xmas2_M_Tat_019", "MP_Xmas2_M_Tat_028",
		"FM_Hip_M_Tat_000", "FM_Hip_M_Tat_002", "FM_Hip_M_Tat_006", "FM_Hip_M_Tat_011", "FM_Hip_M_Tat_012", "FM_Hip_M_Tat_013", "FM_Hip_M_Tat_024", "FM_Hip_M_Tat_025", "FM_Hip_M_Tat_029", "FM_Hip_M_Tat_030",
		"FM_Hip_M_Tat_031", "FM_Hip_M_Tat_032", "FM_Hip_M_Tat_033", "FM_Hip_M_Tat_035", "FM_Hip_M_Tat_041", "FM_Hip_M_Tat_046", "FM_Hip_M_Tat_047",
		"MP_LUXE_TAT_003_M", "MP_LUXE_TAT_006_M", "MP_LUXE_TAT_007_M", "MP_LUXE_TAT_008_M", "MP_LUXE_TAT_014_M", "MP_LUXE_TAT_015_M", "MP_LUXE_TAT_024_M",
		"MP_Luxe_Tat_002_M", "MP_Luxe_Tat_012_M", "MP_Luxe_Tat_022_M", "MP_Luxe_Tat_025_M", "MP_Luxe_Tat_027_M", "MP_Luxe_Tat_029_M" },
		{ //"FM_M_Hair_long_a", "FM_M_Hair_long_b", "FM_M_Hair_long_c", "FM_M_Hair_long_d", "FM_M_Hair_long_e",
		"FM_Tat_Award_M_000", // "FM_Hair_Fuzz",
		"MP_Bea_M_Head_000", "MP_Bea_M_Head_001", "MP_Bea_M_Head_002", "MP_Bea_M_Neck_000", "MP_Bea_M_Neck_001", "MP_Bea_F_Neck_000",
		// "FM_Bus_M_Hair_001_a", "FM_Bus_M_Hair_001_b", "FM_Bus_M_Hair_001_c", "FM_Bus_M_Hair_001_d", "FM_Bus_M_Hair_001_e",
		"MP_Buis_M_Neck_000", "MP_Buis_M_Neck_001", "MP_Buis_M_Neck_002", "MP_Buis_M_Neck_003",
		// "FM_Hip_M_Hair_000_a", "FM_Hip_M_Hair_000_b", "FM_Hip_M_Hair_000_c", "FM_Hip_M_Hair_000_d", "FM_Hip_M_Hair_000_e", "FM_Hip_M_Hair_001_a",
		// "FM_Hip_M_Hair_001_b", "FM_Hip_M_Hair_001_c", "FM_Hip_M_Hair_001_d", "FM_Hip_M_Hair_001_e", "FM_Disc_M_Hair_001_a", "FM_Disc_M_Hair_001_b", "FM_Disc_M_Hair_001_c", "FM_Disc_M_Hair_001_d", "FM_Disc_M_Hair_001_e",
		"FM_Hip_M_Tat_005", "FM_Hip_M_Tat_021" },
		{ "FM_Tat_Award_M_001", "FM_Tat_Award_M_007", "FM_Tat_Award_M_015", "FM_Tat_M_005", "FM_Tat_M_006", "FM_Tat_M_015", "FM_Tat_M_031", "FM_Tat_M_041", "MP_Bea_M_LArm_000", "MP_Bea_M_LArm_001", "MP_Bea_F_LArm_000",
		"MP_Bea_F_LArm_001", "MP_Buis_M_LeftArm_000", "MP_Buis_M_LeftArm_001", "MP_Xmas2_M_Tat_010", "MP_Xmas2_M_Tat_012", "MP_Xmas2_M_Tat_020", "MP_Xmas2_M_Tat_021", "FM_Hip_M_Tat_003", "FM_Hip_M_Tat_007", "FM_Hip_M_Tat_015",
		"FM_Hip_M_Tat_016", "FM_Hip_M_Tat_026", "FM_Hip_M_Tat_027", "FM_Hip_M_Tat_028", "FM_Hip_M_Tat_034", "FM_Hip_M_Tat_037", "FM_Hip_M_Tat_039", "FM_Hip_M_Tat_043", "FM_Hip_M_Tat_048", "MP_LUXE_TAT_009_M", "MP_LUXE_TAT_020_M",
		"MP_LUXE_TAT_021_M",
		"MP_Luxe_Tat_005_M", "MP_Luxe_Tat_016_M", "MP_Luxe_Tat_018_M", "MP_Luxe_Tat_028_M", "MP_Luxe_Tat_031_M" },
		{ "FM_Tat_Award_M_002", "FM_Tat_Award_M_010", "FM_Tat_M_000", "FM_Tat_M_001", "FM_Tat_M_003", "FM_Tat_M_014", "FM_Tat_M_018", "FM_Tat_M_027", "FM_Tat_M_028", "FM_Tat_M_038", "FM_Tat_M_047", "MP_Bea_M_RArm_000",
		"MP_Bea_M_RArm_001", "MP_Buis_M_RightArm_000", "MP_Buis_M_RightArm_001", "MP_Male_Crew_Tat_001", "MP_Xmas2_M_Tat_003", "MP_Xmas2_M_Tat_004", "MP_Xmas2_M_Tat_008", "MP_Xmas2_M_Tat_022", "MP_Xmas2_M_Tat_023",
		"MP_Xmas2_M_Tat_026", "MP_Xmas2_M_Tat_027", "FM_Hip_M_Tat_001", "FM_Hip_M_Tat_004", "FM_Hip_M_Tat_008", "FM_Hip_M_Tat_010", "FM_Hip_M_Tat_014", "FM_Hip_M_Tat_017", "FM_Hip_M_Tat_018", "FM_Hip_M_Tat_020",
		"FM_Hip_M_Tat_022", "FM_Hip_M_Tat_023", "FM_Hip_M_Tat_036", "FM_Hip_M_Tat_044", "FM_Hip_M_Tat_045", "MP_LUXE_TAT_004_M", "MP_LUXE_TAT_013_M", "MP_LUXE_TAT_019_M",
		"MP_Luxe_Tat_010_M", "MP_Luxe_Tat_017_M", "MP_Luxe_Tat_026_M", "MP_Luxe_Tat_030_M", },
		{ "FM_Tat_Award_M_009", "FM_Tat_M_002", "FM_Tat_M_008", "FM_Tat_M_021", "FM_Tat_M_023", "FM_Tat_M_026", "FM_Tat_M_032", "FM_Tat_M_033", "FM_Tat_M_035", "FM_Tat_M_037", "MP_Bea_M_Lleg_000", "MP_Buis_F_LLeg_000",
		"MP_Xmas2_M_Tat_001", "MP_Xmas2_M_Tat_002", "FM_Hip_M_Tat_009", "FM_Hip_M_Tat_019", "FM_Hip_M_Tat_040", "MP_LUXE_TAT_000_M",
		"MP_Luxe_Tat_011_M" },
		{ "FM_Tat_Award_M_006", "FM_Tat_M_007", "FM_Tat_M_017", "FM_Tat_M_022", "FM_Tat_M_039", "FM_Tat_M_040", "FM_Tat_M_042", "FM_Tat_M_043", "MP_Bea_M_Rleg_000", "MP_Xmas2_M_Tat_014", "FM_Hip_M_Tat_038",
		"FM_Hip_M_Tat_042", "MP_LUXE_TAT_001_M",
		"MP_Luxe_Tat_023_M" },
		{ "NG_M_Hair_001", "NG_M_Hair_002", "NG_M_Hair_003", "NG_M_Hair_004", "NG_M_Hair_005", "NG_M_Hair_006", "NG_M_Hair_007", "NG_M_Hair_008", "NG_M_Hair_009", "NG_M_Hair_010", "NG_M_Hair_011", "NG_M_Hair_012",
		"NG_M_Hair_013", "NG_M_Hair_014", "NG_M_Hair_015", "NGBea_M_Hair_000", "NGBea_M_Hair_001", "NGBus_M_Hair_000", "NGBus_M_Hair_001", "NGHip_M_Hair_000", "NGHip_M_Hair_001", "NGInd_M_Hair_000" }
	}
};

LPCSTR collections[] = { "singleplayer_overlays", "multiplayer_overlays", "mpBeach_overlays", "mpBusiness_overlays", "mpChristmas2_overlays", "mpHipster_overlays",
"mpLuxe_overlays", "mpLuxe2_overlays", "hairOverlay" };

LPCSTR tattooSlotNames[] = { "Torso", "Face & Neck", "Left Arm", "Right Arm", "Left Leg", "Right Leg", " ", "Hair" };

int getTattoSlotNameID(int tatSlot){
	switch (tatSlot){
	case 0: return tatZone::torso;
	case 8: return tatZone::head;
	case 9: return tatZone::leftArm;
	case 11: return tatZone::rightArm;
	case 13: return tatZone::leftLeg;
	case 14: return tatZone::rightLeg;
	case 15: return tatZone::hair_zone;
	default: return tatZone::none;
	}
}

LPCSTR getTattoSlotName(int tatSlot){
	return tattooSlotNames[getTattoSlotNameID(tatSlot)];
}

int getNumAvailableTat(int zone, int type, DWORD mask){
	int count = 0;
	if (type < 0 || type > 4 || zone < 0 || zone > 6)
		return 0;
	return (int)tats[type][zone].size();
}

int getTatZone(int tatSlot){
	switch (tatSlot){
	case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
		return tatZone::torso;
	case 8: return tatZone::head;
	case 9: case 10: return tatZone::leftArm;
	case 11: case 12: return tatZone::rightArm;
	case 13: return tatZone::leftLeg;
	case 14: return tatZone::rightLeg;
	case 15: return tatZone::hair_zone;
	default: return tatZone::none;
	}
}

int getTatCollection(int type, int zone, int value){
	if (value < 0 || type < 0 || type > 4)
		return -1;
	Hash big, little;
	switch (type){
	case 0: case 1: case 2:
		return tatCollection::single;
	case 3: case 4:
		little = getTatHash(type, zone, value);
		for (int i = 1; i < sizeof(collections) / sizeof(LPCSTR); ++i){
			big = getTatCollectionHash(i);
			if (PED::_GET_TATTOO_ZONE(big, little) != 7){
				return i;
			}
		}
	default:
		return -1;
	}
}

Hash getTatCollectionHash(int id){
	if (id > tatCollection::hair_collect) return 0;
	return GAMEPLAY::GET_HASH_KEY((char*)collections[id]);
}

Hash getTatHash(int type, int zone, int value){
	if (type < 0 || type > 4 || zone < tatZone::torso || zone > tatZone::none) return 0;
	return GAMEPLAY::GET_HASH_KEY((char*)tats[type][zone][value]);
}

void getTats(PedSkin & skin, int type, bool global){
	if (!isPlayer(type) || skin.tatsPreserve){
		return;
	}
	if (global){
		// to do, read from global
		// I gave up trying to decipher the scripts.
	}
	for (int i = 0; i < numTatSlots; ++i){
		skin.tattoo[i].value = -1;
		skin.tattoo[i].collection = -1;
	}

}

void updateTats(PedSkin & skin, int type){
	if (!isPlayer(type))
		return;
	Ped id = PLAYER::PLAYER_PED_ID();
	int v;
	int c;
	Hash big;
	Hash little;
	PED::CLEAR_PED_DECORATIONS(id);
	for (int i = 0; i < numTatSlots; ++i){
		v = skin.tattoo[i].value;
		c = skin.tattoo[i].collection;
		if (v > -1 && c > -1){
			big = getTatCollectionHash(c);
			little = getTatHash(type, getTatZone(i), v);
			PED::_APPLY_PED_OVERLAY(id, big, little);
		}
	}
};
