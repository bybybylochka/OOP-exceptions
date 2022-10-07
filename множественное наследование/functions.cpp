#include"Header.h"
#include<iostream>
#include<Windows.h>
#include<typeinfo>

using namespace std;

void Developer::create_data()
{
	cout << endl;
	cout << "  Введите ФИО:  ";
	identity_data.set_FIO(check_string());
	cout << "  Введите возраст:  ";
	identity_data.set_age(check_range(10, 100));
	cout << "  Введите желаемую зарплату ($):  ";
	set_expected_salary(check_range(0, 20000));
	cout << "  Введите опыт работы (кол-во месяцев):  ";
	set_experience(check_range(0, 1000));
}
void Developer::print_data()
{
	cout <<endl<< "  ----------  " << endl;
	cout << "  ФИО:  "<<identity_data.get_FIO()<<endl;
	cout << "  Возраст:  " << identity_data.get_age() << endl;
	cout << "  Желаемая зарплата:  " << get_expected_salary() << endl;
	cout << "  Опыт работы:  " << get_experience() << endl;
}
void FrontEndDeveloper::create_data()
{
	Developer::create_data();
	cout << "  Введите уровень вашего владения языком HTML (от 1 до 5):  ";
	set_HTML(check_range(1, 5));
	cout << "  Введите уровень вашего владения языком CSS (от 1 до 5):  ";
	set_CSS(check_range(1, 5));
	cout << "  Введите уровень вашего владения языком JavaScript (от 1 до 5):  ";
	set_JS(check_range(1, 5));
}
void FrontEndDeveloper::print_data()
{
	Developer::print_data();
	cout << "  Уровень владения HTML (Минимум - *, максимум - ***** ):  "; 
	print_level_of_knowledge(get_HTML());
	cout << endl;
	cout << "  Уровень владения CSS (Минимум - *, максимум - ***** ):  ";
	print_level_of_knowledge(get_CSS());
	cout << endl;
	cout << "  Уровень владения JavaScript (Минимум - *, максимум - ***** ):  ";
	print_level_of_knowledge(get_JS());
	cout << endl;
}
void BackEndDeveloper::create_data()
{
	Developer::create_data();
	cout << "  Введите уровень вашего владения базами данных и ситемами управления(от 1 до 5):  ";
	set_database(check_range(1, 5));
	cout << "  Введите фреймворк, которым владеете (1 - Spring Framework, 2 - Django, 3 - Laravel, 4 - Ruby on Rails, 5 - другие):  ";
	set_framework(check_range(1, 5));
	cout << "  Введите язык программирования, на котором специализируетесь:  ";
	set_language(check_language());
}
void BackEndDeveloper::print_framework(int framework)
{
	switch (framework)
	{
	case 1: cout << "Spring Framework";
		break;
	case 2:cout << "Django" ;
		break;
	case 3:cout << "Laravel" ;
		break;
	case 4:cout << "Ruby on Rails" ;
		break;
	case 5:cout << "Другое";
		break;
	}
}
void BackEndDeveloper::print_data()
{
	Developer::print_data();
	cout << "  Уровень владения базами данных (Минимум - *, максимум - ***** ):  ";
	print_level_of_knowledge(get_database());
	cout << endl;
	cout << "  Уровень владения фреймворком:  ";
	print_framework(get_framework());
	cout << endl;
	cout << "  Язык программирования:  "<<get_language();
	cout << endl;
}
void FullStackDeveloper::create_data()
{
	FrontEndDeveloper::create_data();
	cout << "  Введите уровень вашего владения базами данных и ситемами управления(от 1 до 5):  ";
	set_database(check_range(1, 5));
	cout << "  Введите фреймворк, которым владеете (1 - Spring Framework, 2 - Django, 3 - Laravel, 4 - Ruby on Rails, 5 - другие):  ";
	set_framework(check_range(1,5));
	cout << "  Введите язык программирования, на котором специализируетесь:  ";
	set_language(check_language());
}
void FullStackDeveloper::print_data()
{
	FrontEndDeveloper::print_data();
	cout << "  Уровень владения базами данных (Минимум - *, максимум - ***** ):  ";
	print_level_of_knowledge(get_database());
	cout << endl;
	cout << "  Уровень владения фреймворком:  ";
	print_framework(get_framework());
	cout << endl;
	cout << "  Язык программирования:  " << get_language();
	cout << endl;
}
void print_level_of_knowledge(int level)
{
	for (int i = 0; i < level; i++)
	{
		cout << "*";
	}
}
int main_menu()
{
	cout << endl;
	int choice;
	cout << "  Меню:" << endl << "  1 - Заполнить анкету  " << endl << "  2 - Просмотреть анкеты" << endl << "  3 - Завершить работу" << endl << "  Ваш выбор?  ";
	choice=check_range(1, 3);
	return choice;
}
int user_menu()
{
	cout << endl;
	int choice;
	cout << "  Кем вы являетесь?  " << endl << "  1 - FrontEnd-разработчик" << endl << "  2 - BackEnd-разработчик" << endl << "  3 - FullStack-разработчик"
		<< endl << "  Ваш выбор?  ";
	choice = check_range(1, 3);
	return choice;
}

