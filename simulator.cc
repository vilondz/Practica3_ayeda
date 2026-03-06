#include "simulator.h"
#include <assert.h>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include "ant_Cx.h"
#include "ant_Hx.h"
#include "tape_reflective.h"
#include "tape_periodic.h"
Simulator::Simulator(std::string& fichero){
 menu(fichero);
}

void Simulator::Simulacion_por_fichero(std::vector<std::unique_ptr<Ant>>& hormigas, std::unique_ptr<Tape>& cinta){
  //std::cout << "dimensiones de la cinta" << std::endl;
  //std::cout << cinta_x << " " << cinta_y << std::endl;
  //std::cout << "posicion de la hormiga" << std::endl;
  //std::cout << hormiga_x << " " << hormiga_y << " " << orientacion_num << std::endl;
  //std::cout << "casillas negras " << std::endl;
  //for(auto aux : casillas_negras){
  //  std::cout << aux.first << " " << aux.second << std::endl;
  //}
  for(auto &h : hormigas){
    std::cout << *h << std::endl;
  }
  std::cout << "Indique el número de pasos: ";
    int pasos_a_dar, pasos_dados = 0;
    std::cin >> pasos_a_dar;

    while (pasos_a_dar > 0) {
        // Chequeamos si alguna hormiga salió de la cinta
        //if (check_out(cinta, hormigas)) {
        //    std::cout << "Al menos una hormiga salió de la cinta. Terminando simulación." << std::endl;
        //    break;
        //}

        // Visualización
        if (cada_x_pasos_) {
            if (pasos_dados % x_pasos == 0) {
                std::cout << "\033[3J\033[2J\033[H" << std::flush;
                visualizar(cinta, hormigas);
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
            }
        } else {
            std::cout << "\033[3J\033[2J\033[H" << std::flush;
            visualizar(cinta, hormigas);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        // Cada hormiga se mueve según la celda donde está
        for (auto& h : hormigas) {
            auto [x, y] = h->get_pos();
            int color_actual = cinta->get_color(x, y);

            // Cambiamos el color de la celda de manera cíclica
            cinta->change_color(x, y);

            // Llamamos al método virtual que aplica el movimiento de la hormiga
            h->movimiento(color_actual);
            if(h->get_tipo() == "C"){
                for(auto& hormiga : hormigas){
		            if (h.get() == hormiga.get()){
			          continue;
		            }
		            else{
			            if(h->get_pos() == hormiga->get_pos()){
				            h->comer(hormiga->get_vida());
			            }
		            }
        	    }
            }
            else{
                h->comer(cinta->get_color(x, y));
            }
            //std::cout << h->get_pos().first << " " << h->get_pos().second << std::endl;
            //std::cout << h->get_pos().first << " " << h->get_pos().second << std::endl;
        }
        //cinta.draw_tape(std::cout);
        cinta->check_escpecialidad(hormigas);
        // Chequeamos que no haya hormigas en la misma celda
        //check_hormigas_no_superpuestas(hormigas);

        pasos_a_dar--;
        pasos_dados++;

        // Modo paso a paso
        if (paso_a_paso_ && pasos_dados % x_pasos == 0) {
            std::string seguir;
            std::cout << "Presiona 'a' para continuar, cualquier otra tecla para salir: ";
            std::cin >> seguir;
            if (seguir != "a") break;
        }
    }

    // Visualización final
    visualizar(cinta, hormigas);
    std::cout << "Pasos dados: " << pasos_dados << std::endl;

    // Guardado de todas las hormigas
    Guardar_fichero(cinta, hormigas);
}

    
void Simulator::Guardar_fichero(std::unique_ptr<Tape>& cinta, const std::vector<std::unique_ptr<Ant>>& hormigas){
  char opcion;
  std::string fichero_guardado = "guardado.langdon";
  do
  {
    std::cout << "Desea guardar el estado final (y/n)" << std::endl;
    std::cin >> opcion;
  } while (opcion != 'y' && opcion != 'n');
  switch(opcion){
    case 'y':
      std::cout << "Elija un nombre para el fichero de guardado" << std::endl;
      std::cin >> fichero_guardado;
      fichero_guardado += ".langdon";
      crear_archivo_guardado(fichero_guardado, cinta, hormigas);
      break;
    case 'n':
      std::cout << "no se ha guardado el estado final cerrando programa ..." << std::endl;
      std::exit(0);
      break;
    default:
    break;
  }

}

void Simulator::menu(std::string& fichero){
  std::cout << "Configuracion del simulador " << std::endl;
    int opcion = 0;
    do {
        opcion = 0;
        std::cout << "Como quiere imprimir la hormiga de langdon\n"
                  << " 1. Cada x pasos\n"
                  << " 2. Paso a Paso\n"
                  << " 3. Ambas\n";
        std::cin >> opcion;
    } while (opcion != 1 && opcion != 2 && opcion != 3);

    switch (opcion) {
        case 1:
            cada_x_pasos_ = true;
            std::cout << "Cada cuantos pasos quiere imprimir la hormiga" << std::endl;
            std::cin >> x_pasos;
            assert(x_pasos != 0);
            check_fichero(fichero);
            break;

        case 2:
            paso_a_paso_ = true;
            x_pasos = 1;
            check_fichero(fichero);
            break;

        case 3:
            cada_x_pasos_ = true;
            paso_a_paso_ = true;
            std::cout << "Cada cuantos pasos quiere imprimir la hormiga" << std::endl;
            std::cin >> x_pasos;
            assert(x_pasos != 0);
            check_fichero(fichero);
            break;

        default:
            std::cout << "opcion invalida cerrando programa..." << std::endl;
            std::exit(1);
    }
}

//void Simulator::visualizar(Tape& cinta, const std::vector<std::unique_ptr<Ant>>& hormigas){
//  for(int i = 0; i < cinta.get_dimensions().first; i++){
//    for(int j = 0; j < cinta.get_dimensions().second; j++){
//      if(hormiga.get_pos().first == i && hormiga.get_pos().second == j){
//        if(cinta.get_color(hormiga.get_pos().first, hormiga.get_pos().second)){
//          std::cout << RED << BG_BLACK << hormiga << RESET;
//        }
//        else{
//          std::cout << RED << BG_WHITE << hormiga << RESET;
//        }
//          
//
//      }
//      else{
//        if(cinta.get_color(i, j)){
//          std::cout <<BLACK << BG_BLACK << "X" << RESET;
//        }
//        else{
//          std::cout <<WHITE << BG_WHITE << "x" << RESET;
//        }
//      }
//    }
//    std::cout << std::endl;
//  }
//  std::cout << std::endl;
//}

void Simulator::visualizar(std::unique_ptr<Tape>& cinta, const std::vector<std::unique_ptr<Ant>>& hormigas)
{
   
    auto dims = cinta->get_dimensions();
    const int filas = dims.first;
    const int columnas = dims.second;

    for (int i = cinta->get_dimensiones_de_inicio_de_cinta().first; i < filas; ++i) {
        for (int j = cinta->get_dimensiones_de_inicio_de_cinta().second; j < columnas; ++j) {

            bool dibujado = false;

            for (const auto& h : hormigas) {

                if (!h) continue;  

                auto pos = h->get_pos();
                int hx = pos.first;
                int hy = pos.second;

                if (hx == i && hy == j) {
                    std::cout 
                        << h->get_color()
                        << cinta->get_color_draw_bg(cinta->get_color(i, j))
                        << *h
                        << RESET;
                    dibujado = true;
                    break;
                }
            }

            if (!dibujado) {
                std::cout 
                    << cinta->get_color_draw_bg(cinta->get_color(i, j))
                    << cinta->get_color_draw(cinta->get_color(i,j))
                    << "X"
                    << RESET;
            }
        }
        std::cout << '\n';
    }
    for(auto& h : hormigas){
        std::cout << h->get_tipo() << "-" << h->get_forma_de_moverse() << " :"
        << " (" << h->get_pos().first << ", " << h->get_pos().second << ") " <<  h->get_vida() << std::endl;
    }
}


bool Simulator::check_out(std::unique_ptr<Tape>& cinta, const std::vector<std::unique_ptr<Ant>>& hormigas) {
    for (const auto& hormiga : hormigas) {
        auto [x, y] = hormiga->get_pos();
        if (x < 0 || x >= cinta->get_dimensions().first ||
            y < 0 || y >= cinta->get_dimensions().second) {
            return true;  // Al menos una hormiga salió de la cinta
        }
    }
    return false;  // Todas dentro de la cinta
}

void Simulator::crear_archivo_guardado(std::string fichero_guardado, std::unique_ptr<Tape>& cinta, const std::vector<std::unique_ptr<Ant>>& hormigas){
  std::ofstream output_file(fichero_guardado);
    if (!output_file.is_open()) {
        std::cerr << "Error al abrir el archivo de guardado cerrando programa ..." << std::endl;
        std::exit(1);
    }
    // Guardamos las dimensiones de la cinta
    output_file << cinta->get_dimensions().first << " " << cinta->get_dimensions().second << std::endl;

    // Guardamos cada hormiga: posición y orientación
    for (const auto& hormiga : hormigas) {
        output_file << hormiga->get_pos().first << " "
                    << hormiga->get_pos().second << " "
                    << hormiga->get_orientacion_char() << std::endl;
    }
    // Guardamos todas las celdas con color distinto de 0
    for (int i = 0; i < cinta->get_dimensions().first; i++) {
        for (int j = 0; j < cinta->get_dimensions().second; j++) {
            if (cinta->get_color(i, j) != 0) { // cualquier color distinto de 0
                output_file << i << " " << j << " " << cinta->get_color(i, j) << std::endl;
            }
        }
    }
}

void Simulator::check_fichero(std::string fichero){
  std::vector<std::unique_ptr<Ant>> hormigas;
  std::cout << "Estoy leyendo el fichero" << std::endl;
    //std::ifstream input_file(fichero);
    //if (!input_file.is_open()) {
    //    std::cerr << "Error al abrir el fichero terminando programa ..." << std::endl;
    //    std::exit(1);
    //}
//
    //// --- Leemos dimensiones de la cinta y número de colores ---
    //int cinta_x, cinta_y, n_colores;
    //input_file >> cinta_x >> cinta_y >> n_colores;

    // Inicializamos la cinta vacía
    
    //std::unique_ptr<Tape> cinta = std::make_unique<TapePeriodic>(10, 10, 4);
    std::unique_ptr<Tape> cinta = std::make_unique<TapeReflective>(10, 10, 4);

    /**/
    /**--- Leemos las hormigas ---
    /**input_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    /**std::string linea_hormigas;
    /**std::getline(input_file, linea_hormigas);
    /**std::stringstream ss(linea_hormigas);
   /**
    /**std::string bloque;
    /**hormigas.clear();
    /**while (std::getline(ss, bloque, ';')) {
    /**    std::string tipo_hormiga;
    /**    int hormiga_x, hormiga_y;
    /**    char orient_char;
    /**    std::stringstream datos(bloque);
    /**    datos >> tipo_hormiga >> hormiga_x >> hormiga_y >> orient_char;
    /**    orientacion dir;
    /**    switch (orient_char) {
    /**        case '^': dir = orientacion::N; break;
    /**        case 'v': dir = orientacion::S; break;
    /**        case '>': dir = orientacion::E; break;
    /**        case '<': dir = orientacion::O; break;
    /**        default:
    /**            std::cerr << "No mas hormigas" << orient_char << std::endl;
    /**            continue;
    /**    }
/**
    /**    // Creamos la hormiga según el tipo
    /**    if (tipo_hormiga == "DDII") {
    /**        hormigas.push_back(std::make_unique<ant_DDII>(hormiga_x, hormiga_y, dir));
    /**    } else if (tipo_hormiga == "DIDI") {
    /**        hormigas.push_back(std::make_unique<ant_DIDI>(hormiga_x, hormiga_y, dir));
    /**    } else if (tipo_hormiga == "IDDI") {
    /**        hormigas.push_back(std::make_unique<ant_IDDI>(hormiga_x, hormiga_y, dir));
    /**    } else if (tipo_hormiga == "IDID") {
    /**        hormigas.push_back(std::make_unique<ant_IDID>(hormiga_x, hormiga_y, dir));
    /**    } else {
    /**        std::cerr << "Tipo de hormiga desconocido: " << tipo_hormiga << std::endl;
    /**    }
    /**
     *}
    **/
    hormigas.push_back(std::make_unique<ant_Cx>(0, 0, orientacion::N, 10, "IDID"));
    hormigas.push_back(std::make_unique<ant_Hx>(0, 2, orientacion::E, 20, "DIDI"));
    // --- Leemos las celdas con color inicial distinto de 0 ---
    //int celda_x, celda_y, color;
    //while (input_file >> celda_x >> celda_y >> color) {
    //    cinta.set_color(celda_x, celda_y, color);
    //}
//
    //input_file.close();

    Simulacion_por_fichero(hormigas,cinta);
}