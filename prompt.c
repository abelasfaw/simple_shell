#include <stdio.h>
#include <stdlib.h>
int read_input(char *buffer, size_t buffer_size)
{
	ssize_t characters_read;

	characters_read = getline(&buffer, &buffer_size, stdin);
	if (characters_read == -1)
	{
		/**printf("Exiting read \n");**/
		return (-1);
	}
	return (0);
}
/**
int main(void)
{
	char *buffer;
	size_t buffer_size;
	ssize_t characters_read;

	buffer_size = 32;
	buffer = malloc(sizeof(char) * buffer_size);
	if (buffer ==NULL)
	{
		printf("Malloc error \n");
		return (-1);
	}
	printf("$ ");
	characters_read = getline(&buffer, &buffer_size, stdin);
	while (characters_read != -1)
	{
		printf("%s", buffer);
		printf("$ ");
		characters_read = getline(&buffer, &buffer_size, stdin);
	}
	free(buffer);
	return (0);	
}
**/
