@echo off
setlocal
cd /d "%~dp0"
where g++ >nul 2>nul
if errorlevel 1 (
  echo No se encontro g++. Agrega la carpeta bin de MinGW o Dev-C++ al PATH.
  exit /b 1
)
where windres >nul 2>nul
if errorlevel 1 (
  echo No se encontro windres.
  exit /b 1
)
windres windows.rc -O coff -o windows.res
if errorlevel 1 exit /b 1
g++ -std=c++11 -Wall -Wextra -Werror -O2 -DUNICODE -D_UNICODE src/windows.cpp src/interfaz.cpp src/util.cpp src/ciudades.cpp src/rutas.cpp src/pasajeros.cpp src/cola.cpp src/historial.cpp src/busquedas.cpp src/reportes.cpp src/archivos.cpp windows.res -o SITRAC.exe -lcomctl32 -lcomdlg32 -static-libgcc -static-libstdc++
if errorlevel 1 exit /b 1
echo Compilacion exitosa: SITRAC.exe
