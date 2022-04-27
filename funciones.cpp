#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void cuadro(void) {
    int i, d, r, s;
    for (i = 2; i < 80; i++) {
        gotoxy(i, 1);
        printf("%c", 178);//imprime la linea inicio horizontal
        gotoxy(i, 4);
        printf("%c", 95);//imprime la segunda linea horizontal
        gotoxy(i, 24);
        printf("%c", 178);//imprime linea de final horizontal
    }
    for (d = 2; d < 24; d++) {
        gotoxy(2, d);
        printf("%c", 178);//imprime linea inicio vertical

        gotoxy(79, d);
        printf("%c", 178);//imprime linea final vertical
    }

}