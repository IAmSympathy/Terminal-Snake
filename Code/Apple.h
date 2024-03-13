#pragma once
#include "Point.h"
#include <iostream>
#include <windows.h>
#include "mesFonctions.h"

class Apple {
private:
	Point _apple;					//position de la pomme
	Point _recu;
public:
	Apple();					//initialise la position à 0 et couleur rouge
	void setPosition(int x, int y);		//initialise la pomme à la position reçue
	const Point& getPosition() const;	 	//retourne la position de la pomme
	void draw(std::ostream& sortie) const;	//draw la pomme rouge
	int getx();
	int gety();
};
