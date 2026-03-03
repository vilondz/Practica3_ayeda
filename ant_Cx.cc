#include "ant_Cx.h"

ant_Cx::ant_Cx(int pos_x, int pos_y , orientacion direccion, int vida, std::string forma_de_moverse)
 : Ant(pos_x, pos_y, direccion, vida, forma_de_moverse){}
void ant_Cx::movimiento(int color){
  if(get_forma_de_moverse()[color] == 'D'){
		move();
		girar_derecha();
		move();
	}
	else{
		move();
		girar_izquierda();
		move();
	}
}

void ant_Cx::comer(int comida){
	set_vida(get_vida() + (comida * voracidad_));
}