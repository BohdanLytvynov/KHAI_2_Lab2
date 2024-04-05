#ifndef UKRSTRING_H

#define UKRSTRING_H

#include<string>
#include<iostream>
#include"..\SmartAllocator\smartAllocator.h"
namespace strings
{	
	struct ukrString 
	{
	
#pragma region Interface functions

		size_t getLength() const;

		void from_char_ptr(char* src, size_t length);

		void from_string(const std::string& str);

		char* get_chars();

		std::string to_string() const;
		
		void use_for_input();

		void not_for_input();

		bool is_used_for_input() const;

#pragma endregion

#pragma region public static Functions

		static char Ukr(char str);
		
		static void ukrStrCopy(ukrString& src, ukrString dest, int start, int length);

		static std::istream& getLine(std::istream& is, ukrString& output);

#pragma endregion

#pragma region Ctors
		ukrString();//Empty ctor

		ukrString(char *str, size_t length);//Build new Ukr_string 

		explicit ukrString(const char* str);//Convert char string to ukr string
		
		explicit ukrString(const std::string &str);

		ukrString(const ukrString& other);

		explicit ukrString(std::vector<char> & v);
#pragma endregion

#pragma region Operators

		ukrString& operator = (const ukrString& other);

		ukrString& operator = (const char cstr []);

		friend std::ostream& operator << (std::ostream& os, ukrString& string)
		{
			size_t length = string.getLength();

			for (size_t i = 0; i < length; i++)
			{
				if (string.m_use_for_input)
					os << string[i];
				else
					os << Ukr(string[i]);
			}

			return os;
		}

		friend std::ostream& operator << (std::ostream& os, const ukrString& string)
		{
			size_t length = string.getLength();

			for (size_t i = 0; i < length; i++)
			{		
				if (string.m_use_for_input)
					os << string[i];
				else
					os << Ukr(string[i]);
			}

			return os;
		}

		friend std::istream& operator >> (std::istream& is, ukrString& string)
		{
			std::string str;

			is >> str;

			string.from_char_ptr(str._Unchecked_begin(), str.length());

			return is;
		}

		operator std::string() const;

		char& operator [] (int index);

		const char& operator [] (int index) const;

		ukrString operator + (const ukrString& other) const;
		
		void operator += (const ukrString& other);

		bool operator == (const ukrString& other);

		bool operator != (const ukrString& other);


#pragma endregion


#pragma region Destructor
		~ukrString();
#pragma endregion

	private:

#pragma region Fields
				
		allocator::smart_allocator<char> m_chars;//Stores chars 		

		bool m_use_for_input;

#pragma endregion

	};

	
}

#endif // !UKRSTRING_H
