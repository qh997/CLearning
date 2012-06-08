#ifndef EXPXX_H
#define EXPXX_H 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

#define TITLE_WIDTH (65)
#define TITLE_LINE '-'

#define show_var(fmt, var) printf("%s = "fmt"\n", #var, var)

extern void print_title(char *title);

#endif //EXPXX_H