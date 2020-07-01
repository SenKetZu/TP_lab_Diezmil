
//	TP DIEZ MIL 

#include <iostream>
#include <time.h>
#include "rlutil.h"



using namespace std;
using namespace rlutil;

//--------------------funcionales----------------------------

//cuenta cuantas veces aparece el numero indicado en la tirada
int cantNumeros(int elNumeroAcontar,int vectorTirada[6]) {
    //esta variable va a contener la cantidad de veces que aparece el numero que queremos
    int cant = 0;
    
    //este for recorre la tirada buscando el numero que queremos
    for (int j = 0; j <=5; j++) {
        if (vectorTirada[j] == elNumeroAcontar) {
            cant++;
        }
    }


    return cant;
}

// literalmente, dibuja una linea.
void linea() {
    cout << "------------------------------------------------------------------" << endl;
}

//desde aca podemos controlar el tiempo entre pantallas
void Tiempo() {
    msleep(2000);
}

//---------------------------------------------------------------------------------------
//----------------------------Jugadas posibles-------------------------------------------
//---------------------------------------------------------------------------------------


int JuegoDe1 (int vectorTirada[6]) {
    
    if (cantNumeros(1, vectorTirada) == 1 || cantNumeros(1, vectorTirada) == 2) {
        
        return cantNumeros(1, vectorTirada) * 100;

    }
    return 0;
}

int JuegoDe5(int vectorTirada[6]) {
    if (cantNumeros(5, vectorTirada) == 1 || cantNumeros(5, vectorTirada) == 2) {
        return cantNumeros(5, vectorTirada) * 50;
    }
    return 0;
}

int trioDe1(int vectorTirada[6]) {
    if (cantNumeros(1, vectorTirada) == 3) {
        return 1000;
    }
    return 0;
}

int TrioCualquierNumero(int vectorTirada[6]) {
    
    for (int i = 6; i >= 1; i--) {

        if (cantNumeros(i, vectorTirada) == 3){
            
            return cantNumeros(i, vectorTirada) * 100;

		}      
    }
    return 0;

}

int cuatroCincoJuegos(int vectorTirada[6]) {
    for (int i = 6; i > 1; i--) {
        
        if (cantNumeros(i, vectorTirada) == 4 || cantNumeros(i, vectorTirada) == 5) {
            return i * 200;
        }
    }
    return 0;
}

int cuatroCincoUnos(int vectorTirada[6]) {
    if (cantNumeros(1, vectorTirada) == 4 || cantNumeros(1, vectorTirada) == 5) {
        return 2000;
    }
    return 0;
}

int tresPares(int vectorTirada[6]) {
    
    int cantPares = 0;

    //6-6-6-6-6-6
    for (int i = 1; i <= 6; i++) {// aca me pregunta cuantos pares hay de cada numero

            if (cantNumeros(i, vectorTirada) !=0&&cantNumeros(i, vectorTirada) % 2 == 0) {
                cantPares += cantNumeros(i, vectorTirada)/2;
            }
        
    }

    if (cantPares == 3) {
        return 1000;
    }
    
    return 0;
}

int escaleraCompleta(int vectorTirada[6]) {

    for (int i = 1; i <= 6; i++) {
        if (cantNumeros(i, vectorTirada) != 1) {
            return 0;
        }

    }
    return 1500;
}

int sexteto(int vectorTirada[6]) {
    if (cantNumeros(1, vectorTirada) == 6) {
        return 999999;
    }
    return 0;
}

int JuegoNuevo (int vectorTirada[6]){
    //1-6-1-6-1-6/////666111/
    int contador = 0;
    int contador6 = 0;

    if (cantNumeros(1, vectorTirada) == 3 && cantNumeros(6, vectorTirada) == 3){

        for (int i = 0; i < 5; i += 2) {

            if (vectorTirada[i] == 1) {

                contador++;
            }
            
            if (vectorTirada[i] == 6) {
                contador6++;
			}
        }
        if (contador == 3 || contador6 == 3){
            return 1200;
        } 
       
            
    }
    
	
  
    return 0;
}

//---------------------------------------------------------------------------------------
//-------------------FUNCIONES SOBRE LA TIRADA-------------------------------------------
//---------------------------------------------------------------------------------------


