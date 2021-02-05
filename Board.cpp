#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Board.h"
#include "Word.h"
#define MAX_LEN 13

using namespace std;

Board::Board(void)
{
	BoardHeight = 0;
	remainingWords = 0;
	BoardWidth = 0;
	Chars = NULL;
	NumWords = 0;
	Words = NULL;
	being_Used = NULL;
	found = NULL;
}

Board::~Board()
{
	free(Chars);
}

//---------------------------- Init() --------------------------------------------------------------------------------------------------
void Board::Init(int Y, int X, int playing_Words)
{
	int i = 0, j = 0;
	NumWords = 0;
	remainingWords = 0;
	Set_BoardHeight(Y);
	Set_BoardWidth(X);

	Chars = (Char**) new Char * [Y]; // Em que Char é uma classe
	for (int i = 0; i < Y; i++)
		Chars[i] = (Char*)new Char[X];


	for (i = 0; i < BoardHeight; i++) {
		for (j = 0; j < BoardWidth; j++) {
			Chars[i][j].Rand();
		}
	}

	Words = (Word*)new Word[102];	// 102 é o numero de palavras no ficheiro

	being_Used = (int*)new int[playing_Words]; //Alocação dinamica dos vetores being_used que guarda os numeros das palavras que vao estar na sopa de letras
	found = (int*) new int[playing_Words];     // e do vetor found que guarda o numero das palavras ja descobertas pelo utilizador
	for (i = 0; i < playing_Words; i++) {
		being_Used[i] = -1;
		found[i] = -1;
	}


	ifstream myfile;
	myfile.open("palavras.txt");

	if (myfile.is_open()) {

		string line;
		i = 0;
		int contador = 0; 


		while (myfile.peek() != EOF)
		{
			getline(myfile, line);
			Words[i].set_Letters(line);
			Words[i].set_Lenght(line.length());
			contador++;

			/* 
			Usado para debug
			Words[i].View();
			cout << endl;
			cout << "Tamanho:" << Words[i].get_Lenght() << endl;
			*/

			i++;
		}
		myfile.close();

		// Declaração das variáveis random, C_random, L_random, O_random do tipo int e de um objeto P_aux do tipo Point
		int random = rand() % contador;
		int C_random = rand() % BoardWidth;
		int L_random = rand() % BoardHeight;
		int O_random = rand()%8;

	
		Point P_aux;


	for(j=0; j<playing_Words ; j++){ // Utilizando um num de palavras diferente consoante a dificuldade



		random = rand() % contador;

// Seletor de numeros random para dificultar a saida de numeros repetidos
		if (being_Used[0] != -1) { // Significa que já não é a primeira palavra
			for (int k = 0; k < 2; k++) {  // k < 2 para diminuir as chances de poder passar uma palavra repetida
				for (i = 0; i < playing_Words; i++) {
					if (random == being_Used[i])
						random = rand() % contador;
				}
			}
		}
/*
		C_random = rand() % BoardWidth;
		L_random = rand() % BoardHeight;
*/
		O_random = rand() % 8 + 1;
		being_Used[j] = random; // Guarda o numero da palavra a usar
		Words[random].set_Orientation(O_random);

		int contador2=0;
		bool flag = false;
		int aux=0;

		switch (O_random) {
		
			

// HORIZONTAL (ESQUERDA -> DIREITA) 
		case 1: {
			// PASSAR PARA METODO
			do {
				contador2 = 0;
				P_aux.Rand(BoardWidth, BoardHeight);
				Words[random].set_Position(P_aux);		

					// Contador de trues
				if (check_if_Fits(random)) {
					for (i = 0; i < Words[random].get_Lenght(); i++) {
						if (Chars[Words[random].get_Y()][Words[random].get_X() + i].get_State() == true) {
							P_aux.set_P(Words[random].get_Y(), Words[random].get_X() + i);
							aux = i;
							contador2++;
						}
					}
				}

					// Se não encontrar nenhum state a true
				if (contador2 == 0) {
					if (check_if_Fits(random)) {
						flag = true;
					}
				}
					// Se encontrar um state a true
				if(contador2 == 1){
					if (Words[random].get_Letter(aux) == Chars[P_aux.get_Y()][P_aux.get_X()].get_Ch()) {  // Verifica se elas cruzam na mesma letra
						if (check_if_Fits(random)) {
							flag = true;
						}
					}
				}
			} while (!flag);

			put_Word(random);
			view_Info(random);  // Para debug

			break;
			}

// DIAGONAL (CIMA -> BAIXO) (ESQUERDA -> DIREITA)
		case 2: {
			do {
				contador2 = 0;
				P_aux.Rand(BoardWidth, BoardHeight);
				Words[random].set_Position(P_aux);

					// Contador de trues
				if (check_if_Fits(random)) {
					for (i = 0; i < Words[random].get_Lenght(); i++) {
						if (Chars[Words[random].get_Y() + i][Words[random].get_X() + i].get_State() == true) {
							P_aux.set_P(Words[random].get_Y() + i, Words[random].get_X() + i);
							aux = i;
							contador2++;
						}
					}
				}

					// Se não encontrar nenhum state a true
				if (contador2 == 0) {
					if (check_if_Fits(random)) {
						flag = true;
					}
				}
					// Se encontrar um state a true
				if (contador2 == 1) {
					if (Words[random].get_Letter(aux) == Chars[P_aux.get_Y()][P_aux.get_X()].get_Ch()) {
						if (check_if_Fits(random)) {
							flag = true;
						}
					}
				}

			} while (!flag);

			view_Info(random);   // Para debug
			put_Word(random);
		break;
		}

// VERTICAL (CIMA -> BAIXO)
		case 3: {
			do {
				contador2 = 0;
				P_aux.Rand(BoardWidth, BoardHeight);
				Words[random].set_Position(P_aux);

					// Contador de trues
				if (check_if_Fits(random)) {
					for (i = 0; i < Words[random].get_Lenght(); i++) {
						if (Chars[Words[random].get_Y() + i][Words[random].get_X()].get_State() == true) {
							P_aux.set_P(Words[random].get_Y() + i, Words[random].get_X());
							aux = i;
							contador2++;
						}
					}
				}

					// Se não encontrar nenhum state a true
				if (contador2 == 0) {
					if (check_if_Fits(random)) {
						flag = true;
					}
				}
					// Se encontrar um state a true
				if (contador2 == 1) {
					if (Words[random].get_Letter(aux) == Chars[P_aux.get_Y()][P_aux.get_X()].get_Ch()) {
						if (check_if_Fits(random)) {
							flag = true;
						}
					}
				}

			} while (!flag);

			view_Info(random);   // Para debug
			put_Word(random);
		break;
		}

// DIAGONAL (CIMA -> BAIXO) (ESQUERDA <- DIREITA)
		case 4: {
			do {
				contador2 = 0;
				P_aux.Rand(BoardWidth, BoardHeight);
				Words[random].set_Position(P_aux);

					// Contador de trues
				if (check_if_Fits(random)) {
					for (i = 0; i < Words[random].get_Lenght(); i++) {
						if (Chars[Words[random].get_Y() + i][Words[random].get_X() - i].get_State() == true) {
							P_aux.set_P(Words[random].get_Y() + i, Words[random].get_X() - i);
							aux = i;
							contador2++;
						}
					}
				}

					// Se não encontrar nenhum state a true
				if (contador2 == 0) {
					if (check_if_Fits(random)) {
						flag = true;
					}
				}
					// Se encontrar um state a true
				if (contador2 == 1) {
					if (Words[random].get_Letter(aux) == Chars[P_aux.get_Y()][P_aux.get_X()].get_Ch()) {
						if (check_if_Fits(random)) {
							flag = true;
						}
					}
				}

			} while (!flag);

			view_Info(random);   // Para debug
			put_Word(random);
			break;
			}

// HORIZONTAL (ESQUERDA <- DIREITA)
		case 5: {
			do {
				contador2 = 0;
				P_aux.Rand(BoardWidth, BoardHeight);
				Words[random].set_Position(P_aux);

					// Contador de trues
				if (check_if_Fits(random)) {
					for (i = 0; i < Words[random].get_Lenght(); i++) {
						if (Chars[Words[random].get_Y()][Words[random].get_X() - i].get_State() == true) {
							P_aux.set_P(Words[random].get_Y(), Words[random].get_X() - i);
							aux = i;
							contador2++;
						}
					}
				}

					// Se não encontrar nenhum state a true
				if (contador2 == 0) {
					if (check_if_Fits(random)) {
						flag = true;
					}
				}
					// Se encontrar um state a true
				if (contador2 == 1) {
					if (Words[random].get_Letter(aux) == Chars[P_aux.get_Y()][P_aux.get_X()].get_Ch()) {
						if (check_if_Fits(random)) {
							flag = true;
						}
					}
				}

			} while (!flag);

			view_Info(random);   // Para debug
			put_Word(random);
			break;
			}

// DIAGONAL (CIMA <- BAIXO)(ESQUERDA <- DIREITA)
		case 6: {
			do {
				contador2 = 0;
				P_aux.Rand(BoardWidth, BoardHeight);
				Words[random].set_Position(P_aux);

				// Contador de trues
				if (check_if_Fits(random)) {
					for (i = 0; i < Words[random].get_Lenght(); i++) {
						if (Chars[Words[random].get_Y() - i][Words[random].get_X() - i].get_State() == true) {
							P_aux.set_P(Words[random].get_Y() - i, Words[random].get_X() - i);
							aux = i;
							contador2++;
						}
					}
				}

				// Se não encontrar nenhum state a true
				if (contador2 == 0) {
					if (check_if_Fits(random)) {
						flag = true;
					}
				}
				// Se encontrar um state a true
				if (contador2 == 1) {
					if (Words[random].get_Letter(aux) == Chars[P_aux.get_Y()][P_aux.get_X()].get_Ch()) {
						if (check_if_Fits(random)) {
							flag = true;
						}
					}
				}

			} while (!flag);

			view_Info(random);   // Para debug
			put_Word(random);
			break;
			}

// VERTICAL (CIMA <- BAIXO)
		case 7: {
			do {
				contador2 = 0;
				P_aux.Rand(BoardWidth, BoardHeight);
				Words[random].set_Position(P_aux);

				// Contador de trues
				if (check_if_Fits(random)) {
					for (i = 0; i < Words[random].get_Lenght(); i++) {
						if (Chars[Words[random].get_Y() - i][Words[random].get_X()].get_State() == true) {
							P_aux.set_P(Words[random].get_Y() - i, Words[random].get_X());
							aux = i;
							contador2++;
						}
					}
				}

				// Se não encontrar nenhum state a true
				if (contador2 == 0) {
					if (check_if_Fits(random)) {
						flag = true;
					}
				}
				// Se encontrar um state a true
				if (contador2 == 1) {
					if (Words[random].get_Letter(aux) == Chars[P_aux.get_Y()][P_aux.get_X()].get_Ch()) {
						if (check_if_Fits(random)) {
							flag = true;
						}
					}
				}

			} while (!flag);

			view_Info(random);   // Para debug
			put_Word(random);
			break;
			}

// DIAGONAL (CIMA <- BAIXO)(ESQUERDA -> DIREITA)
		case 8: {
			do {
				contador2 = 0;
				P_aux.Rand(BoardWidth, BoardHeight);
				Words[random].set_Position(P_aux);

				// Contador de trues
				if (check_if_Fits(random)) {
					for (i = 0; i < Words[random].get_Lenght(); i++) {
						if (Chars[Words[random].get_Y() - i][Words[random].get_X() + i].get_State() == true) {
							P_aux.set_P(Words[random].get_Y() - i, Words[random].get_X() + i);
							aux = i;
							contador2++;
						}
					}
				}

				// Se não encontrar nenhum state a true
				if (contador2 == 0) {
					if (check_if_Fits(random)) {
						flag = true;
					}
				}
				// Se encontrar um state a true
				if (contador2 == 1) {
					if (Words[random].get_Letter(aux) == Chars[P_aux.get_Y()][P_aux.get_X()].get_Ch()) {
						if (check_if_Fits(random)) {
							flag = true;
						}
					}
				}

			} while (!flag);

			view_Info(random);   // Para debug
			put_Word(random);
			break;
			}

		}

//Apenas para efeitos de debug
/*
			Words[being_Used[j]].View();
			cout << endl;
*/


	}


	
	}
	else {
		cout << "ERRO! Impossivel abrir o ficheiro!" << endl;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------




//----------------------------------View ()--------------------------------------------------------------------------------------
void Board::View(void)
{
	for (int i = 0; i < BoardHeight; i++) {
		cout << "\t\t\t\t\t";
		for (int k = 0; k < BoardWidth; k++) {
			Chars[i][k].View();
		}
		cout << endl;
	}
}
//---------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------put_Word()----------------------------------------------------------------------------------
void Board::put_Word(int word_number)
{
	switch (Words[word_number].get_Orientation()) {
	case 1: {
		// HORIZONTAL (ESQUERDA -> DIREITA)
		for (int i = 0; i < Words[word_number].get_Lenght(); i++) {
			Chars[Words[word_number].get_Y()][Words[word_number].get_X() + i] = Words[word_number].get_Letter(i);
			Chars[Words[word_number].get_Y()][Words[word_number].get_X() + i].set_State(true);
		}
		NumWords++;
		remainingWords++;
		break;
	}
	case 2: {
		// DIAGONAL (CIMA -> BAIXO) (ESQUERDA -> DIREITA)
		for (int i = 0; i < Words[word_number].get_Lenght(); i++) {
			Chars[Words[word_number].get_Y() + i][Words[word_number].get_X() + i] = Words[word_number].get_Letter(i);
			Chars[Words[word_number].get_Y() + i][Words[word_number].get_X() + i].set_State(true);
		}
		NumWords++;
		remainingWords++;
		break;
	}
	case 3: {
		// VERTICAL (CIMA -> BAIXO)
		for (int i = 0; i < Words[word_number].get_Lenght(); i++) {
			Chars[Words[word_number].get_Y() + i][Words[word_number].get_X()] = Words[word_number].get_Letter(i);
			Chars[Words[word_number].get_Y() + i][Words[word_number].get_X()].set_State(true);
		}
		NumWords++;
		remainingWords++;
		break;
	}
	case 4: {
		// DIAGONAL (CIMA -> BAIXO) (ESQUERDA <- DIREITA)
		for (int i = 0; i < Words[word_number].get_Lenght(); i++) {
			Chars[Words[word_number].get_Y() + i][Words[word_number].get_X() - i] = Words[word_number].get_Letter(i);
			Chars[Words[word_number].get_Y() + i][Words[word_number].get_X() - i].set_State(true);
		}
		NumWords++;
		remainingWords++;
		break;
	}
	case 5: {
		// HORIZONTAL (ESQUERDA <- DIREITA)
		for (int i = 0; i < Words[word_number].get_Lenght(); i++) {
			Chars[Words[word_number].get_Y()][Words[word_number].get_X() - i] = Words[word_number].get_Letter(i);
			Chars[Words[word_number].get_Y()][Words[word_number].get_X() - i].set_State(true);
		}
		NumWords++;
		remainingWords++;
		break;
	}
	case 6: {
		// DIAGONAL (CIMA <- BAIXO)(ESQUERDA <- DIREITA)
		for (int i = 0; i < Words[word_number].get_Lenght(); i++) {
			Chars[Words[word_number].get_Y() - i][Words[word_number].get_X() - i] = Words[word_number].get_Letter(i);
			Chars[Words[word_number].get_Y() - i][Words[word_number].get_X() - i].set_State(true);
		}
		NumWords++;
		remainingWords++;
		break;
	}
	case 7: {
		// VERTICAL (CIMA <- BAIXO)
		for (int i = 0; i < Words[word_number].get_Lenght(); i++) {
			Chars[Words[word_number].get_Y() - i][Words[word_number].get_X()] = Words[word_number].get_Letter(i);
			Chars[Words[word_number].get_Y() - i][Words[word_number].get_X()].set_State(true);
		}
		NumWords++;
		remainingWords++;
		break;
	}
	case 8: {
		// DIAGONAL (CIMA <- BAIXO)(ESQUERDA -> DIREITA)
		for (int i = 0; i < Words[word_number].get_Lenght(); i++) {
			Chars[Words[word_number].get_Y() - i][Words[word_number].get_X() + i] = Words[word_number].get_Letter(i);
			Chars[Words[word_number].get_Y() - i][Words[word_number].get_X() + i].set_State(true);
		}
		NumWords++;
		remainingWords++;
		break;
	}
	default: {
		cout << "Nao foi encontrada nenhuma orientacao" << endl;
	}
	}
}
//---------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------view_Info------------------------------------------------------------------
void Board::view_Info(int word_number)
{
	Words[word_number].View();				
	cout << endl;
//	cout << "Tamanho: " << Words[word_number].get_Lenght() << endl;
//	cout << "X = " << Words[word_number].get_X() << endl;
//	cout << "Y = " << Words[word_number].get_Y() << endl;
//	Words[word_number].view_Orientation();
}
//---------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------view_Orientation()-------------------------------------------(debug purpose)----

//---------------------------------------------------------------------------------------------------------------------------------




bool Board::check_if_Fits(int random)
{
	switch (Words[random].get_Orientation()) {
	case 1: {
		if ((BoardWidth - Words[random].get_X()) < Words[random].get_Lenght()) {
			return false;
		}
		return true;
	}
	case 2: {
		if ((BoardWidth - Words[random].get_X()) < Words[random].get_Lenght() || (BoardHeight - Words[random].get_Y()) < Words[random].get_Lenght()) {
			return false;
		}
		return true;
	}
	case 3: {
		if ((BoardHeight - Words[random].get_Y()) < Words[random].get_Lenght()) {
			return false;
		}
		return true;
	}
	case 4: {
		if (Words[random].get_X() < Words[random].get_Lenght() || (BoardHeight - Words[random].get_Y()) < Words[random].get_Lenght()) {
			return false;
		}
		return true;
	}
	case 5: { //
		if (Words[random].get_X() < Words[random].get_Lenght()) {
			return false;
		}
		return true;
	}
	case 6: {
		if (Words[random].get_X() < Words[random].get_Lenght() || (Words[random].get_Y()) < Words[random].get_Lenght()) {
			return false;
		}
		return true;
	}
	case 7: {
		if ((Words[random].get_Y()) < Words[random].get_Lenght()) {
			return false;
		}
		return true;
	}
	case 8: {
		if (BoardWidth - Words[random].get_X() < Words[random].get_Lenght() || (Words[random].get_Y()) < Words[random].get_Lenght()) {
			return false;
		}
		return true;
	}



	}
}

int Board::get_value(int a)
{
	return being_Used[a];

}

int Board::find(string s)
{
	cout << s << endl;
	for (int j = 0; j < get_NumWords(); j++) {
		if (found[j] != -1 && Words[found[j]].get_Letters() == s)
			return -2;
	}

	for (int i = 0; i < get_NumWords(); i++) {
		if (s == Words[being_Used[i]].get_Letters()) {
			if (found[i] == -1) {
				found[i] = being_Used[i];
//				view_Info(being_Used[i]);
				return being_Used[i];
			}

		}
	}
	return -1;
	
}

void Board::less_NumWords(void)
{
	NumWords--; 
}

void Board::less_remainingWords(void)
{
	remainingWords--;
}


