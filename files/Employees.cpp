#include "Employees.h"
#include<iostream>
#include<fstream>

using namespace std;

TVChannelEmployee* Employees::get_StageManager(Genre genre)
{
	for (int i = 0; i < employees.size(); i++)
	{
		if (employees[i]->type_checker() == stage_manager && employees[i]->get_genre() == genre)
		{
			return employees[i];
		}
	}
	throw no_such_object("�� ������ ��������, ���������� ��� �������!");
}
TVChannelEmployee* Employees::get_Editor(Genre genre)
{
	for (int i = 0; i < employees.size(); i++)
	{
		if (employees[i]->type_checker() == editor && employees[i]->get_genre() == genre)
		{
			return employees[i];
		}
	}
	throw new no_such_object("�� ������ ��������, ���������� ��� �������!");
}
TVChannelEmployee* Employees::get_Anchorman(bool ability_to_improvise, Gender gender)
{
	for (int i = 0; i < employees.size(); i++)
	{
		if (employees[i]->type_checker() == anchorman && employees[i]->get_ability_to_improvise() == ability_to_improvise
			&& employees[i]->get_identity_data().get_gender() == gender)
		{
			return employees[i];
		}
	}
	throw no_such_object("�� ������ �����������, ���������� ��� �������!");
}
TVChannelEmployee* Employees::get_Operator(bool ability_to_dynamic_shooting)
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
		throw "�� ������ ��������, ���������� ��� �������!";
	}
	catch (const char* message)
	{
		throw;
	}
}


void Employees::add_employee() {
	IdentityData temp;
	temp.create_identity_data();
	cout << " :\n �������� ��������� ����������: 1 - �����������\n 2 - ��������\n 3 - ��������\n 4 - ��������" << endl;
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

void Employees::print_employees() {
	try {
		if (employees.size() == 0) throw " � ���������, ������ � ����������� �����������!";
		cout << "__________________________________________________________________" << endl;
		cout << "|            ���             | ��� ���������� | ������� |   ���  |" << endl;
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
void Employees::write_into_file()
{
	/*ofstream ouf;
	ouf.open("employees.txt");
	if (!ouf)
	{
		cout << "  ���������� ������� ����!" << endl;
		return;
	}
	for (int i = 0; i < employees.size(); i++)
	{
		ouf << employees[i]->type_checker() << endl;
		ouf << employees[i];
	}*/

}
void Employees::read_from_file()
{
	/*ifstream inf;
	inf.open("employees.txt");
	if (!inf)
	{
		cout << "  ���������� ������� ����!" << endl;
		return;
	}
	int type;
	int count = 0;
	while (true)
	{
		inf >> type;
		if (inf.eof()) break;
		
		switch (type)
		{
		case 0:
		{
			Anchorman temp;
			inf >> temp;
			employees[count] = &temp;
			break;
		}
		case 1:
		{
			Editor temp;
			inf >> temp;
			employees[count] = &temp;
			break;
		}
		case 2:
		{
			StageManager temp;
			inf >> temp;
			employees[count] = &temp;
			break;
		}
		case 3: 
		{
			Operator temp;
			inf >> temp;
			employees[count] = &temp;
			break;
		}
		default: cout << "  ����������� ���" << endl;
		}
		count++;
	}*/
}