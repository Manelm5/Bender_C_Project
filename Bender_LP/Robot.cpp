
#include "Robot.h"
#include "Cua.h"
#include "Punt.h"
#include "fstream"





Robot::Robot()
{
	//Inicalització de les variables estàtiques a 0.
	m_robotX = 0; 
	m_robotY = 0;
	m_anteriorX = 0; 
	m_anteriorY = 0;
	m_contCervesa = 0;
	
}

Robot::~Robot()
{
	//Destructor per defecte
}

void Robot::init()
{
#ifdef GRAPHICS
	
	//Inicialització de l'Sprite Robot
	m_robot.Create("data/bender.png");

#endif

}

void Robot::setX(int &x)
{
	m_robotX= x;
}

void Robot::setY(int &y)
{
	m_robotY = y;
}

int Robot::getX() const
{
	return m_robotX;
}

int Robot::getY() const
{
	return m_robotY;
}

void Robot::dibuixa()
{

#ifdef GRAPHICS
	//Métode que dibuixa l'Sprite en el lloc indicat
	m_robot.Draw(m_robotY*m_robot.getScaleY(), m_robotX*m_robot.getScaleX());
#endif
}


void Robot::updateAnterior(int x, int y)
{
	//Actualització de la posició anterior per a controlar els marges a la funció mouRobot
	m_anteriorX = x;
	m_anteriorY = y;
}



bool Robot::mouRobot(int** matriu, int x, int y, Clauer* clauer)
{
	Punt aux;
	//Métode que comprova si Bender està sobre una cervesa, porta o clau
	comprovaCervesa(matriu);
	comprovaClau(matriu, clauer);
	comprovaPorta(matriu, clauer);
	//Aquests métodes guarden una informació d'un punt i el col·loquen dins d'una cua
	aux.setX(m_robotX);
	aux.setY(m_robotY);
	m_cua.afegeix(aux);
	
	//Bucle d'if anidats que s'encarreguen de gestionar el moviment de Bender
	if ((m_robotY != 0) && (m_robotY - 1 != m_anteriorY) && (matriu[m_robotX][m_robotY - 1] > 0) && (matriu[m_robotX][m_robotY - 1] < 5) && (matriu[m_robotX][m_robotY]!=6))
	{
		//izquierda
		updateAnterior(m_robotX, m_robotY);
		m_pila.push(aux);
		m_robotY--;
		
		matriu[m_anteriorX][m_anteriorY] = 5;

		return true;
	}
	else {
		if ((m_robotX != 0) && (matriu[m_robotX - 1][m_robotY] > 0) && (matriu[m_robotX - 1][m_robotY]) < 5 && (matriu[m_robotX][m_robotY] != 6))
		{
			//arriba
			updateAnterior(m_robotX, m_robotY);
			m_pila.push(aux);
			m_robotX--;
			matriu[m_anteriorX][m_anteriorY] = 5;
			

			return true;
		}
		else {
			if ((m_robotY != y - 1) && (matriu[m_robotX][m_robotY + 1] > 0) && (matriu[m_robotX][m_robotY + 1]) < 5 && (matriu[m_robotX][m_robotY] != 6))
			{
				//derecha
				updateAnterior(m_robotX, m_robotY);
				m_pila.push(aux);
				m_robotY++;
				matriu[m_anteriorX][m_anteriorY] = 5;
				
				return true;
			}
			else {
				if ((m_robotX != x - 1) && ((matriu[m_robotX + 1][m_robotY] > 0)) && ((matriu[m_robotX + 1][m_robotY])) < 5 && (matriu[m_robotX][m_robotY] != 6))
				{
					//abajo
					updateAnterior(m_robotX, m_robotY);
					m_pila.push(aux);
					m_robotX++;
					matriu[m_anteriorX][m_anteriorY] = 5;
					
					return true;
				}
				else {
					if (!m_pila.esBuida()) {
						
						updateAnterior(m_robotX, m_robotY);
						if (matriu[m_anteriorX][m_anteriorY] == 6)
						{
							matriu[m_anteriorX][m_anteriorY] = 6;
						}
						else {
							matriu[m_anteriorX][m_anteriorY] = 5;
						}
						
						m_robotX = m_pila.top().getX();
						m_robotY = m_pila.top().getY();	
						m_pila.pop();
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Robot::comprovaCervesa(int** matriu)
{
	//Si la posició és igual a 2 (Cervesa), es suma 1 al comptador i la casella es transforma en un 1 (buida)
	if (matriu[m_robotX][m_robotY] == 2)
	{
		m_contCervesa++;
		matriu[m_robotX][m_robotY] = 1;
	}
}

void Robot::comprovaPorta(int** matriu, Clauer* clauer)
{
	if (matriu[m_robotX][m_robotY] == 3)
	{
		if (clauer->canOpen())
		{
			clauer->openDoor();
			matriu[m_robotX][m_robotY] = 1;
		}
		else 
		{
			
			matriu[m_robotX][m_robotY] = 6;
			clauer->treureporta();
		}
	}
	
}

void Robot::comprovaClau(int** matriu, Clauer* clauer)
{
	if (matriu[m_robotX][m_robotY] == 4)
	{
		clauer->agafaClau();
		matriu[m_robotX][m_robotY] = 1;
	}
}

void Robot::escriptura(string fichero)
{
	/*
	Aquest métode va obtenint elprimer element de la cua, l'escriu al fitxer de sortida i seguidament l'elimina.
	Això es va repetint en forma de bucle per a escriure tota la cua en el fitxer de sortida
	*/
	ofstream fitxer;

	fitxer.open(fichero);
	
	if (fitxer.is_open()) {
		
		fitxer << m_contCervesa << endl;

		while (!m_cua.esBuida()) {
			fitxer << m_cua.getPrimer().getX() << " " << m_cua.getPrimer().getY() << endl;
			m_cua.treu();
	}
	
	}
	fitxer.close();
}