#pragma once
#include"track.h"
#include<iostream>
#include<vector>

class order
{
private:
	//const user * m_user;
	const track * m_track;
	std::vector <seat *> m_seat_v;
public:
	long static int order_id;
	order(const track &Track);
	~order();
};

