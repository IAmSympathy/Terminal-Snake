#pragma once

class Game
{
private:
	bool _gameOver;		//si on perd

	int _direction,		//la direction choisie
		_cptLive,		//le compteur de vie
		_score;			//le score de la game

	Snake _snake;		//le snake
	Apple _apple;		//la pomme
	Rectangle _plateau;	//rectangle du terrain de jeu
	int _width = 40;	//Largeur - dimension du terrain de jeu
	int _height = 20;	//Hauteur - dimension du terrain de jeu


	enum direction { STOP, LEFT, RIGHT, UP, DOWN, NONE };

public:
	Game();											//initialise les types primitifs à 0
	~Game();										//initialise les types primitifs à 0
	void initialize();								//initalise le jeu

	Point randPosition()const;						//génère une nouvelle position aléatoire dans le terrain
	void createApple();								//génère une nouvelle pomme TQ position est dans le snake

	void StartMenu();								//Affiche le menu de départ du jeu
	void parametersMenu(int& color, int& dimension, int& hauteur, int& largeur, int& speed);
	//Affiche le menu des paramètres du jeu
	void play();									//la main loop du jeu
	void inputKey();								//la saisie des touches pour le déplacement du snake
	bool canMove(const Point& p) const;				//retourne vrai si la tête du snake peut bouger dans le jeu
	int getScore() const;							//retourne le score (seule info qui pourrait être intéressante 
													//de l’extérieur) et aucun setteur pour cet objet.
	void drawScreen();								//Affiche le terrain où le snake se promène

	void printScore(std::ostream& sortie) const;	//affiche le nombre de pommes mangées
	void printLive(std::ostream& sortie) const;		//affiche le compteur de vie
	void printEndGame(std::ostream& sortie) const;	//affiche game over et le nombre de pommes mangées
													//permet de charger les données provenant du fichier texte
	void loadParameters(int& color, int& dimension, int& hauteur, int& largeur, int& speed);
													//permet de sauvegarder les données de paramètre dans le fichier texte
	void saveParameters(int color, int dimension, int hauteur, int largeur, int speed) const;

	direction _dir;
};
