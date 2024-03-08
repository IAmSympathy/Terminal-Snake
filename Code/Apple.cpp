#include "Apple.h"

Apple::Apple()
{
	_apple.setPoint(0, 0, 4);
}

void Apple::setPosition(int x, int y)
{
	_apple.setPosition(x, y);
}

const Point& Apple::getPosition() const
{
	return _apple.getPoint();
}

void Apple::draw(std::ostream& sortie) const
{
	//Utiliser la fonction goToXY pour se positionner
	goToXY(_apple.getX(), _apple.getY());
	//Changer la couleur du texte en console à partir de la couleur du point
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _apple.getColor());
	//Afficher le point avec la couleur spécifiée
	std::cout << "\xFE";
}
