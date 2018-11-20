#pragma once
#include<iostream>
#include<string>
using namespace std;
class IDentity
{
private:
	long static int id_global;
protected:
	string m_name;
	const long int m_id;
public:
	long int get_id() const;
	void edit_name();
	void disp_name() const;
	string get_name() const;
	IDentity();
	IDentity(string name);
	IDentity(const IDentity & identity);
	virtual ~IDentity();
};

