#include "ant.h"
#include "colours.h"
class ant_Hx : public Ant {
	private:
		std::string forma_de_moverse_;
	public:
	ant_Hx(int pos_x = 0, int pos_y = 0, orientacion direccion = orientacion::N, int vida = 10, std::string forma_de_moverse = "DDDD");

	void movimiento(int color);
	std::string get_color(){return GREEN;}
};