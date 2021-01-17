#pragma once
#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

/*
CLASS NODE
* Classe bàsica per a gestionar les classes CUA i PILA
* Conté un punter al següent node de tipus Template i una variable tipus Template que guarda un valor
* Conté mètodes per obtenir i col·locar un Node i mètodes per col·locar un valor 
*/

template <class T>
class Node
{
public:
	Node() : m_valor(T()), m_next(NULL) {};
	~Node() { m_next = NULL; };
	Node(const T &valor) : m_valor(valor), m_next(NULL) {}
	Node<T> *getNext() { return m_next; }
	void setNext(Node<T> *next) { m_next = next; }
	T& getValor() { return m_valor; }
	void setValor(const T &valor) { m_valor = valor; }
private:
	T m_valor;
	Node<T> *m_next;
};

#endif // NODE_H