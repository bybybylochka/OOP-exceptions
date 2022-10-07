#pragma once
#include<string>
using namespace std;

enum Gender {
	male,
	female
};

class IdentityData
{
	string FIO;
	Gender gender;
	int age;
public:
	IdentityData();
	~IdentityData();
	void set_FIO(string);
	void set_gender(Gender);
	void set_age(int);
	string get_FIO();
	Gender get_gender();
	int get_age();
	void create_identity_data();
	void print_identity_data();
};

string check_string();
int check_range(int, int);

