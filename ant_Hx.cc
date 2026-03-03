#include "ant_Hx.h"

ant_Hx::ant_Hx(int pos_x, int pos_y, orientacion direccion, int vida, std::string forma_de_moverse)
: Ant(pos_x, pos_y, direccion, vida, forma_de_moverse){}

void ant_Hx::movimiento(int color){
	if(get_forma_de_moverse()[color] == 'D'){
		girar_derecha();
		move();
	}
	else{
		girar_izquierda();
		move();
	}
}

void ant_Hx::comer(int comida){
	set_vida(get_vida() + (comida + 1));
}