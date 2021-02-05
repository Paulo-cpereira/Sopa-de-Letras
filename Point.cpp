#include "Point.h"
#include <iostream>

using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int hight, int witdh)
{
	this->y = hight;
	this->x = witdh;
}

Point::~Point()
{
}

void Point::set_X(int X)
{
	if(X>=0)
		this->x = X;
}

void Point::set_Y(int Y)
{
	if(Y>=0)
		this->y = Y;
}

void Point::set_P(int Y, int X)
{
	y = Y;
	x = X;
}

void Point::Update(Point P)
{
	this->x = P.x;
	this->y = P.y;
}

bool Point::isValid(void)
{
	if (x >= 0 && y >= 0)
		return true;
	else
		return false;
}

bool Point::AskToSet(void)
{
	cout << "Digite o valor de Y" << endl;
	cin >> y;

	cout << "Digite o valor de X" << endl;
	cin >> x;
	return isValid();
}

void Point::Rand(int NC, int NL)
{
	x = rand() % NC;
	y = rand() % NL;
}

void Point::Show()
{
	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;
}

bool Point::operator==(const Point P) const
{
	if (this->x == P.x)
		if (this->y == P.y)
			return true;
	return false;
}
