/*
Skin Control dataFile.cpp
By Neutrinobeam
*/

#pragma once
#include "dataFile.h"
#include "modMenu.h"
#include "skin.h"
#include "tattoo.h"
#include "weapons.h"

#include <fstream>

/* Save File Format
    v1.0 & v1.1 ?
    Skin Control.dat
    Save file for Skin Control. Do not edit.
    name modelHash nthComponent nthComponentTexture nthProp nthPropTexture weaponID weaponTint
    v1.2
    Skin Control.dat
    Save file for Skin Control. Do not edit.
    name modelHash nthComponent nthComponentTexture nthProp nthPropTexture weaponID weaponTint weaponMask
    v2.0
    Skin Control.dat v2.0
    Save file for Skin Control. Do not edit.
    <name>modelHash nthDrawable nthDrawableTexture weaponID weaponTint weaponMask tattoMask (ifPlayer) nthTattooValue
   nthTattooCollection nthTattooZone (ifFreemode) mother father faceRatio skinRatio overrideRatio nthMorph eyeColor hair
   hairColor hairHighlights nthOverlayValue nthOverlayColor nthOverlayOpacity v2.1 Skin Control.ini v2.1 Hotkey: 119
    <name>modelHash nthDrawable nthDrawableTexture weaponID weaponTint weaponMask tattoMask (ifPlayer) nthTattooValue
   nthTattooCollection nthTattooZone (ifFreemode) mother father faceRatio skinRatio overrideRatio nthMorph eyeColor hair
   hairColor hairHighlights nthOverlayValue nthOverlayColor nthOverlayOpacity
    */

