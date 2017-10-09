/*
Skin Control weapons.cpp
By Neutrinobeam
*/

#pragma once
#include "weapons.h"
#include "modMenu.h"

LPCSTR weaponModels[] = {"WEAPON_UNARMED", "WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT",
    "WEAPON_CROWBAR", "WEAPON_GOLFCLUB", "WEAPON_BOTTLE", "WEAPON_DAGGER", "WEAPON_HATCHET", "WEAPON_BALL",
    "WEAPON_SNOWBALL", "WEAPON_KNUCKLE", "WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_SNSPISTOL", "WEAPON_APPISTOL",
    "WEAPON_PISTOL50", "WEAPON_HEAVYPISTOL", "WEAPON_VINTAGEPISTOL", "WEAPON_MARKSMANPISTOL", "WEAPON_STUNGUN",
    "WEAPON_FLAREGUN", "WEAPON_MICROSMG", "WEAPON_SMG", "WEAPON_ASSAULTSMG", "WEAPON_COMBATPDW", "WEAPON_MG",
    "WEAPON_COMBATMG", "WEAPON_GUSENBERG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE",
    "WEAPON_SPECIALCARBINE", "WEAPON_BULLPUPRIFLE", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN",
    "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN", "WEAPON_HEAVYSHOTGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER",
    "WEAPON_MARKSMANRIFLE", "WEAPON_MUSKET", "WEAPON_GRENADELAUNCHER", "WEAPON_RPG", "WEAPON_FIREWORK",
    "WEAPON_MINIGUN", "WEAPON_RAILGUN", "WEAPON_HOMINGLAUNCHER", "WEAPON_GRENADE", "WEAPON_STICKYBOMB",
    "WEAPON_PROXMINE", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS", "WEAPON_FLARE", "WEAPON_MOLOTOV",
    "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN", "WEAPON_DIGISCANNER", "WEAPON_BRIEFCASE", "WEAPON_BRIEFCASE_02"};
// weapon_programmablear, weapon_rubbergun, weapon_loudhailer, gadget_nightvision, gadget_parachute
LPCSTR weaponNames[] = {"Unarmed", "Knife", "Nightstick", "Hammer", "Bat", "Crowbar", "Golf Club", "Bottle",
    "Antique Dagger", "Hatchet", "Ball", "Snowball", "Knuckle Duster", "Pistol", "Combat Pistol", "SNS Pistol",
    "AP Pistol", ".50 Pistol", "Heavy Pistol", "Vintage Pistol", "Marksman Pistol", "Stun Gun", "Flare Gun",
    "Micro SMG", "SMG", "Assault SMG", "Combat PDW", "MG", "Combat MG", "Gusenberg", "Assault Rifle", "Carbine",
    "Advanced Rifle", "Special Carbine", "Bullpup Rifle", "Pump Shotgun", "Sawed Off", "Assault Shotgun",
    "Bullpup Shotgun", "Heavy Shotgun", "Sniper Rifle", "Heavy Sniper", "Markman's Rifle", "Musket", "Grenade Launch",
    "RPG", "Firework Launch", "Minigun", "Railgun", "Homing Launch", "Grenade", "Stickybomb", "Proximity Mine",
    "Smoke Grenade", "BZ Gas", "Flare", "Molotov", "Extinguisher", "Terry Can", "Scanner", "Briefcase",
    "Alt Briefcase"};

