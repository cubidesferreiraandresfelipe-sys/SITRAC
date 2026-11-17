#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "ciudades.h"
#include "pasajeros.h"
#include "cola.h"
#include "historial.h"
void guardarSistema(Ciudad* ciudades, Pasajero* pasajeros, const Cola& cola, Historial* historial);
void cargarSistema(Ciudad*& ciudades, Pasajero*& pasajeros, Cola& cola, Historial*& historial);
void mostrarUbicacion();
#endif
