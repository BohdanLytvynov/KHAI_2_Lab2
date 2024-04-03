#include"ukrString.h"

using su = strings::ukrString;

#pragma region Ctor Definition

su::ukrString() : allocator::smart_allocator<char>() 
{
	
}

#pragma endregion

#pragma region Destructor

su::~ukrString()
{
	smart_allocator::~smart_allocator();
}

#pragma endregion

