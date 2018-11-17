/*single seat in a room, can be reserved (m_is_free) as well*/
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class seat : 
	public sf::Drawable, public sf::Transformable //
{
private:
	bool m_is_free;
	bool m_is_selected;
	int m_row;
	int m_nr;
	sf::RectangleShape m_seat_shape;
	sf::Font font;
	sf::Text text;
	virtual void draw(RenderTarget& target, RenderStates states) const override;
public:
	seat();
	void show_nr();
	Vector2f getSize();
	FloatRect getGlobalBounds();
	void set_seat_nr(int Row, int Seat_nr);
	void set_position(float position_x, float position_y);
	char get_info() const;
	bool is_selected() const;
	seat* book_seat_v();
	void select_seat();
	void unselect_seat();
	void book_seat();
	void unbook_seat();
	~seat();
};

