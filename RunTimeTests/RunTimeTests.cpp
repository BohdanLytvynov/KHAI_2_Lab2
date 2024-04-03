// RunTimeTests.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include"../SmartAllocator/smartAllocator.h"
#include <iostream>

int main()
{
    using namespace allocator;

    smart_allocator<char> t1;
    t1.allocate();

    smart_allocator<char> t2(t1);

    
}


