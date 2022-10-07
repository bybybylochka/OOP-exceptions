#pragma once
#include"StageManager.h"
#include "IdentityData.h"
enum employeeTypes
{
	anchorman,
	editor,
	stage_manager,
	_operator
};

class TVChannelEmployee
{
	static string place_of_work;
	IdentityData identity_data;
public:
	TVChannelEmployee();
	~TVChannelEmployee();
	virtual void create_data();
	virtual void print_data();
	virtual employeeTypes type_checker();
	virtual Genre get_genre();
	virtual bool get_ability_to_improvise();
	virtual bool get_ability_to_dynamic_shooting();
	IdentityData get_identity_data();
};


