#include"ItSpesialist.h"
#include"Developer.h"
#include"UserInterface.h"
#include<Windows.h>
#include<vector>
#include<memory>

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	UserInterface specialists;
	specialists.read_from_file();
	while (true)
	{
		switch (menu())
		{
		case 1: specialists.add();
			break;
		case 2: specialists.display();
			break;
		case 3: specialists.fire();
			break;
		case 4: specialists.display_fired();
			break;
		case 5: specialists.write_into_file();
			return 0;
			break;
		}
		system("pause");
		system("cls");
	}

}