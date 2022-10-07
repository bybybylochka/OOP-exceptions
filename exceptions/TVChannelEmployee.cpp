#include "TVChannelEmployee.h"
#include"Anchorman.h"
#include"Editor.h"
#include"Operator.h"
#include"IdentityData.h"
#include<typeinfo>
#include<iostream>

TVChannelEmployee::TVChannelEmployee()
{
	this->place_of_work = "News";
}
TVChannelEmployee::~TVChannelEmployee()
{

}
void TVChannelEmployee::create_data()
{
	identity_data.create_identity_data();
}
void TVChannelEmployee::print_data()
{
	identity_data.print_identity_data();
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
Genre TVChannelEmployee::get_genre()
{
	cout << endl;
}
bool TVChannelEmployee::get_ability_to_improvise()
{
	cout << endl;
}
bool TVChannelEmployee::get_ability_to_dynamic_shooting()
{
	cout << endl;
}
IdentityData TVChannelEmployee::get_identity_data()
{
	return identity_data;
}