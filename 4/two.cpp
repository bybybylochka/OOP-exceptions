#include<iostream>
#include<random>
#include<ctime>
#include<iomanip>
#include<fstream>
#include"Array.h"

using namespace std;


void TwoDimensionalArray::set_row_size()
{
	cout << " Введите количество строк матрицы: (не более 10)";
	while (1)
	{
		cin >> row_size;
		if (cin.fail() || row_size<LEFT_RANGE_FOR_SIZE || row_size>MAX_ROW_SIZE)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << " Ошибка ввода! Введите число от 1 до 10: ";
		}
		else
		{
			cin.ignore(32767, '\n');
			break;
		}
	}
}
void TwoDimensionalArray::set_column_size()
{
	cout << " Введите количество столбцов матрицы: (не более 10)";
	while (1)
	{
		cin >> column_size;
		if (cin.fail() || row_size<LEFT_RANGE_FOR_SIZE || row_size>MAX_COLUMN_SIZE)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << " Ошибка ввода! Введите число от 1 до 10: ";
		}
		else
		{
			cin.ignore(32767, '\n');
			break;
		}
	}
}

void TwoDimensionalArray::set_array()
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
	int i, j;
	matrix = new int* [row_size];
	for (i = 0; i < row_size; i++)
		matrix[i] = new int[column_size];
	if (choice == 2)
	{
		srand(time(NULL));
		for (i = 0; i < row_size; i++)
			for (j = 0; j < column_size; j++)
				matrix[i][j] = rand() % 30 - 10;
	}
	if (choice == 1)
	{
		for (i = 0; i < row_size; i++)
		{
			for (j = 0; j < column_size; j++)
			{
				cout << "Элемент [" << i << "][" << j << "]: ";
				set_matrix_element(i, j);
			}
		}
	}
}

void TwoDimensionalArray::set_matrix_element(int i, int j)
{
	while (1)
	{
		cin >> matrix[i][j];
		if (cin.fail() || matrix[i][j] < LEFT_ELEMENT_RANGE || matrix[i][j] > RIGHT_ELEMENT_RANGE)
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

int TwoDimensionalArray::get_row_size() { return this->row_size; }

int TwoDimensionalArray::get_column_size() { return this->column_size; }

void TwoDimensionalArray::get_array()
{
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < column_size; j++)
		{
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}
}

void TwoDimensionalArray::set_data()
{
	cout << "\n Инициализация двумерного массива..." << endl;
	set_row_size();
	set_column_size();
	set_array();
	cout << " Двумерный массив инициализирован успешно!" << endl;
}

void TwoDimensionalArray::get_data()
{
	cout << "\n Двумерный массив\n" << endl;
	cout << " Количество строк: " << get_row_size() << endl;
	cout << " Количество столбцов: " << get_column_size() << endl;
	get_array();
	cout << " Cреднее значение элементов матрицы: " << setprecision(4) << get_average_value() << endl;
	find_max();
	find_min();
}

double TwoDimensionalArray::get_average_value()
{
	int sum = 0;
	for (int i = 0; i < row_size; i++)
		for (int j = 0; j < column_size; j++)
			sum += matrix[i][j];

	int amount_of_elements = row_size * column_size;
	double average_value = double(sum) / amount_of_elements;
	return average_value;
}

void TwoDimensionalArray::find_max()
{
	int max = matrix[0][0];
	int index_I = 0, index_J = 0;
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < column_size; j++)
		{
			if (max < matrix[i][j])
			{
				max = matrix[i][j];
				index_I = i;
				index_J = j;
			}
		}
	}
	cout << " Максимальный элемент матрицы: элемент[" << index_I << "][" << index_J << "]=" << max << endl;
}

void TwoDimensionalArray::find_min()
{
	int min = matrix[0][0];
	int index_I = 0, index_J = 0;
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < column_size; j++)
		{
			if (min > matrix[i][j])
			{
				min = matrix[i][j];
				index_I = i;
				index_J = j;
			}
		}
	}
	cout << " Минимальный элемент матрицы: элемент[" << index_I << "][" << index_J << "]=" << min << endl;
}


