#ifndef STRING_H
#define STRING_H
#include <stdio.h>
#include <stdlib.h>


char* sstr(char* string1, char* string2);
char* mystrchr(char* s, char c);
void procces(char delim, char* paths);
int check(char* paths);
int chs(char* paths);
int csim(char* paths);
int cdom(char* paths);
int cip(char* paths);
int is_valid_ip(char* ip_str);
int valid_digit(char* ip_str);
void op(char* paths);
int slen(char* str);
int ati(char* s);
int sspn(char* str, char* substr);
int scmp(char* str, char* strc);
char* scpy(char* des, char* src);
char* stok(char* str, char* delim);

#endif
