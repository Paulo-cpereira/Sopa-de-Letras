#include "Char.h"
#include <random>
#include <iostream>
#include <time.h>

using namespace std;

Char::Char()
{
	Ch = 'A';
	state = false;
}

Char::Char(char c)
{
	this->Ch = c;
	state = false;
}

Char::~Char()
{
}

void Char::Rand()
{
	Ch = rand() % 26 + 'a'; // MUDAR PARA MAIUSCULO
}

void Char::View()
{
	cout << " " << Ch;
}

void Char::set_Ch(char c)
{
	this->Ch = c;
}