LPCSTR weaponComponentNames[] = {" ", "COMPONENT_AT_PI_FLSH", "COMPONENT_AT_AR_FLSH", "COMPONENT_AT_PI_SUPP",
    "component_at_pi_supp_02", "COMPONENT_AT_AR_SUPP", "COMPONENT_AT_AR_SUPP_02", "component_at_sr_supp",
    "component_at_scope_macro", "component_at_scope_macro_02", "COMPONENT_AT_SCOPE_SMALL",
    "component_at_scope_small_02", "COMPONENT_AT_SCOPE_MEDIUM", "component_at_scope_large",
    "COMPONENT_AT_SCOPE_LARGE_FIXED_ZOOM", "component_at_scope_max", "COMPONENT_AT_AR_AFGRIP",
    "component_pistol_clip_01", "component_pistol_clip_02", "component_combatpistol_clip_01",
    "component_combatpistol_clip_02", "component_appistol_clip_01", "component_appistol_clip_02",
    "component_pistol50_clip_01", "component_pistol50_clip_02", "COMPONENT_SNSPISTOL_CLIP_01",
    "COMPONENT_SNSPISTOL_CLIP_02", "COMPONENT_HEAVYPISTOL_CLIP_01", "COMPONENT_HEAVYPISTOL_CLIP_02",
    "COMPONENT_VINTAGEPISTOL_CLIP_01", "COMPONENT_VINTAGEPISTOL_CLIP_02", "COMPONENT_MICROSMG_CLIP_01",
    "COMPONENT_MICROSMG_CLIP_02", "COMPONENT_SMG_CLIP_01", "COMPONENT_SMG_CLIP_02", "COMPONENT_ASSAULTSMG_CLIP_01",
    "COMPONENT_ASSAULTSMG_CLIP_02", "COMPONENT_ASSAULTRIFLE_CLIP_01", "COMPONENT_ASSAULTRIFLE_CLIP_02",
    "COMPONENT_CARBINERIFLE_CLIP_01", "COMPONENT_CARBINERIFLE_CLIP_02", "COMPONENT_ADVANCEDRIFLE_CLIP_01",
    "COMPONENT_ADVANCEDRIFLE_CLIP_02", "COMPONENT_SPECIALCARBINE_CLIP_01", "COMPONENT_SPECIALCARBINE_CLIP_02",
    "COMPONENT_BULLPUPRIFLE_CLIP_01", "COMPONENT_BULLPUPRIFLE_CLIP_02", "COMPONENT_MG_CLIP_01", "COMPONENT_MG_CLIP_02",
    "COMPONENT_COMBATMG_CLIP_01", "COMPONENT_COMBATMG_CLIP_02", "COMPONENT_ASSAULTSHOTGUN_CLIP_01",
    "COMPONENT_ASSAULTSHOTGUN_CLIP_02", "COMPONENT_HEAVYSHOTGUN_CLIP_01", "COMPONENT_HEAVYSHOTGUN_CLIP_02",
    "component_sniperrifle_clip_01", "component_heavysniper_clip_01", "COMPONENT_MARKSMANRIFLE_CLIP_01",
    "COMPONENT_MARKSMANRIFLE_CLIP_02", "COMPONENT_GUSENBERG_CLIP_01", "COMPONENT_GUSENBERG_CLIP_02",
    "COMPONENT_COMBATPDW_CLIP_01", "COMPONENT_COMBATPDW_CLIP_02", "COMPONENT_KNUCKLE_VARMOD_BASE",
    "COMPONENT_KNUCKLE_VARMOD_PIMP", "COMPONENT_KNUCKLE_VARMOD_BALLAS", "COMPONENT_KNUCKLE_VARMOD_DOLLAR",
    "COMPONENT_KNUCKLE_VARMOD_DIAMOND", "COMPONENT_KNUCKLE_VARMOD_HATE", "COMPONENT_KNUCKLE_VARMOD_LOVE",
    "COMPONENT_KNUCKLE_VARMOD_PLAYER", "COMPONENT_KNUCKLE_VARMOD_KING", "COMPONENT_KNUCKLE_VARMOD_VAGOS"};

LPCSTR weaponSlotNames[numWeaponMods] = {
    "None", "Extended Clip", "Flashlight", "Suppressor", "Scope", "Grip", "Adv Scope"};

int getNumWeapons()
{
    return sizeof(weaponModels) / sizeof(LPCSTR);
}

