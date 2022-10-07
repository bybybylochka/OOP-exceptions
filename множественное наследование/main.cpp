#include<iostream>
#include<Windows.h>
#include"Header.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "  Добро пожаловать!  " << endl;
	WebDeveloperArray array_of_developers;
	while (1)
	{
		switch (main_menu())
		{
		case 1: array_of_developers.add_form();
			break;
		case 2: 
			array_of_developers.sort_forms();
			array_of_developers.print_forms();
			break;
		case 3: 
			return 0;
			break; 
		}
		system("pause");
		system("cls");
	}
}