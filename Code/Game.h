/*====================================
AUTEUR : Samy Larochelle et Loucas Viens
PROJET : TP1 SNAKE (2024)
NOM DU FICHIER : Game.h
DATE : 2 mars 2024
DESCRIPTION : Classe du jeu
====================================*/
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
	Game();											//initialise les types primitifs a 0
	~Game();										//initialise les types primitifs a 0
	void initialize();								//initalise le jeu
	void randPosition();							//creer la pomme et genere une nouvelle position aleatoire dans le terrain

	void StartMenu();								//Affiche le menu au depart du jeu
	void parametersMenu(int& color, int& dimension, int& hauteur, int& largeur, int& speed);	//Affiche le menu des parametres du jeu

	void play();									//la main loop du jeu
	void inputKey();								//la saisie des touches pour le deplacement du snake
	int getScore(int score) const;					//retourne le score (seule info qui pourrait tres interessante de lextrieur) et aucun setteur pour cet objet.
													
	void drawScreen();								//Affiche le terrain o  le snake se prom ne

	void printScore(std::ostream& sortie);			//affiche le nombre de pommes mangees
	void printLive(std::ostream& sortie) const;		//affiche le compteur de vie
	void printEndGame(std::ostream& sortie) const;	//affiche game over et le nombre de pommes mang es
													
	void loadParameters();							//permet de charger les donnees provenant du fichier texte
													
	void saveParameters(int color, int dimension, int hauteur, int largeur, int speed) const; //permet de sauvegarder les donnees de parametre dans le fichier texte

};
