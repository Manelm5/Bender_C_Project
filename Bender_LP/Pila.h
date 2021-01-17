#pragma once

#include "Node.h"
#include "Contenidor.h"

/*
CLASS PILA
* Classe estàndard PILA que hereda a la classe CONTENIDOR
* No conté part privada i l'unic atribut Node<T> es troba a CONTENIDOR
* Conté els métodes bàsics per a garantir el funcionament eficient d'una PILA.
*/

template <class T>
class Pila : public Contenidor<T>
{
public:

	Pila() { };
	~Pila() { };
	void push(const T& valor) { this->insereixNext(valor, NULL); }
	void pop() { this->eliminaNext(NULL); }
	T top() { return this->m_primer->getValor(); }

};

