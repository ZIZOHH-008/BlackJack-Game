#include "Carta.h"

#include <iostream>

Carta::Carta(int _valorNominal, std::string _letraNumCarta, char _palo){
    valorNominal = _valorNominal;
    letraNumCarta = _letraNumCarta;
    palo = _palo;
}


void Carta::mostrarCarta(){
    std::cout << "\n\n==== Información de la carta ====\n";
    std::cout << "Valor: " << valorNominal << '\n';
    std::cout << "Letra o Número: " << letraNumCarta << '\n';   // J, Q, K
    std::cout << "Palo: " << palo << '\n'; // D, C, P, T
}



int Carta::informarValor(){
    return valorNominal;
}



std::string Carta::getLetra(){
    return letraNumCarta;
};