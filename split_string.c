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
/**
int main(void)
{
	int status;
	char str[20] = "ABEL ASFAW    -DINSA";
	words *head = NULL;
	status = split_string(str,&head);
	if (status == -1)
	{
		return (-1);
	}
	while (head->next != NULL)
	{
		printf("%s\n", head->word);
		head = head->next;
	}
	printf("%s\n", head->word);
	return (0);
}
*/
