
//	TP DIEZ MIL 

#include <iostream>
#include <time.h>
#include "rlutil.h"



using namespace std;
using namespace rlutil;

//--------------------funcionales----------------------------
int cantNumeros(int elNumeroAcontar,int vectorTirada[6]) {
    //vector auxiliar, en la posicion 1 esta la cantidad de 1 que hay, y asi sucecivamente
    int cantNumeros[6];

    //este ciclo rellena el vector aux con ceros
    for (int i = 0; i <= 5; i++) {
        cantNumeros[i] = 0;
    }
    
    for (int i = 0; i <= 5; i++) {// i va llenando el vector con la cantidad de numeros, en cada posicion, por ejemplo en i=0 va a guardar todos los 1 que hay
        for (int j = 0; j <=5; j++) {//j recorre la tirada buscando el numero que le pasa la variable i.
            
            if (vectorTirada[j] == i+1) {//i+1 es el numero que busca 
                cantNumeros[i]++;
            }
        }
    }

    return cantNumeros[elNumeroAcontar-1];
}

// literalmente, dibuja una linea.
void linea() {
    cout << "------------------------------------------------------------------" << endl;
}

//---------------------------------------------------------------------------------------
//----------------------------Jugadas posibles-------------------------------------------
//---------------------------------------------------------------------------------------


