#include "pch.h"
#include "order.h"

void order::finish_order() 
{
	m_selected = m_track->get_room()->get_selected_v().size();
	m_pointer = new seat *[m_selected];
	for (auto &&i = 0; i < m_selected; ++i) {
		m_pointer[i] = m_track->get_room()->get_selected_v()[i];
	}
	track_id = m_track->get_id();
	track_title = m_track->get_name();
	track_date = *m_track->get_date();
	m_track->get_room()->book_selected();
}

void order::show_order() const
{
	cout << "track id: " << track_id << " Title/Room: " << track_title <<" Track date: "<< put_time(&track_date, "%d/%m/%Y %X") <<"\nSeats:\n";
	for (auto i = 0; i<m_selected;++i)
	{
		cout <<"row "<<m_pointer[i]->get_number().x + 1<< " nr. " << m_pointer[i]->get_number().y << "\n";
	}
}

track * order::get_track()
{
	return m_track;
}

order::order(track &Track, const user &User) : m_track(&Track), m_user(&User), m_pointer(nullptr), m_selected(0), track_id(0), track_title("unknown"), track_date({0,0,0,0,0,0,0,0,0}), IDentity(User.get_name())
{	
	order_v.push_back(this);
}

order::~order()
{
	for (unsigned int i = 0; i < order_v.size(); ++i)
	{
		if (order_v[i] == this) {
			order_v.erase(order_v.begin() + i);
			break;
		}
	}
}
