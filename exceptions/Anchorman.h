#pragma once
#include "TVChannelEmployee.h"

class Anchorman: public TVChannelEmployee
{
	bool ability_to_improvise;
public:
	Anchorman();
	Anchorman(IdentityData identityData);
	~Anchorman();
	void set_ability_to_improvise(bool);
	bool get_ability_to_improvise();
	void create_data();
	/*void print_data();*/
};

