#include "pch.h"
#include "user.h"

user::user() : m_user_id(++user_id),IDentity()
{
	user_v.push_back(this);
}

user::user(std::string login) : m_user_id(++user_id), IDentity(login)
{
	user_v.push_back(this);
}


user::~user()
{
	for (unsigned int i = 0; i < user_v.size(); ++i)
	{
		if (user_v[i] == this) {
			user_v.erase(user_v.begin() + i);
			break;
		}
	}
}