void TwoDimensionalArray::sort_array(bool sort_type)
{
	if (sort_type)
	{
		for (int k = 0; k < (row_size * column_size - 1); k++)
		{
			for (int i = 0; i < row_size; i++)
			{
				for (int j = 0; j < column_size - 1; j++)
				{
					if (matrix[i][j] > matrix[i][j + 1])
					{
						int temp = matrix[i][j];
						matrix[i][j] = matrix[i][j + 1];
						matrix[i][j + 1] = temp;
					}
				}
			}
		}
		cout << " Cтроки двумерного массива отсортированы по возрастанию!" << endl;
	}
	else
	{
		for (int k = 0; k < (row_size * column_size - 1); k++)
		{
			for (int i = 0; i < row_size; i++)
			{
				for (int j = 0; j < column_size - 1; j++)
				{
					if (matrix[i][j] < matrix[i][j + 1])
					{
						int temp = matrix[i][j];
						matrix[i][j] = matrix[i][j + 1];
						matrix[i][j + 1] = temp;
					}
				}
			}
		}
		cout << " Строки двумерного массива отсортированы по убыванию!" << endl;
	}
	get_array();
}

void TwoDimensionalArray::change_first_negative_with_first()
{
	get_array();
	for (int i = 0; i < row_size; i++)
	{
		bool flag = false;
		for (int j = 0; j < column_size; j++)
		{
			if (matrix[i][j] < 0)
			{
				int temp = matrix[i][0];
				matrix[i][0] = matrix[i][j];
				matrix[i][j] = temp;
				flag = true;
				break;
			}
		}
		if (flag)
			cout << " Cтрока " << i + 1 << ": замена произведена успешно" << endl;
		else
			cout << " Cтрока " << i + 1 << ": нет отрицательных элементов" << endl;
	}
	get_array();
}

void TwoDimensionalArray::set_row_and_column_to_zero()
{
	get_array();
	cout << endl;
	int min = matrix[0][0];
	int index_I = 0, index_J = 0;
	int i, j;
	for (i = 0; i < row_size; i++)
	{
		for (j = 0; j < column_size; j++)
		{
			if (min > matrix[i][j])
			{
				min = matrix[i][j];
				index_I = i;
				index_J = j;
			}
		}
	}
	for (j = 0; j < column_size; j++)
		matrix[index_I][j] = 0;
	for (i = 0; i < row_size; i++)
		matrix[i][index_J] = 0;
	get_array();
}

void TwoDimensionalArray::change_element()
{
	int i;
	cout << " Введите строку изменяемого элемента: ";
	while (1)
	{
		cin >> i;
		if (cin.fail() || i<LEFT_RANGE_FOR_SIZE || i>row_size)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << " Ошибка ввода! Введите число от 1 до " << row_size << " : ";
		}
		else
		{
			cin.ignore(32767, '\n');
			break;
		}
	}
	int j;
	cout << " Введите столбец изменяемого элемента: ";
	while (1)
	{
		cin >> j;
		if (cin.fail() || j<LEFT_RANGE_FOR_SIZE || j>column_size)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << " Ошибка ввода! Введите число от 1 до " << column_size << " : ";
		}
		else
		{
			cin.ignore(32767, '\n');
			break;
		}
	}
	cout << " Элемент [" << i << "][" << j << "] меняется с " << matrix[i][j] << " на: ";
	set_matrix_element(i, j);
}

void TwoDimensionalArray::write_into_file()
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

void TwoDimensionalArray::menu()
{
	while (1)
	{
		cout << "\n 1-Отсортировать массив по возрастанию\n 2-Отсортировать массив по убыванию\n 3-Найти максимальный элемент массива\n"
			" 4-найти минимальный элемент массива\n 5-Найти среднее арифметическое значение элементов массива\n 6-Поменять значение элемента\n"
			" 7-Поменять в каждой строке первый элемент с первым отрицательным\n 8-Обнулить строку и столбец с минимальным элементом\n 9-Выход\n";
		int choice;
		cin >> choice;
		cin.ignore(32767, '\n');
		switch (choice)
		{
		case 1: sort_array(true); break;
		case 2: sort_array(false); break;
		case 3: find_max(); break;
		case 4: find_min(); break;
		case 5: cout << " Среднее значение элементов массива равно " << get_average_value() << endl; break;
		case 6: change_element(); break;
		case 7: change_first_negative_with_first(); break;
		case 8: set_row_and_column_to_zero(); break;
		case 9: return; break;
		default: cout << " Ошибка ввода! Попробуйте еще раз: ";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		system("pause");
		system("cls");
	}
}
