#ifdef _WIN32 // Para Windows
#include <windows.h>
void gotoxy(int x, int y)
{
    COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#elif __linux__ // Para Linux
#include <ncurses.h>
void gotoxy(int x, int y)
{
    move(y, x);
}
#else // Para otros sistemas operativos
void gotoxy(int x, int y)
{
    printf("\033[%d;%df", y, x);
}
#endif