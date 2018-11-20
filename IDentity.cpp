#include "pch.h"
#include "IDentity.h"


long int IDentity::get_id() const
{
	return m_id;
}

void IDentity::edit_name()
{
	cout << "Set new name: ";
	getline(cin, m_name);
	cout << "Done!\n";
}

void IDentity::disp_name() const
{
	cout << m_name << endl;
}

string IDentity::get_name() const
{
	return m_name;
}

IDentity::IDentity() : m_name("undefined"), m_id(++id_global)
{
}

IDentity::IDentity(string name) : m_name(name), m_id(++id_global)
{
}

IDentity::IDentity(const IDentity & identity) : m_name(identity.m_name), m_id(identity.m_id)
{
}

IDentity::~IDentity()
{
}
