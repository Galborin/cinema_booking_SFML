#include "pch.h"
#include "order.h"


order::order(const track &Track) : m_track(&Track)
{	
	++order_id;
}


order::~order()
{
}
