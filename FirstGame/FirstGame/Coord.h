#pragma once
class Coord
{
public:
	Coord();
	Coord(int x, int y);
	~Coord();

	void init(int x, int y);

	void setX(int x);
	void setY(int y);

	int getX();
	int getY();

	bool isInitialized();

private:
	bool _init;
	int _x;
	int _y;
};

