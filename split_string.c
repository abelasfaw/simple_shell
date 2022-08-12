#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int split_string(char *str, words **head)
{
	char *token;
	int word_count;
	
	word_count = 0;
	token = strtok(str, " ");
	if (token == NULL)
	{
		return (-1);
	}
	while (token != NULL)
	{
		add_word_end(head, token);
		word_count += 1;
		token = strtok(NULL, " ");
	}
	return (word_count);
}
