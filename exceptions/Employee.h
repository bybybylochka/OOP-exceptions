#pragma once
#include<vector>
#include"TVChannelEmployee.h"
#include"StageManager.h"
#include"Editor.h"
#include"Anchorman.h"
#include"Operator.h"
class Employee
{
	vector<TVChannelEmployee*> employees;
public:
	TVChannelEmployee* get_StageManager(Genre);
	TVChannelEmployee* get_Editor(Genre);
	TVChannelEmployee* get_Anchorman(bool, Gender);
	TVChannelEmployee* get_Operator(bool);
};
class no_such_object
{
	string message;
public:
	no_such_object(string mes)
	{
		this->message = mes;
	}
	friend ostream& operator<<(ostream& out, const no_such_object& obj)
	{
		out << "  Îøèáêà: " << obj.message << endl;
		return out;
	}
};
