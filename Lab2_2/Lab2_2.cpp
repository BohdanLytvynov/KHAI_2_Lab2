// Lab2_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<conio.h>
#include"..\Lab2_2\ukrString.h"



int main()
{
    using namespace strings;
    using namespace std;
    char key;
    do
    {
        system("cls");

        cout << ukrString("Лабораторна робота номер 2!") << endl;

        cout << ukrString("Введіть ваш рядок:\n");

        string inp;        
        getline(cin, inp);
        ukrString ukr_inp(inp);
        ukr_inp.use_for_input();

        cout << ukrString("Ви ввели:") << endl;
        cout << inp;

        cout << ukrString("\nЯкщо ви бажаєте вийти? Натисніть 1. Або будь яку іншу клавішу.");
        key = _getch();
    } while (key != '1');

    

    system("Pause");
}


