#pragma once

#ifndef LLISTA_H
#define LLISTA_H

#include "Node.h"
#include  <iostream>


//PASARLO A HERÉNCIA (CREAR CLASSE CONTENIDOR)


using namespace std;
template <class T>
class Llista
{
public:
	Llista();
	~Llista();
	bool esBuida() const;
	Node<T> *getInici() const;
	Node<T> *insereixNext(const T& valor, Node<T> *posicio);
	Node<T> *eliminaNext(Node<T>* posicio);
private:
	Node<T>* m_primer;
};

#endif // LLISTA_H



