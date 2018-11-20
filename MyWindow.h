#pragma once
#include <SFML/Graphics.hpp>
#include "user.h"
#include"track.h"
#include "order.h"
#include<vector>
using namespace sf;
using namespace std;
class MyWindow :
	public RenderWindow
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
	Texture texture;
	Text text1;
	Font font;
	Sprite sprit;
	RectangleShape button1;
	RectangleShape button2;
	RectangleShape button3;
	Uint32 unicode;
	Event ev;
	float scroll;
	friend bool operator > (const tm &date1, const tm &date2);
	friend bool operator == (const tm &date1, const tm &date2);
	friend tm operator++ (tm &date1);
	friend tm operator-- (tm &date1);
public:

	bool mode1();
	bool mode2();
	bool mode3();
	bool mode4();
	MyWindow();
	~MyWindow();
};

