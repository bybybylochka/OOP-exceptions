#include "TVShow.h"
#include<iostream>
using namespace std;

TVShow::TVShow()
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
	cout << "  ¬ведите название телепередачи:  ";
	set_name(check_string());
	cout << "  ¬ведите жанр телепередачи(1-спортивына€ телепередача, 2-новости, 3-прогноз погоды):  ";
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
	try {
		team.push_back(employee.get_StageManager(get_genre()));
		team.push_back(employee.get_StageManager(get_genre()));
	}
	catch (no_such_object err) {
		err.what();
	}
}
void TVShow::print_TVShow();