#include "ant.h"
#include "colours.h"
#pragma once
class ant_Hx : public Ant {
	private:
		std::string tipo_ = "H";
	public:
	ant_Hx(int pos_x = 0, int pos_y = 0, orientacion direccion = orientacion::N, int vida = 10, std::string forma_de_moverse = "DDDD");
	std::string get_color(){return GREEN;}
	std::string get_tipo(void){return tipo_;}
	void comer(int comida);
	void movimiento(int color);
};