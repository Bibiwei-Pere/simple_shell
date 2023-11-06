#ifndef MAIN_H
#define MAIN_H

/* System header files */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/* Handles env */
extern char **environ;

/* PROTOTYPES IN ORDER OF USAGE */

/* Print functions */
int print_str(int file_desc, char *buffer);
int print_int(int i, int n);

/* Collects input from users */
int _getline(char **ptbuffer, size_t *buf_size);
char *_memcpy(char *destination, char *source, unsigned int num);

/* Exit & Tokenization functions */
int exit_shell(char *buffer);
void tokenize(char *buffer, char **my_token);

/* Fork and Execute functions*/
void _fork(char *program_name, char **my_token);
void execute_command(char *program_name, char **my_token);

/* Path functions */
char *get_path(char *command);
char *path_location(char *my_path, char *command);

/* Getenv & Error functions */
char *_getenv(char *buffer);
int pere_error(char *program_name, char **my_token, int err_num);

/* Custom strtok function */
char *_strtok(char *buffer, const char *delimeters);

/* Custom String.h prototypes */
int _strlen(char *buffer);
int _strncmp(const char *destination, char *source, int num);
char *_strcpy(char *destination, char *source);
char *_strcat(char *destination, char *source);
char *_strchr(const char *buffer, int character);
char *_strdup(char *buffer);

#endif

