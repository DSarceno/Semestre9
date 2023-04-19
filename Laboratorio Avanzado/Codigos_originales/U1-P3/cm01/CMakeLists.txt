# Se indica la version de cmake minima que se
# debe utilizar para correr este script
cmake_minimum_required(VERSION 3.10)

# Se indica en nombre del proyecto
project(esimple)

# Se aniade un ejecutable al proyecto. Se
# deben indicar los archivos del codigo fuente
# del ejecutable.
add_executable( esimple simple.cpp class01.cpp )
