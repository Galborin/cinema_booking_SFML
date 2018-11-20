#include "pch.h"
#include "seat.h"


seat::seat() : m_is_free(true), m_is_selected(false),m_nr(0),m_row(0),OnScreen(60.f,60.f)
{
	m_rectangleshape.setFillColor(sf::Color::Green);
	text.setCharacterSize(16);
}

void seat::show_nr() const
{
	std::cout <<"Seat number "<< m_row << "  " << m_nr << "\n";
}

Vector2i seat::get_number() const
{
	return Vector2i(m_row, m_nr);
}

void seat::set_seat_nr(int Row,int Seat_nr)
{
	m_row = Row;
	m_nr = Seat_nr;
	text.setString(std::to_string(m_nr));
}

void seat::set_position(float position_x, float position_y)
{
	m_rectangleshape.setPosition(position_x, position_y);
	text.setPosition(position_x+10, position_y+10);
}

bool seat::is_free() const
{
	return m_is_free;
}

bool seat::is_selected() const
{
	return m_is_selected;
}

void seat::select_seat()
{
	m_is_selected = true;
	m_rectangleshape.setFillColor(sf::Color::Magenta);
}

void seat::unselect_seat()
{
	m_is_selected = false;
	m_rectangleshape.setFillColor(sf::Color::Green);
}

void seat::book_seat()
{
	m_is_free = false;
	m_rectangleshape.setFillColor(sf::Color::Red);
}

void seat::unbook_seat()
{
	m_is_free = true;
	m_rectangleshape.setFillColor(sf::Color::Green);
}


seat::~seat()
{
}
