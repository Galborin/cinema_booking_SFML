/*single seat in a room, can be reserved (m_is_free) as well*/
#pragma once
#include <iostream>
#include "OnScreen.h"
using namespace sf;
using namespace std;
class seat : 
	public OnScreen
{
private:
	bool m_is_free;
	bool m_is_selected;
	int m_row;
	int m_nr;
public:
	seat();
	void show_nr() const;
	Vector2i get_number() const;
	void set_seat_nr(int Row, int Seat_nr);
	void set_position(float position_x, float position_y);
	bool is_free() const;
	bool is_selected() const;
	void select_seat();
	void unselect_seat();
	void book_seat();
	void unbook_seat();
	~seat();
};

