#include "ant.h"
#include "colours.h"
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#pragma once 
class ant_Cx : public Ant
{
	private:
		float voracidad_ = 0.30;
		std::string tipo_ = "C";
	public:
	ant_Cx(int pos_x = 0, int pos_y = 0, orientacion direccion = orientacion::N, int vida = 10, std::string forma_de_moverse = "DDDD"); 
	std::string get_color(){return RED;}
	std::string get_tipo(void){return tipo_;}
	void comer(int comida);
	void movimiento(int color);
};