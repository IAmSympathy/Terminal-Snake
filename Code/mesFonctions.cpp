/*====================================
AUTEUR : Samy Larochelle et Loucas Viens
PROJET : TP1 SNAKE (2024)
NOM DU FICHIER : mesFonctions.cpp
DATE : 26 février 2024
DESCRIPTION : Définition des fonctions
====================================*/
#include "mesFonctions.h"

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
