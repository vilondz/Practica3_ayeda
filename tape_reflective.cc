#include "tape_reflective.h"
int TapeReflective::get_color(int x, int y){
  return cinta_[x][y];
}
  
void TapeReflective::change_color(int x, int y){
  cinta_[x][y] = (cinta_[x][y] + 1) % get_n_colores();
}
void TapeReflective::set_color(int x, int y, int color){
  cinta_[x][y] = color;
}
celda_con_orientacion TapeReflective::check_escpecialidad(celda_con_orientacion celda){
//  for(auto& h : hormigas){
//    if(h->get_pos().first == - 1){
//      h->set_pos(0, h->get_pos().second);
//      h->set_orientacion(orientacion::S);
//    }
//    if(h->get_pos().second == -1){
//      h->set_pos(h->get_pos().first, 0);
//      h->set_orientacion(orientacion::E);
//    }
//    if(h->get_pos().first == get_dimensions().first){
//      h->set_pos(get_dimensions().first -1, h->get_pos().second);
//      h->set_orientacion(orientacion::N);
//    }
//    if(h->get_pos().second == get_dimensions().second){
//      h->set_pos(h->get_pos().first, get_dimensions().second - 1);
//      h->set_orientacion(orientacion::O);
//    }
//  }
}