DWORD getWeaponTintMax(Hash model)
{
    int index = hashLookup(model);
    if (index < 0)
    {
        return 0;
    }
    else if (index < 12)
    {
        //"WEAPON_UNARMED", "WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_CROWBAR",
        //"WEAPON_GOLFCLUB", "WEAPON_BOTTLE", "WEAPON_DAGGER", "WEAPON_HATCHET", "WEAPON_BALL", "WEAPON_SNOWBALL"
        return 1;
    }
    else if (index == 12)
    {
        // "WEAPON_KNUCKLE",
        return 10;
    }
    else if (index > 47)
    {
        //"WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_PROXMINE", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
        //"WEAPON_FLARE", "WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN", "WEAPON_DIGISCANNER",
        //"WEAPON_BRIEFCASE", "WEAPON_BRIEFCASE_02"
        return 1;
    }
    else
    {
        /*	"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_SNSPISTOL", "WEAPON_APPISTOL",
        "WEAPON_PISTOL50", "WEAPON_HEAVYPISTOL", "WEAPON_VINTAGEPISTOL", "WEAPON_MARKSMANPISTOL", "WEAPON_STUNGUN",
        "WEAPON_FLAREGUN", "WEAPON_MICROSMG", "WEAPON_SMG", "WEAPON_ASSAULTSMG", "WEAPON_COMBATPDW", "WEAPON_MG",
        "WEAPON_COMBATMG", "WEAPON_GUSENBERG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE",
        "WEAPON_SPECIALCARBINE", "WEAPON_BULLPUPRIFLE", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN",
        "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN", "WEAPON_HEAVYSHOTGUN", "WEAPON_SNIPERRIFLE",
        "WEAPON_HEAVYSNIPER", "WEAPON_MARKSMANRIFLE", "WEAPON_MUSKET", "WEAPON_GRENADELAUNCHER", "WEAPON_RPG",
        "WEAPON_FIREWORK", "WEAPON_MINIGUN", "WEAPON_RAILGUN", "WEAPON_HOMINGLAUNCHER",
        */
        return numTints;
    }
}

void getWeaponEquipped(PedSkin& skin, Ped id, WeaponData& currentWeaponData)
{
    Hash weapon;
    WEAPON::GET_CURRENT_PED_WEAPON(id, &weapon, FALSE);
    skin.weapon = weapon;
    int variant = getPedWeaponVariant(id, weapon, currentWeaponData);
    skin.weaponTint = (variant < 0) ? 0 : variant;
    currentWeaponData = getWeaponComponentData(weapon);
    skin.weaponModMask = getPedWeaponModMask(id, weapon, currentWeaponData);
}

void updateWeaponMod(PedSkin& skin, Ped id, WeaponData& currentWeaponData, int i)
{
    unsigned char componentNameID = currentWeaponData.cmpToHashIDMap[i];
    if (0 < componentNameID)
    {
        Hash component = GAMEPLAY::GET_HASH_KEY((char*)weaponComponentNames[componentNameID]);
        bool alreadyHas = 0 != WEAPON::HAS_PED_GOT_WEAPON_COMPONENT(id, skin.weapon, component);
        if (0 != (skin.weaponModMask & (1 << i)))
        {
            if (!alreadyHas)
            {
                WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(id, skin.weapon, component);
                WAIT(1);
            }
        }
        else if (alreadyHas)
        {
            WEAPON::REMOVE_WEAPON_COMPONENT_FROM_PED(id, skin.weapon, component);
            WAIT(1);
        }
    }
}
void setWeaponOfPed(PedSkin& skin, Ped id, WeaponData& currentWeaponData)
{
    if (0 != PED::IS_PED_HUMAN(id))
    {
        if (0 == WEAPON::HAS_PED_GOT_WEAPON(id, skin.weapon, FALSE))
        {
            int ammo;
            currentWeaponData.added = true;
            if (0 != WEAPON::GET_MAX_AMMO(id, skin.weapon, &ammo))
                WEAPON::GIVE_WEAPON_TO_PED(id, skin.weapon, ammo, FALSE, TRUE);
            else
                WEAPON::GIVE_WEAPON_TO_PED(id, skin.weapon, -1, FALSE, TRUE);
        }
        else
        {
            currentWeaponData.added = false;
        }
        WEAPON::SET_CURRENT_PED_WEAPON(id, skin.weapon, TRUE);
        for (int i = 0; i < numWeaponMods; ++i)
        {
            updateWeaponMod(skin, id, currentWeaponData, i);
        }
        if (skin.weaponTint >= 0)
            setWeaponVariant(skin, id, currentWeaponData);
    }
}

