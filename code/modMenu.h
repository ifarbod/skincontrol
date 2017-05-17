/* Mod Menu Interface File v1.5 */
// NeutrinoBeam
//
//
// You may modify for use in your mods.

#ifndef MODMENU_MODMENU_H
#define MODMENU_MODMENU_H

#pragma once

#include "scripthookv/natives.h"
#include <string>

#pragma warning(disable : 4244 4305)

namespace MM
{

	/* Input */

	// The Inputs are a simplified layer to allow your mod to navigate its menus.
	// Use MM::Input value = MM::getInput() to get the physical input among the below.
	// WASD, Arrow Keys, Controller Left Stick, Controller Dpad : corresponding movement
	// Space, Enter, Controller A : SELECT
	// Escape, Backspace, Controller B : BACK
	// Left Control, Controller X: OPTION
	// The movement Inputs will scroll if held down, SELECT, OPTION, and BACK will not.
	enum Input { NONE, SELECT, BACK, LEFT, RIGHT, UP, DOWN, OPTION };

	// The keyboard, mouse, and/or controller will trigger multiple Controls for each physical input.
	// A given Control may be associated with multiple physical inputs, for instance "Forward (32)"
	// is triggered by both left stick up and the W key.
	enum Control {
		None = -1,

		/*Inputs*/							// Triggered by (Defaults)
		MenuDown = 187,						// ArrowDown + Controller Pad Down
		MenuUp = 188,						// ArrowUp + Controller Pad Up
		MenuLeft = 189,						// ArrowLeft + Controller Pad Left
		MenuRight = 190,					// ArrowRight + Controller Pad Right
		//MenuRDown = 191,					// Enter + Controller A
		//MenuRUp = 192,					// Tab + Controller Y
		//MenuRLeft = 193,					// Space + Controller X
		//MenuRRight = 194,					// Backspace + Controller B
		//MenuAxisX = 195,					// A? + D + Controller RB? + Controller LB + Controller Left Left? + Controller Left Right
		//MenuAxisY = 196,					// W? + S + Controller Left Up? + Controller Left Down
		//MenuRAxisX = 197,					// [? + ] + Controller Right Left? + Controller Right Right
		//MenuRAxisY = 198,					// MouseWheel Up? + MouseWheel Down + Controller Right Up? + Controller Right Down
		//Escape = 200,						// Escape
		//MenuAccept = 201,					// Enter + NumPadEnter + Controller A
		//MenuCancel = 202,					// Escape + Backspace + Controller B
		//MenuXPos = 203,					// Space + Mouse? + Controller X
		//MenuYPos = 204,					// Tab + Mouse? + Controller Y
		//MenuLB = 205,						// Q + Controller LB
		//MenuRB = 206,						// E + Controller RB
		//MenuLT = 207,						// PageDown + Controller LT
		//MenuRT = 208,						// PageUp + Controller RT
		//MenuLIn = 209,					// LeftShift + Controller L3
		//MenuRIn = 210,					// LeftCtrl + Controller R3
		//MenuLeaderboard = 211,			// Tab + Controller RB
		//MenuSocialClub = 212,				// Home + Controller Back
		//MenuSocialClubSecond = 213,		// Controller RB
		//MenuDelete = 214,					// Delete + Controller X
		//MenuEndAccept = 215,				// Enter + Controller A
		//MenuEndExpand = 216,				// Space + Controller X
		//MenuSelect = 217					// CapsLock + Controller Back

