#include "pch.h"
#include "seat.h"

void seat::draw(RenderTarget & target, RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_seat_shape, states);
	target.draw(text, states);
}

seat::seat() : m_is_free(true), m_is_selected(false),m_nr(255),m_row(255)
{
	m_seat_shape.setSize(sf::Vector2f(60, 60));
	m_seat_shape.setFillColor(sf::Color::Green);
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(16);
	text.setFillColor(sf::Color::Black);
}

void seat::show_nr()
{
	std::cout <<"Seat number "<< m_row << "  " << m_nr << "\n";
}

Vector2f seat::getSize()
{
	return m_seat_shape.getSize();
}

FloatRect seat::getGlobalBounds()
{
	return m_seat_shape.getGlobalBounds();
}

void seat::set_seat_nr(int Row,int Seat_nr)
{
	m_row = Row;
	m_nr = Seat_nr;
	text.setString(std::to_string(m_nr));
}

void seat::set_position(float position_x, float position_y)
{
	m_seat_shape.setPosition(position_x, position_y);
	text.setPosition(position_x+10, position_y+10);
}

char seat::get_info() const
{
	if (m_is_free == true)
		return('F');
	else
		return('R');
}

bool seat::is_selected() const
{
	if (m_is_selected == true)
		return true;
	else
		return false;
}

seat* seat::book_seat_v()
{
	m_is_free = false;
	m_seat_shape.setFillColor(sf::Color::Red);
	return this;
}

void seat::select_seat()
{
	m_is_selected = true;
	m_seat_shape.setFillColor(sf::Color::Magenta);
}

void seat::unselect_seat()
{
	m_is_selected = false;
	m_seat_shape.setFillColor(sf::Color::Green);
}

void seat::book_seat()
{
	m_is_free = false;
	m_seat_shape.setFillColor(sf::Color::Red);
}

void seat::unbook_seat()
{
	m_is_free = true;
	m_seat_shape.setFillColor(sf::Color::Green);
}


seat::~seat()
{
}
