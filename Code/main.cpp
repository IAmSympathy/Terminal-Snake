#include "Point.h"
#include "Rect.h"
#include <iostream>
#include <fstream>
#include "mesFonctions.h"

using namespace std;

int main() {

	string input = "";
	Rect r1;
	std::cout << "Saisir coordonnees du rectangle, couleur, largeur, hauteur : (x,y) color w X h : ";
	r1.read(cin);
	cout << endl;
	r1.print(cout);

	r1.draw(cout);




	system("pause");

}
