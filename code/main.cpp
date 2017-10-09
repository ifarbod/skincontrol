
#include "scripthookv/main.h"
#include "keyboard.h"
#include "script.h"

BOOL APIENTRY DllMain(HMODULE hInstance, DWORD reason, LPVOID lpReserved)
{
    switch (reason)
    {
        case DLL_PROCESS_ATTACH:
            scriptRegister(hInstance, ScriptMain);
            keyboardHandlerRegister(OnKeyboardMessage);
            break;
        case DLL_PROCESS_DETACH:
            scriptUnregister(ScriptMain);
            keyboardHandlerUnregister(OnKeyboardMessage);
            break;
    }
    return TRUE;
}
