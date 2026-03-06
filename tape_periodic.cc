#include "tape_periodic.h"

TapePeriodic::TapePeriodic(int size_x, int size_y, int n_colores){
  set_dimensions(size_x, size_y);
  cinta_.resize(size_x);
  set_n_colores(n_colores);
  for(int i = 0; i < size_x; i++){
    cinta_[i].resize(size_y);
  }
  for(int i = 0; i < size_x; i++){
    for(int j = 0; j < size_y; j++){
     // std::cout << "el bucle funciona" << std::endl;
     // std::cout << i  << " " << j << std::endl;
      cinta_[i][j] = 0;
    } 
  }
}

int TapePeriodic::get_color(int x, int y){
  return cinta_[x][y];
}
  
void TapePeriodic::change_color(int x, int y){
  cinta_[x][y] = (cinta_[x][y] + 1) % get_n_colores();
}
void TapePeriodic::set_color(int x, int y, int color){
  cinta_[x][y] = color;
}
celda_con_orientacion TapePeriodic::check_escpecialidad(celda_con_orientacion celda){
  celda_con_orientacion aux(std::make_pair(celda.first.first, celda.first.second), celda.second);
  if(celda.first.first == - 1){
    aux.first.first = get_dimensions().first - 1;
  }
  if(celda.first.second == -1){
    aux.first.second = get_dimensions().second - 1;
  }
  if(celda.first.first == get_dimensions().first){
    aux.first.first = 0;
  }
  if(celda.first.second == get_dimensions().second){
    aux.first.second = 0;
  }
  return aux;
}