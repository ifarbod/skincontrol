/*
Skin Control menu.cpp
By Neutrinobeam
*/

#pragma once
#include "menu.h"
#include "skin.h"
#include "dataFile.h"
#include "weapons.h"
#include "pedModel.h"
#include "tattoo.h"
#include "facedata.h"
#include "keyboard.h"

#pragma warning(disable : 4244 4305)

int SC_menu = 0; // Current menu id

LPCSTR optionMenuNames[] = { "", "Pick Skin", "Save", "Load" };// "Change Character", "Delete Character", "Pose NPC"
LPCSTR partPrimaryNames[] = { "Face", "Base Face", "Face Shape", "Hair", "Face Detail", "Clothing", "Tattoos", "Weapon", "" };

LPCSTR headBlendNames[] = { "Mother", "Father", "Face M:F", "Skin M:F" };
LPCSTR momNames[] = { "Hannah", "Aubrey", "Jasmine", "Gisele", "Amelia", "Isabella", "Zoe", "Ava", "Camila", "Violet", "Sophia", "Evelyn", "Nicole", "Ashley", "Gracie", "Brianna", "Natalie", "Olivia", "Elizabeth", "Charlotte", "Emma", /*DLC*/ " Misty" };
LPCSTR dadNames[] = { "Benjamin", "Daniel", "Joshua", "Noah", "Andrew", "Juan", "Alex", "Isaac", "Evan", "Ethan", "Vincent", "Angel", "Diego", "Adrian", "Gabriel", "Michael", "Santiago", "Kevin", "Louis", "Samuel", "Anthony", /*DLC*/ " Claude", "Niko", "John" };

LPCSTR headMorphs[] = { "Nose Width", "Nose Height", "Nose Depth", "Nose Ridge", "Nose Tip Height", "Nose Broken", "Brow Height", "Brow Depth", "Chkbone Height", "Chkbone Out", "Cheek Gaunt",
"Eye size", "Lip Size", "Jaw Width", "Jaw Rounded", "Chin Height", "Chin Out", "Chin Pointy", "Chin Indent", "?"};

LPCSTR fmOverlays[] = { "Hair", "Eyebrow", "Eyecolor", "Beard", "Chest Hair", "Mole/Freckle", "Ageing", "Complexion", "Blemishes", "Body Blem.", "Add Body Blem.", "Sun Damage", "Makeup", "Blush", "Lipstick" };
// maleDisplay   "Hair", "Eyebrow", "Eyecolor", "Beard", "ChestHair", "Mole", "Ageing", "Complexion", "Blemishes", "Body Blem.", "Add Body Blem.", "SunDam", "Eyeliner",          "Lipstick" };
// femaleDisplay "Hair", "Eyebrow", "Eyecolor",                       "Mole", "Ageing", "Complexion", "Blemishes", "Body Blem.", "Add Body Blem.", "SunDam", "Eyeliner", "Blush", "Lipstick" };
// internal     /"Hair", "Eyecolor",/"Eyebrow", "Beard", "ChestHair", "Mole", "Ageing", "Complexion", "Blemishes", "Body Blem.", "Dense Body Blem.", "SunDam", "Makeup", "Blush", "Lipstick"};
// game								 "Blemishes", "Beard", "Eyebrow", "Ageing", "Makeup", "Blush", "Complexion", "SunDam", "Lipstick", "Mole", "ChestHair", "Body Blemishes", "Dense Body Blemishes",

