#pragma once
#include <SFML/Graphics.hpp>
#include "user.h"
#include"track.h"
#include "order.h"
#include<vector>

class MyWindow :
	public sf::RenderWindow
{
private:
	user * current_user;
	order * current_order;
	track * current_track;
	seat * selected_seat;
	time_t t;
	tm * now;
	tm * current_day;
	errno_t err;
protected:
	float scroll;
	friend bool operator > (const tm &date1, const tm &date2);
	friend bool operator == (const tm &date1, const tm &date2);
	friend tm operator++ (tm &date1);
	friend tm operator-- (tm &date1);
public:
	sf::Texture texture;
	sf::Text text1;
	sf::Font font;
	sf::Sprite sprit;
	sf::RectangleShape button1; 
	sf::RectangleShape button2;
	sf::RectangleShape button3;
	sf::Uint32 unicode;
	sf::Event ev;
	bool mode1();
	bool mode2();
	bool mode3();
	bool mode4();
	MyWindow();
	~MyWindow();
};

