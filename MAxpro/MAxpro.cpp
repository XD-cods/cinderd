#include "Function.h"

int main()
{
	char** arr = 0;
	int w, h;
	while (1)
	{
		w = size_w();
		h = size_h();
		arr = saving(arr, w, h);
		reading(arr, w, h);
		gotoxy(1, 1);
		while(1)control(w, h);
		system("cls");
	}
	return 0;
}
