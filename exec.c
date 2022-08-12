#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
void execute(char *path, char **argv, char **env)
{
	int fork_status, exec_status;

	if (!argv || !argv[0])
	{
		return;
	}
	fork_status = fork();
	if (fork_status == -1)
	{
		perror("fork: ");
	}
	if (fork_status == 0)
	{
		if (execve(path, argv, env) == -1)
		{
			perror(argv[0]);
			exit(2);
		}
		exit(1);
	}
	wait(&exec_status);
}
/**
int main (int argc, char *argv[], char *envp[])
{
	if (argc == 1)
	{
		printf("Invalid number of arguments \n");
		return (-1);
	}
	if (_exec_wrapper(argv[1], NULL, envp) == -1)
	{
		return (-1);
	}
	return (0);
}
**/