		/* Script Inputs */
		//ControllerLAxisX = 218,			// A? + D + Controller Left Left? + Controller Left Right
		//ControllerLAxisY = 219,			// W? + S + Controller Left Up? + Controller Left Down
		//ControllerRAxisX = 220,			// Controller Right Left? + Controller Right Right
		//ControllerRAxisY = 221,			// Controller Right Up? + Controller Right Down
		//ControllerRUp = 222,				// MouseRight + Controller Y
		//ControllerRDown = 223,			// MouseLeft + Controller A
		ControllerRLeft = 224,			// LeftCtrl + Controller X
		//ControllerRRight = 225,			// MouseRight + Controller B
		//ControllerLeftBumper = 226,		// Controller LB
		//ControllerRightBumper = 227,		// Controller RB
		//ControllerLeftTrigger = 228,		// Controller LT
		//ControllerRightTrigger = 229,		// MouseLeft + Controller RT
		//ControllerLeftIn = 230,			// Controller L3
		//ControllerRightIn = 231,			// Controller R3
		//ControllerPadUp = 232,			// W + Controller Pad Up
		//ControllerPadDown = 233,			// S + Controller Pad Down
		//ControllerPadLeft = 234,			// A + Controller Pad Left
		//ControllerPadRight = 235,			// D + Controller Pad Right
		//ControllerSelect = 236,			// V + Controller Back

		/* Special Inputs */
		//LookZoom = 0,						// V + Controller Back
		//LookLeftRight = 1,				// Mouse? + Controller Right Stick
		//LookUpDown = 2,					// Mouse? + Controller Right Stick
		//LookUp = 3, //272					// Mouse? + Controller Right Up
		//LookDown = 4, //273				// Mouse? + Controller Right Down
		//LookLeft = 5, //270				// Mouse? + Controller Right Left
		//LookRight = 6, //271				// Mouse? + Controller Right Right
		//ScaledLookLeftRight = 290,
		//ScaledLookUpDown = 291,
		//ScaledLookUp = 293,
		//ScaledLookDown = 294,
		//ScaledLookLeft = 295,
		//ScaledLookRight = 296,
		SkipCutscene = 18,					//Space + Enter + Controller A + Left Mouse
		//CharSwap = 19,					// Left Alt + Controller Pad Down
		//RadarZoom = 48,					// Z + Controller Pad Down
		//Pickup = 38,						// E + Controller LB
		//TalkTo = 46,						// E + Controller Pad Right
		//ContextAction = 51,				// E + Controller Pad Right
		//SwapMichael = 166,				// F5
		//SwapFranklin = 167,				// F6
		//SwapTrevor = 168,					// F7
		//CancelActionPlay = 170,			// F3 + Controller B
		//ToggleSpecial = 171,				// CapsLock
		//Pause = 199,						// P + Controller Start
		//QuickMenu = 244,					// M + Controller Back
		//ToggleRecording = 288,			// F1 + Controller A
		//ToggleActionPlay = 289,			// F2 + Controller X

		/*On Foot Motion*/
		//Sprint = 21,						// LeftShift + Controller A
		//Jump = 22,						// Space + Controller X
		//EnterVehicle = 23,				// F + Controller Y
		//Fire = 24, //257					// MouseLeft + Controller RT
		//Aim = 25,							// MouseRight + Controller LT
		LookBack = 26,					// C + Controller R3
		//Special = 28,						// Controller L3
		//SpecialSecond = 29,				// B + Controller R3
		//MoveUpDown = 31,					// W? + S + Controller Left Stick
		MoveUp = 32, //268					// W + Controller Left Up
		MoveDown = 33, //269				// S + Controller Left Down
		//MoveLeftright = 30,				// A? + D + Controller Left Stick
		MoveLeft = 34, //266				// A + Controller Left Left
		MoveRight = 35, //267				// D + Controller Left Right
		//Stealth = 36,						// LeftCtrl + Controller L3
		//Cover = 44,						// Q + Controller RB
		//Detonate = 47,					// G + controller Pad Left
		//Dive = 55,						// Space + Controller RB
		//QuickGrenade = 58,				// G + Controller Pad Left
		//MeleeLight = 140, //263			// R + Controller B
		//MeleeHeavy = 141, //264			// Q + Controller A
		//MeleeAlt = 142,					// MouseLeft + Controller RT
		//MeleeDodge = 143,					// Space + Controller X

