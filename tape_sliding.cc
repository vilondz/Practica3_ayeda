#include "tape_sliding.h"


TapeSliding::TapeSliding(int size_x, int size_y, int n_colores){
set_dimensions(size_x, size_y);
set_n_colores(n_colores);
for(int i = 0; i < size_x; i++){

    SlidingVector<int> fila(0,size_y, 0);
    sv_t_.push_back(fila);                 // añade la fila completa
}

  std::cout << get_dimensiones_de_inicio_de_cinta().first <<  " " << get_dimensiones_de_inicio_de_cinta().second << std::endl;
  std::cout << get_dimensions().first << " " << get_dimensions().second << std::endl;
  for(int i = get_dimensiones_de_inicio_de_cinta().first; i < get_dimensions().first; i++){
    for(int j = get_dimensiones_de_inicio_de_cinta().second; j < get_dimensions().second; j++){
      std::cout << sv_t_[i][j];;
    }
    std::cout << std::endl;
  }
  //set_dimensions(size_x, size_y);
  //set_n_colores(n_colores);
//
  //// establecer rango de filas
  //sv_t_.set_indices(0, size_x - 1);
  //sv_t_.resize(size_x);
//
  //for(int i = 0; i < size_x; i++){
  //  // establecer rango de columnas
  //  sv_t_[i].resize(size_y);
//
  //  for(int j = 0; j < size_y; j++){
  //    sv_t_[i][j] = 0;
  //  }
  //}
}

celda_con_orientacion TapeSliding::check_escpecialidad(celda_con_orientacion celda){
    
    //std::cout << x << y << std::endl;
    //// revisar fila
    //bool fila_ok = false;
    //while(!fila_ok){
    //  try {
    //    sv_t_[x];
    //    fila_ok = true;
    //  } 
    //  catch(const SlidingVectorException& e) {
    //    if(e.por_delante()) {
    //        push_fila();
    //    } 
    //    else {
    //        insert_fila();
    //    }
    //  }
    //}
    //bool columna_ok = false;
    //// revisar columna
    //while(!columna_ok){
    //    try {
    //      sv_t_[x][y];
    //      columna_ok = true;
    //    } 
    //    catch(const SlidingVectorException& e) {
    //      if(e.por_delante()) {
    //        push_columna();
    //      } 
    //      else {
    //        insert_columna();
    //      }
    //    }
    //}
    int x = celda.first.first;
    int y = celda.first.second;
    // check filas
    if(get_dimensiones_de_inicio_de_cinta().first > x){
      insert_fila();
    }
    if(x > get_dimensions().first){
      push_fila();
    }
    if(y < get_dimensiones_de_inicio_de_cinta().second){
      insert_columna();
    }
    if(y > get_dimensions().second){
      push_columna();
    }
    return celda;
}


void TapeSliding::set_dimensiones_de_inicio_de_cinta(int x, int y){
  sv_t_.set_indices(x, y);
}

std::pair<int, int> TapeSliding::get_dimensiones_de_inicio_de_cinta(){
  return std::make_pair(sv_t_.get_indices().first, sv_t_[0].get_indices().first);
}

void TapeSliding::push_columna(){
  for(int i = get_dimensiones_de_inicio_de_cinta().first; i < get_dimensions().first; i++){
    sv_t_[i].push_back(0);
  }
  set_dimensions(get_dimensions().first, get_dimensions().second + 1);
}

void TapeSliding::push_fila(){
  SlidingVector<int> fila(get_dimensiones_de_inicio_de_cinta().second, get_dimensions().second, 0);
  sv_t_.push_back(fila);
  set_dimensions(get_dimensions().first + 1,get_dimensions().second);
}

void TapeSliding::insert_fila(){
  SlidingVector<int> fila(get_dimensiones_de_inicio_de_cinta().second, get_dimensions().second, 0);
  sv_t_.insert(fila);
  sv_t_[0].set_indices(sv_t_[0].get_indices().first - 1, sv_t_.get_indices().second);
}

void TapeSliding::insert_columna(){
  for(int i = get_dimensiones_de_inicio_de_cinta().first;i < get_dimensions().first; i++){
    sv_t_[i].insert(0);
  }
  set_dimensions(get_dimensions().first, get_dimensions().second - 1);
}

int TapeSliding::get_color(int x, int y){
  return sv_t_[x][y];
}
  
void TapeSliding::change_color(int x, int y){
  sv_t_[x][y] = (sv_t_[x][y] + 1) % get_n_colores();
}
void TapeSliding::set_color(int x, int y, int color){
  sv_t_[x][y] = color;
}

std::ostream& TapeSliding::draw_tape(std::ostream& out){
  for(int i = get_dimensiones_de_inicio_de_cinta().first; i < ; i++){
    for(int j = get_dimensiones_de_inicio_de_cinta().second; j < get_dimensions().second; j++){
      std::cout << i << j << std::endl;
      out << sv_t_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}