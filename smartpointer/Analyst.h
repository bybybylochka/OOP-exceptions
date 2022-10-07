#pragma once
#include"ItSpesialist.h"
enum Analyst_types
{
	business_alalyst,
	systems_analyst,
	data_analyst
};

class Analyst:public ItSpecialist
{
	Analyst_types analyst_type;
public:
	Analyst();
	Analyst(ItSpecialist* It);
	~Analyst(){}
	void set_analyst_type(Analyst_types analyst_type);
	Analyst_types get_analyst_type();
	void create_data();
};

