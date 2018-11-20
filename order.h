#pragma once
#include"track.h"
#include "user.h"
#include<iostream>
#include<vector>
#include "IDentity.h"
using namespace std;
class order : 
	public IDentity
{
private:
	const user * m_user;
	track * m_track;
	seat ** m_pointer;
	int m_selected;
	long int track_id;
	string track_title;
	tm track_date;
public:
	long static int order_id;
	static vector <order *> order_v;
	void finish_order();
	void show_order() const;
	track * get_track();
	order(track &Track, const user &User);
	~order();
};

