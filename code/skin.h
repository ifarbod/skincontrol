/*
Skin Control skin.h
By Neutrinobeam
*/
#ifndef SC_SKIN
#define SC_SKIN

#pragma once
#include "script.h"

extern LPCSTR pedModelData[740][2];

// Read game to memory
void initializeMenuSkin(PedSkin& skin, WeaponData& currentWeaponData, int& type);

// Read game to memory
void getSkinComponentsFromID(PedSkin& skin, Ped id);

// Push memory to game
void setSkinComponentsOfID(PedSkin& skin, Ped id);

// Push memory to game
void setSkinComponentOfID(PedSkin& skin, Ped pedID, int id);

// Change model in memory, update game, read additional pedskin data
void setSkinFromIndex(PedSkin& skin, int index, WeaponData& currentWeaponData, Hash& lastValidSkin,
    bool& nonDefaultSkin, std::vector<Entity>& weapon, std::vector<std::pair<Hash, int>>& ammoWeapon);

// Push model and optional data to game
void renderPlayerSkin(
    PedSkin& skin, WeaponData& currentWeaponData, int toIndex, bool changeModel, bool useExtras, bool& nonDefaultSkin);

int getDrawableMax(int part);

int getTextureMax(int part, int drawable);

#endif