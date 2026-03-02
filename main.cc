#include <iostream>
#include "simulator.h"
int main (int argc, char** argv){
  std::string fichero = argv[1];
  Simulator simulador(fichero);
  std::cout << "El simulador termino correctamente" << std::endl;
  return 0;
}