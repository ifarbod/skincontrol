/*
Skin Control dataFile.h
By Neutrinobeam
*/
#ifndef SC_DATAFILE
#define SC_DATAFILE

#pragma once
#include "script.h"

#include <string>

#define SAVEFILE "Skin Control.ini"

const int numSaves = 80;

// Determine the version type for the data file
// Read out the hotkey (broken I guess)
int checkDataFile(int& hotkey);

bool convertDataFile2_0();
bool convertDataFile2_1();

// Create a new, blank data file
void initDataFile();

// Read the save names from the data file
void peekNames(std::vector<std::string>* names);

// Read skin from slot of the data file into game
void loadSkin(int slot, PedSkin& skin, WeaponData& currentWeaponData, Hash& lastValidSkin, bool& nonDefaultSkin,
    std::vector<Entity>& weapon, std::vector<std::pair<Hash, int>>& ammoWeapon);

// Read skin from slot of the data file into memory
bool loadPedInSlot(int slot, PedSkin& skin);

// Prompt user for a name for this save
const char* getSaveName();

// Get name and save skin to slot of the data file
bool saveSkin(int slot, PedSkin& skin);

// Save skin to slot of the data file using name
bool saveSkinToSlot(int slot, const char* name, PedSkin& skin);
;

// Pack skin and name into a string
std::string pedSkinAsString(PedSkin& skin, std::string name);

// Unpack skin and name from a string
bool pedSkinFromString(PedSkin& skin, std::string data);

#endif
