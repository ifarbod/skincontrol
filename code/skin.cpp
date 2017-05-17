/*
Skin Control skin.cpp
By Neutrinobeam
*/

#pragma once
#include "script.h"
#include "skin.h"
#include "weapons.h"
#include "tattoo.h"
#include "facedata.h"
#include "modMenu.h"

void initializeMenuSkin(PedSkin & skin, WeaponData & currentWeaponData, int & type)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	skin.model = ENTITY::GET_ENTITY_MODEL(playerPed);
	type = hashLookup(skin.model);
	getSkinComponentsFromID(skin, playerPed);
	getTats(skin, type, true); // global to skin
	getFreeModeFace(skin, type, true); // global/natives to skin
	getWeaponEquipped(skin, playerPed, currentWeaponData);

}

void getSkinComponentsFromID(PedSkin & skin, Ped id){
	for (int i = 0; i < numParts; i++)
	{
		switch (i){
		case 12:
		case 13:
		case 14:
			skin.drawable[i] = PED::GET_PED_PROP_INDEX(id, i - firstProp);
			skin.texture[i] = PED::GET_PED_PROP_TEXTURE_INDEX(id, i - firstProp);
			break;
		case 15:
			skin.drawable[i] = PED::GET_PED_PROP_INDEX(id, watchSlot);
			skin.texture[i] = PED::GET_PED_PROP_TEXTURE_INDEX(id, watchSlot);
			break;
		default:
			skin.drawable[i] = PED::GET_PED_DRAWABLE_VARIATION(id, i);
			skin.texture[i] = PED::GET_PED_TEXTURE_VARIATION(id, i);
			break;
		}
	}
}

void setSkinComponentsOfID(PedSkin & skin, Ped id)
{
	for (int i = 0; i < numParts; i++){
		setSkinComponentOfID(skin, id, i);
	}
}

void setSkinComponentOfID(PedSkin & skin, Ped pedID, int id){
	if (id < firstProp)
		PED::SET_PED_COMPONENT_VARIATION(pedID, id, skin.drawable[id], skin.texture[id], PED::GET_PED_PALETTE_VARIATION(pedID, id));
	else if (id == numParts - 1 && skin.drawable[id] >= 0)
		PED::SET_PED_PROP_INDEX(pedID, watchSlot, skin.drawable[id], skin.texture[id], 0);
	else if (id == numParts - 1)
		PED::CLEAR_PED_PROP(pedID, watchSlot);
	else if (skin.drawable[id] >= 0)
		PED::SET_PED_PROP_INDEX(pedID, id - firstProp, skin.drawable[id], skin.texture[id], 0);
	else
		PED::CLEAR_PED_PROP(pedID, id - firstProp);
}

void setSkinFromIndex(PedSkin & skin, int index, WeaponData & currentWeaponData, Hash & lastValidSkin, bool & nonDefaultSkin, std::vector<Entity> & weapon, std::vector<std::pair<Hash, int>> & ammoWeapon){
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Hash current = ENTITY::GET_ENTITY_MODEL(playerPed);
	setLastSkin(current, lastValidSkin);
	skin.model = getModelHash(index);
	bool modelChange = (skin.model != current);
	std::vector<Entity> weapons;
	std::vector<std::pair<Hash, int>> ammoWeapons;
	Hash equipped;
	if (modelChange){
		if (0 == PED::IS_PED_HUMAN(playerPed)){
			weapons = weapon;
			ammoWeapons = ammoWeapon;
		}
		else
			getWeaponsFromPed(playerPed, &weapons, &ammoWeapons, &equipped);
	}
	skin.tatsPreserve = skin.fmPreserve = !modelChange;
	getTats(skin, index, false);
	getFreeModeFace(skin, index, false);
	renderPlayerSkin(skin, currentWeaponData, index, modelChange, false, nonDefaultSkin);
	playerPed = PLAYER::PLAYER_PED_ID();
	if (modelChange){
		if (0 == PED::IS_PED_HUMAN(playerPed)){
			weapon = weapons;
			ammoWeapon = ammoWeapons;
		}
		else
			setWeaponsOfPed(playerPed, &weapons, &ammoWeapons, equipped);
	}
	getSkinComponentsFromID(skin, playerPed);
	getWeaponEquipped(skin, playerPed, currentWeaponData);
}

void renderPlayerSkin(PedSkin & skin, WeaponData & currentWeaponData, int index, bool newModel, bool fromSave, bool & nonDefaultSkin)
{
	if (STREAMING::IS_MODEL_VALID(skin.model) && STREAMING::IS_MODEL_IN_CDIMAGE(skin.model))
	{
		if (newModel){
			STREAMING::REQUEST_MODEL(skin.model);
			while (!STREAMING::HAS_MODEL_LOADED(skin.model)) WAIT(0);
			PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), skin.model);
			PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
			setNondefaultSkin(index, nonDefaultSkin);
			if (!fromSave && isFreemode(index)){
				setPedHeadBlend(skin, PLAYER::PLAYER_PED_ID());
			}
			WAIT(0);
		}
		if (fromSave){
			setSkinComponentsOfID(skin, PLAYER::PLAYER_PED_ID());
			updateFMFace(skin, index);
			updateTats(skin, index);
			setWeaponOfPed(skin, PLAYER::PLAYER_PED_ID(), currentWeaponData);
		}
		WAIT(0);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(skin.model);
	}
}

int getDrawableMax(int part)
{
	if (part < firstProp)
		return PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), part);
	else if (part == numParts - 1)
		return PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), watchSlot);
	else
		return PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), part - firstProp);
}

int getTextureMax(int part, int drawable)
{
	if (part < firstProp)
		return PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(PLAYER::PLAYER_PED_ID(), part, drawable);
	else if (part == numParts - 1)
		return PED::GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(PLAYER::PLAYER_PED_ID(), watchSlot, drawable);
	else
		return PED::GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(PLAYER::PLAYER_PED_ID(), part - firstProp, drawable);
}
