/*������� ����� String ��� ������ �� ��������.������� ������
������� � ����� ������.����������� � ���� ������ ��������� � += �
(�������� � �����), � + �(������������), � > � ����������� ���� �����.
����������� ������������(�� ���������, � �����������, �����������),
����������.����������� friend - ������� ��� ���������� ����� / ������ � �����
��� ���������� ������.
*/
#include<iostream>
#include<Windows.h>
#include"header.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������������" << endl;
	String string1;                        //���������� ������������ �� ���������
	cout << string1.get_length() << endl;
	cout << string1.get_string() << endl << endl;
	String string2(7);                     //���������� ������������ � ���������� �����
	cout << string2.get_length() << endl;
	cout << string2.get_string() << endl << endl;
	String string3(string2);               //���������� ������������ �����������
	cout << string3.get_length() << endl;
	cout << string3.get_string() << endl << endl << endl;
	cout << "���������� ����������" << endl;
	cout << "������ 1:" << endl;
	String object1;
	cin >> object1;                         //���������� �����
	cout << object1;                        //���������� ������
	cout << "������ 2:" << endl;
	char* temp_string = new char[1000];     //��������� ���������� ��� �������� ��������� � �����������
	cout << "������� ������:";
	cin.getline(temp_string, 1000);
	String object2(temp_string);
	delete[] temp_string;
	cout << object2;                        //���������� ������
	while (1)
	{
		switch (menu())
		{
		case 1:cout << object1;
			break;
		case 2:
			cout << object2;
			break;
		case 3:
		{
			String object3 = object1 + object2;
			cout << object3;
		}
		break;
		case 4:
		{
			object1 += object2;
			cout << object1;
		}
		break;
		case 5:
		{
			if (object1 > object2)
				cout << "������ 1 ������ ������� 2" << endl;
			else
				cout << "������ 1 ������ ���� ����� ������� 2" << endl;
		}
		break;
		case 6:
			return 0;
			break;
		default: cout << "�������� ��������! ���������� ��� ���!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			break;
		}
	}
	return 0;
}
