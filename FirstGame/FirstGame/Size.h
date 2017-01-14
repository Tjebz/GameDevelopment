#pragma once
class Size
{
public:
	Size();
	Size(int width, int heigth);
	~Size();

	void setWidth(int width);
	void setHeigth(int heigth);

	int getWidth();
	int getHeigth();

private:
	unsigned int _width;
	unsigned int _heigth;
};

