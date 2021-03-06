#include "Julia.h"


using namespace std;


// Initialisateur

Julia::Julia(std::function<Homogene (Homogene)> fonction, unsigned int borne, std::vector<Homogene> *cycles): fonctionIteree(fonction), borneDIteration(borne), cyclesAttractifs(cycles){}


// Test de convergence des itérées


Complexe Julia::convergenceDe(Homogene z, double parametreConvergence){

	// Etude de la convergence d'un point donné
	
	Homogene copie = z; // Utile pour la seconde partie de la fonction
	
	for (int j = 0; j <= borneDIteration; j++){
		for (int k = 0; k < cyclesAttractifs->size(); k++) {
			Homogene cycle = (*cyclesAttractifs)[k];
			if (cycle.distanceAvec(z) < parametreConvergence) {
				return Complexe(j,k+1); // correspond au message : j itérées, proche du cycle k
			}
		}
		z = fonctionIteree(z);
	}
	
	// Recherche d'un cycle en cas de non convergence
	/*/ À activer selon les cas, peut allonger la durer d'execution.
	//
	
	Cycle moteurDesCycles(fonctionIteree);
	Homogene cycle = moteurDesCycles.chercheUnCycleAuPoint(z, pointDefaut);
	
	if ((cycle.x != pointDefaut.x || cycle.y != pointDefaut.y)) {
		(*cyclesAttractifs).push_back(cycle);
		cout << "+1 spé";
		cycle.print();
		for (int j = 0; j<= borneDIteration ; j++) {
			if ( copie.distanceAvec(cycle) < parametreConvergence) {
				return Complexe(j, cyclesAttractifs->size());
			}
			copie = fonctionIteree(copie);
		}
	}
	
	//*/
	 
	return Complexe(borneDIteration); // renvoie le message qu'il n'y a pas eu de convergence

}
