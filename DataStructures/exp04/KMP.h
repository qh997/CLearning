#ifndef KMP_H
#define KMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../mydef.h"

int *get_kmp_next(char *S);
int *get_kmp_next1(char *S);
int kmp_matching(char *T, char *P);

#endif //KMP_H