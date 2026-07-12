#include "Participante.h"


Participante::Participante(){
}


Participante::~Participante(){
}


void Participante::agregarCarta(Carta carta){    // Recibe la carta y la pone en su mano
    mano.agregarCarta(carta);
}


void Participante::mostrarMano(){
    mano.mostrarMano();
}


int Participante::calcularValorMano(){
    return mano.calcularValor();
}


void Participante::reiniciarMano(){
    mano = Mano();
}




bool Participante::tieneBlackjack(){
    return mano.tieneBlackjack();
}


bool Participante::tieneVentiuno(){
    return mano.tieneVentiuno();
}


bool Participante::estaPasado(){
    return mano.estaPasada();
}
