#pragma once
#include<vector>
#include"SmartPointer.h"
#include"Transaction.h"
#include"ItSpesialist.h"
class UserInterface
{
	vector<SmartPointer<ItSpecialist>> specialist_vector;
	vector<SmartPointer<ItSpecialist>> fired_specialist_vector;
	Transaction<ItSpecialist> transaction;
public:
	void display();
	void add();
	void fire();
	int check_code();
	void display_fired();
	void write_into_file();
	void read_from_file();
};
int menu();

