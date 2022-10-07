#pragma once
#include"ItSpesialist.h"
enum Testing_types 
{
	manual_testing,
	automated_testing
};

class Tester: public ItSpecialist
{
	Testing_types testing_type;
public:
	Tester();
	Tester(ItSpecialist* It);
	~Tester(){}
	void set_testing_type(Testing_types testing_type);
	Testing_types get_testing_type();
	void create_data();
};

