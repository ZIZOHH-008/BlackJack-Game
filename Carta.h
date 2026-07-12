/*
Autores:
John Santiago Jurado - 2537685
Juan Sebastian Paredes - 2535230
Juan Manuel Parra - 2538414

Fecha: mayo 31 de 2026



CRC CARD

Clase: Carta

Responsabilidades:
- Almacenar el valor nominal de la carta.
- Almacenar la representación de la carta (A, 2-10, J, Q, K).
- Almacenar el palo de la carta.
- Informar el valor de la carta.
- Informar la representación de la carta.
- Mostrar la información de la carta.

Colaboradores:
- No tiene porque es la clase base de todo
  */




#ifndef CARTA_H
#define CARTA_H
#include <string>


class Carta{
    private:
        int valorNominal{};
        std::string letraNumCarta{}; //Más adelante, es más útil como "string" que como "char"
        char palo{};


    public:
        Carta(int, std::string, char); //constructor

        int informarValor();
        void mostrarCarta();
        std::string getLetra();
};

#endif // CARTA_H
