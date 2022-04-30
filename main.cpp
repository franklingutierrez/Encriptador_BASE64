#include<iostream>
#include<conio.h>
#include<windows.h>
#include"base64.h"
#include <string>
#include "base64.h"
using namespace std;

void gotoxy(int x, int y);
void cuadro(void);

int main() {

	//=============== Estetica del programa =========================
	cuadro();//Impresion de cuadro
	int i, d, x, y;
	gotoxy(30, 3);
	cout << ".:. MENU PRINCIPAL .:.";
	gotoxy(20, 6);
	cout << "E N C R I P T A D O R | Franklin Gutierrez ";
	//================================================================

	string msg;
	int clave;

	while (1) {
		gotoxy(34, 9);
		cout << "Selecciona: \n";
		gotoxy(20, 12);
		cout << "=> 1. Encriptar\n";
		gotoxy(20, 13);
		cout << "=> 2. Desencriptar\n";
		char opt;
		do {
			gotoxy(20, 15);
			cout << "====> ";
			cin >> opt;
		} while (opt != '1' && opt != '2');
		system("cls");

		//=============== Estetica del programa =========================
		system("color c0");
		cuadro();//Impresion de cuadro
		int i, d, x, y;
		gotoxy(22, 3);
		cout << ".:. ENCRIPTACION / DESENCRIPTACION .:.";
		gotoxy(20, 6);
		cout << "E N C R I P T A D O R | Franklin Gutierrez ";
		//================================================================

		gotoxy(30, 11);
		cout << "Escribe el mensaje:";
		gotoxy(5, 13);
		cin >> ws;
		system("cls;");
		getline(cin, msg);

		//=============== Estetica del programa =========================
		cuadro();//Impresion de cuadro
		system("color 0f");
		gotoxy(30, 3);
		cout << ".:. MENU PRINCIPAL .:.";
		gotoxy(20, 6);
		cout << "E N C R I P T A D O R | Franklin Gutierrez ";
		//================================================================

		if (opt == '1') {
			// ENCRIPTAR
			auto nuevo = base64::Cifrar(msg);
			gotoxy(5, 18);
			cout << "Mensaje encriptado:";
			gotoxy(5, 19);
			cout << "_________________________________";
			gotoxy(5, 21);
			cout << nuevo;
			
		}
		else {
			// DESENCRIPTAR
			auto nuevo = base64::Descifrar(msg);
			gotoxy(5, 18);
			cout << "Mensaje descifrado: ";
			gotoxy(5, 19);
			cout << "_________________________________";
			gotoxy(5, 21);
			cout << nuevo;
		}
	}
	system("pause>log.txt");
	return 0;
}