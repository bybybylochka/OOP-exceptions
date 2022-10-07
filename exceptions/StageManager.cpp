#include "StageManager.h"
#include<iostream>
using namespace std;

StageManager::StageManager()
{
	this->genre = sport;
}

StageManager::~StageManager()
{

}
void StageManager::set_genre(Genre genre)
{
	this->genre = genre;
}
Genre StageManager::get_genre()
{
	return this->genre;
}
void StageManager::create_data()
{
	TVChannelEmployee::create_data();
	cout << "  ������� ����, �� ������� ���������������� ��������(1-���������� ������������, 2-�������, 3-������� ������):  ";
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
}
void StageManager::print_data()
{
	TVChannelEmployee::print_data();
	cout << "����:";
	cout << get_genre();
}