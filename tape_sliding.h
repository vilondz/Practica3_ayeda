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
    //por delante
    void push_fila();
    void push_columna();
    //por detras
    void insert_fila();
    void insert_columna();
    void check_escpecialidad(std::vector<std::unique_ptr<Ant>>& hormigas);
    std::pair<int, int> get_dimensiones_de_inicio_de_cinta();
};