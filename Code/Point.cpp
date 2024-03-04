#include "Point.h"
#include "mesFonctions.h"
#include <windows.h>
#include <iostream>

Point::Point()
{
	_x = _y = 0,
	_color = 7;

}

Point::Point(int x, int y, int color) {
	_x = x;
	_y = y;
	_color = 7;	//couleur Lite gray par défaut
}

Point::Point(const Point& p)
{
	_x = p.getX();
	_y = p.getY();
	_color= p.getColor();
}

Point::~Point()
{
	_color = _x = _y = 0;
}

int Point::getX() const
{
	return _x;

}int Point::getY() const
{
	return _y;

}int Point::getColor() const
{
	return _color;

}Point Point::getPoint() const
{
	return *this;
}

void Point::setX(int x)
{
	_x = x;
}
void Point::setY(int y)
{
	_y = y;
}

void Point::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Point::setColor(int color)
{
	_color = color;
}

void Point::setPoint(int x, int y, int color)
{
	_x = x;
	_y = y;
	_color = color;
}

void Point::draw(std::ostream& os) const
{
	  //Utiliser la fonction goToXY pour se positionner
		goToXY(_x, _y);
	  //Changer la couleur du texte en console à partir de la couleur du point
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
	  //Afficher le point avec la couleur spécifiée
		std::cout << "\xFE";
}
void Point::print(std::ostream &sortie) const
{
	sortie << "(" << _x << ", " << _y << ") " << _color;
}

void Point::read(std::istream& input)
{
	{
		int x = 0, y = 0, color = 0;
		char skip;
		input >> skip >> x >> skip >> y >> skip >> color;
		setPoint(x, y, color);
	}
}