// used to convert pre v2.0 save files to v2.0
bool convertDataFile2_0()
{
    std::string text;
    std::string outText = "";
    std::string tempText = "";
    int modelID = -2;
    int value = -1;
    int valueID;
    int mother = 0;
    int father = 0;
    int hair = 0;
    int haircolor = 0;
    int mix = 0;
    size_t pos;
    size_t pre;
    bool readValid;
    std::fstream buffer(SAVEFILE, std::fstream::in);
    if (!buffer.is_open())
    {
        MM::notifyAboveMap("Count not open data file.");
        return false;
    }
    std::getline(buffer, text);
    outText.append("Skin Control.dat ");
    outText.append(VERSION);
    std::getline(buffer, text);
    outText.push_back('\n');
    outText.append("Save file for Skin Control. Do not edit.");
    outText.push_back('\n');
    for (int i = 0; i < numSaves; i++)
    {
        readValid = true;
        valueID = -1;
        std::getline(buffer, text);
        pos = text.find_first_of(' ');
        if (pos != std::string::npos)
        {
            outText.append("<");
            outText.append(text.substr(0, pos));
            outText.append(">");
            while (readValid)
            {
                ++valueID;
                switch (valueID)
                {
                    case 0:  // malformed modelHash to default
                        pre = pos + 1;
                        pos = text.find_first_of(' ', pre);
                        if (pos != std::string::npos)
                            modelID = hashLookup(std::stoul(text.substr(pre, pos - pre)));
                        else
                        {
                            modelID = hashLookup(std::stoul(text.substr(pre)));
                            ++valueID;
                        }
                        if (modelID == -1)
                        {  // -2 when pos == npos
                            // Unreadable to Franklin
                            outText.append(std::to_string(getModelHash(1)));
                            outText.append(" ");
                            modelID = 1;
                        }
                        else if (pos != std::string::npos)
                        {
                            outText.append(text.substr(pre, pos - pre + 1));
                        }
                        break;
                    case 1:  // freemode parent face to head blend
                        pre = pos + 1;
                        pos = text.find_first_of(' ', pre);
                        if (pos != std::string::npos)
                        {
                            value = std::stoi(text.substr(pre, pos - pre));
                        }
                        else
                        {
                            value = std::stoi(text.substr(pre));
                            ++valueID;
                        }
                        if (isFreemode(modelID))
                        {
                            // 0 to PED::_0x5EF...(0)-1 to PED::_0x5EF...(0)+ PED::_0x5EF...(2)-1 : male
                            // PED::_0x5EF...(0)+ PED::_0x5EF...(2)-1 to
                            if (value >= PED::_GET_NUM_PARENT_PEDS_OF_TYPE(0) + PED::_GET_NUM_PARENT_PEDS_OF_TYPE(2) +
                                             PED::_GET_NUM_PARENT_PEDS_OF_TYPE(1) +
                                             PED::_GET_NUM_PARENT_PEDS_OF_TYPE(3))
                                value = 0;
                            if (value >= PED::_GET_NUM_PARENT_PEDS_OF_TYPE(0) + PED::_GET_NUM_PARENT_PEDS_OF_TYPE(2))
                            {
                                mother =
                                    value - PED::_GET_NUM_PARENT_PEDS_OF_TYPE(0) - PED::_GET_NUM_PARENT_PEDS_OF_TYPE(2);
                            }
                            else
                            {
                                father = value;
                                mix = 16;
                            }
                            value = 0;
                        }
                        outText.append(std::to_string(value));
                        outText.append(" ");
                        break;
                    case 5:  // freemode old hair to head overlay
                        pre = pos + 1;
                        pos = text.find_first_of(' ', pre);
                        if (pos != std::string::npos)
                        {
                            value = std::stoi(text.substr(pre, pos - pre));
                        }
                        else
                        {
                            value = std::stoi(text.substr(pre));
                            ++valueID;
                        }
                        if (isFreemode(modelID))
                        {
                            hair = value;
                        }
                        outText.append(std::to_string(value));
                        outText.append(" ");
                        break;
                    case 6:  // freemode old hair color to head overlay
                        pre = pos + 1;
                        pos = text.find_first_of(' ', pre);
                        if (pos != std::string::npos)
                        {
                            value = std::stoi(text.substr(pre, pos - pre));
                        }
                        else
                        {
                            value = std::stoi(text.substr(pre));
                            ++valueID;
                        }
                        if (isFreemode(modelID))
                        {
                            haircolor = value;
                        }
                        outText.append(std::to_string(value));
                        outText.append(" ");
                        break;
                    case 25:
                    case 26:
                    case 27:
                    case 28:
                    case 29:
                    case 30:
                    case 37:
                    case 38:
                        pre = pos + 1;
                        pos = text.find_first_of(' ', pre);
                        if (pos != std::string::npos)
                        {
                            value = std::stoi(text.substr(pre, pos - pre));
                        }
                        else
                        {
                            value = std::stoi(text.substr(pre));
                            ++valueID;
                        }
                        outText.append(std::to_string(value - 1) + ' ');
                        break;
                    case 31:
                    case 32:
                    case 33:
                    case 34:
                    case 35:
                    case 36:
                    case 39:
                    case 40:
                        pre = pos + 1;
                        pos = text.find_first_of(' ', pre);
                        break;
                    case 41:
                        pre = pos + 1;
                        pos = text.find_first_of(' ', pre);
                        if (pos != std::string::npos)
                        {
                            value = std::stoi(text.substr(pre, pos - pre));
                        }
                        else
                        {
                            value = std::stoi(text.substr(pre));
                            ++valueID;
                        }
                        // read value to weaponHash
                        if (value > 11)
                            ++value;
                        if (value > 18)
                            ++value;
                        if (value > 25)
                            ++value;
                        outText.append(std::to_string(getWeaponHash(value)));
                        outText.append(" ");
                        break;
                    default:
                        pre = pos + 1;
                        pos = text.find_first_of(' ', pre);
                        if (pos != std::string::npos)
                        {
                            outText.append(text.substr(pre, pos - pre + 1));
                        }
                        else
                        {
                            outText.append(text.substr(pre));
                            outText.append(" ");
                            ++valueID;
                        }
                        break;
                }
                readValid = (pos != std::string::npos);
            }
            if (!readValid)
            {
                switch (valueID)
                {
                    case 0:
                        outText.append("2602752943 ");  // model = Franklin
                    case 1:
                        outText.append("0 ");  // Drawable 0
                    case 2:
                        outText.append("0 ");  // Drawable 0 texture
                    case 3:
                        outText.append("0 ");
                    case 4:
                        outText.append("0 ");
                    case 5:
                        outText.append("0 ");
                    case 6:
                        outText.append("0 ");
                    case 7:
                        outText.append("0 ");
                    case 8:
                        outText.append("0 ");
                    case 9:
                        outText.append("0 ");
                    case 10:
                        outText.append("0 ");
                    case 11:
                        outText.append("0 ");
                    case 12:
                        outText.append("0 ");
                    case 13:
                        outText.append("0 ");
                    case 14:
                        outText.append("0 ");
                    case 15:
                        outText.append("0 ");
                    case 16:
                        outText.append("0 ");
                    case 17:
                        outText.append("0 ");
                    case 18:
                        outText.append("0 ");
                    case 19:
                        outText.append("0 ");
                    case 20:
                        outText.append("0 ");
                    case 21:
                        outText.append("0 ");
                    case 22:
                        outText.append("0 ");
                    case 23:
                        outText.append("0 ");  // Drawable 11
                    case 24:
                        outText.append("0 ");  // Drawable 11 texture
                    case 25:
                        outText.append("-1 ");  // Drawable 12 (1st prop)
                    case 26:
                        outText.append("-1 ");
                    case 27:
                        outText.append("-1 ");
                    case 28:
                        outText.append("-1 ");
                    case 29:
                        outText.append("-1 ");
                    case 30:
                        outText.append("-1 ");
                    case 31:  // skip block
                    case 32:
                    case 33:
                    case 34:
                    case 35:
                    case 36:  //
                    case 37:
                        outText.append("-1 ");  // Drawable 15 (watch prop)
                    case 38:
                        outText.append("-1 ");  // Drawable 15 texture
                    case 39:                    // skip block
                    case 40:                    //
                    case 41:
                        outText.append("0xA2719263 ");  // weaponHash unarmed 0xA2719263
                    case 42:
                        outText.append("0 ");  // weaponTint
                    case 43:
                        outText.append("0 ");  // weaponMask
                        break;
                    default:  // case -1:
                        break;
                }
            }
            // Additional data
            if (isPlayer(modelID))
            {
                // -1 -1 x16
                outText.append(
                    "-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 ");
            }
            if (isFreemode(modelID))
            {
                // 0 0 0 0
                // 0 x 20
                // 0 0 0 0
                outText.append(std::to_string(mother));
                outText.append(" ");
                outText.append(std::to_string(father));
                outText.append(" ");
                outText.append(std::to_string(mix));
                outText.append(" ");
                outText.append(std::to_string(mix));
                outText.append(" 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ");
                outText.append(std::to_string(hair));
                outText.append(" ");
                outText.append(std::to_string(haircolor));
                outText.append(" ");
                outText.append(std::to_string(haircolor));
                outText.append(" -1 0 20 -1 0 20 -1 0 20 -1 0 20 -1 0 20 -1 0 20 -1 0 20 -1 0 20 -1 0 20 -1 0 20 -1 0 "
                               "20 -1 0 20 -1 0 20 ");
            }
        }
        // blank line or end of line with ' '
        outText.push_back('\n');
    }
    buffer.close();
    buffer.open(SAVEFILE, std::fstream::out | std::fstream::trunc);
    if (!buffer.is_open())
    {
        MM::notifyAboveMap("Could not write data file.");
        return false;
    }
    buffer.write(outText.c_str(), outText.size() - 1);
    buffer.close();
    return true;
}

