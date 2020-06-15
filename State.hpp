#ifndef STATE_HPP
#include <SFML/Graphics.hpp>
#include <stdlib.h>
class State
{
	private:
		sf::Color StateUp;
		sf::Color StateDown;
		sf::Color CurrentState;
		int value;

	public: 
		State()
		{
			StateUp = sf::Color::White;
			StateDown = sf::Color::Black;
			CurrentState = StateDown;
			value = 0;
		};

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
		
		void SetStateUp()
		{
			value=1;
			CurrentState = StateUp;
		}

		void SetStateDown()
		{
			value=-1;
			CurrentState = StateDown;
		}
		int GenerateRandomState()
		{

			if(rand()%2 == 1) return 1;
			else return -1;
		}

};

#endif