LPCSTR fHairNames[] = { "Close Shave", "Short", "Layered Bob", "Pigtails", "Ponytail", "Braided Mohawk", "Braids", "Bob", "Faux Hawk", "French Twist", "Long Bob", "Loose Tied", "Pixie", "Shaved Bangs", "Top Knot", "Wavy Bob", "Pin Up Girl", "Messy Bun", "Unknown", "Tight Bun", "Twisted Bob", "Big Bangs", "Braided Top Knot", "Mullet", "Nightvision"};
LPCSTR mHairNames[] = { "Close Shave", "Buzzcut", "Faux Hawk", "Hipster", "Side Parting", "Shorter Cut", "Biker", "Ponytail", "Cornrows", "Slicked", "Short Brushed", "Spikey", "Caesar", "Chopped", "Dreads", "Long Hair", "Shaggy Curls", "Surfer Dude", "Short Side Part", "High Slicked Sides", "Long Slicked", "Hipster Youth", "Mullet", "Nightvision" };
LPCSTR eyeColorNames[] = { "Green", "Emerald", "Light Blue", "Ocean Blue", "Light Brown", "Dark Brown", "Hazel", "Dark Gray", "Light Gray", "Pink", "Yellow", "Purple", "Blackout", "Shades of Gray", "Tequila Sunrise", "Atomic", "Warp", "ECola", "Space Ranger", "Ying Yang", "Bullseye", "Lizard", "Dragon", "Extra Terrestrial", "Goat", "Smiley", "Possessed", "Demon", "Infected", "Alien", "Undead", "Zombie"};
std::vector< std::vector<LPCSTR>> overlayNames = {
	// eyebrow
	{ "None", "Balanced", "Fashion", "Cleopatra", "Quizzical", "Femme", "Seductive", "Pinched", "Chola", "Triomphe", "Carefree", "Curvaceous", "Rodent", "Double Tram", "Thin", "Penciled", "Mother Plucker", "Straight and Narrow", "Natural", "Fuzzy", "Unkempt", "Caterpillar", "Regular", "Mediterranean", "Groomed", "Bushels", "Feathered", "Prickly", "Monobrow", "Winged", "Triple Tram", "Arched Tram", "Cutouts", "Fade Away", "Solo Tram" },
	// beard
	{ "Clean Shaven", "Light Stubble", "Balbo", "Circle Beard", "Goatee", "Chin", "Chin Fuzz", "Pencil Chin Strap", "Scruffy", "Musketeer", "Mustache", "Trimmed Beard", "Stubble", "Thin Circle Beard", "Horseshoe", "Pencil and Chops", "Chin Strap Beard", "Balbo and Sideburns", "Mutton Chops", "Scruffy Beard", "Curly", "Curly and Deep Stranger", "Handlebar", "Faustic", "Otto and Patch", "Otto and Full Stranger", "Light Franz", "The Hampstead", "The Ambrose", "Lincoln Curtain" },
	// chestHair
	{ "Shaved", "Natural", "The Strip", "The Tree", "Hairy", "Grisly", "Ape", "Groomed Ape", "Bikini", "Lightning Bolt", "Reverse Lightning", "Love Heart", "Chestache", "Happy Face", "Skull", "Snail Trail", "Slug and Nips", "Hairy Arms" },
	// mole & freckle
	{ "None", "Cherub", "All Over", "Irregular", "Dot Dash", "Over the Bridge", "Baby Doll", "Pixie", "Sun Kissed", "Beauty Marks", "Line Up", "Modelesque", "Occasional", "Speckled", "Rain Drops", "Double Dip", "One Sided", "Pairs", "Growth" },
	// aging
	{ "None", "Crow's Feet", "First Signs", "Middle Aged", "Worry Lines", "Depression", "Distinguished", "Aged", "Weathered", "Wrinkled", "Sagging", "Tough Life", "Vintage", "Retired", "Junkie", "Geriatric" },
	// complexion
	{ "None", "Rosy Cheeks", "Stubble Rash", "Hot Flush", "Sunburn", "Bruised", "Alchoholic", "Patchy", "Totem", "Blood Vessels", "Damaged", "Pale", "Ghostly" },
	// blemishes
	{ "None", "Measles", "Pimples", "Spots", "Break Out", "Blackheads", "Build Up", "Pustules", "Zits", "Full Acne", "Acne", "Cheek Rash", "Face Rash", "Picker", "Puberty", "Eyesore", "Chin Rash", "Two Face", "T Zone", "Greasy", "Marked", "Acne Scarring", "Full Acne Scarring", "Cold Sores", "Impetigo" },
	// body blemishes -1 - 11
	{ "None", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" },
	// dense body blemishes -1 - 1
	{ "None", "1", "2" },
	// sum damage
	{ "None", "Uneven", "Sandpaper", "Patchy", "Rough", "Leathery", "Textured", "Coarse", "Rugged", "Creased", "Cracked", "Gritty" },
	// makeup
	{ "None", "Smoky Black", "Bronze", "Soft Gray", "Retro Glam", "Natural Look", "Cat Eyes", "Chola", "Vamp", "Vinewood Glamour", "Bubblegum", "Aqua Dream", "Pin up", "Purple Passion", "Smoky Cat Eye", "Smoldering Ruby", "Pop Princess",
	// face paint
	"Kiss My Axe", "Panda Pussy", "The Bat", "Skull in Scarlet", "Serpentine", "The Veldt", "Unknown 1", "Unknown 2", "Unknown 3", "Unknown 4", "Tribal Lines", "Tribal Swirls", "Tribal Orange", "Tribal Red", "Trapped in A Box", "Clowning"
	// makeup pt 2
	"Guyliner", "Unknown 5","Blood Tears", "Heavy Metal", "Sorrow", "Prince of Darkness", "Rocker", "Goth", "Punk", "Devastated"
	},
	// blush
	{ "None", "Full", "Angled", "Round", "Horizontal", "High", "Sweetheart", "Eighties" },
	// lipstick
	{ "None", "Color Matte", "Color Gloss", "Lined Matte", "Lined Gloss", "Heavy Lined Matte", "Heavy Lined Gloss", "Lined Nude Matte", "Liner Nude Gloss", "Smudged", "Geisha" }
};

LPCSTR fmPartNames[] = { "Face", "Hair", "Hats", "Mask", "Glasses", "Ear",  "Top", "Upper Skin", "Decals", "Under Coat", "Watch", "Pants", "Shoes", "Accessories",  "Armor",  "Parachute"};
LPCSTR spPartNames[] = { "Face & Skin", "Hair", "Mask/Hats", "Glasses", "Ear", "Facial Hair", "Upper Body", "Neck", "Decals", "Watch", "Hands", "Lower Body", "Shoes", "Accessories", "Equipment", "Other"};
LPCSTR partNames[] = { "Face & Skin", "Hair", "Mask/Hats", "Face/Glasses", "Ear", "Facial Hair", "Upper Body", "Neck", "Decals", "Watch", "Hands", "Lower Body", "Accessories", "Equipment", "Other", "Other"};

//std::string menuWeaponOptions[] = { "Name", "Infinite Ammo" };

void setMainMenu(){
	SC_menu = 0;
}

void processSkinControlMenu(int & convertFile, Hash & lastValidSkin, bool & nondefaultSkin, PedSkin & skin, std::vector<Entity> & weapon, std::vector<std::pair<Hash, int>> & ammoWeapon, int hotkey)
{
	int menuX[numMenus] = { 0, 0, 0, 0, 0};
	int menuY[numMenus] = { 0, 0, 0, 0, 0};

	bool inUI = false;

	WeaponData equippedWeaponData;

	int playerType = -1;
	int fileVal = 0;
	DWORD maxTickCount;
	int xLines = 0;
	int yLines = 0;
	float xPos = 0.0f;
	float yPos = 0.0f;

	std::vector<std::string> saveNames(numSaves, "");
	std::string title = "Skin Control ";
	title.append(VERSION);
	std::string pedName;

	resetGlobals(convertFile);
	GRAPHICS::GET_SCREEN_RESOLUTION(&xLines, &yLines);
	peekNames(&saveNames);
	MM::isolateControlsExcludeCamera();
	MM::Input current;

	initializeMenuSkin(skin, equippedWeaponData, playerType);
	pedName = getModelName(playerType);
	inUI = true;
	while (inUI)
	{
		maxTickCount = GetTickCount() + 200;
		do
		{
			// Title
			MM::drawRectWithText(title, titleWidth, titlePad, titleDown, titleLeft, titleTextAlign, false, 0xFFFFFFFF, 0.6, 1, 0x000000FF);
			// First Menu
			xPos = 0.5 * xLines - menuXMax[optionMenuID] * 0.5 * (nameWidth + nameXSpace) + 0.5 * nameXSpace;
			yPos = nameBelowTitle;
			drawOptionMenu(menuX[optionMenuID], xPos, yPos, pedName);
			// Second Menu
			if (SC_menu == fileMenuID){
				yPos = (yLines - menuYMax[fileMenuID] * (nameHeight + nameYSpace)) / 2;
				xPos = (xLines - menuXMax[fileMenuID] * (nameWidth + nameXSpace) + nameXSpace) / 2;
				drawFileMenu(menuX[SC_menu] * menuYMax[SC_menu] + menuY[SC_menu], xPos, yPos, &saveNames);
			}
			// Third
			if (SC_menu == skinMenuID){
				xPos = 0.5 * xLines - menuXMax[optionMenuID] * 0.5 * (nameWidth + nameXSpace) + 0.5 * nameXSpace + nameWidth + nameXSpace;
				yPos = nameBelowTitle + nameHeight + nameYSpace;
				drawSkinMenu(menuX[SC_menu], menuY[SC_menu], xPos, yPos);
			}
			// Fourth Menu
			if (SC_menu == partMenuID || SC_menu == varMenuID){
				xPos = 0.5 * xLines - 0.5 * (2 * subMenuWidth + nameXSpace);
				yPos = nameBelowTitle + partMenuOffset * (nameHeight + nameYSpace);
				drawPartMenu(SC_menu, menuX, menuY, xPos, yPos, playerType, skin, equippedWeaponData);
			}
			current = MM::getInput();
			if (IsKeyJustUp(hotkey))
				current = MM::BACK;
			WAIT(0);
		} while (current == MM::Input::NONE || GetTickCount() < maxTickCount);
		switch (SC_menu)
		{
		case optionMenuID:
			processOptionMenu(current, inUI, menuX, menuY);
			break;
		case fileMenuID:
			fileVal = processFileMenu(current, skin, menuX, menuY, equippedWeaponData, lastValidSkin, nondefaultSkin, weapon, ammoWeapon);
			if (fileVal == 1)
				peekNames(&saveNames);
			else if (fileVal == 2){
				playerType = hashLookup(skin.model);
				pedName = getModelName(playerType);
			}
			break;
		case skinMenuID:
			processSkinMenu(current, skin, menuX, menuY, equippedWeaponData, lastValidSkin, nondefaultSkin, weapon, ammoWeapon);
			if (current == MM::SELECT){
				playerType = hashLookup(skin.model);
				pedName = getModelName(playerType);
			}
			break;
		case partMenuID:
			processPartMenu(current, skin, menuX, menuY, playerType);
			break;
		case varMenuID:
			processVariationMenu(current, skin, menuX, menuY, playerType, equippedWeaponData);
		break;
		default:
			break;
		}
	}
	MM::resetControls();
}

void processOptionMenu(MM::Input current, bool & inUI, int(&menuX)[numMenus], int(&menuY)[numMenus])
{
	switch (current)
	{
	case MM::Input::LEFT:
	case MM::Input::RIGHT:
		moveHorizontal(optionMenuID, current, menuX, menuY, menuXMax[optionMenuID]);
		break;
	case MM::Input::UP:
	case MM::Input::DOWN:
		break;
	case MM::Input::BACK:
		inUI = false;
		break;
	case MM::Input::SELECT:
		switch (menuX[optionMenuID])
		{
		case 1:
			SC_menu = skinMenuID;
			break;
		case 2:
		case 3:
			SC_menu = fileMenuID;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

int getSkinYMax(DWORD index) // result is 1 indexed, see pedModel.cpp or hashLookup(Hash)
{
	if (index < 20)
		return 5;
	if (index >= 680 && index < 700)
		return 1;
	if (index >= 720 && index < 740)
		return 6;
	return menuYMax[skinMenuID];
}

void processSkinMenu(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus], WeaponData & currentWeaponData, Hash & lastValidSkin, bool & nondefaultSkin, std::vector<Entity> & weapon, std::vector<std::pair<Hash, int>> & ammoWeapon){
	switch (current)
	{
	case MM::Input::LEFT:
	case MM::Input::RIGHT:
		moveHorizontal(skinMenuID, current, menuX, menuY, menuXMax[skinMenuID]);
		break;
	case MM::Input::UP:
	case MM::Input::DOWN:
		moveVertical(skinMenuID, current, menuX, menuY, getSkinYMax(menuX[skinMenuID] * menuYMax[skinMenuID] + menuY[skinMenuID]));
		break;
	case MM::Input::SELECT:
		setSkinFromIndex(skin, menuX[skinMenuID] * menuYMax[skinMenuID] + menuY[skinMenuID], currentWeaponData, lastValidSkin, nondefaultSkin, weapon, ammoWeapon);
		SC_menu = partMenuID;
		menuX[partMenuID] = menuY[partMenuID] = 0;
		break;
	case MM::Input::BACK:
		SC_menu = optionMenuID;
		break;
	default:
		break;
	}
}

int getPartMenuMax(int type){
	bool mpModel = isFreemode(type);
	if (!mpModel && isPlayer(type))
		return 5;
	else if (mpModel)
		return 6;
	else if (isAnimal(type))
		return 3;
	else
		return 4;
}

void processPartMenu(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus], int type)
{
	switch (current)
	{
	case MM::Input::LEFT:
		break;
	case MM::Input::UP:
	case MM::Input::DOWN:
		moveVertical(partMenuID, current, menuX, menuY, getPartMenuMax(type));
		break;
	case MM::Input::BACK:
		SC_menu = skinMenuID;
		break;
	case MM::Input::RIGHT:
	case MM::Input::SELECT:
		SC_menu = varMenuID;
		menuX[varMenuID] = menuY[varMenuID] = 0;
		break;
	default:
		break;
	}
}

int processFileMenu(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus], WeaponData & currentWeaponData, Hash & lastValidSkin, bool & nonDefaultSkin, std::vector<Entity> & weapon, std::vector<std::pair<Hash, int>> & ammoWeapon)
{
	switch (current)
	{
	case MM::Input::LEFT:
	case MM::Input::RIGHT:
		moveHorizontal(fileMenuID, current, menuX, menuY, menuXMax[fileMenuID]);
		break;
	case MM::Input::UP:
	case MM::Input::DOWN:
		moveVertical(fileMenuID, current, menuX, menuY, menuYMax[fileMenuID]);
		break;
	case MM::Input::BACK:
		SC_menu = optionMenuID;
		break;
	case MM::Input::SELECT:
		if (menuX[optionMenuID] == 2)
		{
			SC_menu = optionMenuID;
			if (saveSkin(menuX[fileMenuID] * menuYMax[fileMenuID] + menuY[fileMenuID], skin))
				return 1;
			MM::notifyAboveMap("Save failed.");
		}
		else if (menuX[optionMenuID] == 3){
			loadSkin(menuX[fileMenuID] * menuYMax[fileMenuID] + menuY[fileMenuID], skin, currentWeaponData, lastValidSkin, nonDefaultSkin, weapon, ammoWeapon);
			return 2;
		}
		break;
	default:
		break;
	}
	return 0;
}

void processVariationMenu(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus], int type, WeaponData & currentWeaponData)
{
	bool mpModel = isFreemode(type);
	bool spModel = !mpModel && isPlayer(type);
	if (menuY[partMenuID] == 0 && mpModel) // face blend
		processFaceBlendMenu(current, skin, menuX, menuY);
	else if (menuY[partMenuID] == 0) // drawable head
		processDrawableMenu(current, skin, menuX, menuY, 0);
	else if (menuY[partMenuID] == 1 && mpModel) // head morph
		processMorphMenu(current, skin, menuX, menuY);
	else if (menuY[partMenuID] == 1) // drawable hair
		processDrawableMenu(current, skin, menuX, menuY, 2);
	else if (menuY[partMenuID] == 2 && mpModel) // head overlay
		processOverlayMenu(current, skin, menuX, menuY, type);
	else if (menuY[partMenuID] == 2) // clothing
		processClothingMenu(current, skin, menuX, menuY, type);
	else if (menuY[partMenuID] == 3 && mpModel) //clothing
		processClothingMenu(current, skin, menuX, menuY, type);
	else if (menuY[partMenuID] == 3 && spModel) // tattoos
		processTatMenu(current, skin, menuX, menuY, type);
	else if (menuY[partMenuID] == 3) // weapon
		processWeaponMenu(current, skin, menuX, menuY, type, currentWeaponData);
	else if (menuY[partMenuID] == 4 && mpModel) // tattos
		processTatMenu(current, skin, menuX, menuY, type);
	else if (menuY[partMenuID] == 4 && spModel) // weapon
		processWeaponMenu(current, skin, menuX, menuY, type, currentWeaponData);
	else if (menuY[partMenuID] == 5 && mpModel) // weapon
		processWeaponMenu(current, skin, menuX, menuY, type, currentWeaponData);
}


