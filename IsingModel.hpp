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
	long int steps_of_simulation =230000;
 	//230000; // parametry do symulacji
		//long int steps_of_simulation = 100000; // parametry do symulacji
	int skip_first_steps = 30000;
	int inter = 100;
	
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
	void CalcPhysicalParameters(Grid *grid, float* usedConfigs, float* m, int option, int MCS)
	{	
		float mTemp=0;
		// flips 
		float flip_temp = 0;
		for(int x=0;x<grid->GetColumns();x++)
		{
			for(int y=0;y<grid->GetRows();y++)
			{
				mTemp +=grid->GetCellVal(x,y);
			}	
		}	
		
		if(option == 1)
		{
		flip_temp = mTemp/ ((grid->GetRows()*grid->GetColumns()));
		printf("%d , %.3f \n", MCS, flip_temp );
		}
		if(option == 3 ) // namagnesowanie 
		{

		mTemp = abs(mTemp)/ (grid->GetRows()*grid->GetColumns());
		*m += mTemp;
		}
		
	}

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

	// ceon with next and prev  table 
	double CEoNP(Grid * grid, int r, int c, int* N, int *  P  )
	{
				
	 double de = 2* grid->GetCellVal(r,c) * ( grid->GetCellVal(N[r],c) + grid->GetCellVal(P[r],c) + grid->GetCellVal(r,N[c]) + grid->GetCellVal(r,P[c]));
	
	return de;
	
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
	
	void Iteration(Grid * grid, int option, float T_opt )
	{	

		int c = 0;            // pomocnicze zmienne 
		int r = 0;
		int h = 0;	      // hamiltonianu 
		int s = 0;	      // stan komórki 	
		
		float dE = 0; 
		int P[grid->GetRows()];
		int N[grid->GetColumns()];
		for(int i = 0; i < grid->GetRows(); i++)
		{//nearest neighbor
		
		N[i] = i + 1;//next
		P[i] = i - 1;//previous
		
		}
		
		P[0] = grid->GetRows()-1;
		N[grid->GetRows()-1] = 0;			

		
	//	int RowColTab[2][4]; // pomocnicza tabela do przetrzymywania stanów sąsiadów
		
		//printf(" Magnetisation : %lf energy : %lf \n",GetM(), GetE());		
		float  m = 0,  usedConfigs = (steps_of_simulation-skip_first_steps)/inter;
		double omega ; 
		float R;
		int S[grid->GetColumns()][grid->GetColumns()];
		
		for(int i = 0; i <grid->GetColumns() ; i++){//initial config
			
			for(int j = 0; j < grid->GetColumns(); j++)
			{
				S[i][j] = 1;
			}
		}

		for(int i= 0 ; i < steps_of_simulation ; i++)
		{
					// MCS - iteracja po siatce
				for(int x = 0; x < grid->GetColumns();x++)
				{
					for(int y = 0; y < grid->GetRows();y++)
					{		
						c = y;
						r = x;   

						s = grid->GetCellVal( r , c ); 
			       			dE = CEoNP(grid,r,c,N,P); 

			       			if( dE< 0 )   // jeśli koszt jest mniejszy niż 0 zmień stan komórki 
						{s *= -1;}	 
			 			else 
						{
						 
						 omega = exp(-dE/T_opt);
						 R = (float)rand()/RAND_MAX;
						if(R <= omega)
						{
						s *= -1;
						}		
						}   
						
						grid->GetCell(r,c).ChangeState(s); // zmień stan komórki w siatce 	
		

					}
				}

				if(modulo(i, inter)==0 && i>=skip_first_steps)
				{ 
					CalcPhysicalParameters( grid, &usedConfigs,&m,option, i);	
					
				}
		}
		if(option == 3 )
		{
			
		m /= usedConfigs;
		printf(" %.3f , %.3f \n" ,T_opt,  m );
		//printf("m = %.3e , T= %.3f, L = %d \n" , m , T_opt, grid->GetColumns());	
		}	
}		



	void CalcE(Grid * grid  )
	{	E = 0;
		double de;
		int r;
		int c;
		
		for(int i = 0;i < grid->GetRows();i++)
		{	
			for(int j = 0 ;j < grid->GetColumns(); j++)
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
};
#endif
