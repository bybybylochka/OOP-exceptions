#include<iostream>
#include<iomanip>
#include<fstream>
#include"Array.h"

using namespace std;

void OneDimensionalArray::set_size()
{
	cout << " ������� ������ ������� ( �� ������ 50 ���������): " << endl;
	while (1)
	{
		cin >> size;
		if (cin.fail() || size< MIN_ARRAY_SIZE || size > MAX_ARRAY_SIZE)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << " ������ �����! ������� ����� �� " << MIN_ARRAY_SIZE <<" �� " << MAX_ARRAY_SIZE << ": ";
		}
		else
		{
			cin.ignore(32767, '\n');
			break;
		}
	}
}

void OneDimensionalArray::set_array()
{
	cout << "\n �������� ������ ����� �������: " << endl << " 1-�������\n 2-������\n\n ��� �����? ";
	int choice;
	while (1)
	{
		cin >> choice;
		if (cin.fail() || choice < 1 || choice > 2)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << " ������ �����!\n ������� 1 ��� ��������� ������� �������, 2-��� ���������� ����������: ";
		}
		else
		{
			cin.ignore(32767, '\n');
			break;
		}
	}
	arr = new int[size];
	if (choice == 2)
	{
		srand(time(NULL));
		for (int i = 0; i < size; i++)
			arr[i] = rand() % 30 - 10;
	}
	if (choice == 1)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "������� [" << i << "]: ";
			set_array_element(i);
		}
	}
}

void OneDimensionalArray::set_array_element(int i)
{
	while (1)
	{
		cin >> arr[i];
		if (cin.fail() || arr[i] < LEFT_ELEMENT_RANGE || arr[i] > RIGHT_ELEMENT_RANGE)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << " ������ �����! ������� ����� �� " << LEFT_ELEMENT_RANGE << " �� " << RIGHT_ELEMENT_RANGE << ": ";
		}
		else
		{
			cin.ignore(32767, '\n');
			break;
		}
	}
}

int OneDimensionalArray::get_size() { return this->size; }

void OneDimensionalArray::get_array()
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << arr[i];
	cout << endl;
}

void OneDimensionalArray::set_data()
{
	cout << "\n ������������� ����������� �������..." << endl;
	set_size();
	set_array();
	cout << " ���������� ������ ������� ���������������! " << endl;
}

void OneDimensionalArray::get_data()
{
	cout << "\n ���������� ������" << endl;
	cout << " ������: " << get_size() << endl;
	get_array();
	cout << " C������ ��������: " << setprecision(4) << get_average_value() << endl;
	find_max();
	find_min();
}

double OneDimensionalArray::get_average_value()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	double average_value = (double)sum / size;
	return average_value;
}

void OneDimensionalArray::find_max()
{
	int i, index = 0;
	int max = arr[0];
	for (i = 0; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}
	cout << " ������������ ������� ������� : �������[" << index<< "] = " << max << endl;
}

void OneDimensionalArray::find_min()
{
	int i, index = 0;
	int min = arr[0];
	for (i = 0; i < size; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			index = i;
		}
	}
	cout << " ����������� ������� ������� : �������[" << index << "] = " << min << endl;
}

void OneDimensionalArray::sort_array(bool sort_type)
{
	if (sort_type)
	{
		int i, j;
		int gap;
		int flag;
		for (gap = size / 2; gap > 0; gap /= 2)
		{
			do
			{
				flag = 0;
				for (i = 0, j = gap; j < size; i++, j++)
				{
					if (arr[i] > arr[i + gap])
					{
						int temp = arr[i];
						arr[i] = arr[i + gap];
						arr[i + gap] = temp;
						flag = 1;
					}
				}
			} while (flag);
		}
		cout << " ������ ������������ �� �����������! " << endl;
	}
	else
	{
		int i, j;
		int gap;
		int flag;
		for (gap = size / 2; gap > 0; gap /= 2)
		{
			do
			{
				flag = 0;
				for (i = 0, j = gap; j < size; i++, j++)
				{
					if (arr[i] < arr[i + gap])
					{
						int temp = arr[i];
						arr[i] = arr[i + gap];
						arr[i + gap] = temp;
						flag = 1;
					}
				}
			} while (flag);
		}
		cout << " ������ ������������ �� ��������! " << endl;
	}
	get_array();
}

void OneDimensionalArray::change_element()
{
	cout << " ������� ���������� ����� ��������, ������� ����� �������� : ";
		int i;
		while (1)
		{
			cin >> i;
			if (cin.fail() || i<LEFT_RANGE_FOR_SIZE || i>size)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << " ������ �����! ������� ����� �� 1 �� " << size << " : ";
			}
			else
			{
				cin.ignore(32767, '\n');
				break;
			}
		}
	cout << " ������� [" << i << "] �������� � " << arr[i] << " ��: ";
	set_array_element(i);
}

void OneDimensionalArray::write_into_file()
{
	ofstream fout;
	fout.open("arrays.dat", ios::binary);
	if (fout.is_open())
	{
		fout.write((char*)this, sizeof(*this));
	}
	else cout << " �� ������� ������� ����!" << endl;
	fout.close();
}

void OneDimensionalArray::menu()
{
	while (1)
	{
		cout << "\n 1-������������� ������ �� ����������\n 2-������������� ������ �� ��������\n 3-����� ������������ ������� �������\n"
			" 4-����� ����������� ������� �������\n 5-����� ������� �������������� �������� ��������� �������\n 6-�������� �������� ��������\n 7-�����\n";
		int choice;
		cin >> choice;
		cin.ignore(32767, '\n');
		switch (choice)
		{
		case 1: sort_array(true); break;
		case 2: sort_array(false); break;
		case 3: find_max(); break;
		case 4: find_min(); break;
		case 5: get_average_value(); break;
		case 6: change_element(); break;
		case 7: return; break;
		default: cout << " ������ �����! ���������� ��� ���: ";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		system("pause");
		system("cls");
	}
}