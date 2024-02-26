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
	Point(const Point& p);


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

	void draw(std::ostream& os) const;
	void print(std::ostream& sortie) const;
};