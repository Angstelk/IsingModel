#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Cell.hpp"
#include "Grid.hpp"
#include "Model.hpp"
#include "IsingModel.hpp"
#define WIDTH 50 // makro definiujące ilosć kolumn i wierszy siatki  
#define SIZE 2 	     // makro definiujące długosć boku kwadratowej komórki autoamtu w pikselach 		

int main(int argc, char* argv[] )
{

    float  t=0.49;  //parametr modelu 

    sf::RenderWindow window1(sf::VideoMode(WIDTH * SIZE,WIDTH * SIZE ), "Ising model1"); // tworzenie okna 
    sf::Color kolor1(33,66,255);
    sf::Color kolor2(2,255,90);
    
   sf::Color kolor11(255,33,66);
   sf::Color kolor22(66,33,255);
    // definiowanie kolorów reprezentujących stany 
    Grid * grid_ptr = new Grid(WIDTH,WIDTH,SIZE,kolor1,kolor2); // tworzy się instancja siatki o wymiarach WIDTH komórek (gdzie  każda komórka ma SIZE pikseli), stany są symbolizowane przez kolor 1 i 2  
    

    IsingModel * IM_ptr = new IsingModel(1, 2, t ); // instancja modelu
     grid_ptr->RandomizeGrid(); // siatka się losuje swoje stany


      	
	while (window1.isOpen()) 
	{
        	sf::Event event;



        	while (window1.pollEvent(event))
       		{
           		 if (event.type == sf::Event::Closed) // sprawdzanie czy nie zamknąłem okna
            		    window1.close();
		}
	
 	
			for(std::size_t i=0; i<grid_ptr->size(); ++i)
			{
				window1.draw(* grid_ptr->operator[](i).getCell());   // narysuj każdą komórkę w oknie
			}	

		window1.display(); // wyswietl stan siatki 

		 IM_ptr->Iteration(grid_ptr,10000);	// wykonaj 10000 kroków symulacji  modelu na siatce m  w zależności od temperatury t 


    }


    return 0;
}

