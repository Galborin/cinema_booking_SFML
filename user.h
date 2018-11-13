#pragma once
#include<iostream>
#include<string>
#include"order.h"

class user
{
private:
	std::string m_login;
	std::vector <order *> m_order_v;
	long int m_id;
public:
	user();
	static long int user_id;
	static std::vector<user*>user_v;
	user(std::string login);
	long int get_id();
	void make_order(track &Track);
	void edit_personal_data();
	std::string * get_personal_data();
	~user();
};

