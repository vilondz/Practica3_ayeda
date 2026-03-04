#include "tape_reflective.h"

void TapeReflective::check_escpecialidad(std::vector<std::unique_ptr<Ant>>& hormigas){
  for(auto& h : hormigas){
    if(h->get_pos().first == - 1){
      h->set_pos(0, h->get_pos().second);
      h->set_orientacion(orientacion::S);
    }
    if(h->get_pos().second == -1){
      h->set_pos(h->get_pos().first, 0);
      h->set_orientacion(orientacion::E);
    }
    if(h->get_pos().first == get_dimensions().first){
      h->set_pos(get_dimensions().first -1, h->get_pos().second);
      h->set_orientacion(orientacion::N);
    }
    if(h->get_pos().second == get_dimensions().second){
      h->set_pos(h->get_pos().first, get_dimensions().second - 1);
      h->set_orientacion(orientacion::O);
    }
  }
}
