#include <iostream>
#pragma once
//fichero         0 ,1, 2, 3
enum orientacion {N, S, E, O};

class Ant{
  private:
    int pos_x_;
    int pos_y_;
    orientacion orientacion_;
    int vida_;
  public:
    //Ant();
    Ant(int pos_x = 0, int pos_y = 0, orientacion direccion = orientacion::N, int vida = 10);
    virtual ~Ant() = default;
    std::pair<int, int> get_pos() const;
    void sobre_blanco(); 
    void sobre_negro();
    virtual void movimiento(int color) = 0;
    void move();
    void girar_derecha();
    void girar_izquierda();
    orientacion get_orientacion(void);
    char get_orientacion_char(void);
    void set_orientacion(orientacion);
    friend std::ostream& operator<<(std::ostream& out, const Ant& hormiga);
};