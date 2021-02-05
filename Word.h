#pragma once
#include <string>
#include "Char.h"
#include "Point.h"

using namespace std;

class Word
{
private:
	string Letters;
	int lenght;
	Point Position;
	int Orientation;


public:
	Word();
	Word(string);
	Word(string, Point);
	Word(string, Point, int);
	~Word();



	Point get_Position() { return Position;
};
	void set_Position(Point P) { Position = P; };
	int get_X() { return Position.get_X(); };
	int get_Y() { return Position.get_Y(); };
	void set_X(int);
	void set_Y(int);
	void set_Letters(string);

	void set_Orientation(int);
	int get_Orientation(void) { return Orientation; }
	void view_Orientation(void);


	string get_Letters(void) { return Letters; };
	char get_Letter(int i) { return Letters[i]; }
	void View(void);
	int get_Lenght(void);
	void set_Lenght(int);

	void upper(int);

};

