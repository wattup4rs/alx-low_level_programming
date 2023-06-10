#include <stdio.h>
/**
 * main - prints its name, followed by anew line.
 * @argc: number of command line arguments.
 * @argv: aray that contains the program command line arguments.
 * Return: 0 - success.
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
