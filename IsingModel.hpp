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
 */
class IsingModel : public Model
{
	private:
	
	double M;		// average value of spin
	double J;		// strenght of exchange interaction if  > 0 
	double T;		// 1/temp * k ( stała Stefena Boltzmana )
	double E; 		// Energy of configuration
	public:
	

	IsingModel()
	{
	this->SetName("IsingModel"); /* konstruktor*/
	M = 0; 
	J = 1;
	T = 0;
	}

	IsingModel(double m, double j, double t)
	{
	this->SetName("IsingModel"); /* konstruktor*/
	M = m; 
	J = j;
	T = t;
	}
	
	double GetT()
	{
		return T;	
	}
	
	void SetT(double t)
	{
		T=t;
	}
	/* 
	 *Calculate Energy of Neighbourhood 
	 */
	double CEoN(Grid * grid, int r, int c )
	{
				int RowColTab[2][4]; 

			
				RowColTab[0][0] = modulo(r+1, grid->GetRows());
				RowColTab[1][0] = c;
				RowColTab[0][1] = r;
				RowColTab[1][1] = modulo(c+1 , grid->GetColumns());
				RowColTab[0][2] = modulo(r-1 , grid->GetRows());
				RowColTab[1][3] = modulo(c-1 , grid->GetColumns());
				RowColTab[1][2] = c;
				RowColTab[0][3] = r;


				double de = (grid->GetCellVal( RowColTab[0][0] , RowColTab[1][0]) + grid->GetCellVal( RowColTab[0][1] , RowColTab[1][1]) + grid->GetCellVal( RowColTab[0][2] , RowColTab[1][2]) +  grid->GetCellVal( RowColTab[0][3] , RowColTab[1][3]));
	
	return de;
	
	}

	void CalcE(Grid * grid  )
	{	E = 0;
		double de;
		int r;
		int c;

		for(int i = 0;i < grid->GetRows();i++)
		{
			for(int j = 0 ;j < grid->
				      GetColumns()	; j++)
			{
			
				r = i;
				c = j;

				int s = grid->GetCellVal( r , c ); 
				de = CEoN(grid, r, c);

				E += (-1)*s*de;
			}
		}

				E /= 4;
	}

	double GetE()
	{
		return E;
	}

	void CalcM(Grid * grid)
	{	
		M = 0;
		double sum=0;
		for(int i;i< grid->size();i++)
		{
			sum+= grid->GetCellVal(i);
		}
		M = sum /grid->size();
	}
	
	double GetM()
	{
		return M;
	}
	
	void SetJ(double  j)
	{
		J = j;
	}
	
	double GetJ()
	{
		return J;
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
	
	void Iteration(Grid * grid, long epochs)
	{	

		int c = 0;            // pomocnicze zmienne 
		int r = 0;
		int h = 0;	      // hamiltonianu 
		int s = 0;	      // stan komórki 	
		
		float dE = 0; 

		
	//	int RowColTab[2][4]; // pomocnicza tabela do przetrzymywania stanów sąsiadów
		
		// wykonaj  epochs  kroków symulacji 
		CalcM(grid);
		CalcE(grid);
		//printf(" Magnetisation : %lf energy : %lf \n",GetM(), GetE());		

		for(double i= 0 ; i < epochs ; i++)
		{
				// losowanie punktu 
				c = rand() % grid->GetColumns();
				r = rand() % grid->GetRows();   

				s = grid->GetCellVal( r , c ); 
			       	h = CEoN(grid,r,c); 
				dE = (2)* s *h ; // obliczenie zmiany energii   

			       if( dE< 0 )   // jeśli koszt jest mniejszy niż 0 zmień stan komórki 
			       {s *= -1;}	 
			 	else if (  ((double) rand() / (RAND_MAX ))< exp((-1) * dE*  T )) // jeśli nie to wylosuj liczbę z zakresu [0;1], jeśli będzie mniejsza niż e^(-cost/kT) to zmień stan    
				{	
					s *= -1;
				}	
				
				grid->GetCell(r,c).ChangeState(s); // zmień stan komórki w siatce 	
		

		}

	}		

};
#endif