// convert v2.0 to v2.1
bool convertDataFile2_1()
{
    std::string text;
    std::string outText = "";
    std::string tempText = "";
    std::fstream buffer(SAVEFILE, std::fstream::in);
    if (!buffer.is_open())
    {
        MM::notifyAboveMap("Count not open data file.");
        return false;
    }
    std::getline(buffer, text);
    outText.append("Skin Control.ini ");
    outText.append(VERSION);
    std::getline(buffer, text);
    outText.push_back('\n');
    outText.append("Hotkey: ");
    outText.append(std::to_string(HOTKEY));
    outText.push_back('\n');
    for (int i = 0; i < numSaves; i++)
    {
        std::getline(buffer, text);
        outText.append(text);
        outText.push_back('\n');
    }
    buffer.close();
    buffer.open(SAVEFILE, std::fstream::out | std::fstream::trunc);
    if (!buffer.is_open())
    {
        MM::notifyAboveMap("Could not write data file.");
        return false;
    }
    buffer.write(outText.c_str(), outText.size() - 1);
    buffer.close();
    return true;
}

int checkDataFile(int& hotkey)
{
    std::string text;
    std::string text2;
    std::fstream buffer(SAVEFILE, std::fstream::in);
    if (!buffer.is_open())
    {
        initDataFile();
        return 0;
    }
    std::getline(buffer, text2);
    if (text2.size() < 17)
        return 2;
    text = text2.substr(17);
    std::getline(buffer, text2);
    buffer.close();
    if (0 == text.compare(VERSION))
    {
        if (text2.size() > 8)
            hotkey = std::stoi(text2.substr(8));
        return 0;
    }
    if (0 == text.compare("v2.1"))
    {
        if (text2.size() > 8)
            hotkey = std::stoi(text2.substr(8));
        return 0;
    }
    if (0 == text.compare("v2.0"))
        return 1;
    return 2;
}

