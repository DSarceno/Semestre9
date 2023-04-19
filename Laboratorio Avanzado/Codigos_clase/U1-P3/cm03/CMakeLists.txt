cmake_minimum_required(VERSION 3.10)

project(cm03)

# Se indica donde encontrar los "headers" para 
# este proyecto
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                   )

# Se pueden definir variables que apunten a archivos o
# grupos de archivos
file(GLOB libestudiante_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# En este ejemplo se va generar una libreria dinamica
# donde este los objetos de las clases persona y estudiante
add_library (estudiante SHARED ${libestudiante_sources})


# Ahora se compila el ejecutable. Notese que ya no se
# incluye el codigo de las clases estudiante y persona
# ya que estos estaran en la libreria
add_executable(inheritance inherintance.cpp)

# Se indica que el ejecutable debe ser enlazado con la 
# libreria estudiante.
target_link_libraries (inheritance LINK_PUBLIC estudiante)
