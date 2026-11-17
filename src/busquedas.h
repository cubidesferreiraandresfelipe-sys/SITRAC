#ifndef BUSQUEDAS_H
#define BUSQUEDAS_H
#include "ciudades.h"
#include "pasajeros.h"
#include "cola.h"
#include "historial.h"
void buscarCiudad(Ciudad* inicio, const std::string& nombre);
void buscarPasajeroDocumento(Pasajero* inicio, const std::string& doc);
void buscarPasajeroNombre(Pasajero* inicio, const std::string& nombre);
void buscarRutaDirecta(Ciudad* inicio, const std::string& origen, const std::string& destino);
void buscarCaminoCorto(Ciudad* inicio, const std::string& origen, const std::string& destino);
#endif
