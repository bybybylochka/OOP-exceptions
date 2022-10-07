#include "ItSpesialist.h"
#include<iostream>
#include<iomanip>
using namespace std;

ItSpecialist::ItSpecialist()
{
	this->code = "no code";
	this->FIO = "no data";
	this->age = 0;
	Date date_of_admission;
	this->date_of_admission = date_of_admission;
	this->level = junior;
}

void ItSpecialist::set_FIO(string FIO)
{
	this->FIO = FIO;
}

void ItSpecialist::set_age(int age)
{
	this->age = age;
}

void ItSpecialist::set_admission_date()
{
	date_of_admission.create_date();
}

void ItSpecialist::set_level(Level level)
{
	this->level = level;
}

void ItSpecialist::set_salary(float salary)
{
	this->salary = salary;
}

string ItSpecialist::get_FIO()
{
	return this->FIO;
}

int ItSpecialist::get_age()
{
	return this->age;
}

Date ItSpecialist::get_admission_date()
{
	return this->date_of_admission;
}

Level ItSpecialist::get_level()
{
	return this->level;
}

float ItSpecialist::get_salary()
{
	return this->salary;
}

string ItSpecialist::level_to_string() {
	switch (this->level)
	{
	case junior: return "junior"; 
		break;
	case middle: return "middle";
		break;
	case senior: return "senior";
		break;
	}
}

ItSpecialist::ItSpecialist(const ItSpecialist& obj)
{
	this->code = obj.code;
	this->FIO = obj.FIO;
	this->age = obj.age;
	this->date_of_admission = obj.date_of_admission;
	this->level = obj.level;
	this->salary = obj.salary;
}

void ItSpecialist::create_data()
{
	cout << "  Введите ФИО сотрудника:  ";
	set_FIO(check_string());
	cout << "  Введите возраст сотрудника:  ";
	set_age(check_range(16, 60));
	cout << "  Введите дату приема на работу:  ";
	set_admission_date();
	cout << "  Введите уровень сотрудника (1-junior, 2-middle, 3-senior):  ";
	set_level(check_level());
	cout << "  Введите среднюю зарплату сотрудника($):  ";
	set_salary(check_range(1.00, 15000.00));
}
string check_string()
{
	string FIO;
	while (1)
	{
		getline(cin, FIO);
		string wrong_symbols = "!@#$%^&*()_+=?:;№{}<>,.|/0123456789";
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
			cout << "  Ошибка ввода! Попробуйте еще раз:  ";
		}
		else
		{
			return FIO;
			break;
		}
	}
}
template <class T>
T check_range(T bottom, T top)
{
	T range;
	while (1)
	{
		cin >> range;
		if (cin.fail() || range<bottom || range>top)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "  Ошибка ввода! Попробуйте еще раз:  ";
		}
		else
		{
			cin.ignore(32767, '\n');
			return range;
			break;
		}
	}
}
Level check_level()
{
	switch (check_range(1, 3))
	{
	case 1: return junior;
		break;
	case 2: return middle;
		break;
	case 3: return senior;
		break;
	}
}

string ItSpecialist::generate_code(string position, string type)
{
	srand(time(NULL));
	string code = position;
	code = code + "-" + type;
	int digit_code = rand() % 900 + 100;
	code = code + "-"+to_string(digit_code);
	return code;
}

void ItSpecialist::set_code(string code)
{
	this->code = code;
}
string ItSpecialist::get_code()
{
	return this->code;
}

void ItSpecialist::print_data()
{
	cout << "|" << setw(13) << this->code << "|" << setw(33) << this->FIO << "|" << setw(9) << this->age << "|" << setw(8) << 
		this->date_of_admission.get_day() <<"/"<< this->date_of_admission.get_month()<<"/"<< this->date_of_admission.get_year()<<
		"|" << setw(11) << this->level_to_string() << "|" << setw(12) << this->salary << "|" << endl;
}

void ItSpecialist::write(ofstream& fout)
{
	fout << code << endl << FIO << endl << age << endl
		<< date_of_admission.get_day() << endl << date_of_admission.get_month() << endl
		<< date_of_admission.get_year() << endl << level << endl << salary << endl;
}

void ItSpecialist::read(ifstream& fin)
{
	string temp_str;
	getline(fin, temp_str);
	getline(fin, temp_str);
	set_code(temp_str);
	temp_str.clear();
	getline(fin, temp_str);
	set_FIO(temp_str);
	temp_str.clear();
	fin >> age;
	int temp_int;
	fin >> temp_int;
	date_of_admission.set_day(temp_int);
	fin >> temp_int;
	date_of_admission.set_month(temp_int); 
	fin >> temp_int;
	date_of_admission.set_year(temp_int);
	fin >> temp_int;
	set_level((Level)temp_int);
	fin >> salary;

}