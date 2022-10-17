#pragma once
#include<vector>
#include<iostream>
#include"TVChannelEmployee.h"
#include"StageManager.h"
#include"Editor.h"
#include"Anchorman.h"
#include"Header.h"

using namespace std;


class Employees
{
	vector<TVChannelEmployee*> employees;
public:
	TVChannelEmployee* get_StageManager(Genre);
	TVChannelEmployee* get_Editor(Genre);
	TVChannelEmployee* get_Anchorman(bool, Gender);
	TVChannelEmployee* get_Operator(bool);
	void print_employees();
	void add_employee();
	void write_into_file();
	void read_from_file();
};

class no_such_object
{
	string message;
public:
	no_such_object(string mes)
	{
		this->message = mes;
	}
	friend ostream& operator<<(ostream& out, no_such_object& obj)
	{
		out << "  Îøèáêà: " << obj.message << endl;
		return out;
	}
};

class index_out_of_range : public exception
{
	string message;
public:
	index_out_of_range(string message)
	{
		this->message = message;
	}
	const char* what()
	{
		return message.c_str();
	}

};