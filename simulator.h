#include <fstream>
#include "ant.h"
#include "tape.h"
#include "colours.h"
#include <thread>
#include <chrono>
#pragma once
class Simulator{
  private:
    bool paso_a_paso_ = false;
    bool cada_x_pasos_ = false;
    int x_pasos = 0;
  public:
    Simulator(std::string& fichero);
    void Simulacion_por_fichero(std::vector<std::unique_ptr<Ant>>& hormigas, std::unique_ptr<Tape>& cinta);
    void Guardar_fichero(std::unique_ptr<Tape>& cinta, const std::vector<std::unique_ptr<Ant>>& hormigas);
    void visualizar(std::unique_ptr<Tape>& cinta, const std::vector<std::unique_ptr<Ant>>& hormigas);
    bool check_out(std::unique_ptr<Tape>& cinta, const std::vector<std::unique_ptr<Ant>>& hormigas);
    void menu(std::string& fichero);
    void check_fichero(std::string fichero);
    void crear_archivo_guardado(std::string fichero_guardado, std::unique_ptr<Tape>& cinta, const std::vector<std::unique_ptr<Ant>>& hormigas);
};