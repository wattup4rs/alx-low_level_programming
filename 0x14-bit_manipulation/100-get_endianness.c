#include "main.h"

/**
 * get_endianness - checks the  endianness
 * Return: 0 if big endian else, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int n;
	char *c;

	n = 1;
	c = (char *) &n;

	return (*c == 1);
}
