#include "ant.h"
#include "colours.h"
#include <vector>
#include <cstdlib>
#include <stdlib.h>

class ant_Cx : public Ant
{
	private:
		int voracidad_;
		std::string forma_de_moverse_;
	public:
	ant_Cx(int pos_x, int pos_y = 0, orientacion direccion = orientacion::N, int vida = 10, std::string forma_de_moverse = "DDDD"); 
	void movimiento(int color);
	std::string get_color(){return RED;}
};