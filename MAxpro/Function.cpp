#include "Function.h"

char** saving(char** MAS,int w,int h)
{	


    MAS = new char* [h];
    for(int i=0;i<h;i++)
    {
    MAS[i] = new char[w];
    }
    for (int i = 0; i < h; i++)
    {
        for (int b = 0; b < w; b++)
        {
           MAS[i][b]=0;
        }
    }
    for (int i = 0; i < w; i++)
    {        
        MAS[0][i] = '*';
        MAS[h - 1][i] = '*';
    }
    for (int i = 0; i < h; i++)
    {
        MAS[i][0] = '*';
        MAS[i][w - 1] = '*';
    }
    

	return MAS;
}



void reading(char** MAS,int w,int h)
{
    
    for (int i = 0; i < h; i++)
    {
        for (int b = 0; b < w; b++)
        {
            cout << MAS[i][b];
        }
        cout << '\n';
    }
}