#include <iostream>
#include <fstream>
#include <conio.h>
#include "Game.h"
#include "Snake.h"
#include "Apple.h"
#include "Rect.h"

using namespace std;

void Game::StartMenu() {
	int reponse = 0;
	bool switch1 = true;
	int couleur = 1;
	int dimensionSnake = 6;
	int dimensionPlateauH = 25;
	int dimensionPlateauL = 40;
	int vitesseSnake = 100;
	
	do
	{
		system("CLS");
		cout << endl << "Bienvenue au Snake en CONSOLE!" << endl << endl;
		cout << "1- Jouer au Snake" << endl;
		cout << "2- Parametres du jeu" << endl;
		cout << "3- Quitter" << endl;
		cout << endl << "Votre choix : ";
		cin >> reponse;

		void viderBuffer();
		{
			cin.clear();
			cin.seekg(0, ios::end);
			if (!cin.fail()) {
				cin.ignore(1000);
			}
			else {
				cin.clear();
			}
		}

		switch (reponse)
		{
		case 1:
			/*COMMENCER LE JEU*/
			break;
		case 2:
			
			break;
		case 3:
			exit(0);
			switch1 = false;
			break;
		default:
			cout << "Choisissez une option entre 1 et 3!";
			switch1 = true;
			cin.ignore();
			cin.get();
			system("CLS");
			break;
		}
	} while (switch1 == true);
}

void Game::parametersMenu(int& color, int& dimension, int& hauteur, int& largeur, int& speed)
{
	bool verification1 = true;
	bool verification2 = true;
	bool verification3 = true;
	bool verification4 = true;
	bool verification5 = true;
	int reponse = 0;
	bool switch2 = true;

	do
	{
		system("CLS");
		cout << endl << "Voici les parametres qui peuvent etre modifie dans le jeu Snake" << endl << endl;
		cout << "1- Couleur du snake" << endl;
		cout << "2- Dimensions du snake" << endl;
		cout << "3- Dimensions du plateau" << endl;
		cout << "4- Vitesse du snake" << endl;
		cout << "5- Revenir au menu precedent" << endl;
		cout << endl << "Votre choix : ";
		cin >> reponse;

		void viderBuffer();
		{
			cin.clear();
			cin.seekg(0, ios::end);
			if (!cin.fail()) {
				cin.ignore(1000);
			}
			else {
				cin.clear();
			}
		}

		switch (reponse)
		{
		case 1:
			do
			{
				system("CLS");
				cout << "Entrez la couleur du snake! Vous devez faire un choix entre 1 a 15! ";
				cin >> color;

				void viderBuffer();
				{
					cin.clear();
					cin.seekg(0, ios::end);
					if (!cin.fail()) {
						cin.ignore(1000);
					}
					else {
						cin.clear();
					}
				}

				if (color <= 15 && color >= 1)
				{
					verification1 = false;
				}
				else
				{
					cout << "Entrez un nombre entre 1 et 15!";
					cin.ignore();
					cin.get();
					verification1 = true;
				}
			} while (verification1 == true);
			break;
		case 2:
			do
			{
				system("CLS");
				cout << "Entrez la dimension du snake que vous desirez! Vous devez faire un choix entre 6 a 20! ";
				cin >> dimension;

				void viderBuffer();
				{
					cin.clear();
					cin.seekg(0, ios::end);
					if (!cin.fail()) {
						cin.ignore(1000);
					}
					else {
						cin.clear();
					}
				}

				if (dimension <= 20 && dimension >= 6)
				{
					verification2 = false;
				}
				else
				{
					cout << "Entrez un nombre entre 6 et 20!";
					cin.ignore();
					cin.get();
					verification2 = true;
				}
			} while (verification2 == true);
			break;
		case 3:
			do
			{
				do
				{
					system("CLS");
					cout << "Entrez la dimension du plateau de jeu que vous desirez!" << endl;
					cout << "Entrez la hauteur. Celle-ci dois se trouver entre 10 et 25! ";
					cin >> hauteur;

					void viderBuffer();
					{
						cin.clear();
						cin.seekg(0, ios::end);
						if (!cin.fail()) {
							cin.ignore(1000);
						}
						else {
							cin.clear();
						}
					}

					if (hauteur <= 25 && hauteur >= 10)
					{
						verification3 = false;
					}
					else
					{
						cout << "Entrez un nombre entre 10 et 25!";
						cin.ignore();
						cin.get();
						verification3 = true;
					}
				} while (verification3 == true);
				cout << "Entrez la largeur. Celle-ci dois se trouver entre 40 et 60! ";
				cin >> largeur;

				void viderBuffer();
				{
					cin.clear();
					cin.seekg(0, ios::end);
					if (!cin.fail()) {
						cin.ignore(1000);
					}
					else {
						cin.clear();
					}
				}

				if (largeur <= 60 && largeur >= 40)
				{
					verification4 = false;
				}
				else
				{
					cout << "Entrez un nombre entre 40 et 60!";
					cin.ignore();
					cin.get();
					verification4 = true;
				}
			} while (verification4 == true);
			break;
		case 4:
			do
			{
				system("CLS");
				cout << "Entrez la vitesse du snake que vous desirez! Vous devez faire un choix entre 50 a 125! La vitesse par defaut est de 100, si vous reduisez le nombre, le snake ira plus vite!" << endl;
				cout << "Entrer la vitesse. Celle-ci dois se trouver entre 50 et 125. ";
				cin >> speed;

				void viderBuffer();
				{
					cin.clear();
					cin.seekg(0, ios::end);
					if (!cin.fail()) {
						cin.ignore(1000);
					}
					else {
						cin.clear();
					}
				}

				if (speed <= 125 && speed >= 50)
				{
					verification5 = false;
				}
				else
				{
					cout << "Entrez un nombre entre 50 et 125!";
					cin.ignore();
					cin.get();
					verification5 = true;
				}
			} while (verification5 == true);
			break;
		case 5:
			switch2 = false;
			break;
		default:
			cout << "Choisissez une option entre 1 et 5!";
			switch2 = true;
			cin.ignore();
			cin.get();
			system("CLS");
			break;
		}
	Game::parametersMenu;
	} while (switch2 == true);
}

