/*
Autores:
John Santiago Jurado - 2537685
Juan Sebastian Paredes - 2535230
Juan Manuel Parra - 2538414

Fecha: mayo 31 de 2026



CRC CARD

Clase: Juego

Responsabilidades:
- Administrar el desarrollo de la partida.
- Gestionar las rondas de juego.
- Controlar el estado del juego.
- Administrar los jugadores participantes.
- Coordinar el reparto inicial de cartas.
- Reiniciar las manos al finalizar una ronda.
- Determinar los ganadores de la ronda.
- Administrar las apuestas y el dinero de los jugadores.
- Informar al jugador su saldo restante
- Pagar a los ganadores.
- Cobrar a los perdedores.

Colaboradores:
- Jugador
- Crupier
  */



#include "Jugador.h"
#include "Crupier.h"


class Juego{
    private:
        std::vector<Jugador> jugadores;
        Crupier crupier;
        bool estadoJuego{0};
        int rondaActual{0};
        
        
    public:
        Juego();
        
        void iniciarRonda();
        void terminarRonda();

        void repartirCartasIniciales();
        void reiniciarManos();

        void informarSaldo();
        void determinarGanador();
        void administrarDinero();
        void pagarGanadores();
        void cobrarPerdedores();
        
        void agregarJugador(const Jugador& jugador); //Referencia para no copiar objeto
        void eliminarJugador(int index);
        int cantidadJugadores() const;
        
};

