#include "hash_tables.h"

/**
 * hahs_table_get - function that enables access of values referenced by keys
 * @ht: hash table from which data is to be retrieved
 * @key: a string that referenced a value in the hash table
 *
 * Return: a string value
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index, size;
	hash_node_t *node;
	char *value = NULL;

	if (!ht)
		return (NULL);
	size = ht->size;
	index = key_index((unsigned char *)key, size);
	if (!ht->array[index])
		return (NULL);

	node = ht->array[index];
	while (node)
	{
		if (!strcmp(node->key, key))
			value = node->value;
		node = node->next;
	}
	return (value);
}
