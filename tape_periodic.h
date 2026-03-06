#include "tape.h"
#include "ant.h"
#include <vector>
#include <memory>
#pragma once

class TapePeriodic : public Tape {
  private:
    Cinta cinta_;
  public:
  TapePeriodic(int x, int y, int n_colores);
  ~TapePeriodic(){}
  int get_color(int, int);
  void change_color(int, int);
  void set_color(int, int, int);
  celda_con_orientacion check_escpecialidad(celda_con_orientacion celda);
  std::pair<int, int> get_dimensiones_de_inicio_de_cinta(void){return std::make_pair(0,0);}
};