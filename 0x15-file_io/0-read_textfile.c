#include "main.h"

/**
 * read_textfile - reads text file & prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. else, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	ssize_t nrd, nwr;
	char *buf;

	if (!filename)
		return (0);

	file = open(filename, O_RDONLY);

	if (file == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nrd = read(file, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(file);

	free(buf);

	return (nwr);
}

