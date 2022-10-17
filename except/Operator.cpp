#include "Operator.h"
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