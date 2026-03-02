#include "ant_Hx.h"

ant_Hx::ant_Hx(int pos_x = 0, int pos_y = 0, orientacion direccion = orientacion::N, int vida = 10, std::string forma_de_moverse){
	forma_de_moverse_ = forma_de_moverse;
}

void ant_Hx::movimiento(int color){
	if(forma_de_moverse_[color] == 'D'){
		girar_derecha();
		move();
	}
	else{
		girar_izquierda();
		move();
	}
}