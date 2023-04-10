#include "main.h"

/**
 * clear_bit - sets a bit valueto 0.
 * at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 if it worked else, -1 .
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int uim;

	if (index > 63)
		return (-1);

	uim = 1 << index;

	if (*n & uim)
		*n ^= uim;

	return (1);
}

