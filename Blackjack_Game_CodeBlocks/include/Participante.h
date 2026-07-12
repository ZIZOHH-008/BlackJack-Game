/*
Autores:
John Santiago Jurado - 2537685
Juan Sebastian Paredes - 2535230
Juan Manuel Parra - 2538414

Fecha: julio 10 de 2026


CRC CARD

Clase: Participante (Clase Padre)

Responsabilidades:
- Administrar la mano de cartas, comportamiento común a todo
  participante de la partida (jugador o crupier).
- Agregar cartas a la mano.
- Mostrar las cartas de la mano.
- Calcular el valor de la mano.
- Reiniciar la mano.
- Determinar si tiene Blackjack.
- Determinar si tiene veintiuno.
- Determinar si se ha pasado de 21.

Colaboradores:
- Mano
- Carta
*/



#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include "Mano.h"

class Participante{
    protected:
        Mano mano;   // Atributo protegido: accesible por las clases derivadas (Jugador, Crupier)


    public:
        Participante();
        virtual ~Participante();

        //Las clases hijas no van a modificar el método, no deben ser VIRTUAL
        void agregarCarta(Carta carta);
        void mostrarMano();
        int calcularValorMano();
        void reiniciarMano();

        bool tieneBlackjack();
        bool tieneVentiuno();
        bool estaPasado();
};

#endif // PARTICIPANTE_H