		/*On Foot Weapon*/
		//WeaponInSlotNext = 14, //262		// MouseWheelDown + Controller RT + Controller Pad Right
		//WeaponInSlotPrevious = 15, //261	// MouseWheelUp + Controller LT + Controller Pad Left
		//WeaponNext = 16,					// MouseWheelDown
		//WeaponPrevious = 17,				// MouseWheelUp
		WeaponWheel = 37,					// Tab + Controller LB
		//Zoom = 39,						// [ + MouseWheelDown + Controller R3 + Controller Left Down
		//ZoomIn = 40, //42, 274, 276		// ] + MouseWheelUp + Controller Left Up
		//ZoomOut = 41, //43, 275, 277		// [ + MouseWheelDown + Controller Left Down
		//Reload = 45,						// R + Controller B
		//AccurateAim = 50,					// [ + MouseWheelDown + Controller R3
		//ToggleWeaponAccessory = 54,		// E + Controller Pad Right
		//WeaponSlotUnarmed = 157,			// 1
		//WeaponSlotMelee = 158,			// 2
		//WeaponSlotPistol = 159,			// 6
		//WeaponSlotShotgun = 160,			// 3
		//WeaponSlotSMG = 161,				// 7
		//WeaponSlotAssault = 162,			// 8
		//WeaponSlotSniper = 163,			// 9
		//WeaponSlotHeavy = 164,			// 4
		//WeaponSlotGrenade = 165,			// 5

		/*Cars, Bikes, & Boats*/
		//CinematicSlow = 7,				// L + Controller R3
		//CinematicCamera = 80,				// R + Controller B
		//CinematicUpDown = 95,				// Mouse? + Controller Right Stick?
		//CinematicUp = 96,					// NumPad+ + MouseWheelUp
		//CinematicDown = 97,				// NumPad- + MouseWheelDown
		//CinematicLeftRight = 98,			// Mouse? + Controller Right Stick?
		//SteerLeftRight = 59,				// A? + D + Controller Left Stick
		//LeanFrontBack = 60,				// LeftShift? + LeftCtrl + NumPad8? + NumPad5 + Controller Left Stick
		//LeanForward = 61, //280			// LeftShift + NumPad8 + Controller Left Up
		//LeanBackward = 62, //281			// LeftCtrl + NumPad5 + Controller Left Down
		//SteerLeft = 63, //278				// A + Controller Left Left
		//SteerRight = 64, //279			// D + Controller Right Left
		//DrivebyAim = 68,					// MouseRight + Controller LB
		//DrivebyFire = 69, //70,			// MouseLeft + Controller RB
		//PassengerAim = 91,				// MouseRight + Controller LT
		//PassengerFire = 92,				// MouseLeft + Controller RT
		//Accelerate = 71,					// W + Controller RT
		//Brake = 72,						// S + Controller LT
		//Duck = 73,						// X + Controller A
		//Headlights = 74,					// H + Controller Pad Right
		//Roof = 101,						// H + Controller Pad Right
		//RadioShuffle = 104,				// H + Controller Pad Right
		//ExitVehicle = 75,					// F + Controller Y
		//Handbrake = 76,					// Space + Controller RB
		//BikeJump = 102,					// Space + Controller RB
		//LookBackVehicle = 79,				// C + Controller R3
		//RadioWheelUpDown = 332,			// Controller Right Up? + Controller Right Down
		//RadioWheelLeftright = 333,		// Controller Right Left? + Controller Right Right
		//RadioNext = 81,					// . + MouseWheel Down
		//RadioPrevious = 82,				// ,
		//RadioPCNext = 83,					// =
		//RadioPCPrevious = 84,				// -
		//RadioWheel = 85,					// Q + Controller Pad Left
		//Horn = 86,						// E + Controller L3
		//WeaponNextVehicle = 99,			// Tab + MouseWheel Up + Controller X
		//WeaponPreviousVehicle = 100,		// [
		//MouseDrive = 106,					// MouseLeft
		//BikePedal = 136,					// W + Controller A
		//BikeSprint = 137,					// CapsLock + Controller A
		//BikeFrontBrake = 138,				// Q + Controller LT
		//BikeBackBreak = 139,				// S + Controller RT
		//VehAimLeft = 282,					// Mouse? + Controller Right Left? + Controller Right Right?
		//VehAimRight = 283,				// Mouse? + Controller Right Left? + Controller Right Right?
		//VehAimUp = 284,					// Mouse? + Controller Right Up? + Controller Right Right?
		//VehAimDown = 285,					// Mouse? + Controller Right Down? + Controller Right Right?
		//VehLookLeft = 286,				// Mouse? + Controller Right Left? + Controller Right Right?
		//VehLookRight = 287,				// Mouse? + Controller Right Left? + Controller Right Right?
		//JumpSpeedUpDown = 334,			// PageUp? + PageDown + MouseWheel Up? + MouseWheel Down + Controller Right Up? + Controller Right Down
		//JumpSpeedUp = 335,				// PageUp + MouseWheel Up
		//JumpSpeedDown = 336,				// PageDown + MouseWheel Down

