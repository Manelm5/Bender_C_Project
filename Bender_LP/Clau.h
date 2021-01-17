#pragma once
#include <iostream>
#include <string>
using namespace std;



/*
*CLASS CLAU
* Classe encarregada de gestionar tot els métodes bàsics per gestionar la clau.
* Entre els seus atributs hi trobem un string per la contrasenya i un int per el número de la porta.
* Conté métodes per a modificar i obtenir els atributs de la classe i els operadors modificats per a utilitzar-los en la clases

*/



class Clau
{
public:
	Clau()
	{
		m_contrasenya = "NULL";
		m_numPorta = 0;
	}
	Clau(int n, string c) 
	{
		m_contrasenya = c;
		m_numPorta = n;
	}

	~Clau() {}
	void setContra(string c) { m_contrasenya = c; }
	void setNum(int n) { m_numPorta = n; }
	string getContrasenya() { return m_contrasenya; }
	int getNumporta() { return m_numPorta; }
	
	bool operator !=(const Clau aux) { return (m_numPorta == aux.m_numPorta); }
	bool operator ==(const Clau aux) { return (m_numPorta == aux.m_numPorta); }
	bool operator >(const Clau aux) { return (m_numPorta > aux.m_numPorta); }
	bool operator <(const Clau aux) { return (m_numPorta < aux.m_numPorta); }
	bool operator >=(const Clau aux) { return (m_numPorta >= aux.m_numPorta); }
	bool operator <=(const Clau aux) { return (m_numPorta <= aux.m_numPorta); }
	
	
	friend std::ostream& operator<<(std::ostream& out, const Clau& c)
	{
		out << c.m_numPorta << " " << c.m_contrasenya << endl;
		return out;
	}
	
	friend istream& operator >> (istream& is, Clau& c)
	{
		is >> c.m_numPorta >> c.m_contrasenya;
		return is;

	}
	
	Clau& operator=(const Clau& other)
	{
		if (this != &other) {
			this->m_contrasenya = other.m_contrasenya;
			this->m_numPorta = other.m_numPorta;
		}
		return *this;
	}

private:

	string m_contrasenya;
	int m_numPorta;

};