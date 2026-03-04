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
};