#include "Tester.h"
#include "ItSpesialist.h"
#include<iostream>

using namespace std;
Tester::Tester()
{
	this->testing_type = manual_testing;
}
Tester::Tester(ItSpecialist* It)
	: ItSpecialist(*(It))
{
}
void Tester::set_testing_type(Testing_types testing_type)
{
	this->testing_type = testing_type;
}
Testing_types Tester::get_testing_type()
{
	return this->testing_type;
}
void Tester::create_data()
{
	cout << "  Введите тип тестирование, на котором специализируется сотрудник (1-ручное тестирование, 2-автоматизированное тестирование):  ";
	switch (check_range(1,2))
	{
	case 1: set_testing_type(manual_testing);
		set_code(generate_code("test", "man"));
		break;
	case 2: set_testing_type(automated_testing);
		set_code(generate_code("test", "auto"));
		break;
	}
}