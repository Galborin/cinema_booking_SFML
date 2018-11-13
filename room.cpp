#include "pch.h"
#include "room.h"
#include "seat.h"



room::room(int rows_in_room, int seats_in_row, std::string name) : m_rows_in_room(rows_in_room), m_seats_in_row(seats_in_row), m_room_id(++room_id),IDentity(name)
{
	room_v.push_back(this);
	float seat_position_x, seat_position_y;
	m_pointer = new seat *[rows_in_room];
	for (int i = 0; i < rows_in_room; ++i) {
		m_pointer[i] = new seat[seats_in_row];
		for (int j = 0; j < seats_in_row; ++j) {
			m_pointer[i][j].set_seat_nr(i, j);
			seat_position_x = ((1024.0f - (m_seats_in_row * (m_pointer[i][j].get_shape()->getSize().x+1.0f))) / 2.0f) + (j*(m_pointer[i][j].get_shape()->getSize().x+1));
			seat_position_y = ((768.0f - (m_rows_in_room * (m_pointer[i][j].get_shape()->getSize().y+1.0f))) / 2.0f) +(i*(m_pointer[i][j].get_shape()->getSize().y+1 ));
			m_pointer[i][j].set_seat_position(seat_position_x, seat_position_y);
		}
	}
}

room::room() : m_seats_in_row(0),m_rows_in_room(0), m_room_id(++room_id),IDentity()
{
	room_v.push_back(this);
}

room::room(const room & Room) : m_rows_in_room(Room.m_rows_in_room), m_seats_in_row(Room.m_seats_in_row), m_pointer(new seat *[Room.m_rows_in_room]) //update!! name
{	
	for (int i = 0; i < Room.m_rows_in_room; ++i) {
		m_pointer[i] = new seat[Room.m_seats_in_row];
	}
}

void room::edit_room()
{
	bool bad_format;
	std::string tmp;
	do {
		bad_format = false;
		std::cout << "Set room name: ";
		getline(std::cin, tmp);
		m_name = tmp;
		std::cout << "Set number of rows: ";
		getline(std::cin, tmp);
		m_rows_in_room = std::stoi(tmp);
		std::cout << "Set number of seats in row: ";
		getline(std::cin, tmp);
		m_seats_in_row = std::stoi(tmp);
	} while (bad_format == true);
}

room * room::return_room(long int id)
{
	for (auto &&i : room_v) {
		if (i->m_room_id == id) {
			return i;
			break;
		}
	}
	return nullptr;
}

seat * room::get_seat(int row,int seat_nr)
{
	return &m_pointer[row][seat_nr];
}


void room::show() const
{
	std::cout << "Room " << m_name << std::endl;
	for (int i = m_rows_in_room - 1; i >= 0; --i) {
		for (int j = 0; j < m_seats_in_row; ++j) {
			std::cout << "[" << m_pointer[i][j].get_info() << "]";
		}
		std::cout << "  row " << i + 1 << std::endl;
	}
	for (int i = 1; i <= m_seats_in_row; i++) {
		std::cout << " " << i << ((i<9) ? " " : "");
	}
	std::cout << std::endl;
}

void room::draw_seats(sf::RenderWindow &app)
{
	for (int i = 0; i < m_rows_in_room; ++i) {
		for (int j = 0; j < m_seats_in_row; ++j) {
			app.draw(*m_pointer[i][j].get_shape());
			app.draw(*m_pointer[i][j].get_text());
		}
	}
}




void room::update(sf::RenderWindow & app) {
	for (int i = 0; i < m_rows_in_room; ++i) {
		for (int j = 0; j < m_seats_in_row; ++j) {
			if (m_pointer[i][j].get_shape()->getGlobalBounds().contains(app.mapPixelToCoords(sf::Mouse::getPosition(app))))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				{
					if (m_pointer[i][j].get_info() == 'F') {
						m_pointer[i][j].book_seat();
						show();
						while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {};
					}
					else {
						m_pointer[i][j].unbook_seat();
						show();
						while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {};
					}
				}
			}
		}
	}
}


room::~room()
{
	for (unsigned int i = 0; i < room_v.size(); ++i)
	{
		if (room_v[i] == this){
			room_v.erase(room_v.begin() + i);
			break;
		}
	}

	for (int i = 0; i < m_rows_in_room; ++i) {
		delete [] m_pointer[i];
	}
	delete [] m_pointer;
}