void getWeaponsFromPed(
    Ped pedID, std::vector<Entity>* weapons, std::vector<std::pair<Hash, int>>* ammoWeapons, Hash* equipped)
{
    Hash weapon;
    std::pair<Hash, int> temp;
    if (0 == PED::IS_PED_HUMAN(pedID))
    {
        return;
    }
    weapons->clear();
    ammoWeapons->clear();
    if (equipped != NULL)
        WEAPON::GET_CURRENT_PED_WEAPON(pedID, equipped, FALSE);
    for (int i = 0; i < getNumWeapons(); i++)
    {
        weapon = GAMEPLAY::GET_HASH_KEY((char*)weaponModels[i]);
        if (weapon != 0xA2719263 && 0 != WEAPON::HAS_PED_GOT_WEAPON(pedID, weapon, FALSE))
        {
            if (isAmmoWeapon(weapon))
            {
                temp.first = weapon;
                temp.second = WEAPON::GET_AMMO_IN_PED_WEAPON(pedID, weapon);
                ammoWeapons->emplace_back(temp);
            }
            else
            {
                WEAPON::SET_CURRENT_PED_WEAPON(pedID, weapon, TRUE);
                weapons->emplace_back(WEAPON::GET_WEAPON_OBJECT_FROM_PED(pedID, TRUE));  // true?
                ENTITY::SET_ENTITY_VISIBLE(weapons->back(), FALSE, FALSE);
            }
        }
    }
}

void setWeaponsOfPed(
    Ped pedID, std::vector<Entity>* weapons, std::vector<std::pair<Hash, int>>* ammoWeapons, Hash equipped)
{
    if (0 != PED::IS_PED_HUMAN(pedID))
    {
        for (int i = 0; i < weapons->size(); ++i)
        {
            WEAPON::GIVE_WEAPON_OBJECT_TO_PED(weapons->at(i), pedID);
        }
        for (int i = 0; i < ammoWeapons->size(); ++i)
        {
            WEAPON::GIVE_DELAYED_WEAPON_TO_PED(pedID, ammoWeapons->at(i).first, ammoWeapons->at(i).second, FALSE);
        }
        WEAPON::SET_CURRENT_PED_WEAPON(pedID, equipped, TRUE);
    }
}

bool getWeaponModSetting(PedSkin& skin, WeaponData& currentWeaponData, int slot)
{
    unsigned char componentID = getWeaponComponentForSlot(currentWeaponData, slot, true);
    return 0 != (skin.weaponModMask & (1 << componentID));
}
void updateWeaponModMask(PedSkin& skin, WeaponData& currentWeaponData, int slot, bool active)
{
    unsigned char componentID = getWeaponComponentForSlot(currentWeaponData, slot, true);
    unsigned char defaultID = getWeaponComponentForSlot(currentWeaponData, slot, false);
    if (active)
    {
        skin.weaponModMask |= 1 << componentID;
        if (hasAlternateComponent(currentWeaponData, slot))
        {
            skin.weaponModMask &= 0xFF - (1 << defaultID);
        }
    }
    else
    {
        skin.weaponModMask &= 0xFF - (1 << componentID);
        if (hasAlternateComponent(currentWeaponData, slot))
        {
            skin.weaponModMask |= 1 << defaultID;
        }
    }
}
void updateWeaponModMaskFromPed(Ped pedId, Hash weapon, PedSkin& skin, WeaponData& currentWeaponData)
{
    // If ped has weapon, read its mods into menuSkin.weaponModMask
    // Otherwise leave default
    if (0 != WEAPON::HAS_PED_GOT_WEAPON(pedId, weapon, FALSE))
        skin.weaponModMask = getPedWeaponModMask(pedId, weapon, currentWeaponData);
}
bool hasAlternateComponent(WeaponData& currentWeaponData, int slot)
{
    if (0 == currentWeaponData.slotToCmpMap[0] && 1 == slot)
        return true;
    else if (currentWeaponData.defaultMask > 63)
        return true;
    else
        return false;
}
unsigned char getWeaponComponentForSlot(WeaponData& currentWeaponData, int slot, bool active)
{
    bool defaultSwap = currentWeaponData.slotToCmpMap[0] == 0;
    if (active)
        return currentWeaponData.slotToCmpMap[slot + (defaultSwap ? 1 : 0)];
    else
        return getDefaultComponentForSlot(currentWeaponData, slot);
}
unsigned char getDefaultComponentForSlot(WeaponData& currentWeaponData, int slot)
{
    if (72 == currentWeaponData.defaultMask && 1 == slot)
    {  // Sniper
        return 4;
    }
    else if (64 == currentWeaponData.defaultMask && 0 == slot)
    {  // Heavy sniper
        return 4;
    }
    else
        return 0;
}

