#include "Word.h"
#include <string>
#include <iostream>

using namespace std;

Word::Word()
{
	Letters = "";
	Position.set_X(0);
	Position.set_Y(0);
	Orientation = -1;
}

Word::Word(string s)
{
	Letters = s;
	Position.set_X(0);
	Position.set_Y(0);
	Orientation = -1;
}

Word::Word(string s, Point P)
{
	Letters = s;
	Position.set_X(P.get_X());
	Position.set_Y(P.get_Y());
	Orientation = -1;
}

Word::Word(string s, Point P, int Orient)
{
	Letters = s;
	Position.set_X(P.get_X());
	Position.set_Y(P.get_Y());
	this->Orientation = Orient;
}

Word::~Word()
{
}

void Word::set_X(int valor)
{
	Position.set_X(valor);
}

void Word::set_Y(int valor)
{
	Position.set_Y(valor);
}


void Word::set_Letters(string s)
{
	this->Letters = s;
}

void Word::set_Orientation(int Or)
{
	this->Orientation = Or;
}

void Word::View(void)
{
	cout << Letters;
}

int Word::get_Lenght(void)
{
	lenght = Letters.length();
	return lenght;
}

void Word::set_Lenght(int t)
{
	this->lenght = t;
}

void Word::view_Orientation(void)
{
	switch (this->Orientation) {
	case 1: {
		cout << "HORIZONTAL (ESQUERDA -> DIREITA)" << endl;
		break;
	}
	case 2: {
		cout << "DIAGONAL (CIMA -> BAIXO) (ESQUERDA -> DIREITA)" << endl;
		break;
	}
	case 3: {
		cout << "VERTICAL (CIMA -> BAIXO)" << endl;
		break;
	}
	case 4: {
		cout << "DIAGONAL (CIMA -> BAIXO) (ESQUERDA <- DIREITA)" << endl;
		break;
	}
	case 5: {
		cout << "HORIZONTAL (ESQUERDA <- DIREITA)" << endl;
		break;
	}
	case 6: {
		cout << "DIAGONAL (CIMA <- BAIXO)(ESQUERDA <- DIREITA)" << endl;
		break;
	}
	case 7: {
		cout << "VERTICAL (CIMA <- BAIXO)" << endl;
		break;
	}
	case 8: {
		cout << "DIAGONAL (CIMA <- BAIXO)(ESQUERDA -> DIREITA)" << endl;
		break;
	}
	}
}

void Word::upper(int tamanho)
{
	for (int i = 0; i < tamanho; i++) {
		if (Letters[i] >= 'a' && Letters[i] <= 'z') {
			Letters[i] = Letters[i] - 32;
//			cout << Letters[i];
		}
		
	}
	cout << endl;
}

