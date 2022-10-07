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
	throw no_such_object("Не найден режиссер!");
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
	throw new no_such_object("Не найден редактор!");
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
	throw no_such_object("Не найден ведущий!");
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
		throw "Не найден оператор!";
	}
	catch (const char* message)
	{
		throw;
	}
}
