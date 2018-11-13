/*single seat in a room, can be reserved (m_is_free) as well*/
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class seat // todo : Drawable
{
private:
	bool m_is_free;
	int m_row;
	int m_nr;
	sf::RectangleShape m_seat_shape;
	sf::Font font;
	sf::Text text;
public:
	seat();
	void show_nr();
	void set_seat_nr(int Row, int Seat_nr);
	void seat_initialize();
	void set_seat_position(float position_x, float position_y);
	char get_info();
	sf::RectangleShape * get_shape();
	sf::Text * get_text();
	seat* book_seat_v();
	void book_seat();
	void unbook_seat();
	~seat();
};

