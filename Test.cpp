#include <iostream> 
#include <cassert>      //Elegimos usar el "assert" para rapidez y comodidad

#include "Carta.h"
#include "Mano.h"
#include "Baraja.h"
#include "Jugador.h"
#include "Crupier.h"
#include "Juego.h"



//RECOMIENDO OCULTAR LAS FUNCIONES Y SOLO DEJAR ABIERTA LA QUE SE VAYA A TESTEAR



void testCarta(){

    // Constructor
    Carta carta1(10, "10", 'P');

    // informarValor()
    assert(carta1.informarValor() == 10);

    // getLetra()
    assert(carta1.getLetra() == "10");



    // Otra carta para verificar que el constructor funciona con otros valores
    Carta carta2(11, "J", 'C');

    assert(carta2.informarValor() == 11);
    assert(carta2.getLetra() == "J");



    // Carta As
    Carta carta3(1, "A", 'D');

    assert(carta3.informarValor() == 1);
    assert(carta3.getLetra() == "A");


    std::cout << "Pruebas Carta superadas.\n";
}






void testMano(){

    // Mano vacía
    Mano mano;

    assert(mano.numeroCartas() == 0);
    assert(mano.calcularValor() == 0);
    assert(mano.tieneVentiuno() == false);
    assert(mano.tieneBlackjack() == false);
    assert(mano.estaPasada() == false);


    // Agregar una carta
    mano.agregarCarta(Carta(10, "10", 'P'));

    assert(mano.numeroCartas() == 1);
    assert(mano.calcularValor() == 10);


    // Agregar segunda carta
    mano.agregarCarta(Carta(8, "8", 'C'));

    assert(mano.numeroCartas() == 2);
    assert(mano.calcularValor() == 18);
    assert(mano.tieneVentiuno() == false);
    assert(mano.tieneBlackjack() == false);
    assert(mano.estaPasada() == false);


    // Blackjack
    Mano blackjack;

    blackjack.agregarCarta(Carta(11, "A", 'D'));
    blackjack.agregarCarta(Carta(10, "K", 'T'));

    assert(blackjack.numeroCartas() == 2);
    assert(blackjack.calcularValor() == 21);
    assert(blackjack.tieneVentiuno() == true);
    assert(blackjack.tieneBlackjack() == true);
    assert(blackjack.estaPasada() == false);



    // 21 SIN Blackjack
    Mano veintiuno;

    veintiuno.agregarCarta(Carta(7, "7", 'P'));
    veintiuno.agregarCarta(Carta(7, "7", 'C'));
    veintiuno.agregarCarta(Carta(7, "7", 'D'));

    assert(veintiuno.calcularValor() == 21);
    assert(veintiuno.tieneVentiuno() == true);
    assert(veintiuno.tieneBlackjack() == false);


    // Mano pasada
    Mano pasada;

    pasada.agregarCarta(Carta(10, "10", 'P'));
    pasada.agregarCarta(Carta(9, "9", 'C'));
    pasada.agregarCarta(Carta(5, "5", 'D'));

    assert(pasada.calcularValor() == 24);
    assert(pasada.estaPasada() == true);


    // As contado como 1
    Mano asReducido;

    asReducido.agregarCarta(Carta(11, "A", 'P'));
    asReducido.agregarCarta(Carta(10, "K", 'C'));
    asReducido.agregarCarta(Carta(5, "5", 'D'));

    assert(asReducido.calcularValor() == 16);
    assert(asReducido.estaPasada() == false);


    std::cout << "Pruebas Mano superadas.\n";
}






