#include <unistd.h>
#include <stdio.h>
int create_process()
{
	pid_t process_id;

	process_id = fork();
	if (process_id == -1)
	{
		printf("Fork error \n");
		return (-1);
	}
	return (process_id);
}
