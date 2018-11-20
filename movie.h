#pragma once
#include"IDentity.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class movie : 
	public IDentity
{
private:
	long int m_movie_id;
public:
	long static int movie_id;
	static vector <movie*> movie_v;
	static movie* get_movie(long int id);
	static movie* get_movie(string title);
	movie(const string title);
	movie();
	~movie();
};
