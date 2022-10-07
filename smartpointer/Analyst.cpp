#include "Analyst.h"
#include <iostream>
#include "ItSpesialist.h"
using namespace std;

Analyst::Analyst()
{
	this->analyst_type = data_analyst;
}
Analyst::Analyst(ItSpecialist* It)
	: ItSpecialist(*(It))
{
}
void Analyst::set_analyst_type(Analyst_types analyst_type)
{
	this->analyst_type = analyst_type;
}
Analyst_types Analyst::get_analyst_type()
{
	return this->analyst_type;
}
void Analyst::create_data()
{
	cout << "  ¬ведите тип аналитика (1-бизнес-аналитик, 2-системный аналитик, 3-внвлитик данных):  ";
	switch (check_range(1, 3))
	{
	case 1: set_analyst_type(business_alalyst);
		set_code(generate_code("an", "bus"));
		break;
	case 2: set_analyst_type(systems_analyst);
		set_code(generate_code("an", "sys"));
		break;
	case 3: set_analyst_type(data_analyst);
		set_code(generate_code("an", "data"));
		break;
	}
}