void WebDeveloperArray::add_form()
{
	switch (user_menu())
	{
	case 1: developers[counter] = new FrontEndDeveloper();
		break;
	case 2:developers[counter] = new BackEndDeveloper();
		break;
	case 3:developers[counter] = new FullStackDeveloper();
		break;
	}
	developers[counter]->create_data();
	counter++;
}

int admin_menu()
{
	cout << endl;
	int choice;
	cout<<"  Чьи анкеты вы хотите просмотреть?"<<endl<< "  1 - FrontEnd-разработчики" << endl << "  2 - BackEnd-разработчики" << endl << "  3 - FullStack-разработчики"
		<<endl<<"  4 - Все анкеты" << endl << "  Ваш выбор?  ";
	choice = check_range(1, 4);
	return choice;
}



void WebDeveloperArray::print_forms()
{
	int flag;
	switch (admin_menu())
	{
	case 1: 
		flag = 0;
		for (int i = 0; i < counter; i++)
		{
			if (developers[i]->type_checker() == FRONT_END_DEVELOPER)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0) cout << "  Данные анкеты отсутствуют!  " << endl;
		else
		{
			for (int i = 0; i < counter; i++)
			{
				if (developers[i]->type_checker() == FRONT_END_DEVELOPER)
					developers[i]->print_data();
			}
		}
		    break;
	case 2:
		flag = 0;
		for (int i = 0; i < counter; i++)
		{
			if (developers[i]->type_checker() == BACK_END_DEVELOPER)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0) cout << "  Данные анкеты отсутствуют!  " << endl;
		else
		{
			for (int i = 0; i < counter; i++)
			{
				if (developers[i]->type_checker() == BACK_END_DEVELOPER)
					developers[i]->print_data();
			}
		}
		break;
	case 3:
		flag = 0;
		for (int i = 0; i < counter; i++)
		{
			if (developers[i]->type_checker() == FULL_STACK_DEVELOPER)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0) cout << "  Данные анкеты отсутствуют!  " << endl;
		else
		{
			for (int i = 0; i < counter; i++)
			{
				if (developers[i]->type_checker() == FULL_STACK_DEVELOPER)
					developers[i]->print_data();
			}
		}
		break;
	case 4:
		if (counter == 0)
			cout << "  Анкеты отсутствуют!  " << endl;
		else
		{
			for (int i = 0; i < counter; i++)
			{
				developers[i]->print_data();
			}
		}
		break;
	}
}

void WebDeveloperArray::sort_forms()
{
	cout <<endl<< "  Желаете отсортировать анкеты по опыту работы?  (Да - введите 1, нет - введите 0)" << endl << "  Ваш выбор:  ";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		for (int i = 0; i < counter; i++)
		{
			for (int j = 0; j < counter - 1; j++)
			{
				if (developers[j]->get_experience() < developers[j + 1]->get_experience())
				{
					Developer* temp = developers[j];
					developers[j] = developers[j + 1];
					developers[j + 1] = temp;
				}
			}
		}
	}
}

developerTypes Developer::type_checker()
{
	if (typeid(*this) == typeid(FrontEndDeveloper))
		return FRONT_END_DEVELOPER;
	if (typeid(*this) == typeid(BackEndDeveloper))
		return BACK_END_DEVELOPER;
	if (typeid(*this) == typeid(FullStackDeveloper))
		return FULL_STACK_DEVELOPER;
}

int check_range(int bottom, int top)
{
	int range;
	while (1)
	{
		cin >> range;
		if (cin.fail()||range<bottom||range>top)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "  Ошибка ввода! Попробуйте еще раз:  ";
		}
		else
		{
			cin.ignore(32767, '\n');
			return range;
			break;
		}
	}
}

string check_string()
{
	string FIO;
	while (1)
	{
		getline(cin, FIO);
		string wrong_symbols = "!@#$%^&*()_+=?:;№{}<>,.|/0123456789";
		int flag = 0;

		for (int i = 0; i < FIO.length(); i++)
		{
			for (int j = 0; j < wrong_symbols.length(); j++)
			{
				if (FIO[i] == wrong_symbols[j])
				{
					flag = 1;
					i - FIO.length();
					j = wrong_symbols.length();
				}
			}

		}
		if (flag == 1)
		{
			cout << "  Ошибка ввода! Попробуйте еще раз:  ";
		}
		else
		{
			return FIO;
			break;
		}
	}
}

string BackEndDeveloper::check_language()
{
	string language;
	while (1)
	{
		int flag = 0;
		getline(cin, language);
		for (int i = 0; i < 10; i++)
		{
			if (language == LANGUAGES[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << "  Ошибка ввода! Попробуйте еще раз:  ";
		}
		else
		{
			return language;
			break;
		}
	}
}