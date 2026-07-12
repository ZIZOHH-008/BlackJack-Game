/*
Autores:
John Santiago Jurado - 2537685
Juan Sebastian Paredes - 2535230
Juan Manuel Parra - 2538414

Fecha: mayo 31 de 2026



CRC CARD

Clase: Baraja

Responsabilidades:
- Almacenar las cartas del juego.
- Barajar las cartas.
- Repartir cartas cuando son solicitadas.
- Informar cuántas cartas quedan disponibles.

Colaboradores:
- Carta
  */




#ifndef BARAJA_H
#define BARAJA_H

#include "Carta.h"
#include <vector>


class Baraja{
    private:
        std::vector<Carta> cartas;


    public:
        Baraja();

        void barajar();
        Carta repartirCarta();
        int cartasRestantes();
};

#endif // BARAJA_H