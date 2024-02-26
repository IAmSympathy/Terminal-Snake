#pragma once
#include "Point.h"
#include <iostream>

class Rect
{
private:
	Point _coord;
	int _w;
	int _h;
public:
	Rect();
	Rect(int x,int y, int w, int h);

	~Rect();

	int getH();
	int getW();
	Point& getPosition();
	const Point &getPosition() const;

	void setWidth(int w);
	void setHeight(int h);
	void setSize(int h, int w);
	void setRectangle(int x, int y, int w,int h);
};

