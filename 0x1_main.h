#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char **environ;

/* PROTOTYPES IN ORDER OF USAGE */

/* Print functions */
int print_str(int file_desc, char *buffer);
int print_int(int i, int n);

/* Exit & Tokenization functionS */
int exit_shell(char *buffer);
void tokenize(char *buffer, char **my_token);

/* Fork and Execute functions*/
void _fork(char *err_name, char **my_token, char *env[]);
void execute_command(char *err_name, char **my_token, char *env[]);

/* Path functions */
char *get_path(char *command);
char *path_location(char *my_path, char *command);

/* Getenv & Error functions */
char *_getenv(const char *buffer);
int pere_error(char *err_name, char **my_token, int err_num);

/* Custom String.h functions */
int _strlen(char *buffer);
int _strncmp(const char *destination, char *source, int num);
char *_strcpy(char *destination, char *source);
char *_strcat(char *destination, char *source);
char *_strstr(char *haystack, char *needle);

#endif

