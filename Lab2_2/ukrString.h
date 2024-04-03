#ifndef UKRSTRING_H

#define UKRSTRING_H

#include<string>
#include<iostream>
#include"..\SmartAllocator\smartAllocator.h"
namespace strings
{
	struct ukrString : allocator::smart_allocator<char>
	{
	
#pragma region Interface functions
		size_t getLength() const;
		void strCopy(char* src, size_t length);
		
#pragma endregion

#pragma region Ctors
		ukrString();//Empty ctor

		ukrString(char *str, size_t length);//Build new Ukr_string 
		explicit ukrString(char str []);//Convert char string to ukr string
		explicit ukrString(const std::string &str);

		ukrString(const ukrString& other);
#pragma endregion

#pragma region Operators

		ukrString& operator = (const ukrString& other);

		friend std::ostream& operator << (std::ostream& os, const ukrString& string);

		friend std::istream& operator >> (std::istream& is, const ukrString& string);

#pragma endregion


#pragma region Destructor
		~ukrString();
#pragma endregion

	private:

#pragma region Fields
		size_t m_length;//Length of the string
		
#pragma endregion

#pragma region private Functions



#pragma endregion

	};
}

#endif // !UKRSTRING_H
