#include "IdentityData.h"
#include<iostream>
using namespace std;

IdentityData::IdentityData()
{
	this->FIO = "No data";
	this->gender = male;
	this->age = 0;
}
IdentityData::~IdentityData() {}
void IdentityData::set_FIO(string FIO)
{
	this->FIO = FIO;
};
void IdentityData::set_gender(Gender gender)
{
	this->gender = gender;
};
void IdentityData:: set_age(int age)
{
	this->age = age;
};
string IdentityData::get_FIO()
{
	return this->FIO;
};
Gender IdentityData::get_gender()
{
	return this->gender;
};
int IdentityData::get_age()
{
	return this->age;
};
void IdentityData::create_identity_data()
{
	cout << "  ������� ������� ����������:  ";
	set_FIO(check_string());
	cout << "  ������� ��� ����������(0-�������, 1-�������):  ";
	if (check_range(0, 1) == 0)
		set_gender(male);
	else
		set_gender(female);
	cout << "  ������� ������� ����������:  ";
	set_age(check_range(18, 60));
}
void IdentityData::print_identity_data()
{

}
string check_string()
{
	string FIO;
	while (1)
	{
		getline(cin, FIO);
		string wrong_symbols = "!@#$%^&*()_+=?:;�{}<>,.|/0123456789";
		int flag = 0;

		for (int i = 0; i < FIO.length(); i++)
		{
			for (int j = 0; j < wrong_symbols.length(); j++)
			{
				if (FIO[i] == wrong_symbols[j])
				{
					flag = 1;
					i = FIO.length();
					j = wrong_symbols.length();
				}
			}

		}
		if (flag == 1)
		{
			cout << "  ������ �����! ���������� ��� ���:  ";
		}
		else
		{
			return FIO;
			break;
		}
	}
}

int check_range(int bottom, int top)
{
	int range;
	while (1)
	{
		cin >> range;
		if (cin.fail() || range<bottom || range>top)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "  ������ �����! ���������� ��� ���:  ";
		}
		else
		{
			cin.ignore(32767, '\n');
			return range;
			break;
		}
	}
}