void initDataFile()
{
    std::filebuf fs;
    fs.open(SAVEFILE, std::ios_base::out | std::ios_base::trunc);
    std::ostream os(&fs);
    os << SAVEFILE << " " << VERSION << std::endl;
    os << "Hotkey: " << HOTKEY << std::endl;
    for (int i = 0; i < numSaves; i++)
        os << std::endl;
    fs.close();
}

void peekNames(std::vector<std::string>* names)
{
    std::string str;
    std::ifstream buffer(SAVEFILE, std::ios_base::in);
    std::getline(buffer, str);
    std::getline(buffer, str);
    for (int i = 0; i < numSaves; i++)
    {
        std::getline(buffer, str);
        size_t pos = str.find_first_of('<');
        size_t pos2 = str.find_first_of('>');
        if (pos == std::string::npos || pos2 == std::string::npos)
        {
            names->at(i) = " ";
        }
        else
        {
            names->at(i) = str.substr(pos + 1, pos2 - pos - 1).c_str();
        }
    }
    buffer.close();
}

void loadSkin(int slot, PedSkin& skin, WeaponData& currentWeaponData, Hash& lastValidSkin, bool& nonDefaultSkin,
    std::vector<Entity>& weapon, std::vector<std::pair<Hash, int>>& ammoWeapon)
{
    if (loadPedInSlot(slot, skin))
    {  // save to skin
        Ped playerPed = PLAYER::PLAYER_PED_ID();
        Hash model = ENTITY::GET_ENTITY_MODEL(playerPed);
        setLastSkin(model, lastValidSkin);
        int index = hashLookup(skin.model);
        std::vector<Entity> weapons;
        std::vector<std::pair<Hash, int>> ammoWeapons;
        currentWeaponData = getWeaponComponentData(skin.weapon);
        if (0 == PED::IS_PED_HUMAN(playerPed))
        {
            weapons = weapon;
            ammoWeapons = ammoWeapon;
        }
        else
        {
            getWeaponsFromPed(playerPed, &weapons, &ammoWeapons, NULL);
        }
        renderPlayerSkin(skin, currentWeaponData, index, true, true, nonDefaultSkin);
        playerPed = PLAYER::PLAYER_PED_ID();
        if (0 == PED::IS_PED_HUMAN(playerPed))
        {
            weapon = weapons;
            ammoWeapon = ammoWeapons;
        }
        else
            setWeaponsOfPed(playerPed, &weapons, &ammoWeapons, skin.weapon);
    }
    else
        MM::notifyAboveMap("Load failed");
}

bool loadPedInSlot(int slot, PedSkin& skin)
{
    std::string text;
    std::ifstream buffer(SAVEFILE, std::ios_base::in);
    std::getline(buffer, text);
    std::getline(buffer, text);
    for (int i = 0; i < numSaves; i++)
    {
        std::getline(buffer, text);
        if (i == slot)
            break;
    }
    buffer.close();
    return pedSkinFromString(skin, text);
}

char* getSaveName()
{
    bool done = false;
    int status = 0;
    while (!done)
    {
        GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(TRUE, "Save Name", "", "Enter a name.", "", "", "", 64);
        while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0)
            WAIT(0);
        status = GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD();
        if (status == 1)
            done = true;
        else if (status == 2 || status == 3)
            return "";
    }
    return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}

