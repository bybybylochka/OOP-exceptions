#include<iostream>
#include<string>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include"header.h"
int menu()
{
	int n;
	cout << "1-������� ������ 1" << endl << "2-������� ������ 2" << endl << "3-���������� '+'" << endl
		<< "4-���������� '+='" << endl << "5-���������� '>'" << endl << "6-����� �� ���������" << endl;
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
	cout << "�������� ���������� �����..." << endl;
	cout << "������� ������:";
	char str[1000];
	cin.getline(str, 1000);
	object.string = new char[strlen(str) + 1];
	strcpy(object.string, str);
	object.length = strlen(object.string);
	return in;
}
ostream& operator<<(ostream& out, const String& object)
{
	cout << "�������� ���������� ������..." << endl;
	out << "�����:" << object.length << endl;
	out << "������:" << object.string << endl;
	cout << endl;
	return out;
}
String operator+(const String& object1, const String& object2)
{
	cout << "�������� ���������� ��������� +..." << endl;
	char* str = new char[strlen(object1.string) + strlen(object2.string) + 1];
	strcpy(str, object1.string);
	return String(strcat(str, object2.string));
}
String String::operator+=(const String& object)
{
	cout << "�������� ���������� ��������� +=..." << endl;
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
