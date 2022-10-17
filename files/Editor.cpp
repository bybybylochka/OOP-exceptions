#include "Editor.h"
#include<iostream>
#include"TVChannelEmployee.h"
using namespace std;

Editor::Editor()
{
	this->genre = sport;
}
Editor::Editor(IdentityData identity_data)
	: TVChannelEmployee(identity_data)
{
	this->genre = sport;
}
Editor::~Editor()
{

}
void Editor::set_genre(Genre genre)
{
	this->genre = genre;
}
Genre Editor::get_genre()
{
	return this->genre;
}
void Editor::create_data()
{
	cout << "  Введите жанр, на котором специализируется редактор(1-спортивные телепередачи, 2-новости, 3-прогноз погоды):  ";
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
//istream& operator>>(istream& in, Editor& obj)
//{
//	string temp_FIO;
//	getline(in, temp_FIO);
//	obj.get_identity_data().set_FIO(temp_FIO);
//	int temp_age;
//	in >> temp_age;
//	obj.get_identity_data().set_age(temp_age);
//	int temp_gender;
//	in >> temp_gender;
//	obj.get_identity_data().set_gender((Gender)temp_gender);
//	int temp_genre;
//	in >> temp_genre;
//	obj.set_genre((Genre)temp_genre);
//	return in;
//}
//ostream& operator<<(ostream& out, Editor& obj)
//{
//	out << obj.get_identity_data().get_FIO();
//	out << obj.get_identity_data().get_age();
//	out << obj.get_identity_data().get_gender();
//	out << obj.get_genre();
//	return out;
//}