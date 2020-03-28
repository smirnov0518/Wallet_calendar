#pragma once
#include <iostream>
#include<fstream>
#include "windows.h"
#include <stdio.h>
#include <windows.h>
#include<string>

#define GREEN SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define RED SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
#define ORANGE SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define WHITE SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

using std::cout;
using std::cin;
using std::endl;
using std::string;

void show_calenda();

