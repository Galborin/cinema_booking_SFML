

#include "pch.h"
#include <iostream>
#include<SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include"room.h"
#include"order.h"
#include"movie.h"
#include"track.h"
#include"user.h"
#include"MyWindow.h"
#include"IDentity.h"

long int IDentity::id_global = 0;
long int order::order_id = 0;
long int movie::movie_id = 0;
long int room::room_id = 0;
long int track::track_id = 0;
long int user::user_id = 0;
std::vector<movie*> movie::movie_v;
std::vector<room*> room::room_v;
std::vector<track*> track::track_v;
std::vector<user*> user::user_v;
//movie, track, order,room should have one basic class

int main()
{
	//declaration of some class objects
	new user("admin");
	new room(5,10,"Room0");
	new room(3, 5, "Room1 (small)");
	new room(7, 14, "Room2 (big)");
	new movie("Star Wars: Episode 1");
	new movie("The Last of Us");
	new movie("The Witcher");
	new movie("Marvel Superheroes");
	tm date,date2,date3;
	date.tm_mday = 11; date2.tm_mday = 11; date3.tm_mday = 11;
	date.tm_mon = 11; date2.tm_mon = 11; date3.tm_mon = 11;
	date.tm_year = 2018; date2.tm_year = 2018; date3.tm_year = 2018;
	date.tm_hour = 10; date2.tm_hour = 12; date3.tm_hour = 15;
	date.tm_min = 15; date2.tm_min = 15; date3.tm_min = 15;
	new track(new movie("Gladiator"), *room::room_v[0],date);
	new track(new movie("Dandelion"), *room::room_v[2], date2);
	new track(movie::return_movie("The Last of Us"), *room::room_v[2], date2);
	
	std::string tmp;
	movie * movptr;
	room * roomptr;
	do {
		system("cls");
		std::cout << "Choose:\n1: add room\n2: add movie\n3: add track\ne: exit\n";
		getline(std::cin, tmp);
		switch (tmp[0])
		{
		case '1': {
			new room();
			room::room_v.back()->edit_room();
			break;
		}
		case '2': {
			new movie();
			movie::movie_v.back()->edit_name();
			break;
		}
		case '3': {
			new track();
			track::track_v.back()->set_date();
			track::track_v.back()->set_time();
			std::cout << "Movies: \n";
			for (auto &&i: movie::movie_v) {  //as a function call
				i->disp_name();
				std::cout << " movie id: " << i->get_id() << "\n";
			}
			system("Pause");
			std::cout << "Rooms: \n";
			for (auto &&i : room::room_v) {
				i->disp_name();
				std::cout << " room id: " << i->get_id() << "\n";
			}
			system("Pause");
			do{
				std::cout << "Movie id: ";
				getline(std::cin, tmp);
				movptr = movie::return_movie(std::stol(tmp));
			} while (movptr== nullptr);
			track::track_v.back()->set_movie(movptr);
			do {
				std::cout << "Room id: ";
				getline(std::cin, tmp);
				roomptr = room::return_room(std::stol(tmp));
			} while (roomptr== nullptr);
			track::track_v.back()->set_room(roomptr);
			break;
		}
		default: {
			break;
		}
		}
	} while (tmp[0] != 'e');

	user * use = user::user_v.front();

	MyWindow menu_window;

	sf::Texture texture;
	texture.loadFromFile("obraz.jpeg");

	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	sf::Sprite sprit;
	sprit.setTexture(texture);
	sprit.setPosition(0, 0);

	sf::RectangleShape rectangle(sf::Vector2f(80, 80));
	rectangle.setPosition(900, 700);

	sf::Text text1;
	text1.setFont(font);
	text1.setCharacterSize(40);
	text1.setFillColor(sf::Color::Red);
	text1.setString("Login: ");
	text1.setPosition(0, 0);
	sf::Uint32 unicode;
	sf::Event ev;
	user * current_user = use;
	bool new_user;

	while (menu_window.isOpen())
	{
		unicode = 0;
		menu_window.clear(sf::Color::Blue);
		while (menu_window.pollEvent(ev)) {


			if (ev.type == sf::Event::Closed || (ev.type == sf::Event::KeyPressed&&ev.key.code == sf::Keyboard::Escape))
				menu_window.close();
			if (ev.type == sf::Event::MouseButtonPressed&&rectangle.getGlobalBounds().contains(menu_window.mapPixelToCoords(sf::Mouse::getPosition(menu_window))))
			{
				rectangle.setFillColor(sf::Color::Red);
				new_user = true;
				for (unsigned int i = 0; i < user::user_v.size(); ++i) 
				{
					if (*user::user_v[i]->get_personal_data() == (text1.getString().substring(7, text1.getString().getSize())))
					{
						current_user = user::user_v[i];
						new_user = false;
						break;
					}
				}
				if (new_user == true) {
					new user(text1.getString().substring(7, text1.getString().getSize()));
					current_user = user::user_v.back();
				}
			}
			else
				rectangle.setFillColor(sf::Color::Green);

			if (ev.type == sf::Event::TextEntered)
				unicode = ev.text.unicode;
		}
		if (unicode == 8)
		{
			if (text1.getString().getSize() > 7)
				text1.setString(text1.getString().substring(0, text1.getString().getSize() - 1));
		}
		else if (unicode)
			text1.setString(text1.getString() + unicode);

		
		track::track_v[0]->setPosition(500,500);
		menu_window.draw(sprit);
		menu_window.draw(text1);
		menu_window.draw(*track::track_v[0]);
		room::room_v.front()->draw_seats(menu_window);
		room::room_v.front()->update(menu_window);
		menu_window.draw(rectangle);
		menu_window.display();
	}
	
	return 0;
}



