#include "tape.h"
#include "ant.h"
#include <vector>
#include <memory>
#pragma once

class TapePeriodic : public Tape {
  private:

  public:
  TapePeriodic(int x, int y, int n_colores) : Tape(x, y, n_colores){}
  ~TapePeriodic(){}
  void check_escpecialidad(std::vector<std::unique_ptr<Ant>>& hormigas);
  std::pair<int, int> get_dimensiones_de_inicio_de_cinta(void){return std::make_pair(0,0);}
};