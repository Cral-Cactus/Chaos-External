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

void SetColor(unsigned short color)
{
    HANDLE con = 0;
    con = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(con, color);
}
