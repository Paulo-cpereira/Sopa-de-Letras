#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

class Player 
{
private:
	string nome;
	int idade;

public:
	Player(void);
	Player(string, int);
	Player(string);
	Player(int);
	~Player();

	void set_nome(string s);
	string get_nome(void) { return nome; };

	void set_idade(int i);
	int get_idade(void) { return idade; }

	friend class Game;


	

};

