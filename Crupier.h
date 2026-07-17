#include "Crupier.h"
#include "Jugador.h"
#include "Art.h"
#include <iostream>

#include <thread> // Necesario para std::this_thread
#include <chrono> // Necesario para std::chrono


Crupier::Crupier(){

}


Crupier::~Crupier(){

}


void Crupier::repartirCartaAdicional(Participante& participante){     // Toma una carta de la baraja
    participante.agregarCarta(baraja.repartirCarta());
}


// mostrarMano(), calcularValorMano() y reiniciarMano() ya no se
// redefinen aquí: Crupier las hereda directamente de Participante.


Carta Crupier::repartirCarta(){
    return baraja.repartirCarta();
}


int Crupier::cartasRestantes(){
    return baraja.cartasRestantes();
}


void Crupier::reiniciarBaraja(){
    baraja = Baraja();
    baraja.barajar();
}


void Crupier::jugarTurno(){

    while(calcularValorMano() < 17){
        std::cout << "\n\n♣═♠═♥═♦ El crupier pide una carta.... ♣═♠═♥═♦\n\n";
        agregarCarta(baraja.repartirCarta());
        std::this_thread::sleep_for(std::chrono::milliseconds(3500));

        std::cout << "\n\n\n============== MANO CRUPIER ==============";
        mostrarMano();
        std::cout << "\nValor Mano Crupier: " << calcularValorMano() << "\n";
    }
    std::cout << "\n♣═♠═♥═♦ El crupier se planta ♣═♠═♥═♦\n\n\n";
}

