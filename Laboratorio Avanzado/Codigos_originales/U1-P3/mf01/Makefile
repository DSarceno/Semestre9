# Se puede declarar como una variable el comando de compilacion
C++ = g++

# esimple al ser el primer target que aparece en el archivo
# es el que se construira por defecto.
esimple: simple.o class01.cpp
	$(C++)  simple.o class01.cpp -o esimple

# simple.o se construira ya que es prerrequisito de esimple
simple.o: simple.hpp simple.cpp
	$(C++) -c simple.cpp -o simple.o

# clean es un target que elimina los archivos generados
# por el proceso de compilacion. Debe ser llamado explicitamente
# desde linea de comando.
clean:
	rm -rf simple.o esimple
