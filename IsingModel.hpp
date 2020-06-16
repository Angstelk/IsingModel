#ifndef ISINGMODEL_HPP
#define ISINGMODEL_HPP
#include "Model.hpp"
#include "Grid.hpp"
#include <random>
#include <math.h>

class IsingModel : public Model
{
	private:
		
	public:

    	unsigned modulo( int value, unsigned m)
       	{
    	int mod = value % (int)m;
    
	if (value < 0){ mod += m; }
    	return mod;
	}

	void IsingIteration(Grid * grid, float T  )
	{	

		std::random_device rd;  //Will be used to obtain a seed for the random number engine
    		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    		std::uniform_real_distribution<> dis(1.0, 2.0);

		int c = 0;
		int r = 0;
		int h = 0;
		int s = 0;	
		
		float cost = 0;
		
		int RowColTab[2][4];
		
		int as;	
		
		int zmiany = 0 ;	
		
		for(double row = 1 ; row < grid->GetRows() ; row++)
		{
			for(double col = 1 ; col < grid->GetColumns() ; col++ )
			{	
				// losowanie punktu 
				c = rand() % grid->GetColumns();
				r = rand() % grid->GetRows();   

				s = grid->GetCellVal( r , c ); 
					
				as = s;	

				RowColTab[0][0] = modulo(r+1, grid->GetRows());
				RowColTab[1][0] = c;
				RowColTab[0][1] = r;
				RowColTab[1][1] = modulo(c+1 , grid->GetColumns());
				RowColTab[0][2] = modulo(r-1 , grid->GetRows());
				RowColTab[1][3] = modulo(c-1 , grid->GetColumns());
				RowColTab[1][2] = c;
				RowColTab[0][3] = r;
				
				// liczenie hamiltonianu sąsiadów punktu 
				
				h = grid->GetCellVal( RowColTab[0][0] , RowColTab[1][0]) + grid->GetCellVal( RowColTab[0][1] , RowColTab[1][1]) + grid->GetCellVal( RowColTab[0][2] , RowColTab[1][2]) +  grid->GetCellVal( RowColTab[0][3] , RowColTab[1][3]);
				
				cost = 2 * s *h ;
			       if( cost < 0 )
			       {s *= -1;}	 
			 	else if (  ((double) rand() / (RAND_MAX))< exp(-cost * T) )
				{	
				//	printf("Wylosowalismy i zmieniamy stan %d %d  \n ", a, b );
					s *= -1;
				}	
				
				if(as != s){ zmiany ++; }
				else{
				//grid->GetCell(r,c).ChangeState(s);	
				}
			
				grid->GetCell(r,c).ChangeState(s);		
		
			}

		}		

			//printf(" Zmiany %d \n " , zmiany);
			zmiany = 0;
	}		

};
#endif
