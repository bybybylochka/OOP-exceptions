#include "Header.h"
#include<iostream>
using namespace std;

Operator::Operator()
{
	ability_to_dynamic_shooting = false;
}
Operator::Operator(IdentityData identity_data)
	:TVChannelEmployee(identity_data)
{
	ability_to_dynamic_shooting = false;
}
Operator::~Operator()
{

}
void Operator::set_ability_to_dynamic_shooting(bool ability_to_dynamic_shooting)
{
	this->ability_to_dynamic_shooting = ability_to_dynamic_shooting;
}
bool Operator::get_ability_to_dynamic_shooting()
{
	return this->ability_to_dynamic_shooting;
}
void Operator::create_data()
{
	cout << "  На какой съемке специализируется оператор(0-статической, 1-динамической):  ";
	if (check_range(0, 1) == 0)
		set_ability_to_dynamic_shooting(false);
	else
		set_ability_to_dynamic_shooting(true);
}
//istream& operator>>(istream& in, Operator& obj)
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
//	in >> obj.ability_to_dynamic_shooting;
//	return in;
//}
//ostream& operator<<(ostream& out, Operator& obj)
//{
//	out << obj.get_identity_data().get_FIO();
//	out << obj.get_identity_data().get_age();
//	out << obj.get_identity_data().get_gender();
//	out << obj.ability_to_dynamic_shooting;
//	return out;
//}