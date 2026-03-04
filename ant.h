#include <iostream>
#include <memory>
#pragma once
//fichero         0 ,1, 2, 3
enum orientacion {N, S, E, O};

class Ant{
  private:
    int pos_x_;
    int pos_y_;
    orientacion orientacion_;
    int vida_;
    std::string forma_de_moverse_;
  public:
    //Ant();
    Ant(int pos_x = 0, int pos_y = 0, orientacion direccion = orientacion::N, int vida = 10 , std::string forma_de_moverse = "DIDI");
    virtual ~Ant() = default;
    std::pair<int, int> get_pos() const;
    void set_pos(int x, int y){pos_x_ = x; pos_y_ = y;}
    void sobre_blanco(); 
    void sobre_negro();
    virtual void movimiento(int color) = 0;
    void move();
    void girar_derecha();
    void girar_izquierda();
    virtual void comer(int comida) = 0;
    virtual std::string get_color() = 0;
    std::string get_forma_de_moverse(){return forma_de_moverse_;}
    orientacion get_orientacion(void);
    char get_orientacion_char(void);
    void set_orientacion(orientacion);
    void set_vida(int vida){vida_ = vida;}
    virtual std::string get_tipo() = 0;
    int get_vida(void){return vida_;}
    friend std::ostream& operator<<(std::ostream& out, const Ant& hormiga);
};