/*
Skin Control tattoo.cpp
By Neutrinobeam
*/

#include "script.h"

// Internally tattoos occupy one of 15 slots
LPCSTR getTattoSlotName(int tatSlot);

int getNumAvailableTat(int zone, int type, DWORD mask);

int getTatZone(int tatSlot);

int getTatCollection(int type, int zone, int value);

Hash getTatCollectionHash(int id);

Hash getTatHash(int type, int zone, int value);

void getTats(PedSkin & skin, int type, bool global);

void updateTats(PedSkin & skin, int type);