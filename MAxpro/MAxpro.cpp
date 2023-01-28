

#include "Function.h"

int main()
{
    char** arr = 0;

    int w, h;
    HANDLE hWndConsole;
    if (hWndConsole = GetStdHandle(-12))
    {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
        {
            w = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
            h = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
        }
    }
    

    arr = saving(arr, w, h);  
    reading(arr, w, h);
    system("pause>nul");
    return 0;
}
