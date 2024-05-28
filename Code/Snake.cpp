/*====================================
AUTEUR : Samy Larochelle
PROJET : TP1 SNAKE (2024)
NOM DU FICHIER : Snake.cpp
DATE : 6 mars 2024
DESCRIPTION : Définition des méthodes du serpent
====================================*/
#include "Snake.h"

Snake::Snake()
{
	_speed = 100;
	_size = 6;
}

Snake::Snake(int x, int y)
{
	_snake[0].setPosition(x, y);
	_speed = 100;
	_size = 6;
}

Snake::~Snake()
{
	_speed = 0;
	_size = 0;
}

void Snake::initialize(int x, int y, int color, int size, int speed)
{
	_snake[0].setPoint(x, y, color);
	_speed = speed;
	_size = size;
}

int Snake::getSize() const
{
	return _size;
}

int Snake::getSpeed() const
{
	return _speed;
}

Point& Snake::getPosition(int ind)
{
	return 	_snake[ind];
}

Point& Snake::operator[](int ind)
{
	return 	_snake[ind];
}

void Snake::setSize(int size)
{
	_size = size;
}

void Snake::setSpeed(int speed)
{
	_speed = speed;
}

void Snake::setColor(int color)
{
	_snake[0].setColor(color);
}

Point Snake::newPosition(int dir) const
{
	Point newPos;
	switch (dir)
	{
	case 1:
		newPos.setX((_snake[0].getX() - 1));
		newPos.setY(_snake[0].getY());
		break;
	case 2:
		newPos.setX((_snake[0].getX() + 1));
		newPos.setY(_snake[0].getY());
		break;
	case 3:
		newPos.setY((_snake[0].getY() - 1));
		newPos.setX(_snake[0].getX());
		break;
	case 4:
		newPos.setY((_snake[0].getY() + 1));
		newPos.setX(_snake[0].getX());
		break;
	}
	return newPos;
}

bool Snake::ifCollision(const Point& pos) const
{
	for (int i = 0; i < _size; i++)
	{
		if (pos.getX() == _snake[i].getX() && pos.getY() == _snake[i].getY())
		{
			return true;
		}
	}
}

void Snake::move(int dir)
{
	Point oldPos[800];
	int keepColor = _snake[0].getColor();
	for (int i = 0; i < _size + 1; i++)
	{
		oldPos[i] = _snake[i];
	}
	_snake[0] = newPosition(dir);

	for (int i = 1; i < _size + 1; i++)
	{
		_snake[i] = oldPos[i - 1];
	}
	_snake[0].setColor(keepColor);
}

void Snake::eat()
{
	_size++;
}

void Snake::draw(std::ostream& sortie)
{
	Point derPoint;
	for (int i = 0; i < _size + 1; i++)
	{
		goToXY(_snake[i].getX(), _snake[i].getY());
		//Changer la couleur du texte en console à partir de la couleur du point
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _snake[0].getColor());
		//Afficher le point avec la couleur spécifiée
		std::cout << "\xFE";
		derPoint = _snake[i];
	}
	goToXY(derPoint.getX(), derPoint.getY());
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	std::cout << "\xFE";
}

