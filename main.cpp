

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
#include"OnScreen.h"
using namespace sf;
using namespace std;
long int IDentity::id_global = 0;
long int order::order_id = 0;
long int movie::movie_id = 0;
long int room::room_id = 0;
long int track::track_id = 0;
long int user::user_id = 0;
vector<movie*> movie::movie_v;
vector<room*> room::room_v;
vector<track*> track::track_v;
vector<user*> user::user_v;
vector<order*> order::order_v;
Resources OnScreen::resources;
int main()
{
	//some objects
	new user("guest");
	new track(*new movie("Gladiator"), *new room(5, 10, "Room nr 1"), *new tm = { 0, 15 , 10, 18, 11 - 1, 2018 - 1900 });
	new track(*new movie("Dandelion"), *new room(3, 5, "Room nr 2 (small)"), *new tm = { 0, 0 , 18, 17, 11 - 1, 2018 - 1900 });
	new track(*new movie("The Last of Us"), *new room(5, 14, "3 Extra (big)"), *new tm = { 0, 30 , 16, 17, 11 - 1, 2018 - 1900 });
	new track(*new movie("Batman"), *new room(7,11,"Room nr 4"), *new tm = { 0 , 30,14,18,11 - 1,2018 - 1900 });
	new track(*new movie("The Lord of the Rings: The Fellowship of the Ring"), *new room(5,6,"Room 88"), *new tm = { 0, 15 , 11, 18, 11 - 1, 2018 - 1900 });
	string tmp;
	movie * movptr;
	room * roomptr;
	track * traptr;
	while (true)
	{
		do {
			system("cls");
			cout << "Choose:\n1: add room\n2: add movie\n3: add track\n4: show all orders\n5: show all tracks\ne: exit\n";
			getline(cin, tmp);
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
				traptr=new track();
				traptr->set_date();
				traptr->set_time();
				cout << "Movies: \n";
				for (auto &&i : movie::movie_v) {  //as a function call
					i->disp_name();
					cout << " movie id: " << i->get_id() << "\n";
				}
				system("Pause");
				cout << "Rooms: \n";
				for (auto &&i : room::room_v) {
					i->disp_name();
					cout << " room id: " << i->get_id() << "\n";
				}
				system("Pause");
				do {
					cout << "Movie id: ";
					getline(cin, tmp);
					movptr = movie::get_movie(stol(tmp));
				} while (movptr == nullptr);
				traptr->set_movie(movptr);
				do {
					cout << "Room id: ";
					getline(cin, tmp);
					roomptr = room::get_room(stol(tmp));
				} while (roomptr == nullptr);
				traptr->set_room(roomptr);
				traptr->update();
				traptr->show_info();
				system("Pause");
				break;
			}
			case '4': {
				for (auto &&i : order::order_v) {
					cout << "order id: " << i->get_id() << " user: " << i->get_name() <<"\n";
					i->show_order();
				}
				system("Pause");
				break;
			}
			case '5': {
				for (auto &&i : track::track_v) {
					i->show_info();
				}
				system("Pause");
				break;
			}
			default: {
				break;
			}
			}
		} while (tmp[0] != 'e');

		MyWindow menu_window;
		while (menu_window.isOpen())
		{

			while (menu_window.mode1() && menu_window.isOpen())
			{
			}
			while (menu_window.mode2() && menu_window.isOpen())
			{
			}
			while (menu_window.mode3() && menu_window.isOpen())
			{
			}
			while (menu_window.mode4() && menu_window.isOpen())
			{
			}
		}
	}
	return 0;
}



