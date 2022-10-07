#include<iostream>
#include"Array.h"
#include<Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Array* arrays[2];
	arrays[0] = new TwoDimensionalArray;
	arrays[1] = new OneDimensionalArray;
	while (1)
	{
		cout << "\n 1-���������������� ������� \n 2-������� ������ � �������� �� �����\n 3-�������� � ��������� ��������\n 4-�������� � ���������� ��������"
			"\n 5-�������� ������ � �������� � ����\n 6-�����" << endl;
		int choice;
		cin >> choice;
		cin.ignore(32767, '\n');
		switch (choice)
		{
		case 1:
		{
			for (int i = 0; i < AMOUNT_OF_ARRAYS; i++)
				arrays[i]->set_data();
			break;
		}
		case 2:
		{
			for (int i = 0; i < AMOUNT_OF_ARRAYS; i++)
				arrays[i]->get_data();
			break;
		}
		case 3: arrays[0]->menu(); break;
		case 4: arrays[1]->menu(); break;
		case 5:
		{
			for (int i = 0; i < AMOUNT_OF_ARRAYS; i++)
				arrays[i]->write_into_file();
			break;
		}
		case 6: return 0; break;
		default: cout << " ������ �����! ���������� ��� ���: " << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		system("pause");
		system("cls");
	}
}