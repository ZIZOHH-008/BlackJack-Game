#include "Baraja.h"
#include <algorithm>
#include <random>

Baraja::Baraja(){       // Double deck 

    char palos[] = {'C','D','P','T'};

    for(int mazo = 0; mazo<2; mazo++){   // Con cambiar el comparador de mazo se aumentan las barajas
        for(int i = 0; i < 4; i++){

            cartas.push_back(Carta(11,"A",palos[i]));

            for(int j = 2; j <= 10; j++){
                cartas.push_back(Carta(j, std::to_string(j), palos[i]));
            }

            cartas.push_back(Carta(10,"J",palos[i]));
            cartas.push_back(Carta(10,"Q",palos[i]));
            cartas.push_back(Carta(10,"K",palos[i]));
        }
    }
    barajar();
}



Baraja::~Baraja(){

};



void Baraja::barajar(){
    /*
    shuffle - mezcla aleatoriamente los elementos del vector
    random_device{}() - Semilla aleatoria para que no se inicie siempre con el mismo valor
    default_random_engine(...)  - Generador de numero aleatorios
    
    shuffle(cartas.begin(), cartas.end(), generador);  - Mezcla las cartas
    */
    std::shuffle(cartas.begin(), cartas.end(), std::default_random_engine(std::random_device{}()));
}



Carta Baraja::repartirCarta(){
    Carta carta = cartas.back();    //Toma lo ultimo del vector
    cartas.pop_back();  //elimina el último elemento del vector (en este caso, elimina la carta de baraja)
    return carta;   //regresa lo que había de ultimo en el vector
}



int Baraja::cartasRestantes(){
    return cartas.size();
}
