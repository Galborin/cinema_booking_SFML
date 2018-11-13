/*cinema room*/

#pragma once
#include "seat.h"
#include"IDentity.h"
#include <iostream>
#include <string>
#include<vector>
class room :
	public IDentity
{
private:
	int m_rows_in_room;
	int m_seats_in_row;
	seat **m_pointer;
	long int m_room_id;
public:
	long static int room_id;
	static std::vector<room*>room_v;
	room(int rows_number, int seats_in_row, std::string name);
	room();
	room(const room &Room);
	void edit_room();
	static room * return_room(long int id);
	seat * get_seat(int row, int seat_nr);
	void show() const;
	void draw_seats(sf::RenderWindow &app);
	void update(sf::RenderWindow & app);
	~room();
};

