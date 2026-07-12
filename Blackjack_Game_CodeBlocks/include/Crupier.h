/*
Autores:
John Santiago Jurado - 2537685
Juan Sebastian Paredes - 2535230
Juan Manuel Parra - 2538414

Fecha: julio 10 de 2026



CRC CARD

Clase: Crupier (hereda de Participante)


Responsabilidades:
- Administrar la baraja de juego.
- Repartir cartas a los participantes.
- Repartir cartas para sí mismo.
- Informar cuántas cartas quedan en la baraja.
- Reiniciar la baraja cuando sea necesario.
- Ejecutar su turno de juego según las reglas del Blackjack.
(La administración de su propia mano -agregar carta, mostrarla,
calcular su valor y reiniciarla- la hereda de la clase base Participante)

Colaboradores:
- Participante (clase base de donde hereda Mano y Carta)
- Baraja
- Jugador
  */




#ifndef CRUPIER_H
#define CRUPIER_H

#include "Baraja.h"
#include "Participante.h"
#include <vector>
class Jugador; //evitar dependencia circular, es como incluir jugador


class Crupier : public Participante{
    private:
        Baraja baraja;


    public:
        Crupier();

        void repartirCartaAdicional(Participante& participante);
        Carta repartirCarta();
        int cartasRestantes();
        void reiniciarBaraja();

        void jugarTurno();
};

#endif // CRUPIER_H
