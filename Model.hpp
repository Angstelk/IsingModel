#ifndef MODEL_HPP
#define MODEL_HPP
#include "Grid.hpp"
#include <string>
/*
 * Klasa Model, po niej mogą dziedziczyć różne  symulacjie i modele 
 * (potencjał od rozwoju)
 *
 * */

class Model
{
	private:
	std::string name; /*nazwa modelu*/		
	public:
	
	Model()	{  name = "unnamed"; }	/* konstruktor  */
	Model(std::string n){name = n; } /* konstruktor parametryczny*/

	std::string GetName(){ 
	       return name;  } 
	void SetName( std::string n){ name = n; } /*metody get i set do pobrania i zmiany nazwy modelu  */
	virtual void Iteration(Grid * grid){ printf("Parent Model \n"); } /*metoda wirtualna do przeciążenia w każdym modelu dziedziczący po nim */

};

#endif
