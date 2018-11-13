#pragma once
#include <iostream>
#include <string>
#include "movie.h"
#include "room.h"
#include<ctime>
using namespace sf;
class track : 
	public sf::Drawable,public sf::Transformable
{
private:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	const room * m_room;
	const movie * m_movie;
	tm m_date;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	long int m_id;
public:
	long int get_id();
	static std::vector<track*>track_v;
	static long int track_id;
	track(const movie * Movie, const room &Roo, const tm date);
	track(const movie * Movie, const room &Roo);
	track();
	void set_movie(movie *movie);
	void set_room(room *room);
	void set_date();
	void set_time();
	void show_info() const;
	~track();
};

