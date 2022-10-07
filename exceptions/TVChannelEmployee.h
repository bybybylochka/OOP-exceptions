#pragma once
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
	virtual Genre gen_genre() { cout << endl; }
};


