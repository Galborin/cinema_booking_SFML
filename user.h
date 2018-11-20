#pragma once
#include<iostream>
#include<string>
#include"track.h"
using namespace std;
class user : 
	public IDentity
{
private:
	long int m_user_id;
public:
	static long int user_id;
	static vector<user*>user_v;
	user();
	user(string login);
	~user();
};

