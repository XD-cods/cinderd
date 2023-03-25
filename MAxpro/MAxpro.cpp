#include "Function.h"

int main()
{
	char** arr = 0;
	int w, h;
	w = size_w();
	h = size_h();
	arr = saving(arr, w, h);
	cor** M = 0;
	M = createstb_MAS(w, h, M);
	reading(arr, w, h, M);
	control(arr, w, h, M);
	system("cls");
	return 0;
}
