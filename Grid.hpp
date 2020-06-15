#ifndef GRID_HPP
#define GRID_HPP
#include <vector>
#include "Cell.hpp"

class Grid
{

	private:
 	std::vector<Cell> Cells;	
	int Rows;
	int Columns;	
	public:

	Grid();
	Grid( int NumColumns,int NumRows, int SizeOfCell, sf::Color Su, sf::Color Sd );

	Cell &  operator[](double i)
	{
		return Cells[i];
	}

	int  GetCellVal(int Row , int Col)
	{
		

//  printf("GET Val : %f  Row : %d , Columns : %d , col %d \n", static_cast<float> (Row * Columns + Col), Row, Columns, Col );
	
		if(Row > Rows || Col > Columns)
		{
			printf(" Error :  Index out of range \n");
			return 0;
		}
	
		return Cells[ Row * Rows + Col ].GetState();
	}
	
	Cell & GetCell(int r, int c )

	{//	printf("GET CELL CIPPA : %f ",  static_cast<float> (c * Columns + r  ));
		return Cells[ r * Rows + c  ];
	}
	
	Cell & operator()( int r , int c )
	{
		return Cells[ r * Rows + c ]; 
	}	

	double size(){return Rows*Columns; }
	int GetColumns(){ return Columns;  } 	
	int GetRows(){ return Rows;  } 	
	void RandomizeGrid();
};
#endif