bool saveSkin(int slot, PedSkin& skin)
{
    char* name = getSaveName();
    if (strcmp(name, "") == 0)
        return false;
    return saveSkinToSlot(slot, name, skin);
}

bool saveSkinToSlot(int slot, char* name, PedSkin& skin)
{
    std::string tempS = "";
    std::string text;
    std::fstream buffer(SAVEFILE, std::fstream::in);
    if (!buffer.is_open())
    {
        MM::notifyAboveMap("Could not read data file.");
        return false;
    }
    for (int i = 0; i < numSaves + 2; i++)
    {
        std::getline(buffer, text);
        if (i == slot + 2)
        {
            tempS.append(pedSkinAsString(skin, name));
            tempS.push_back('\n');
        }
        else
        {
            tempS.append(text);
            tempS.push_back('\n');
        }
    }
    buffer.close();
    buffer.open(SAVEFILE, std::fstream::out | std::fstream::trunc);
    if (!buffer.is_open())
    {
        MM::notifyAboveMap("Could not write data file.");
        return false;
    }
    buffer.write(tempS.c_str(), tempS.size());
    buffer.close();
    return true;
}

std::string pedSkinAsString(PedSkin& skin, std::string name)
{
    // int modelID = -1;
    int type = hashLookup(skin.model);
    std::string value = "";
    value.append("<" + name + ">");
    value.append(std::to_string(skin.model) + " ");
    for (int i = 0; i < numParts; i++)
    {
        value.append(std::to_string(skin.drawable[i]) + " ");
        value.append(std::to_string(skin.texture[i]) + " ");
    }
    value.append(std::to_string(skin.weapon) + " ");
    value.append(std::to_string(skin.weaponTint) + " ");
    value.append(std::to_string(skin.weaponModMask) + " ");
    // Tattoos
    if (isPlayer(type))
    {
        for (int i = 0; i < numTatSlots; ++i)
        {
            value.append(std::to_string(skin.tattoo[i].value) + " ");
            value.append(std::to_string(skin.tattoo[i].collection) + " ");
        }
    }  // Freemode extra data
    if (isFreemode(type))
    {
        // Parents
        value.append(std::to_string(skin.freemodeData.mother) + " ");
        value.append(std::to_string(skin.freemodeData.father) + " ");
        value.append(std::to_string(skin.freemodeData.faceRatio) + " ");
        value.append(std::to_string(skin.freemodeData.skinRatio) + " ");
        // Morphs
        for (int i = 0; i < numMorphs; ++i)
        {
            value.append(std::to_string(skin.freemodeData.morph[i]) + " ");
        }
        // Eye
        value.append(std::to_string(skin.freemodeData.eyeColor) + " ");
        // Hair
        value.append(std::to_string(skin.freemodeData.hair) + " ");
        value.append(std::to_string(skin.freemodeData.hairColor) + " ");
        value.append(std::to_string(skin.freemodeData.hairHighlights) + " ");
        // Overlay
        for (int i = 0; i < numFaceOverlays; ++i)
        {
            value.append(std::to_string(skin.freemodeData.overlay[i].value) + " ");
            value.append(std::to_string(skin.freemodeData.overlay[i].color) + " ");
            value.append(std::to_string(skin.freemodeData.overlay[i].opacity) + " ");
        }
    }
    return value;
}

