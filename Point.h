#pragma once
class Point
{
private:
	int x;
	int y;

public:
	Point();
	Point(int, int);
	~Point();

	void set_X(int);
	void set_Y(int);
	void set_P(int, int);
	void Update(Point);
	int get_X() const { return this->x; }
	int get_Y() const { return this->y; }
	bool isValid(void);
	bool AskToSet(void);
	void Rand(int, int);

	void Show();
	bool operator == (const Point) const;
};

