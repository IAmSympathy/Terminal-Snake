/*====================================
AUTEUR : Samy Larochelle
PROJET : TP1 SNAKE (2024)
NOM DU FICHIER : Rect.cpp
DATE : 26 f�vrier 2024
DESCRIPTION : D�finition des fonctions de rectangle
====================================*/
#include "Rect.h"
#include "Game.h"
#include <iostream>
#include <fstream>

Rect::Rect()
{
	Point p;
	_coord = p;
	_w = 1;
	_h = 1;
}

Rect::Rect(int x, int y, int w, int h)
{
	setRectangle(x, y, w, h);
}

Rect::~Rect()
{
	_w = 0;
	_h = 0;
}

int Rect::getH() const
{
	return _h;
}

int Rect::getW() const
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
		std::cout << "La longuer ne peut �tre negative" << std::endl;
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
		std::cout << "La hauteur ne peut �tre negative" << std::endl;
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

void Rect::read(std::istream& input)
{
	char skip;
	int w = 0, h = 0;
	getPosition().read(input);
	input >> w >> skip >> h;
	setRectangle(getPosition().getX(), getPosition().getY(), w, h);
}

void Rect::print(std::ostream& output) const
{
	output << "(" << _coord.getX() << "," << _coord.getY() << ") " << _coord.getColor() << " " << _w << " X " << _h << std::endl;
}

void Rect::draw(std::ostream&) const
{
	system("CLS");
	int color = 0;
	int dimension = 0;
	int _h = 0;
	int _w = 0;
	int speed = 0;

	ifstream load;
	load.open("setting.txt");
	if (!load)
	{
		cout << "ERREUR : Impossible d'ouvrir le fichier" << endl;
	}
	else
	{
		load >> color;
		load >> dimension;
		load >> _h;
		load >> _w;
		load >> speed;
	}
	load.close();



	for (int j = 0; j < _h + 1; j++)
	{
		for (int i = 0; i < _w + 1; i++)
		{
			goToXY(_coord.getX() + i, _coord.getY() + j);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _coord.getColor());

				if (j == 0 || j == _h)
				{
					std::cout << "\xFE";
				}
				else if (i == 0 || i == _w)
				{
					std::cout << "\xFE";
				}


		}
	}
}
