# BlackJack-Game
In first semester I made "Mortal Zero" in Python. In this one, Two co-workers and I going to make a BlackJack Game in C++ with OOP

Para compilar:

_g++ main.cpp Carta.cpp Mano.cpp Baraja.cpp Participante.cpp Jugador.cpp Crupier.cpp  Juego.cpp Art.cpp -o output/main 
./output/main_




========== NUESTRAS REGLAS ===========

1. SOBRE EL NUM DE CARTAS  (Se configura en Baraja.cpp)
    1 baraja → “single deck” - 52 cartas     
    2 barajas → “double deck” - 104 cartas    ------->  Nuestro Juego Actual
    4, 6 u 8 barajas → lo más común en casinos modernos - hasta 416 cartas

    Nosotros usaremos: 1 a 2 barajas (por el momento 1 nomas)


2. ¿CUANDO SE GANA?
    El blackjack es solo si tiene 2 cartas y suman 21 (apenas inicia la partida). Esto otorga más del doble del dinero apostado.
    Tener más de 2 cartas y tener 21 de suma tambien finaliza la partida; pero ganando solo el doble del dinero
    Si crupier o Jugador se pasan de 21, finaliza la partida.


3. ¿CUÁNTO SE GANA?                                 (si apostara $100)
    Blackjack natural	3:2                         ($250) 
    Victoria normal	1:1                             ($200)
    Empate (push)	Se devuelve la apuesta          ($100)
    Derrota	Se pierde la apuesta                    ($0)


4. Las barajas NO TIENEN comodines


5. Solo se puede apostar DINERO


6. CARTAS AL CRUPIER
    16 o menos → debe pedir
    17 o más → debe plantarse
