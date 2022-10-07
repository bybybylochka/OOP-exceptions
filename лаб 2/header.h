#pragma once
#include<string>
using namespace std;
#pragma warning (disable:4996)
class String
{
	char* string;
	int length;
public:
	String()
	{
		cout << "Работает конструктор по умолчанию..." << endl;
		length = 1;
		string = new char[length + 1];
		strcpy(string, "0");
	}
	String(int length)
	{
		cout << "Работает конструктор с параметрами(длина)..." << endl;
		this->length = length;
		string = new char[length + 1];
		strcpy(string, "hello!");
	}
	String(const char* temp_string)
	{
		cout << "Работает конструктор с параметрами(строка)..." << endl;
		length = strlen(temp_string);
		string = new char[length + 1];
		strcpy(string, temp_string);
	}
	String(const char* strings, int length)
	{
		cout << "Работает конструктор с параметрами(строка и длина)..." << endl;
		string = new char[length + 1];
		strcpy(string, strings);
	}
	String(const String& str)
	{
		cout << "Работает коструктор копирования..." << endl;
		length = strlen(str.string);
		string = new char[length + 1];
		strcpy(string, str.string);
	}
	~String()
	{
		cout << "Работает деструктор..." << endl;
		delete string;
	}
	std::string get_string()               //Методы доступак полям класса
	{
		cout << "Строка:";
		return string;
	}
	int get_length()
	{
		cout << "Длина:";
		return length;
	}
	void type_one();
	friend istream& operator>>(istream& in, String& object);
	friend ostream& operator<<(ostream& out, const String& object);
	friend String operator+(const String& object1, const String& object2);
	String operator+=(const String&);
	friend bool operator>(const String&, const String&);
};
int menu();
