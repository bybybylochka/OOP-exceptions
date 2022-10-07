#include "Employee.h"
#include<iostream>
using namespace std;

TVChannelEmployee* Employee::get_StageManager(Genre genre)
{
	for (int i = 0; i < employees.size(); i++)
		{
			if (employees[i]->type_checker() == stage_manager && employees[i]->get_genre() == genre)
			{
				return employees[i];
			}
		}
	throw no_such_object("Не найден режиссер, подходящий под условия!");
}
TVChannelEmployee* Employee::get_Editor(Genre genre)
{
	for (int i = 0; i < employees.size(); i++)
	{
		if (employees[i]->type_checker() == editor && employees[i]->get_genre() == genre)
		{
			return employees[i];
		}
	}
	throw new no_such_object("Не найден редактор, подходящий под условия!");
}
TVChannelEmployee* Employee::get_Anchorman(bool ability_to_improvise, Gender gender)
{
	for (int i = 0; i < employees.size(); i++)
	{
		if (employees[i]->type_checker() == anchorman && employees[i]->get_ability_to_improvise() == ability_to_improvise
			&& employees[i]->get_identity_data().get_gender()==gender)
		{
			return employees[i];
		}
	}
	throw no_such_object("Не найден ведущий, подходящий под условия!");
}
TVChannelEmployee* Employee::get_Operator(bool ability_to_dynamic_shooting)
{
	try 
	{
		for (int i = 0; i < employees.size(); i++)
		{
			if (employees[i]->type_checker() == _operator && employees[i]->get_ability_to_dynamic_shooting() == ability_to_dynamic_shooting)
			{
				return employees[i];
			}
		}
		throw "Не найден оператор, подходящий под условия!";
	}
	catch (const char* message)
	{
		throw;
	}
}


void Employee::add_employee() {
	IdentityData temp;
	temp.create_identity_data();
	cout << " Укажите тип сотрудника:\n 1 - Телеведущий\n 2 - Оператор\n 3 - Режиссер\n 4 - Редактор" << endl;
	TVChannelEmployee* employee = nullptr;
	switch (check_range(1, 4)) 
	{
	case 1: employee = new Anchorman(temp); 
		break;
	case 2: employee = new Operator(temp);
		break;
	case 3: employee = new Editor(temp);
		break;
	case 4: employee = new StageManager(temp);
		break;
	}
	employee->create_data();
	employees.push_back(employee);
}

void Employee::print_employees() {
	try {
		if (employees.size() == 0) throw " К сожалению, данные о сотрудниках отсутствуют!";
		cout << "__________________________________________________________________" << endl;
		cout << "|            ФИО             | Тип сотрудника | Возраст |   Пол  |" << endl;
		cout << "__________________________________________________________________" << endl;
		for (int i = 0; i < employees.size(); i++)
		{
			employees[i]->print_data();
			cout << "__________________________________________________________________" << endl;
		}
	}
	catch (const char* message) {
		cout << message << endl;
	}

}