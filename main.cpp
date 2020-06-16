#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Cell.hpp"
#include "Grid.hpp"
#include "Model.hpp"
#include "IsingModel.hpp"
#define WIDTH 100 
#define SIZE 5

int main()
{

    sf::RenderWindow window(sf::VideoMode(WIDTH * SIZE,WIDTH * SIZE ), "Ising model");
    sf::RectangleShape rectangle( sf::Vector2f( 1.f, 1.f ) ); 
    rectangle.setPosition(0,0);
    rectangle.setFillColor(sf::Color::White);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::White);
    sf::Color kolor1(90,2,255);
    sf::Color kolor2(20,180,2);
    
    Grid m(WIDTH,WIDTH,SIZE,kolor1,kolor2); // tworzy się instancja siarki o wymirarach WIDTH, każda komórka SIZE, stany są symbolizowane przez kolor 1 i 2  
    
    float  t=0;

    IsingModel maciek; // instancja modelu
    m.RandomizeGrid(); // siatka się losuje swoje stany

    while (window.isOpen())
    { 
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // sprawdzanie czy nie zamknąłem okna
                window.close();
        }

       // window.clear();
	
	for(std::size_t i=0; i<m.size(); ++i)
	{
		window.draw(*m[i].getCell());   // narysuj każdą komórkę w oknie
	}	

	maciek.IsingIteration(&m,t);	// wykonaj iteracje modelu na siatce m  w zależności od temperatury t 

	window.display();
    }

    return 0;
}

