#include <stdio.h>
#include <stdlib.h>
#include "string.h"


char* sstr(char* string1, char* string2) {
	char* strptr = string1;
	int j = 0, i;
	for (i = 0; string1[i] != 0; i++) {
		if (string2[j] == 0) {
			return strptr;
		}
		if (string1[i] != string2[j]) {
			j = 0;
			continue;
		}
		if (string1[i] == string2[j]) {
			if (j == 0) {
				strptr = string1 + i;
			}
			j++;
		}
	}
	if (string2[j] == 0) {
		return strptr;
	} else {
		return NULL;
	}
}

char* mystrchr(char* s, char c) {
	while (*s && *s != c) ++s;
	return (*s) ? (char*)s : NULL;
}

int slen(char* str) {
	int count = 0, i;
	for (i = 0; str[i] != '\0'; i++) {
		count++;
	}
	return count++;
}

int sspn(char* str, char* substr) {
	int count = 0, i, j;
	for (i = 0; str[i] != 0; i++) {
		for (j = 0; substr[j]; j++) {
			if (str[i] == substr[j]) {
				count++;
			}
		}
	}
	return count;
}

int scmp(char* str, char* strc) {
	int ncount = 0, pcount = 0, i;
	for (i = 0; str[i] != 0; i++) {
		if (str[i] < strc[i]) {
			ncount++;
		} else if (str[i] > strc[i]) {
			pcount++;
		}
	}
	if (ncount < pcount) {
		return pcount;
	} else if (ncount > pcount) {
		return -ncount;
	}
	return 0;
}

char* scpy(char* des, char* src) {
	int i;
	for (i = 0; src[i] != 0; i++) {
		des[i] = src[i];
	}
	des[i] = 0;
	return des;
}

char* stok(char* str, char* delim) {
	static char* next;

	if (str) {
		next = str;
		while (*next && mystrchr(delim, *next)) *next++ = '\0';
	}

	if (!*next) return NULL;

	str = next;

	while (*next && !mystrchr(delim, *next)) ++next;
	while (*next && mystrchr(delim, *next)) *next++ = '\0';

	return str;
}
