#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stddef.h>
typedef struct words_list
{
	char *word;
	struct words_list* next;
} words;
int read_input(char *buffer, size_t buffer_size);
int split_string(char *str, words **head);
words *add_word_end(words **head, char *str);
int create_process();
int build_argument_vector(words *head, char *argv[]);
int check_command_path(char *path);
char *create_complete_path(char *command);
int _putchar(char c);
void _puts(char *str);
void execute(char *path, char **argv, char **env);
extern char **environ;
char *_getenv(char *name);
void _printenv(void);
int check_command(char *command, char *buffer);
void _print_error(char *str);
#endif
