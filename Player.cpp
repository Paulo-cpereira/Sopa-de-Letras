#include "Player.h"

Player::Player(void)
{
	nome = "Player";
	idade = 0;
}

Player::Player(string s, int i)
{
	nome = s;
	idade = i;
}

Player::Player(string s)
{
	nome = s;
	idade = 0;
}

Player::Player(int i)
{
	nome = "Player";
	idade = i;
}

Player::~Player()
{
}

void Player::set_nome(string s)
{
	nome = s;
}

void Player::set_idade(int i)
{
	idade = i;
}

