#include "Rect.h"

Rect::Rect()
{
	Point p;
	_coord = p;
	_w = 1;
	_h = 1;
}

Rect::Rect(int x, int y, int w, int h)
{
	_coord.setPosition(x, y);
	_w = w;
	_h = h;
}

Rect::~Rect()
{
	_w = 0;
	_h = 0;
}

int Rect::getH()
{
	return _h;
}

int Rect::getW()
{
	return _w;
}


Point& Rect::getPosition()
{
	return _coord;
}

const Point &Rect::getPosition() const
{
	return _coord;
}

void Rect::setWidth(int w)
{
	if (w > 0)
	{
		_w = w;
	}
	else
	{
		std::cout << "La longuer ne peut être negative" << std::endl;
	}
}

void Rect::setHeight(int h)
{
	if (h > 0)
	{
		_h = h;
	}
	else
	{
		std::cout << "La hauteur ne peut être negative" << std::endl;
	}
}

void Rect::setSize(int w, int h)
{
	setWidth(w);
	setHeight(h);
}

void Rect::setRectangle(int x, int y, int w, int h)
{
	setSize(w, h);
	getPosition().setPosition(x, y);
}
