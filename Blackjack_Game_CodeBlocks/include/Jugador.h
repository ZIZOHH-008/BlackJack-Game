/*
Autores:
John Santiago Jurado - 2537685
Juan Sebastian Paredes - 2535230
Juan Manuel Parra - 2538414

Fecha: julio 10 de 2026



CRC CARD

Clase: Jugador (hereda de Participante)



Responsabilidades:
- Administrar la información del jugador.
- Gestionar el saldo disponible.
- Realizar y almacenar apuestas.
- Solicitar cartas al crupier.
- Decidir si desea continuar jugando.
- Ejecutar su turno de juego.
- Determinar el resultado de la ronda.
(La administración de la mano -agregar carta, mostrarla, calcular su
valor y reiniciarla- la hereda de la clase base Participante)


Colaboradores:
- Participante (clase base de donde hereda Mano y Carta)
- Crupier

  */




#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Participante.h"
class Crupier;



class Jugador : public Participante{

    private:
        std::string nombre{};
        float saldo{};
        float valorApuesta{};
        bool decisión = true;
        int resultadoRonda{};   //0 = perdió    1 = ganó    2 = empate   3 = blackjack


    public:
        Jugador(std::string nombre, int saldo);
        std::string getName() const;

        void pedirCarta(Crupier& crupier); //Referencia al crupier para no copiar objetos

        bool decidirContinuar();
        void jugarTurno(Crupier& crupier);
        void establecerResultado(int resultado);
        int obtenerResultado() const;

        void aumentarSaldo(float cantidad);
        void disminuirSaldo(float cantidad);

        float informarSaldoRestante() const;
        float apostar();    //guarda la apuesta
        float obtenerApuesta() const;     //getter de la apuesta
};

#endif // JUGADOR_H