void changeHeadBlend(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus]){
	if (current == MM::UP){
		switch (menuY[varMenuID]){
		case 0:
			++(skin.freemodeData.mother);
			if (skin.freemodeData.mother >= PED::_GET_NUM_PARENT_PEDS_OF_TYPE(1) + PED::_GET_NUM_PARENT_PEDS_OF_TYPE(3)){
				skin.freemodeData.mother = 0;
			}
			break;
		case 1:
			++(skin.freemodeData.father);
			if (skin.freemodeData.father >= PED::_GET_NUM_PARENT_PEDS_OF_TYPE(0) + PED::_GET_NUM_PARENT_PEDS_OF_TYPE(2)){
				skin.freemodeData.father = 0;
			}
			break;
		case 2:
			if (skin.freemodeData.faceRatio < 16){
				++(skin.freemodeData.faceRatio);
			}
			break;
		case 3:
			if (skin.freemodeData.skinRatio < 16){
				++(skin.freemodeData.skinRatio);
			}
			break;
		}
	}
	else if (current == MM::DOWN){
		switch (menuY[varMenuID]){
		case 0:
			if (skin.freemodeData.mother <= 0){
				skin.freemodeData.mother = PED::_GET_NUM_PARENT_PEDS_OF_TYPE(1) + PED::_GET_NUM_PARENT_PEDS_OF_TYPE(3);
			}
			--(skin.freemodeData.mother);
			break;
		case 1:
			if (skin.freemodeData.father <= 0){
				skin.freemodeData.father = PED::_GET_NUM_PARENT_PEDS_OF_TYPE(0) + PED::_GET_NUM_PARENT_PEDS_OF_TYPE(2);
			}
			--(skin.freemodeData.father);
			break;
		case 2:
			if (skin.freemodeData.faceRatio > 0){
				--(skin.freemodeData.faceRatio);
			}
			break;
		case 3:
			if (skin.freemodeData.skinRatio > 0){
				--(skin.freemodeData.skinRatio);
			}
			break;
		}
	}
	switch (menuY[varMenuID]){
	case 0: case 1:
		setPedHeadBlend(skin, PLAYER::PLAYER_PED_ID());
		break;
	case 2: case 3:
		PED::UPDATE_PED_HEAD_BLEND_DATA(PLAYER::PLAYER_PED_ID(), (float)(skin.freemodeData.faceRatio) / 16.0f, (float)(skin.freemodeData.skinRatio) / 16.0f, 0.0f);
		break;
	}
}

void changeHeadMorph(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus]){
	if (current == MM::UP){
		if (skin.freemodeData.morph[menuY[varMenuID]] < 10)
			++(skin.freemodeData.morph[menuY[varMenuID]]);
	}
	else if (current == MM::DOWN){
		if (skin.freemodeData.morph[menuY[varMenuID]] > -10)
			--(skin.freemodeData.morph[menuY[varMenuID]]);
	}
	setPedHeadMorph(skin, PLAYER::PLAYER_PED_ID(), menuY[varMenuID]);
}

int displayToInternal(int dID, int type){
	if (type != 4 && type != 3) return -1;
	switch (dID){
	case 0: return -2;
	case 1: return 0;
	case 2: return -1;
	case 13: return (type == 4 ? dID - 1 : -1);
	default: return (type == 4 ? dID - 2 : dID);
	}
}

