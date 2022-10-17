#pragma once
#include"TVChannelEmployee.h"

class Operator : public TVChannelEmployee
{
private:
	bool ability_to_dynamic_shooting;
public:
	Operator();
	Operator(IdentityData identityData);
	~Operator();
	void set_ability_to_dynamic_shooting(bool);
	bool get_ability_to_dynamic_shooting();
	void create_data();
	/*friend istream& operator>>(istream& in, Operator& obj);
	friend ostream& operator<<(ostream& in, Operator& obj);*/
};