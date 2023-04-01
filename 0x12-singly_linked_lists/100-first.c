#include <stdio.h>

/**
 * cmain - the function executed before main
 * Return: a no return.
 */

void __attribute__ ((constructor)) cmain()
{
	printf("You're beat! and yet, you must allow");
	printf(",\nI bore my house upon my back!\n");
}

