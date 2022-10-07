#include "TVChannelEmployee.h"
#include"Anchorman.h"
#include"Editor.h"
#include"Operator.h"
#include"IdentityData.h"
#include<typeinfo>
#include<iostream>
#include<iomanip>

string TVChannelEmployee::place_of_work;

TVChannelEmployee::TVChannelEmployee()
{
	this->place_of_work = "News";
}
TVChannelEmployee::TVChannelEmployee(IdentityData identity_data) {
	this->identity_data = identity_data;
	this->place_of_work = "News";
}
TVChannelEmployee::~TVChannelEmployee() {}
void TVChannelEmployee::create_data()
{
	identity_data.create_identity_data();
}
void TVChannelEmployee::print_data()
{
	cout << "|"  << setw(30) << identity_data.get_FIO() << get_type_name(type_checker())
		<< setw(10) << identity_data.get_age() << setw(10) << identity_data.get_gender() << "|" << endl;
	// доделать
}
employeeTypes TVChannelEmployee::type_checker()
{
	if (typeid(*this) == typeid(Anchorman))
		return anchorman;
	if (typeid(*this) == typeid(Operator))
		return _operator;
	if (typeid(*this) == typeid(StageManager))
		return stage_manager;
	if (typeid(*this) == typeid(Editor))
		return editor;
}
string TVChannelEmployee::get_type_name(employeeTypes type) {
	switch (type)
	{
	case anchorman: return "телеведущий";
		break;
	case editor: return "редактор";
		break;
	case stage_manager: return "режиссер";
		break;
	case _operator: return "оператор";
		break;
	}
}
Genre TVChannelEmployee::get_genre()
{
	return news;
}
bool TVChannelEmployee::get_ability_to_improvise()
{
	return false;
}
bool TVChannelEmployee::get_ability_to_dynamic_shooting()
{
	return false;
}
IdentityData TVChannelEmployee::get_identity_data()
{
	return identity_data;
}