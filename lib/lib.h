#ifndef shell_lib_h
#define shell_lib_h
char *_getline();
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
/*char **_strtok(char *line, char *delim);*/
long _strtok(char ***arr, char *line, char *delim);
char *_strcat(char *s1, char *s2);
int run_commands(char ***, long);
int run(char **cmd, long size);
void free_array(char ***arr, int size);
int append_path(char ***, long);

#endif
