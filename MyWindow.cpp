#include "pch.h"
#include "MyWindow.h"

bool operator> (const tm &date1, const tm &date2) {
	if (date1.tm_year > date2.tm_year)
		return true;
	else if (date1.tm_year == date2.tm_year) {
		if (date1.tm_mon > date2.tm_mon)
			return true;
		else if (date1.tm_mon == date2.tm_mon) {
			if (date1.tm_mday > date2.tm_mday)
				return true;
			else if (date1.tm_mday == date2.tm_mday) {
				if (date1.tm_hour > date2.tm_hour)
					return true;
				else if (date1.tm_hour == date2.tm_hour) {
					if (date1.tm_min > date2.tm_min)
						return true;
				}
			}
		}
	}
	return false;
}

bool operator == (const tm &date1, const tm &date2) {
	if ((date1.tm_year == date2.tm_year) && (date1.tm_mon == date2.tm_mon) && (date1.tm_mday == date2.tm_mday))
		return true;
	else
		return false;
}

tm operator++(tm & date1)
{
	if ((((date1.tm_mday == 31) && (date1.tm_mon == 0 || date1.tm_mon == 2 || date1.tm_mon == 4 || date1.tm_mon == 6 || date1.tm_mon == 7 || date1.tm_mon == 9 || date1.tm_mon == 11)) ||
		((date1.tm_mday == 30) && (date1.tm_mon == 3 || date1.tm_mon == 5 || date1.tm_mon == 8 || date1.tm_mon == 10))
		|| (date1.tm_mday == 29 && (date1.tm_mon == 1) && (date1.tm_year % 4 == 0))
		|| (date1.tm_mday == 28 && (date1.tm_mon == 1) && (date1.tm_year % 4 != 0)))) {
		if ((date1.tm_mon == 11)) {
			date1.tm_mday = 1;
			date1.tm_mon = 0;
			++date1.tm_year;
		}
		else
		{
			date1.tm_mday = 1;
			date1.tm_mon++;
		}

	}
	else
		++date1.tm_mday;
	return date1;
}

tm operator--(tm & date1)
{
	if (date1.tm_mday == 1) {
		if ((date1.tm_mon == 4 || date1.tm_mon == 6 || date1.tm_mon == 9 || date1.tm_mon == 11))
		{
			date1.tm_mday = 30;
			--date1.tm_mon;
		}
		else if ((date1.tm_mon == 1 || date1.tm_mon == 3 || date1.tm_mon == 5 || date1.tm_mon == 7 || date1.tm_mon == 8 || date1.tm_mon == 10))
		{
			date1.tm_mday = 31;
			--date1.tm_mon;
		}
		else if ((date1.tm_mon == 2) && (date1.tm_year % 4 == 0))
		{
			date1.tm_mday = 29;
			--date1.tm_mon;
		}
		else if ((date1.tm_mon == 2) && (date1.tm_year % 4 != 0))
		{
			date1.tm_mday = 28;
			--date1.tm_mon;
		}
		else if (date1.tm_mon == 0)
		{
			date1.tm_mday = 31;
			date1.tm_mon = 11;
			--date1.tm_year;
		}
	}
	else
		--date1.tm_mday;
	return date1;
}