//devuelve cual fue la tirada ej: escalera, juego extendido, 3 pares y el puntaje.
int analizarTirada(int vectorTirada[6]){//100-50-0-0-0-....
    int posTirada = 0, puntajeTirada=0, valoresTiradas[10] = { JuegoDe1(vectorTirada), JuegoDe5(vectorTirada), trioDe1(vectorTirada), TrioCualquierNumero(vectorTirada), cuatroCincoUnos(vectorTirada), cuatroCincoJuegos(vectorTirada), tresPares(vectorTirada), escaleraCompleta(vectorTirada),sexteto(vectorTirada), JuegoNuevo(vectorTirada) };

    
    for (int i = 0; i < 10; i++) {
        if (valoresTiradas[i] > puntajeTirada) {
            puntajeTirada = valoresTiradas[i];
            posTirada=i+1;

        }
    }
    
    locate(1, 13);
    switch (posTirada)
    {
    case 0: {cout << "No salio ningun juego :("; break; }
    case 1: {cout << "Juego de 1! +"<<puntajeTirada<<" Puntos"; break; }
    case 2: {cout << "Juego de 5! +" << puntajeTirada << " Puntos"; break; }
    case 3: {cout << "trio de 1! +" << puntajeTirada << " Puntos"; break;  }
    case 4: {cout << "trio de " + to_string(puntajeTirada/100)<< "! +" << puntajeTirada << " Puntos"; break; }
    case 5: {cout << "Juego extendido de unos! +" << puntajeTirada << " Puntos"; break; }
    case 6: {cout << "Juego Extendido de " + to_string(puntajeTirada / 200) + "! +" << puntajeTirada << " Puntos"; break; }
    case 7: {cout << "Juego de tres pares! +" << puntajeTirada << " Puntos";  break; }
    case 8: {cout << "Escalera Completa! +" << puntajeTirada << " Puntos";  break; }
    case 9: {cout << "10.000 TU GANAS";  break; }
    case 10: {cout << "JUEGO NUEVO" << puntajeTirada << "Puntos"; break; }


    default:
        break;
    }
    return puntajeTirada;
}

//hace una tirada => le pone valores aleatorios al vector tirada
void hacerUnaTirada(int vectorTirada[6]) {
	
	for (int i = 0; i < 6;i++) {
        //cin >> vectorTirada[i];
        vectorTirada[i] = rand() % 6 + 1;

	}
}

//esta muestra un dado por pantalla dependiendo del numero, se usa para construir la tirada entera.
void mostrarUnDado(int x, int y, int numero) {
    //Caras del dado
    
    switch (numero){

        case 1: {
            locate(x + 4, y + 2); cout<<(char)219;
            locate(x + 5, y + 2); cout<<(char)219;
        
            break; }
        case 2: {
            locate(x + 1, y + 1); cout<<(char)219;
            locate(x + 2, y + 1); cout<<(char)219;
            locate(x + 7, y + 3); cout<<(char)219;
            locate(x + 8, y + 3); cout<<(char)219;
        
            break; }
        case 3: {
            locate(x + 4, y + 2); cout<<(char)219;
            locate(x + 5, y + 2); cout<<(char)219;
            locate(x + 1, y + 1); cout<<(char)219;
            locate(x + 2, y + 1); cout<<(char)219;
            locate(x + 7, y + 3); cout<<(char)219;
            locate(x + 8, y + 3); cout<<(char)219;
        
            break; }
        case 4: {
            locate(x + 1, y + 1); cout<<(char)219;
            locate(x + 2, y + 1); cout<<(char)219;

            locate(x + 7, y + 1); cout << (char)219;
            locate(x + 8, y + 1); cout << (char)219;

            locate(x + 1, y + 3); cout << (char)219;
            locate(x + 2, y + 3); cout << (char)219;

            locate(x + 7, y + 3); cout<<(char)219;
            locate(x + 8, y + 3); cout<<(char)219;

            break; }
        case 5: {
            locate(x + 1, y + 1); cout<<(char)219;
            locate(x + 2, y + 1); cout<<(char)219;

            locate(x + 7, y + 3); cout<<(char)219;
            locate(x + 8, y + 3); cout<<(char)219;

            locate(x + 4, y + 2); cout<<(char)219;
            locate(x + 5, y + 2); cout<<(char)219;

            locate(x + 1, y + 3); cout<<(char)219;
            locate(x + 2, y + 3); cout<<(char)219;

            locate(x + 7, y + 1); cout<<(char)219;
            locate(x + 8, y + 1); cout<<(char)219;
        
            break; }
        case 6: {
            locate(x + 1, y + 1); cout<<(char)219;
            locate(x + 2, y + 1); cout<<(char)219;
            
            locate(x + 7, y + 3); cout<<(char)219;
            locate(x + 8, y + 3); cout<<(char)219;

            locate(x + 1, y + 3); cout<<(char)219;
            locate(x + 2, y + 3); cout<<(char)219;
            
            locate(x + 7, y + 1); cout<<(char)219;
            locate(x + 8, y + 1); cout<<(char)219;

            locate(x + 4, y + 1); cout<<(char)219;
            locate(x + 5, y + 1); cout<<(char)219;
           
            locate(x + 4, y + 3); cout<<(char)219;
            locate(x + 5, y + 3); cout<<(char)219;
        
            break; }
        default:break;        
    }

    //marco del dado-----------4= al alto de los dados/9= al ancho del dado----------------------------------
    
    //horizontal
    for (int i = 0, ancho = x; i < 9; ancho++, i++) {
        locate(ancho, y); cout << (char)205;
        locate(ancho, 4 + y); cout<<(char)205;
    }
    //vertical
    for (int i = 0, alto = y; i < 4; alto++, i++) {
        locate(x, alto); cout<<(char)186;
        locate(x + 9, alto); cout<<(char)186;
    }
    //esquinas
    locate(x, y); cout << (char)201;
    locate(x, y + 4); cout << (char)200;
    locate(9 + x, y); cout << (char)187;
    locate(9 + x, y + 4); cout << (char)188;
    //------------------------------------------------------------
    
}

