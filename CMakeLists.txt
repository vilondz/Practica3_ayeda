cmake_minimum_required()

project(Practica3)

add_executable(Practica3 main.cc simulator.h tape.h ant.h ant.cc tape.cc simulator.cc colours.h 
ant_Hx.h ant_Hx.cc ant_Cx.h ant_Cx.cc tape_periodic.h tape_periodic.cc tape_reflective.h tape_reflective.cc)
