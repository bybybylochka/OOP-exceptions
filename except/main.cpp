#include<iostream>
#include<Windows.h>
#include"IdentityData.h"
#include"Employees.h"
#include"TVShow.h"

using namespace std;

int main() {
	Employees employee;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		set_terminate(my_terminate);
		cout << "\n 1 - Добавить работника телеканала" << endl << " 2 - Просмотреть данные о работниках телеканала" << endl
			<< " 3 - Собрать команду на телепередачу" << endl << " 4 - Выйти из программы" << endl;
		switch (check_range(1, 4))
		{
		case 1: employee.add_employee();
			break;
		case 2: employee.print_employees();
			break;
		case 3:
		{
			TVShow show(employee);
			show.create_TVShow();
			try { show.print_TVShow(); }
			catch (int)
			{
				cout << " К сожалению, собрать команду не удалось!" << endl;
			}
			break;
		}
		case 4: return 0; break;
		}
		system("pause");
		system("cls");
	}
}