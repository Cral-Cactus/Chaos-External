#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include "proc.h"
#include <stdio.h>
#include <string>
#include <cstdlib>
#include "LeMenu.h"

using namespace std;

char Hacks;
char Discord;
char Exit;

void Main()
{
        int MenuStatus{};
        log(_xor_(" Welcome to Chaos External by Nik.#9999 and Siloe#6969!\n\n").c_str());
        Sleep(40);
        log(_xor_(" (1) - Hacks\n").c_str());
        log(_xor_(" (2) - Discord/Help\n").c_str());
        log(_xor_(" (3) - Exit\n\n").c_str());
        std::cout << "[>] ";
        std::cin >> MenuStatus;
        switch (MenuStatus)
        {
        case 1:
            system("CLS");
            Menu();
            break;
        case 2:
            ShellExecute(0, 0, L"Discord.gg/Penis", 0, 0, SW_SHOW);
            break;
        case 3:
            exit(EXIT_SUCCESS);
            break;
        }
   
        while (MenuStatus > 3)
        {
            system("CLS");
            log(_xor_(" Invalid selection, please try again.\n").c_str());
            Sleep(1500);
            system("CLS");
            Main();
        }
            
            
      
}






