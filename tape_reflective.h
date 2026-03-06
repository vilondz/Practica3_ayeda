#include "tape.h"
#include "ant.h"
#include <vector>
#include <memory>
#pragma once
typedef std::vector<celda> fila_de_celdas ;
typedef std::vector<fila_de_celdas> Cinta;
class TapeReflective : public Tape {
  private:
    Cinta cinta_;
  public:
    TapeReflective(int x, int y, int n_colores);
    ~TapeReflective(){}
    int get_color(int x, int y);
    void change_color(int x, int y);
    void set_color(int x, int y, int color);
    celda_con_orientacion check_escpecialidad(celda_con_orientacion celda);
    std::pair<int, int> get_dimensiones_de_inicio_de_cinta(void){return std::make_pair(0,0);}
};