/*cinema room*/

#pragma once
#include "seat.h"
#include"IDentity.h"
#include <iostream>
#include <string>
#include<vector>
using namespace sf;
using namespace std;
class room :
	public IDentity, public Drawable  
{
private:
	virtual void draw(RenderTarget &target, RenderStates states) const override;
	int m_rows_in_room;
	int m_seats_in_row;
	seat **m_pointer;
	RectangleShape screen;
	long int m_room_id;
	vector <seat *> selected_v;
public:
	long static int room_id;
	static std::vector<room*>room_v;
	void edit_room();
	void book_selected();
	vector<seat*> & get_selected_v();
	static room * get_room(long int id);
	seat * get_seat(int row, int seat_nr) const;
	void show() const;
	void unselect_all();
	void update(sf::RenderWindow & app);
	room();
	room(int rows_number, int seats_in_row, std::string name);
	room(const room &Room);
	~room();
};

