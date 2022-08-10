#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
int check_command(char *command);
int compare_string(char *str1, char *str2);
char *_getenv(char *name)
{
	int i, j;
	char *env;
	if (!name)
	{
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
				{
					break;
				}
				j++;
			}	
			if (name[j] == '\0')
			{
				env= (environ[i] + j + 1);
				return (env);
			}
		}
	}
	return (0);
}
int check_command(char *command)
{
	if (compare_string("env", command) == 0)
	{
		_printenv();
		return (0);
	}
	else if (compare_string("exit", command) == 0)
	{
		exit(0);
	}
	return (-1);
}
int compare_string(char *str1, char *str2)
{
	int index = 0;

	if (str1 == NULL || str2 == NULL)
	{
		return (-1);
	}
	
	while (str1[index] != '\0')
	{
		if (str1[index] != str2[index])
		{
			return (-1);
		}
		index += 1;
	}
	if (str1[index] == '\0' && str2[index] != '\0')
	{
		return (-1);
	}
	return (0);
}
void _printenv(void)
{
	int index = 0;
	while (environ[index] != NULL)
	{
		_puts(environ[index]);
		_puts("\n");
		index += 1;
	}
}