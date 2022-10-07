#pragma once
#include "ItSpesialist.h"
class Developer: public ItSpecialist
{
	string language;
public:
	Developer();
	Developer(ItSpecialist* It);
	~Developer(){}
	void set_language(string language);
	string get_language();
	void create_data();
	string check_language(int&);

};

