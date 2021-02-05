#pragma once
#include "Point.h"
#include "Char.h"
#include "Word.h"
#include "Board.h"
#include "Game.h"
#include <time.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>


using namespace std;

void splashScreen(void);
int askMenuOption(void);

int main(void) {

	/*                 ------------------------------ Teste do Ponto ---------------------------------------
		Point P[5];

		P[1].Update(1, 4);
		P[1].Show();
		P[2].Show();
		if (P[1] == P[2])
			cout << "Os pontos são os mesmos!" << endl;
					   -------------------------------------------------------------------------------------
	*/

	/* ----------------------------- Teste da Letra ------------------------------
		Char C[5];
	;
		C[4].set_Ch('B');
		C[3].Rand();
		C[3].View();
		C[4].View();

	 --------------------------------------------------------------------------
	*/

	/*  --------------------- Teste Word -----------------
		Word W[5];
		Point P(5, 5);
		W[0].set_Letters("LULA");
		W[0].View();
		W[1].set_Position(P);
		--------------------------------------------------
	*/

	srand((int)time(NULL));
	Word nickname;
	int opcao = 0;
	string aux = {};



	do {
		int _aux = 0;
		int idade = 0;
		int dificuldade = 0;
		int cols = 0;
		int rows = 0;


		splashScreen();
		opcao = askMenuOption();
		if (opcao == 1) {
			cout << endl << endl << "\t\t\t\t\t";
			cout << "Introduza um nickname:";
			cin >> ws;
			getline(cin, aux);
			nickname.set_Letters(aux);

			cout << endl << "\t\t\t\t\tIntroduza a idade: ";
			cin >> idade;
			cout << endl << "\t\t\t\t\tIntroduza o numero de colunas: ";
			cin >> cols;
			cout << endl << "\t\t\t\t\tIntroduza o numero de linhas: ";
			cin >> rows;

			cout << endl << "\t\t\t\t\tIntroduza a dificuldade:" << endl << "\t\t\t\t\t1.Principiante" << endl << "\t\t\t\t\t2.Experiente" << endl;
			cout << "\t\t\t\t\tOpcao:";
			cin >> dificuldade;

			system("cls");

			Game mygame(cols, rows, nickname.get_Letters(), idade, dificuldade);
			mygame.Run();
		}
		if (opcao == 2) {

		}
		if (opcao == 3) {
			cout << endl;
			cout << "\t\t\t\t\t\t\tTem a certeza?" << endl;
			cout << "\t\t\t\t\t\t\t1-Sim \t 2-Nao" << endl;
			cout << "\t\t\t\t\t\t\tOpcao: ";
			cin >> _aux;
			if (_aux == 1) {
				opcao = -1;
				splashScreen();
				cout << "\t\t\t\t\t\tThanks for playing";
				cout << endl << endl << endl;	
			}
		}

	} while (opcao != -1);

	exit(0);

}

void splashScreen(void)
{
		system("cls");
		cout << endl;
		cout << "\t\t&========================& BEM VINDO AO JOGO SOPA DE LETRAS &========================&";
		cout << endl << endl << endl << endl;
}

int askMenuOption(void) {
	int numero = 0;
	do {
		cout << "\t\t\t\t\t\t\t==MENU==" << endl << endl << endl;
		cout << "\t\t\t\t\t\t\t1.Jogar" << endl << endl;
		cout << "\t\t\t\t\t\t\t2.Carregar Jogo" << endl << endl;
		cout << "\t\t\t\t\t\t\t3.Sair" << endl << endl;
		cout << "\t\t\t\t\t\t\tOpcao:";
		cin >> numero;
	} while (numero != 1 && numero != 2 && numero != 3);

	return numero;
}
