#pragma once
#include <iostream>
#include <string>
#include "movie.h"
#include "room.h"
#include "IDentity.h"
#include"OnScreen.h"
#include<ctime>
#include <SFML/Graphics.hpp>
#include<iomanip>
#include<cstring>
using namespace sf;
using namespace std;
class track : 
	public IDentity,public OnScreen
{
private:
	room * m_room;
	movie * m_movie;
	tm * m_date;
	long int m_track_id;
public:
	void update();
	static long int track_id;
	static vector<track*>track_v;
	tm * get_date() const;
	room * get_room() const;
	void set_movie(movie *movie);
	void set_room(room *room);
	void set_date();
	tm * get_date();
	void set_time();
	void show_info() const;
	track(movie & Movie, const room &Roo, tm &date);
	track();
	~track();
};

