#include "tape.h"
#include "ant.h"
#include <vector>
#include <memory>
#pragma once

class TapeReflective : public Tape {
  private:

  public:
    TapeReflective(int x, int y, int n_colores) : Tape(x, y, n_colores){}
    ~TapeReflective(){}
    void check_escpecialidad(std::vector<std::unique_ptr<Ant>>& hormigas);
};