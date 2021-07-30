/*
Skin Control script.h
By Neutrinobeam

v2.2
Converted parent faces under "Base Face" from numbers to names.
Converted options under "Face Detail" from numbers to names.
Corrected certain maximum values under "Face Detail".

v2.1
Tenative fix for crashes in FiveM.
If you have saved skins, rename "Skin Control.dat" to "Skin Control.ini".
Customizable keybind added, defaults as F8. Edit in "Skin Control.ini" in GTA directory after first launch.
Fixed a bug with saving skins writing bad face data.
Configured tats and freemode face data will be remembered in the menu for that play session.
Removed Mod Menu support (watch for an update from it.)

v2.0
Total layout change.

Added support for setting tattoos, but can't be read from characters.
Added support for setting additional freemode face options, but can't be read from characters.
Skin changes are now applied immediately (excluding weapon components.)
Use SELECT (Controller A, Enter, Space, Left Mouse) and BACK (Controller B, Backspace, Right Mouse) to advance/reverse
in menus when UP and DOWN are otherwise occupied. Dying or being arrested now switches to last used player skin.

Added support for Combat PDW, Knuckle Duster, and Marksman Pistol.
Weapons are maintained when dying or being arrested while not a player skin.
Weapons saved when switching to an animal skin, but will be lost on reload.
Weapons can be removed.
Equipped weapons now stored as hash instead of index (better for adding DLC weapons.)

Added more save slots.
More informative error messages when saving.
Save names can contain spaces now.
Changed the data file format, prior versions should auto update.
Removed unused prop slots.
*/
#ifndef SC_SCRIPT
#define SC_SCRIPT

#include "pedModel.h"
#include "scripthookv/enums.h"
#include "scripthookv/natives.h"
#include "scripthookv/types.h"

#include <vector>

#define VERSION "v2.2"
#define HOTKEY 0x75

const int numParts = 16;
const int firstProp = 12;
const int watchSlot = 6;
const int numTatSlots = 16;
const int numMorphs = 20;
const int numFaceOverlays = 13;  // no hair, no eyecolor
const int numOverlaySlots = 8;
const int numWeaponMods = 7;

struct WeaponData
{
    bool added;
    unsigned char maxSlots;
    unsigned char defaultMask;                  // Componentwise: 0-6
    std::vector<unsigned char> slotToCmpMap;    // Slotwise: 1 - maxSlots
    std::vector<unsigned char> cmpToHashIDMap;  // Componentwise: 0-6
    WeaponData()
    {
        slotToCmpMap.resize(numWeaponMods);
        cmpToHashIDMap.resize(numWeaponMods);
    }
    WeaponData(unsigned char mS, unsigned char dM, std::vector<unsigned char> sTCM, std::vector<unsigned char> cTHIM)
        : maxSlots(mS), defaultMask(dM), slotToCmpMap(sTCM), cmpToHashIDMap(cTHIM)
    {
        added = false;
    }
};

struct FaceOverlay
{
    int value;
    DWORD color;
    DWORD opacity;
};

struct FMFace
{
    int mother;
    int father;
    DWORD faceRatio;
    DWORD skinRatio;
    int* morph;
    DWORD eyeColor;
    int hair;
    DWORD hairColor;
    DWORD hairHighlights;
    FaceOverlay* overlay;

    FMFace()
    {
        morph = new int[numMorphs];
        overlay = new FaceOverlay[numFaceOverlays];
    };
    ~FMFace()
    {
        delete[] morph;
        delete[] overlay;
    };
};

struct Tattoo
{
    int value;
    int collection;
};

int hashLookup(Hash hex);

struct PedSkin
{
    Hash model;
    int* drawable;
    int* texture;
    Tattoo* tattoo;
    bool tatsPreserve;
    Hash weapon;
    DWORD weaponModMask;
    DWORD weaponTint;
    bool fmPreserve;
    FMFace freemodeData;

    PedSkin()
    {
        drawable = new int[numParts];
        texture = new int[numParts];
        tattoo = new Tattoo[numTatSlots];
        model = -1;
        fmPreserve = false;
        tatsPreserve = false;
    };
    ~PedSkin()
    {
        delete[] drawable;
        delete[] texture;
        delete[] tattoo;
    }
};

void ScriptMain();
void Main();

void setNondefaultSkin(int skinIndex, bool& nonDefaultSkin);
void setLastSkin(Hash model, Hash& lastValidSkin);
void updateFeatures(bool& nonDefaultSkin, Hash lastValidSkin);
void checkPlayerModel(bool& nonDefaultSkin, Hash lastValidSkin);
void resetGlobals(int& convertFile);

#endif
