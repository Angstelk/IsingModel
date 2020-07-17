#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP
#include "Model.hpp"
#include "Grid.hpp"
#include <math.h>
/*
 * Klasa dziedzicząca po Modelu, 
 * tutaj odbywa się symulacja na zewnętrznym obiekcie - Grid 
 */
class GameOfLife : public Model
{
	private:
		 /* klasa nie posiada pól, tylko metode która dokonuje symulacji  */
	public:
	
	GameOfLife()
	{
	this->SetName("Game of Life"); /* konstruktor*/
	}
	/* pomocnicza funkcja modulo*/
    	
	unsigned modulo( int value, unsigned m)
       	{
    	int mod = value % (int)m;
    
	if (value < 0){ mod += m; }
    	return mod;
	}

	/* Moore Neigbourhood Values 
	 *
	 * function gets concrete cell by coordinates (r- row , c - column) 
	 * and write in tab N values of neighbour in sense of moore neighbourhood 
	 *
	 * returns number of alive cells on 8 
	 *
	 */

	int  MNV(int r,int c, int * NV, Grid * grid ) // moore neighbourhood 
	{
	
		int alivecells=0;
		
		int **N;
		N = new int *[2];
		
		for(int i = 0; i <2; i++)
   		N[i] = new int[8];
		
		IoNM( r , c ,  grid, N  );
		

		NV[0] = grid->GetCellVal(N[0][0],N[1][0]); 
		NV[1] = grid->GetCellVal(N[0][1],N[1][1]); 
		NV[2] = grid->GetCellVal(N[0][2],N[1][2]); 
		NV[3] = grid->GetCellVal(N[0][3],N[1][3]); 
		NV[4] = grid->GetCellVal(N[0][4],N[1][4]); 
		NV[5] = grid->GetCellVal(N[0][5],N[1][5]); 
		NV[6] = grid->GetCellVal(N[0][6],N[1][6]); 
		NV[7] = grid->GetCellVal(N[0][7],N[1][7]); 

		for(int i=0;i<8;i++)
		{
			if(NV[i] > 0) alivecells ++;
		}
		return alivecells;
	}	

	int IoNM(int r, int c, Grid * grid  ,int **N )//Index of Neighbours  Mapping - auxiliary function that mapps indexes of neighbour 
	{
	 
	 N[0][0] =  modulo(r-1, grid->GetRows());
	 N[1][0] =  modulo(c-1, grid->GetColumns());

	 
	 N[0][1] =  modulo(r-1, grid->GetRows());
	 N[1][1] =  modulo(c, grid->GetColumns());


	 N[0][2] =  modulo(r-1, grid->GetRows());
	 N[1][2] =  modulo(c+1, grid->GetColumns());


	 N[0][3] =  modulo(r, grid->GetRows());
	 N[1][3] =  modulo(c-1, grid->GetColumns());


	 N[0][4] = modulo(r, grid->GetRows());
	 N[1][4] = modulo(c+1, grid->GetColumns());

	 
	 N[0][5] = modulo(r+1, grid->GetRows());
	 N[1][5] = modulo(c-1, grid->GetColumns());


	
	 N[0][6] = modulo(r+1, grid->GetRows());
	 N[1][6] = modulo(c, grid->GetColumns());
	 
	 N[0][7] = modulo(r+1, grid->GetRows());
	 N[1][7] = modulo(c+1, grid->GetColumns());
	
	 return 0;
	}


	/*
	 * State of Cell Dependent of Neighbourhood 
	 * Funkcja zwraca :
	 * 		  1 jeśli komórka jest żywa w nowej epoce 
	 * 		  -1 jeśli komórka jest martwa w nowej epoce 
	 */

	int SoCDN( Grid * grid, int r , int c  ) 
	{
		 int state = grid->GetCellVal(r,c );
		 int NV[8];
		 int AC= MNV(r,c, NV ,grid);
		
	 	if(state == 1)
		{
		
			if(AC == 2 || AC == 3)			{
		
			return 1;
			}
			else
			{
				return -1;
			}

		}	 
		else
		{
			if(AC == 3)
			{	
			return 1;
			}
			else
			{
				return -1;
			}	
		}


	} 
	
	/*
	 * Główna metoda klasy,
	 * 
	 */
	void UpdateGrid(Grid * grid)
	{
		int map[grid->GetRows()][grid->GetColumns()];
		int n_state ;

		for(int r = 0 ; r < grid->GetRows() ; r++)
		 {

			for( int c = 0 ; c < grid->GetColumns();c++ )
			 {
				map[r][c] = SoCDN(grid,r,c);
			 }	 				 
		 }

			
		for(int r = 0 ; r < grid->GetRows() ; r++)
		 {

			for( int c = 0 ; c < grid->GetColumns();c++ )
			 {
				if(map[r][c]> 0 )
			 	{
			 	 grid->GetCell(r,c).StateCellUp();	
				}
			 	else 
			 	{
			 	 grid->GetCell(r,c).StateCellDown();	
			 	}

			}
		}
	}	
	void Iteration(Grid * grid)
	{	
	// tu będzie iterowane po każdym cellu i zmieniany stan w zależności od tego co zwroaca SoCne	
	UpdateGrid(grid);	

					

				// wykonaj  epochs  kroków symulacji 

	}		

};
#endif
