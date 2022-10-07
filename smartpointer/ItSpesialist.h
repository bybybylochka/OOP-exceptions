#pragma once
#include<string>
#include<fstream>
#include "Date.h"

using namespace std;

enum Level
{
	junior,
	middle,
	senior
};

class ItSpecialist
{
protected:
	string code;
	string FIO;
	int age;
	Date date_of_admission;
	Level level;
	float salary;
public:
	ItSpecialist();
	ItSpecialist(const ItSpecialist& obj);
	void set_code(string);
	void set_FIO(string FIO);
	void set_age(int age);
	void set_admission_date();
	void set_level(Level level);
	void set_salary(float salary);
	string get_code();
	string get_FIO();
	int get_age();
	Date get_admission_date();
	Level get_level();
	float get_salary();
	string level_to_string();
	virtual void create_data();
	string generate_code(string position, string type);
	void print_data();
	void write(ofstream& fout);
	void read(ifstream& fin);
};
string check_string();
template <class T>
T check_range(T bottom, T top); 

Level check_level();