bool MyWindow::mode1()//signing up, logging in
{
	unicode = 0;
	clear(Color::Blue);
	while (pollEvent(ev)) {


		if (ev.type == Event::Closed || (ev.type == Event::KeyPressed&&ev.key.code == Keyboard::Escape)) {
			close();
			break;
		}
		if (ev.type == Event::MouseButtonPressed&&button1.getGlobalBounds().contains(mapPixelToCoords(Mouse::getPosition(*this))))
		{
			button1.setFillColor(Color::Red);
			if (text1.getString().getSize() > 7) {
				current_user = nullptr;
				for (unsigned int i = 0; i < user::user_v.size(); ++i)
				{
					if (user::user_v[i]->get_name() == (text1.getString().substring(7, text1.getString().getSize())))
					{
						current_user = user::user_v[i];
						break;
					}
				}
				if (current_user == nullptr) {
					current_user = new user(text1.getString().substring(7, text1.getString().getSize()));
				}
				//logged_in(menu_window);
				button1.setFillColor(Color::Green);
				t = time(NULL);
				err = localtime_s(current_day, &t);
				text1.setString("Logged as: " + current_user->get_name() + "\n" + to_string(current_day->tm_mday) + "." + to_string(current_day->tm_mon + 1));
				text1.setPosition(0, 0);
				current_track = nullptr;
				scroll = 0;
				return false;
				break;
			}
		}
		else
			button1.setFillColor(Color::Green);

		if (ev.type == Event::TextEntered)
			unicode = ev.text.unicode;
	}
	if (unicode == 8)
	{
		if (text1.getString().getSize() > 7)
			text1.setString(text1.getString().substring(0, text1.getString().getSize() - 1));
	}
	else if (unicode)
		text1.setString(text1.getString() + unicode);

	draw(sprit);
	draw(text1);

	draw(button1);
	display();
	return true;
}

bool MyWindow::mode2()//choosing track
{
	t = time(NULL);
	err = localtime_s(now, &t);

	clear(Color::Blue);
	while (pollEvent(ev)) {
		if (ev.type == Event::Closed || (ev.type == Event::KeyPressed&&ev.key.code == Keyboard::Escape))
			close();
		if (ev.type == Event::MouseButtonPressed&&button1.getGlobalBounds().contains(mapPixelToCoords(Mouse::getPosition(*this)))) {
			button1.setFillColor(Color::Red);
			++*current_day;
			scroll = 0;
			if (current_track != nullptr)
			{
				current_track->setOutlineThickness(0.f);
				current_track = nullptr;
			}
			text1.setString("Logged as: " + current_user->get_name() + "\n" + to_string(current_day->tm_mday) + "." + to_string(current_day->tm_mon + 1));
		}
		else
			button1.setFillColor(Color::Green);
		if (ev.type == Event::MouseButtonPressed&&button2.getGlobalBounds().contains(mapPixelToCoords(Mouse::getPosition(*this)))) {
			button2.setFillColor(Color::Red);
			--*current_day;
			scroll = 0;
			if (current_track != nullptr)
			{
				current_track->setOutlineThickness(0.f);
				current_track = nullptr;
			}
			text1.setString("Logged as: " + current_user->get_name() + "\n" + to_string(current_day->tm_mday) + "." + to_string(current_day->tm_mon + 1));
		}
		else
			button2.setFillColor(Color::Green);
		if (ev.type == Event::MouseButtonPressed&&button3.getGlobalBounds().contains(mapPixelToCoords(Mouse::getPosition(*this)))) {
			button3.setFillColor(Color::Red);
			if (current_track != nullptr) {
				//track is chosen;
				current_track->setOutlineThickness(0);
				current_order = new order(*current_track, *current_user);
				text1.setPosition(0, 0);
				return false;
			}
		}
		else
			button3.setFillColor(Color::Green);
		if (ev.type == Event::MouseWheelMoved)
		{
			scroll = scroll + ev.mouseWheel.delta;
		}
	}
	draw(sprit);
	//what to draw:
	for (unsigned int i = 0, j = 0; i < track::track_v.size(); ++i) {
		if ((*track::track_v[i]->get_date() == *current_day)) {
			track::track_v[i]->set_position(+0.f, 100.f + (110.f*j++) + (scroll*10));
			if (Mouse::isButtonPressed(Mouse::Button::Left) && (track::track_v[i]->getGlobalBounds().contains(this->mapPixelToCoords(Mouse::getPosition(*this)))))
			{
				if (current_track == nullptr) {
					current_track = track::track_v[i];
					track::track_v[i]->setOutlineThickness(10.f);

				}
				else if (current_track == track::track_v[i])
				{
					track::track_v[i]->setOutlineThickness(0);
					current_track = nullptr;
				}
				else
				{
					current_track->setOutlineThickness(0);
					current_track = track::track_v[i];
					track::track_v[i]->setOutlineThickness(10.f);
				}
				while (Mouse::isButtonPressed(Mouse::Button::Left)) {};
			}
			draw(*track::track_v[i]);
		}
	}
	draw(text1);
	draw(button1);
	draw(button2);
	draw(button3);
	display();
	return true;
}

