#ifndef ISINGMODEL_HPP
#define ISINGMODEL_HPP
#include "Model.hpp"
#include "Grid.hpp"
#include <random>
#include <math.h>
/*
 * Klasa dziedzicząca po Modelu, 
 * tutaj odbywa się symulacja na zewnętrznym obiekcie - Grid 
 *
 *
 * */
class IsingModel : public Model
{
	private:
		 /* klasa nie posiada pól, tylko metode która dokonuje symulacji  */
	public:
	
	IsingModel()
	{
	this->SetName("IsingModel"); /* konstruktor*/
	}
	/* pomocnicza funkcja modulo*/
    	unsigned modulo( int value, unsigned m)
       	{
    	int mod = value % (int)m;
    
	if (value < 0){ mod += m; }
    	return mod;
	}

	/*
	 * 
	 * Główna metoda klasy, przekazane parametry do symulacji to temperatura 
	 * i ilość kroków symulacji 
	 * */
	
	void Iteration(Grid * grid, float T, long epochs)
	{	

		int c = 0;            // pomocnicze zmienne 
		int r = 0;
		int h = 0;	      // hamiltonianu 
		int s = 0;	      // stan komórki 	
		
		float cost = 0; 
		
		int RowColTab[2][4]; // pomocnicza tabela do przetrzymywania stanów sąsiadów
		
		// wykonaj  epochs  kroków symulacji 

		for(double i= 0 ; i < epochs ; i++)
		{
				// losowanie punktu 
				c = rand() % grid->GetColumns();
				r = rand() % grid->GetRows();   

				s = grid->GetCellVal( r , c ); 
					
				RowColTab[0][0] = modulo(r+1, grid->GetRows());
				RowColTab[1][0] = c;
				RowColTab[0][1] = r;
				RowColTab[1][1] = modulo(c+1 , grid->GetColumns());
				RowColTab[0][2] = modulo(r-1 , grid->GetRows());
				RowColTab[1][3] = modulo(c-1 , grid->GetColumns());
				RowColTab[1][2] = c;
				RowColTab[0][3] = r;
				
				// liczenie hamiltonianu sąsiadów wylosowanego punktu i samego punktu 
				
				h = grid->GetCellVal( RowColTab[0][0] , RowColTab[1][0]) + grid->GetCellVal( RowColTab[0][1] , RowColTab[1][1]) + grid->GetCellVal( RowColTab[0][2] , RowColTab[1][2]) +  grid->GetCellVal( RowColTab[0][3] , RowColTab[1][3]);
				
			       cost = 2 * s *h ; // obliczenie funkcji kosztu zmiany  

			       if( cost < 0 )   // jeśli koszt jest mniejszy niż 0 zmień stan komórki 
			       {s *= -1;}	 
			 	else if (  ((double) rand() / (RAND_MAX))< exp(-cost * T) ) // jeśli nie to wylosuj liczbę z zakresu [0;1], jeśli będzie mniejsza niż e^(-cost*T) to zmień stan    
				{	
					s *= -1;
				}	
				
				grid->GetCell(r,c).ChangeState(s); // zmień stan komórki w siatce 	
		

		}		
	}		

};
#endif
