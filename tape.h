#include <string>
#include <stdexcept>
#include <vector>
#include <memory>
#include "ant.h"
#include "exepcion_de_rango.h"

#pragma once 
typedef int celda;
typedef std::vector<celda> fila_de_celdas ;
typedef std::vector<fila_de_celdas> Cinta;
typedef std::pair<int, int> celda_par;
typedef std::pair<celda_par,orientacion> celda_con_orientacion;
class Tape {
  private:
    int size_x_;
    int size_y_;
    int n_colores_;
  public:
    std::pair<int, int> get_dimensions();
    void set_dimensions(int x, int y){size_x_ = x; size_y_ = y;}
    virtual int get_color(int x, int y) = 0;
    int get_n_colores(void){return n_colores_;}
    void set_n_colores(int n_colores){n_colores_ = n_colores;}
    virtual void change_color(int x, int y) = 0;
    virtual void set_color(int x, int y, int color) = 0;
    std::string get_color_draw(int color);
    std::string get_color_draw_bg(int color);
    virtual celda_con_orientacion check_escpecialidad(celda_con_orientacion celda) = 0;
    virtual std::pair<int,int> get_dimensiones_de_inicio_de_cinta() = 0;
    virtual std::ostream& draw_tape(std::ostream& out) = 0;
};