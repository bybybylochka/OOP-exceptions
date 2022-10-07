/*������� ����� Tile(������), ������� ����� ��������� ���� brand,
height, weight, price, quantity � ������ ������ � ������ ������.�������
������ �������� ���������� ������, ��������� ������� �������.���������
����� ��������� ���������� �� ������ ������.� ����� ��������
����������� ����� ����� � �������(������� ��� ���� � ��� ������) ��
���� ����������.������������ ����������� � �����������, ����������� ���
����������, ����������� �����������.������������� ����� ��� ������
���������� ������ � ����.*/
#include<iostream>
#include<Windows.h>
#include<iomanip>
#include"header.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int amount;
	bool flag=false;
	cout << "������� ���������� �������, ������� ������ ������" << endl;
	while (!flag)                     //�������� �����
	{
		cin >> amount;
		if (cin.fail() || amount <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �����! ������� ������������� �����!" << endl;
		}
		else
		{
			flag = true;
			cin.ignore(32767, '\n');
		}
	}
	Tile* store = new Tile[amount];
	int i;
	for (i = 0; i < amount; i++)         //���� ������� ��������
	{
		store[i].input();
	}
	while (1)
	{
		switch (menu())
		{
		case 1:
			type(store, amount); 
			break;
		case 2: change_data(amount, store);
			break;
		case 3:
			total_store(store, amount);
			break;
		case 4: ; return 0;
			break;
		case 5: write_into_file(store, amount); 
			break;
		}
	}
	delete[] store;
	return 0;
}
