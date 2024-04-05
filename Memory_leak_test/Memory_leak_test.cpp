#include <iostream>
#include <crtdbg.h>
#include "..\SmartAllocator\smartAllocator.h"
#include"..\Lab2_2\ukrString.h"

strings::ukrString Returning()
{
	return strings::ukrString("Тест");
}

void Test()
{
    allocator::smart_allocator<int> alloc(23);

	strings::ukrString text("Test String");
}

void ExcepTest()
{
	try
	{
		allocator::smart_allocator<char> test('e');

		strings::ukrString text("Test String");

		throw std::exception("Test");
	}
	catch (const std::exception&)
	{
		return;
	}
}

int main()
{
    int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    flag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(flag);

    Test();

	ExcepTest();

	allocator::smart_allocator<int> alloc(23);

	strings::ukrString text("Test String");

	strings::ukrString res = Returning();

	std::cout << res << std::endl;
	        
}


