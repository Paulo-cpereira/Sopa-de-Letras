#pragma once
#include "Board.h"
#include "Experiente.h"
#include "Principiante.h"
#include <string>
using namespace std;
class Game
{

private:
	Board PlayBoard;
	string Nome;
	int idade;
	int GameScore;
	int Ronda;
	int Difficulty;
	//Player Jogador;
	Experiente Exp;
	Principiante Noob;

public:
	Game(int, int, string, int _idade, int _dificuldade);
	Game(int, int);

	int Play();
	void View();
//	void SaveGame(ofstream& os);
	void Run();
};

