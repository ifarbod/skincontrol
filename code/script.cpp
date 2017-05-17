/*
Skin Control script.cpp
By Neutrinobeam
*/

#pragma once
#include "script.h"
#include "menu.h"
#include "dataFile.h"
#include "weapons.h"
#include "keyboard.h"

void ScriptMain()
{
	main();
}
void main()
{
	int hotkey = HOTKEY;
	bool nonDefaultSkin = false;
	Hash lastValidSkin = 0;
	std::vector<Entity> storedWeapons = {};
	std::vector<std::pair<Hash, int>> storedAmmoWeapons = {};
	int convertFile = checkDataFile(hotkey);
	PedSkin menuSkin;
	while (true)
	{
		if (IsKeyJustUp(hotkey)){
			processSkinControlMenu(convertFile, lastValidSkin, nonDefaultSkin, menuSkin, storedWeapons, storedAmmoWeapons, hotkey);
		}
		updateFeatures(nonDefaultSkin, lastValidSkin);
		WAIT(0);
	}
}

// Non-default skins may cause infinite black screen when dying
void setNondefaultSkin(int skinIndex, bool & nonDefaultSkin){
	switch (skinIndex){
	case 0:
	case 1:
	case 2:
		nonDefaultSkin = false;
		break;
	default:
		nonDefaultSkin = true;
		break;
	}
}

// Keep last default skin in case need to change back
void setLastSkin(Hash model, Hash & lastValidSkin){
	int index = hashLookup(model);
	if (index == 0 || index == 1 || index == 2){
		lastValidSkin = model;
	}
}

// Runs every tick, catches player death or arrest
void updateFeatures(bool & nonDefaultSkin, Hash lastValidSkin){
	if (nonDefaultSkin)
		checkPlayerModel(nonDefaultSkin, lastValidSkin);
}

void checkPlayerModel(bool & nonDefaultSkin, Hash lastValidSkin)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (ENTITY::DOES_ENTITY_EXIST(playerPed) == 0) return;

	Hash model = ENTITY::GET_ENTITY_MODEL(playerPed);
	if ((ENTITY::IS_ENTITY_DEAD(playerPed) | PLAYER::IS_PLAYER_BEING_ARRESTED(player, TRUE)) != 0){
		setMainMenu();
		if (nonDefaultSkin)
		{
			MM::notifyAboveMap("Switching to player");
			model = lastValidSkin;
			if (lastValidSkin == 0){
				model = GAMEPLAY::GET_HASH_KEY("player_one");
			}
			STREAMING::REQUEST_MODEL(model);
			Hash equipped;
			std::vector<Entity> storedWeapons;
			std::vector<std::pair<Hash, int>> storedAmmoWeapons;
			getWeaponsFromPed(playerPed, &storedWeapons, &storedAmmoWeapons, &equipped);
			while (!STREAMING::HAS_MODEL_LOADED(model))
				WAIT(0);
			PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
			PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			nonDefaultSkin = false;
			// wait until player is ressurected
			while ((ENTITY::IS_ENTITY_DEAD(PLAYER::PLAYER_PED_ID()) | PLAYER::IS_PLAYER_BEING_ARRESTED(player, TRUE)) != 0)
				WAIT(0);
			setWeaponsOfPed(PLAYER::PLAYER_PED_ID(), &storedWeapons, &storedAmmoWeapons, getUnarmedHash());
		}
	}
}

void resetGlobals(int & convertFile){
	bool convert = true;
	setMainMenu();
	if (convertFile > 0){
		MM::notifyAboveMap("Skin Control found an old save file, converting.");
		if (convertFile > 1)
			convert &= convertDataFile2_0();
		convert &= convertDataFile2_1();
		convertFile = 0;
		if (!convert)
			initDataFile();
	}
}

