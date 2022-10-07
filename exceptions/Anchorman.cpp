#include "Anchorman.h"
#include<iostream>
using namespace std;

Anchorman::Anchorman()
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
	TVChannelEmployee::create_data();
	cout << "  ����� �� ����������� ��������������� � �����(0-���, 1-��):  ";
	if (check_range(0, 1) == 0)
		set_ability_to_improvise(false);
	else
		set_ability_to_improvise(true);
}
void Anchorman::print_data()
{
	TVChannelEmployee::print_data();
	cout << "  ����������� ���������������:  ";
	cout << get_ability_to_improvise();
}