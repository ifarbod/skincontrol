/*
Skin Control
facedata.cpp
By Neutrinobeam
*/

#pragma once
#include "facedata.h"
#include "menu.h"

void updateFMFace(PedSkin& skin, int type)
{
    if (!isFreemode(type))
        return;
    Ped pedID = PLAYER::PLAYER_PED_ID();
    setPedHeadBlend(skin, pedID);
    for (int i = 0; i < numMorphs; ++i)
    {
        setPedHeadMorph(skin, pedID, i);
    }
    for (int i = -2; i < numFaceOverlays; ++i)
    {
        setPedFreemodeOverlay(skin, pedID, i, type);
    }
}

int gameToInternal(int iID)
{
    switch (iID)
    {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 8;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 6;
        case 6:
            return 12;
        case 7:
            return 13;
        case 8:
            return 7;
        case 9:
            return 11;
        case 10:
            return 14;
        case 11:
            return 5;
        case 12:
            return 4;
        case 13:
            return 9;
        case 14:
            return 10;
    }
    return -1;
}

int internalToGame(int iID)
{
    switch (iID)
    {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 10;
        case 3:
            return 9;
        case 4:
            return 3;
        case 5:
            return 6;
        case 6:
            return 0;
        case 7:
            return 11;
        case 8:
            return 12;
        case 9:
            return 7;
        case 10:
            return 4;
        case 11:
            return 5;
        case 12:
            return 8;
        default:
            return -1;
    }
}

void getFreeModeFace(PedSkin& skin, int type, bool global)
{
    if (!isFreemode(type) || skin.fmPreserve)
    {
        return;
    }
    Ped id = PLAYER::PLAYER_PED_ID();
    HeadBlend temp;
    int val;
    if (global)
    {
        PED::_GET_PED_HEAD_BLEND_DATA(id, (Any*)&temp);
        if (temp.faceMother >= PED::_GET_FIRST_PARENT_ID_FOR_PED_TYPE(3))
            skin.freemodeData.mother =
                temp.faceMother - PED::_GET_FIRST_PARENT_ID_FOR_PED_TYPE(3) + PED::_GET_NUM_PARENT_PEDS_OF_TYPE(1);
        else
            skin.freemodeData.mother = temp.faceMother - PED::_GET_FIRST_PARENT_ID_FOR_PED_TYPE(1);
        if (temp.faceFather >= PED::_GET_FIRST_PARENT_ID_FOR_PED_TYPE(2))
            skin.freemodeData.father =
                temp.faceMother - PED::_GET_FIRST_PARENT_ID_FOR_PED_TYPE(2) + PED::_GET_NUM_PARENT_PEDS_OF_TYPE(0);
        else
            skin.freemodeData.father = temp.faceFather - PED::_GET_FIRST_PARENT_ID_FOR_PED_TYPE(0);
        skin.freemodeData.faceRatio = SYSTEM::ROUND(temp.faceBlend * 16);
        skin.freemodeData.skinRatio = SYSTEM::ROUND(temp.skinBlend * 16);
        // I gave up. This part of the scripts is insane and looked like it was pulling the data
        // from Rockstar’s servers which I wanted to avoid.
        for (int i = 0; i < numMorphs; ++i)
        {
            skin.freemodeData.morph[i] = 0;
        }
        skin.freemodeData.eyeColor = 0;
        skin.freemodeData.hair = PED::GET_PED_DRAWABLE_VARIATION(id, 2);
        skin.freemodeData.hairColor = PED::GET_PED_TEXTURE_VARIATION(id, 2);
        skin.freemodeData.hairHighlights = skin.freemodeData.hairColor;
        for (int i = 0; i < numFaceOverlays; ++i)
        {
            val = PED::_GET_PED_HEAD_OVERLAY_VALUE(id, internalToGame(i));
            if (val == 255)
                skin.freemodeData.overlay[i].value = -1;
            else
                skin.freemodeData.overlay[i].value = val;
            skin.freemodeData.overlay[i].color = 0;
            skin.freemodeData.overlay[i].opacity = 20;
        }
    }
    else
    {
        skin.freemodeData.mother = 0;
        skin.freemodeData.father = 0;
        skin.freemodeData.faceRatio = SYSTEM::ROUND((type - 3) * 16);
        skin.freemodeData.skinRatio = SYSTEM::ROUND((type - 3) * 16);
        for (int i = 0; i < numMorphs; ++i)
        {
            skin.freemodeData.morph[i] = 0;
        }
        skin.freemodeData.eyeColor = 0;
        skin.freemodeData.hair = PED::GET_PED_DRAWABLE_VARIATION(id, 2);
        skin.freemodeData.hairColor = PED::GET_PED_TEXTURE_VARIATION(id, 2);
        skin.freemodeData.hairHighlights = skin.freemodeData.hairColor;
        for (int i = 0; i < numFaceOverlays; ++i)
        {
            skin.freemodeData.overlay[i].value = -1;
            skin.freemodeData.overlay[i].color = 0;
            skin.freemodeData.overlay[i].opacity = 20;
        }
    }
}