int hashLookup(Hash hex){
	switch (hex)
	{
		// Weapons
	case 0xA2719263:  return 0; //WEAPON_UNARMED=
	case 0x99B507EA:  return 1; //WEAPON_KNIFE=
	case 1737195953:  return 2; //WEAPON_NIGHTSTICK=
	case 1317494643:  return 3; //WEAPON_HAMMER=
	case 0x958A4A8F:  return 4; //WEAPON_BAT=
	case 0x84BD7BFD:  return 5; //WEAPON_CROWBAR=
	case 1141786504:  return 6; //WEAPON_GOLFCLUB=
	case 4192643659:  return 7; //WEAPON_BOTTLE
	case 2460120199:  return 8; //WEAPON_DAGGER
	case 4191993645:  return 9; //WEAPON_HATCHET
	case 600439132:  return 10; //WEAPON_BALL=
	case 126349499:  return 11; //WEAPON_SNOWBALL
	case 3638508604: return 12; //WEAPON_KNUCKLE
	case 453432689:  return 13; //WEAPON_PISTOL=
	case 1593441988: return 14; //WEAPON_COMBATPISTOL=
	case 3218215474: return 15; //WEAPON_SNSPISTOL
	case 584646201:  return 16; //WEAPON_APPISTOL=
	case 0x99AEEB3B: return 17; //WEAPON_PISTOL50=
	case 3523564046: return 18; //WEAPON_HEAVYPISTOL
	case 137902532:  return 19; //WEAPON_VINTAGEPISTOL

	case 3696079510: return 20; //WEAPON_MARKSMANPISTOL
	case 911657153:  return 21; //WEAPON_STUNGUN=
	case 1198879012: return 22; //WEAPON_FLAREGUN
	case 324215364:  return 23; //WEAPON_MICROSMG
	case 736523883:  return 24; //WEAPON_SMG=
	case 0xEFE7E2DF: return 25; //WEAPON_ASSAULTSMG=
	case 171789620:  return 26;	//WEAPON_COMBATPDW
	case 0x9D07F764: return 27; //WEAPON_MG=
	case 2144741730: return 28; //WEAPON_COMBATMG=
	case 1627465347: return 29; //WEAPON_GUSENBERG
	case 0xBFEFFF6D: return 30; //WEAPON_ASSAULTRIFLE=
	case 0x83BF0278: return 31; //WEAPON_CARBINERIFLE=
	case 0xAF113F99: return 32; //WEAPON_ADVANCEDRIFLE=
	case 3231910285: return 33; //WEAPON_SPECIALCARBINE
	case 2132975508: return 34; //WEAPON_BULLPUPRIFLE
	case 487013001:  return 35; //WEAPON_PUMPSHOTGUN=
	case 2017895192: return 36; //WEAPON_SAWNOFFSHOTGUN=
	case 0xE284C527: return 37; //WEAPON_ASSAULTSHOTGUN=
	case 0x9D61E50F: return 38; //WEAPON_BULLPUPSHOTGUN=
	case 984333226:  return 39; //WEAPON_HEAVYSHOTGUN

	case 100416529:  return 40; //WEAPON_SNIPERRIFLE=
	case 205991906:  return 41; //WEAPON_HEAVYSNIPER=
	case 3342088282: return 42; //WEAPON_MARKSMANRIFLE
	case 2828843422: return 43; //WEAPON_MUSKET
	case 0xA284510B: return 44; //WEAPON_GRENADELAUNCHER=
	case 0xB1CA77B1: return 45; //WEAPON_RPG=
	case 2138347493: return 46; //WEAPON_FIREWORK
	case 1119849093: return 47; //WEAPON_MINIGUN=
	case 1834241177: return 48; //WEAPON_RAILGUN
	case 1672152130: return 49; //WEAPON_HOMINGLAUNCHER
	case 0x93E220BD: return 50; //WEAPON_GRENADE=
	case 741814745:  return 51; //WEAPON_STICKYBOMB=
	case 2874559379: return 52; //WEAPON_PROXMINE
	case 0xFDBC8A50: return 53; //WEAPON_SMOKEGRENADE=
	case 0xA0973D5E: return 54; //WEAPON_BZGAS=
	case 1233104067: return 55; //WEAPON_FLARE=
	case 615608432:  return 56; //WEAPON_MOLOTOV=
	case 101631238:  return 57; //WEAPON_FIREEXTINGUISHER=
	case 883325847:  return 58; //WEAPON_PETROLCAN=
	case 0xFDBADCED: return 59; //WEAPON_DIGISCANNER=

	case 0x88C78EB7: return 60; //WEAPON_BRIEFCASE=
	case 28811031:   return 61; //WEAPON_BRIEFCASE_02=

	// Ped Models
	case 225514697:  return 0; // player_zero
	case 2602752943: return 1; // player_one
	case 2608926626: return 2; // player_two
	case 2627665880: return 3; // mp_f_freemode_01
	case 1885233650: return 4; // mp_m_freemode_01
		// 20
	case 2306246977: return 20; // csb_abigail
	case 1074457665: return 21; // ig_abigail
	case 4037813798: return 22; // u_m_y_abner
	case 4042020578: return 23; // u_m_m_aldinapoli
	case 2515474659: return 24; // cs_amandatownley
	case 1830688247: return 25; // ig_amandatownley
	case 3881194279: return 26; // cs_andreas
	case 1206185632: return 27; // ig_andreas
	case 117698822:  return 28; // csb_anita
	case 2781317046: return 29; // csb_anton
	case 3479321132: return 30; // u_m_y_antonb
	case 650367097:  return 31; // cs_ashley
	case 2129936603: return 32; // ig_ashley
	case 1752208920: return 33; // g_m_y_azteca_01
	case 3658575486: return 34; // u_m_y_babyd
	case 1767447799: return 35; // cs_barry
	case 797459875:  return 36; // ig_barry
	case 3027157846: return 37; // cs_beverly
	case 3181518428: return 38; // ig_beverly
	case 4024807398: return 39; // cs_brad
		// 40
	case 3183167778: return 40; // ig_brad
	case 1915268960: return 41; // cs_bradcadaver
	case 3935738944: return 42; // cs_casey
	case 3774489940: return 43; // ig_casey
	case 261586155:  return 44; // s_m_y_chef_01
	case 2739391114: return 45; // csb_chef
	case 2925257274: return 46; // csb_chef2
	case 1240128502: return 47; // ig_chef
	case 2240322243: return 48; // ig_chef2
	case 610290475:  return 49; // u_m_y_chip
	case 3237179831: return 50; // mp_m_claude_01
	case 2634057640: return 51; // ig_claypain
	case 3687553076: return 52; // cs_clay
	case 1825562762: return 53; // ig_clay
	case 3404326357: return 54; // csb_cletus
	case 3865252245: return 55; // ig_cletus
	case 216536661:  return 56; // cs_dale
	case 1182012905: return 57; // ig_dale
	case 2240226444: return 58; // cs_davenorton
	case 365775923:  return 59; // ig_davenorton
		// 60
	case 3973074921: return 60; // cs_debra
	case 1870669624: return 61; // cs_denise
	case 2181772221: return 62; // ig_denise
	case 3045926185: return 63; // csb_denise_friend
	case 788622594:  return 64; // cs_devin
	case 1952555184: return 65; // ig_devin
	case 2606068340: return 66; // s_m_y_devinsec_01
	case 1635617250: return 67; // csb_popov
	case 645279998:  return 68; // ig_popov
	case 1198698306: return 69; // cs_dom
	case 2620240008: return 70; // ig_dom
	case 2745392175: return 71; // cs_drfriedlander
	case 3422293493: return 72; // ig_drfriedlander
	case 712602007:  return 73; // u_m_m_edtoh
	case 2349847778: return 74; // cs_tomepsilon
	case 3447159466: return 75; // ig_tomepsilon
	case 1191403201: return 76; // cs_fabien
	case 3499148112: return 77; // ig_fabien
	case 3284966005: return 78; // cs_mrk
	case 3990661997: return 79; // ig_mrk
		// 80
	case 103106535:  return 80; // cs_floyd
	case 2981205682: return 81; // ig_floyd
	case 2727244247: return 82; // csb_g
	case 261428209:  return 83; // cs_guadalope
	case 3969814300: return 84; // csb_hao
	case 1704428387: return 85; // ig_hao
	case 1863555924: return 86; // csb_hugh
	case 3812756443: return 87; // csb_imran
	case 3064628686: return 88; // u_f_y_comjane
	case 808778210:  return 89; // cs_janet
	case 225287241:  return 90; // ig_janet
	case 2050158196: return 91; // ig_jay_norris
	case 60192701:   return 92; // cs_jimmyboston
	case 3986688045: return 93; // ig_jimmyboston
	case 3100414644: return 94; // cs_jimmydisanto
	case 1459905209: return 95; // ig_jimmydisanto
	case 943915367:  return 96; // mp_m_marston_01
	case 4203395201: return 97; // cs_johnnyklebitz
	case 2278195374: return 98; // ig_johnnyklebitz
	case 4036845097: return 99; // cs_joeminuteman
		// 100
	case 3189787803: return 100; // ig_joeminuteman
	case 1167549130: return 101; // cs_josef
	case 3776618420: return 102; // ig_josef
	case 1158606749: return 103; // cs_josh
	case 2040438510: return 104; // ig_josh
	case 2109968527: return 105; // u_m_y_justin
	case 1269774364: return 106; // cs_karen_daniels
	case 3948009817: return 107; // ig_karen_daniels
	case 1530648845: return 108; // ig_kerrymcintosh
	case 1162230285: return 109; // cs_lamardavis
	case 1706635382: return 110; // ig_lamardavis
	case 949295643:  return 111; // cs_lazlow
	case 3756278757: return 112; // ig_lazlow
	case 3046438339: return 113; // cs_lestercrest
	case 1302784073: return 114; // ig_lestercrest
	case 1477887514: return 115; // cs_magenta
	case 4242313482: return 116; // ig_magenta
	case 4222842058: return 117; // cs_manuel
	case 4248931856: return 118; // ig_manuel
	case 479578891:  return 119; // u_m_m_markfost
		// 120
	case 1464721716: return 120; // cs_marnie
	case 411185872:  return 121; // ig_marnie
	case 1129928304: return 122; // cs_martinmadrazo
	case 161007533:  return 123; // cs_maryann
	case 2741999622: return 124; // ig_maryann
	case 3166991819: return 125; // csb_maude
	case 1005070462: return 126; // ig_maude
	case 1890499016: return 127; // cs_michelle
	case 3214308084: return 128; // ig_michelle
	case 3077190415: return 129; // cs_milton
	case 3408943538: return 130; // ig_milton
	case 1095737979: return 131; // u_f_m_miranda
	case 3509125021: return 132; // mp_f_misty_01
	case 1167167044: return 133; // cs_molly
	case 2936266209: return 134; // ig_molly
	case 3422397391: return 135; // cs_mrsphillips
	case 946007720:  return 136; // ig_mrsphillips
	case 1334976110: return 137; // cs_mrs_thornhill
	case 503621995:  return 138; // ig_mrs_thornhill
	case 1325314544: return 139; // cs_natalia
		// 140
	case 3726105915: return 140; // ig_natalia
	case 2023152276: return 141; // cs_nervousron
	case 3170921201: return 142; // ig_nervousron
	case 3779566603: return 143; // cs_nigel
	case 3367442045: return 144; // ig_nigel
	case 4007317449: return 145; // mp_m_niko_01
	case 2339419141: return 146; // cs_omega
	case 1625728984: return 147; // ig_omega
	case 768005095:  return 148; // ig_oneil
	case 3235579087: return 149; // csb_ortega
	case 648372919:  return 150; // ig_ortega
	case 4095687067: return 151; // csb_oscar
	case 1528799427: return 152; // csb_paige
	case 357551935:  return 153; // ig_paige
	case 3750433537: return 154; // cs_patricia
	case 3312325004: return 155; // ig_patricia
	case 1012965715: return 156; // cs_dreyfuss
	case 3666413874: return 157; // ig_dreyfuss
	case 3696858125: return 158; // u_m_y_pogo_01
	case 602513566:  return 159; // u_f_y_poppymich
		// 160
	case 411081129:  return 160; // csb_rashcosvki
	case 940330470:  return 161; // ig_rashcosvki
	case 2858686092: return 162; // csb_roccopelosi
	case 3585757951: return 163; // ig_roccopelosi
	case 3230888450: return 164; // cs_siemonyetarian
	case 1283141381: return 165; // ig_siemonyetarian
	case 4140949582: return 166; // cs_solomon
	case 2260598310: return 167; // ig_solomon
	case 2766184958: return 168; // cs_stevehains
	case 941695432:  return 169; // ig_stevehains
	case 2302502917: return 170; // cs_stretch
	case 915948376:  return 171; // ig_stretch
	case 3885222120: return 172; // ig_talina
	case 1123963760: return 173; // cs_tanisha
	case 226559113:  return 174; // ig_tanisha
	case 2288257085: return 175; // cs_taocheng
	case 3697041061: return 176; // ig_taocheng
	case 1397974313: return 177; // cs_taostranslator
	case 2089096292: return 178; // ig_taostranslator
	case 978452933:  return 179; // cs_terry
		// 180
	case 1728056212: return 180; // ig_terry
	case 1776856003: return 181; // cs_tom
	case 1665391897: return 182; // csb_tonya
	case 3402126148: return 183; // ig_tonya
	case 101298480:  return 184; // cs_tracydisanto
	case 3728026165: return 185; // ig_tracydisanto
	case 1382414087: return 186; // ig_tylerdix
	case 3529955798: return 187; // cs_wade
	case 2459507570: return 188; // ig_wade
	case 819699067:  return 189; // cs_chengsr
	case 2867128955: return 190; // ig_chengsr
	case 3937184496: return 191; // cs_zimbor
	case 188012277:  return 192; // ig_zimbor
	case 3614493108: return 193; // csb_agent
	case 610988552:  return 194; // ig_agent
	case 1841036427: return 195; // csb_mp_agent14
	case 4227433577: return 196; // ig_mp_agent14
	case 3513928062: return 197; // a_m_m_afriamer_01
	case 1567728751: return 198; // s_f_y_airhostess_01
	case 1644266841: return 199; // s_m_y_airworker
		// 200
	case 1684083350: return 200; // s_m_m_movalien_01
	case 1413662315: return 201; // a_m_m_acult_01
	case 1430544400: return 202; // a_m_o_acult_01
	case 1268862154: return 203; // a_m_o_acult_02
	case 3043264555: return 204; // a_m_y_acult_01
	case 2162532142: return 205; // a_m_y_acult_02
	case 2651349821: return 206; // s_m_y_ammucity_01
	case 233415434:  return 207; // s_m_m_ammucountry
	case 4058522530: return 208; // g_m_m_armboss_01
	case 4255728232: return 209; // g_m_m_armgoon_01
	case 3310258058: return 210; // g_m_y_armgoon_02
	case 3882958867: return 211; // g_m_m_armlieut_01
	case 3455013896: return 212; // mp_s_m_armoured_01
	case 2512875213: return 213; // s_m_m_armoured_01
	case 1669696074: return 214; // s_m_m_armoured_02
	case 1657546978: return 215; // s_m_y_armymech_01
	case 2988916046: return 216; // s_m_y_autopsy_01
	case 68070371:   return 217; // s_m_m_autoshop_01
	case 4033578141: return 218; // s_m_m_autoshop_02
	case 4096714883: return 219; // g_m_y_ballaeast_01
		// 220
	case 361513884:  return 220; // g_f_y_ballas_01
	case 2884567044: return 221; // csb_ballasog
	case 2802535058: return 222; // ig_ballasog
	case 588969535:  return 223; // g_m_y_ballaorig_01
	case 599294057:  return 224; // g_m_y_ballasout_01
	case 2539657518: return 225; // cs_bankman
	case 2426248831: return 226; // ig_bankman
	case 3272005365: return 227; // u_m_m_bankman
	case 373000027:  return 228; // s_f_m_fembarber
	case 3852538118: return 229; // s_m_y_barman_01
	case 2014052797: return 230; // s_f_y_bartender_01
	case 436345731:  return 231; // s_m_m_cntrybar_01
	case 1250841910: return 232; // s_f_y_baywatch_01
	case 189425762:  return 233; // s_m_y_baywatch_01
	case 808859815:  return 234; // a_f_m_beach_01
	case 1077785853: return 235; // a_m_m_beach_01
	case 2021631368: return 236; // a_m_m_beach_02
	case 1264920838: return 237; // a_m_y_musclbeac_01
	case 3374523516: return 238; // a_m_y_musclbeac_02
	case 2217202584: return 239; // a_m_o_beach_01
		// 240
	case 2359345766: return 240; // a_f_m_trampbeac_01
	case 1404403376: return 241; // a_m_m_trampbeac_01
	case 3349113128: return 242; // a_f_y_beach_01
	case 3523131524: return 243; // a_m_y_beach_01
	case 600300561:  return 244; // a_m_y_beach_02
	case 3886638041: return 245; // a_m_y_beach_03
	case 1464257942: return 246; // ig_bestmen
	case 3188223741: return 247; // a_f_m_bevhills_01
	case 2688103263: return 248; // a_f_m_bevhills_02
	case 1423699487: return 249; // a_m_m_bevhills_01
	case 1068876755: return 250; // a_m_m_bevhills_02
	case 1146800212: return 251; // a_f_y_bevhills_01
	case 1546450936: return 252; // a_f_y_bevhills_02
	case 549978415:  return 253; // a_f_y_bevhills_03
	case 920595805:  return 254; // a_f_y_bevhills_04
	case 1982350912: return 255; // a_m_y_bevhills_01
	case 1720428295: return 256; // a_m_y_bevhills_02
	case 2905870170: return 257; // cs_orleans
	case 1641334641: return 258; // ig_orleans
	case 1984382277: return 259; // u_m_m_bikehire_01
		// 260
	case 4198014287: return 260; // u_f_y_bikerchic
	case 3019107892: return 261; // s_m_y_blackops_01
	case 2047212121: return 262; // s_m_y_blackops_02
	case 1349953339: return 263; // s_m_y_blackops_03
	case 3482496489: return 264; // a_m_y_stbla_01
	case 2563194959: return 265; // a_m_y_stbla_02
	case 1004114196: return 266; // a_f_m_bodybuild_01
	case 2681481517: return 267; // s_m_m_bouncer_01
	case 933205398:  return 268; // a_m_y_breakdance_01
	case 2193587873: return 269; // csb_bride
	case 1633872967: return 270; // ig_bride
	case 2363277399: return 271; // csb_burgerdrug
	case 2340239206: return 272; // u_m_y_burgerdrug_01
	case 3640249671: return 273; // s_m_y_busboy_01
	case 2597531625: return 274; // a_m_y_busicas_01
	case 532905404:  return 275; // a_f_m_business_02
	case 2120901815: return 276; // a_m_m_business_01
	case 664399832:  return 277; // a_f_y_business_01
	case 826475330:  return 278; // a_f_y_business_02
	case 2928082356: return 279; // a_f_y_business_03
		// 280
	case 3083210802: return 280; // a_f_y_business_04
	case 3382649284: return 281; // a_m_y_business_01
	case 3014915558: return 282; // a_m_y_business_02
	case 2705543429: return 283; // a_m_y_business_03
	case 2912874939: return 284; // s_m_o_busker_01
	case 71501447:   return 285; // csb_car3guy1
	case 2230970679: return 286; // ig_car3guy1
	case 327394568:  return 287; // csb_car3guy2
	case 1975732938: return 288; // ig_car3guy2
	case 2362341647: return 289; // cs_carbuyer
	case 788443093:  return 290; // s_m_m_chemsec_01
	case 4128603535: return 291; // g_m_m_chemwork_01
	case 3118269184: return 292; // g_m_m_chiboss_01
	case 2119136831: return 293; // g_m_m_chigoon_01
	case 2831296918: return 294; // csb_chin_goon
	case 4285659174: return 295; // g_m_m_chigoon_02
	case 275618457:  return 296; // g_m_m_chicold_01
	case 71929310:   return 297; // s_m_y_clown_01
	case 3621428889: return 298; // s_m_y_construct_01
	case 3321821918: return 299; // s_m_y_construct_02
		// 300
	case 2595446627: return 300; // csb_cop
	case 368603149:  return 301; // s_f_y_cop_01
	case 1581098148: return 302; // s_m_y_cop_01
	case 773063444:  return 303; // u_f_m_corpse_01
	case 2624589981: return 304; // u_f_y_corpse_01
	case 228356856:  return 305; // u_f_y_corpse_02
	case 3387290987: return 306; // s_m_m_ccrew_01
	case 3253960934: return 307; // cs_chrisformage
	case 678319271:  return 308; // ig_chrisformage
	case 2756669323: return 309; // csb_customer
	case 4257633223: return 310; // a_m_y_cyclist_01
	case 755956971:  return 311; // u_m_y_cyclist_01
	case 1943971979: return 312; // mp_f_deadhooker
	case 3835149295: return 313; // s_m_y_dealer_01
	case 1646160893: return 314; // u_m_m_doa_01
	case 349680864:  return 315; // s_m_m_dockwork_01
	case 2255894993: return 316; // s_m_y_dockwork_01
	case 3564307372: return 317; // s_m_m_doctor_01
	case 579932932:  return 318; // s_m_y_doorman_01
	case 4282288299: return 319; // a_m_y_dhill_01
		// 320
	case 1699403886: return 320; // a_f_m_downtown_01
	case 766375082:  return 321; // a_m_y_downtown_01
	case 3680420864: return 322; // a_f_y_scdressy_01
	case 1976765073: return 323; // s_m_y_dwservice_01
	case 4119890438: return 324; // s_m_y_dwservice_02
	case 2638072698: return 325; // a_f_m_eastsa_01
	case 1674107025: return 326; // a_f_m_eastsa_02
	case 4188468543: return 327; // a_m_m_eastsa_01
	case 131961260:  return 328; // a_m_m_eastsa_02
	case 4121954205: return 329; // a_f_y_eastsa_01
	case 70821038:   return 330; // a_f_y_eastsa_02
	case 1371553700: return 331; // a_f_y_eastsa_03
	case 2756120947: return 332; // a_m_y_eastsa_01
	case 377976310:  return 333; // a_m_y_eastsa_02
	case 1755064960: return 334; // a_f_y_epsilon_01
	case 2010389054: return 335; // a_m_y_epsilon_01
	case 2860711835: return 336; // a_m_y_epsilon_02
	case 1161072059: return 337; // mp_m_exarmy_01
	case 1191548746: return 338; // u_m_y_militarybum
	case 1777626099: return 339; // s_f_y_factory_01
		// 340
	case 1097048408: return 340; // s_m_y_factory_01
	case 3896218551: return 341; // g_m_y_famca_01
	case 866411749:  return 342; // mp_m_famdd_01
	case 3681718840: return 343; // g_m_y_famdnf_01
	case 1309468115: return 344; // g_f_y_families_01
	case 2217749257: return 345; // g_m_y_famfor_01
	case 3263172030: return 346; // csb_ramp_gang
	case 3845001836: return 347; // ig_ramp_gang
	case 2488675799: return 348; // a_m_m_farmer_01
	case 4206136267: return 349; // a_f_m_fatbla_01
	case 3050275044: return 350; // a_f_m_fatcult_01
	case 1641152947: return 351; // a_m_m_fatlatin_01
	case 951767867:  return 352; // a_f_m_fatwhite_01
	case 1348537411: return 353; // a_f_y_femaleagent
	case 874722259:  return 354; // u_m_m_fibarchitect
	case 2243544680: return 355; // u_m_y_fibmugger_01
	case 3988550982: return 356; // s_m_m_fiboffice_01
	case 653289389:  return 357; // s_m_m_fiboffice_02
	case 1558115333: return 358; // mp_m_fibsec_01
	case 2072724299: return 359; // s_m_m_fibsec_01
		// 360
	case 1482427218: return 360; // cs_fbisuit_01
	case 988062523:  return 361; // ig_fbisuit_01
	case 1189322339: return 362; // u_m_o_finguru_01
	case 3065114024: return 363; // s_m_y_fireman_01
	case 1165780219: return 364; // a_f_y_fitness_01
	case 331645324:  return 365; // a_f_y_fitness_02
	case 466359675:  return 366; // csb_fos_rep
	case 2841034142: return 367; // s_m_m_gaffer_01
	case 4000686095: return 368; // s_m_y_garbage
	case 1240094341: return 369; // s_m_m_gardener_01
	case 3519864886: return 370; // a_m_y_gay_01
	case 2775713665: return 371; // a_m_y_gay_02
	case 115168927:  return 372; // a_m_m_genfat_01
	case 330231874:  return 373; // a_m_m_genfat_02
	case 793439294:  return 374; // a_f_y_genhot_01
	case 1640504453: return 375; // a_f_o_genstreet_01
	case 2908022696: return 376; // a_m_o_genstreet_01
	case 2557996913: return 377; // a_m_y_genstreet_01
	case 891398354:  return 378; // a_m_y_genstreet_02
	case 1169888870: return 379; // u_m_m_glenstank_01
		// 380
	case 2850754114: return 380; // a_m_m_golfer_01
	case 2111372120: return 381; // a_f_y_golfer_01
	case 3609190705: return 382; // a_m_y_golfer_01
	case 3293887675: return 383; // u_m_m_griff_01
	case 815693290:  return 384; // s_m_y_grip_01
	case 2058033618: return 385; // csb_groom
	case 4274948997: return 386; // ig_groom
	case 3898166818: return 387; // csb_grove_str_dlr
	case 3333724719: return 388; // u_m_y_guido_01
	case 3005388626: return 389; // u_m_y_gunvend_01
	case 3272931111: return 390; // cs_gurk
	case 1099825042: return 391; // s_m_m_hairdress_01
	case 1809430156: return 392; // a_m_m_hasjew_01
	case 3782053633: return 393; // a_m_y_hasjew_01
	case 2240582840: return 394; // csb_ramp_hic
	case 1165307954: return 395; // ig_ramp_hic
	case 4049719826: return 396; // s_m_m_highsec_01
	case 691061163:  return 397; // s_m_m_highsec_02
	case 1939545845: return 398; // s_m_y_hwaycop_01
	case 813893651:  return 399; // a_f_y_hiker_01
		// 400
	case 1358380044: return 400; // a_m_y_hiker_01
	case 1822107721: return 401; // a_m_m_hillbilly_01
	case 2064532783: return 402; // a_m_m_hillbilly_02
	case 343259175:  return 403; // a_f_y_hippie_01
	case 4030826507: return 404; // u_m_y_hippie_01
	case 2097407511: return 405; // a_m_y_hippy_01
	case 569740212:  return 406; // csb_ramp_hipster
	case 3740245870: return 407; // ig_ramp_hipster
	case 2185745201: return 408; // a_f_y_hipster_01
	case 2549481101: return 409; // a_f_y_hipster_02
	case 2780469782: return 410; // a_f_y_hipster_03
	case 429425116:  return 411; // a_f_y_hipster_04
	case 587703123:  return 412; // a_m_y_hipster_01
	case 349505262:  return 413; // a_m_y_hipster_02
	case 1312913862: return 414; // a_m_y_hipster_03
	case 42647445:   return 415; // s_f_y_hooker_01
	case 348382215:  return 416; // s_f_y_hooker_02
	case 51789996:   return 417; // s_f_y_hooker_03
	case 2874755766: return 418; // s_f_y_scrubs_01
	case 2526768638: return 419; // u_f_y_hotposh_01
		// 420
	case 1531218220: return 420; // cs_hunter
	case 3457361118: return 421; // ig_hunter
	case 1650288984: return 422; // s_m_m_ciasec_01
	case 880829941:  return 423; // u_m_y_imporage
	case 3721046572: return 424; // a_m_m_indian_01
	case 3134700416: return 425; // a_f_o_indian_01
	case 153984193:  return 426; // a_f_y_indian_01
	case 706935758:  return 427; // a_m_y_indian_01
	case 3254803008: return 428; // csb_janitor
	case 2842417644: return 429; // s_m_m_janitor
	case 2585681490: return 430; // u_m_o_taphillbilly
	case 3459037009: return 431; // u_m_m_jesus_01
	case 767028979:  return 432; // a_m_y_jetski_01
	case 994527967:  return 433; // hc_driver
	case 193469166:  return 434; // hc_gunman
	case 2579169528: return 435; // hc_hacker
	case 3872144604: return 436; // u_m_m_jewelthief
	case 4040474158: return 437; // u_f_y_jewelass_01
	case 1145088004: return 438; // cs_jewelass
	case 257763003:  return 439; // ig_jewelass
		// 440
	case 2899099062: return 440; // u_m_m_jewelsec_01
	case 3343476521: return 441; // a_f_y_runner_01
	case 623927022:  return 442; // a_m_y_runner_01
	case 2218630415: return 443; // a_m_y_runner_02
	case 3675473203: return 444; // a_f_y_juggalo_01
	case 2445950508: return 445; // a_m_y_juggalo_01
	case 1380197501: return 446; // u_m_y_baygor
	case 891945583:  return 447; // g_m_m_korboss_01
	case 1388848350: return 448; // a_f_m_ktown_01
	case 1090617681: return 449; // a_f_m_ktown_02
	case 2093736314: return 450; // g_m_y_korlieut_01
	case 3512565361: return 451; // a_m_m_ktown_01
	case 1204772502: return 452; // a_f_o_ktown_01
	case 355916122:  return 453; // a_m_o_ktown_01
	case 611648169:  return 454; // g_m_y_korean_01
	case 452351020:  return 455; // a_m_y_ktown_01
	case 2414729609: return 456; // g_m_y_korean_02
	case 696250687:  return 457; // a_m_y_ktown_02
	case 2659242702: return 458; // s_m_m_lathandy_01
	case 3265820418: return 459; // a_m_m_stlat_02
		// 460
	case 2255803900: return 460; // a_m_y_stlat_01
	case 321657486:  return 461; // a_m_y_latino_01
	case 1918178165: return 462; // cs_lifeinvad_01
	case 1401530684: return 463; // ig_lifeinvad_01
	case 666718676:  return 464; // ig_lifeinvad_02
	case 3724572669: return 465; // s_m_m_lifeinvad_01
	case 3684436375: return 466; // s_m_m_linecook
	case 2423691919: return 467; // u_m_m_willyfist
	case 1985653476: return 468; // s_m_m_lsmetro_01
	case 3767780806: return 469; // s_f_m_maid_01
	case 803106487:  return 470; // a_m_m_malibu_01
	case 3367706194: return 471; // u_m_y_mani
	case 2124742566: return 472; // s_m_m_mariachi_01
	case 1634506681: return 473; // csb_ramp_marine
	case 4074414829: return 474; // s_m_m_marine_01
	case 4028996995: return 475; // s_m_m_marine_02
	case 1702441027: return 476; // s_m_y_marine_01
	case 1490458366: return 477; // s_m_y_marine_02
	case 1925237458: return 478; // s_m_y_marine_03
	case 1142162924: return 479; // s_m_y_xmech_01
		// 480
	case 3189832196: return 480; // s_m_y_xmech_02
	case 1631478380: return 481; // csb_mweather
	case 1768677545: return 482; // a_m_y_methhead_01
	case 4132362192: return 483; // csb_ramp_mex
	case 3870061732: return 484; // ig_ramp_mex
	case 1466037421: return 485; // g_m_m_mexboss_01
	case 1226102803: return 486; // g_m_m_mexboss_02
	case 3185399110: return 487; // g_m_y_mexgang_01
	case 653210662:  return 488; // g_m_y_mexgoon_01
	case 832784782:  return 489; // g_m_y_mexgoon_02
	case 2521633500: return 490; // g_m_y_mexgoon_03
	case 2992445106: return 491; // a_m_m_mexlabor_01
	case 3716251309: return 492; // a_m_m_mexcntry_01
	case 810804565:  return 493; // a_m_y_mexthug_01
	case 3579522037: return 494; // s_f_y_migrant_01
	case 3977045190: return 495; // s_m_m_migrant_01
	case 1021093698: return 496; // s_m_y_mime
	case 1573528872: return 497; // u_f_y_mistress
	case 2560490906: return 498; // csb_money
	case 939183526:  return 499; // ig_money
		// 500
	case 1694362237: return 500; // a_m_y_motox_01
	case 2007797722: return 501; // a_m_y_motox_02
	case 3887273010: return 502; // s_m_m_movspace_01
	case 728636342:  return 503; // u_m_m_filmdirector
	case 587253782:  return 504; // s_f_y_movprem_01
	case 1270514905: return 505; // cs_movpremf_01
	case 3630066984: return 506; // s_m_m_movprem_01
	case 2372398717: return 507; // cs_movpremmale
	case 894928436:  return 508; // u_f_o_moviestar
	case 1746653202: return 509; // a_m_m_og_boss_01
	case 518814684:  return 510; // cs_old_man1a
	case 1906124788: return 511; // ig_old_man1a
	case 2566514544: return 512; // cs_old_man2
	case 4011150407: return 513; // ig_old_man2
	case 3972697109: return 514; // a_m_m_paparazzi_01
	case 1346941736: return 515; // u_m_y_paparazzi
	case 3008586398: return 516; // s_m_m_paramedic_01
	case 2180468199: return 517; // u_m_m_partytarget
	case 921110016:  return 518; // u_m_y_party_01
	case 1209091352: return 519; // s_m_y_pestcont_01
		// 520
	case 3881519900: return 520; // s_m_m_pilot_01
	case 2872052743: return 521; // s_m_y_pilot_01
	case 4131252449: return 522; // s_m_m_pilot_02
	case 2849617566: return 523; // a_m_m_polynesian_01
	case 1329576454: return 524; // g_m_y_pologoon_01
	case 2733138262: return 525; // g_m_y_pologoon_02
	case 2206530719: return 526; // a_m_y_polynesian_01
	case 793443893:  return 527; // csb_porndudes
	case 1650036788: return 528; // s_m_m_postal_01
	case 1936142927: return 529; // s_m_m_postal_02
	case 1299047806: return 530; // cs_priest
	case 1681385341: return 531; // ig_priest
	case 3538133636: return 532; // u_f_y_princess
	case 1456041926: return 533; // s_m_m_prisguard_01
	case 2981862233: return 534; // s_m_y_prisoner_01
	case 2073775040: return 535; // u_m_y_prisoner_01
	case 1596003233: return 536; // s_m_y_prismuscl_01
	case 2237544099: return 537; // u_m_y_proldriver_01
	case 4027271643: return 538; // csb_prologuedriver
	case 379310561:  return 539; // a_f_m_prolhost_01
		// 540
	case 2534589327: return 540; // a_m_m_prolhost_01
	case 3306347811: return 541; // u_f_o_prolhost_01
	case 2718472679: return 542; // u_f_m_promourn_01
	case 3465937675: return 543; // u_m_m_promourn_01
	case 2141384740: return 544; // csb_prolsec
	case 1888624839: return 545; // u_m_m_prolsec_01
	case 512955554:  return 546; // cs_prolsec_02
	case 666086773:  return 547; // ig_prolsec_02
	case 1822283721: return 548; // mp_g_m_pros_01
	case 2680682039: return 549; // s_f_y_ranger_01
	case 4017173934: return 550; // s_m_y_ranger_01
	case 776079908:  return 551; // csb_reporter
	case 1011059922: return 552; // u_m_y_rsranger_01
	case 1624626906: return 553; // u_m_m_rivalpap
	case 4116817094: return 554; // a_m_y_roadcyc_01
	case 3227390873: return 555; // s_m_y_robber_01
	case 1064866854: return 556; // a_f_y_rurmeth_01
	case 1001210244: return 557; // a_m_m_rurmeth_01
	case 1179785778: return 558; // cs_russiandrunk
	case 1024089777: return 559; // ig_russiandrunk
		// 560
	case 2923947184: return 560; // s_f_m_shop_high
	case 2842568196: return 561; // s_f_y_shop_low
	case 1846684678: return 562; // s_m_y_shop_mask
	case 1055701597: return 563; // s_f_y_shop_mid
	case 3725461865: return 564; // a_f_m_salton_01
	case 1328415626: return 565; // a_m_m_salton_01
	case 1626646295: return 566; // a_m_m_salton_02
	case 2995538501: return 567; // a_m_m_salton_03
	case 2521108919: return 568; // a_m_m_salton_04
	case 3439295882: return 569; // a_f_o_salton_01
	case 539004493:  return 570; // a_m_o_salton_01
	case 3613420592: return 571; // a_m_y_salton_01
	case 2422005962: return 572; // g_m_y_salvaboss_01
	case 663522487:  return 573; // g_m_y_salvagoon_01
	case 846439045:  return 574; // g_m_y_salvagoon_02
	case 62440720:   return 575; // g_m_y_salvagoon_03
	case 1092080539: return 576; // s_m_m_scientist_01
	case 2346790124: return 577; // csb_screen_writer
	case 4293277303: return 578; // ig_screen_writer
	case 3613962792: return 579; // s_m_m_security_01
		// 580
	case 1096929346: return 580; // s_f_y_sheriff_01
	case 2974087609: return 581; // s_m_y_sheriff_01
	case 416176080:  return 582; // mp_m_shopkeep_01
	case 1767892582: return 583; // a_f_y_skater_01
	case 3654768780: return 584; // a_m_m_skater_01
	case 3250873975: return 585; // a_m_y_skater_01
	case 2952446692: return 586; // a_m_y_skater_02
	case 2962707003: return 587; // a_f_m_skidrow_01
	case 32417469:   return 588; // a_m_m_skidrow_01
	case 451459928:  return 589; // s_m_m_snowcop_01
	case 1951946145: return 590; // a_f_m_soucent_01
	case 4079145784: return 591; // a_f_m_soucent_02
	case 193817059:  return 592; // a_m_m_socenlat_01
	case 1750583735: return 593; // a_m_m_soucent_01
	case 2674735073: return 594; // a_m_m_soucent_02
	case 2346291386: return 595; // a_m_m_soucent_03
	case 3271294718: return 596; // a_m_m_soucent_04
	case 3454621138: return 597; // a_f_m_soucentmc_01
	case 1039800368: return 598; // a_f_o_soucent_01
	case 2775443222: return 599; // a_f_o_soucent_02
		// 600
	case 718836251:  return 600; // a_m_o_soucent_01
	case 1082572151: return 601; // a_m_o_soucent_02
	case 238213328:  return 602; // a_m_o_soucent_03
	case 744758650:  return 603; // a_f_y_soucent_01
	case 1519319503: return 604; // a_f_y_soucent_02
	case 2276611093: return 605; // a_f_y_soucent_03
	case 3877027275: return 606; // a_m_y_soucent_01
	case 2896414922: return 607; // a_m_y_soucent_02
	case 3287349092: return 608; // a_m_y_soucent_03
	case 2318861297: return 609; // a_m_y_soucent_04
	case 1794381917: return 610; // u_m_y_sbike
	case 2886641112: return 611; // u_m_m_spyactor
	case 1535236204: return 612; // u_f_y_spyactress
	case 2442448387: return 613; // u_m_y_staggrm_01
	case 2035992488: return 614; // s_m_m_strperf_01
	case 469792763:  return 615; // s_m_m_strpreach_01
	case 4246489531: return 616; // g_m_y_strpunk_01
	case 228715206:  return 617; // g_m_y_strpunk_02
	case 3465614249: return 618; // s_m_m_strvend_01
	case 2457805603: return 619; // s_m_y_strvend_01
		// 620
	case 2934601397: return 620; // csb_stripper_01
	case 1381498905: return 621; // s_f_y_stripper_01
	case 2168724337: return 622; // csb_stripper_02
	case 1846523796: return 623; // s_f_y_stripper_02
	case 1544875514: return 624; // s_f_y_stripperlite
	case 695248020:  return 625; // mp_f_stripperlite
	case 3072929548: return 626; // a_m_y_sunbathe_01
	case 3938633710: return 627; // a_m_y_surfer_01
	case 2374966032: return 628; // s_m_y_swat_01
	case 824925120:  return 629; // s_f_m_sweatshop_01
	case 2231547570: return 630; // s_f_y_sweatshop_01
	case 2494442380: return 631; // u_m_y_tattoo_01
	case 1545995274: return 632; // cs_tenniscoach
	case 2721800023: return 633; // ig_tenniscoach
	case 1426880966: return 634; // a_f_y_tennis_01
	case 1416254276: return 635; // a_m_m_tennis_01
	case 4250220510: return 636; // g_f_y_lost_01
	case 1330042375: return 637; // g_m_y_lost_01
	case 1032073858: return 638; // g_m_y_lost_02
	case 850468060:  return 639; // g_m_y_lost_03
		// 640
	case 3727243251: return 640; // csb_trafficwarden
	case 1461287021: return 641; // ig_trafficwarden
	case 2633130371: return 642; // a_f_y_topless_01
	case 1347814329: return 643; // a_f_m_tourist_01
	case 3365863812: return 644; // a_m_m_tourist_01
	case 1446741360: return 645; // a_f_y_tourist_01
	case 2435054400: return 646; // a_f_y_tourist_02
	case 1224306523: return 647; // a_f_m_tramp_01
	case 516505552:  return 648; // a_m_m_tramp_01
	case 1787764635: return 649; // u_m_o_tramp_01
	case 390939205:  return 650; // a_m_o_tramp_01
	case 411102470:  return 651; // s_m_m_gentransport
	case 3773208948: return 652; // a_m_m_tranvest_01
	case 4144940484: return 653; // a_m_m_tranvest_02
	case 1498487404: return 654; // s_m_m_trucker_01
	case 4017642090: return 655; // csb_undercover
	case 1798879480: return 656; // cs_paper
	case 2577072326: return 657; // ig_paper
	case 2680389410: return 658; // s_m_m_ups_01
	case 3502104854: return 659; // s_m_m_ups_02
		// 660
	case 3389018345: return 660; // s_m_y_uscg_01
	case 1520708641: return 661; // g_f_y_vagos_01
	case 999748158:  return 662; // s_m_y_valet_01
	case 2114544056: return 663; // a_m_y_beachvesp_01
	case 3394697810: return 664; // a_m_y_beachvesp_02
	case 3247667175: return 665; // a_m_y_vindouche_01
	case 435429221:  return 666; // a_f_y_vinewood_01
	case 3669401835: return 667; // a_f_y_vinewood_02
	case 933092024:  return 668; // a_f_y_vinewood_03
	case 4209271110: return 669; // a_f_y_vinewood_04
	case 1264851357: return 670; // a_m_y_vinewood_01
	case 1561705728: return 671; // a_m_y_vinewood_02
	case 534725268:  return 672; // a_m_y_vinewood_03
	case 835315305:  return 673; // a_m_y_vinewood_04
	case 2907468364: return 674; // s_m_y_waiter_01
	case 605602864:  return 675; // a_m_y_stwhi_01
	case 919005580:  return 676; // a_m_y_stwhi_02
	case 1426951581: return 677; // s_m_y_winclean_01
	case 3290105390: return 678; // a_f_y_yoga_01
	case 2869588309: return 679; // a_m_y_yoga_01
		// 680
	case 2890614022: return 680; // u_m_y_zombie_01
		// 700
	case 3462393972: return 700; // a_c_boar
	case 2825402133: return 701; // a_c_chimp
	case 4244282910: return 702; // a_c_cow
	case 1682622302: return 703; // a_c_coyote
	case 3630914197: return 704; // a_c_deer
	case 802685111:  return 705; // a_c_fish
	case 1794449327: return 706; // a_c_hen
	case 1462895032: return 707; // a_c_cat_01
	case 2864127842: return 708; // a_c_chickenhawk
	case 1457690978: return 709; // a_c_cormorant
	case 402729631:  return 710; // a_c_crow
	case 2344268885: return 711; // a_c_dolphin
	case 1193010354: return 712; // a_c_humpback
	case 2374682809: return 713; // a_c_killerwhale
	case 111281960:  return 714; // a_c_pigeon
	case 3549666813: return 715; // a_c_seagull
	case 1015224100: return 716; // a_c_sharkhammer
	case 2971380566: return 717; // a_c_pig
	case 3283429734: return 728; // a_c_rat
	case 3268439891: return 719; // a_c_rhesus
	// 720
	case 351016938:  return 720; // a_c_chop
	case 1318032802: return 721; // a_c_husky
	case 307287994:  return 722; // a_c_mtlion
	case 882848737:  return 723; // a_c_retriever
	case 113504370:  return 724; // a_c_sharktiger
	case 1126154828: return 725; // a_c_shepherd

	default: return -1;
	}
}
