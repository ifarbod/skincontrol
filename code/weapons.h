/*
Skin Control weapons.h
By Neutrinobeam
*/
#ifndef SC_WEAPONS
#define SC_WEAPONS

#pragma once
#include "script.h"

const int numTints = 8;

int getNumWeapons();

DWORD getWeaponTintMax(Hash model);

void getWeaponEquipped(PedSkin& skin, Ped id, WeaponData& currentWeaponData);
void setWeaponOfPed(PedSkin& skin, Ped id, WeaponData& currentWeaponData);

void getWeaponsFromPed(
    Ped pedID, std::vector<Entity>* weapons, std::vector<std::pair<Hash, int>>* ammoWeapons, Hash* equipped);
void setWeaponsOfPed(
    Ped pedID, std::vector<Entity>* weapons, std::vector<std::pair<Hash, int>>* ammoWeapons, Hash equipped);

bool getWeaponModSetting(PedSkin& skin, WeaponData& currentWeaponData, int slot);
void updateWeaponModMask(PedSkin& skin, WeaponData& currentWeaponData, int slot, bool active);
void updateWeaponModMaskFromPed(Ped pedId, Hash weapon, PedSkin& skin, WeaponData& currentWeaponData);
void updateWeaponMod(PedSkin& skin, Ped id, WeaponData& currentWeaponData, int i);
bool hasAlternateComponent(WeaponData& currentWeaponData, int slot);
unsigned char getWeaponComponentForSlot(WeaponData& currentWeaponData, int slot, bool active);
unsigned char getDefaultComponentForSlot(WeaponData& currentWeaponData, int slot);

void setWeaponVariant(PedSkin& skin, Ped id, WeaponData& currentWeaponData);
DWORD getPedWeaponVariant(Ped pedID, Hash weapon, WeaponData& tempWeaponData);

DWORD getPedWeaponModMask(Ped id, Hash weapon, WeaponData& currentWeaponData);

WeaponData getWeaponComponentData(Hash weapon);

Hash getUnarmedHash();

Hash getWeaponHash(int index);

LPCSTR getWeaponName(Hash weapon);

bool isAmmoWeapon(Hash weapon);
bool isKnuckle(Hash weapon);

extern LPCSTR weaponNames[];

extern LPCSTR weaponModels[];

extern LPCSTR weaponSlotNames[numWeaponMods];

#endif