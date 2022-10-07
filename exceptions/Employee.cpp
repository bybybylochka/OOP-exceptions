#include "Employee.h"
#include<iostream>
using namespace std;

TVChannelEmployee* Employee::get_StageManager(Genre genre)
{
	for (int i = 0; i < employees.size(); i++)
		{
			if (employees[i]->type_checker() == stage_manager && employees[i]->gen_genre() == genre)
			{
				return employees[i];
			}
		}
	throw no_such_object("Не найден режиссер!");
}
TVChannelEmployee* Employee::get_Editor(Genre)
{

}
TVChannelEmployee* Employee::get_Anchorman(bool, Gender)
{

}
TVChannelEmployee* Employee::get_Operator(bool)
{

}
