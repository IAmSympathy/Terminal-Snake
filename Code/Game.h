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
	Game();											//initialise les types primitifs � 0
	~Game();										//initialise les types primitifs � 0
	void initialize();								//initalise le jeu

	Point randPosition()const;						//g�n�re une nouvelle position al�atoire dans le terrain
	void createApple();								//g�n�re une nouvelle pomme TQ position est dans le snake

	void StartMenu();								//Affiche le menu de d�part du jeu
	void parametersMenu(int& color, int& dimension, int& hauteur, int& largeur, int& speed);
	//Affiche le menu des param�tres du jeu
	void play();									//la main loop du jeu
	void inputKey();								//la saisie des touches pour le d�placement du snake
	bool canMove(const Point& p) const;				//retourne vrai si la t�te du snake peut bouger dans le jeu
	int getScore() const;							//retourne le score (seule info qui pourrait �tre int�ressante 
													//de l�ext�rieur) et aucun setteur pour cet objet.
	void drawScreen();								//Affiche le terrain o� le snake se prom�ne

	void printScore(std::ostream& sortie) const;	//affiche le nombre de pommes mang�es
	void printLive(std::ostream& sortie) const;		//affiche le compteur de vie
	void printEndGame(std::ostream& sortie) const;	//affiche game over et le nombre de pommes mang�es
													//permet de charger les donn�es provenant du fichier texte
	void loadParameters(int& color, int& dimension, int& hauteur, int& largeur, int& speed);
													//permet de sauvegarder les donn�es de param�tre dans le fichier texte
	void saveParameters(int color, int dimension, int hauteur, int largeur, int speed) const;

	direction _dir;
};
