/*
Skin Control menu.h
By Neutrinobeam
*/
#ifndef SC_MENU
#define SC_MENU

#pragma once
#include "modMenu.h"
#include "script.h"

// Avoiding magic numbers
const int numMenus = 5;

// Primary menu (when the hotkey is pressed)
const int optionMenuID = 0;

// Grid displayed during save and load
const int fileMenuID = 1;

// Model selection
const int skinMenuID = 2;

// Changeable parts of a model (first vertical bar, e.g. components and props)
const int partMenuID = 3;

// Selection of variations of a “part”
const int varMenuID = 4;

// Navigation help
const int menuXMax[numMenus] = {4, 5, 37, 1, 0};
const int menuYMax[numMenus] = {1, 5, 20, 6, 0};

// Internal ids for special face overlays
const int oHairID = -2;
const int oBeardID = 1;
const int oEyebrowID = 0;
const int oChestID = 2;
const int oEyeID = -1;
const int oBodyBlem1 = 7;
const int oBodyBlem2 = 8;
const int oBlushID = 11;
const int oLipstickID = 12;

// Menu sizing and spacing (intended for 1080x1920)
const float titleWidth = 250.0f;
const float titlePad = 3.0f;
const float titleHeight = 30.0f;
const float titleLeft = 0.0f;
const float titleDown = 0.0f;
const float titleTextAlign = 3.0f;
const float nameWidth = 200.0f;
const float namePad = 2.0f;
const float nameHeight = 16.0f + 2 * namePad;
const float nameLeft = 10.0f;
const float nameBelowTitle = 5.0f + titleDown + titleHeight + 2 * titlePad;
const float nameXSpace = 4.0f;
const float nameYSpace = 2.0f;
const float nameTextAlign = 3.0f;
const float subMenuWidth = 110.0f;

// This does nothing :^)
const int partMenuOffset = 1;

void setMainMenu();

// Called when hotkey is pressed
// Continually draws the current menus based on state and sends
// user input to the appropriate “process” submenu.
void processSkinControlMenu(int& convertFile, Hash& lastValidSkin, bool& nondefaultSkin, PedSkin& skin,
    std::vector<Entity>& weapon, std::vector<std::pair<Hash, int>>& ammoWeapons, int hotkey);

// Receives input to the main menu
void processOptionMenu(MM::Input current, bool& inUI, int (&menuX)[numMenus], int (&menuY)[numMenus]);

// Receives input to the model select menu
void processSkinMenu(MM::Input current, PedSkin& skin, int (&menuX)[numMenus], int (&menuY)[numMenus],
    WeaponData& currentWeaponData, Hash& lastValidSkin, bool& nondefaultSkin, std::vector<Entity>& weapon,
    std::vector<std::pair<Hash, int>>& ammoWeapon);

// Receives input to the model components menu
void processPartMenu(MM::Input current, PedSkin& skin, int (&menuX)[numMenus], int (&menuY)[numMenus], int type);

// Receives input to the file selection menu
int processFileMenu(MM::Input current, PedSkin& skin, int (&menuX)[numMenus], int (&menuY)[numMenus],
    WeaponData& currentWeaponData, Hash& lastValidSkin, bool& nonDefaultSkin, std::vector<Entity>& weapon,
    std::vector<std::pair<Hash, int>>& ammoWeapon);

// Delegates input to the model components’ submenus.
void processVariationMenu(MM::Input current, PedSkin& skin, int (&menuX)[numMenus], int (&menuY)[numMenus], int type,
    WeaponData& currentWeaponData);

// Receives input to the face blend variation menu.
void processFaceBlendMenu(MM::Input current, PedSkin& skin, int (&menuX)[numMenus], int (&menuY)[numMenus]);

// Receives input to the face morph variation menu.
void processMorphMenu(MM::Input current, PedSkin& skin, int (&menuX)[numMenus], int (&menuY)[numMenus]);

// Receives input to the face overlay variation menu.
void processOverlayMenu(MM::Input current, PedSkin& skin, int (&menuX)[numMenus], int (&menuY)[numMenus], int type);

// Receives input to one drawable (clothing / component) variation menu.
void processDrawableMenu(MM::Input current, PedSkin& skin, int (&menuX)[numMenus], int (&menuY)[numMenus], int slot);

// Receives input to the clothing & props variation menu.
void processClothingMenu(MM::Input current, PedSkin& skin, int (&menuX)[numMenus], int (&menuY)[numMenus], int type);

// Receives input to the tattoos variation menu.
void processTatMenu(MM::Input current, PedSkin& skin, int (&menuX)[numMenus], int (&menuY)[numMenus], int type);

// Receives input to the weapons variation menu.
void processWeaponMenu(MM::Input current, PedSkin& skin, int (&menuX)[numMenus], int (&menuY)[numMenus], int type,
    WeaponData& currentWeaponData);

// Push changes to game
void changeMenuSkinDrawable(MM::Input current, PedSkin& skin, int posY);
void changeMenuSkinTexture(MM::Input current, PedSkin& skin, int posY);
void changeMenuWeapon(MM::Input current, PedSkin& skin, WeaponData& currentWeaponData);
void changeMenuWeaponTint(MM::Input current, PedSkin& skin);
void changeMenuWeaponModSetting(PedSkin& skin, WeaponData& currentWeaponData, int weaponModSlot, bool weaponModSetting);

// Move selection
void moveHorizontal(int menu, MM::Input current, int (&menuX)[numMenus], int (&menuY)[numMenus], int max);
void moveVertical(int menu, MM::Input current, int (&menuX)[numMenus], int (&menuY)[numMenus], int max);

void drawOptionMenu(int posX, float xPox, float yPos, std::string name);
void drawFileMenu(int index, float xPos, float yPos, std::vector<std::string>* saveNames);
void drawSkinMenu(int posX, int posY, float xPos, float yPos);
void drawPartMenu(int menu, int (&menuX)[numMenus], int (&menuY)[numMenus], float xPos, float yPos, int type,
    PedSkin& skin, WeaponData& currentWeaponData);
void drawVariationMenu(int menu, int (&menuX)[numMenus], int (&menuY)[numMenus], float xPos, float yPos, int type,
    PedSkin& skin, WeaponData& currentWeaponData);
void drawPedMenu(int index, int optionMenuSetting, float xPos, float yPos, std::vector<PedSkin>& skins);

void drawFaceBlend(int menu, int posX, int posY, float xPos, float yPos, PedSkin& skin);
void drawHeadMorph(int menu, int posX, int posY, float xPos, float yPos, PedSkin& skin);
void drawOverlays(int menu, int posX, int posY, float xPos, float yPos, int type, PedSkin& skin);
void drawOneDrawable(int menu, int posX, int posY, float xPos, float yPos, int i, bool spModel, PedSkin& skin);
void drawTwoDrawable(
    int menu, int posX, int posY, float xPos, float yPos, int i, bool mpModel, bool spModel, PedSkin& skin);
void drawClothingMenu(int menu, int posX, int posY, float xPos, float yPos, bool mpModel, bool spModel, PedSkin& skin);
void drawTatMenu(int menu, int posX, int posY, float xPos, float yPos, int type, PedSkin& skin);
void drawWeaponMenu(int menu, int posX, int posY, float xPos, float yPos, PedSkin& skin, WeaponData& currentWeaponData);

std::string sublineAsString(std::string text, int A, int B);

#endif
