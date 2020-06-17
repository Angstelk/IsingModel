#ifndef STATE_HPP
#include <SFML/Graphics.hpp>
#include <stdlib.h>

/*Klasa implementująca  stan komórki, związnany z obliczeniami w symulacji 
 * i reprezentacjie kalsy przez kolor 
 *
 */

class State
{
	private:
		sf::Color StateUp;     // obiekt z biblioreki sfml reprezentujący kolor stanu 
		sf::Color StateDown;
		sf::Color CurrentState; 
		int value;		// pole przechowujące wartość liczbąwą stanu

	public: 
		State()
		{
			StateUp = sf::Color::White;  // domyślnymi kolorami są biały 
			StateDown = sf::Color::Black; // i czarny
			CurrentState = StateDown;    // domyślny stan to 0
			value = 0;
		};

		/*konstruktor parametryczny  */
		State(sf::Color SUp,sf::Color SDown, int val)
		{			
			StateUp=SUp;
			StateDown=SDown;
			value=val;
			if(value == -1)
			{
				CurrentState = StateDown;

			}
			else 
			{
				CurrentState = StateUp;
			}

			
		}
		// moetody get i set stanu reprezentowanego prez liczbę komórki 
		int GetState()
		{
			return value;
		}
		
		sf::Color GetColour()
		{
			return CurrentState;
		}

		void SetState(int val)
		{
			value=val;
			
			if(value == -1)
			{
				CurrentState = StateDown;
			}
			else
			{
				CurrentState = StateUp;
			}

		}
		// zmień stany na UP
		void SetStateUp()
		{
			value=1;
			CurrentState = StateUp;
		}
		// i Down
		void SetStateDown()
		{
			value=-1;
			CurrentState = StateDown;
		}
		// ustaw stan losowy 
		int GenerateRandomState()
		{

			if(rand()%2 == 1) return 1;
			else return -1;
		}

};

#endif

