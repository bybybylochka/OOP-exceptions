#include"TVChannelEmployee.h"
#include"Anchorman.h"
#include"Editor.h"
#include"Header.h"
#include"IdentityData.h"
#include<typeinfo>
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

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
	cout << "|" << setw(28) << identity_data.get_FIO() << "|" << setw(16) << get_type_name(type_checker()) << "|"
		<< setw(9) << identity_data.get_age() << "|" << setw(8) << get_string_gender(identity_data.get_gender()) << "|" << endl;
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
	case anchorman: return "Ведущий";
		break;
	case editor: return "Редактор";
		break;
	case stage_manager: return "Режиссер";
		break;
	case _operator: return "Оператор";
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
//istream& operator>>(istream& in, TVChannelEmployee& obj)
//{
//	string temp_FIO;
//	getline(in, temp_FIO);
//	obj.get_identity_data().set_FIO(temp_FIO);
//	int temp_age;
//	in >> temp_age;
//	obj.get_identity_data().set_age(temp_age);
//	int temp_gender;
//	in >> temp_gender;
//	obj.get_identity_data().set_gender((Gender)temp_gender);
//}
//ostream& operator<<(ostream& out, TVChannelEmployee& obj)
//{
//	out << obj.get_identity_data().get_FIO() << endl;
//	out << obj.get_identity_data().get_age() << endl;
//	out << obj.get_identity_data().get_gender() << endl;
//}