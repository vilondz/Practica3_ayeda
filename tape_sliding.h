#include "tape.h"
#include "sliding_vector.h"

typedef SlidingVector<int> sv; 

class TapeSliding : public Tape{
  private:
  SlidingVector<sv> sv_t_;
  public:
    TapeSliding(){}
    TapeSliding(int x, int y, int n_colores);
    ~TapeSliding(){}
    int get_color(int x, int y);
    void change_color(int x, int y);
    void set_color(int x, int y, int color);
    //por delante
    void push_fila();
    void push_columna();
    //por detras
    void insert_fila();
    void insert_columna();
    celda_con_orientacion check_escpecialidad(celda_con_orientacion celda);
    std::pair<int, int> get_dimensiones_de_inicio_de_cinta();
    void set_dimensiones_de_inicio_de_cinta(int, int);
    std::ostream& draw_tape(std::ostream& out);
};