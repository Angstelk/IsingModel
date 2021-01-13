#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Cell.hpp"
#include "Grid.hpp"
#include "Model.hpp"
#include "RandomWalkModel.hpp"
#include "IsingModel.hpp"
#include "GameOfLife.hpp"
#define WIDTH 80 // makro definiujące ilosć kolumn i wierszy siatki  
#define SIZE 10 	     //  makro definiujące długosć boku kwadratowej komórki autoamtu w pikselach 			
int main(int argc, char* argv[] )
{
       // parametr jako 1/(k * T) k - stała stefana boltzmana T temperatura 
     
     float t=atof(argv[1]);
     int L = atoi(argv[2]);
     
     float inter_1 = 0.1;
     float inter_2 = 0.03;
     float T_tab[100];  
   sf::Color kolor1(255,8,0);
   sf::Color kolor2(0,10,255);
   // definiowanie kolorów reprezentujących stany 
    Grid * grid_ptr = new Grid(L,L,SIZE,kolor1,kolor2); // tworzy się instancja siatki o wymiarach WIDTH komórek (gdzie  każda komórka ma SIZE pikseli), stany są symbolizowane przez kolor 1 i 2   
     IsingModel * IM_ptr = new IsingModel(1, 1, t); // instancja modelu
     //grid_ptr->RandomizeGrid();
     
     
     grid_ptr->StateDownGrid();
     
     if(atoi(argv[3]) == 3)
     { 
	     T_tab[0]=0;

	for(int i =1 ;5.5>T_tab[i-1]; i++)
	{  
     		IM_ptr->Iteration(grid_ptr,atoi(argv[3]),T_tab[i-1]);

		if(( T_tab[i-1] > 0.5)  && ( T_tab[i-1] <2.6) )
		{
			T_tab[i]= T_tab[i-1]+inter_2;
		}
		else { T_tab[i]= T_tab[i-1]+inter_1;}
		
	
	}

     } 
     
     IM_ptr->Iteration(grid_ptr,atoi(argv[3]),atoi(argv[1]));

     sf::RenderWindow window1(sf::VideoMode(L* SIZE,L * SIZE ), "" ) ; // tworzenie okna 
			for(std::size_t i=0; i<grid_ptr->size(); ++i)
			{
				window1.draw(* grid_ptr->operator[](i).getCell());   // narysuj każdą komórkę w oknie
			}	

			window1.display(); // wyswietl stan siatki 
	while (window1.isOpen()) 
	{
        	sf::Event event;

        	while (window1.pollEvent(event))
       		{
           		 if (event.type == sf::Event::Closed) // sprawdzanie czy nie zamknąłem okna
            		    window1.close();
		}
	
 	



    }
     return 0;
}




     /* 	
    //sf::RenderWindow window1(sf::VideoMode(WIDTH * SIZE,WIDTH * SIZE ), "" ) ; // tworzenie okna 
   //sf::Color kolor111(255,33,66);
   //sf::Color kolor222(0,0,0);
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
			Rand->Iteration( grid_ptr2 );
		//	gol->Iteration( grid_ptr );
			//  IM_ptr->Iteration( grid_ptr , 100000 );	// wykonaj 10000 kroków symulacji  modelu na siatce m  w zależności od temperatury t 


    }

    */
