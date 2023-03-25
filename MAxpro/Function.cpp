#include "Function.h"

short int x = 1, y = 1;
int counter = 0;
int this_page = 0,max_page=0;

//------------------------------------------------------------------------------------------------

cor** createstb_MAS(int w, int h, cor** MASs)
{
	MASs = (cor**)malloc(w * sizeof(cor*));
	for (int i = 0; i < w; i++)
	{
		MASs[i] = (cor*)malloc(2 * sizeof(cor));
		MASs[i][0].xx = 0;
		MASs[i][0].yy = 0;
		MASs[i][1].xx = 0;
		MASs[i][1].yy = 0;
	}
	return MASs;
}

//------------------------------------------------------------------------------------------------

cor** createstr_MAS(int w, int h, cor** MASs,int n)
{
	for (int i = 0; i < w; i++)
	{
		MASs[i] = (cor*)malloc(n * sizeof(cor));
	}
	return MASs;
}

//------------------------------------------------------------------------------------------------

void cin_elem(int w, int h, cor** MASS)
{
	char c;
	if (counter < w)
	{
		scanf_s("%c", &MASS[counter][this_page].name);
		MASS[counter][this_page].xx = x;
		MASS[counter][this_page].yy = y;
		counter++;
		/*gotoxy(1, 1);*/
		c = ' ';
		gotoxy(x, y);
	}
}
//------------------------------------------------------------------------------------------------

//void del_elem(int w, cor** MASS)
//{
//	for(int i=0;i<w;i++)
//	{
//		if (MASS[i][0].xx == x && MASS[i][0].yy = y)
//		{
//			MASS[i][0].name = "";
//		}
//	}
//}

//------------------------------------------------------------------------------------------------

char** saving(char** MAS, int w, int h)
{

	MAS = (char**)calloc(h, sizeof(char));
	int d = w * 0.3;

	for (int i = 0; i < h; i++)
	{
		MAS[i] = (char*)calloc(w, sizeof(char));
	}

	for (int i = 1; i < h; i++)
	{
		for (int b = 1; b < w; b++)
		{
			MAS[i][b] = ' ';
		}
	}
	for (int i = 0; i < w; i++)
	{
		MAS[0][i] = 196;
		MAS[h - 1][i] = 196;
	}
	for (int i = 0; i < h; i++)
	{
		MAS[i][0] = '|';
		MAS[i][w - 1] = '|';
	}
	for (int i = 1; i < h - 4; i++)
	{
		MAS[i][d] = 124;
		MAS[i][2 * d] = 124;
	}
	for (int i = 1; i < w - 1; i++)
	{
		MAS[h - 4][i] = 196;
	}
	//углы
	MAS[0][0] = 218;
	MAS[h - 1][0] = 192;
	MAS[0][w - 1] = 191;
	MAS[h - 1][w - 1] = 217;
	//
	MAS[h - 4][d] = 193;
	MAS[h - 4][2 * d] = 193;
	MAS[h - 4][0] = 195;
	MAS[h - 4][w - 1] = 180;
	MAS[0][d] = 194;
	MAS[0][2 * d] = 194;




	return MAS;
}

//------------------------------------------------------------------------------------------------

void reading(char** MAS, int w, int h, cor** MASs)
{
	for (int i = 0; i < h; i++)
	{
		for (int b = 0; b < w; b++)
		{
			printf("%c", MAS[i][b]);
		}
		printf("\n");
	}
	gotoxy(1, h - 3);
	printf("ENTER - input | ESC - exit | E - next page | Q - prewiew page");
	gotoxy((w-1)/2-3, h - 1);
	printf("%d / %d", this_page, max_page);
	for (int i = 0; i < w; i++)
	{
		if (MASs[i][this_page].xx != 0 && MASs[i][this_page].yy != 0)
		{
			gotoxy(MASs[i][this_page].xx, MASs[i][this_page].yy);
			printf("%c", MASs[i][this_page].name);
		}

	}
	gotoxy(0, 0);
	gotoxy(1, 1);
}

//------------------------------------------------------------------------------------------------

int size_h()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int h;
	if (hStdOut = GetStdHandle(-12))
	{
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		if (GetConsoleScreenBufferInfo(hStdOut, &consoleInfo))
		{
			h = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
		}
	}
	return h;
}

//------------------------------------------------------------------------------------------------

int size_w()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int w;
	if (hStdOut = GetStdHandle(-12))
	{
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		if (GetConsoleScreenBufferInfo(hStdOut, &consoleInfo))
		{
			w = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
		}
	}
	return w;
}

//------------------------------------------------------------------------------------------------

void gotoxy(short int j, short int h)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD curspos = { j , h };
	SetConsoleCursorPosition(hStdOut, curspos);
}

//------------------------------------------------------------------------------------------------

void showCursor(bool visible)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ccInfo;
	ccInfo.bVisible = visible;
	ccInfo.dwSize = 20;
	SetConsoleCursorInfo(hStdOut, &ccInfo);
}

//------------------------------------------------------------------------------------------------

int control(char** MASS, int w, int h, cor** MASi)
{
	char g = _getch();
	switch (g)
	{
	case 72:
		if (y > 1)
		{
			y--;
			gotoxy(x, y);
		}
		break;
	case 80:
		if (y < (h - 5))
		{
			y++;
			gotoxy(x, y);
		}
		break;
	case 77:
		if (x != w * 0.3 && x < w * 0.3 * 2)
		{
			x += (w * 0.3);
			gotoxy(x, y);
		}
		else if (x == w * 0.3) {
			x += (w * 0.3 * 2);
			gotoxy(x, y);
		}
		break;
	case 13:
		cin_elem(w, h, MASi);
		break;
	case 27:
		return 0;
	case 101:
		this_page++;
		if (this_page < max_page) {
			max_page++;
			createstr_MAS(w,h,MASi,max_page);
		}
		break;
	case 75:
		if (x > 1)
		{
			x -= (w * 0.3);
			gotoxy(x, y);
		}
		break;
	}
	return control(MASS, w, h, MASi);
}

