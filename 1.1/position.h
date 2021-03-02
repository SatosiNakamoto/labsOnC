#ifndef _POS_
#define _POS_

// храним позицию, как координату на плоскости 8х8. Потом можно прсто добавить методы, которые будут смотреть какого цвета клетка, какое число, какая буква, какая фигура etc

class position
{
public:
	//можно добавить метод проверки того, что x и y внутри доски
	position(int x, int y) : m_x(x), m_y(y) {}

	int get_x(){ return m_x; }
	int get_y(){ return m_y; }

	void set_x(int x_in){ m_x = x_in; }
	void set_y(int y_in){ m_y = y_in; }
	
private:
	int m_x;
	int m_y;	
};

#endif