int JuegoDe1(int vectorTirada[6]) {
    //pregunta si hay uno o dos 1 en la tirada, y te da el puntaje.
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
    for (int i = 6; i > 1; i--) {
        if (cantNumeros(i, vectorTirada) == 3) {
            return i * 100;
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


    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 3; j++) {
            if (cantNumeros(i, vectorTirada) !=0&&cantNumeros(i, vectorTirada) % (j * 2) == 0) {
                cantPares += j;
            }
        }
    }
    if (cantPares >= 3) {
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


//---------------------------------------------------------------------------------------
//-------------------FUNCIONES SOBRE LA TIRADA-------------------------------------------
//---------------------------------------------------------------------------------------


//devuelve cual fue la tirada ej: escalera, juego extendido, 3 pares y el puntaje.
int analizarTirada(int vectorTirada[6]){//100-50-0-0-0-....
    int posTirada = 0, puntajeTirada=0, valoresTiradas[9] = { JuegoDe1(vectorTirada), JuegoDe5(vectorTirada), trioDe1(vectorTirada), TrioCualquierNumero(vectorTirada), cuatroCincoUnos(vectorTirada), cuatroCincoJuegos(vectorTirada), tresPares(vectorTirada), escaleraCompleta(vectorTirada),sexteto(vectorTirada) };

    
    for (int i = 0; i < 9; i++) {
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


    default:
        break;
    }
    return puntajeTirada;
}

//hace una tirada => le pone valores aleatorios al vector tirada
void hacerUnaTirada(int vectorTirada[6]) {
	
	for (int i = 0; i < 6;i++) {
		
        vectorTirada[i] = rand() % 6 + 1;

	}
}

//esta muestra un dado por pantalla dependiendo del numero, se usa para construir la tirada entera.
void mostrarUnDado(int x, int y, int numero) {
    //Caras del dado
    //4-7-2
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
        locate(x + 7, y + 3); cout<<(char)219;
        locate(x + 8, y + 3); cout<<(char)219;

        locate(x + 1, y + 3); cout<<(char)219;
        locate(x + 2, y + 3); cout<<(char)219;
        locate(x + 7, y + 1); cout<<(char)219;
        locate(x + 8, y + 1); cout<<(char)219;
        
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


    default:
        break;
    }

    //marco del dado---------------------------------------------
       //horizontal
    for (int i = 0, ancho = x; i < 9; ancho++, i++) {
        locate(ancho, y); cout << (char)205;
        locate(ancho, 4 + y); cout<<(char)205;
    };
    //vertical
    for (int i = 0, alto = y; i < 4; alto++, i++) {
        locate(x, alto); cout<<(char)186;
        locate(x + 9, alto); cout<<(char)186;
    };
    //esquinas
    locate(x, y); cout << (char)201;
    locate(x, y + 4); cout << (char)200;
    locate(9 + x, y); cout << (char)187;
    locate(9 + x, y + 4); cout << (char)188;
    //------------------------------------------------------------
    
}

//muestra la tirada completa dibujando los 6 dados con sus numeros correspondientes
void mostrarTiradaDados(int y, int vectorTirada[6]) {
    
    for (int i = 0,posX=4; i < 6;i++,posX+=10) {
		switch (vectorTirada[i])
		{

        case 1: {mostrarUnDado(posX, y, 1); break; }
		case 2: {mostrarUnDado(posX, y, 2); break; }
		case 3: {mostrarUnDado(posX, y, 3); break; }
		case 4: {mostrarUnDado(posX, y, 4); break; }
		case 5: {mostrarUnDado(posX, y, 5); break; }
		case 6: {mostrarUnDado(posX, y, 6); break; }
		
		
		default:
			break;
		}
	}
    
    cout << endl;
}
//---------------------------------------------------------------------------------------



//----------------------------------INTERFACES ------------------------------------------

//te pregunta si queres seguir tirando dados para acumular puntos
bool seguirTirando(int vectorPuntaje[2], int jug, int puntajeParcial) {
    locate(1, 16); cout << "seguir tirando?(Y/N)";

    bool control = true;

    while (control) { 
        msleep(100);
        
        //vacia el getch
        while (kbhit())
            getch();
        //----------------        
        

        int tecla = getch();


        if (tecla == 110 || tecla == 78) {

            if (vectorPuntaje[jug] + puntajeParcial <= 10000) {
                vectorPuntaje[jug] += puntajeParcial;
            }
            return false;            
        }
        else if (tecla == 89 || tecla == 121) {
            return true;
        }
        else {
            system("pause");
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
int opcionesJuego(string vectorJugadores[2]) {
    int corte = 0;

    do {
        cls();
        linea();
        cout << "seleccione modo de juego:" << endl;
        linea();
        cout << "1- modo un jugador.\n";
        cout << "2- modo dos jugadores.\n";
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
void mostrarMarcoPuntuaciones(int ronda, int jugadorActual, string vectorJugadores[2], int vectorPuntaje[2], int cantJugadores) {
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
}

//muestra quien gano y en que ronda.
bool pantallaGanadora(int ronda, int jugador, string vectorJugadores[2]) {

    locate(10, 10); cout <<"\t"<< vectorJugadores[jugador]<<" Gano en la ronda "<<ronda;

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
    
    
    msleep(2000);
}

//muestra un cuadro de empate y en que ronda termino.
void pantallaEmpate(int ronda) {
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
    msleep(2000);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------
//--------------------------juego principal---------------------------
//--------------------------------------------------------------------

void Juego(int cantJugadores, int vectorTirada[6], int vectorPuntaje[2], string vectorJugadores[2]) {
    
    bool ganoAlguien = false;

    for (int rondas = 1; rondas <= 10; rondas++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                            //https://cutt.ly/eu6Ape5
        bool seguirHaciendoTiradas = true;
        
        for (int jug = 0; jug <= cantJugadores; jug++) {
            seguirHaciendoTiradas = true;
            int lanzamiento = 1, puntajeParcial=0, puntajeTirada=0;
            
            while (seguirHaciendoTiradas) {
                
                cls();              
                hacerUnaTirada(vectorTirada);
                mostrarTiradaDados(7,vectorTirada);

                puntajeTirada = analizarTirada(vectorTirada);
                
                
                if (puntajeTirada != 0 && puntajeParcial+puntajeTirada+vectorPuntaje[jug]<10000) {
                    
                    
                    puntajeParcial += puntajeTirada;
                    
                    interfaz(jug, rondas, lanzamiento, vectorPuntaje[jug], puntajeParcial, vectorJugadores);
                                                         
                }else{
                    seguirHaciendoTiradas = false;
                    if (cantJugadores == 0 && puntajeParcial + puntajeTirada + vectorPuntaje[jug] == 10000) {
                        cls();
                        ganoAlguien= pantallaGanadora(rondas, jug, vectorJugadores);
                        jug = 2;
                        rondas = 11;
                        msleep(2000);
                        break;
                    }
                    
                    //si te sale un sexteto
                    if (puntajeTirada==999999) {
                        
                        cls();
                        ganoAlguien = pantallaGanadora(rondas, jug, vectorJugadores);
                        jug = 2;
                        rondas = 11;
                        msleep(2000);
                        break;
                    }
                    //si te pasas de 10000 en la tirada
                    else if (puntajeParcial+puntajeTirada +  vectorPuntaje[jug] > 10000) {
                        
                        cls();
                        mostrarTiradaDados(7, vectorTirada);
                        interfaz(jug, rondas, lanzamiento, vectorPuntaje[jug], puntajeParcial, vectorJugadores);
                        

                        locate(1, 13); cout << "Te pasaste "<< (puntajeParcial + puntajeTirada + vectorPuntaje[jug]) - 10000<<" puntos";
                        msleep(2000);      
                        puntajeParcial = 0;

                    }
                    else if(puntajeTirada==0) {
                        puntajeParcial = 0;
                        interfaz(jug, rondas, lanzamiento, vectorPuntaje[jug], puntajeParcial, vectorJugadores);
                        lanzamiento = 0;

                        msleep(2000);
                        
                    }                                                           
                }
                if (seguirHaciendoTiradas){ 
                    
                    seguirHaciendoTiradas =seguirTirando(vectorPuntaje, jug, puntajeParcial);

                }
                
                
                

                puntajeTirada = 0;
                lanzamiento++;
            } 
            cls();
            mostrarMarcoPuntuaciones(rondas,jug, vectorJugadores, vectorPuntaje, cantJugadores);
            msleep(4000);
        }       
        if (vectorPuntaje[0] == 10000&& vectorPuntaje[1] == 10000) {
            cls();
            pantallaEmpate(rondas);
            break;
        }
        else if (vectorPuntaje[0]==10000) {
            cls();
            ganoAlguien = pantallaGanadora(rondas,0,vectorJugadores);
            break;

        }
        else if (vectorPuntaje[1] == 10000) {
            cls();
            ganoAlguien = pantallaGanadora(rondas, 1, vectorJugadores);
            break;
        }
    }




    if (!ganoAlguien) {
        if(vectorPuntaje[0] == vectorPuntaje[1]) {
            cls();
            pantallaEmpate(10);

        }
        else if (vectorPuntaje[0] > vectorPuntaje[1]) {
            cls();
            pantallaGanadora(10,0, vectorJugadores);
        }
        else {
            cls();
            pantallaGanadora(10, 1, vectorJugadores);
        }
    }
    msleep(1000);
}

//--------------------------------------------------------------------
//----------------------------MAIN------------------------------------
//--------------------------------------------------------------------
int main() {
    //-------VECTORES INT
    int vectorTirada[6], vectorPuntaje[2] = { 0,0 };

    //-------VECTORES STRING
    string vectorJugadores[2] = { "Jugador1","Jugador2" };
    
    
    pantallaInicio();
    anykey();
    cls();
    Juego(opcionesJuego(vectorJugadores), vectorTirada, vectorPuntaje, vectorJugadores);
   

    
  
    
    cout << endl;
    system("pause");
	return 0;
}