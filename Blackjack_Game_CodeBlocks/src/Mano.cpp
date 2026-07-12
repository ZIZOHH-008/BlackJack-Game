#include "Mano.h"
#include "Art.h"
#include <iostream>




Mano::Mano(){
};




void Mano::agregarCarta(Carta carta){
    cartas.push_back(carta);
}




int Mano::calcularValor(){
    int total = 0;
    int ases = 0;

    for(int i = 0; i < cartas.size(); i++){
        total += cartas[i].informarValor();

        if(cartas[i].getLetra() == "A"){  // o como lo tengas
            ases++;
        }
    }

    // ajustar ases
    while(total > 21 && ases > 0){
        total -= 10;   // As pasa de 11 a 1
        ases--;
    }

    return total;
}




void Mano::mostrarMano(){
    std::cout << art::cards << '\n';
    for (int i=0; i<(cartas.size()); i++){
        cartas[i].mostrarCarta();
    }
};




int Mano::numeroCartas(){
    return cartas.size();
};




bool Mano::tieneVentiuno(){
    bool continua{false};


    if (calcularValor() == 21){
        continua = true;
    }

    return continua;
};




bool Mano::tieneBlackjack(){
    bool BJ{false};


    if ((calcularValor() == 21)&&(numeroCartas()==2)){
        BJ = true;
    }

    return BJ;
};




bool Mano::estaPasada(){
    bool continua{false};

    if (calcularValor() > 21){
            continua = true;
    }

    return continua;
};
