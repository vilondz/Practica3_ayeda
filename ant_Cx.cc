#include "ant_Cx.h"

ant_Cx::ant_Cx(int pos_x, int pos_y , orientacion direccion, int vida, std::string forma_de_moverse)
 : Ant(pos_x, pos_y, direccion, vida){
  forma_de_moverse_ = forma_de_moverse;
}
void ant_Cx::movimiento(int color){
  if(forma_de_moverse_[color] == 'D'){
		girar_derecha();
		move();
	}
	else{
		girar_izquierda();
		move();
	}
}