void changeOverlay(MM::Input current, PedSkin & skin, int posX, int posY, int type){
	Ped id = PLAYER::PLAYER_PED_ID();
	switch (posY){
	case oHairID:
		switch (posX){
		case 1:
			if (current == MM::UP){
				++(skin.freemodeData.hair);
				if (skin.freemodeData.hair >= PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 2)){
					skin.freemodeData.hair = 0;
				}
			}
			else if (current == MM::DOWN){
				if (skin.freemodeData.hair <= 0){
					skin.freemodeData.hair = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 2);
				}
				--(skin.freemodeData.hair);
			}
			skin.drawable[2] = skin.freemodeData.hair;
			break;
		case 2:
			if (current == MM::UP){
				++(skin.freemodeData.hairColor);
				if (skin.freemodeData.hairColor >= PED::_GET_NUM_HAIR_COLORS()){
					skin.freemodeData.hairColor = 0;
				}
			}
			else if (current == MM::DOWN){
				if (skin.freemodeData.hairColor <= 0){
					skin.freemodeData.hairColor = PED::_GET_NUM_HAIR_COLORS();
				}
				--(skin.freemodeData.hairColor);
			}
			skin.texture[2] = skin.freemodeData.hairColor;
			break;
		case 3:
			if (current == MM::UP){
				++(skin.freemodeData.hairHighlights);
				if (skin.freemodeData.hairHighlights >= PED::_GET_NUM_HAIR_COLORS()){
					skin.freemodeData.hairHighlights = 0;
				}
			}
			else if (current == MM::DOWN){
				if (skin.freemodeData.hairHighlights <= 0){
					skin.freemodeData.hairHighlights = PED::_GET_NUM_HAIR_COLORS();
				}
				--(skin.freemodeData.hairHighlights);
			}
			break;
		}
		break;
	case oEyeID:
		if (current == MM::UP){
			++(skin.freemodeData.eyeColor);
			if (skin.freemodeData.eyeColor >= 32){ // from XB1
				skin.freemodeData.eyeColor = 0;
			}
		}
		else if (current == MM::DOWN){
			if (skin.freemodeData.eyeColor <= 0){
				skin.freemodeData.eyeColor = 32; // from XB1
			}
			--(skin.freemodeData.eyeColor);
		}
		break;
	case oEyebrowID: case oBeardID: case oChestID: case oLipstickID: case oBlushID:
		switch (posX){
			case 1:
			if (current == MM::UP){
				++(skin.freemodeData.overlay[posY].value);
				if (skin.freemodeData.overlay[posY].value >= PED::_GET_NUM_HEAD_OVERLAY_VALUES(internalToGame(posY))){ // fix ?
					skin.freemodeData.overlay[posY].value = -1;
				}
			}
			else if (current == MM::DOWN){
				if (skin.freemodeData.overlay[posY].value <= -1){
					skin.freemodeData.overlay[posY].value = PED::_GET_NUM_HEAD_OVERLAY_VALUES(internalToGame(posY)); // fix ?
				}
				--(skin.freemodeData.overlay[posY].value);
			}
			break;
		case 2:
			if (current == MM::UP){
				++(skin.freemodeData.overlay[posY].color);
				if (skin.freemodeData.overlay[posY].color >= (posY == oLipstickID ? 38 : (posY == oBlushID) ? 33 : 48)){ // from XB1
					skin.freemodeData.overlay[posY].color = 0;
				}
			}
			else if (current == MM::DOWN){
				if (skin.freemodeData.overlay[posY].color <= 0){
					skin.freemodeData.overlay[posY].color = (posY == oLipstickID ? 38 : (posY == oBlushID) ? 33 : 48); // from XB1
				}
				--(skin.freemodeData.overlay[posY].color);
			}
			break;
		case 3:
			if (current == MM::UP){
				++(skin.freemodeData.overlay[posY].opacity);
				if (skin.freemodeData.overlay[posY].opacity > 20){
					skin.freemodeData.overlay[posY].opacity = 0;
				}
			}
			else if (current == MM::DOWN){
				if (skin.freemodeData.overlay[posY].opacity <= 0){
					skin.freemodeData.overlay[posY].opacity = 21;
				}
				--(skin.freemodeData.overlay[posY].opacity);
			}
			break;
		}
		break;
	default:
		switch (posX){
		case 1:
			if (current == MM::UP){
				++(skin.freemodeData.overlay[posY].value);
				if (skin.freemodeData.overlay[posY].value >= PED::_GET_NUM_HEAD_OVERLAY_VALUES(internalToGame(posY))){
					skin.freemodeData.overlay[posY].value = -1;
				}
			}
			else if (current == MM::DOWN){
				if (skin.freemodeData.overlay[posY].value <= -1){
					skin.freemodeData.overlay[posY].value = PED::_GET_NUM_HEAD_OVERLAY_VALUES(internalToGame(posY));
				}
				--(skin.freemodeData.overlay[posY].value);
			}
			break;
		case 2:
			if (current == MM::UP){
				++(skin.freemodeData.overlay[posY].opacity);
				if (skin.freemodeData.overlay[posY].opacity > 20){
					skin.freemodeData.overlay[posY].opacity = 0;
				}
			}
			else if (current == MM::DOWN){
				if (skin.freemodeData.overlay[posY].opacity <= 0){
					skin.freemodeData.overlay[posY].opacity = 21;
				}
				--(skin.freemodeData.overlay[posY].opacity);
			}
			break;
		}
	break;
	}
	setPedFreemodeOverlay(skin, PLAYER::PLAYER_PED_ID(), posY, type);
}

void changeTatVariation(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus], int type){
	if (current == MM::UP){
		++(skin.tattoo[menuY[varMenuID]].value);
		if (skin.tattoo[menuY[varMenuID]].value >= getNumAvailableTat(getTatZone(menuY[varMenuID]), type, 0))
			skin.tattoo[menuY[varMenuID]].value = -1;
	}
	else if (current == MM::DOWN){
		if (skin.tattoo[menuY[varMenuID]].value < 0)
			skin.tattoo[menuY[varMenuID]].value = getNumAvailableTat(getTatZone(menuY[varMenuID]), type, 0);
		--(skin.tattoo[menuY[varMenuID]].value);
	}
	skin.tattoo[menuY[varMenuID]].collection = getTatCollection(type, getTatZone(menuY[varMenuID]), skin.tattoo[menuY[varMenuID]].value);
}

void changeMenuSkinDrawable(MM::Input current, PedSkin & skin, int id){
	int texMax;
	if (current == MM::Input::UP)
	{
		skin.drawable[id]++;
		if (id < firstProp && skin.drawable[id] >= getDrawableMax(id)){
			skin.drawable[id] = 0;
		}
		else if (id >= firstProp){
			if (skin.drawable[id] == 0){
				skin.texture[id] = 0;
			}
			if (skin.drawable[id] >= getDrawableMax(id)){
				skin.drawable[id] = -1;
				skin.texture[id] = -1;
			}
		}
	}
	else if (current == MM::Input::DOWN)
	{
		if (id < firstProp && skin.drawable[id] <= 0){
			skin.drawable[id] = getDrawableMax(id);
		}
		else if (id >= firstProp && skin.drawable[id] < 0){
			skin.drawable[id] = getDrawableMax(id);
			skin.texture[id] = 0;
		}
		skin.drawable[id]--;
		if (id >= firstProp && skin.drawable[id] < 0){
			skin.texture[id] = -1;
		}
	}
	texMax = getTextureMax(id, skin.drawable[id]);
	if (texMax > 0 && skin.texture[id] >= texMax)
		skin.texture[id] = texMax - 1;
	setSkinComponentOfID(skin, PLAYER::PLAYER_PED_ID(), id);
}

void changeMenuSkinTexture(MM::Input current, PedSkin & skin, int id)
{
	if (current == MM::Input::UP)
	{
		skin.texture[id]++;
		if (skin.texture[id] >= getTextureMax(id, skin.drawable[id])){
			skin.texture[id] = 0;
		}
	}
	else if (current == MM::Input::DOWN)
	{
		if (skin.texture[id] <= 0)
			skin.texture[id] = getTextureMax(id, skin.drawable[id]);
		skin.texture[id]--;
	}
	setSkinComponentOfID(skin, PLAYER::PLAYER_PED_ID(), id);
}

void changeMenuWeapon(MM::Input current, PedSkin & skin, WeaponData & currentWeaponData){
	int i = hashLookup(skin.weapon);
	if (currentWeaponData.added && i > 0){
		WEAPON::REMOVE_WEAPON_FROM_PED(PLAYER::PLAYER_PED_ID(), skin.weapon);
	}
	if (current == MM::Input::UP)
	{
		i++;
		if (i == getNumWeapons())
			i = 0;
	}
	else if (current == MM::Input::DOWN)
	{
		if (i == 0)
			i = getNumWeapons();
		i--;
	}
	skin.weapon = getWeaponHash(i);
	// get new weapon data
	currentWeaponData = getWeaponComponentData(skin.weapon);
	skin.weaponTint = getPedWeaponVariant(PLAYER::PLAYER_PED_ID(), skin.weapon, currentWeaponData);
	// get default mods
	skin.weaponModMask = currentWeaponData.defaultMask;
	// update mods
	updateWeaponModMaskFromPed(PLAYER::PLAYER_PED_ID(), skin.weapon, skin, currentWeaponData);
	setWeaponOfPed(skin, PLAYER::PLAYER_PED_ID(), currentWeaponData);

}

void changeMenuWeaponTint(MM::Input current, PedSkin & skin, WeaponData & currentWeaponData){
	if (current == MM::Input::UP)
	{
		skin.weaponTint++;
		if (skin.weaponTint >= getWeaponTintMax(skin.weapon))
			skin.weaponTint = 0;
	}
	else if (current == MM::Input::DOWN)
	{
		if (skin.weaponTint <= 0)
			skin.weaponTint = getWeaponTintMax(skin.weapon);
		skin.weaponTint--;
	}
	setWeaponVariant(skin, PLAYER::PLAYER_PED_ID(), currentWeaponData);
}

