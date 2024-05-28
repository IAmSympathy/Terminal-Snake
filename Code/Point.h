/*====================================
AUTEUR : Samy Larochelle 
PROJET : TP1 SNAKE (2024)
NOM DU FICHIER : Point.h
DATE : 26 f�vrier 2024
DESCRIPTION : Classe du Point
====================================*/
#pragma once

#include <fstream>

class Point {
private:
	int _x, _y;			//coordonn�es du point
	int _color;			//couleur du point

public:
	// constructeur
	Point();			//Constructeur sans param�tre
	Point(int x, int y, int color);	//Constructeur avec param�tres
	Point(const Point& p); //Constructeur de copie


	//destructeur
	~Point();		//remet le point � l�origine

	//getteur
	int getX() const;
	int getY() const;
	int getColor() const;
	Point getPoint() const;

	//setteur
	void setX(int x);
	void setY(int y);
	void setPosition(int x, int y);
	void setColor(int color);
	void setPoint(int x, int y, int color);

	void draw(std::ostream& os) const; //Affiche un carr� a la position du point
	void print(std::ostream& sortie) const; //Affiche les coordonees dans la console
	void read(std::istream& input); //lit un point dans le fichier
};