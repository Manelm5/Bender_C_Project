#include "Llista.h"
#include "Node.h"



//PASARLO A HERÉNCIA (CREAR CLASSE CONTENIDOR)

template <class T>
Llista<T>::Llista()
{
	//ctor
	m_primer = NULL;
}

template <class T>
Llista<T>::~Llista()
{
	while (m_primer != NULL)
		eliminaNext(NULL);
}

template <class T>
bool Llista<T>::esBuida() const
{
	return (m_primer == NULL);
}

template <class T>
Node<T>* Llista<T>::getInici() const
{
	return m_primer;
}

template <class T>
Node<T>* Llista<T>::insereixNext( const T& valor, Node<T> *posicio)
{
	Node<T>* aux = new Node<T>();
	if (aux != NULL)
	{
		aux->setValor(valor);
		if (posicio == NULL)
		{
			aux->setNext(m_primer);
			m_primer = aux;
		}
		else
		{
			aux->setNext(posicio->getNext());
			posicio->setNext(aux);
		}
	}
	return aux;
}

template <class T>
Node<T>* Llista<T>::eliminaNext(Node<T>* posicio)
{
	Node<T>* aux;
	Node<T>* seguent = NULL;
	if (posicio == NULL)
	{
		aux = m_primer;
		m_primer = aux->getNext();
		delete aux;
		seguent = m_primer;
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

