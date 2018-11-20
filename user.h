#pragma once
#include<iostream>
#include<string>
#include"track.h"

class user : 
	public IDentity
{
private:
	long int m_user_id;
public:
	static long int user_id;
	static std::vector<user*>user_v;
	user();
	user(std::string login);
	~user();
};

