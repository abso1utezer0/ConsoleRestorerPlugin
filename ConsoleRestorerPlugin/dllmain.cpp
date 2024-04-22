#include "pch.h"
#include <Windows.h>
#include <iostream>

// Function to create a console window
void CreateConsole()
{
    AllocConsole();

    // Redirect stdout to the console
    FILE* pFile;
    freopen_s(&pFile, "CONOUT$", "w", stdout);
}

// Entry point
extern "C" BOOL WINAPI DllMain(HINSTANCE hinst, DWORD dwReason, LPVOID reserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        // Create console window
        CreateConsole();
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
    }

    return TRUE;
}