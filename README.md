# SITRAC para Windows

Aplicación de escritorio nativa en C++, basada en el proyecto SITRAC proporcionado.

## Abrir la aplicación

1. Extrae **todo** el ZIP en una carpeta de tu usuario, por ejemplo Documentos/SITRAC.
2. Abre **SITRAC.exe** con doble clic. No se necesita instalar Python, Java ni un servidor.
3. La aplicación carga los datos de ejemplo de la carpeta `datos` al iniciar.
4. Selecciona un módulo a la izquierda, una acción en el desplegable y completa el formulario.
5. Pulsa **Guardar cambios** para conservar tu trabajo antes de salir.

El ejecutable incluido es para Windows de 64 bits. Mantén `datos` junto al ejecutable y ejecuta una sola instancia a la vez. Usa una carpeta donde tengas permiso de escritura. No abras el EXE directamente dentro del ZIP.

## Funciones

- Ciudades: registrar, consultar, eliminar y gestionar conexiones.
- Rutas: registrar, eliminar, consultar ruta directa y calcular el camino más corto con Dijkstra. El regreso se crea o elimina solo si escribes `s`.
- Pasajeros: registro, consulta por documento, actualización y eliminación.
- Solicitudes: registrar viajes, ver el siguiente, atender y cancelar en orden FIFO.
- Historial: consultar todos los registros o los de un pasajero.
- Búsquedas: ciudades, pasajeros por nombre/documento, rutas, caminos, solicitudes e historial.
- Reportes: resumen, ciudad más conectada, rutas extremas, grupos de edad y estados de solicitudes.
- Archivos: guardar, recargar y consultar la ubicación real de los datos.
- Exportar consulta: guarda el resultado visible en un archivo de texto UTF-8.

Los resultados se muestran en un panel de texto seleccionable. La interfaz incluye navegación lateral, formularios, botones y confirmaciones; no abre una consola.

## Datos y reglas

Se conserva el formato de los cinco archivos originales. Los cambios quedan en memoria hasta pulsar Guardar. Al cerrar con cambios, la aplicación permite guardar, descartar o cancelar el cierre. Antes de guardar se copia cada archivo anterior a un archivo `.bak`; estas copias se renuevan en cada guardado. Para restaurarlas, cierra SITRAC y copia los `.bak` sobre los `.txt` correspondientes.

Recargar reemplaza el trabajo en memoria con los datos guardados. Eliminar una ciudad elimina sus conexiones. Las solicitudes que queden sin un camino o sin pasajero se rechazan al atenderse, igual que en el proyecto original. Se mantienen las búsquedas sensibles a mayúsculas: escribe los nombres como aparecen registrados (por ejemplo, `Bogota`). Usa punto decimal para las distancias. La fecha es un campo de texto, como en la versión original, con formato sugerido AAAA-MM-DD.

## Código y compilación

Se conservaron listas enlazadas, grafo por adyacencias, cola FIFO, historial y Dijkstra. `src/windows.cpp` contiene la ventana Win32; `src/interfaz.cpp` conecta las acciones de los formularios con los módulos originales. Cada módulo tiene una nueva entrada `interfaz_*` de una sola acción para evitar que un dato inválido se interprete como otra opción del menú.

- **Dev-C++:** abre `SITRAC-Windows.dev` y compila. `SITRAC.dev` sigue siendo el proyecto de consola original.
- **MinGW:** con `g++` y `windres` en PATH, ejecuta `COMPILAR_WINDOWS.bat`.
- **Visual Studio:** abre esta carpeta como proyecto CMake, selecciona un destino Windows x64 y compila SITRAC. Se necesita la carga de trabajo de desarrollo de escritorio con C++.
- **Consola original:** se conservan `src/main.cpp`, `Makefile`, las pruebas y `README_ORIGINAL.md`.

## Pruebas

Se incluyen las pruebas originales en `pruebas/probar.sh` y las pruebas de la integración gráfica en `pruebas/interfaz_test.cpp`. Estas últimas se ejecutan desde una carpeta temporal con una copia de los datos de ejemplo, porque prueban guardado y carga. Ver `VALIDACION.txt` para el alcance verificado de esta entrega.
