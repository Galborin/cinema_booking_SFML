#pragma once
#include"IDentity.h"
#include<iostream>
#include<string>
#include<vector>

class movie : 
	public IDentity
{
private:
	long int m_movie_id;
public:
	long static int movie_id;
	static std::vector <movie*> movie_v;
	static movie* return_movie(long int id);
	static movie* return_movie(std::string title);
	movie(const std::string title);
	movie();
	~movie();
};