void setWeaponVariant(PedSkin& skin, Ped id, WeaponData& currentWeaponData)
{
    Hash component;
    if (skin.weapon == 3638508604)
    {  // WEAPON_KNUCKLE
        component =
            GAMEPLAY::GET_HASH_KEY((char*)weaponComponentNames[currentWeaponData.cmpToHashIDMap[0] + skin.weaponTint]);
        WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(id, skin.weapon, component);
    }
    else
    {
        WEAPON::SET_PED_WEAPON_TINT_INDEX(id, skin.weapon, skin.weaponTint);
    }
}

DWORD getPedWeaponVariant(Ped pedID, Hash weapon, WeaponData& currentWeaponData)
{
    Hash component;
    if (0 == WEAPON::HAS_PED_GOT_WEAPON(pedID, weapon, FALSE))
    {
        return 0;
    }
    if (weapon == 3638508604)
    {  // WEAPON_KNUCKLE
        for (DWORD i = 0; i < getWeaponTintMax(weapon); ++i)
        {
            component = GAMEPLAY::GET_HASH_KEY((char*)weaponComponentNames[currentWeaponData.cmpToHashIDMap[0] + i]);
            if (WEAPON::HAS_PED_GOT_WEAPON_COMPONENT(pedID, weapon, component))
            {
                return i;
            }
        }
        return 0;
    }
    else
    {
        return WEAPON::GET_PED_WEAPON_TINT_INDEX(pedID, weapon);
    }
}

// Returns the defaultMask of currentWeaponData masked according to the weapon mods ped id has for weapon
DWORD getPedWeaponModMask(Ped id, Hash weapon, WeaponData& currentWeaponData)
{
    DWORD mask = currentWeaponData.defaultMask;
    DWORD part = 1;
    Hash component;
    for (int i = 0; i < numWeaponMods; ++i)
    {
        unsigned char cmpNameID = currentWeaponData.cmpToHashIDMap[i];
        if (cmpNameID != 0)
        {
            component = GAMEPLAY::GET_HASH_KEY((char*)weaponComponentNames[cmpNameID]);
            mask &= 0xFF - part * (1 - WEAPON::HAS_PED_GOT_WEAPON_COMPONENT(id, weapon, component));
        }
        part <<= 1;
    }
    return mask;
}

Hash getUnarmedHash()
{
    return 0xA2719263;
}

Hash getWeaponHash(int index)
{
    if (index < 0 || index >= getNumWeapons())
        return getUnarmedHash();
    else
        return GAMEPLAY::GET_HASH_KEY((char*)weaponModels[index]);
}

LPCSTR getWeaponName(Hash weapon)
{
    int id = hashLookup(weapon);
    if (id < 0 || id >= getNumWeapons())
        return " ";
    return weaponNames[id];
}

bool isAmmoWeapon(Hash weapon)
{
    switch (weapon)
    {
        // Weapons
        case 600439132:   // WEAPON_BALL=
        case 126349499:   // WEAPON_SNOWBALL
        case 0x93E220BD:  // WEAPON_GRENADE=
        case 741814745:   // WEAPON_STICKYBOMB=
        case 2874559379:  // WEAPON_PROXMINE
        case 0xFDBC8A50:  // WEAPON_SMOKEGRENADE=
        case 0xA0973D5E:  // WEAPON_BZGAS=
        case 1233104067:  // WEAPON_FLARE=
        case 615608432:   // WEAPON_MOLOTOV=
            return true;
        default:
            return false;
    }
}

