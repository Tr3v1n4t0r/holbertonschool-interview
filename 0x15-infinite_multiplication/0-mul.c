#include "holberton.h"

/**
 * main - multiplies two positive numbers
 * @argc: num of args
 * @argv: array of args
 *
 * Return: 0 on success, 98 otherwise
 */
int main(int argc, char* argv[])
{
	char* result;

	if (argc != 3 || check(argv[1]) == 0 || check(argv[2]) == 0)
	{
		_puts("Error");
		exit(98);
	}

	result = inf_mul(argv[1], argv[2]);
	_puts(skip_zeroes(result));
	free(result);

	return (0);
}

/**
 * check - checks if a string is only numbers
 * @s: string to check
 *
 * Return: 0 if not only numbers, 1 if only numbers
 */
int check(char* s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * _puts - prints a string
 * @str: string to print
 *
 * Return: num of chars printed
 */
int _puts(char* str)
{
	size_t i, len = _strlen(str);

	for (i = 0; i < len; i++)
		_putchar(str[i]);
	_putchar('\n');

	return (i + 1);
}

/**
 * inf_mul - multiplies two numbers
 * @n1: num to multiply
 * @n2: num to multiply by
 *
 * Return: pointer to new string with result
 */
char* inf_mul(char* n1, char* n2)
{
	size_t i, j;
	size_t size1 = _strlen(n1), size2 = _strlen(n2);
	char* buf = _calloc(size1 + size2, sizeof(char));
	int product, digit, carry;

	rev_str(n1);
	rev_str(n2);

	for (i = 0; i < size1; i++)
	{
		for (carry = 0, j = 0; j < size2; j++)
		{
			product = ((n1[i] - '0') * (n2[j] - '0')) + carry;
			digit = product % 10;
			carry = product / 10;
			add_digit(buf + i + j, digit);
		}

		if (carry)
			add_digit(buf + i + j, carry);
	}

	rev_str(buf);

	return (buf);
}

/**
 * _strlen - calculates length of a string
 * @str: string to count
 *
 * Return: length of string
 */
size_t _strlen(char* str)
{
	size_t len;

	if (str == NULL)
		return (0);

	for (len = 0; str[len]; len++)
		;

	return (len);
}

/**
 * _calloc - allocates and clears an amount of memory
 * @nmem: num of members
 * @size: size of members
 *
 * Return: pointer to allocated space
 */
void* _calloc(size_t nmem, size_t size)
{
	char* buf = malloc(nmem * size);
	size_t i;

	if (buf == NULL)
		return (NULL);

	for (i = 0; i < nmem * size; i++)
		buf[i] = 0;

	return ((void*)buf);
}

/**
 * rev_str - reverses a string
 * @str: string to reverse
 */
void rev_str(char* str)
{
	size_t i, j;
	char tmp;

	for (i = 0, j = _strlen(str) - 1; i < j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

/**
 * add_digit - adds a digit to a reversed string representation of a number
 * @num: number string to add to
 * @digit: digit to add
 */
void add_digit(char* num, int digit)
{
	int result;

	for (; 1; num++)
	{
		if (*num)
			result = (*num - '0') + digit;
		else
			result = digit;

		*num = (result % 10) + '0';
		digit = result / 10;

		if (digit == 0)
			break;
	}
}

/**
 * skip_zeroes - skips leading zeroes in a string
 * @str: string to process
 * Return: pointer to first non-zero char
 */
char* skip_zeroes(char* str)
{
	while (*(str + 1) && *str == '0')
		str++;

	return (str);
}