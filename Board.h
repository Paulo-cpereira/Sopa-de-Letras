#pragma once
#include "Char.h"
#include "Word.h"

class Board
{
private:
	int BoardWidth;
	int BoardHeight;
	Char** Chars;
	Word* Words;
	int NumWords;
	int remainingWords;
	int* being_Used;
	int* found;

public:
	Board(void);
	~Board();
	void Init(int Y, int X, int playing_Words);
	void View(void);
	void put_Word(int word_number);
	void view_Info(int word_number);
//	void read_File();
	bool check_if_Fits(int word_number);
	int get_value(int a);

	int get_NumWords() { return NumWords; }
	int find(string);

	void less_NumWords(void); // para decrementar o NumWords
	void less_remainingWords(void);
	void set_remainingWords(int a) { remainingWords = a; }
	int get_remainingWords(void) { return remainingWords; }

	inline void Set_BoardWidth(int bw) { BoardWidth = bw; }
	inline void Set_BoardHeight(int bh) { BoardHeight = bh; };



};