		/*Planes & Helicopters*/
		//AirThrottleUp = 87,				// W + Controller RT
		//AirThrottleDown = 88,				// S + Controller LT
		//AirLeft = 89,						// A + Controller LB
		//AirRight = 90,					// D + Controller RB
		//AirHook = 103,					// E + Controller Pad Right
		//AirDropPayload = 105,				// X + Controller A
		//AirRollLR = 107,					// NumPad4? + NumPad6 + Controller Left Left? + Controller Left Right
		//AirRollLeft = 108,				// NumPad4 + Controller Left Left
		//AirRollRight = 109,				// NumPad6 + Controller Left Right
		//AirPitchFrontBack = 110,			// NumPad8? + NumPad5 + Controller Left Up? + Controller Left Down
		//AirPitchForward = 111,			// NumPad8 + Controller Left Up
		//AirPitchBackward = 112,			// NumPad5 + Controller Left Down
		//AirLandingGear = 113,				// G + Controller L3
		//AirFire = 114,					// Space + MouseRight + Controller A
		//AirFireAlt = 331,					// Space + MouseRight
		//AirNextWeapon = 115,				// Tab + MouseWheel Up + Controller Pad Left
		//AirPreviousweapon = 116,			// [
		//AirAimLeft = 117,					// NumPad7 + Controller LB
		//AirAimRight = 118,				// NumPad9 + Controller RB
		//AirVTOL = 119,					// E + Controller Pad Right
		//AirDuck = 120,					// X + Controller A
		//AirWeaponCamera = 121,			// Insert + Controller R3
		//AirMouseDrive = 122,				// MouseLeft

		/*Submarine*/
		//SubLeftRight = 123,				// NumPad4? + NumPad6 + Controller Left Left? + Controller Left Right
		//SubLeft = 124,					// NumPad4 + Controller Left Left
		//SubRight = 125,					// NumPad6 + Controller Left Right
		//SubPitchFrontBack = 126,			// NumPad5 + NumPad8? + Controller Left Up? + Controller Left Down
		//SubPitchForward = 127,			// NumPad8 + Controller Left Up
		//SubPitchBackward = 128,			// NumPad5 + Controller Left Down
		//SubThrottleUp = 129,				// W + Controller RT
		//SubThrottleDown = 130,			// S + Controller LT
		//SubUp = 131,						// LeftShift + Controller X
		//SubDown = 132,					// LeftCtrl + Controller A
		//SubHardLeft = 133,				// A? + Controller LB
		//SubHardRight = 134,				// S + Controller RB
		//SubMouseDrive = 135,				// MouseLeft

