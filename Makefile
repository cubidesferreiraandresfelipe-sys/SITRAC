CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror
SRC = src/main.cpp src/util.cpp src/ciudades.cpp src/rutas.cpp src/pasajeros.cpp src/cola.cpp src/historial.cpp src/busquedas.cpp src/reportes.cpp src/archivos.cpp
TARGET = sitrac

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
