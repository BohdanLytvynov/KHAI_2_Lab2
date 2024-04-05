#ifndef LAB2_2_FUNCTIONS_H

#define LAB2_2_FUNCTIONS_H
#include "ukrString.h"
#include <algorithm>

namespace lab2
{
	template<class T>
	static T Input(const strings::ukrString& msg, std::function<T(std::string& str)> converter,
		std::function<bool(std::string& str, strings::ukrString& error)> validator = nullptr)
	{
		strings::ukrString error;

		std::string str;

		do
		{
			std::cout << msg << std::endl;

			std::getline(std::cin, str);

			if (!validator)
				break;

			if (validator(str, error))
				break;
			else
				std::cout << error << std::endl;

		} while (true);

		return converter(str);
	}

	using Word = std::vector<char>;

	using wordSet = std::vector<Word>;

	static bool Compare(char current, const char delim[])
	{
		size_t length = strlen(delim);

		for (size_t i = 0; i < length; i++)
		{
			if (current == delim[i])
				return true;
		}

		return false;
	}


	static void Split(strings::ukrString& str, wordSet& word_Set,
		const char delim[])
	{
		bool delim_found = false;

		size_t length = str.getLength();

		Word word;

		for (size_t i = 0; i < length; i++)//O(n * sizeof(delim))
		{
			if (!Compare(str[i], delim) || i == 0)//Space not found or we are at the begining create Word
			{
				word.push_back(str[i]);

				delim_found = false;
			}
			else//delim_found found
			{
				if (!delim_found)
				{
					word_Set.push_back(word);

					word.clear();
				}
				
				delim_found = true;
			}

			if (i == length - 1)//End reached
			{
				word_Set.push_back(word);

				word.clear();
			}
		}
	}	

	static Word FindTheBiggestWord(strings::ukrString& str)
	{
		wordSet set;

		Split(str, set, { " " });

		int max_index = -1;

		size_t max = 0;

		size_t length = set.size();

		for (size_t i = 0; i < length; i++)
		{			
			if (set[i].size() > max)
			{
				max_index = i;
				max = set[i].size();
			}
		}

		return set[max_index];
	}

}

#endif // !LAB2_2_FUNCTIONS_H