		/*Parachute*/
		//ChuteDeploy = 144,				// F + MouseLeft + Controller A
		///ChuteDetach = 145,				// F + Controller Y
		//ChuteLeftRight = 146,				// A? + D + Controller Left Left? + Controller Left Right
		//ChuteLeft = 147,					// A? + Controller Left Left
		//ChuteRight = 148,					// D + Controller Left Right
		//ChuteForwardBackward = 149,		// W? + S + Controller Left Up? + Controller Left Down
		//ChuteForward = 150,				// W + Controller Left Up
		//ChuteBackward = 151,				// S + Controller Left Down
		//ChuteHardLeft = 152,				// Q + Controller LB
		//ChuteHardRight = 153,				// E + Controller RB
		//ChuteSmoke = 154,					// X + Controller A
		//ChuteFineControl = 155,			// LeftShift + Controller LB & RB?

		/*Phone*/
		//PhoneOn = 27,						// ArrowUp + MouseMiddle + Controller Pad Up
		//PhoneUp = 172,					// ArrowUp + Controller Pad Up
		//PhoneDown = 173,					// ArrowDown + Controller Pad Down
		//PhoneLeft = 174,					// ArrowLeft + Controller Pad Left
		//PhoneRight = 175,					// ArrowRight + Controller Pad Right
		//PhoneSelect = 176,				// Enter + MouseLeft + Controller A
		PhoneCancel = 177,					// Escape + Backspace + MouseRight + Controller B
		//PhoneOption = 178,				// Delete + Controller Y
		//PhoneAltOption = 179,				// Space + MouseMiddle + Controller X
		//PhoneScrollRight = 180,			// MouseWheel Down
		//PhoneScrollLeft = 181,			// MouseWheel Up
		//PhoneCamLockFocus = 182,			// L + Controller RT
		//PhoneCamGrid = 183,				// G + Controller RB
		//PhoneCamMode = 184,				// E + MouseMiddle + Controller R3
		//PhoneCamDOF = 185,				// F
		//PhoneCamFace = 186,				// X + Controller L3

		/* Other */
		//MouseL = 237,					// MouseLeft
		//MouseR = 238,					// MouseRight
		//MousePosX = 239,				// Mouse?
		//MousePosY = 240,				// Mouse?
		//MouseWUp = 241,				// MouseWheel Up
		//MouseWDown = 242,				// MouseWheel Down
		//CheatCode = 243,				// Tilde
		//RappelJump = 258,				// Controller A
		//RappelLongJump = 259,			// Controller X
		//RappelSmashWindow = 260,		// Controller RT
		//Whistle = 256,				// Delete + Controller X
		//DriveLook = 329				// MouseLeft
		//DriveLookSecond = 330			// MouseRight
		//MapPOI = 337,
		//Arrest = 49,					// F + Controller Y
		//WeaponSpecial = 53,			// Controller Y
		//DropWeapon = 56,				// F9 + Controller Y
		//DropAmmo = 57,				// F10 + Controller B
		//VehHotwireLeft = 77			// W + Controller LT
		//VehHotwireRight = 78			// S + Controller RT
		//RightTrigger = 260,			// Controller RT
		//MouseLAndRightTrigger = 92,	// MouseLeft + Controller Rt
		//CreatorAccept = 255,			// Enter + Space + Controller A

		/* Custom Inputs */
		//Tilde = CheatCode,
		Select = SkipCutscene,
		Cancel = PhoneCancel,
	};

	/* void isolateControls() */
	// Call this before launching your UI to prevent the base game from catching input.
	// If you do not use, your character may "dance", the phone could be activated, etc.
	void isolateControls();
	// Does not disable pause, menu movement, or cancel.

	/* void isolateControlsExcludeCamera() */
	// Call this before launching your UI to prevent the base game from catching input.
	// Acts like isolateControls, but allows the base game to move the camera.
	void isolateControlsExcludeCamera();

	/* void resetControls() */
	// Call this to reactivate all inputs with the base game.
	// You should, but don't need to, call this when your mod closes its menus.
	void resetControls();

