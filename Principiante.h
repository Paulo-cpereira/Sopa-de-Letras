#pragma once
#include "Player.h"
class Principiante : public Player 
{
private:
	int num_Words;
public:
	Principiante();
	~Principiante();
	void set_num_Words(int a) { num_Words = a; }
	int get_num_Words(void) { return num_Words; }
};

