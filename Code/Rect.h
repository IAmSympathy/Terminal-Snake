/*====================================
AUTEUR : Samy Larochelle
PROJET : TP1 SNAKE (2024)
NOM DU FICHIER : Rect.h
DATE : 26 février 2024
DESCRIPTION : Classe du Rectangle
====================================*/
#pragma once
#include "Point.h"
#include <iostream>
#include <fstream>
#include "mesFonctions.h"

using namespace std;

class Rect
{
private:
	Point _coord; //Coordonee
	int _w; //Largeur
	int _h; //Hauteur
public:
	//Constructeurs
	Rect(); 
	Rect(int x,int y, int w, int h); 

	//Destructeur
	~Rect();

	//Getteurs
	int getH() const;
	int getW() const;
	Point& getPosition();
	const Point &getPosition() const;

	//Setteurs
	void setWidth(int w);
	void setHeight(int h);
	void setSize(int h, int w);
	void setRectangle(int x, int y, int w,int h);


	void read(std::istream&); //lit la taille et la hauteur dans un fichier
	void print(std::ostream&) const; //Affiche les coordonees dans la console
	void draw(std::ostream&) const; //Affiche un carre a chaque point du rectangle
};

