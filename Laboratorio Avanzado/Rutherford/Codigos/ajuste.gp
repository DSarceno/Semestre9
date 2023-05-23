# lun 22 may 2023 13:10:27 CST 
# ajuste.gp 
# Diego Sarceno (dsarceno68@gmail.com) 

# Resumen 

# Codificado del texto: UTF8 
# Compiladores probados: GNUPLOT (Ubuntu 20.04 Linux) 5.2 
# Instruciones de Ejecución: no requiere nada mas 
# gnuplot ajuste.gp 


# PROGRAM 
# Idioma 
set encoding utf8 

# Terminal 
unset label 
clear 
set terminal pdf 

set output "Ajuste.pdf"


set yrange [-5E6:3E7]
set xrange [-20:145]

set xlabel "Ángulo de los Detectores"
set ylabel "Mediciones"
set key right top box
set title "Promedio de los Datos Obtenidos"
set grid

plot "data.dat" u 1:2 w lp pointtype 3 t "Mean Detections"








