#include "shell.h"
/**
 * my_strcspn - This fuction find the length of a prefix substring
 * in a given string until a specific set of characters is encountered
 * @str:the string
 * @chars: chars to find
 * Return:length of string
 */
size_t my_strcspn(const char *str, const char *chars)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		size_t char_index = 0;

		while (chars[char_index] != '\0')
		{
			if (str[length] == chars[char_index])
				return (length);
			char_index++;
		}
		length++;
	}
	return (length);
}
