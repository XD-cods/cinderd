#pragma once


#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cor
{
	char name[10];
	short int xx, yy;
};

void cin_elem(int w, int h, cor** MASS);
int size_h();
int size_w();
char** saving(char** MAS, int w, int h);
void reading(char** MAS, int w, int h, cor** MASs);
void gotoxy(short int x, short int y);
void showCursor(bool visible);
int control(char** MASS,int w, int h, cor** MASi);
cor** createstb_MAS(int w, int h, cor** MASs);
cor** createstr_MAS(int w, int h, cor** MASs);
