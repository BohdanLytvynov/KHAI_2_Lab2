#include"ukrString.h"

using su = strings::ukrString;

#pragma region Interface functions definitions

size_t su::getLength() const
{
	return m_chars.getSize();
}

void su::from_char_ptr(char* src, size_t length)
{
	if (length == 0) return;

	if (m_chars.isAllocated())
		m_chars.deAllocate();

	m_chars.allocate_memory_block(src, length);
}

char* su::get_chars() 
{
	return m_chars.getPtr();
}

std::string su::to_string() const
{
	std::string str;

	size_t length = this->getLength();

	if (length == 0) return str;

	for (size_t i = 0; i < length; i++)
	{
		str.push_back(m_chars[i]);
	}

	return str;
}

void su::use_for_input()
{
	m_use_for_input = true;
}

bool su::is_used_for_input() const
{
	return m_use_for_input;
}

void su::not_for_input()
{
	m_use_for_input = false;
}

void su::from_string(const std::string& str)
{
	if (m_chars.isAllocated())
		m_chars.deAllocate();

	m_chars.allocate_memory_block(str._Unchecked_begin(), str.length());
}

#pragma endregion


#pragma region Ctor Definition

su::ukrString(): m_use_for_input(false) {}

su::ukrString(char* str, size_t length) : ukrString()
{
	m_chars.allocate_memory_block(str, length);
}

su::ukrString(char str[]) : ukrString()
{
	m_chars.allocate_memory_block(str, strlen(str));
}

su::ukrString(const std::string& str) : ukrString()
{
	m_chars.allocate_memory_block(str._Unchecked_begin(), str.length());
}

su::ukrString(const ukrString& other)
{
	m_use_for_input = other.m_use_for_input;
	m_chars = other.m_chars;
}

#pragma endregion

#pragma region Operators

su& su::operator= (const char c_str [])
{
	if (this->m_chars.isAllocated())
		this->m_chars.deAllocate();

	m_chars.allocate_memory_block(c_str, strlen(c_str));

	return *this;
}

su& su::operator = (const ukrString& other)
{
	m_use_for_input = other.m_use_for_input;
	this->m_chars = other.m_chars;

	return *this;
}

su::operator std::string() const
{
	return to_string();
}

char& su::operator [] (int index)
{
	if (m_chars.isAllocated())
		return m_chars[index];
}

const char& su::operator [] (int index) const
{
	if (m_chars.isAllocated())
		return m_chars[index];
}

#pragma endregion


#pragma region Destructor

su::~ukrString()
{
	m_chars.~smart_allocator();
}

#pragma endregion

#pragma region public static functions

void su::ukrStrCopy(ukrString& src, ukrString dest, int start, int length)
{
	if (src.getLength() == 0) return;

	if (start < 0 || start > length - 1) 
		throw std::runtime_error("Incorrect range! Start index is greater then end index!");

	for (int i = start; i < length; i++)
	{
		dest[i] = src[i];
	}
}

char su::Ukr(char str)
{	
	switch (str)
	{
		case -78: return 73;  // ²
		case -77: return 105; // ³
		case -86: return 242; // ª
		case -70: return 243; // º
		case -81: return 244; // ¯
		case -65: return 245; // ¿
		case -88: return 240; // ¨
		case -72: return 241; // ¸

	default:
		{
		if (str <= -17 && str >= -64) return str -= 64;
		else
			if (str <= -1 && str >= -16) return str -= 16;
		}
	}
}

std::istream& su::getLine(std::istream& is, su& output)
{
	std::string str;

	std::getline(is, str);

	output.from_string(str);

	output.use_for_input();

	return is;
}

#pragma endregion