bool isKnuckle(Hash weapon)
{
    return (weapon == 3638508604);
}

WeaponData getWeaponComponentData(Hash weapon)
{
    switch (weapon)
    {
        // case hash: return WeaponData(numModSlots, defaultModMask b, modSlotNameIndices, modNameIndices); break;
        case 453432689:
            return WeaponData(3, 15, std::vector<unsigned char>{0, 1, 2, 3, 0, 0, 0},
                std::vector<unsigned char>{17, 18, 1, 4, 0, 0, 0});
            break;  // Pistol
        case 1593441988:
            return WeaponData(3, 15, std::vector<unsigned char>{0, 1, 2, 3, 0, 0, 0},
                std::vector<unsigned char>{19, 20, 1, 3, 0, 0, 0});
            break;  // CombatPistol
        case 584646201:
            return WeaponData(3, 15, std::vector<unsigned char>{0, 1, 2, 3, 0, 0, 0},
                std::vector<unsigned char>{21, 22, 1, 3, 0, 0, 0});
            break;  // APPistol
        case 0x99aeeb3b:
            return WeaponData(3, 15, std::vector<unsigned char>{0, 1, 2, 3, 0, 0, 0},
                std::vector<unsigned char>{23, 24, 1, 6, 0, 0, 0});
            break;  // Pistol50
        case 3218215474:
            return WeaponData(1, 3, std::vector<unsigned char>{0, 1, 0, 0, 0, 0, 0},
                std::vector<unsigned char>{25, 26, 0, 0, 0, 0, 0});
            break;  // WEAPON_SNSPISTOL
        case 3523564046:
            return WeaponData(3, 15, std::vector<unsigned char>{0, 1, 2, 3, 0, 0, 0},
                std::vector<unsigned char>{27, 28, 1, 3, 0, 0, 0});
            break;  // WEAPON_HEAVYPISTOL
        case 137902532:
            return WeaponData(2, 11, std::vector<unsigned char>{0, 1, 3, 0, 0, 0, 0},
                std::vector<unsigned char>{29, 30, 0, 3, 0, 0, 0});
            break;  // WEAPON_VINTAGEPISTOL
        case 324215364:
            return WeaponData(4, 31, std::vector<unsigned char>{0, 1, 2, 3, 4, 0, 0},
                std::vector<unsigned char>{31, 32, 1, 6, 8, 0, 0});
            break;  // MicroSMG
        case 736523883:
            return WeaponData(4, 31, std::vector<unsigned char>{0, 1, 2, 3, 4, 0, 0},
                std::vector<unsigned char>{33, 34, 2, 3, 9, 0, 0});
            break;  // SMG
        case 0xEFE7E2DF:
            return WeaponData(4, 31, std::vector<unsigned char>{0, 1, 2, 3, 4, 0, 0},
                std::vector<unsigned char>{35, 36, 2, 6, 8, 0, 0});
            break;  // assaultsmg
        case 0xBFEFFF6D:
            return WeaponData(5, 63, std::vector<unsigned char>{0, 1, 2, 3, 4, 5, 0},
                std::vector<unsigned char>{37, 38, 2, 6, 8, 16, 0});
            break;  // AssaultRifle
        case 0x83BF0278:
            return WeaponData(5, 63, std::vector<unsigned char>{0, 1, 2, 3, 4, 5, 0},
                std::vector<unsigned char>{39, 40, 2, 5, 12, 16, 0});
            break;  // Carbine
        case 0xAF113F99:
            return WeaponData(4, 31, std::vector<unsigned char>{0, 1, 2, 3, 4, 0, 0},
                std::vector<unsigned char>{41, 42, 2, 5, 10, 0, 0});
            break;  // advancedrifle
        case 3231910285:
            return WeaponData(5, 63, std::vector<unsigned char>{0, 1, 2, 3, 4, 5, 0},
                std::vector<unsigned char>{43, 44, 2, 6, 12, 16, 0});
            break;  // WEAPON_SPECIALCARBINE
        case 2132975508:
            return WeaponData(5, 63, std::vector<unsigned char>{0, 1, 2, 3, 4, 5, 0},
                std::vector<unsigned char>{45, 46, 2, 5, 10, 16, 0});
            break;  // WEAPON_BULLPUPRIFLE
        case 0x9D07F764:
            return WeaponData(2, 19, std::vector<unsigned char>{0, 1, 4, 0, 0, 0, 0},
                std::vector<unsigned char>{47, 48, 0, 0, 11, 0, 0});
            break;  // mg
        case 2144741730:
            return WeaponData(3, 51, std::vector<unsigned char>{0, 1, 4, 5, 0, 0, 0},
                std::vector<unsigned char>{49, 50, 0, 0, 12, 16, 0});
            break;  // combatmg
        case 487013001:
            return WeaponData(2, 12, std::vector<unsigned char>{2, 3, 0, 0, 0, 0, 0},
                std::vector<unsigned char>{0, 0, 2, 7, 0, 0, 0});
            break;  // pumpshotgun
        case 0xE284C527:
            return WeaponData(4, 47, std::vector<unsigned char>{0, 1, 2, 3, 5, 0, 0},
                std::vector<unsigned char>{51, 52, 2, 5, 0, 16, 0});
            break;  // assaultshotgun
        case 0x9D61E50F:
            return WeaponData(3, 44, std::vector<unsigned char>{2, 3, 5, 0, 0, 0, 0},
                std::vector<unsigned char>{0, 0, 2, 6, 0, 16, 0});
            break;  // bullpupshotgun
        case 984333226:
            return WeaponData(4, 47, std::vector<unsigned char>{0, 1, 2, 3, 5, 0, 0},
                std::vector<unsigned char>{53, 54, 2, 6, 0, 16, 0});
            break;  // WEAPON_HEAVYSHOTGUN
        case 0x5fc3c11:
            return WeaponData(2, 72, std::vector<unsigned char>{3, 6, 0, 0, 0, 0, 0},
                std::vector<unsigned char>{55, 0, 0, 6, 13, 0, 15});
            break;  // sniper
        case 0xc472fe2:
            return WeaponData(1, 64, std::vector<unsigned char>{6, 0, 0, 0, 0, 0, 0},
                std::vector<unsigned char>{56, 0, 0, 0, 13, 0, 15});
            break;  // heavySniper
        case 3342088282:
            return WeaponData(5, 63, std::vector<unsigned char>{0, 1, 2, 3, 4, 5, 0},
                std::vector<unsigned char>{57, 58, 2, 5, 14, 16, 0});  // WEAPON_MARKSMANRIFLE
        case 0xA284510B:
            return WeaponData(3, 52, std::vector<unsigned char>{2, 4, 5, 0, 0, 0, 0},
                std::vector<unsigned char>{0, 0, 2, 0, 10, 16, 0});  // grenadelauncher
        case 1627465347:
            return WeaponData(1, 3, std::vector<unsigned char>{0, 1, 0, 0, 0, 0, 0},
                std::vector<unsigned char>{59, 60, 0, 0, 0, 0, 0});  // WEAPON_GUSENBERG
        case 0xA3D4D34:
            return WeaponData(4, 55, std::vector<unsigned char>{0, 1, 2, 4, 5, 0, 0},
                std::vector<unsigned char>{61, 62, 2, 0, 10, 16, 0});  // WEAPON_COMBATPDW
        case 3638508604:
            return WeaponData(0, 0, std::vector<unsigned char>{0, 0, 0, 0, 0, 0, 0},
                std::vector<unsigned char>{63, 0, 0, 0, 0, 0, 0});  // WEAPON_KNUCKLE

        default:
            break;
    }
    return WeaponData(
        0, 0, std::vector<unsigned char>{0, 0, 0, 0, 0, 0, 0}, std::vector<unsigned char>{0, 0, 0, 0, 0, 0, 0});
};
