#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_addr - prints address
 * @ptr: ELF header
 */
void print_addr(char *ptr)
{
    int i;
    int begin;
    char sys;

    printf("  Entry point address:               0x");

    sys = ptr[4];
    if (sys == ELFCLASS32)
    {
        begin = 26;
        printf("80");
        for (i = begin; i >= 22; i--)
        {
            if (ptr[i] > 0)
                printf("%02x", ptr[i]);
            else if (ptr[i] < 0)
                printf("%02x", 256 + ptr[i]);
        }
        if (ptr[5] == ELFDATA2LSB)
            printf("00");
    }

    if (sys == ELFCLASS64)
    {
        begin = 24;
        for (i = begin; i < begin + 8; i++)
        {
            printf("%02x", ptr[i]);
        }
    }
    printf("\n");
}

/**
 * print_type - prints type
 * @ptr: ELF header
 */
void print_type(char *ptr)
{
    char type;

    if (ptr[4] == ELFCLASS32)
        type = ptr[16];
    else
        type = ptr[18];

    printf("  Type:                              ");
    if (type == ET_NONE)
        printf("NONE (No file type)\n");
    else if (type == ET_REL)
        printf("REL (Relocatable file)\n");
    else
        printf("Unknown (%d)\n", type);
}

/**
 * print_osabi - prints osabi
 * @ptr: magic.
 * Return: no return.
 */
void print_osabi(char *ptr)
{
    char osabi = ptr[7];

    printf("  OS/ABI:                            ");
    switch (osabi)
    {
        case 0:
            printf("UNIX - System V\n");
            break;
        case 2:
            printf("UNIX - NetBSD\n");
            break;
        case 6:
            printf("UNIX - Solaris\n");
            break;
        default:
            printf("<unknown: %x>\n", osabi);
            break;
    }

    printf("  ABI Version:                       %d\n", ptr[8]);
}


/**
 * print_version - prints version
 * @ptr: magic.
 * Return: no return.
 */
void print_version(char *ptr)
{
    int version = ptr[6];

    printf("  Version:                           %d",

/**
 * print_data - prints the data
 * @ptr: magic.
 * Return: no return.
 */
void print_data(char *ptr)
{
	char data = ptr[5];

	printf("  Data:       2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}
/**
 * print_magic - prints the magic info.
 * @ptr: magic.
 * Return: no return.
 */
void print_magic(char *ptr)
{
	int bytes;

	printf("  Magic:  ");

	for (bytes = 0; bytes < 16; bytes++)
		printf(" %02x", ptr[bytes]);

	printf("\n");

}

/**
 * check_sys - check the system version.
 * @ptr: magic.
 * Return: no return.
 */
void check_sys(char *ptr)
{
	char sys = ptr[4] + '0';

	if (sys == '0')
		exit(98);

	printf("ELF Header:\n");
	print_magic(ptr);

	if (sys == '1')
		printf("  Class:                             ELF32\n");

	if (sys == '2')
		printf("  Class:                             ELF64\n");

	print_data(ptr);
	print_version(ptr);
	print_osabi(ptr);
	print_type(ptr);
	print_addr(ptr);
}

/**
 * check_elf - check if it is an elf file.
 * @ptr: magic.
 * Return: 1 if it is an elf file. 0 if not.
 */
int check_elf(char *ptr)
{
	int addr = (int)ptr[0];
	char E = ptr[1];
	char L = ptr[2];
	char F = ptr[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - check the code.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file, ret_read;
	char ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	file = open(argv[1], O_RDONLY);

	if (file < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(file, 0, SEEK_SET);
	ret_read = read(file, ptr, 27);

	if (ret_read == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!check_elf(ptr))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	check_sys(ptr);
	close(file);

	return (0);
}

