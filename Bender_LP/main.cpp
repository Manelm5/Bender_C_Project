#pragma once

#include "Definitions.h"

//===========================TEMA GR�FICS===========================
#ifdef GRAPHICS

#define SDL_MAIN_HANDLED
#include "lib\libreria.h"
#include <windows.h>

#endif
//========================================================================

#include "Laberint.h"
#include "Robot.h"
#include "Clauer.h"
#include <iostream>
using namespace std;

//Mida	de	la	pantalla
const int MIDA_TOTAL = 480;

//Declaraci� del codi en soft-code amb argc i argv[]
int main(int argc, char* argv[])
{
	//Control d'excepci� en el qual comprovem que els par�metres que es passin pel main siguin exactament 2.

	if (argc != 7)
	{
		cout << "ERROR: Numero de argumentos incorrectos. Se esperaban 6" << endl;
			return -1;
	}

	string aux = argv[0]; //Ejecutable per defecte
	string mapa = argv[1]; 
	string recorregut = argv[2];
	string fitxercontingutInicialClauer = argv[3];
	string fitxercontingutFinalClauer = argv[4];
	string fitxerCuaClaus = argv[5];
	string fitxerCuaPortes = argv[6];


#ifdef GRAPHICS

	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);
	// Declaraci� de l�objecte de la classe Game canviant el tamany per defecte de la pantalla
	Game joc;
#endif
	
	//Declaraci� dels objectes de les classes que ser�n utilitzades en el joc
	Laberint laberint;
	Robot bender;
	Clauer clauer(fitxercontingutInicialClauer);
	//Inicialitzaci� de les cues Clau i Porta
	clauer.lleguirClaus(fitxerCuaClaus);
	clauer.lleguirPortes(fitxerCuaPortes);
	
#ifdef GRAPHICS	
	// Inicialitzaci� de l�entorn gr�fic. S�ha de cridar abans de declarar o 
	// utilitzar qualsevol altre element de la llibreria
	joc.Init();
	// Inicialitzaci� de la variable laberint 
	laberint.init();
	// Inicialitz,aci� de la variable bender
	bender.init();
#endif

	//Inicialitzaci� del laberint amb la lectura del fitxer i comprovaci� d'excepci�
	if (laberint.initJoc(mapa, &bender) == false)
	{
		return -1;
	}
	else
	{
#ifdef GRAPHICS	

		//Mostra pantalla gr�fica
		joc.Video_ShowWindow();

#endif	
		//Bucle principal del Laberint que funciona quan Bender es pugui moure
		do {

#ifdef GRAPHICS
			
			//M�todes que s'encarreguen de dibuixar Bender i Laberint	
			laberint.dibuixa();
			bender.dibuixa();

			//Actualitzaci� de la pantalla	
			joc.VideoUpdate();
			Sleep(500);
#endif
			

		} while (bender.mouRobot(laberint.getPunter(),laberint.getTamanyX(),laberint.getTamanyY(),&clauer));

		//M�tode encarregat d'efectuar l'escriptura al fitxer de sortida
		bender.escriptura(recorregut);
		clauer.escriureFitxer(fitxercontingutFinalClauer);

#ifdef GRAPHICS	
		//Destrueix	la pantalla tancant els grafics degudament
		joc.~Game();
#endif
	}

return 0;

}
