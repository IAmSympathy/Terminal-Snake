#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Point.h"

void goToXY(int xpos, int ypos);
void ouvrirFichier(std::ifstream& monFlux, const std::string& nomFichier);
int lireFichier(std::ifstream& monFlux, Point tabPoints[]);
void afficherForme(const Point tabPoints[], int longueur, std::ostream& monFlux);