void changeMenuWeaponEquipped(WeaponData & currentWeaponData){
	currentWeaponData.added = !currentWeaponData.added;
}

void changeMenuWeaponMod(MM::Input current, PedSkin & skin, int posY, WeaponData & currentWeaponData){
	bool set = getWeaponModSetting(skin, currentWeaponData, posY);
	updateWeaponModMask(skin, currentWeaponData, posY, !set);
	updateWeaponMod(skin, PLAYER::PLAYER_PED_ID(), currentWeaponData, posY);
}

void changeWeaponVariation(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus], WeaponData & currentWeaponData){
	switch (menuY[varMenuID]){
	case 0: changeMenuWeapon(current, skin, currentWeaponData); break;
	case 1: changeMenuWeaponEquipped(currentWeaponData); break;
	case 2: changeMenuWeaponTint(current, skin, currentWeaponData); break;
	default: changeMenuWeaponMod(current, skin, menuY[varMenuID] - 3, currentWeaponData); break;
	}
}


void processFaceBlendMenu(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus]){
	switch (current)
	{
	case MM::Input::LEFT:
		if (menuX[varMenuID] == 0)
			SC_menu = partMenuID;
		else
			moveHorizontal(varMenuID, current, menuX, menuY, 2);
		break;
	case MM::Input::RIGHT:
		moveHorizontal(varMenuID, current, menuX, menuY, 2);
		break;
	case MM::Input::UP:
	case MM::Input::DOWN:
		if (menuX[varMenuID] == 0)
			moveVertical(varMenuID, current, menuX, menuY, 4);
		else{
			changeHeadBlend(current, skin, menuX, menuY);
		}
		break;
	case MM::Input::BACK:
		if (menuX[varMenuID] == 0 || menuY[varMenuID] <= 0)
			SC_menu = partMenuID;
		else{
			--menuY[varMenuID];
			menuX[varMenuID] = 1;
		}
		break;
	case MM::Input::SELECT: // advance
		if (menuY[varMenuID] >= 4 - 1){
			++menuY[partMenuID];
			menuX[varMenuID] = 1;
			menuY[varMenuID] = 0;
		}
		else{
			++menuY[varMenuID];
			menuX[varMenuID] = 1;
		}
		break;
	default:
		break;
	}
}

void processMorphMenu(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus]){
	switch (current)
	{
	case MM::Input::LEFT:
		if (menuX[varMenuID] == 0)
			SC_menu = partMenuID;
		else
			moveHorizontal(varMenuID, current, menuX, menuY, 2);
		break;
	case MM::Input::RIGHT:
		moveHorizontal(varMenuID, current, menuX, menuY, 2);
		break;
	case MM::Input::UP:
	case MM::Input::DOWN:
		if (menuX[varMenuID] == 0)
			moveVertical(varMenuID, current, menuX, menuY, numMorphs);
		else{
			changeHeadMorph(current, skin, menuX, menuY);
		}
		break;
	case MM::Input::BACK:
		if (menuX[varMenuID] == 0)
			SC_menu = partMenuID;
		else if (menuY[varMenuID] <= 0){
			--menuY[partMenuID];
			menuX[varMenuID] = 1;
			menuY[varMenuID] = 4 - 1;
		}
		else{
			--menuY[varMenuID];
			menuX[varMenuID] = 1;
		}
		break;
	case MM::Input::SELECT: // advance
		if (menuY[varMenuID] >= numMorphs - 1){
			++menuY[partMenuID];
			menuX[varMenuID] = 1;
			menuY[varMenuID] = 0;
		}
		else{
			++menuY[varMenuID];
			menuX[varMenuID] = 1;
		}
		break;
	default:
		break;
	}
}

int getNumOverlays(int type){
	switch (type){
	case 3: return 13; break;
	case 4: return 14; break;
	default: return 0; break;
	}
}

int getOverlayNumOptions(int id){
	switch (id){
	case oHairID: case oEyebrowID: case oBeardID: case oBlushID: case oLipstickID:
		return 4; break;
	case oEyeID:
		return 2; break;
	default:
		return 3; break;
	}
}

void processOverlayMenu(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus], int type){
	switch (current)
	{
	case MM::Input::LEFT:
		if (menuX[varMenuID] == 0)
			SC_menu = partMenuID;
		else
			moveHorizontal(varMenuID, current, menuX, menuY, getOverlayNumOptions(displayToInternal(menuY[varMenuID], type)));
		break;
	case MM::Input::RIGHT:
		moveHorizontal(varMenuID, current, menuX, menuY, getOverlayNumOptions(displayToInternal(menuY[varMenuID], type)));
		break;
	case MM::Input::UP:
	case MM::Input::DOWN:
		if (menuX[varMenuID] == 0)
			moveVertical(varMenuID, current, menuX, menuY, getNumOverlays(type));
		else{
			changeOverlay(current, skin, menuX[varMenuID], displayToInternal(menuY[varMenuID], type), type);
		}
		break;
	case MM::Input::BACK:
		if (menuX[varMenuID] == 0)
			SC_menu = partMenuID;
		else if (menuY[varMenuID] <= 0){
			--menuY[partMenuID];
			menuX[varMenuID] = 1;
			menuY[varMenuID] = numMorphs - 1;
		}
		else{
			--menuY[varMenuID];
			menuX[varMenuID] = 1;
		}
		break;
	case MM::Input::SELECT: // advance
		if (menuY[varMenuID] >= getNumOverlays(type) - 1){
			++menuY[partMenuID];
			menuX[varMenuID] = 1;
			menuY[varMenuID] = 0;
		}
		else{
			++menuY[varMenuID];
			menuX[varMenuID] = 1;
		}
		break;
	default:
		break;
	}
}

void processDrawableMenu(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus], int slot){
	switch (current)
	{
	case MM::Input::LEFT:
		if (menuX[varMenuID] == 0)
			SC_menu = partMenuID;
		else
			moveHorizontal(varMenuID, current, menuX, menuY, 3);
		break;
	case MM::Input::RIGHT:
		moveHorizontal(varMenuID, current, menuX, menuY, 3);
		break;
	case MM::Input::UP:
	case MM::Input::DOWN:
		if (menuX[varMenuID] == 0){}
		else if (menuX[varMenuID] == 1){
			changeMenuSkinDrawable(current, skin, slot);
		}
		else if (menuX[varMenuID] == 2){
			changeMenuSkinTexture(current, skin, slot);
		}
		break;
	case MM::Input::BACK:
		if (menuX[varMenuID] == 0 || slot == 0)
			SC_menu = partMenuID;
		else if (slot == 2){
			--menuY[partMenuID];
			menuX[varMenuID] = 1;
			menuY[varMenuID] = 0; // hair to head
		}
		break;
	case MM::Input::SELECT: // advance
		++menuY[partMenuID];
		menuX[varMenuID] = 1;
		menuY[varMenuID] = 0;
		break;
	default:
		break;
	}
}

int displayToGameDrawable(int dID, bool mpModel, bool spModel){
	switch (dID){
	case 0: return 0;
	case 1: return 2;
	case 2: return 12;
	case 3: return (mpModel ? 1 : 13);
	case 4: return (mpModel ? 13 : 14);
	case 5: return (mpModel ? 14 : 1);
	case 6: return (mpModel ? 11 : 3);
	case 7: return (mpModel ? 3 : 11);
	case 8: return 10;
	case 9: return (mpModel ? 8 : 15);
	case 10: return (mpModel ? 15 : 5);
	case 11: return 4;
	case 12: return (mpModel || spModel ? 6 : 8);
	case 13: return (mpModel ? 7 : (spModel ? 8 : 9));
	case 14: return (mpModel || spModel ? 9 : 6);
	case 15: return (mpModel ? 5 : 7);
	default:
		return -1;
	}
}

