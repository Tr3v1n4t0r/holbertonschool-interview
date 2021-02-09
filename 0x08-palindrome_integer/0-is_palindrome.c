#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned long is a palindrome
 * 
 * @n: The number to check
 * 
 * Return: 1 if palindrome, else 0
 **/
int is_palindrome(unsigned long n)
{
    unsigned long int temp = n, rev = 0;

    for (; temp > 0; temp /= 10)
        rev = rev * 10 + (temp % 10);

    return (rev == n);
}