//muestra la tirada completa dibujando los 6 dados con sus numeros correspondientes
void mostrarTiradaDados(int y, int vectorTirada[6]) {
    cls();
    for (int i = 0,posX=4; i < 6;i++,posX+=10){
        mostrarUnDado(posX, y, vectorTirada[i]);       
	}
    
    cout << endl;
}
//---------------------------------------------------------------------------------------



//----------------------------------INTERFACES ------------------------------------------

//te pregunta si queres seguir tirando dados para acumular puntos
bool seguirTirando(int vectorPuntaje[3], int jug, int puntajeParcial) {
    locate(1, 16); cout << "seguir tirando?(Y/N)";

    bool control = true;

    while (control) { 
        msleep(100);
        
        //vacia el getch
        while (kbhit()) {
            getch();
        }            
        //----------------
        

        int tecla = getch();

        //si presiona n/N
        if (tecla == 110 || tecla == 78) {

            if (vectorPuntaje[jug] + puntajeParcial <= 10000) {
                vectorPuntaje[jug] += puntajeParcial;
            }
            return false;            
        }
        //si presiona y/Y
        else if (tecla == 89 || tecla == 121) {
            return true;
        }
        //si presiona cualqueir otra cosa
        else {
            cout<<endl<<"Ingrese una opcion valida";
        }
    }
}

//es la presentacion del juego  
void pantallaInicio() {
    srand(time(NULL));
    hidecursor();
    
    system("mode con: cols=66 lines=30");

    linea();
    cout << "\t\t     Bienvenido al Diez Mil" << endl;
    cout << "\t\    Presione cualquier tecla para continuar" << endl;
    linea();

    locate(47, 29); cout  << " elfos.exe "<<(char)184  << " - 1750";
}

//aca se decide la cantidad de jugadores.
int opcionesJuego(string vectorJugadores[3], int rondaGanadora, int vectorPuntaje[3]) {
    
    int corte = 0;


    //vectorPuntaje[2] se guarda la ronda en la que se gano mas rapido
    //rondaGanadora esta el valor de la ronda de la ultima ves que se gano
    if (rondaGanadora != 0) {

        if (rondaGanadora < vectorPuntaje[2]){

            vectorPuntaje[2] = rondaGanadora; 

            if (vectorPuntaje[0] > vectorPuntaje[1]) {

                vectorJugadores[2] = vectorJugadores[0];


			}else if(vectorPuntaje[0] < vectorPuntaje[1]){
                vectorJugadores[2] = vectorJugadores[1];

            }
            else {
                vectorJugadores[2] = "Empate";
            }
		}
	}

    
    do {
        cls();
        
        if (vectorPuntaje[2] != 11) {
            linea();
            cout << "Puntaje maximo anterior: " << vectorJugadores[2] << " en la ronda: " << vectorPuntaje[2] << endl;
        }
        
        linea();
        cout << "seleccione modo de juego:"<<endl ;
        linea();
        cout << "1- Modo un jugador.\n";
        cout << "2- Modo dos jugadores.\n";
        // getch te lee lo que apretas en el teclado
        corte = getch();
        linea();

    } while (!(corte == 49 || corte == 50));

    //si apretaste 1
    if (corte == 49) {
        cout << "nombre del jugador 1: ";
        showcursor();
        cin >> vectorJugadores[0];
        hidecursor();
    }
    //si apretaste 2
    else {
        showcursor();
        cout << "nombre del jugador 1: ";
        cin >> vectorJugadores[0];
        linea();
        cout << "nombre del jugador 2: ";
        cin >> vectorJugadores[1];
        linea();
        hidecursor();
        msleep(1500);
    }
    cls();
    if (corte == 49) {
        return 0;
    }
    else {
        return 1;
    }
}

