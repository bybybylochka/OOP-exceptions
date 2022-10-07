/*Создать класс Tile(плитка), который будет содержать поля brand,
height, weight, price, quantity и методы работы с полями класса.Создать
массив объектов созданного класса, заполнить объекты данными.Посчитать
общую стоимость хранящейся на складе плитки.В класс добавить
необходимый набор полей и методов(минимум два поля и два метода) на
свое усмотрение.Использовать конструктор с параметрами, конструктор без
параметров, конструктор копирования.Предусмотреть метод для записи
полученных данных в файл.*/
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
	cout << "Введите количество записей, которое хотите ввести" << endl;
	while (!flag)                     //Проверка ввода
	{
		cin >> amount;
		if (cin.fail() || amount <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода! Введите положительное число!" << endl;
		}
		else
		{
			flag = true;
			cin.ignore(32767, '\n');
		}
	}
	Tile* store = new Tile[amount];
	int i;
	for (i = 0; i < amount; i++)         //ввод массива объектов
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
