#include "pch.h"
#include "order.h"


void order::add_seat(seat & Seat)
{
	m_seat_v.push_back(&Seat);
}

void order::set_track(const track & Track)
{
	m_track = &Track;
}

order::order(const track &Track,const user &User) : m_track(&Track),m_user(&User), IDentity(User.get_name())
{	
	order_v.push_back(this);
}

order::order(const user & User) : m_user(&User), IDentity()
{
	order_v.push_back(this);
}


order::~order()
{
}
