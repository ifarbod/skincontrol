/*
Skin Control
facedata.h
By Neutrinobeam
*/

#pragma once
#include "script.h"
// See menu.h and menu.cpp for human readable strings and values of constants

// Push freemode face data to game
void updateFMFace(PedSkin & skin, int type);

// Read whatever freemode face data can be from the game
void getFreeModeFace(PedSkin & skin, int type, bool global);

// Push face data derived from parents to game
void setPedHeadBlend(PedSkin & skin, Ped pedID);

// Push face feature (morphs, e.g. nose length) to game
void setPedHeadMorph(PedSkin & skin, Ped pedID, int id);

// Push face decorations (overlays, e.g. makeup) to game
void setPedFreemodeOverlay(PedSkin & skin, Ped pedID, int id, int type);

// Different overlays call different natives, and I wanted them
// contiguous in local (“internal”) memory
// I don’t remember if they have to be called in order.
int internalToGame(int iID);
