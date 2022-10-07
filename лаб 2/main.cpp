/*Создать класс String для работы со строками.Создать методы
доступа к полям класса.Перегрузить в этом классе операторы « += »
(добавить в конец), « + »(конкатенации), « > » сравнивания длин строк.
Реализовать конструкторы(по умолчанию, с параметрами, копирования),
деструктор.Реализовать friend - функции для операторов ввода / вывода в поток
для созданного класса.
*/
#include<iostream>
#include<Windows.h>
#include"header.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "КОНСТРУКТОРЫ" << endl;
	String string1;                        //Реализация конструктора по умолчанию
	cout << string1.get_length() << endl;
	cout << string1.get_string() << endl << endl;
	String string2(7);                     //Реализация конструктора с параметром длины
	cout << string2.get_length() << endl;
	cout << string2.get_string() << endl << endl;
	String string3(string2);               //Реализация конструктора копирования
	cout << string3.get_length() << endl;
	cout << string3.get_string() << endl << endl << endl;
	cout << "ПЕРЕГРУЗКИ ОПЕРАТОРОВ" << endl;
	cout << "Объект 1:" << endl;
	String object1;
	cin >> object1;                         //Перегрузка ввода
	cout << object1;                        //Перегрузка вывода
	cout << "Объект 2:" << endl;
	char* temp_string = new char[1000];     //Временная переменная для передачи параметра в конструктор
	cout << "Введите строку:";
	cin.getline(temp_string, 1000);
	String object2(temp_string);
	delete[] temp_string;
	cout << object2;                        //Перегрузка вывода
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
				cout << "Объект 1 больше объекта 2" << endl;
			else
				cout << "Объект 1 меньше либо равно объекта 2" << endl;
		}
		break;
		case 6:
			return 0;
			break;
		default: cout << "Неверное значение! Попробуйте еще раз!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			break;
		}
	}
	return 0;
}
