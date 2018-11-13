#include "pch.h"
#include "IDentity.h"


long int IDentity::get_id() const
{
	return m_id;
}

void IDentity::edit_name()
{
	std::string tmp;
	std::cout << "Set new name: ";
	getline(std::cin, tmp);
	m_name = tmp;
}

void IDentity::disp_name() const
{
	std::cout << m_name << std::endl;
}

std::string IDentity::get_name() const
{
	return m_name;
}

IDentity::IDentity() : m_name("undefined"), m_id(++id_global)
{
}

IDentity::IDentity(std::string name) : m_name(name), m_id(++id_global)
{
}


IDentity::~IDentity()
{
}
