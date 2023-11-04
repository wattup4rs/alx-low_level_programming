#include "hash_tables.h"

/**
 * key_index - function that maps key to indices
 * @key: a string that is to be mapped to an index
 * @size: the measure of the hash table
 *
 * Return: an unsigned long int number
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	hash = hash_djb2(key);
	return (hash % size);
}
