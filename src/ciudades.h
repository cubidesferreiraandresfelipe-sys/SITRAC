#ifndef CIUDADES_H
#define CIUDADES_H
#include <string>
struct Conexion {
    std::string destino;
    double distancia;
    Conexion* siguiente;
};
struct Ciudad {
    std::string nombre;
    Conexion* conexiones;
    Ciudad* siguiente;
};
void agregarCiudad(Ciudad*& inicio, const std::string& nombre);
void eliminarCiudad(Ciudad*& inicio, const std::string& nombre);
Ciudad* buscarCiudad(Ciudad* inicio, const std::string& nombre);
void agregarConexion(Ciudad* inicio, const std::string& origen, const std::string& destino, double distancia);
void consultarCiudades(Ciudad* inicio);
void consultarConexiones(Ciudad* inicio, const std::string& nombre);
void liberarCiudades(Ciudad*& inicio);
void interfaz_ciudades(Ciudad*& inicio, int opcion);
#endif
