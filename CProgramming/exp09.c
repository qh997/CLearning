#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    int month;
    int day;
}Date;

typedef struct {
    long int num;
    char *name;
    char sex;
    Date birthday;
}Student;

typedef struct {
    char * name;
    int count;
}Person;

typedef struct IntScalar{
    int value;
    struct IntScalar *prev;
    struct IntScalar *next;
}IntScalar;

typedef enum {
    NUMBER,
    STRING,
}ScalarType;

typedef union {
    int ivalue;
    char *cvalue;
}PerlScalar;

typedef struct {
    ScalarType type;
    PerlScalar value;
}Scalar;

void int_pipe_push (IntScalar * head, int new_val);
int int_pipe_shift (IntScalar ** head);

int main () {
    printf("---------- EXP09 ----------\n");
    Student stu1;
    stu1.num = 1001;
    stu1.name = "changxy";
    stu1.sex = 'F';
    stu1.birthday.year = 1985;
    printf("Name : %s\n", stu1.name);

    printf("------- struct array ------\n");
    printf("sizeof(char *) = %ld\n", sizeof(char *));
    printf("sizeof(int) = %ld\n", sizeof(int));
    printf("sizeof(struct Person) = %ld\n", sizeof(Person));
    void *leader;
    leader = malloc(3 * sizeof(Person));
    for (int i = 0; i < 3; i++) {
        (*((Person *)leader + i)).name = "gengs";
    }
    printf("%s\n", (((Person *)leader + 1))->name);

    printf("------- Linked list -------\n");
    IntScalar *perl_array = malloc(sizeof(IntScalar));
    perl_array->value = 1;
    perl_array->next = NULL;
    printf("%d\n", perl_array->value);
    int_pipe_push(perl_array, 2);
    printf("%d\n", perl_array->next->value);
    printf("shift = %d\n", int_pipe_shift(&perl_array));
    printf("%d\n", perl_array->value);

    printf("---------- union ----------\n");
    PerlScalar perl_scalar;
    perl_scalar.cvalue = "Hello Perl!";
    printf("%s\n", perl_scalar.cvalue);
    printf("%d\n", perl_scalar.ivalue);

    Scalar my_start;
    my_start.type = NUMBER;
    my_start.value.ivalue = 90;
    printf("%d\n", my_start.value.ivalue);

    return 0;
}

void int_pipe_push (IntScalar * head, int new_val) {
    IntScalar *search = head;
    while (NULL != search->next)
        search = search->next;

    search->next = malloc(sizeof(IntScalar));
    search->next->value = new_val;
    search->next->next = NULL;
}

int int_pipe_shift (IntScalar ** head) {
    int ret_val = (*head)->value;
    IntScalar * del = (*head);
    if ((*head)->next != NULL)
        (*head) = (*head)->next;
    else
        (*head) = NULL;
    free(del);
    return ret_val;
}