void processClothingMenu(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus], int type){
	bool mpModel = isFreemode(type);
	bool spModel = !mpModel && isPlayer(type);
	switch (current)
	{
	case MM::Input::LEFT:
		if (menuX[varMenuID] == 0)
			SC_menu = partMenuID;
		else
			moveHorizontal(varMenuID, current, menuX, menuY, 3);
		break;
	case MM::Input::RIGHT:
		moveHorizontal(varMenuID, current, menuX, menuY, 3);
		break;
	case MM::Input::UP:
	case MM::Input::DOWN:
		if (menuX[varMenuID] == 0)
			moveVertical(varMenuID, current, menuX, menuY, numParts - 2);
		else if (menuX[varMenuID] == 1)
			changeMenuSkinDrawable(current, skin, displayToGameDrawable(menuY[varMenuID] + 2, mpModel, spModel));
		else if (menuX[varMenuID] == 2)
			changeMenuSkinTexture(current, skin, displayToGameDrawable(menuY[varMenuID] + 2, mpModel, spModel));
		break;
	case MM::Input::BACK:
		if (menuX[varMenuID] == 0){
			SC_menu = partMenuID;
		}
		else if (menuY[varMenuID] <= 0){
			--menuY[partMenuID];
			menuX[varMenuID] = 1;
			menuY[varMenuID] = (mpModel ? getNumOverlays(type) - 1 : 0);
		}
		else{
			--menuY[varMenuID];
			menuX[varMenuID] = 1;
		}
		break;
	case MM::Input::SELECT: // advance
		if (menuY[varMenuID] >= numParts - 3){
			++menuY[partMenuID];
			menuX[varMenuID] = 1;
			menuY[varMenuID] = 0;
		}
		else{
			++menuY[varMenuID];
			menuX[varMenuID] = 1;
		}
		break;
	default:
		break;
	}
}

void processTatMenu(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus], int type){
	switch (current)
	{
	case MM::Input::LEFT:
		if (menuX[varMenuID] == 0)
			SC_menu = partMenuID;
		else
			moveHorizontal(varMenuID, current, menuX, menuY, 2);
		break;
	case MM::Input::RIGHT:
		moveHorizontal(varMenuID, current, menuX, menuY, 2);
		break;
	case MM::Input::UP:
	case MM::Input::DOWN:
		if (menuX[varMenuID] == 0){
			moveVertical(varMenuID, current, menuX, menuY, numTatSlots - 1);
		}
		else{
			changeTatVariation(current, skin, menuX, menuY, type);
			updateTats(skin, type);
		}
		break;
	case MM::Input::BACK:
		if (menuX[varMenuID] == 0){
			SC_menu = partMenuID;
		}
		else if (menuY[varMenuID] <= 0){
			--menuY[partMenuID];
			menuX[varMenuID] = 1;
			menuY[varMenuID] = numParts - 3;
		}
		else{
			--menuY[varMenuID];
			menuX[varMenuID] = 1;
		}
		break;
	case MM::Input::SELECT: // advance
		if (menuY[varMenuID] >= numTatSlots - 2 ){
			++menuY[partMenuID];
			menuX[varMenuID] = 1;
			menuY[varMenuID] = 0;
		}
		else{
			++menuY[varMenuID];
			menuX[varMenuID] = 1;
		}
		break;
	default:
		break;
	}
}

void processWeaponMenu(MM::Input current, PedSkin & skin, int(&menuX)[numMenus], int(&menuY)[numMenus], int type, WeaponData & currentWeaponData){
	switch (current)
	{
	case MM::Input::LEFT:
		if (menuX[varMenuID] == 0)
			SC_menu = partMenuID;
		else
			moveHorizontal(varMenuID, current, menuX, menuY, 2);
		break;
	case MM::Input::RIGHT:
		moveHorizontal(varMenuID, current, menuX, menuY, 2);
		break;
	case MM::Input::UP:
	case MM::Input::DOWN:
		if (menuX[varMenuID] == 0)
			moveVertical(varMenuID, current, menuX, menuY, 3 + currentWeaponData.maxSlots);
		else
			changeWeaponVariation(current, skin, menuX, menuY, currentWeaponData);
		break;
	case MM::Input::BACK:
		if (menuX[varMenuID] == 0){
			SC_menu = partMenuID;
			if (currentWeaponData.added && skin.weapon != 0xA2719263){
				WEAPON::REMOVE_WEAPON_FROM_PED(PLAYER::PLAYER_PED_ID(), skin.weapon);
			}
		}
		else if (menuY[varMenuID] <= 0){
			--menuY[partMenuID];
			menuX[varMenuID] = 1;
			menuY[varMenuID] = (isSinglePlayer(type) ? numTatSlots - 2 : numParts - 3);
		}
		else{
			--menuY[varMenuID];
			menuX[varMenuID] = 1;
		}
		break;
	case MM::Input::SELECT: // advance
		if (menuY[varMenuID] >= currentWeaponData.maxSlots + 3 - 1){
			SC_menu = partMenuID;
			if (currentWeaponData.added && skin.weapon != 0xA2719263){
				WEAPON::REMOVE_WEAPON_FROM_PED(PLAYER::PLAYER_PED_ID(), skin.weapon);
			}
		}
		else{
			++menuY[varMenuID];
			menuX[varMenuID] = 1;
		}
		break;
	default:
		break;
	}
}


void moveHorizontal(int menu, MM::Input current, int (&menuX)[numMenus], int (&menuY)[numMenus], int max)
{
	if (current == MM::Input::LEFT)
	{
		if (menuX[menu] == 0)
			menuX[menu] = max;
		menuX[menu]--;
	}
	else if (current == MM::Input::RIGHT)
	{
		menuX[menu]++;
		if (menuX[menu] == max)
			menuX[menu] = 0;
	}
	// Move left or right into an empty spot,
	if (menu == skinMenuID && menuY[menu] >= getSkinYMax(menuX[menu] * menuYMax[menu] + menuY[menu]))
	{
		menuY[menu] = getSkinYMax(menuX[menu] * menuYMax[menu] + menuY[menu]) - 1;
	}
}

void moveVertical(int menu, MM::Input current, int (&menuX)[numMenus], int (&menuY)[numMenus], int max)
{
	if (current == MM::Input::UP)
	{
		if (menuY[menu] <= 0)
			menuY[menu] = max;
		--menuY[menu];
	}
	else if (current == MM::Input::DOWN)
	{
		++menuY[menu];
		if (menuY[menu] >= max)
			menuY[menu] = 0;
	}
}


void drawOptionMenu(int posX, float xPos, float yPos, std::string name){
	for (int i = 0; i < menuXMax[optionMenuID]; i++){
		std::string caption;
		if (i == 0){
			caption = name;
		}
		else{
			caption = optionMenuNames[i];
		}
		if (SC_menu == optionMenuID && i == posX)
			MM::drawRectWithText(caption, nameWidth, namePad, yPos, xPos + i * (nameWidth + nameXSpace), 0x000000FF, 0xF2DAF2FF);
		else
			MM::drawRectWithText(caption, nameWidth, namePad, yPos, xPos + i * (nameWidth + nameXSpace), 0xFFFFFFFF, 0x5F465FFF);
	}
}

void drawSkinMenu(int posX, int posY, float xPos, float yPos){
	std::string caption = "Page " + std::to_string(posX+1) + " of " + std::to_string(menuXMax[skinMenuID]);
	MM::draw_menu_line(caption, 100.0, titlePad, titleDown, titleLeft + titleWidth - 100.0, titleTextAlign, false, true);
	for (int i = 0; i < menuYMax[skinMenuID]; i++)
	{
		if (i == posY){
			caption = "< ";
			caption.append(getModelName(posX * menuYMax[skinMenuID] + i));
			caption.append(" >");
			MM::drawRectWithText(caption, nameWidth, namePad, yPos + i * (nameHeight + nameYSpace), xPos, nameTextAlign, false, 0x000000FF, 0.35, 0, 0xF2DAF2FF);
		}
		else{
			caption = getModelName(posX * menuYMax[skinMenuID] + i);
			if (caption.size() > 0){
				MM::drawRectWithText(caption, nameWidth, namePad, yPos + i *  (nameHeight + nameYSpace), xPos, nameTextAlign, false, 0xFFFFFFFF, 0.35, 0, 0x5F465FFF);
			}
		}
	}
}

int partPrimaryToSecondary(int i, int type){
	switch (type){
	// singleplayer
	case 0: case 1: case 2:
		switch (i){
		case 0: return 0; break;
		case 1: return 3; break;
		case 2: return 5; break;
		case 3: return 6; break;
		case 4: return 7; break;
		}
		break;
	// freemode
	case 3: case 4:
		switch (i){
		case 0: return 1; break;
		case 1: return 2; break;
		case 2: return 4; break;
		case 3: return 5; break;
		case 4: return 6; break;
		case 5: return 7; break;
		}
		break;
	// rest
	default:
		switch (i){
		case 0: return 0; break;
		case 1: return 3; break;
		case 2: return 5; break;
		case 3: return 7; break;
		}
		break;
	}
	return 8;
}

