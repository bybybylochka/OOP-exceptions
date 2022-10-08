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
	//TVChannelEmployee::create_data();
	cout << "  Умеет ли телеведущий импровизировать в кадре(0-нет, 1-да):  ";
	check_range(0, 1) == 0 ? set_ability_to_improvise(false) : set_ability_to_improvise(true);
}
//void Anchorman::print_data()
//{
//	TVChannelEmployee::print_data();
//	cout << "  Способность импровизировать:  ";
//	cout << get_ability_to_improvise();
//}