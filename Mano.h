/*
Autores:
John Santiago Jurado - 2537685
Juan Sebastian Paredes - 2535230
Juan Manuel Parra - 2538414

Fecha: mayo 31 de 2026

CRC CARD

Clase: Mano

Responsabilidades:

- Almacenar las cartas de un jugador o del crupier.
- Agregar cartas a la mano.
- Calcular el valor total de la mano.
- Mostrar las cartas de la mano.
- Contar el número de cartas.
- Determinar si la mano tiene Blackjack.
- Determinar si la mano tiene veintiuno.
- Determinar si la mano se ha pasado de 21.

Colaboradores:

- Carta
  */






#ifndef MANO_H
#define MANO_H

#include "Carta.h"
#include <vector>


class Mano{
    private:
        std::vector<Carta> cartas;


    public:
        Mano(); //Inicia vacío porque una mano inicia SIN CARTAS
        ~Mano();

        void agregarCarta(Carta carta);     //El objeto se llama carta y es de tipo Carta
        int calcularValor();
        void mostrarMano();
        int numeroCartas();
        bool tieneBlackjack();
        bool tieneVentiuno();
        bool estaPasada();   
};

#endif // MANO_H