void drawPartMenu(int menu, int(&menuX)[numMenus], int(&menuY)[numMenus], float xPos, float yPos, int type, PedSkin & skin, WeaponData & currentWeaponData){
	for (int i = 0; i < getPartMenuMax(type); ++i){
		if (menu == partMenuID && i == menuY[partMenuID])
			MM::drawRectWithText(partPrimaryNames[partPrimaryToSecondary(i, type)], subMenuWidth, namePad, yPos + (i + 1) * (nameHeight + nameYSpace), xPos, nameTextAlign, false, 0x000000FF, 0.35, 0, 0xF2DAF2FF);
		else
			MM::drawRectWithText(partPrimaryNames[partPrimaryToSecondary(i, type)], subMenuWidth, namePad, yPos + (i + 1) * (nameHeight + nameYSpace), xPos, nameTextAlign, false, 0xFFFFFFFF, 0.35, 0, 0x5F465FFF);
	}
	drawVariationMenu(menu, menuX, menuY, xPos + subMenuWidth + nameXSpace, yPos + (1 + menuY[partMenuID]) * (nameHeight + nameYSpace), type, skin, currentWeaponData);
}

void drawVariationMenu(int menu, int(&menuX)[numMenus], int(&menuY)[numMenus], float xPos, float yPos, int type, PedSkin & skin, WeaponData & currentWeaponData){
	bool mpModel = isFreemode(type);
	bool spModel = !mpModel && isPlayer(type);
	if (menuY[partMenuID] == 0 && mpModel) // face blend
		drawFaceBlend(menu, menuX[varMenuID], menuY[varMenuID], xPos, yPos, skin);
	else if (menuY[partMenuID] == 0) // drawable head
		drawOneDrawable(menu, menuX[varMenuID], menuY[varMenuID], xPos, yPos, 0, spModel, skin);
	else if (menuY[partMenuID] == 1 && mpModel) // head morph
		drawHeadMorph(menu, menuX[varMenuID], menuY[varMenuID], xPos, yPos, skin);
	else if (menuY[partMenuID] == 1) // drawable hair
		drawOneDrawable(menu, menuX[varMenuID], menuY[varMenuID], xPos, yPos, 1, spModel, skin);
	else if (menuY[partMenuID] == 2 && mpModel) // head overlay
		drawOverlays(menu, menuX[varMenuID], menuY[varMenuID], xPos, yPos, type, skin);
	else if (menuY[partMenuID] == 2) // clothing
		drawClothingMenu(menu, menuX[varMenuID], menuY[varMenuID], xPos, yPos, mpModel, spModel, skin);
	else if (menuY[partMenuID] == 3 && mpModel) //clothing
		drawClothingMenu(menu, menuX[varMenuID], menuY[varMenuID], xPos, yPos, mpModel, spModel, skin);
	else if (menuY[partMenuID] == 3 && spModel) // tattoos
		drawTatMenu(menu, menuX[varMenuID], menuY[varMenuID], xPos, yPos, type, skin);
	else if (menuY[partMenuID] == 3) // weapon
		drawWeaponMenu(menu, menuX[varMenuID], menuY[varMenuID], xPos, yPos, skin, currentWeaponData);
	else if (menuY[partMenuID] == 4 && mpModel) // tattos
		drawTatMenu(menu, menuX[varMenuID], menuY[varMenuID], xPos, yPos, type, skin);
	else if (menuY[partMenuID] == 4 && spModel) // weapon
		drawWeaponMenu(menu, menuX[varMenuID], menuY[varMenuID], xPos, yPos, skin, currentWeaponData);
	else if (menuY[partMenuID] == 5 && mpModel) // weapon
		drawWeaponMenu(menu, menuX[varMenuID], menuY[varMenuID], xPos, yPos, skin, currentWeaponData);
}

void drawFaceBlend(int menu, int posX, int posY, float xPos, float yPos, PedSkin & skin){
	std::string blendInfo[2];
	for (int i = 0; i < 4; ++i){
		blendInfo[0] = headBlendNames[i];
		switch(i){
		case 0: blendInfo[1] = momNames[skin.freemodeData.mother]; break;
		case 1: blendInfo[1] = dadNames[skin.freemodeData.father]; break;
		case 2: blendInfo[1] = std::to_string(16 - skin.freemodeData.faceRatio) + ":" + std::to_string(skin.freemodeData.faceRatio); break;
		case 3: blendInfo[1] = std::to_string(16 - skin.freemodeData.skinRatio) + ":" + std::to_string(skin.freemodeData.skinRatio); break;
		default: blendInfo[1] = " "; break;
		}
		for (int j = 0; j < 2; ++j){
			if (menu == varMenuID && posY == i && posX == j)
				MM::drawRectWithText(blendInfo[j], subMenuWidth, namePad, yPos + i * (nameHeight + nameYSpace), xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0x000000FF, 0.35, 0, 0xF2DAF2FF);
			else
				MM::drawRectWithText(blendInfo[j], subMenuWidth, namePad, yPos + i * (nameHeight + nameYSpace), xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0xFFFFFFFF, 0.35, 0, 0x5F465FFF);
		}
	}
}

void drawHeadMorph(int menu, int posX, int posY, float xPos, float yPos, PedSkin & skin){
	std::string morphInfo[2];
	for (int i = 0; i < numMorphs; ++i){
		morphInfo[0] = headMorphs[i];
		morphInfo[1] = std::to_string(10 - skin.freemodeData.morph[i]) + ":" + std::to_string(10 + skin.freemodeData.morph[i]);
		for (int j = 0; j < 2; ++j){
			if (menu == varMenuID && posY == i && posX == j)
				MM::drawRectWithText(morphInfo[j], subMenuWidth, namePad, yPos + i * (nameHeight + nameYSpace), xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0x000000FF, 0.35, 0, 0xF2DAF2FF);
			else
				MM::drawRectWithText(morphInfo[j], subMenuWidth, namePad, yPos + i * (nameHeight + nameYSpace), xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0xFFFFFFFF, 0.35, 0, 0x5F465FFF);
		}
	}
}

int genderedDisplayID(int dID){
	switch (dID){
	case -2: return 0; break;
	case -1: return 2; break;
	case 0: return 1; break;
	default: return dID + 2; break;
	}
}

std::string getOverlayText(PedSkin & skin, int iID, int sID, int type){
	switch (sID){
	case 0: return fmOverlays[genderedDisplayID(iID)];
		break;
	case 1:
		switch (iID){
		case oHairID:
			if (type == 3)
				return fHairNames[skin.freemodeData.hair];
			else if (type == 4)
				return mHairNames[skin.freemodeData.hair];
			return "";
		case oEyeID:
			return eyeColorNames[skin.freemodeData.eyeColor];
		default:
			return overlayNames[iID][skin.freemodeData.overlay[iID].value + 1];
		}
		break;
	case 2:
		switch (iID){
		case oHairID:
			return "Color " + std::to_string(skin.freemodeData.hairColor);
		case oBeardID: case oEyebrowID: case oChestID: case oBlushID: case oLipstickID:
			return "Color " + std::to_string(skin.freemodeData.overlay[iID].color);
		default:
			return "Opacity " + std::to_string(skin.freemodeData.overlay[iID].opacity * 5) + "%";
		}
		break;
	case 3:
		switch (iID){
		case oHairID:
			return "Highlights " + std::to_string(skin.freemodeData.hairHighlights);
		default:
			return "Opacity" + std::to_string(skin.freemodeData.overlay[iID].opacity * 5) + "%";
		}
		break;
	}
	return " ";
}

void drawOverlays(int menu, int posX, int posY, float xPos, float yPos, int type, PedSkin & skin){
	std::string overlayInfo;
	int j;
	for (int i = 0; i < getNumOverlays(type); ++i){
		j = displayToInternal(i, type);
		for (int k = 0; k < getOverlayNumOptions(j); ++k){
			if (menu == varMenuID && posY == i && posX == k){
				overlayInfo = getOverlayText(skin, j, k, type);
				MM::drawRectWithText(overlayInfo, subMenuWidth, namePad, yPos + i * (nameHeight + nameYSpace), xPos + k * (subMenuWidth + nameXSpace), nameTextAlign, false, 0x000000FF, 0.35, 0, 0xF2DAF2FF);
			} else if ((menu == partMenuID && posX == 0) || (menu == varMenuID && posY == i)){
				overlayInfo = getOverlayText(skin, j, k, type);
				MM::drawRectWithText(overlayInfo, subMenuWidth, namePad, yPos + i * (nameHeight + nameYSpace), xPos + k * (subMenuWidth + nameXSpace), nameTextAlign, false, 0xFFFFFFFF, 0.35, 0, 0x5F465FFF);
			}
		}
	}
}

