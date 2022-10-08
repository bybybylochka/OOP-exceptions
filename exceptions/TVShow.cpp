 #include "TVShow.h"
#include<iostream>
#include<iomanip>
using namespace std;

TVShow::TVShow()
{
	this->name = "no data";
	this->genre = sport;
}
TVShow::TVShow(Employee employee)
{
	this->name = "no data";
	this->genre = sport;
	this->employee = employee;
}
TVShow::TVShow(const TVShow& obj)
{
	this->name = obj.name;
	this->genre = obj.genre;
	this->team = obj.team;
}
TVShow::~TVShow()
{

}
void TVShow::set_name(string name)
{
	this->name = name;
}
void TVShow::set_genre(Genre genre)
{
	this->genre = genre;
}
string TVShow::get_name()
{
	return this->name;
}
Genre TVShow::get_genre()
{
	return this->genre;
}
void TVShow::create_TVShow()
{
	cout << "  ������� �������� ������������:  ";
	set_name(check_string());
	cout << "  ������� ���� ������������(1-����������� ������������, 2-�������, 3-������� ������):  ";
	switch (check_range(1, 3))
	{
	case 1:
		set_genre(sport);
		break;
	case 2:
		set_genre(news);
		break;
	case 3:
		set_genre(weather);
		break;
	}
	cout << "  ������� �������� ��� ��� ������������(0-�������,1-�������):  ";
	Gender temp_gen;
	check_range(0, 1) == 0 ? temp_gen = male : temp_gen = female;
	cout << "  ������ �� ����������� ����� ����� ������������(0-���, 1-��):  ";
	bool temp_imp;
	check_range(0, 1) == 0 ? temp_imp = false : temp_imp = true;
	cout << "  ������ �� �������� �������� ������� ������������ ������(0-���, 1-��):  ";
	bool temp_shooting = false;
	check_range(0, 1) == 0 ? temp_shooting == false : temp_shooting == true;
	try {
		team.push_back(employee.get_StageManager(get_genre()));
		team.push_back(employee.get_Editor(get_genre()));
		team.push_back(employee.get_Anchorman(temp_imp, temp_gen));
		team.push_back(employee.get_Operator(temp_shooting));
	}
	catch (no_such_object err) 
	{
		cout << err << endl;
	}
	catch (no_such_object* err) 
	{
		cout << err << endl;
	}
	catch (const char* message)
	{
		cout << message << endl;
	}
}
void TVShow::print_TVShow()
{
	if (team.size() < 4) throw 1;
	cout << "  ���������� � ������������  " << endl;
	cout << "  �������� ������������:  " << get_name() << endl;
	cout << "  ���� ������������:  " << get_genre() << endl;
	cout << "  ��������� �������:  " << endl;
	cout << "____________________________________________"<<endl<<endl;
	cout << "|  ���������  |            ���             |" << endl;
	cout << "____________________________________________" << endl;
	cout << setw(14) << "�������" << setw(30)<<team[0]->get_identity_data().get_FIO() << endl;
	cout << "____________________________________________" << endl;
	cout << setw(14) << "��������" << setw(30) << team[1]->get_identity_data().get_FIO() << endl;
	cout << "____________________________________________" << endl;
	cout << setw(14) << "�������" << setw(30) << team[2]->get_identity_data().get_FIO() << endl;
	cout << "____________________________________________" << endl;
	cout << setw(14) << "��������" << setw(30) << team[3]->get_identity_data().get_FIO() << endl;
	cout << "____________________________________________" << endl;
}