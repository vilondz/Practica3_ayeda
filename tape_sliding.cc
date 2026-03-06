#include "tape_sliding.h"


TapeSliding::TapeSliding(int size_x, int size_y, int n_colores){
  set_dimensions(size_x, size_y);
  set_n_colores(n_colores);
  sv_t_.resize(size_x);
  for(int i = 0; i < size_x; i++){
    sv_t_[i].resize(size_y);
  }
  for(int i = 0; i < size_x; i++){
    for(int j = 0; j < size_y; j++){
     // std::cout << "el bucle funciona" << std::endl;
     // std::cout << i  << " " << j << std::endl;
      sv_t_[i][j] = 0;
    } 
  }
}

//void TapeSliding::check_escpecialidad(std::vector<std::unique_ptr<Ant>>& hormigas){
//  for(auto& h : hormigas){
//    if()
//  }
//}

std::pair<int, int> TapeSliding::get_dimensiones_de_inicio_de_cinta(){
  return sv_t_.get_indices();
}

void TapeSliding::push_columna(){
  for(int i = get_dimensiones_de_inicio_de_cinta().first; i < get_dimensions().first; i++){
    sv_t_[i].push_back(0);
    set_dimensions(get_dimensions().first, get_dimensions().second + 1);
  }
}

void TapeSliding::push_fila(){
  sv_t_.push_back(sv(get_dimensiones_de_inicio_de_cinta().second, get_dimensions().second, 0));
  set_dimensions(get_dimensions().first + 1, get_dimensions().second);
}

void TapeSliding::insert_fila(){
  sv_t_.insert(sv(get_dimensiones_de_inicio_de_cinta().second, get_dimensions().second, 0));
  
}

void TapeSliding::insert_columna(){
  for(int i = get_dimensiones_de_inicio_de_cinta().first; i < get_dimensions().first; i++){
    sv_t_[i].insert(0);
  }
}