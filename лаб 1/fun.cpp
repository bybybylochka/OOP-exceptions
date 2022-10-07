#include<iostream>
#include<string>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include"header.h"
using namespace std;

void Tile::input()      //сеттер
{
	int i, flag1=0;
	bool flag=true;
	cout << "Введите бренд плитки:" << endl;
	cin >> brand;
	cout << "Введите цвет плитки:" << endl;
	while (flag)     //проверка ввода
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
			cout << "Ошибка ввода! Введите название цвета!" << endl;
			flag1 = 0;
		}
		else
		{
			flag = false;
			cin.ignore(32767, '\n');
		}
	}
	cout << "Введите размеры плитки:" << endl;
	cout << "Высота-";
	while (!flag)       //проверка ввода
	{
		cin >> height;
		if (cin.fail() || height <=0)
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
	cout << endl << "Вес-";
	while (flag)      //проверка ввода
	{
		cin >> weight;
		if (cin.fail() || weight <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода! Введите положительное число!" << endl;
		}
		else
		{
			flag = false;
			cin.ignore(32767, '\n');
		}
	}
	cout << endl << "Введите цену плитки:" << endl;
	while (!flag)         //проверка ввода
	{
		cin >> price;
		if (cin.fail() || price <= 0)
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
	cout << "Введите количество плитки:" << endl;
	while (flag)       //проверка ввода
	{
		cin >> quantity;
		if (cin.fail() || quantity <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода! Введите положительное число!" << endl;
		}
		else
		{
			flag = false;
			cin.ignore(32767, '\n');
		}
	}
	total_price = price * quantity;
	cout << "Общая стоимость плитки:" << endl <<total_price << endl;
}

int menu()      //функция меню
{
	cout << "Меню:" << endl<<"1-вывести данные\n2-изменить данные\n3-посчитать общую стоимость\n4-выйти из программы\n5-записать данные в файл\n";
	int choice;
	bool flag=false;
	while (!flag)       //проверка ввода
	{
		cin >> choice;
		if (cin.fail() || choice < 1 || choice>5)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода! Введите число от 1 до 5!" << endl;
		}
		else
		{
			flag = true;
			cin.ignore(32767, '\n');
		}
	}
	return choice;
}

void Tile::type_one()        //метод для вывода одного обьекта класса
{
	cout << setw(8) << brand << setw(11) << color << setw(13) << height << setw(10) << weight
		<< setw(11) << price << setw(17) << quantity << setw(23) << total_price << endl;
}
void type(Tile* tile, int kol)     //функция для вывода данных
{
	cout << "| Бренд |   | Цвет |   | Высота |   | Вес |   | Цена |   | Количество |   | Общая стоимость |"<<endl;
	cout << "*********************************************************************************************"<<endl;
	int i;
	for (i = 0; i < kol; i++)
	{
		tile[i].type_one();
	}
}
void total_store(Tile* tile, int kol)        //функция для подсчета итоговой стоимости плитки, хранящейся на складе
{
	int i, sum=0;
	for (i = 0; i < kol; i++)
	{
		sum += tile[i].get_total_store();
	}
	cout << "Общая стоимость плитки, хранящейся на складе:"<<endl<<sum << endl;
}
void Tile::change_brand()      //функция для редактирования данных о бренде
{
	std::string brand;
	cout << "Введите новое название бренда" << endl;
	cin >> brand;
	this->brand = brand;
}

void Tile::change_color()       ////функция для редактирования данных о цвете
{
	std::string color;
	cout << "Введите название цвета" << endl;
	bool flag = false;
	int i, flag1 = 0;
	while (!flag)      //проверка ввода
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
			cout << "Ошибка ввода!Введите название цвета!" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			flag = true;
		}
	}
	this->color = color;
}
void Tile::change_height()     //функция для редактирования данных о высоте
{
	int height;
	cout << "Введите новую высоту" << endl;
	bool flag = false;
	while (!flag)        //проверка ввода
	{
		cin >> height;
		if (cin.fail() || height < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода! Введите положительное число!" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			flag = true;
		}
	}
	this->height= height;
}
void Tile::change_weight()       //функция для редактирования данных о весе
{
	int weight;
	cout << "Введите новый вес" << endl;
	bool flag = false;
	while (!flag)       //проверка ввода
	{
		cin >> weight;
		if (cin.fail() || weight < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода! Введите положительное число!" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			flag = true;
		}
	}
	this->weight = weight;
}
void Tile::change_price()          //функция для редактирования данных о цене
{
	int price;
	cout << "Введите новую цену" << endl;
	bool flag = false;
	while (!flag)      //проверка ввода
	{
		cin >> price;
		if (cin.fail() || price < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода! Введите положительное число!" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			flag = true;
		}
	}
		this->price = price;
		total_price = this->price * quantity;
		cout << "Новое значение итоговой цены: " << total_price << endl;
}
void Tile::change_quantity()       //функция для редактирования данных о количестве 
{
	int quantity;
	cout << "Введите новое количество" << endl;
	bool flag = false;
	while (!flag)       //проверка ввода
	{
		cin >> quantity;
		if (cin.fail() || quantity < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода! Введите положительное число!" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			flag = true;
		}
	}
	this->quantity = quantity;
	total_price = this->quantity * price;
	cout << "Новое значение итоговой цены: " << total_price << endl;
}

void change_data(int kol, Tile* tile)        //функция для выбора, какие данные отредактировать
{
	int flag1= 0;
	std::string change_brand;
	cout << "Введите название бренда, данные о котором хотите изменить" << endl;
	cin >> change_brand;
	for (int i = 0; i < kol; i++)
	{
		if (change_brand == tile[i].get_brand())
		{
			flag1 = 1;
			cout << "Что вы хотите изменить?\n"
				"1-изменить бренд\n"
				"2-изменить цвет\n"
				"3-изменить высоту\n"
				"4-изменить вес\n"
				"5-изменить цену\n"
				"6-изменить количество\n";

			bool flag = false;
			int choice;
			while (!flag)     //проверка ввода
			{
				cin >> choice;
				if (cin.fail() || choice < 1 || choice>6)
				{
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Ошибка ввода\n" << endl;
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
			default: cout << "Неверное значение! Введите цифру от 0 до 6!" << endl;
			}
		}
	}
	if (flag1 == 0)
		cout << "Данных об этом бренде нет!" << endl;
}


void write_into_file(Tile* tile, int kol)       //функция для записи данных в файл
{
	int i;
	ofstream fout;
	fout.open("tile.txt", ofstream::app);
	if (!fout.is_open())
		cout << "Невозможно открыть файл" << endl;
	else
	{
		for (i = 0; i < kol; i++)
		{
			fout.write((char*)&tile[i], sizeof(Tile));
		}
		cout << "Данные записаны в файл" << endl;
	}
}

	