	/* Input getInput() */
	// Gets a simplified input from the game's native control system.
	// Call isolateControls() once before using getInput().
	Input getInput();


	/* Display */

	// A few helpers for drawing to the screen.
	// A note on positioning, the internal resolution appears to be fixed at 1280x720

	// A Hex has value 0 - 255, equivalently, 0x00 through 0xFF
	typedef unsigned char Hex;

	// A color is four 'Hex'es packed together in RGBA order, i.e. 0xrrggbbaa
	typedef unsigned int Color;

	// Gets the red component of a given color.
	Hex getRed(Color color);

	// Gets the green component of a given color.
	Hex getGreen(Color color);

	// Gets the blue component of a given color.
	Hex getBlue(Color color);

	// Gets the alpha (transparency) component of a given color.
	Hex getAlpha(Color color);

	// Gets the color with components red, green, blue, alpha.
	Color getColor(Hex red, Hex green, Hex blue, Hex alpha);

	/* void drawRect(float xPos, float yPos, float width, float height, Color backColor) */
	// Draws a filled in rectangle given its top-left corner, dimensions, and fill color.
	void drawRect(float xPos, float yPos, float width, float height, Color backColor);

	/* void drawRect(float xPos, float yPos, float width, float height, Hex red, Hex green, Hex blue, Hex alpha) */
	// Draws a filled in rectangle given its top-left corner, dimensions, and components of fill color.
	void drawRect(float xPos, float yPos, float width, float height, Hex red, Hex green, Hex blue, Hex alpha);

	/* void drawRectWithText(std::string caption, float rectWidth, float vertPadding, float rectTop, float rectLeft, float textLeft, bool center = false, Color textColor = 0xFFFFFFFF, float scale = 0.35, int font = 0, Color backColor = 0x0000009B) */
	// Draws a filled in rectangle overlaid with text.
	// std::string caption  	The text to render. Passing an empty string will cause unintended behavior. Use a space " " instead.
	// float rectWidth      	The width of the rectangle in pixels assuming the screen is 1280x720.
	// float vertPadding    	How far the rectangle should extend beyond the text vertically. Measured in pixels assuming the screen is 1280x720.
	// float rectTop			    The distance of the top of the rectangle from the top of the screen assuming the screen is 1280x720.
	// float rectLeft       	    The distance of the left of the rectangle from the left of the screen assuming the screen is 1280x720.
	// float textLeft       	    How far the text should be from the left side of the rectangle. Measured in pixels assuming the screen is 1280x720.
	// bool center				     If the text should be centered instead of left aligned.
	// Color textColor      	The desired color for the text. Defaults as 0xFFFFFFFF (white.)
	// float scale          	        The desired size/scale for the text. It appears to be preserved across external resolutions.
	//                      	            Every 0.05 of scale corresponds to about 2 pixels of vertical resolution of the internal 720. Defaults to 0.35.
	// int font             	        Display font. Defaults to 0 for the game default. Set to 1 for cursive.
	// Color backColor      	The desired color for the rectangle. Defaults as 0x0000009B (the game menu's default.)
	//
	void drawRectWithText(std::string caption, float rectWidth, float vertPadding, float rectTop, float rectLeft, float textLeft, bool center = false, Color textColor = 0xFFFFFFFF, float scale = 0.35, int font = 0, Color backColor = 0x0000009B);

	void drawRectWithText(std::string caption, float rectWidth, float vertPadding, float rectTop, float rectLeft, Color textColor = 0xFFFFFFFF, Color backColor = 0x0000009B);

	/* A stand in for Alexander Blade's implementation of the game default. */
	void draw_menu_line(std::string caption, float rectWidth, float vertPadding, float rectTop, float rectLeft, float textLeft, bool active, bool title, bool rescaleText = true);

	/* Puts a message up to 63 characters above the map. */
	void notifyAboveMap(std::string msg);

	// Audio

	void menu_beep();

	void playSound(DWORD collection, DWORD sound);

}

#endif