bool MyWindow::mode3()//choosing seats
{
	clear(Color::Blue);
	
	while (pollEvent(ev)) {
		if (ev.type == Event::Closed || (ev.type == Event::KeyPressed&&ev.key.code == Keyboard::Escape))
			close();
		if (ev.type == Event::MouseButtonPressed&&button3.getGlobalBounds().contains(mapPixelToCoords(Mouse::getPosition(*this)))) {
			button3.setFillColor(Color::Red);
			current_order->finish_order();
			cout << "Order completed!\n";
			text1.setString("" + current_user->get_name() + ",\n" + "YOUR ORDER IS COMPLETED");
			text1.setPosition(100, 200);
			current_order->show_order();
			return false;
		}
		else
			button3.setFillColor(Color::Green);
		if (ev.type == Event::MouseButtonPressed&&button2.getGlobalBounds().contains(mapPixelToCoords(Mouse::getPosition(*this)))) {
			button2.setFillColor(Color::Red);
			current_track->get_room()->unselect_all();
			current_track = nullptr;
			delete current_order;
			while (mode2()) {};
		}
		else
			button2.setFillColor(Color::Green);
	}

	draw(sprit);
	//what to draw:
	if (this->isOpen()) {
		this->draw(*current_track->get_room());
		current_track->get_room()->update(*this);
	}
	draw(button3);
	draw(button2);
	display();
	return true;
}

bool MyWindow::mode4() //order completed
{
	clear(Color::Blue);
	t = time(NULL);
	err = localtime_s(current_day, &t);
	text1.setString(current_user->get_name() + ",\n" + "YOUR ORDER IS COMPLETED" + "\n" + to_string(current_day->tm_mday) + "." + to_string(current_day->tm_mon + 1) + "  "); 
	if (current_day->tm_hour < 10) text1.setString(text1.getString() + "0");
	text1.setString(text1.getString() + to_string(current_day->tm_hour) + ":");
	if (current_day->tm_min < 10) text1.setString(text1.getString() + "0");
	text1.setString(text1.getString() + to_string(current_day->tm_min));
	while (pollEvent(ev)) {
		if (ev.type == Event::Closed || (ev.type == Event::KeyPressed&&ev.key.code == Keyboard::Escape))
			close();
		if (ev.type == Event::MouseButtonPressed&&button3.getGlobalBounds().contains(mapPixelToCoords(Mouse::getPosition(*this)))) {
			button3.setFillColor(Color::Red);

			text1.setString("Login: ");
			text1.setPosition(300, 300);
			return false;
		}
		else
			button3.setFillColor(Color::Green);
	}

	draw(sprit);
	draw(text1);
	//what to draw:
	
	draw(button3);
	display();
	return true;
}

MyWindow::MyWindow() : current_user(user::user_v.front()),now(new tm),current_day(new tm),scroll(0)
{
	create(VideoMode(1024, 768, 32), "MyWindow");//,Style::Fullscreen); //1024, 768
	setFramerateLimit(60);
	texture.loadFromFile(".\\cinema_booking_SFML\\obraz.jpeg");
	font.loadFromFile(".\\cinema_booking_SFML\\arial.ttf");
	sprit.setTexture(texture);
	sprit.setPosition(0, 0);
	button1.setSize(Vector2f(80, 80));
	button1.setPosition(900, 688);
	button2.setSize(Vector2f(80, 80));
	button2.setPosition(44, 688);
	button3.setSize(Vector2f(200, 80));
	button3.setPosition(412, 688);
	text1.setFont(font);
	text1.setCharacterSize(40);
	text1.setFillColor(Color::Red);
	text1.setString("Login: ");
	text1.setPosition(300, 300);
	
}


MyWindow::~MyWindow()
{
}
