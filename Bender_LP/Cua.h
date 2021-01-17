#pragma once

#include "Node.h"
#include "Contenidor.h"

/*
* CLASS CUA
* Classe estàndard CUA que hereda a la classe CONTENIDOR.
* Conté un punter a un Node de tipus Template (Node<t>* m_últim). Aquest node farà referència a l'ultim element de la cua.
* Conté els métodes bàsics per a garantir el funcionament eficient d'una PILA.

*/

template <class T>
class Cua : public Contenidor<T>
{
public:
	Cua() { m_ultim = NULL; } 
	~Cua() {} 

	void afegeix(T& valor); 
	void treu();
	T &getPrimer() const { return this->m_primer->getValor(); }   
	T &getUltim() const { return m_ultim->getValor(); }   
	
private:
	Node<T>* m_ultim;

};

template<class T>
inline void Cua<T>::afegeix(T & valor)
{
		Node<T>* aux;

		aux = new Node<T>;
		aux->setValor(valor);
		aux->setNext(NULL);

		if (this->esBuida())
		{

			this->m_primer = aux;
			m_ultim = aux;

		}
		else
		{
			m_ultim->setNext(aux);
			m_ultim = aux;

		}

}

template<class T>
inline void Cua<T>::treu()
{
	this->eliminaNext(NULL);
	if (this->m_primer == NULL)
		m_ultim = NULL;
}
