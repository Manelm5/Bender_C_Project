#ifndef PUNT_H
#define PUNT_H

#include <iostream>
using namespace std;

/*



*/

class Punt
{
    public:
		Punt() {};
		~Punt() {};
        Punt(int x, int y): m_x(x), m_y(y) {};
		Punt(const Punt& pt) 
		{
			m_x = pt.m_x;
			m_y = pt.m_y;
		};

        int getX() const { return m_x; }
        void setX(const int x) { m_x = x; }
        int getY() const { return m_y; }
        void setY(const int y) { m_y = y; }
    private:
        int m_x;
        int m_y;
};

#endif // PUNT_H
