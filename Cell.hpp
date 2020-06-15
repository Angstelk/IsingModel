#ifndef CELL_HPP
#define CELL_HPP
#include <SFML/Graphics.hpp>
#include "State.hpp"

class Cell
{
	private:
	
	State * CellState;
	sf::RectangleShape * Cell_pt; 
	
	float Size;
	int X_pos;
        int Y_pos;	
	
	int StateR;
	int StateG;
	int StateB;
	
	
	public:
	Cell();

	Cell(float size, int x,int y, int val, sf::Color SUp, sf::Color SDown );

	float GetPix();
	sf::RectangleShape * getCell();
	void SetPos(int x,int y);
	void SetSize(float size);
	void ChangeState(int s);
	void StateCellUp();
	void StateCellDown();
	int GetX();
	int GetY();
	int RandomState();
	int GetState();	
};
#endif
