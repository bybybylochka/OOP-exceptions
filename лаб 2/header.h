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
		cout << "�������� ����������� �� ���������..." << endl;
		length = 1;
		string = new char[length + 1];
		strcpy(string, "0");
	}
	String(int length)
	{
		cout << "�������� ����������� � �����������(�����)..." << endl;
		this->length = length;
		string = new char[length + 1];
		strcpy(string, "hello!");
	}
	String(const char* temp_string)
	{
		cout << "�������� ����������� � �����������(������)..." << endl;
		length = strlen(temp_string);
		string = new char[length + 1];
		strcpy(string, temp_string);
	}
	String(const char* strings, int length)
	{
		cout << "�������� ����������� � �����������(������ � �����)..." << endl;
		string = new char[length + 1];
		strcpy(string, strings);
	}
	String(const String& str)
	{
		cout << "�������� ���������� �����������..." << endl;
		length = strlen(str.string);
		string = new char[length + 1];
		strcpy(string, str.string);
	}
	~String()
	{
		cout << "�������� ����������..." << endl;
		delete string;
	}
	std::string get_string()               //������ �������� ����� ������
	{
		cout << "������:";
		return string;
	}
	int get_length()
	{
		cout << "�����:";
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