//esta dibuja la interfaz que se ve durante todo el juego
void interfaz(int jugador, int ronda, int lanz, int puntaje, int puntParcial, string vectorJugadores[2]) {
    locate(1,1);
    cout << "Turno de : "<<vectorJugadores[jugador]<< " | ronda N* "<<ronda << "| Puntaje total: "<<puntaje << endl;
    linea();

    cout << "\nPuntaje de la ronda: "<<puntParcial <<"\n\nLanzamiento N*"<<lanz;
   
    
}

// -----------------------Marco de puntuaciones ----------------------------------------------------------------------------------------------------





//muestra las puntuaciones en la ronda actual
void mostrarMarcoPuntuaciones(int ronda, int jugadorActual, string vectorJugadores[2], int vectorPuntaje[3], int cantJugadores) {
    cls();
    if (cantJugadores==1) {
        //determina el proximo jugador
        int proxJugador;
        if (jugadorActual == 0) {
            proxJugador = 1;
        }
        else {
            proxJugador = 0;
        }
        //----------------------------

        locate(5, 6);
        cout << "\t\t\tRonda N* " << ronda << ":";
        //cout << "\t\t\tProximo turno de ...: " << endl << endl;
        locate(10, 9); cout << "\tEl puntaje de " << vectorJugadores[0] << " es " << vectorPuntaje[0] << " PUNTOS";
        locate(10, 11); cout <<"\tEl puntaje de " << vectorJugadores[1] << " es " << vectorPuntaje[1] << " PUNTOS";
        locate(10, 13); cout <<"\tEl proximo en jugar es: " << vectorJugadores[proxJugador];

    }
    else {
        locate(5, 6);
        cout << "\t\t\tRonda N* " << ronda << ":";
        //cout << "\t\t\tProximo turno de ...: " << endl << endl;
        locate(10, 9); cout << "\tPuntaje de " << vectorJugadores[0] << " es " << vectorPuntaje[0] << " PUNTOS";
        
        
    }
    //muestra el cuadro
    //horizontal
    for (int i = 1; i < 50;  i++) {
        locate(i+8, 5); cout << (char)196;
        locate(i+8, 14); cout << (char)196;
    }
    //vertical
    for (int i = 1; i < 10;  i++) {
        locate(9, i+4); cout << (char)179;
        locate(58, i+4); cout << (char)179;
    }
    //esquinas
    locate(9, 14); cout << (char)192;
    locate(9, 5); cout << (char)218;
    locate(58 , 5); cout << (char)191;
    locate(58 , 14); cout << (char)217;
    //-------------------------------------------------------------------
    msleep(4000);
}

//muestra quien gano y en que ronda.
bool pantallaGanadora(int ronda, int jugador, string vectorJugadores[2], int vectorPuntaje[3]) {
    cls();
    if (vectorPuntaje[jugador] == 10000) {
        locate(10, 10); cout << "\t   " << vectorJugadores[jugador] << " Gano en la ronda " << ronda ;

    }
    else {
        locate(10, 10); cout << "  " << vectorJugadores[jugador] << " Gano en la ronda " << ronda << " con: " << vectorPuntaje[jugador] << " Puntos";

    }
    
    //horizontal
    for (int i = 1; i < 50; i++) {
        locate(i + 8, 5); cout << (char)196;
        locate(i + 8, 14); cout << (char)196;
    }
    //vertical
    for (int i = 1; i < 10; i++) {
        locate(9, i + 4); cout << (char)179;
        locate(58, i + 4); cout << (char)179;
    }
    //esquinas
    locate(9, 14); cout << (char)192;
    locate(9, 5); cout << (char)218;
    locate(58, 5); cout << (char)191;
    locate(58, 14); cout << (char)217;
    
    
    return true;
    
    
    Tiempo();
}

