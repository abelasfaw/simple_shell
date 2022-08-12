#include <stdlib.h>
#include "main.h"
char *concat_all(char *env_name, char *separator, char *value)
{
	char *final;
	int index, index2, l1, l2, l3;

	l1 = _strlen(env_name);
	l2 = _strlen(separator);
	l3 = _strlen(value);

	final = malloc(l1 + l2 + l3 + 1);
	if (!final)
		return (NULL);

	for (index = 0; env_name[index]; index++)
		final[index] = env_name[index];
	index2 = index;

	for (index = 0; separator[index]; index++)
		final[index2 + index] = separator[index];
	index2 = index2 + index;

	for (index = 0; value[index]; index++)
		final[index2 + index] = value[index];
	index2 = index2 + index;

	final[index2] = '\0';

	return (final);
}
