#include "Function.h"

int** saving(int** arr,int w,int h)
{	


    int** mass = new int* [w];
    for(int i=0;i<w;i++)
    {
    mass[i] = new int[h];
    }
    for (int i = 0; i < h; i++)
    {
        mass[0][i] = 1;
        mass[w - 1][i] = 1;
    }
    for (int i = 0; i < w; i++)
    {
        mass[i][0] = 1;
        mass[i][h - 1] = 1;
    }

	return mass;
}



void reading(int** arr,int w,int h)
{
    
    for (int i = 0; i < w; i++)
    {
        for (int b = 0; b < h; b++)
        {
            cout << arr[i][b];
        }
        cout << '\n';
    }
}