//muestra un cuadro de empate y en que ronda termino.
void pantallaEmpate(int ronda) {
    cls();
    locate(10, 10); cout << "\t" << " El juego termino en empate en la ronda: " << ronda;

    //horizontal
    for (int i = 1; i < 50; i++) {
        locate(i + 8, 5); cout << (char)196;
        locate(i + 8, 14); cout << (char)196;
    }
    //vertical
    for (int i = 1; i < 10; i++) {
        locate(9, i + 4); cout << (char)179;
        locate(58, i + 4); cout << (char)179;
    }
    //esquinas
    locate(9, 14); cout << (char)192;
    locate(9, 5); cout << (char)218;
    locate(58, 5); cout << (char)191;
    locate(58, 14); cout << (char)217;
    Tiempo();
}

//la ultima pantalla que se muestra en el programa.
void pantallaFinal() {
    cls();
    locate(10, 10); cout << "\t\t" << "El juego termino";

    //horizontal
    for (int i = 1; i < 50; i++) {
        locate(i + 8, 5); cout << (char)196;
        locate(i + 8, 14); cout << (char)196;
    }
    //vertical
    for (int i = 1; i < 10; i++) {
        locate(9, i + 4); cout << (char)179;
        locate(58, i + 4); cout << (char)179;
    }
    //esquinas
    locate(9, 14); cout << (char)192;
    locate(9, 5); cout << (char)218;
    locate(58, 5); cout << (char)191;
    locate(58, 14); cout << (char)217;
    Tiempo();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------
//--------------------------juego principal---------------------------
//--------------------------------------------------------------------

int Juego(int cantJugadores, int vectorTirada[6], int vectorPuntaje[3], string vectorJugadores[3]) {
    vectorPuntaje[0] = 0;
    vectorPuntaje[1] = 0;

    int ronda_ganadora=0;
    bool ganoAlguien = false, seguirHaciendoTiradas;

    for (int rondas = 1; rondas <= 10&&!ganoAlguien; rondas++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                            //https://cutt.ly/eu6Ape5               
        for (int jug = 0; jug <= cantJugadores; jug++) {
            
            seguirHaciendoTiradas = true;
            int lanzamiento = 1, puntajeParcial=0, puntajeTirada=0;
            
            //este ciclo sigue haciendo tiradas mientras el jugador asi quiera y mientras no pierda.
            while (seguirHaciendoTiradas) {
                            
                hacerUnaTirada(vectorTirada);
                mostrarTiradaDados(7,vectorTirada);

                puntajeTirada = 100;//analizarTirada(vectorTirada);
                
                //si la tirada sale normal
                if (puntajeTirada != 0 && puntajeParcial+puntajeTirada+vectorPuntaje[jug]<10000) {
                    
                    
                    puntajeParcial += puntajeTirada;                    
                    interfaz(jug, rondas, lanzamiento, vectorPuntaje[jug], puntajeParcial, vectorJugadores);
                    
                    //pregunta si queres seguir tirando o te plantas.
                    seguirHaciendoTiradas = seguirTirando(vectorPuntaje, jug, puntajeParcial);
                }
                
                //cualquier otra cosa
                else{
                    seguirHaciendoTiradas = false;
                    
                    //si llegas a 10000 y jugas solo, termina la partida
                    if (cantJugadores == 0 && puntajeParcial + puntajeTirada + vectorPuntaje[jug] == 10000) {
                        puntajeParcial += puntajeTirada;
                        vectorPuntaje[jug] += puntajeParcial;
                        ganoAlguien= pantallaGanadora(rondas, jug, vectorJugadores, vectorPuntaje);
                        ronda_ganadora = rondas;


                        Tiempo();
                        break;
                    }
                    //si llegas a 10000 jugando de a 2
                    else if (puntajeParcial + puntajeTirada + vectorPuntaje[jug] == 10000) {
                        puntajeParcial += puntajeTirada;
                        vectorPuntaje[jug] += puntajeParcial;
                        ganoAlguien = pantallaGanadora(rondas, jug, vectorJugadores, vectorPuntaje);
                        ronda_ganadora = rondas;


                        Tiempo();
                        break;
                    }
                    
                    //si te sale un sexteto
                    else if (puntajeTirada==999999) {
                        vectorPuntaje[jug] = 10000;
                        ganoAlguien = pantallaGanadora(rondas, jug, vectorJugadores, vectorPuntaje);

                        Tiempo();
                        break;
                    }                   
                    
                    //si te pasas de 10000 en la tirada
                    else if (puntajeParcial+puntajeTirada +  vectorPuntaje[jug] > 10000) {
                        

                        interfaz(jug, rondas, lanzamiento, vectorPuntaje[jug], puntajeParcial, vectorJugadores);
                        

                        locate(1, 13); cout << "Te pasaste "<< (puntajeParcial + puntajeTirada + vectorPuntaje[jug]) - 10000 <<" puntos                                                     ";
                        Tiempo();      
                        puntajeParcial = 0;

                    }
                    
                    //si no te sale nada en la tirada
                    else if(puntajeTirada==0) {
                        puntajeParcial = 0;
                        interfaz(jug, rondas, lanzamiento, vectorPuntaje[jug], puntajeParcial, vectorJugadores);
                        lanzamiento = 0;
                        Tiempo();                       
                    }                                                           
                }
                
                

                puntajeTirada = 0;
                lanzamiento++;
            } 
            //final de cada turno
            if (!ganoAlguien) {
                mostrarMarcoPuntuaciones(rondas, jug, vectorJugadores, vectorPuntaje, cantJugadores);
            }
           
        }


        if (cantJugadores == 1) {
            //si los dos terminan la ronda en 10000
            if (vectorPuntaje[0] == 10000 && vectorPuntaje[1] == 10000) {
                pantallaEmpate(rondas);
                ronda_ganadora = rondas;
                break;

            }

            //si el jugador 1 termina la ronda en 10000
            else if (vectorPuntaje[0] == 10000) {
                ganoAlguien = pantallaGanadora(rondas, 0, vectorJugadores, vectorPuntaje);
                ronda_ganadora = rondas;
                break;

            }

            //si el jugador 2 termina la ronda en 10000
            else if (vectorPuntaje[1] == 10000) {
                ganoAlguien = pantallaGanadora(rondas, 1, vectorJugadores, vectorPuntaje);
                ronda_ganadora = rondas;
                break;
            }
        }
    }
    
    //si nadie llego a 10000 al final del juego
    if (!ganoAlguien&&cantJugadores==1) {
        if(vectorPuntaje[0] == vectorPuntaje[1]) {
            pantallaEmpate(10);
        }
        else if (vectorPuntaje[0] > vectorPuntaje[1]) {
            pantallaGanadora(10,0, vectorJugadores, vectorPuntaje);
        }
        else {
            pantallaGanadora(10, 1, vectorJugadores, vectorPuntaje);
        }
    }
    else {
        pantallaFinal();

    }
    if (!ganoAlguien) {
        return 0;
    }
    return ronda_ganadora;
}

//--------------------------------------------------------------------
//----------------------------MAIN------------------------------------
//--------------------------------------------------------------------


int main() {
    bool otrojuego = true;
    int rond = 0;
    //-------VECTORES INT
    int vectorTirada[6];
    //el tercer puntaje, es en realidad la ronda en la que se gano antes.
    int vectorPuntaje[3] = { 0,0,11 };

    //-------VECTORES STRING
    string vectorJugadores[3] = { "Jugador1","Jugador2","jugadorMaximo" };
   
    
    while (otrojuego) {
        
        pantallaInicio();
        anykey();
        cls();

        
        rond=Juego(opcionesJuego(vectorJugadores, rond, vectorPuntaje),    vectorTirada, vectorPuntaje, vectorJugadores);


        locate(1, 16); cout << "seguir jugando?(Y/N)";

        bool control = true;

        while (control) {
            msleep(100);

            //vacia el getch
            while (kbhit()) {
                getch();
            }
            //----------------


            int tecla = getch();

            //si presiona n/N
            if (tecla == 110 || tecla == 78) {

                otrojuego = false;
                control = false;



            }
            //si presiona y/Y
            else if (tecla == 89 || tecla == 121) {
                
                control = false;

            }
            //si presiona cualqueir otra cosa
            else {
                cout << endl << "Ingrese una opcion valida";
            }

        }
    }
    
    cout << endl;
    system("pause");
    return 0;
}