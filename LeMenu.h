#pragma once
#include "stdafx.h"

#include <iostream>

#include <vector>

#include <Windows.h>

#include "proc.h"

#include <stdio.h>

#include <string>

#include "Shit.h"

#include "Xor.h"

#include "Colours.h"

using namespace std;

void Main();

void Menu()
{

    bool infAmmo = false;
    bool infHealth = false;
    bool infTimer = false;
 
    //Get ProcId of the target process
    DWORD procId = GetProcId(L"ChaosGame424-Win64-Shipping.exe");
    //Getmodulebaseaddress
    uintptr_t moduleBase = GetModuleBaseAddress(procId, L"ChaosGame424-Win64-Shipping.exe");
    //Get Handle to Process
    HANDLE hProcess = 0;
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

    if (procId != NULL)
    {
        SetColor(GREEN);
        log(_xor_(" Chaos process obtained!\n\n").c_str());
    }
    else
    {
        log(_xor_(" Unable to get Process ID, please relaunch the program, and open the game!\n\n").c_str());
    }

    SetColor(WHITE);
    log(_xor_(" (F1) - Infinite Ammo\n").c_str());
    log(_xor_(" (F2) - Infinite Health\n").c_str());
    log(_xor_(" (F3) - Game Never Ends\n").c_str());
    log(_xor_(" (Backspace) - Go Back to the main menu\n").c_str());
    log(_xor_(" (F5) - Disable all\n\n").c_str());

   


    while (true)
    {

        if (GetAsyncKeyState(VK_F1) & 1)
        {
            infAmmo = !infAmmo;
        }

        if (GetAsyncKeyState(VK_F2) & 1)
        {
           infHealth = !infHealth;
        }


        if (GetAsyncKeyState(VK_F3) & 1)
        {
             infTimer = !infTimer;
        }

        if (GetAsyncKeyState(VK_BACK) & 1)
        {
            system("CLS");
            Main();
        }

        if (GetAsyncKeyState(VK_F5) & 1)
        {
            infAmmo = false;
            infHealth = false;
            infTimer = false;
        }

        if (infAmmo == true)
        {
            //Resolve base address of the pointer chain
            uintptr_t dynamicPtrBaseAddr = moduleBase + 0x03450F88;
            //Resolve our ammo pointer chain
            std::vector < unsigned int > ammoOffsets = {
              0x50,
              0x0,
              0x248,
              0x974
            };
            uintptr_t ammoAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, ammoOffsets);
            //Read Ammo value
            int ammoValue = 0;
            ReadProcessMemory(hProcess, (BYTE*)ammoAddr, &ammoValue, sizeof(ammoValue), nullptr);
            //Write to it
            int newAmmo = 1337;
            WriteProcessMemory(hProcess, (BYTE*)ammoAddr, &newAmmo, sizeof(newAmmo), nullptr);
        }


        else if (infHealth == true)
        {
            //Resolve base address of the pointer chain
            uintptr_t dynamicPtrBaseAddr = moduleBase + 0x035CC570;
            //Resolve our ammo pointer chain
            std::vector < unsigned int > HealthOffsets = {
              0x0,
              0xA0,
              0x8B0
            };
            uintptr_t HealthAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, HealthOffsets);
            //Read Ammo value
            float HealthValue = 0;
            ReadProcessMemory(hProcess, (BYTE*)HealthAddr, &HealthValue, sizeof(HealthValue), nullptr);
            //Write to it
            float newHealth = 1000;
            WriteProcessMemory(hProcess, (BYTE*)HealthAddr, &newHealth, sizeof(newHealth), nullptr);
        }

        else  if (infTimer == true)
        {
            uintptr_t dynamicPtrBaseAddr = moduleBase + 0x035DEF98;
            std::vector < unsigned int > TimerOffsets = {
              0x488,
              0x128,
              0x310
            };
            uintptr_t TimerAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, TimerOffsets);
            //Read Ammo value
            int TimerValue = 0;
            ReadProcessMemory(hProcess, (BYTE*)TimerAddr, &infTimer, sizeof(infTimer), nullptr);
            //Write to it
            float newTimer = 999;
            WriteProcessMemory(hProcess, (BYTE*)TimerAddr, &newTimer, sizeof(newTimer), nullptr);
        }
    }
}

