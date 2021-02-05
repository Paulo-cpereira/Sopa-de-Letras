#pragma once
class Char
{
private:
	char Ch;
	bool state;

public:
	Char();
	Char(char);
	~Char();

	void Rand();
	void View();

	void set_State(bool S) { state = S; }
	bool get_State() { return state; };

	void set_Ch(char);
	char get_Ch(void) { return Ch; };



};

