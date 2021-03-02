#include "menger.h"

/**
 * menger - Prints a 2D version of a menger sponge
 * 
 * @level: The order of the sponge
 **/
void menger(int level)
{
    unsigned long int width = pow(3, level);
    uint i, j;

    for (i = 0; i < width; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (checkpos(i, j, level))
                putchar('#');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

/**
 * checkpos - Checks if a position should be a # or ' '
 * 
 * @x: The x coordinate of the plane
 * @y: The y coordinate of the plane
 * @level: The total order of the sponge
 * 
 * Return: True for #, false for ' '
 **/
bool checkpos(uint x, uint y, int level)
{
    uint onorder = level;

    for (; onorder > 0; onorder--)
    {
        if (!checkbit(onorder, x) && !checkbit(onorder, y))
            return (false);
    }
    return (true);
}

/**
 * checkbit - Checks if a bit is a 1 or 0 on a certain order
 * 
 * @order: The order to check on
 * @index: The index to check
 * 
 * Return: 1 for true, 0 for false
 **/
bool checkbit(uint order, uint index)
{
    if (order == 0)
        return (1);
    return ((uint)(index / pow(3, order - 1)) % 3 != 1);
}