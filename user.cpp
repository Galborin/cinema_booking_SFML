#include "pch.h"
#include "user.h"

user::user() : m_login("undefined"),m_id(++user_id)
{
	user_v.push_back(this);
}

user::user(std::string login) : m_login(login), m_id(++user_id)
{
	user_v.push_back(this);
}

long int user::get_id()
{
	return m_id;
}

void user::make_order(track & Track)
{
	//int Row_tmp, Seat_nr_tmp;
	//std::string tmp;
	//m_order_v.push_back(new order(Track));
	/*std::cout << "order ID: " << m_order_v.back()->order_id << std::endl;
	std::cout << "Set row: ";
	getline(std::cin, tmp);
	Row_tmp = stoi(tmp);
	std::cout << "Set seat number: ";
	getline(std::cin, tmp);
	Seat_nr_tmp = stoi(tmp);*/
	//m_order_v.back()->book_seat(Row_tmp, Seat_nr_tmp);
}

void user::edit_personal_data() {
	std::cout << "Name: ";
	getline(std::cin, m_login);
	std::cout << "Done!\n";
}

std::string * user::get_personal_data()
{
	return &m_login;
}

user::~user()
{
	for (unsigned int i = 0; i < user_v.size(); ++i)
	{
		if (user_v[i] == this) {
			user_v.erase(user_v.begin() + i);
			break;
		}
	}
}
