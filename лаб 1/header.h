#pragma once
#include<string>
class Tile
{
	std::string brand;
	std::string color;
	int height;
	int weight;
	double price;
	int quantity;
	double total_price;
public:
	Tile():height(0),weight(0),price(0),quantity(0),total_price(0)      //конструктор без параметров
	{  
		brand="0";
		color = "0";
	}
	Tile(std::string brand, std::string color, int height, int weight, int price, int quantity, int total_price)   //конструктор с параметрами
	{
		this->brand = brand;
		this->color = color;
		this->height = height;
		this->weight = weight;
		this->price = price;
		this->quantity = quantity;
		this->total_price = total_price;
	}
	Tile(const Tile& obj)          //конструктор копирования
	{
		brand = obj.brand;
		color = obj.color;
		height = obj.height;
		weight = obj.weight;
		price = obj.price;
		quantity = obj.quantity;
		total_price = obj.total_price;
	}
	~Tile()            //деструктор
	{
		std::cout << "деструктор\n";
	}

	void input();
	void type_one();

	std::string get_brand() { return brand; }    //геттер для поля бренд
	void change_brand();
	void change_color();
	void change_height();
	void change_weight();
	void change_price();
	void change_quantity();
	int get_total_store() { return total_price; };      //геттер для поля итоговая стоимость плитки, хранящейся на складе
};
int menu();
void type(Tile*, int kol);
void total_store(Tile*, int kol);
void change_data(int, Tile*);
void write_into_file(Tile*, int kol);
