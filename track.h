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
using namespace sf;

class track : 
	public IDentity,public OnScreen
{
private:
	const room * m_room;
	const movie * m_movie;
	tm * m_date;
	long int m_track_id;
public:
	void initialize();
	static long int track_id;
	static std::vector<track*>track_v;
	track(const movie * Movie, const room &Roo, tm &date);
	track(const movie * Movie, const room &Roo);
	track();
	tm * get_date();
	seat * get_selected_seats() const;
	void draw_room(RenderWindow & target);
	void set_movie(movie *movie);
	void set_room(room *room);
	void set_date();
	void set_time();
	void show_info() const;
	~track();
};

