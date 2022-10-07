#include<iostream>
#include<iomanip>
#include<fstream>
#include"Array.h"

using namespace std;

void OneDimensionalArray::set_size()
{
	cout << " Введите размер массива ( не больше 50 элементов): " << endl;
	while (1)
	{
		cin >> size;
		if (cin.fail() || size< MIN_ARRAY_SIZE || size > MAX_ARRAY_SIZE)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << " Ошибка ввода! Введите число от " << MIN_ARRAY_SIZE <<" до " << MAX_ARRAY_SIZE << ": ";
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
	cout << "\n Выберите способ ввода массива: " << endl << " 1-Вручную\n 2-Рандом\n\n Ваш выбор? ";
	int choice;
	while (1)
	{
		cin >> choice;
		if (cin.fail() || choice < 1 || choice > 2)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << " Ошибка ввода!\n Введите 1 для заполения массива вручную, 2-для рандомного заполнения: ";
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
			cout << "Элемент [" << i << "]: ";
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
			cout << " Ошибка ввода! Введите число от " << LEFT_ELEMENT_RANGE << " до " << RIGHT_ELEMENT_RANGE << ": ";
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
	cout << "\n Инициализация одномерного массива..." << endl;
	set_size();
	set_array();
	cout << " Одномерный массив успешно инициализирован! " << endl;
}

void OneDimensionalArray::get_data()
{
	cout << "\n Одномерный массив" << endl;
	cout << " Размер: " << get_size() << endl;
	get_array();
	cout << " Cреднее значение: " << setprecision(4) << get_average_value() << endl;
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
	cout << " Максимальный элемент массива : элемент[" << index<< "] = " << max << endl;
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
	cout << " Минимальный элемент массива : элемент[" << index << "] = " << min << endl;
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
		cout << " Массив отсортирован по возрастанию! " << endl;
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
		cout << " Массив отсортирован по убыванию! " << endl;
	}
	get_array();
}

void OneDimensionalArray::change_element()
{
	cout << " Введите порядковый номер элемента, который нужно изменить : ";
		int i;
		while (1)
		{
			cin >> i;
			if (cin.fail() || i<LEFT_RANGE_FOR_SIZE || i>size)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << " Ошибка ввода! Введите число от 1 до " << size << " : ";
			}
			else
			{
				cin.ignore(32767, '\n');
				break;
			}
		}
	cout << " Элемент [" << i << "] меняется с " << arr[i] << " на: ";
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
	else cout << " Не удалось открыть файл!" << endl;
	fout.close();
}

void OneDimensionalArray::menu()
{
	while (1)
	{
		cout << "\n 1-Отсортировать массив по возрастани\n 2-Отсортировать массив по убыванию\n 3-Найти максимальный элемент массива\n"
			" 4-найти минимальный элемент массива\n 5-Найти среднее арифметическое значение элементов массива\n 6-Поменять значение элемента\n 7-Выход\n";
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
		default: cout << " Ошибка ввода! Попробуйте еще раз: ";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		system("pause");
		system("cls");
	}
}