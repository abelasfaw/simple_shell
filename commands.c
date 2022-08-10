#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * _str_len- calculates length of a string
 * @str: string to be processed
 * Return: length of string
 */
int _str_len(const char *str)
{
	int index, len;
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
/**
 * add_node_end- adds a new node at the end of a list_t list
 * @head: addres of list_t type pointer
 * @str: string to use for struct
 * Return: address of new element, else NULL
 */
words *add_word_end(words**head, char *str)
{
	if (*(head) == NULL)
	{
		*(head) = malloc(sizeof(words));
		if (*head == NULL)
		{
			return (NULL);
		}
		(*(head))->word = str;
		(*(head))->next = NULL;
		return (*head);
	}
	else
	{
		words *current;
		words *ptr;

		current = malloc(sizeof(words));
		if (current == NULL)
		{
			return (NULL);
		}
		current->word = str;
		current->next = NULL;
		ptr = *(head);
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = current;
		return (current);
	}
}
