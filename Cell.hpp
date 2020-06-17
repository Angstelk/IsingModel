#ifndef CELL_HPP
#define CELL_HPP
#include <SFML/Graphics.hpp>
#include "State.hpp"
/*
 * Klasa implementująca komórkę autoamtu 
 *
 */
class Cell
{
	private:
	
	State * CellState;                // wskaźnik na obiekt State
	sf::RectangleShape * Cell_pt;    // wskaźnik na obiekt z biblioteki graficznej 
	
	float Size;			// Rozmiar komórki
	int X_pos;			// koordynaty komórki 
        int Y_pos;					
	
	int StateR; 			// Składowe koloru komórki
	int StateG;
	int StateB;
	
	
	public:
	Cell();
	// konstruktor parametryczny komórki 
	Cell(float size, int x,int y, int val, sf::Color SUp, sf::Color SDown );
	
	 
	float GetPix(); 
	
	sf::RectangleShape * getCell();
	// inicjalizacja funkcji zmieniającej pozcje komórki 
	void SetPos(int x,int y);
	// inicjalizacja funkcji ustawiającej rozmiar komórki 
	void SetSize(float size);

	// inicjalizacja funkcji zmieniającej stan komórki na przeciwny 
	void ChangeState(int s);

	// inicjalizacja fynkcji zmieniających stan komórki na wysoki, niski  
	void StateCellUp();
	void StateCellDown();

	// inicjaliacja metod zwracajacych pozycje danej komórki 
	int GetX();
	int GetY();
	
	// zrandomizuj stan komórki 
	int RandomState();
	
	int GetState();	
};
#endif
