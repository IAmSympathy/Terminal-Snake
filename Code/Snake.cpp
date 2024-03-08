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
	_snake[0].setPoint(x,y,color);
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

const Point& Snake::getHeadPosition() const
{
	return 	_snake[0];
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

Point Snake::newPosition(int dir) const
{
	Point newPos(_snake[0].getX(), _snake[0].getY(), 7);
	switch (dir)
	{
	case1:
		newPos.setX((_snake[0].getX() - 1));
	case2:
		newPos.setX((_snake[0].getX() + 1));
	case3:
		newPos.setY((_snake[0].getY() + 1));
	case4:
		newPos.setY((_snake[0].getY() - 1));
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
	switch (dir)
	{
	case 1:
		for (int i = 0; i < _size; i++)
		{
			_snake[i].setX((_snake[0].getX() - 1));
		}
	case 2:
		for (int i = 0; i < _size; i++)
		{
			_snake[i].setX((_snake[0].getX() + 1));;
		}
	case 3:
		for (int i = 0; i < _size; i++)
		{
			_snake[i].setY((_snake[0].getY() + 1));
		}
	case 4:
		for (int i = 0; i < _size; i++)
		{
			_snake[i].setY((_snake[0].getY() - 1));
		}
	}
}

void Snake::eat(int dir)
{

}

void Snake::draw(std::ostream& sortie)
{
	//Utiliser la fonction goToXY pour se positionner
	for (int i = 0; i < _size; i++)
	{
		goToXY(_snake[i].getX(), _snake[i].getY());
	//Changer la couleur du texte en console à partir de la couleur du point
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _snake[i].getColor());
	//Afficher le point avec la couleur spécifiée
	std::cout << "\xFE";
	}
}
