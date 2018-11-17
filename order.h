#pragma once
#include"track.h"
#include "user.h"
#include<iostream>
#include<vector>
#include "IDentity.h"

class order : 
	public IDentity
{
private:
	const user * m_user;
	const track * m_track;
	std::vector <seat *> m_seat_v;
public:
	long static int order_id;
	static std::vector <order *> order_v;
	void add_seat(seat &Seat);
	void set_track(const track & Track);
	order(const track &Track, const user &User);
	order(const user &User);
	~order();
};

