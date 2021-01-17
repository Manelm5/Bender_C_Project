#pragma once

#include "Node.h"
#include "Punt.h"

/*
* CLASS CONTENIDOR
* Classe que serà heredada i utilitzada per Cua i Pila
* Conté un punter a un Node Template el qual funcionarà com el primer element
* Conté mètodes per afegir i treure Nodes, un reton del Node inici, i un bool que comprova que no estigui buit
*/

template <class T>
class Contenidor
{
public:
	Contenidor() { this->m_primer = NULL; }; 
	~Contenidor() {}; 
	bool esBuida() const { return (this->m_primer == NULL); }

protected:
	Node<T> *getInici() const { return this->m_primer; }; 
	Node<T> *insereixNext(const T& valor, Node<T> *posicio); 
	Node<T> *eliminaNext(Node<T> *posicio); 
	Node<T> *m_primer; 
};



template<class T>
inline Node<T>* Contenidor<T>::insereixNext(const T & valor, Node<T>* posicio)
{
	Node<T>* aux = new Node<T>;
	if (aux != NULL)
	{
		aux->setValor(valor);
		if (posicio == NULL)
		{
			aux->setNext(this->m_primer);
			this->m_primer = aux;
		}
		else
		{
			aux->setNext(posicio->getNext());
			posicio->setNext(aux);
		}
	}
	return aux;
}


template<class T>
inline Node<T>* Contenidor<T>::eliminaNext(Node<T>* posicio)
{
	Node<T>* aux;
	Node<T> *seguent = NULL;
	if (posicio == NULL)
	{
		aux = this->m_primer;
		this->m_primer = aux->getNext();
		delete aux;
		seguent = this->m_primer;
	}
	else
	{
		aux = posicio->getNext();
		if (aux != NULL)
		{
			posicio->setNext(aux->getNext());
			seguent = aux->getNext();
			delete aux;
		}
	}
	return seguent;
}



