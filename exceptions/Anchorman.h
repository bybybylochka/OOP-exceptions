#pragma once
#include "TVChannelEmployee.h"

class Anchorman: public TVChannelEmployee
{
	bool ability_to_improvise;
public:
	Anchorman();
	Anchorman(IdentityData identity_data);
	~Anchorman();
	void set_ability_to_improvise(bool);
	bool get_ability_to_improvise();
	void create_data();
};

