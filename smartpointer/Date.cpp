#include "Date.h"
#include"ItSpesialist.h"
#include<iostream>
using namespace std;

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 2000;
}
void Date::set_day(int day)
{
	this->day = day;
}
void Date::set_month(int month)
{
	this->month = month;
}
void Date::set_year(int year)
{
	this->year = year;
}
int Date::get_day()
{
	return this->day;
}
int Date::get_month()
{
	return this->month;
}
int Date::get_year()
{
	return this->year;
}
void Date::create_date()
{
	cout << "  ¬ведите день приема:  ";
	set_day(check_range(1, 31));
	cout << "  ¬ведите мес€ц приема:  ";
	set_month(check_range(1, 12));
	cout << "  ¬ведите год приема:  ";
	set_year(check_range(2000, 2022));
}