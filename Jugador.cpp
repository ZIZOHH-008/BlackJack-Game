#include "Jugador.h"
#include "Crupier.h"
#include "Art.h"
#include <iostream>

#include <thread> // Necesario para std::this_thread
#include <chrono> // Necesario para std::chrono



Jugador::Jugador(std::string _nombre, int _saldo){
    nombre = _nombre;
    saldo = _saldo;
}


Jugador::~Jugador(){

}



std::string Jugador::getName() const{
    return nombre;
}


// ============ Sobre el turno ============

bool Jugador::decidirContinuar(){
    bool decision{false};

    std::cout << "\n\n¿Desea continuar? (0/1)\n";
    std::cin >> decision;
    return decision;
}


void Jugador::jugarTurno(Crupier& crupier){

    // Bucle de recibir cartas hasta que él decida parar o se pase de 21
    while(!estaPasado() && !tieneVentiuno()){
        if(!decidirContinuar()){
            break;
        }
        pedirCarta(crupier);

        std::cout << "\n\n♣═♠ Esperando la nueva carta solicitada.... ♣═♠\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "\n\n========= MANO DE "<< getName() << " =========\n";        //Muestra la mano al recibir carta
        mostrarMano();
        std::cout << "\nValor Mano " << getName() << ": " << calcularValorMano() << "\n";
    }



    if(estaPasado()){
        std::cout << "\nTe pasaste de 21.\n";
    }

    else if(tieneVentiuno()){
        std::cout << "\n¡Consiguió 21!\n";
    }
}


// ============ Sobre manejo de la Mano y Baraja ============
// agregarCarta(), mostrarMano(), calcularValorMano() y reiniciarMano()
// ya no se redefinen aquí: Jugador las hereda directamente de Participante.

void Jugador::pedirCarta(Crupier& crupier){     // Solicitud de carta
    crupier.repartirCartaAdicional(*this);  // *this es que se lo pase a él mismo (al jugador)
}



void Jugador::establecerResultado(int resultado){
    resultadoRonda = resultado;
}


int Jugador::obtenerResultado() const{
    return resultadoRonda;
}



// ============ Sobre Dinero y apuestas ============

void Jugador::aumentarSaldo(float cantidad){
    saldo += cantidad;
}


void Jugador::disminuirSaldo(float cantidad){
    saldo -= cantidad;
}


float Jugador::informarSaldoRestante() const{
    return saldo;
}



float Jugador::apostar(){
    while (true) {
        std::cout << "\n\n¿Cuanto dinero apostará en la ronda el jugador "<< getName() << "?: ";
        std::cin >> valorApuesta;
        
        if (std::cin.fail()) {
            std::cin.clear();   // Quita el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada inválida
            std::cout << "Ingrese un valor válido\n\n";
            continue;
        }

        if(valorApuesta <= 0 || valorApuesta > saldo){
            std::cout << "Por favor ingrese una apuesta válida (Mayor a 0$ y Menor o igual a su saldo total)\n";
            continue;
        }

        break;
    }
    
    return valorApuesta;
}



float Jugador::obtenerApuesta() const{
    return valorApuesta;
}
