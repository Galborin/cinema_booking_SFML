#include "pch.h"
#include "movie.h"


movie * movie::get_movie(long int id)
{
	for (auto &&i : movie_v) {
		if (i->m_id == id) {
			return i;
			break;
		}
	}
	cout << "wrong film id \n";
	return nullptr;
}

movie * movie::get_movie(string title)
{
	for (auto &&i : movie_v) {
		if (i->m_name == title) {
			return i;
			break;
		}
	}
	return new movie(title);
}

movie::movie(string title) : m_movie_id(++movie_id) ,IDentity(title)
{
	movie_v.push_back(this);
}

movie::movie() : m_movie_id(++movie_id), IDentity()
{
	movie_v.push_back(this);
}

movie::~movie()
{
	for (unsigned int i = 0; i < movie_v.size(); ++i)
	{
		if (movie_v[i] == this) {
			movie_v.erase(movie_v.begin() + i);
			break;
		}
	}
}