void drawOneDrawable(int menu, int posX, int posY, float xPos, float yPos, int i, bool spModel, PedSkin & skin){
	std::string drawableInfo[3];
	int j = displayToGameDrawable(i, false, spModel);
	int drawMax = getDrawableMax(j);
	int texMax = getTextureMax(j, skin.drawable[j]);
	drawableInfo[0] = (spModel ? spPartNames[i] : partNames[i]);
	drawableInfo[1] = sublineAsString("Model ", skin.drawable[j] + 1, drawMax);
	drawableInfo[2] = sublineAsString("Texture ", skin.texture[j] + 1, texMax);
	for (int k = 0; k < 3; ++k){
		if (menu == varMenuID && posY == 0 && posX == k)
			MM::drawRectWithText((k == 0 || drawMax > 0) ? drawableInfo[k] : " ", subMenuWidth, namePad, yPos, xPos + k * (subMenuWidth + nameXSpace), nameTextAlign, false, 0x000000FF, 0.35, 0, 0xF2DAF2FF);
		else if ((menu == partMenuID && posX == 0) || (menu == varMenuID && posY == 0))
			MM::drawRectWithText((k == 0 || drawMax > 0) ? drawableInfo[k] : " ", subMenuWidth, namePad, yPos, xPos + k * (subMenuWidth + nameXSpace), nameTextAlign, false, 0xFFFFFFFF, 0.35, 0, 0x5F465FFF);
	}
}

void drawClothingMenu(int menu, int posX, int posY, float xPos, float yPos, bool mpModel, bool spModel, PedSkin & skin){
	std::string drawableInfo[3];
	int drawMax, texMax;
	int j = -1;
	for (int i = 2; i < numParts; ++i){
		j = displayToGameDrawable(i, mpModel, spModel);
		drawMax = getDrawableMax(j);
		texMax = getTextureMax(j, skin.drawable[j]);
		drawableInfo[0] = (mpModel ? fmPartNames[i] : (spModel ? spPartNames[i] : partNames[i]));
		drawableInfo[1] = sublineAsString("Model ", skin.drawable[j] + 1, drawMax);
		drawableInfo[2] = sublineAsString("Texture ", skin.texture[j] + 1, texMax);
		for (int k = 0; k < 3; k++){
			if (menu == varMenuID && posY + 2 == i && posX == k)
				MM::drawRectWithText((k == 0 || drawMax > 0) ? drawableInfo[k] : " ", subMenuWidth, namePad, yPos + (i - 2) * (nameHeight + nameYSpace), xPos + k * (subMenuWidth + nameXSpace), nameTextAlign, false, 0x000000FF, 0.35, 0, 0xF2DAF2FF);
			else if ((menu == partMenuID && posX == 0) || (menu == varMenuID && posY + 2 == i))
				MM::drawRectWithText((k == 0 || drawMax > 0) ? drawableInfo[k] : " ", subMenuWidth, namePad, yPos + (i - 2) * (nameHeight + nameYSpace), xPos + k * (subMenuWidth + nameXSpace), nameTextAlign, false, 0xFFFFFFFF, 0.35, 0, 0x5F465FFF);
		}
	}
}

void drawTatMenu(int menu, int posX, int posY, float xPos, float yPos, int type, PedSkin & skin){
	std::string tatInfo[2];
	int t, n;
	for (int i = 0; i < numTatSlots - 1; ++i){ // - hair under
		for (int j = 0; j < 2; ++j){
			tatInfo[0] = getTattoSlotName(i);
			t = skin.tattoo[i].value;
			n = getNumAvailableTat(getTatZone(i), type, 0);
			tatInfo[1] = (t < 0) ? " " : (n <= 0) ? "None" : std::to_string(t + 1).append(" of ").append(std::to_string(n));
			if (menu == varMenuID && posY == i && posX == j)
				MM::drawRectWithText(tatInfo[j], subMenuWidth, namePad, yPos + i * (nameHeight + nameYSpace), xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0x000000FF, 0.35, 0, 0xF2DAF2FF);
			else
				MM::drawRectWithText(tatInfo[j], subMenuWidth, namePad, yPos + i * (nameHeight + nameYSpace), xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0xFFFFFFFF, 0.35, 0, 0x5F465FFF);
		}
	}
}

void drawWeaponMenu(int menu, int posX, int posY, float xPos, float yPos, PedSkin & skin, WeaponData & currentWeaponData){
	// Draw the weapon info
	std::string weaponInfo[2] = { "Name", getWeaponName(skin.weapon) };
	for (int j = 0; j < 2; j++){
		if (menu == varMenuID && posY == 0 && posX == j)
			MM::drawRectWithText(weaponInfo[j], subMenuWidth, namePad, yPos, xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0x000000FF, 0.35, 0, 0xF2DAF2FF);
		else
			MM::drawRectWithText(weaponInfo[j], subMenuWidth, namePad, yPos, xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0xFFFFFFFF, 0.35, 0, 0x5F465FFF);
	}
	weaponInfo[0] = "Action";
	weaponInfo[1] = (currentWeaponData.added ? "Drop" : "Equip");
	for (int j = 0; j < 2; j++){
		if (menu == varMenuID && posY == 1 && posX == j)
			MM::drawRectWithText(weaponInfo[j], subMenuWidth, namePad, yPos + nameHeight + nameYSpace, xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0x000000FF, 0.35, 0, 0xF2DAF2FF);
		else
			MM::drawRectWithText(weaponInfo[j], subMenuWidth, namePad, yPos + nameHeight + nameYSpace, xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0xFFFFFFFF, 0.35, 0, 0x5F465FFF);
	}
	weaponInfo[0] = (isKnuckle(skin.weapon) ? "Type" : "Tint");
	weaponInfo[1] =	sublineAsString("", skin.weaponTint + 1, getWeaponTintMax(skin.weapon));
	for (int j = 0; j < 2; j++){
		if (menu == varMenuID && posY == 2 && posX == j)
			MM::drawRectWithText(weaponInfo[j], subMenuWidth, namePad, yPos + 2 * (nameHeight + nameYSpace), xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0x000000FF, 0.35, 0, 0xF2DAF2FF);
		else
			MM::drawRectWithText(weaponInfo[j], subMenuWidth, namePad, yPos + 2 * (nameHeight + nameYSpace), xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0xFFFFFFFF, 0.35, 0, 0x5F465FFF);
	}
	// Draw the weapon mod info
	bool defaultSwaps = currentWeaponData.slotToCmpMap[0] == 0;
	int nameIndex;
	for (int i = 0; i < currentWeaponData.maxSlots; ++i){
		nameIndex = currentWeaponData.slotToCmpMap[i + (defaultSwaps ? 1 : 0)];
		for (int j = 0; j < 2; j++){
			weaponInfo[0] = weaponSlotNames[nameIndex];
			weaponInfo[1] = (nameIndex == 0) ? " " : (getWeaponModSetting(skin, currentWeaponData, i) ? "On" : "Off");
			if (menu == varMenuID && posY == 3 + i && posX == j)
				MM::drawRectWithText(weaponInfo[j], subMenuWidth, namePad, yPos + (3 + i) * (nameHeight + nameYSpace), xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0x000000FF, 0.35, 0, 0xF2DAF2FF);
			else
				MM::drawRectWithText(weaponInfo[j], subMenuWidth, namePad, yPos + (3 + i) *(nameHeight + nameYSpace), xPos + j * (subMenuWidth + nameXSpace), nameTextAlign, false, 0xFFFFFFFF, 0.35, 0, 0x5F465FFF);
		}
	}
}

void drawFileMenu(int index, float xPos, float yPos, std::vector<std::string> * saveNames){
	for (int i = 0; i < numSaves; i++){
		if (i == index)
			MM::drawRectWithText(saveNames->at(i), nameWidth, namePad + 3.0, yPos + (i % menuYMax[fileMenuID]) * (nameHeight + nameYSpace + 12.0), xPos + (i / menuYMax[fileMenuID]) * (nameWidth + nameXSpace), 0x000000FF, 0xF2DAF2FF);
		else
			MM::drawRectWithText(saveNames->at(i), nameWidth, namePad + 3.0, yPos + (i % menuYMax[fileMenuID]) * (nameHeight + nameYSpace + 12.0), xPos + (i / menuYMax[fileMenuID]) * (nameWidth + nameXSpace), 0xFFFFFFFF, 0x5F465FFF);
	}
}

std::string sublineAsString(std::string text, int A, int B){
	return text + std::to_string(A) + " of " + std::to_string(B);
}
