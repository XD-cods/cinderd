#include "Function.h"


//------------------------------------------------------------------------------------------------

char** saving(char** MAS,int w,int h)
{	

    MAS = new char* [h];
    int d = w * 0.3;

    for(int i=0;i<h;i++)
    {
        MAS[i] = new char[w];
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
    for (int i = 1; i < h-4; i++)
    {
        MAS[i][d] = 124;
        MAS[i][2 * d] = 124;
    }
    for (int i = 1; i < w-1; i++)
    {
        MAS[h-4][i] = 196;   
    }
    //углы
    MAS[0][0] = 218;
    MAS[h-1][0] = 192;
    MAS[0][w-1] = 191;
    MAS[h - 1][w-1] = 217;
    //
    MAS[h - 4][d] = 193;
    MAS[h - 4][2*d] = 193;
    MAS[h - 4][0] = 195;
    MAS[h - 4][w - 1] = 180;
    MAS[0][d] = 194;
    MAS[0][2 * d] = 194;


    
    
	return MAS;
}

//------------------------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------------------------