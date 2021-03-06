//
//  Dynamicien.hpp
//  Simulation Dynamiques
//
//  Created by Raphaël Alexandre on 02/01/2018.
//  Copyright © 2018 Raphaël Alexandre. All rights reserved.
//

#ifndef Dynamicien_h
#define Dynamicien_h

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <cmath>

#include "Algebre.h"
#include "Cycle.h"

#include "lodepng.h"

struct Dynamicien {
	int borneDIteration;

	std::function<Complexe(Homogene)> dynamique;
    std::vector<Complexe> creeLaMatrice(int longueur, int hauteur, double echelle, Complexe origine);


    // À vocation à disparaitre
	sf::VertexArray creeLaMatriceWin(int longueur, int hauteur, double echelle, Complexe origine);
    const char* filename =  "/Users/Raphael/Desktop/PhotoJulia.png";
    bool peindreEnBlanc = true;
};

std::vector<double> coloration(Complexe couleur, bool peindreEnBlanc);

#endif /* Dynamicien_h */
