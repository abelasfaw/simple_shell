#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
int _strcat(char *des, char *src);
int _strlen(char *str);
void _puts(char *str);
int build_argument_vector(words *head, char *argv[])
{
	int index;

	index  = 0;
	if (head == NULL)
	{
		return (-1);
	}
	while (head->next != NULL)
	{
		words *prev;
		argv[index] = head->word;
		prev = head;
		head = head->next;
		index += 1;
		free(prev);
	}
	argv[index] = strtok(head->word, "\n");
	argv[index + 1] = NULL;
	free(head);
	return(0);
}
char *create_complete_path(char *command)
{
	char *complete_path;
	char bin_path[]= "/bin/";
	int index, index2;
	char ch;

	index = index2 = 0;
	complete_path = malloc(sizeof(char) * (_strlen(bin_path) + _strlen(command) + 1));
	if (complete_path == NULL)
	{
		_puts("Malloc error\n");
		return (NULL);
	}
	ch = *(bin_path + index);
	while (ch != '\0')
	{
		complete_path[index] = ch;
		index += 1;
		ch = *(bin_path + index);
	}
	ch = *(command + index2);
	while (ch != '\0')
	{
		complete_path[index] = ch;
		index += 1;
		index2 += 1;
		ch = *(command + index2);
	}
	complete_path[index] = '\0';
	return (complete_path);
}
int check_command_path(char *path)
{
	struct stat st;
	char *updated_path = NULL;

	if (stat(path, &st) == 0)
	{
		return (0);
	}
	else
	{
		updated_path = create_complete_path(path);
		if (stat(updated_path, &st) == 0)
		{
			return (1);
		}
	}
	return (-1);
}
int _strlen(char *str)
{
	int len, index;
	char ch;

	index = len = 0;
	ch = *(str + index);
	while (ch != '\0')
	{
		len += 1;
		index += 1;
		ch = *(str + index);
	}
	return (len);
}
int _strcat(char *dest, char *src)
{
	int len, index;
	char ch;

	index = 0;
	len = _strlen(dest);
	if (len > 0)
	{
		ch = *(src + index);
		while (ch != '\0')
		{
			*(dest + len + index) = ch;
			index += 1;
			ch = *(src + index);
		}
		*(dest + len + index) = '\0';
	}
	return (index);
}
int _putchar(char c)
{
	return (write(1, &c, 1));
}
void _puts(char *str)
{
	int index = 0;

	while (str[index])
	{
		_putchar(str[index]);
		index += 1;
	}
}
