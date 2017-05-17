/*
Skin Control pedModels.h
By Neutrinobeam, "Legible" names from Enhanced Native Trainer
*/
#ifndef SC_PEDMODELS
#define SC_PEDMODELS

#pragma once
#include "scripthookv/types.h"

// Helper functions related to model hashes

bool isSinglePlayer(Hash model);

bool isFreemode(Hash model);

bool isFreemode(int index);

bool isPlayer(Hash model);

bool isPlayer(int index);

bool isAnimal(int index);

Hash getModelHash(int index);

LPCSTR getModel(int index);

LPCSTR getModelName(int index);

#endif
