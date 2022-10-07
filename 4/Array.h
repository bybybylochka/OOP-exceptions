#pragma once
const int MAX_ROW_SIZE = 10;
const int MAX_COLUMN_SIZE = 10;
const int MIN_ARRAY_SIZE = 1;
const int MAX_ARRAY_SIZE = 50;
const int LEFT_RANGE_FOR_SIZE = 0;
const int LEFT_ELEMENT_RANGE = -100;
const int RIGHT_ELEMENT_RANGE = 100;
const int AMOUNT_OF_ARRAYS = 2;


class Array
{
public:
	virtual void set_data() = 0;
	virtual void get_data() = 0;
	virtual void set_array() = 0;
	virtual void get_array() = 0;
	virtual double get_average_value() = 0;
	virtual void find_max() = 0;
	virtual void find_min() = 0;
	virtual void sort_array(bool) = 0;
	virtual void change_element() = 0;
	virtual void write_into_file() = 0;
	virtual void menu() = 0;
};


class OneDimensionalArray : public Array
{
	int size;
	int* arr;
public:
	OneDimensionalArray()
	{
		size = 5;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = 0;
	}
	OneDimensionalArray(int size)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = 0;
	}
	OneDimensionalArray(const OneDimensionalArray& obj)
	{
		this->size = obj.size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = obj.arr[i];
	}
	~OneDimensionalArray() { delete[] arr; };
	void set_size();
	void set_array();
	void set_array_element(int i);
	int get_size();
	void get_array();
	void set_data();
	void get_data();
	double get_average_value();
	void find_max();
	void find_min();
	void sort_array(bool);
	void change_element();
	void write_into_file();
	void menu();
};

class TwoDimensionalArray : public Array
{
	int row_size;
	int column_size;
	int** matrix;
public:
	TwoDimensionalArray()
	{
		this->row_size = 3;
		this->column_size = 3;
		matrix = new int* [row_size];
		for (int i = 0; i < row_size; i++)
			matrix[i] = new int[column_size];
		for (int i = 0; i < row_size; i++)
			for (int j = 0; j < column_size; j++)
				matrix[i][j] = 0;
	}
	TwoDimensionalArray(int rows, int columns)
	{
		this->row_size = row_size;
		this->column_size = column_size;
		matrix = new int* [row_size];
		for (int i = 0; i < row_size; i++)
			matrix[i] = new int[column_size];
		for (int i = 0; i < row_size; i++)
			for (int j = 0; j < column_size; j++)
				matrix[i][j] = 0;
	}
	TwoDimensionalArray(const TwoDimensionalArray& obj)
	{
		this->row_size = obj.row_size;
		this->column_size = obj.column_size;
		matrix = new int* [row_size];
		for (int i = 0; i < row_size; i++)
			matrix[i] = new int[column_size];
		for (int i = 0; i < row_size; i++)
			for (int j = 0; j < column_size; j++)
				this->matrix[i][j] = obj.matrix[i][j];
	}
	~TwoDimensionalArray()
	{
		for (int i = 0; i < row_size; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	void set_row_size();
	void set_column_size();
	void set_array();
	void set_matrix_element(int, int);
	int get_row_size();
	int get_column_size();
	void get_array();
	void set_data();
	void get_data();
	double get_average_value();
	void find_max();
	void find_min();
	void sort_array(bool);
	void change_first_negative_with_first();
	void set_row_and_column_to_zero();
	void change_element();
	void write_into_file();
	void menu();
};
