#include "tape_periodic.h"

void TapePeriodic::check_escpecialidad(std::vector<std::unique_ptr<Ant>>& hormigas){
  for(auto& h : hormigas){
    if(h->get_pos().first == - 1){
      h->set_pos(get_dimensions().first - 1, h->get_pos().second);
    }
    if(h->get_pos().second == -1){
      h->set_pos(h->get_pos().first, get_dimensions().second - 1);
    }
    if(h->get_pos().first == get_dimensions().first){
      h->set_pos(0, h->get_pos().second);
    }
    if(h->get_pos().second == get_dimensions().second){
      h->set_pos(h->get_pos().first, 0);
    }
  }
}