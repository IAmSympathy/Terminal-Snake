#pragma once
#include "Point.h"
#include <windows.h>
#include "mesFonctions.cpp"

class Snake {
private:
	Point _snake[800];	//tableau pour toutes les positions du snake
	int _size;			//taille réelle du snake
	int _speed;
public:
	Snake();				//initialise la taille du snake à 6 et speed à 100  
	Snake(int x, int y);	//initialise la position ou une coordonnée(x, y), taille 6 et speed de 100 (snake)
	~Snake();				//remet le _size et la vitesse à 0

	//initialise le snake à partir de (x, y), une taille 6 et speed à 100
	void initialize(int x, int y, int color, int size, int speed);

	int getSize()const;							//retourne la taille du snake
	int getSpeed() const;						//retourne la vitesse du snake
	const Point& getHeadPosition() const;	    //retourne la position de la tête du snake
	Point& getPosition(int ind);				//retourne la position à l’indice reçue
	Point& operator[](int ind);	 				//opérateur qui appelle getteur de position
	void setSize(int size);						//Set la taille du snake entre 6 et 20
	void setSpeed(int speed);					//Set la vitesse du snake entre 50 et 125
	Point newPosition(int dir) const;	        //retourne la nouvelle position selon la direction

	bool ifCollision(const Point& pos) const;	//retourne vrai si la position reçue est en
	//collision avec une des positions du snake
	void move(int dir);							//avance le snake dans la bonne direction
	void eat(int dir);							//avance et mange une pomme dans la direction

	void draw(std::ostream& sortie);	 		//dessine le snake au complet
};

std::ostream& operator<<(std::ostream& sortie, Snake& s);