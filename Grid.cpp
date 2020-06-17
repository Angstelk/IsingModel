#include "Grid.hpp"
#include "Cell.hpp"
#include <vector>
#include <stdlib.h>
Grid::Grid()
{
}
/*
 * Konstruktor parametryczny
 * NumColumns   - liczba kolumn siatki 
 * NumRows      - liczba rzędów 
 * SizeOfCell   - rozmiar komórki 
 * Su 		- kolor pierwszego stanu
 * Sd		- kolor drugiego stanu
 * */
Grid::Grid(int NumColumns, int NumRows, int SizeOfCell,sf::Color Su, sf::Color Sd)
{       
	
	Rows     = NumRows;    // przypisanie wartości 
	Columns  = NumColumns;   

	int Xpos = 0;		
	int Ypos = 0;		// ustalanie pozycji komórek 

	int r    = 0;		// inicjalizacyjny stan komórki  

	for( int i =0  ; i < NumRows ; i++)
	{ 
		for(int k = 0 ; k < NumColumns ; k++)
		{	
			r= rand() % 2; 
			if(r==0) r=-1;
			else r=1;
			Cells.push_back(Cell(SizeOfCell,Xpos,Ypos,r, Su, Sd));
			Xpos += SizeOfCell;
		}
	
	       	Ypos += SizeOfCell;
		Xpos = 0;
	}
}

/*
 * Funkcja losująca stany siatki
 *
 */

void Grid::RandomizeGrid(){

		for(unsigned int i=0;i<Cells.size();++i)
		{
		Cells[i].ChangeState(Cells[i].RandomState()); 
		}
}
