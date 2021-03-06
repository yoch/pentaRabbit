#ifndef __Simulation__Cycle__
#define __Simulation__Cycle__

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Algebre.h"

class Cycle {
	std::function<Homogene(Homogene)> fonctionIteree;
	
	double c_eps = 0.00005;
	
	bool donneUnCycle(Homogene z0);

	Homogene c_point = Homogene(0.0);
	Homogene pointDefaut = Homogene(Complexe(-1,-2),Complexe(-3,-4));
	Homogene pointInfini = Homogene(Complexe(1.0),Complexe(0.0));
	

	bool nEstPasDejaUnCycle(Homogene point, double parametreDistance = 0.005);
	
	std::vector<Homogene> cyclesAttractifs;
	void calculeLesCyclesAttractifs();
	bool premiereRechercheEffectuee = false;
	
public:
	
	Cycle(std::function<Homogene (Homogene)> fonctionAIterer):fonctionIteree(fonctionAIterer){};
	
	int c_borne = 100;
	
	void eps(double eps){c_eps = eps;}
	double eps(){return c_eps;}
	
	void borne(int borne){c_borne = borne;}
	int borne(){return c_borne;}
	
	std::vector<Homogene>* getCyclesAttractifs();
	
	Homogene chercheUnCycleAuPoint(Homogene z0, Homogene pointParDefaut);

	void chercheANouveau(Complexe origine, double echelle);
};

#endif /* defined(__Simulation__Cycle__) */