void Game::play()
{
}

void Game::inputKey() {
	int touche;
	if (_kbhit()) {			//si une touche est enfoncée
		touche = _getch();		//saisit la touche

		if (touche == 'q') {		//si la touche est q, on veut arrêter le jeu
			_gameOver = true;
			_dir = STOP;
		}
		else if (touche == 224) {	//si la touche est 224, c’est une flèche
			touche = _getch();	//dans le buffer on prend la 2e partie de la touche
			switch (touche) {
			case 75:		//code ascii des flèches
				_dir = LEFT;
				break;
			case 72:
				_dir = UP;
				break;
			case 80:
				_dir = DOWN;
				break;
			case 77:
				_dir = RIGHT;
			}
		}
	}
}

bool Game::canMove(const Point& p) const
{
}

int Game::getScore(int score) const
{
	score = _score;
	return score;
}

void Game::drawScreen()
{
	Rect::draw;
}

void Game::printScore(std::ostream& sortie) const
{

}

void Game::printLive(std::ostream& sortie) const
{
}

void Game::printEndGame(std::ostream& sortie) const
{
}

void Game::loadParameters(int& color, int& dimension, int& hauteur, int& largeur, int& speed)
{
}

void Game::saveParameters(int color, int dimension, int hauteur, int largeur, int speed) const
{
}

Game::Game()
{
}

Game::~Game()
{
}

void Game::initialize()
{
}

Point Game::randPosition() const
{
	return Point();
}

void Game::createApple()
{
}
