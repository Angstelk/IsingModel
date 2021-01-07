#ifndef RANDOMWALKMODEL_HPP
#define RANDOMWALKMODEL_HPP
#include "Model.hpp"
#include "Grid.hpp"
#include <random>
#include <vector>
#include <math.h>


/*
 * Klasa dziedzicząca po Modelu, 
 * tutaj odbywa się symulacja na zewnętrznym obiekcie - Grid 
 *
 *
 */
class Particle
{
	private:
	int	position_r;
	int	position_c;
	sf::Color ColorParticle;

	public:
	Particle();
	Particle(int posR, int posC, sf::Color CP)
	{        
		position_r = posR;
		position_c = posC;
		ColorParticle = CP; 


      	}
	int GetPosR(){return position_r ;}
	int GetPosC(){return position_c ;}
	sf::Color GetColor(){return ColorParticle;}
	void SetPosR(int R){position_r = R;}
	void SetPosC(int C){position_c = C;}



};

class RandomWalkModel: public Model
{
	private:
	
	std::vector<Particle> Particles;	
	
	public:
	

	RandomWalkModel()
	{
	
	this->SetName("Random walk 2d n particles"); /* konstruktor*/	
   	sf::Color ParC(205,33,66);
	Particles.push_back(Particle(100,100,ParC));
	Particles.push_back(Particle(20,20,ParC));
	Particles.push_back(Particle(0,120,ParC));
	

	}

    	unsigned modulo( int value, unsigned m)
       	{
    		int mod = value % (int)m;
    
		if (value < 0){ mod += m; }
    		return mod;
	}

	void	RandomStep(Particle * part)
	{
		int rand_step = rand() % 8;
	//	printf("%d \n" , rand_step);
		switch(rand_step)
		{
			case 0 :
			part->SetPosR(part->GetPosR()-1 );
			part->SetPosC(part->GetPosC()-1 );
				break;
			case 1 :
			part->SetPosR(part->GetPosR()-1);
			//part->SetPosC(part->GetPosC() );
				break;
			case 2 :
			part->SetPosR(part->GetPosR() -1 );
			part->SetPosC(part->GetPosC() +1 );
				break;
			case 3 :
			//part->SetPosR(part->GetPosR() );
			part->SetPosC(part->GetPosC()-1 );
				break;
			case 4 :
			//part->SetPosR(part->GetPosR() );
			part->SetPosC(part->GetPosC() +1 );
				break;
			case 5 :
			part->SetPosR(part->GetPosR()+1 );
			part->SetPosC(part->GetPosC()-1 );
				break;
			case 6 :
			part->SetPosR(part->GetPosR()+1 );
			//part->SetPosC(part->GetPosC() );
				break;
			case 7 :
			part->SetPosR(part->GetPosR()+1 );
			part->SetPosC(part->GetPosC()+1 );
				break;
		}		
	}
	

	void Iteration(Grid * grid)
	{
		int R = 0;
		int C = 0;
		

		for(int i = 0; i <(int) Particles.size(); i++)
		{
			RandomStep(&Particles[i]);
	
			R = modulo(Particles[i].GetPosR(),grid->GetRows());
			C =  modulo(Particles[i].GetPosC(),grid->GetColumns());

			grid->CellUp(R,C);
		}
		
		

	}
};
#endif 