void setPedHeadBlend(PedSkin& skin, Ped pedID)
{
    int dad = skin.freemodeData.father;
    int mom = PED::_GET_FIRST_PARENT_ID_FOR_PED_TYPE(1) + skin.freemodeData.mother;
    if (dad >= PED::_GET_NUM_PARENT_PEDS_OF_TYPE(0))
    {
        dad = (dad - PED::_GET_NUM_PARENT_PEDS_OF_TYPE(0)) + PED::_GET_FIRST_PARENT_ID_FOR_PED_TYPE(2);
    }
    if (mom >= PED::_GET_NUM_PARENT_PEDS_OF_TYPE(1) + PED::_GET_FIRST_PARENT_ID_FOR_PED_TYPE(1))
    {
        mom = mom - PED::_GET_NUM_PARENT_PEDS_OF_TYPE(1) - PED::_GET_FIRST_PARENT_ID_FOR_PED_TYPE(1) +
              PED::_GET_FIRST_PARENT_ID_FOR_PED_TYPE(3);
    }
    PED::SET_PED_HEAD_BLEND_DATA(pedID, mom, dad, 0, mom, dad, 0, (float)(skin.freemodeData.faceRatio) / 16.0f,
        (float)(skin.freemodeData.skinRatio) / 16.0f, 0.0f, 0);
}

void setPedHeadMorph(PedSkin& skin, Ped pedID, int id)
{
    switch (id)
    {
        case 0:
        case 7:
        case 9:
        case 10:
        case 13:
        case 14:
        case 16:
        case 18:
            PED::_SET_PED_FACE_FEATURE(pedID, id, (float)skin.freemodeData.morph[id] / 10.0);
            break;
        case 19:  // absolute
            PED::_SET_PED_FACE_FEATURE(pedID, id, (float)(skin.freemodeData.morph[id] + 10) / 20.0);
            break;
        default:  // reverse
            PED::_SET_PED_FACE_FEATURE(pedID, id, (float)skin.freemodeData.morph[id] / -10.0);
            break;
    }
}

int internalToColorType(int iID, int type)
{
    switch (iID)
    {
        case oEyebrowID:
        case oBeardID:
        case oChestID:
            return 1;
        case oBlushID:
        case oLipstickID:
            return 2;
        default:
            return 0;
    }
}

// maleDisplay   "Hair", "Eyebrow", "Eyecolor", "Beard", "ChestHair", "Mole", "Ageing", "Complexion", "Blemishes", "Body
// Blem.", "Add Body Blem.", "SunDam", "Eyeliner",          "Lipstick" }; femaleDisplay "Hair", "Eyebrow", "Eyecolor",
// "Mole", "Ageing", "Complexion", "Blemishes", "Body Blem.", "Add Body Blem.", "SunDam", "Eyeliner", "Blush",
// "Lipstick" }; internal     /"Hair", "Eyecolor",/"Eyebrow", "Beard", "ChestHair", "Mole", "Ageing", "Complexion",
// "Blemishes", "Body Blem.", "Dense Body Blem.", "SunDam", "Makeup", "Blush", "Lipstick"}; game
// "Blemishes", "Beard", "Eyebrow", "Ageing", "Makeup", "Blush", "Complexion", "SunDam", "Lipstick", "Mole",
// "ChestHair", "Body Blemishes", "Dense Body Blemishes",

void setPedFreemodeOverlay(PedSkin& skin, Ped pedID, int id, int type)
{
    switch (id)
    {
        case oHairID:
            PED::SET_PED_COMPONENT_VARIATION(
                pedID, 2, skin.freemodeData.hair, 0, PED::GET_PED_PALETTE_VARIATION(pedID, 2));
            PED::_SET_PED_HAIR_COLOR(pedID, skin.freemodeData.hairColor, skin.freemodeData.hairHighlights);
            break;
        case oEyeID:
            PED::_SET_PED_EYE_COLOR(pedID, SYSTEM::ROUND((float)skin.freemodeData.eyeColor));
            break;
        case oEyebrowID:
        case oBeardID:
        case oChestID:
        case oLipstickID:
        case oBlushID:
            if (skin.freemodeData.overlay[id].value > -1)
            {
                PED::SET_PED_HEAD_OVERLAY(pedID, internalToGame(id), skin.freemodeData.overlay[id].value,
                    (float)skin.freemodeData.overlay[id].opacity / 20.0);
                PED::_SET_PED_HEAD_OVERLAY_COLOR(pedID, internalToGame(id), internalToColorType(id, type),
                    skin.freemodeData.overlay[id].color, skin.freemodeData.overlay[id].color);
            }
            else
            {
                PED::SET_PED_HEAD_OVERLAY(pedID, internalToGame(id), 0, 0.0f);
                PED::_SET_PED_HEAD_OVERLAY_COLOR(pedID, internalToGame(id), internalToColorType(id, type), 0, 0);
            }
            break;
        default:
            if (skin.freemodeData.overlay[id].value > -1)
            {
                PED::SET_PED_HEAD_OVERLAY(pedID, internalToGame(id), skin.freemodeData.overlay[id].value,
                    (float)skin.freemodeData.overlay[id].opacity / 20.0);
            }
            else
            {
                PED::SET_PED_HEAD_OVERLAY(pedID, internalToGame(id), 0, 0.0f);
            }
            break;
    }
}
