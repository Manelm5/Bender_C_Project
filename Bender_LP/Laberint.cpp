
#include <string.h>
#include "Laberint.h"
#include "Robot.h"
#include "fstream"
#include <iostream>
#include <string>


using namespace std;

const int MIDA_BLOC = 60;


Laberint::Laberint()
{
	//Inicalització de les variables estàtiques a 0.

	int m_tamanyX = 0;
	int m_tamanyY = 0;
	
}


Laberint::~Laberint()
{
	//Destructor per defecte
}


void Laberint::init()
{

#ifdef GRAPHICS

	//Creació dels sprites utilitzats a aquesta classe

	m_cnegre.Create("data/cnegre.png");
	m_cblanc.Create("data/cblanc.png");
	m_beer.Create("data/beer.png");
	m_clau.Create("data/clau.png");
	m_porta.Create("data/porta.png");

#endif
}


int Laberint::getTamanyX() const
{
	return m_tamanyX;
}


void Laberint::setTamanyX(int &x)
{
	m_tamanyY = x;
}


int Laberint::getTamanyY() const
{
	return m_tamanyY;
}


void Laberint::setTamanyY(int &y)
{
	m_tamanyY = y;
}

int** Laberint::getPunter() const
{
	return m_mur;
}


void Laberint::dibuixa()
{
	//Métode que s'encarrega de dibuixar l'Sprite en funció de si tenim un 0, 1 o 2


	for (int i = 0; i < m_tamanyX; i++)
	{
		for (int j = 0; j < m_tamanyY; j++)
		{
			if (m_mur[j][i] == 0) {
#ifdef GRAPHICS
				m_cnegre.Draw(i*MIDA_BLOC, j*MIDA_BLOC);
#endif
			}
			if (m_mur[j][i] == 1) {
#ifdef GRAPHICS
				m_cblanc.Draw(i * MIDA_BLOC, j * MIDA_BLOC);
#endif
			}
			if (m_mur[j][i] == 2) {
#ifdef GRAPHICS
				m_beer.Draw(i * MIDA_BLOC, j * MIDA_BLOC);
#endif
			}
			if (m_mur[j][i] == 3) {
#ifdef GRAPHICS
				m_porta.Draw(i * MIDA_BLOC, j * MIDA_BLOC);
#endif
			}
			if (m_mur[j][i] == 4) {
#ifdef GRAPHICS
				m_clau.Draw(i * MIDA_BLOC, j * MIDA_BLOC);
#endif
			}
			if (m_mur[j][i] == 5) {
#ifdef GRAPHICS
				m_cblanc.Draw(i * MIDA_BLOC, j * MIDA_BLOC);
#endif
			}
			if (m_mur[j][i] == 6) {
#ifdef GRAPHICS
				m_porta.Draw(i * MIDA_BLOC, j * MIDA_BLOC);
#endif
			}

		}
	}
}



bool Laberint::initJoc(string fichero, Robot* bender)
{
	bool correcte = false;

	int robotY, robotX;

	ifstream fitxer;

	fitxer.open(fichero);

	if (fitxer.is_open())
	{
		fitxer >> robotX >> robotY;
		
		//Inicialització de la posició inicial de Robot
		bender->setX(robotX);
		bender->setY(robotY);

		fitxer >> m_tamanyY >> m_tamanyX;


		//Inicialitazció de la matriu amb els valors Y i X agafats del fitxer els quals determinen la dimensió
		initMatriu(m_tamanyY, m_tamanyX);

		while (!fitxer.eof())
		{
			//For anidat que s'encarrega d'omplir la matriu dinàmica amb els valors llegits al fitxer
			for (int i = 0; i< m_tamanyY; i++)
			{
				for (int j = 0; j < m_tamanyX; j++)
				{
					fitxer >> m_mur[i][j];
				}
			}

		}

		fitxer.close();
		correcte = true;

	}
	else 
	{
		//Control d'excepció en cas de que no es pugui obrir l'arxiu
		cout << "ERROR: No se pudo abrir el archivo" << " " << fichero << endl;
		correcte = false;
	}

	return correcte;
}

void Laberint::initMatriu(int midaY, int midaX)
{
	//Inicialització de la matriu dinàmica
	m_mur = NULL;
	m_mur = new int*[midaY];

	for (int i = 0; i < midaY; i++)
	{
		m_mur[i] = new int[midaX];
	}
}


