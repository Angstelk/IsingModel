#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.hpp"
// konsruktor 
Cell::Cell()
{	
	StateR 	= 0;
	StateG 	= 0;
	StateB 	= 0;
	Size  	= 0;
	X_pos 	= 0;
	Y_pos 	= 0;
	Cell_pt = NULL;
	CellState = new State();
}


// konstruktor parametryczny 
Cell::Cell(float size, int x,int y, int val,sf::Color SUp, sf::Color SDown )
{
	
	Size    = size;
	X_pos   = x;
	Y_pos   = y;
	Cell_pt = new sf::RectangleShape( sf::Vector2f( size , size )); 
	Cell_pt->setPosition( X_pos , Y_pos );
	CellState = new State( SUp , SDown , val );
	Cell_pt->setFillColor(CellState->GetColour());
}

float Cell::GetPix(){return Size;}	

sf::RectangleShape * Cell::getCell()
{
	return Cell_pt;
}

void Cell::SetPos(int x ,int y)
{
	X_pos = x;
	Y_pos = y;
    	Cell_pt->setPosition( X_pos , Y_pos );
}

void Cell::ChangeState(int s)
{
	CellState->SetState(s);
	Cell_pt->setFillColor(CellState->GetColour());
}

void Cell::StateCellUp()
{
	CellState->SetStateUp();
	Cell_pt->setFillColor(CellState->GetColour());
}

void Cell::StateCellDown()
{
	CellState->SetStateDown();
	Cell_pt->setFillColor(CellState->GetColour());
}

void Cell::SetSize(float size){Size = size;}
int Cell::GetX(){return X_pos;}
int Cell::GetY(){return Y_pos;}

int Cell::RandomState()
{
	return CellState->GenerateRandomState();
}

int Cell::GetState()
{
	return CellState->GetState(); 
}

