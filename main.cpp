#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Cell.hpp"
#include "Grid.hpp"
#include "Model.hpp"
#include "IsingModel.hpp"
#define WIDTH 600     // makro definiujące ilosć kolumn i wierszy  
#define SIZE 1	     // makro definiujące długosć boku kwadratowej komórki autoamtu w pikselach 		

int main(int argc, char* argv[] )
{

    float  t=5000; // temperatura jako parametr modelu 

    sf::RenderWindow window(sf::VideoMode(WIDTH * SIZE,WIDTH * SIZE ), "Ising model"); // tworzenie okna 
    sf::Color kolor1(90,2,255);
    sf::Color kolor2(2,255,90);
  
    // definiowanie kolorów reprezentujących stany 
    Grid m(WIDTH,WIDTH,SIZE,kolor1,kolor2); // tworzy się instancja siatki o wymiarach WIDTH komórek (gdzie  każda komórka ma SIZE pikseli), stany są symbolizowane przez kolor 1 i 2  
    

    IsingModel * Ising = new IsingModel(); // instancja modelu
    m.RandomizeGrid(); // siatka się losuje swoje stany
 

    while (window.isOpen())
    { 						// pętla główna programu 
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // sprawdzanie czy nie zamknąłem okna
                window.close();
        }

	for(std::size_t i=0; i<m.size(); ++i)
	{
		window.draw(*m[i].getCell());   // narysuj każdą komórkę w oknie
	}	

	Ising->Iteration(&m,t, 10000);	// wykonaj 10000 kroków symulacji  modelu na siatce m  w zależności od temperatury t 

	window.display(); // wyswietl stan siatki 
    }

    return 0;
}

