#include "pch.h"
#include "seat.h"

seat::seat() : m_is_free(true),m_nr(255),m_row(255)
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

void seat::set_seat_nr(int Row,int Seat_nr)
{
	m_row = Row;
	m_nr = Seat_nr;
	text.setString(std::to_string(m_nr));
}

void seat::seat_initialize()
{
	m_seat_shape.setSize(sf::Vector2f(80, 80));
	if(m_is_free == true)
		m_seat_shape.setFillColor(sf::Color::Green);
	else
		m_seat_shape.setFillColor(sf::Color::Red);
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(26);
	text.setFillColor(sf::Color::Black);
}

void seat::set_seat_position(float position_x, float position_y)
{
	//std::cout << position_x << " " << position_y << "\n"; //display position
	m_seat_shape.setPosition(position_x, position_y);
	text.setPosition(position_x+10, position_y+10);
}

char seat::get_info() {
	if (m_is_free == true)
		return('F');
	else
		return('R');
}

sf::RectangleShape * seat::get_shape()
{
	return &m_seat_shape;
}

sf::Text * seat::get_text()
{
	return &text;
}

seat* seat::book_seat_v()
{
	m_is_free = false;
	m_seat_shape.setFillColor(sf::Color::Red);
	return this;
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
