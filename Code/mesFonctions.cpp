#include "mesFonctions.h"

//fonction pour se positionner dans l'écran à x,y
void goToXY(int xpos, int ypos) {
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void afficherForme(const Point tabPoints[], int longueur, std::ostream& monFlux)
{
	int x = 0, y = 0, color = 0;
	for (int i = 0; i < longueur; i++)
	{
		tabPoints[i].draw(std::cout);
	}
}

void viderBuffer()
{
	std::cin.clear();
	std::cin.seekg(0, std::ios::end);
	if (!std::cin.fail()) {
		std::cin.ignore(1000);
	}
	else {
		std::cin.clear();
	}
}
