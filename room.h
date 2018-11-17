/*cinema room*/

#pragma once
#include "seat.h"
#include"IDentity.h"
#include <iostream>
#include <string>
#include<vector>
using namespace sf;
class room :
	public IDentity, public Drawable  
{
private:
	virtual void draw(RenderTarget &target, RenderStates states) const override;
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
	seat * get_selected() const;
	static room * return_room(long int id);
	seat * get_seat(int row, int seat_nr) const;
	void show() const;
	void update(sf::RenderWindow & app) const;
	~room();
};

