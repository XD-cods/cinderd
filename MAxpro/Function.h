#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <windows.h>


int size_h();
int size_w();
char** saving(char** MAS, int w, int h);
void reading(char** MAS, int w, int h);
void gotoxy(short int x, short int y);
void showCursor(bool visible);
void control(int w, int h);