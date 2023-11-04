#inclue "hash_tables.h"

/**
 * hash_table_delete - delete the existing hash table
 * @ht: hash table to be deleted
 *
 * Return: Nothing
 */

void hash_table_delte(hash_table_t *ht)
{
	unsigned long int index, size;
	hash_node_t *node, *temp_node;

	size = ht->size;
	for (index = 0; index < size; index++)
	{
		node = ht->array[index];
		while (node)
		{
			temp_node = node;
			free(temp_node);
			node = node->next;
		}
		ht->array[index] = NULL;
	}
	free(ht->array);
	free(ht);
}
