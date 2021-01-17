#pragma once 

#include "Definitions.h"

#ifdef GRAPHICS
#include "lib/libreria.h"
#endif 

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
//#include <tchar.h>
#include "Robot.h"
using namespace std;

/**
* CLASS LABERINT
* Classe que permet guardar els Sprites utilitzats per a la creaci� de laberint, aix� com el tamany del gr�fic i la matriu din�mica.
* Les dades que cont� s�n: 3 Sprites, 2 int per gestionar tamany del gr�fic i un doble punter a int per a la creaci� del laberint. 
* Cont� m�todes per accedir i modificar les dades, un m�tode per dibuixar els Sprites, un m�tode per inicialitzar el joc correctament i
un m�tode que serveix per llegir el fitxer d'entrada
*/


class Laberint
{
public:

	Laberint();
	~Laberint();
	int getTamanyX() const;
	void setTamanyX(int &x);
	int getTamanyY() const;
	void setTamanyY(int &y);

	void init();


	void dibuixa();

	bool initJoc(string fichero, Robot* bender);
	void initMatriu(int midaY, int midaX);

	int** getPunter() const;

private:

#ifdef GRAPHICS
	Sprite m_cnegre;
	Sprite m_cblanc;
	Sprite m_beer;
	Sprite m_clau;
	Sprite m_porta;
#endif
	int m_tamanyX;
	int m_tamanyY;
	int** m_mur;
};