void testBaraja(){

    // Constructor
    Baraja baraja;

    // Double Deck = 104 cartas
    assert(baraja.cartasRestantes() == 104);


    // Repartir una carta
    Carta carta1 = baraja.repartirCarta();

    assert(baraja.cartasRestantes() == 103);

    // La carta repartida debe tener un valor válido
    assert(carta1.informarValor() >= 2 && carta1.informarValor() <= 11);


    // Repartir otra carta
    Carta carta2 = baraja.repartirCarta();

    assert(baraja.cartasRestantes() == 102);
    assert(carta2.informarValor() >= 2 && carta2.informarValor() <= 11);



    // Repartir muchas cartas
    for(int i = 0; i < 50; i++){
        baraja.repartirCarta();
    }

    assert(baraja.cartasRestantes() == 52);



    // Barajar nuevamente
    baraja.barajar();

    // Debe seguir teniendo las mismas cartas
    assert(baraja.cartasRestantes() == 52);


    std::cout << "Pruebas Baraja superadas.\n";
}





void testJugador(){

    // Constructor
    Jugador jugador("Juan",1000);
    
    assert(jugador.getName() == "Juan");
    assert(jugador.informarSaldoRestante() == 1000);



    // Métodos heredados de Participante
    jugador.agregarCarta(Carta(10,"10",'P'));
    jugador.agregarCarta(Carta(11,"A",'C'));

    assert(jugador.calcularValorMano() == 21);
    assert(jugador.tieneBlackjack() == true);
    assert(jugador.tieneVentiuno() == true);
    assert(jugador.estaPasado() == false);

    jugador.reiniciarMano();

    assert(jugador.calcularValorMano() == 0);


    // Resultado de la ronda
    jugador.establecerResultado(1);

    assert(jugador.obtenerResultado() == 1);



    // Aumentar saldo
    jugador.aumentarSaldo(500);

    assert(jugador.informarSaldoRestante() == 1500);



    // Disminuir saldo
    jugador.disminuirSaldo(300);

    assert(jugador.informarSaldoRestante() == 1200);


    std::cout << "Pruebas Jugador superadas.\n";
}





void testCrupier(){

    Crupier crupier;

    // ============================
    // Baraja inicial
    // ============================
    assert(crupier.cartasRestantes() == 104);


    // ============================
    // Repartir una carta
    // ============================
    Carta carta = crupier.repartirCarta();

    assert(crupier.cartasRestantes() == 103);

    // La carta debe tener un valor válido
    assert(carta.informarValor() >= 2 && carta.informarValor() <= 11);


    // ============================
    // Repartir carta a un jugador
    // ============================
    Jugador jugador("Juan",1000);

    crupier.repartirCartaAdicional(jugador);

    assert(jugador.calcularValorMano() > 0);
    assert(crupier.cartasRestantes() == 102);


    // ============================
    // Reiniciar baraja
    // ============================
    crupier.reiniciarBaraja();

    assert(crupier.cartasRestantes() == 104);


    // ============================
    // Métodos heredados de Participante
    // ============================
    crupier.agregarCarta(Carta(10,"10",'P'));
    crupier.agregarCarta(Carta(11,"A",'C'));

    assert(crupier.calcularValorMano() == 21);
    assert(crupier.tieneBlackjack() == true);

    crupier.reiniciarMano();

    assert(crupier.calcularValorMano() == 0);


    std::cout << "Pruebas Crupier superadas.\n";
}






void testJuego(){

    Juego juego;

    assert(juego.cantidadJugadores()==0);

    juego.agregarJugador(
        Jugador("Juan",1000)
    );

    assert(juego.cantidadJugadores()==1);

    juego.agregarJugador(
        Jugador("Pedro",500)
    );

    assert(juego.cantidadJugadores()==2);

    juego.eliminarJugador(0);

    assert(juego.cantidadJugadores()==1);

    std::cout<<"Pruebas Juego superadas.\n";
}








/*
g++ Test.cpp Carta.cpp Mano.cpp Baraja.cpp Participante.cpp Jugador.cpp Crupier.cpp  Juego.cpp Art.cpp -o output/test
./output/test
*/


int main(){
    testCarta();
    testMano();
    testBaraja();
    // La clase "Participante.h se prueba al usar Crupier.h y Jugador.h"
    testJugador();
    testCrupier();
    testJuego();    //Como hay funciones que requieren interacción con el usuario, no se pueden realizar

    std::cout << "\nTodas las pruebas fueron exitosas.\n";


    return 0;
}
