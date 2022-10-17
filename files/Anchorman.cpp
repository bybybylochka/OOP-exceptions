#include "Anchorman.h"
#include<iostream>
using namespace std;

Anchorman::Anchorman()
{
	ability_to_improvise = false;
}
Anchorman::Anchorman(IdentityData identity_data)
	: TVChannelEmployee(identity_data)
{
	ability_to_improvise = false;
}
Anchorman::~Anchorman()
{

}
void Anchorman::set_ability_to_improvise(bool ability_to_improvise)
{
	this->ability_to_improvise = ability_to_improvise;
}
bool Anchorman::get_ability_to_improvise()
{
	return this->ability_to_improvise;
}
void Anchorman::create_data()
{
	cout << "  Умеет ли телеведущий импровизировать в кадре(0-нет, 1-да):  ";
	check_range(0, 1) == 0 ? set_ability_to_improvise(false) : set_ability_to_improvise(true);
}
//istream& operator>>(istream& in, Anchorman& obj)
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
//	in >> obj.ability_to_improvise;
//	return in;
//}
//ostream& operator<<(ostream& out, Anchorman& obj)
//{
//	out << obj.get_identity_data().get_FIO();
//	out << obj.get_identity_data().get_age();
//	out << obj.get_identity_data().get_gender();
//	out << obj.ability_to_improvise;
//	return out;
//}