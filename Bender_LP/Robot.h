#pragma once

#include "Definitions.h"

#ifdef GRAPHICS
#include "lib/libreria.h"
#endif

#include "string"
#include "string.h"
#include "Cua.h"
#include "Pila.h"
#include "Clauer.h"
#include <iostream>

using namespace std;

/*
*CLASS ROBOT
* Classe encarregada de gestionar tot el funcionament i la inteligéncia del Robot a través del laberint
* Entre els seus atributs hi trobem int m_robotX, m_robotY (encarregats de tenir la informació de la posició de Bender),
m_anteriorX, m_anteriorY(que s'encarreguen de guardar la informació de l'última posició efectuada per el Bender, 
Cua<Punt> m_cua (una cua que s'encarrega de guardar totes les posicions visitades, m_bifur[4] (array d'enters que serveix per
a guardar i gestionar bifurcacions), l'Sprite de Bender i finalment, int m_contCervesa (Atribut que guarda les cerveses begudes per Bender.
* Conté métodes per a modificar i obtenir els atributs de la classe, un métode per escriure, métodes per a comrpovar les bifurcacions del 
laberint i métodes per a garantir el moviment eficient del robot.

*/

class Robot
{
	public:

		Robot();
		~Robot();

		void init();

		void setX(int &x);
		void setY(int &y);
		int getX() const;
		int getY() const;
		
		void dibuixa();
		void updateAnterior(int x, int y);
		bool mouRobot(int** matriu, int x, int y, Clauer* clauer);
		void comprovaCervesa(int** matriu);
		void comprovaPorta(int** matriu, Clauer* clauer);
		void comprovaClau(int** matriu, Clauer* clauer);
		void escriptura(string fichero);
	

	private:

		int m_robotX, m_robotY;
		int m_anteriorX, m_anteriorY;
		Cua<Punt> m_cua;
		Pila<Punt> m_pila;
		int m_bifur[4];
#ifdef GRAPHICS
		Sprite m_robot;
#endif
		int m_contCervesa;
};

