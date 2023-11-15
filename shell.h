#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/stat.h>


/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built ins */
int checker(char **cmd, char *buff);
void prompt_user(void);
void handle_signal(int mm);
char **tokenizer(char *line);
char *test_path(char **the_path, char *user_command);
char *append_path(char *the_path, char *user_command);
int handle_builtin(char **user_command, char *line);
void exit_command(char **user_command, char *line);

void print_envn(void);

/* string handlers */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);

void executing(char *ucp, char **cmd);
char *find_path(void);

/* helper function for efficient free */
void free_buffers(char **buff);

struct builtin
{
	char *envn;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif /* SHELL_H */
