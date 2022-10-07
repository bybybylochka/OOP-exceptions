#pragma once
#include <string>
#include<typeinfo>

using namespace std;

enum developerTypes
{
	FRONT_END_DEVELOPER,
	BACK_END_DEVELOPER,
	FULL_STACK_DEVELOPER
};

class IdentityData //чем отличается html и xml!
{
	string FIO;
	int age;
public:
	IdentityData()
	{
		this->FIO = "No data";
		this->age = 0;
	}
	~IdentityData(){}
	void set_FIO(string FIO)
	{
		this->FIO = FIO;
	};
	void set_age(int age)
	{
		this->age = age;
	};
	string get_FIO()
	{
		return this->FIO;
	};
	int get_age()
	{
		return this->age;
	};
};
class Developer
{
	IdentityData identity_data;
	int expected_salary;
	int experience;
public:
	Developer()
	{
		this->expected_salary = 0;
		this->experience = 0;
	}
	~Developer()
	{

	}
	void set_expected_salary(int expected_salary)
	{
		this->expected_salary = expected_salary;
	};
	void set_experience(int experience)
	{
		this->experience = experience;
	};
	int get_expected_salary()
	{
		return this->expected_salary;
	};
	int get_experience()
	{
		return this->experience;
	};
	virtual void create_data();
	virtual void print_data();
	virtual developerTypes type_checker();
};

class BackEndDeveloper: public virtual Developer
{	int database_level;
	int framework;
	string language;
	const string LANGUAGES[10] = { "Java", "C", "C++", "Visual Basic", "PHP", "Perl", "C#", "Python", "JavaScript", "Ruby"};
public:
	BackEndDeveloper(): Developer()
	{
		this->database_level = 0;
		this->framework = 0;
		this->language = "No data";
	}
	void set_database(int database)
	{
		this->database_level = database;
	}
	void set_framework(int framework)
	{
		this->framework = framework;
	}
	void set_language(string language)
	{
		this->language = language;
	}
	int get_database()
	{
		return this->database_level;
	}
	int get_framework()
	{
		return this->framework;
	}
	string get_language()
	{
		return this->language;
	}
	void create_data();
	void print_data();
	void print_framework(int);
	string check_language();
	~BackEndDeveloper() {}
};

class FrontEndDeveloper: public virtual Developer
{
	int HTML_level;
	int CSS_level;
	int JS_level;
public:
	FrontEndDeveloper(): Developer()
	{
		this->HTML_level = 0;
		this->CSS_level = 0;
		this->JS_level = 0;
	}
	void set_HTML(int HTML)
	{
		this->HTML_level = HTML;
	}
	void set_CSS(int CSS)
	{
		this->CSS_level = CSS;
	}
	void set_JS(int JS)
	{
		this->JS_level = JS;
	}
	int get_HTML()
	{
		return this->HTML_level;
	}
	int get_CSS()
	{
		return this->CSS_level;
	}
	int get_JS()
	{
		return this->JS_level;
	}
	void create_data();
	void print_data();
	~FrontEndDeveloper(){}

};

class FullStackDeveloper: public BackEndDeveloper, public FrontEndDeveloper
{
public:
	FullStackDeveloper() : BackEndDeveloper(), FrontEndDeveloper(){}
	void create_data();
	void print_data();
	~FullStackDeveloper(){}
};

class WebDeveloperArray
{
	const int MAX_AMOUNT_OF_DEVELOPERS = 10;
	int counter;
	Developer** developers;
public:
	WebDeveloperArray() {
		counter = 0;
		developers = new Developer * [MAX_AMOUNT_OF_DEVELOPERS];
	}
	void add_form();
	void print_forms();
	void sort_forms();
	~WebDeveloperArray()
	{
		delete[] developers;
	}
};

void print_level_of_knowledge(int level);
int main_menu();
int admin_menu();
int user_menu();
int check_range(int, int);
string check_string();
