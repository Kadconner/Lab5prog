#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define MAX_PATH 260
#define DELIM "."

void op(char* paths) { printf("new paths: %s\n", paths); }

void input(char* delim,char* paths[]) {  //, char *paths) {
	char temp[2];
	fputs("delim: ", stdout);
	fgets(temp, 2, stdin);
	*delim = temp[0];
    fputs("paths: ", stdout);
    fgets(temp, 2, stdin);
    fgets(paths, MAX_PATH * 4 + 4, stdin);
}

void procces(char delim, char* paths) {
	char piece[MAX_PATH] = "";
	char path[MAX_PATH] = "";
	char newpaths[MAX_PATH * 4] = "";
	int ipi, ipa = 0, en = 0, oldipa = 0, i, j, stand = 0, hj;
	while (en == 0) {
		for (ipi = 0, ipa; (paths[ipa] != delim) && ipa != slen(paths);
		     ++ipi) {
			piece[ipi] = paths[ipa];
			ipa++;
			if (paths[ipa] == '\0') en++;
		}
		ipa = ipa + 1;

		hj = check(piece);

		if (hj == 0) {
			int ns = 0;
			ns = chs(piece);

			for (i = 0, j = ns; piece[i] != '\0'; ++i, ++j) {
				path[i] = piece[j];
				if (path[i] == '/') path[i] = '\\';
			}

			for (i = 0, j = stand; path[i] != '\0'; ++i, ++j) {
				newpaths[j] = path[i];
			}
			stand = j;
			newpaths[stand] = '+';
			stand++;
		}
	}
	newpaths[stand - 1] = ' ';
	printf("\n");
	op(newpaths);
}

int check(char* paths) {
	if (csim(paths) == 1) {
		return 1;
	}
	if (chs(paths) == 1) {
		return 1;
	}
	if ((cip(paths) == 1) && (cdom(paths) == 1)) {
		return 1;
	}
	return 0;
}

int cdom(char* paths) {
	char a[] = ".ru";
	char a1[] = ".com";
	char* i;
	i = sstr(paths, a);
	i = sstr(paths, a1);
	if (i != NULL)
		return 0;
	else
		return 1;
}

int csim(char* paths) {
	int i, j;
	char reject[7] = {'\\', '*', '?', '\"', '<', '>', '|'};
	for (i = 0; paths[i] != '\0'; ++i) {
		for (j = 0; reject[j] != '\0'; ++j) {
			if (paths[i] == reject[j]) return 1;
		}
	}
	return 0;
}

int chs(char* paths) {
	int right = 0;
	int i;
	char a[] = "smb:";
	char a1[] = "http:";

	for (i = 0; paths[i] != '/'; ++i) {
		if (a[i] == paths[i]) right++;
	}
	if (right == 4) return right;
	right = 0;

	for (i = 0; paths[i] != '/'; ++i) {
		if (a1[i] == paths[i]) right++;
	}
	if (right == 5) return right;
	return 1;
}

int cip(char* paths) {
	char ip[20] = "";
	int ns = chs(paths) + 2, i, j;
	for (i = ns, j = 0; paths[i] != '/'; ++i, ++j) ip[j] = paths[i];
	return is_valid_ip(ip);
}

int valid_digit(char* ip_str) {
	while (*ip_str) {
		if (*ip_str >= '0' && *ip_str <= '9')
			++ip_str;
		else
			return 0;
	}
	return 1;
}

int ati(char* s) {
	int n = 0;
	while (*s >= '0' && *s <= '9') {
		n *= 10;
		n += *s++;
		n -= '0';
	}
	return n;
}

int is_valid_ip(char* ip_str) {
	int num, dots = 0;
	char* ptr;

	if (ip_str == NULL) return 1;

	ptr = stok(ip_str, DELIM);

	if (ptr == NULL) return 1;

	while (ptr) {
		if (!valid_digit(ptr)) return 1;

		num = ati(ptr);

		if (num >= 0 && num <= 255) {
			/* parse remaining string */
			ptr = stok(NULL, DELIM);
			if (ptr != NULL) ++dots;
		} else
			return 1;
	}

	if (dots != 3) return 1;
	return 0;
}

int main(int argc, char* argv[]) {
	char *paths = malloc(sizeof(char) * MAX_PATH*4);
	char delim = '+';
	/*char paths[] = {
	    "smb://192.168.1.1/test+http://mysrv.com/Windows/+http://"
	    "192.500.1.1/test+ftp.."};*/
	input(&delim,paths);//, paths);
	procces(delim, paths);

	return 0;
}