bool pedSkinFromString(PedSkin& skin, std::string data)
{
    int modelID = -1;
    int type = -1;
    // <Savename>model frame1 texture1 frame2 texture2 ...
    size_t pos2 = 0;
    size_t pos = data.find_first_of('>');
    try
    {
        pos2 = pos + 1;
        pos = data.find_first_of(' ', pos + 1);
        skin.model = std::stoul(data.substr(pos2, pos - pos2), NULL);
        type = hashLookup(skin.model);
        for (int i = 0; i < numParts; i++)
        {
            pos2 = pos + 1;
            pos = data.find_first_of(' ', pos + 1);
            skin.drawable[i] = std::stoi(data.substr(pos2, pos - pos2), NULL);
            pos2 = pos + 1;
            pos = data.find_first_of(' ', pos + 1);
            skin.texture[i] = std::stoi(data.substr(pos2, pos - pos2), NULL);
        }
        pos2 = pos + 1;
        pos = data.find_first_of(' ', pos + 1);
        skin.weapon = std::stoul(data.substr(pos2, pos - pos2), NULL);
        pos2 = pos + 1;
        pos = data.find_first_of(' ', pos + 1);
        skin.weaponTint = std::stoul(data.substr(pos2, pos - pos2), NULL);
        pos2 = pos + 1;
        pos = data.find_first_of(' ', pos + 1);
        skin.weaponModMask = std::stoul(data.substr(pos2, pos - pos2), NULL);
        // Tattoos
        skin.tatsPreserve = false;
        if (isPlayer(type))
        {
            for (int i = 0; i < numTatSlots; ++i)
            {
                pos2 = pos + 1;
                pos = data.find_first_of(' ', pos + 1);
                skin.tattoo[i].value = std::stoi(data.substr(pos2, pos - pos2), NULL);
                pos2 = pos + 1;
                pos = data.find_first_of(' ', pos + 1);
                skin.tattoo[i].collection = std::stoi(data.substr(pos2, pos - pos2), NULL);
            }
            skin.tatsPreserve = true;
        }
        // Freemode extra data
        skin.fmPreserve = false;
        if (isFreemode(type))
        {
            // Parents
            pos2 = pos + 1;
            pos = data.find_first_of(' ', pos + 1);
            skin.freemodeData.mother = std::stoi(data.substr(pos2, pos - pos2), NULL);
            pos2 = pos + 1;
            pos = data.find_first_of(' ', pos + 1);
            skin.freemodeData.father = std::stoi(data.substr(pos2, pos - pos2), NULL);
            pos2 = pos + 1;
            pos = data.find_first_of(' ', pos + 1);
            skin.freemodeData.faceRatio = std::stoi(data.substr(pos2, pos - pos2), NULL);
            pos2 = pos + 1;
            pos = data.find_first_of(' ', pos + 1);
            skin.freemodeData.skinRatio = std::stoi(data.substr(pos2, pos - pos2), NULL);
            // Morphs
            for (int i = 0; i < numMorphs; ++i)
            {
                pos2 = pos + 1;
                pos = data.find_first_of(' ', pos + 1);
                skin.freemodeData.morph[i] = std::stoi(data.substr(pos2, pos - pos2), NULL);
            }
            // Non-overlay
            pos2 = pos + 1;
            pos = data.find_first_of(' ', pos + 1);
            skin.freemodeData.eyeColor = std::stoul(data.substr(pos2, pos - pos2), NULL);
            pos2 = pos + 1;
            pos = data.find_first_of(' ', pos + 1);
            skin.freemodeData.hair = std::stoi(data.substr(pos2, pos - pos2), NULL);
            pos2 = pos + 1;
            pos = data.find_first_of(' ', pos + 1);
            skin.freemodeData.hairColor = std::stoul(data.substr(pos2, pos - pos2), NULL);
            pos2 = pos + 1;
            pos = data.find_first_of(' ', pos + 1);
            skin.freemodeData.hairHighlights = std::stoul(data.substr(pos2, pos - pos2), NULL);
            // Overlay
            for (int i = 0; i < numFaceOverlays; ++i)
            {
                pos2 = pos + 1;
                pos = data.find_first_of(' ', pos + 1);
                skin.freemodeData.overlay[i].value = std::stoi(data.substr(pos2, pos - pos2), NULL);
                pos2 = pos + 1;
                pos = data.find_first_of(' ', pos + 1);
                skin.freemodeData.overlay[i].color = std::stoul(data.substr(pos2, pos - pos2), NULL);
                pos2 = pos + 1;
                pos = data.find_first_of(' ', pos + 1);
                skin.freemodeData.overlay[i].opacity = std::stoul(data.substr(pos2, pos - pos2), NULL);
            }
        }
        skin.fmPreserve = true;
    }
    catch (std::exception e)
    {
        MM::notifyAboveMap("Damaged data file.");
        return false;
    }
    return true;
}
