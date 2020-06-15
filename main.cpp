#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Cell.hpp"
#include "Grid.hpp"
#include "Model.hpp"
#include "IsingModel.hpp"
#define WIDTH 400 
#define SIZE 1

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
    
    Grid m(WIDTH,WIDTH,SIZE,kolor1,kolor2);
    
    int x=0;
    int y=0;
    float  t =0;
    
    IsingModel maciek;
    m.RandomizeGrid();
    while (window.isOpen())
    { 
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
	
	
	for(std::size_t i=0; i<m.size(); ++i)
	{
		window.draw(*m[i].getCell());
	}	
	t +=0.1;
	maciek.Iteration1(&m,t);	
	if(t > 300) t=0;	
	window.display();
	x++;
	y++;
    }

    return 0;
}

