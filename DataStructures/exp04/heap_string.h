#ifndef HEAP_STRING_H
#define HEAP_STRING_H

#include <stdlib.h>
#include "../mydef.h"

typedef struct
{
    char *ch;
    int length;
} HString;

Status InitStr(HString *T);
Status StrAssign(HString *T, const char *str);
int StrLength(const HString *T);
char *StrClone(const HString *T);
Status Concat(HString *T, const char *str);

#endif //HEAP_STRING_H