#ifndef GRID_HPP
#define GRID_HPP
#include <vector>
#include "Cell.hpp"
/*
 * Klasa Grid przechowuje wektor obiektów typu Cell  
 *
 */


class Grid
{

	private:
 	
	std::vector<Cell> Cells;	
	int Rows;
	int Columns;	
	int SizeOfCell;
	sf::Color StateUp;
	sf::Color StateDown;

	public:

	Grid();
	
	// Konstruktor parametryczny 
	Grid( int NumColumns,int NumRows, int SizeofCell, sf::Color Su, sf::Color Sd );
	
	// przeciązenie operatra dostępu 
	Cell &  operator[](double i)
	{
		return Cells[i];
	}

	// fukcja zwracająca stan komórki w danej pozycji  
	int  GetCellVal(int Row , int Col)
	{
		

	
		if(Row > Rows || Col > Columns)
		{
			printf(" Error :  Index out of range \n");
			return 0;
		}
	
		return Cells[ Row * Rows + Col ].GetState();
	}
	
	int GetCellVal(int i)
	{
	return Cells[i].GetState();	
	}

	// funkcja zwraca referencje do danej komórki siatki
	Cell & GetCell(int r, int c )

	{
		return Cells[ r * Rows + c  ];
	}
	
	// przeciążenie operatora nawiasów 

	Cell & operator()( int r , int c )
	{
		return Cells[ r * Rows + c ]; 
	}	

	double size(){return Rows*Columns; }
	void CellUp(int r, int c);	
	// metody set get wektora komórek  
	int GetColumns(){ return Columns;  } 	
	int GetRows(){ return Rows;  } 	
	// funkcja zmieniajaca stany siatki na losowe 	
	int GetSizeOfCell(){ return SizeOfCell; }
	sf::Color GetColorUp(){ return StateUp;  }
	sf::Color GetColorDown(){return StateDown;  }
	void RandomizeGrid();
	void StateDownGrid();

};
#endif
