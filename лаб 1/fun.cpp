#include<iostream>
#include<string>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include"header.h"
using namespace std;

void Tile::input()      //������
{
	int i, flag1=0;
	bool flag=true;
	cout << "������� ����� ������:" << endl;
	cin >> brand;
	cout << "������� ���� ������:" << endl;
	while (flag)     //�������� �����
	{
		cin >> color;
		for (i = 0; i < color.length(); i++)
		{
			if(isdigit(color[i]))
			flag1 = 1;
		}
		if (cin.fail() || flag1==1 )
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �����! ������� �������� �����!" << endl;
			flag1 = 0;
		}
		else
		{
			flag = false;
			cin.ignore(32767, '\n');
		}
	}
	cout << "������� ������� ������:" << endl;
	cout << "������-";
	while (!flag)       //�������� �����
	{
		cin >> height;
		if (cin.fail() || height <=0)
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
	cout << endl << "���-";
	while (flag)      //�������� �����
	{
		cin >> weight;
		if (cin.fail() || weight <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �����! ������� ������������� �����!" << endl;
		}
		else
		{
			flag = false;
			cin.ignore(32767, '\n');
		}
	}
	cout << endl << "������� ���� ������:" << endl;
	while (!flag)         //�������� �����
	{
		cin >> price;
		if (cin.fail() || price <= 0)
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
	cout << "������� ���������� ������:" << endl;
	while (flag)       //�������� �����
	{
		cin >> quantity;
		if (cin.fail() || quantity <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �����! ������� ������������� �����!" << endl;
		}
		else
		{
			flag = false;
			cin.ignore(32767, '\n');
		}
	}
	total_price = price * quantity;
	cout << "����� ��������� ������:" << endl <<total_price << endl;
}

int menu()      //������� ����
{
	cout << "����:" << endl<<"1-������� ������\n2-�������� ������\n3-��������� ����� ���������\n4-����� �� ���������\n5-�������� ������ � ����\n";
	int choice;
	bool flag=false;
	while (!flag)       //�������� �����
	{
		cin >> choice;
		if (cin.fail() || choice < 1 || choice>5)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �����! ������� ����� �� 1 �� 5!" << endl;
		}
		else
		{
			flag = true;
			cin.ignore(32767, '\n');
		}
	}
	return choice;
}

void Tile::type_one()        //����� ��� ������ ������ ������� ������
{
	cout << setw(8) << brand << setw(11) << color << setw(13) << height << setw(10) << weight
		<< setw(11) << price << setw(17) << quantity << setw(23) << total_price << endl;
}
void type(Tile* tile, int kol)     //������� ��� ������ ������
{
	cout << "| ����� |   | ���� |   | ������ |   | ��� |   | ���� |   | ���������� |   | ����� ��������� |"<<endl;
	cout << "*********************************************************************************************"<<endl;
	int i;
	for (i = 0; i < kol; i++)
	{
		tile[i].type_one();
	}
}
void total_store(Tile* tile, int kol)        //������� ��� �������� �������� ��������� ������, ���������� �� ������
{
	int i, sum=0;
	for (i = 0; i < kol; i++)
	{
		sum += tile[i].get_total_store();
	}
	cout << "����� ��������� ������, ���������� �� ������:"<<endl<<sum << endl;
}
void Tile::change_brand()      //������� ��� �������������� ������ � ������
{
	std::string brand;
	cout << "������� ����� �������� ������" << endl;
	cin >> brand;
	this->brand = brand;
}

void Tile::change_color()       ////������� ��� �������������� ������ � �����
{
	std::string color;
	cout << "������� �������� �����" << endl;
	bool flag = false;
	int i, flag1 = 0;
	while (!flag)      //�������� �����
	{
		cin >> color;
		for (i = 0; i < color.length(); i++)
		{
			if (isdigit(color[i]))
			{
				flag1 = 1;
			}
		}
		if (cin.fail() || flag1 == 1)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �����!������� �������� �����!" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			flag = true;
		}
	}
	this->color = color;
}
void Tile::change_height()     //������� ��� �������������� ������ � ������
{
	int height;
	cout << "������� ����� ������" << endl;
	bool flag = false;
	while (!flag)        //�������� �����
	{
		cin >> height;
		if (cin.fail() || height < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �����! ������� ������������� �����!" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			flag = true;
		}
	}
	this->height= height;
}
void Tile::change_weight()       //������� ��� �������������� ������ � ����
{
	int weight;
	cout << "������� ����� ���" << endl;
	bool flag = false;
	while (!flag)       //�������� �����
	{
		cin >> weight;
		if (cin.fail() || weight < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �����! ������� ������������� �����!" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			flag = true;
		}
	}
	this->weight = weight;
}
void Tile::change_price()          //������� ��� �������������� ������ � ����
{
	int price;
	cout << "������� ����� ����" << endl;
	bool flag = false;
	while (!flag)      //�������� �����
	{
		cin >> price;
		if (cin.fail() || price < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �����! ������� ������������� �����!" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			flag = true;
		}
	}
		this->price = price;
		total_price = this->price * quantity;
		cout << "����� �������� �������� ����: " << total_price << endl;
}
void Tile::change_quantity()       //������� ��� �������������� ������ � ���������� 
{
	int quantity;
	cout << "������� ����� ����������" << endl;
	bool flag = false;
	while (!flag)       //�������� �����
	{
		cin >> quantity;
		if (cin.fail() || quantity < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �����! ������� ������������� �����!" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			flag = true;
		}
	}
	this->quantity = quantity;
	total_price = this->quantity * price;
	cout << "����� �������� �������� ����: " << total_price << endl;
}

void change_data(int kol, Tile* tile)        //������� ��� ������, ����� ������ ���������������
{
	int flag1= 0;
	std::string change_brand;
	cout << "������� �������� ������, ������ � ������� ������ ��������" << endl;
	cin >> change_brand;
	for (int i = 0; i < kol; i++)
	{
		if (change_brand == tile[i].get_brand())
		{
			flag1 = 1;
			cout << "��� �� ������ ��������?\n"
				"1-�������� �����\n"
				"2-�������� ����\n"
				"3-�������� ������\n"
				"4-�������� ���\n"
				"5-�������� ����\n"
				"6-�������� ����������\n";

			bool flag = false;
			int choice;
			while (!flag)     //�������� �����
			{
				cin >> choice;
				if (cin.fail() || choice < 1 || choice>6)
				{
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "������ �����\n" << endl;
				}
				else
				{
					flag = true;
					cin.ignore(32767, '\n');
				}
			}
			switch (choice)
			{
			case 1:tile[i].change_brand(); break;
			case 2:tile[i].change_color(); break;
			case 3:tile[i].change_height(); break;
			case 4:tile[i].change_weight(); break;
			case 5:tile[i].change_price(); break;
			case 6:tile[i].change_quantity(); break;
			case 0: return; break;
			default: cout << "�������� ��������! ������� ����� �� 0 �� 6!" << endl;
			}
		}
	}
	if (flag1 == 0)
		cout << "������ �� ���� ������ ���!" << endl;
}


void write_into_file(Tile* tile, int kol)       //������� ��� ������ ������ � ����
{
	int i;
	ofstream fout;
	fout.open("tile.txt", ofstream::app);
	if (!fout.is_open())
		cout << "���������� ������� ����" << endl;
	else
	{
		for (i = 0; i < kol; i++)
		{
			fout.write((char*)&tile[i], sizeof(Tile));
		}
		cout << "������ �������� � ����" << endl;
	}
}

	


