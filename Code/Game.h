#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "Snake.h"
#include "Apple.h"
#include "Rect.h"

class Game
{
private:
	bool _gameOver;		//si on perd

	int _dir,			//la direction choisie
		_cptLive,		//le compteur de vie
		_score;			//le score de la game

	Snake _snake;		//le snake
	Apple _apple;		//la pomme
	Rect _plateau;		//rectangle du terrain de jeu
	int _width;			//Largeur - dimension du terrain de jeu
	int _height;		//Hauteur - dimension du terrain de jeu


	enum _dir { STOP, LEFT, RIGHT, UP, DOWN, NONE };

public:
	Game();											//initialise les types primitifs � 0
	~Game();										//initialise les types primitifs � 0
	void initialize();								//initalise le jeu
	void randPosition();							//g�n�re une nouvelle position al�atoire dans le terrain

	void StartMenu();								//Affiche le menu de d�part du jeu
	void parametersMenu(int& color, int& dimension, int& hauteur, int& largeur, int& speed);
													//Affiche le menu des param�tres du jeu
	void play();									//la main loop du jeu
	void inputKey();								//la saisie des touches pour le d�placement du snake
	int getScore(int score) const;					//retourne le score (seule info qui pourrait �tre int�ressante 
													//de l�ext�rieur) et aucun setteur pour cet objet.
	void drawScreen();								//Affiche le terrain o� le snake se prom�ne

	void printScore(std::ostream& sortie) const;	//affiche le nombre de pommes mang�es
	void printLive(std::ostream& sortie) const;		//affiche le compteur de vie
	void printEndGame(std::ostream& sortie) const;	//affiche game over et le nombre de pommes mang�es
													//permet de charger les donn�es provenant du fichier texte
	void loadParameters(int& color, int& dimension, int& hauteur, int& largeur, int& speed);
													//permet de sauvegarder les donn�es de param�tre dans le fichier texte
	void saveParameters(int color, int dimension, int hauteur, int largeur, int speed) const;

};
