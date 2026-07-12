#include "Juego.h"
#include "Art.h"
#include <iostream>

#include <thread> // Necesario para std::this_thread
#include <chrono> // Necesario para std::chrono



Juego::Juego(){
}



// ============ Manejo de las rondas ============

void Juego::iniciarRonda(){ //¿VIOLA EL PRU?

    for(int i=0; i<jugadores.size(); i++){
        jugadores[i].apostar();
    }

    repartirCartasIniciales();

    for(int i=0; i<jugadores.size(); i++){
        std::cout << '\n' << art::borde1 << "\n";
        std::cout << "\n\n\n♣═♠ Turno del Jugador.... "<< jugadores[i].getName() << " ♣═♠\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));

        std::cout << "\n\n========= MANO DE "<< jugadores[i].getName() << " =========\n";
        jugadores[i].mostrarMano();  // Muestra la mano de las cartas iniciales
        std::cout << "\nValor Mano " << jugadores[i].getName() << ": " << jugadores[i].calcularValorMano() << "\n";

        jugadores[i].jugarTurno(crupier);   //Aquí se hace lo que aparece en jugador::jugarTurno
    }

    std::cout << "\n\n♣═♠ Turno del Crupier.... ♣═♠\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << '\n' << art::borde2 << "\n";
    std::cout << "\n\n\n============== MANO CRUPIER ==============";
    crupier.mostrarMano(); // Muestra cartas iniciales
    std::cout << "\n\nValor Mano del Crupier: "<<  crupier.calcularValorMano() << "\n\n";
    crupier.jugarTurno();
}



void Juego::terminarRonda(){

    for(int i = 0; i < jugadores.size(); i++){
        if(jugadores[i].informarSaldoRestante() <= 0){
            std::cout << "\n♠ El jugador "<< jugadores[i].getName() << " ha quebrado.";
            eliminarJugador(i);
            i--;
        }
    }

    rondaActual++;

    if(jugadores.size() == 0){
        estadoJuego = false;
    }

    reiniciarManos();
}




// ============ Manejo de cartas y manos ============

void Juego::repartirCartasIniciales(){

    std::cout << "\n\n♣═♠═♥═♦ Repartiendo Cartas Iniciales... ♣═♠═♥═♦\n\n";


    for(int i=0; i<2; i++){

        for(int j=0; j<jugadores.size(); j++){
            jugadores[j].pedirCarta(crupier);
        }

        crupier.agregarCarta(
            crupier.repartirCarta()
        );
    }
}



void Juego::reiniciarManos(){
    for(int i=0; i<jugadores.size(); i++){
        jugadores[i].reiniciarMano();
    }

    crupier.reiniciarMano();
}






// ============ Manejo de Dinero ============

void Juego::informarSaldo(){

    for(int i=0; i<jugadores.size(); i++){
        float apuesta = jugadores[i].obtenerApuesta();

        std::cout << "\n\n========= ECONOMÍA DE "<< jugadores[i].getName() << " =========";
        std::cout << "\nApostó: $" << apuesta;

        if(jugadores[i].obtenerResultado() == 0){
            std::cout << "\nPerdió: $" << apuesta;
        }

        else if(jugadores[i].obtenerResultado() == 1){
            std::cout << "\nGanó: $" << apuesta;
        }

        else if(jugadores[i].obtenerResultado() == 3){
            std::cout << "\nGanó (Blackjack): $" << apuesta * 1.5;
        }

        else{
            std::cout << "\nEmpató";
        }

        std::cout << "\nSaldo actual: $" << jugadores[i].informarSaldoRestante() << "\n\n\n";
    }
}


void Juego::administrarDinero(){
    cobrarPerdedores();
    pagarGanadores();
}


void Juego::determinarGanador(){
    int valorCrupier = crupier.calcularValorMano();

    std::cout << art::borde1 << "\n";
    std::cout << "\n\n♣═♠ Cargando Resultados de la ronda.... ♣═♠\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3500));


    std::cout << "\n\n\n♣═♠═♥═♦═♣═♠═♥═♦═♣ RESULTADOS ♣═♠═♥═♦═♣═♠═♥═♦═♣\n\n";

    for(int i=0; i<jugadores.size(); i++){
        int valorJugador = jugadores[i].calcularValorMano();

        if(valorJugador > 21){
            jugadores[i].establecerResultado(0);
            std::cout << "♠ El jugador " << jugadores[i].getName() << " pierde\n";
            std::cout << art::loose1 << "\n\n\n\n";
        }

        else if(jugadores[i].tieneBlackjack()){
            jugadores[i].establecerResultado(3);
            std::cout << "♥ ♦ El jugador " << jugadores[i].getName() << " TUVO UN BLACKJACK\n";
            std::cout << art::money_BJ << "\n\n\n\n";
        }

        else if(valorCrupier > 21){
            jugadores[i].establecerResultado(1);
            std::cout << "♦ El jugador " << jugadores[i].getName() << " gana\n";
            std::cout << art::money_norm << "\n\n\n\n";
        }

        else if(valorJugador > valorCrupier){
            jugadores[i].establecerResultado(1);
            std::cout << "♦ El jugador " << jugadores[i].getName() << " gana\n";
            std::cout << art::money_norm << "\n\n\n\n";
        }

        else if(valorJugador < valorCrupier){
            jugadores[i].establecerResultado(0);
            std::cout << "♠ El jugador " << jugadores[i].getName() << " pierde\n";
            std::cout << art::loose1 << "\n\n\n\n";
        }

        else{
            jugadores[i].establecerResultado(2);
            std::cout << "♥ El jugador " << jugadores[i].getName() << " empató\n";
            std::cout << art::peaceful << "\n\n\n\n";
        }
    }
}



void Juego::pagarGanadores(){

    for(int i=0; i<jugadores.size(); i++){
        float apuesta = jugadores[i].obtenerApuesta();
        if(jugadores[i].obtenerResultado() == 1){
            jugadores[i].aumentarSaldo(apuesta);
        }

        else if(jugadores[i].obtenerResultado() == 3){
            jugadores[i].aumentarSaldo(apuesta * 1.5);
        }
    }
}



void Juego::cobrarPerdedores(){
    for(int i=0; i<jugadores.size(); i++){
        float apuesta = jugadores[i].obtenerApuesta();
        if(jugadores[i].obtenerResultado() == 0){
            jugadores[i].disminuirSaldo(apuesta);
        }
    }
}






// ============ Manejo de Jugadores ============

void Juego::agregarJugador(const Jugador& jugador){
    jugadores.push_back(jugador);
}


void Juego::eliminarJugador(int index){
    jugadores.erase(jugadores.begin() + index);
}


int Juego::cantidadJugadores() const {
    return (jugadores.size());
}