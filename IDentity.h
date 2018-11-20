#pragma once
#include<iostream>
#include<string>
class IDentity
{
private:
	long static int id_global;
protected:
	std::string m_name;
	const long int m_id;
public:
	long int get_id() const;
	void edit_name();
	void disp_name() const;
	std::string get_name() const;
	IDentity();
	IDentity(std::string name);
	IDentity(const IDentity & identity);
	virtual ~IDentity();
};

