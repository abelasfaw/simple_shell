#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>
void _isterminal(void)
{
	if(isatty(STDIN_FILENO))
	{
		_puts("$ ");
	}
}
int main(int argc, char *args[], char *env[])
{
	char *input_buffer;
	size_t buffer_size;
	int status, words_count, path_status, freed, error;
	char *argv[100];
	char *updated_path;
	/**pid_t child1;**/
	words *head;

	head = NULL;
	buffer_size = 100;
	freed = error = 0;
	input_buffer = malloc(sizeof(char) * buffer_size);
	if (input_buffer == NULL)
	{
		_puts("Malloc error \n");
		return (-1);
	}
	while (1)
	{
		_isterminal();
		status = read_input(input_buffer, buffer_size);
		if (status == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				_puts("\n");
			}
			free(input_buffer);
			if (error == 1)
			{
				exit(127);
			}
			exit(0);
		}
		words_count = split_string(input_buffer, &head);
		if (words_count == -1)
		{
			freed = 1;
			break;
		}
		if (build_argument_vector(head, argv) == -1)
		{
			break;
		}
		if (argv[0] == NULL)
		{
			head = NULL;
			continue;
		}
		if (check_command(argv, input_buffer) == 0)
		{
			head = NULL;
			continue;
		}
		head = NULL;
		path_status = check_command_path(argv[0]);
		if (path_status == -1)
		{
			_print_error(args[argc - argc]);
			_print_error(": 1: ");
			_print_error(argv[0]);
			_print_error(": not found\n");
			error = 1;
			continue;
		}
		if (path_status == 1)
		{
			updated_path = create_complete_path(argv[0]);
			execute(updated_path, argv, env);
			free(updated_path);
		}
		else
		{
			execute(argv[0], argv, env);
		}
	}
	if (head != NULL)
	{
		free(head);
	}
	if (freed != 1)
	{
		free(input_buffer);
	}
	return (0);
}
