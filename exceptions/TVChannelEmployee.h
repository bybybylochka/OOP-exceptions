#pragma once
#include"IdentityData.h"
enum employeeTypes
{
	anchorman,
	editor,
	stage_manager,
	_operator
};

enum Genre {
	sport,
	news,
	weather
};

class TVChannelEmployee
{
	static string place_of_work;
	IdentityData identity_data;
public:
	TVChannelEmployee();
	TVChannelEmployee(IdentityData identity_data);
	~TVChannelEmployee();
	void print_data();
	virtual void create_data();
	IdentityData get_identity_data();
	virtual employeeTypes type_checker();
	virtual string get_type_name(employeeTypes type);
	///
	virtual Genre get_genre();
	virtual bool get_ability_to_improvise();
	virtual bool get_ability_to_dynamic_shooting();
};


