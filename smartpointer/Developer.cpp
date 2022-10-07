#include "Developer.h"
#include<iostream>

Developer::Developer()
{
	this->language = "no data";
}
Developer::Developer(ItSpecialist* It)
	: ItSpecialist(*(It))
{
}

void Developer::set_language(string language)
{
	this->language = language;
}
string Developer::get_language()
{
	return this->language;
}
string Developer::check_language(int& position)
{
	static const string LANGUAGES[10] = { "Java", "C", "C++", "Visual Basic", "PHP", "Perl", "C#", "Python", "JavaScript", "Ruby" };
	string language;
	while (1)
	{
		int flag = 0;
		getline(cin, language);
		for (int i = 0; i < 10; i++)
		{
			if (language == LANGUAGES[i])
			{
				position = i;
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
void Developer::create_data()
{
	const string lan[10] = { "Java", "C", "C++", "VB", "PHP", "Perl", "C#", "Py", "JS", "Ruby" };
	cout << "  Введите язык программирования, на котором специализируется сотрудник:  ";
	int position;
	set_language(check_language(position));
	set_code(generate_code("dev", lan[position]));
}
