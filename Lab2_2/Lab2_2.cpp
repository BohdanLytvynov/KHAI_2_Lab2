// Lab2_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<conio.h>
#include<functional>
#include<string>
#include<vector>
#include"..\Lab2_2\ukrString.h"
#include"Lab2_2_functions.h"


int main()
{
	using namespace lab2;
	using namespace strings;
	using namespace std;
	char key = '0';
	do
	{
		cout << ukrString("Лабораторна робота номер 2!") << endl;

		cout << ukrString("Введіть ваш рядок:\n");

		ukrString inp;

		ukrString::getLine(cin, inp);

		cout << ukrString("Ви ввели:") << endl;
		cout << inp;

		char key = Input<char>(ukrString("Виберіть опцію, та натисніть ENTER: \n\t- 1) Пошук слова макс довжини, натисніть 1 \n\t- 2) Виконати завдання за варіантом натисніть 2 \n\t- 3) Вийти, натисніть 3"),
			[](std::string& str)->char {return *str.c_str(); },
			[](std::string& str, strings::ukrString& error)->bool
			{
				int input = -1;

				try
				{
					input = std::stoi(str);
				}
				catch (...)
				{
					error = "Невірний ввод!";
					return false;
				}

				if (!(input >= 1 && input <= 3))
				{
					error = "Невірний діапазон!";
					return false;
				}

				return true;

			});

		switch (key)
		{
		case '1':

			break;
		case '2':

			break;
		default:
			break;
		}

		cout << ukrString("\nЯкщо ви бажаєте вийти? Натисніть 1. Або будь яку іншу клавішу.");
		key = _getch();
	} while (key != '1');


}


