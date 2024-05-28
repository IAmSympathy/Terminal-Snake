/*====================================
AUTEUR : Samy Larochelle et Loucas Viens
PROJET : TP1 SNAKE (2024)
NOM DU FICHIER : Game.cpp
DATE : 2 mars 2024
DESCRIPTION : Définition des méthodes du jeu
====================================*/
#include "Game.h"

using namespace std;

void Game::StartMenu() {
	int reponse = 0;
	bool switch1 = true;
	loadParameters();
	int couleur = _snake[0].getColor();
	int dimensionSnake = _snake.getSize();
	int dimensionPlateauH = _plateau.getH();
	int dimensionPlateauL = _plateau.getW();
	int vitesseSnake = _snake.getSpeed();
	
	do
	{
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		_dir = LEFT;
		_gameOver = false;
		cout << endl << "Bienvenue au Snake en CONSOLE!" << endl << endl;
		cout << "1- Jouer au Snake" << endl;
		cout << "2- Parametres du jeu" << endl;
		cout << "3- Quitter" << endl;
		cout << endl << "Votre choix : ";
		cin >> reponse;

		viderBuffer();
		
		switch (reponse)
		{
		case 1:
			play();
			break;
		case 2:
		parametersMenu(couleur,dimensionSnake, dimensionPlateauH, dimensionPlateauL, vitesseSnake);
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
		loadParameters();
		cout << endl << "Voici les parametres qui peuvent etre modifie dans le jeu Snake" << endl << endl;
		cout << "1- Couleur du snake" << endl;
		cout << "2- Dimensions du snake" << endl;
		cout << "3- Dimensions du plateau" << endl;
		cout << "4- Vitesse du snake" << endl;
		cout << "5- Revenir au menu precedent" << endl;
		cout << endl << "Votre choix : ";
		cin >> reponse;

		viderBuffer();
					
		switch(reponse){
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
				do
				{
					system("CLS");
					cout << "Entrez la dimension du plateau de jeu que vous desirez!" << endl;
					cout << "Entrez la hauteur. Celle-ci dois se trouver entre 10 et 25! " << endl;
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
			saveParameters(color, dimension, hauteur, largeur, speed);
			switch2 = false;
			StartMenu();
			break;
		default:
			cout << "Choisissez une option entre 1 et 5!";
			switch2 = true;
			cin.ignore();
			cin.get();
			system("CLS");
			break;
		}
	Game::parametersMenu(color, dimension, hauteur, largeur, speed);
	} while (switch2 == true);
}

void Game::play()
{
	loadParameters();
	_cptLive = 3;
	_score = 0;
	drawScreen();
	int nbMurs = 0;
	Point Murs[800];
	int hauteurMur = 1;
	randPosition();
	for (int i = 0; i < _plateau.getW() + 1; i++)
	{
		Murs[i].setX(i);

		if (i == _plateau.getW())
		{
			i++;
			for (int j = 1; j < _plateau.getH() + 1; j++)
			{

				Murs[i].setY(j);
				Murs[i].setX(0);
				i++;
				Murs[i].setX(_plateau.getW());
				Murs[i].setY(j);
				i++;
			}
		}
		nbMurs = i - 1;
	}
	for (int i = 0; i < _plateau.getW() + 1; i++)
	{
		Murs[nbMurs + 1].setX(i);
		Murs[nbMurs + 1].setY(_plateau.getH());
		nbMurs++;
	}
	initialize();
	printScore(cout);
	printLive(cout);
	do
	{
		inputKey();
		if (_dir != STOP)
		{
			for (int i = 0; i < nbMurs + 1; i++)
			{
				if (_snake.newPosition(_dir).getX() == Murs[i].getX() && _snake.newPosition(_dir).getY() == Murs[i].getY())
				{
					_cptLive--;
					printLive(cout);
					if (_cptLive == 0)
					{
						_gameOver = true;
					}
					else
					{
						drawScreen();
						initialize();
						printScore(cout);
						printLive(cout);
						randPosition();
					}
				}
			}
			for (int i = 0; i < _snake.getSize() + 1; i++)
			{
				if (_snake.newPosition(_dir).getX() == _snake[i].getX() && _snake.newPosition(_dir).getY() == _snake[i].getY())
				{
					_cptLive--;
					if (_cptLive == 0)
					{
						_gameOver = true;
					}
					drawScreen();
					printScore(cout);
					initialize();
					printLive(cout);
					randPosition();
				}
			}
			if (_snake[0].getX() == _apple.getx() && _snake[0].getY() == _apple.gety())
			{
				_snake.eat();
				_score++;
				randPosition();
				printScore(cout);
				printLive(cout);
			}
			else
			{
				_snake.move(_dir);
			}

			_snake.draw(std::cout);
			Sleep(_snake.getSpeed());
		}
	} while (_gameOver != true);

	if (_dir != STOP)
	{
		printEndGame(cout);
	}
	StartMenu();
}

void Game::inputKey() {
	int touche;
	if (_kbhit()) {			//si une touche est enfonc�e
		touche = _getch();		//saisit la touche

		if (touche == 'q') {		//si la touche est q, on veut arr�ter le jeu
			_gameOver = true;
			_dir = STOP;
		}
		else if (touche == 224) {	//si la touche est 224, c�est une fl�che
			touche = _getch();	//dans le buffer on prend la 2e partie de la touche
			switch (touche) {
			case 75:		//code ascii des fl�ches
				if (_dir != RIGHT)
				_dir = LEFT;
				break;
			case 72:
				if (_dir != DOWN)
				_dir = UP;
				break;
			case 80:
				if (_dir != UP)
				_dir = DOWN;
				break;
			case 77:
				if (_dir != LEFT)
				_dir = RIGHT;
			}
		}
	}
}

int Game::getScore(int score) const
{
	score = _score;
	return score;
}

void Game::drawScreen()
{

	_plateau.draw(cout);
}

void Game::printScore(std::ostream& sortie)
{
	goToXY(0, _plateau.getH() + 2);
	cout << "Nombre de pomme ramassees : " << _score << endl;
}

void Game::printLive(std::ostream& sortie) const
{
	cout << "Vos vies restantes : " << _cptLive << endl;
}

void Game::printEndGame(std::ostream& sortie) const
{
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "Vous avez perdu !" << endl << endl;
	system("PAUSE");
}

void Game::loadParameters()
{
	int color, dimension, hauteur, largeur, speed;

	ifstream load;
	load.open("setting.txt");
	if (!load)
	{
		cout << "ERREUR : Impossible d'ouvrir le fichier" << endl;
	}
	else
	{
		load >> color;
		_snake.setColor(color);
		load >> dimension;
		_snake.setSize(dimension);
		load >> hauteur;
		_plateau.setHeight(hauteur);
		load >> largeur; 
		_plateau.setWidth(largeur);
		load >> speed;
		_snake.setSpeed(speed);
	}
}

void Game::saveParameters(int color, int dimension, int hauteur, int largeur, int speed) const
{
	ofstream save;
	save.open("setting.txt");
	if (!save)
	{
		cout << "ERREUR : Impossible d'ouvrir le fichier" << endl;
	}
	else
	{
		save << color << endl;
		save << dimension << endl;
		save << hauteur << endl;
		save << largeur << endl;
		save << speed;

		cout << "Sauvegarde terminer" << endl;
	}
	save.close();
}

Game::Game()
{
	_gameOver = false;
	_dir = 1;
	_cptLive = 3;
	_score = 0;
	_width = 40;
	_height = 20;

}

Game::~Game()
{
	_gameOver = false;
	_dir = 0;
	_cptLive = 0;
	_score = 0;
	_width = 0;
	_height = 0;
}

void Game::initialize()
{
	_dir = LEFT;
	_snake.initialize(_plateau.getW() / 2, _plateau.getH() / 2, _snake[0].getColor(), _snake.getSize(), _snake.getSpeed());
	for (int i = 0; i < _snake.getSize(); i++)
	{
		_snake[i+1].setX(_snake[i].getX() + 1);
		_snake[i+1].setY(_snake[i].getY());
	}

}

void Game::randPosition()
{
	int X;
	int Y;
	do
	{
		X = (rand() % _plateau.getW() - 1) + 1;
	} while (X == 0);
	do
	{
		Y = (rand() % _plateau.getH() - 1) + 1;
	} while (Y == 0);
	_apple.setPosition(X, Y);
	for (int i = 0; i < _snake.getSize()+1; i++)
	{
		if (_apple.getx() == _snake[i].getX() && _apple.gety() == _snake[i].getY())
		{
			randPosition();
		}
	}
	goToXY(X, Y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	std::cout << "\xFE";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
