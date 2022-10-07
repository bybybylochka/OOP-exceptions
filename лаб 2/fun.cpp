#include<iostream>
#include<string>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include"header.h"
int menu()
{
	int n;
	cout << "1-вывести объект 1" << endl << "2-вывести объект 2" << endl << "3-перегрузка '+'" << endl
		<< "4-перегрузка '+='" << endl << "5-перегрузка '>'" << endl << "6-выход из программы" << endl;
	cin >> n;
	cin.ignore(32767, '\n');
	return n;
}
void String::type_one()
{
	cout << string << endl;
}
istream& operator>>(istream& in, String& object)
{
	cout << "Работает перегрузка ввода..." << endl;
	cout << "Введите строку:";
	char str[1000];
	cin.getline(str, 1000);
	object.string = new char[strlen(str) + 1];
	strcpy(object.string, str);
	object.length = strlen(object.string);
	return in;
}
ostream& operator<<(ostream& out, const String& object)
{
	cout << "Работает перегрузка вывода..." << endl;
	out << "Длина:" << object.length << endl;
	out << "Строка:" << object.string << endl;
	cout << endl;
	return out;
}
String operator+(const String& object1, const String& object2)
{
	cout << "Работает перегрузка оператора +..." << endl;
	char* str = new char[strlen(object1.string) + strlen(object2.string) + 1];
	strcpy(str, object1.string);
	return String(strcat(str, object2.string));
}
String String::operator+=(const String& object)
{
	cout << "Работает перегрузка оператора +=..." << endl;
	length += strlen(object.string);
	string = (char*)realloc(string, length + 1);
	return String(strcat(string, object.string));
}
bool operator>(const String& object1, const String& object2)
{
	if (strlen(object1.string) > strlen(object2.string))
		return true;
	else
		return false;
}
