#include "pch.h"
#include "script.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            scriptRegister(hModule, presencemod::onScriptInit);
            break;

        case DLL_PROCESS_DETACH:
            presencemod::onScriptExit();
            scriptUnregister(hModule);
            break;
    }

    return TRUE;
}

