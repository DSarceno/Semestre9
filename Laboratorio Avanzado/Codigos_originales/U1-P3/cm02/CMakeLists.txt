cmake_minimum_required(VERSION 3.10)

project(cm02)

# Se indica donde encontrar los "headers" para 
# este proyecto
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                   )

# Se pueden definir variables que apunten a archivos o
# grupos de archivos
file(GLOB e2_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# En este caso se agregan los archivos en la carpeta src
# a las fuentes para construir el ejecutable
add_executable(inheritance ${e2_sources} inherintance.cpp)
