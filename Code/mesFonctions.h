/*====================================
AUTEUR : Samy Larochelle et Loucas Viens
PROJET : TP1 SNAKE (2024)
NOM DU FICHIER : mesFonctions.h
DATE : 26 février 2024
DESCRIPTION : Contient les prototypes des fonctions
====================================*/
#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Point.h"

void goToXY(int xpos, int ypos); //Déplace le curseur a une position
void afficherForme(const Point tabPoints[], int longueur, std::ostream& monFlux); //Affiche une table de point
void viderBuffer(); //Vide le buffer