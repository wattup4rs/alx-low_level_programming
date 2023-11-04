/**
 * hash_djb2 - Haash function implementing the djb2 algorithm
 * @Str: The string to hash
 *
 * Return: The calculated hash.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /*hash * 33 + c */
	return (hash);
}
