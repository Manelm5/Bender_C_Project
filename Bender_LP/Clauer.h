#pragma once

#include "Tree.hpp"
#include "Clau.h"
#include "stdio.h"
#include <stdlib.h>
#include "Cua.h"

using namespace std;



/*

*CLASS CLAUER
* Classe encarregada de gestionar el clauer, així com les cues de portes i les cues de claus
* Entre els seus atributs hi trobem un BBTree<Clau> que funciona com a clauer i les dues cues de portes i claus
* Conté métodes per a modificar i obtenir els atributs de la classe, funcions que llegeixen tots els arxius per a emplenar cues i l'arbre binari de cerca,
així com métodes que serveixen per a escriure en un fitxer el BBTree i métodes per agafar claus i treure portes. També disposem d'una funció que s'encarrega d'un bool per veure si podem
obrir una porta.

*/


class Clauer
{
public:

	Clauer() {}
	~Clauer() {}

	Clauer(const string& fitxerClauerEntrada)
	{
		m_clauer.read(fitxerClauerEntrada);
	}

	void afegirClau(Clau clau) 
	{
		m_clauer.insert(clau);
	}

	string obtenirContrasenya(int numeroPorta)
	{
		string ret = "NULL";
		Clau aux(numeroPorta, "NULL");
		BBTree<Clau> *auxT;
		if (auxT = m_clauer.cerca(aux)) 
		{
			ret = auxT->getData().getContrasenya();
		}
		return ret;
	}

	void escriureFitxer(const string& fitxerClauerSortida) 
	{
		int z = 0;

		ofstream fitxer;
		fitxer.open(fitxerClauerSortida);
		if (fitxer.is_open()) {
			if (!m_clauer.isEmpty())
			{
				int max = m_clauer.altura(&m_clauer);
				fitxer << max << endl;
				m_clauer.escriureFitxerRec(fitxer, &m_clauer, z, max);
			}
			else
			{
				fitxer << -1;
			}

			fitxer.close();
		}
		else {
			cout << "“ERROR: No s'ha pogut obrir l'arxiu" << fitxerClauerSortida << endl;
		}

	}

	void lleguirClaus(string& nomFitxer) 
	{
		ifstream fitxer;
		fitxer.open(nomFitxer);
		if (fitxer.is_open()) 
		{
			while (!fitxer.eof())
			{
				int naux;
				string taux;

				fitxer >> naux;
				fitxer >> taux;
				
				Clau c(naux, taux);
				m_Cuaclaus.afegeix(c);
			}

			fitxer.close();
		}
		else {
			
			cout << "“ERROR: No se pudo abrir el archivo " << nomFitxer << endl;
		}
	}


	void lleguirPortes(string & nomFitxer) 
	{
		ifstream fitxer;
		fitxer.open(nomFitxer);
		if (fitxer.is_open()) 
		{
			while (!fitxer.eof())
			{
				Clau p;
				fitxer >> p;
				m_Cuaportes.afegeix(p);
			}
			fitxer.close();
		}
		else 
		{
			cout << "“ERROR: No se pudo abrir el archivo " << nomFitxer << endl;
		}
	}


	bool canOpen()
	{
		bool open = false;
		if (!m_clauer.isEmpty() && !m_Cuaportes.esBuida())
		{
			Clau a = m_Cuaportes.getPrimer();
			if (obtenirContrasenya(a.getNumporta()) == a.getContrasenya()) 
			{
				open = true;
			}
		}
		return open;
	}


	void openDoor() 
	{
		if (!m_clauer.isEmpty() && !m_Cuaportes.esBuida())
		{
			Clau a = m_Cuaportes.getPrimer();
			if (obtenirContrasenya(a.getNumporta()) == a.getContrasenya())
			{
				m_Cuaportes.treu();
			}
		}
	}


	void treureporta()
	{
		if (!m_Cuaportes.esBuida() && !m_clauer.isEmpty())
		{
			m_Cuaportes.treu();
		}
	
	}


	void agafaClau() 
	{
		if (!m_Cuaclaus.esBuida())
		{
			Clau c = m_Cuaclaus.getPrimer();
			
			if (!m_clauer.cerca(c))
			{
				m_clauer.insert(c);
			}
			m_Cuaclaus.treu();
		}
	}


	void printArbre() 
	{
		m_clauer.print();
	}

private:
	
	BBTree<Clau> m_clauer;
	Cua<Clau> m_Cuaclaus;
	Cua<Clau> m_Cuaportes;

};