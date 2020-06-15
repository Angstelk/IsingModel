#ifndef MODEL_HPP
#define MODEL_HPP
#include "Grid.hpp"
#include <string>

class Model
{
	private:
	std::string name;		
	public:
	
	Model()	{  name = "unnamed"; }	
	Model(std::string n) { name = n; }
	std::string GetName(){ return name;  }
	void SetName( std::string n){ name = n; }
	virtual void Iteration(Grid * grid){ printf("Basic Model \n"); }

};

#endif
