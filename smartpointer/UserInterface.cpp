#include "UserInterface.h"
#include"Developer.h"
#include"Analyst.h"
#include"Tester.h"
#include<iostream>
#include<fstream>
using namespace std;

void UserInterface::display()
{
	if (specialist_vector.size() == 0)
		cout << "  Данные отсутствуют!  " << endl;
	else
	{
		cout << "____________________________________________________________________________________________________" << endl << endl;
		cout << "|     Код     |               ФИО               | Возраст |  Дата приема  |  Уровень  |  Зарплата  |" << endl;
		cout << "____________________________________________________________________________________________________" << endl;
		for (int i = 0; i < specialist_vector.size(); i++)
		{
			specialist_vector[i]->print_data();
			cout << "____________________________________________________________________________________________________" << endl;
		}
	}
}

int menu()
{
	cout << "  Меню:" << endl << "  1-Добавить информацию о сотруднике" << endl << "  2-Просмотреть информацию о сотрудниках" << endl << "  3-Удалить информацию о сотруднике" <<
		endl << "  4-Просмотреть информацию об удаленных (уволенных) сотрудниках " << endl << "  5-Завершить работу"<<endl<<"  Ваш выбор:  ";
	int choice;
	choice = check_range(1, 5);
	return choice;
}

void UserInterface::add()
{
	cout << "  Введите должность сотрудника, информацию о котором необходимо добавить (1-разработчик, 2-тестировщик, 3-аналитик):  ";
	int position = check_range(1, 3);
	transaction.begin_transaction();
	SmartPointer<ItSpecialist> temp(new ItSpecialist);
	switch (position)
	{
	case 1: temp = new Developer(transaction.operator->());
		break;
	case 2: temp = new Tester(transaction.operator->());
		break;
	case 3: temp = new Analyst(transaction.operator->());
		break;
	}
	temp->create_data();
	cout << "  Подтверждение ввода (1-подтвердить, 2-отменить):  ";
	int choice;
	choice = check_range(1, 2);
	if (choice == 1)
	{
		transaction.commit_transaction();
		specialist_vector.push_back(temp);
	}
	else
		transaction.delete_transaction();
}
int UserInterface::check_code()
{
	string code;
	while (1)
	{
		cin >> code;
		for (int i = 0; i < specialist_vector.size(); i++)
		{
			if (specialist_vector[i]->get_code() == code)
				return i;
		}
		cout << "  Данного кода не существует! Попробуйте еще раз:  ";
	}
}
void UserInterface::fire()
{
	if (specialist_vector.size() == 0)
		cout << "  Данные отсутствуют!  " << endl;
	else
	{
		cout << "  Введите код уволенного сотрудника:  ";
		int index = check_code();
		fired_specialist_vector.push_back(specialist_vector[index]);
		specialist_vector.erase(specialist_vector.begin() + index);
		cout << "  Данные о сотруднике успешно удалены!  " << endl;
	}
}
void UserInterface::display_fired()
{
	if (fired_specialist_vector.size() == 0)
		cout << "  Данные отсутствуют!  " << endl;
	else
	{
		cout << "____________________________________________________________________________________________________" << endl << endl;
		cout << "|     Код     |               ФИО               | Возраст |  Дата приема  |  Уровень  |  Зарплата  |" << endl;
		cout << "____________________________________________________________________________________________________" << endl;
		for (int i = 0; i < fired_specialist_vector.size(); i++)
		{
			fired_specialist_vector[i]->print_data();
			cout << "____________________________________________________________________________________________________" << endl;
		}
	}
}

void UserInterface::write_into_file() 
{
	ofstream file;
	file.open("data.txt");
	file << specialist_vector.size() << endl;
	for (int i = 0; i < specialist_vector.size(); i++)
	{
		specialist_vector[i]->write(file);
	}
	file.close();
	file.open("fired.txt");
	file << fired_specialist_vector.size() << endl;
	for (int i = 0; i < fired_specialist_vector.size(); i++)
	{
		fired_specialist_vector[i]->write(file);
	}
	file.close();
}

void UserInterface::read_from_file()
{
	ifstream file;
	
	file.open("data.txt");
	int size;
	file >> size;
	for (int i = 0; i < size; i++)
	{
		SmartPointer<ItSpecialist> temp(new ItSpecialist);
		temp->read(file);
		specialist_vector.push_back(temp);
	}
	file.close();
	file.open("fired.txt");
	file >> size;
	for (int i = 0; i < size; i++)
	{
		SmartPointer<ItSpecialist> temp(new ItSpecialist);
		temp->read(file);
		fired_specialist_vector.push_back(temp);
	}
	file.close();

}