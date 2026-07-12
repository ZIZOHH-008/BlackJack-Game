/*============ PROYECTO FINAL DE POO ============

Realizado por:
    - Juan Manuel Parra Prado - 2538414
    - Juan Sebastian Paredes Arroyave - 2535230
    - John Santiago Jurado - 2537685

Fecha:
    - Durante el semestre 2026-1
*/

/*
g++ main.cpp Carta.cpp Mano.cpp Baraja.cpp Participante.cpp Jugador.cpp Crupier.cpp  Juego.cpp Art.cpp -o output/main 
./output/main
*/


#include "Carta.h"
#include "Mano.h"
#include "Baraja.h"
#include "Jugador.h"
#include "Crupier.h"
#include "Juego.h"

#include "Art.h"
#include <iostream>
#include <limits>


 


int main(){
    Juego juego;
    int cantidadJugadores;

    std::cout << art::title << '\n';
    std::cout << art::machine << '\n';
 

    // Bucle para que no Entre en BUG si alguien ingresa un número de jugadores inválido
    while (true) {
        std::cout << "Cantidad de jugadores: ";
        std::cin >> cantidadJugadores;
        
        if (std::cin.fail()) {
            std::cin.clear();   // Quita el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada inválida
            std::cout << "Ingrese un número válido\n\n";
            continue;
        }

        if (cantidadJugadores <= 0) {
            std::cout << "La cantidad de jugadores debe ser mayor que 0\n\n";
            continue;
        }

        break;
    }


    // Agrega las personas al juego
    for(int i = 0; i < cantidadJugadores; i++){
        std::string nombre;
        float saldoInicial;

        std::cout << "\nNombre del jugador " << i + 1 << ": ";
        std::cin >> nombre;


        // Bucle para que no Entre en BUG si alguien ingresa un saldo inválido
        while (true) {
            std::cout << "Saldo inicial: ";
            std::cin >> saldoInicial;
            
            if (std::cin.fail()) {
                std::cin.clear();   // Quita el estado de error
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada inválida
                std::cout << "Ingrese un saldo válido\n\n";
                continue;   //Repite el bucle desde el inicio
            }

            if (saldoInicial <= 0) {
                std::cout << "El saldo de entrada debe ser mayor que 0.\n\n";
                continue;   //Repite el bucle desde el inicio
            }

            break;
        }
        
        Jugador jugador(nombre, saldoInicial);
        juego.agregarJugador(jugador);
    }



    // Inicia la ronda
    char continuar = 's';

    do{
        char economia{};
        juego.iniciarRonda();

        juego.determinarGanador();

        juego.administrarDinero();
        juego.terminarRonda();


        if (juego.cantidadJugadores() == 0) {
            std::cout << "\n\n♠ ♥ ♦ ♣  TODOS LOS JUGADORES HAN QUEBRADO ♠ ♥ ♦ ♣ \n";
            break;
        }

        else{
            std::cout << "\n\n¿Desea ver su economía? (s/n): ";
            std::cin >> economia;

            if(economia == 's' || economia == 'S'){
                juego.informarSaldo();
            } 

            std::cout << "\n\n¿Jugar otra ronda? (s/n): ";
            std::cin >> continuar;
        }

    } while((continuar == 's' || continuar == 'S') && (juego.cantidadJugadores()>0));



    std::cout << "\n\n\n\n\n";
    std::cout << art::title_finish;
    std::cout << art::finish;

    return 0;

}

