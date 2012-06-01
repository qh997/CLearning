#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int age;
    int level;
} Girl;

int main () {
/*    printf("---------- EXP10 ----------\n");
    FILE *f1;
    if((f1 = fopen("../README.md", "r")) == NULL)
        printf("Can't open file!\n");
    else {
        char ch;
        while (!feof(f1)) {
            ch = fgetc(f1);
            putchar(ch);
        }
        printf("\n");
        fclose(f1);
    }

    printf("------- file string -------\n");
    f1 = fopen("../README.md", "r");
    char *string = malloc(5);
    fgets(string, 5, f1);
    printf("%s\n", string);
    fgets(string, 5, f1);
    printf("%s\n", string);

    printf("--------- binmode ---------\n");
    Girl girls[] = {"cxy", 28, 5, "xjj", 29, 4, "wxs", 29, 4, "lji", 31, 5};
    FILE *fp;
    fp = fopen("girls.dat", "wb");
//    for (int i = 0; i < sizeof(girls) / sizeof(*girls); i++)
//        if (fwrite(&girls[i], sizeof(Girl), 1, fp) != 1) 
//            printf("File write error!\n");
    fwrite(girls, sizeof(Girl), sizeof(girls) / sizeof(*girls), fp);
    fclose(fp);

    fp = fopen("girls.dat", "rb");
    Girl *mygirls = malloc(3 * sizeof(Girl));
    fread(mygirls, sizeof(Girl), sizeof(girls) / sizeof(*girls), fp);
    printf("%s\n", (mygirls + 1)->name);
    fclose(fp);

    printf("------- rewind fseek ------\n");
    fp = fopen("girls.dat", "rb");
    fclose(fp);
*/
    int *ints = malloc(sizeof(int));
    printf("%p\n", ints);
    ints = realloc(ints, 50000 * sizeof(int));
    printf("%p\n", ints);
    ints = realloc(ints, 100000 * sizeof(int));
    printf("%p\n", ints);
    ints = realloc(ints, 2000000 * sizeof(int));
    printf("%p\n", ints);
    ints = realloc(ints, 4000000 * sizeof(int));
    printf("%p\n", ints);

    return 0;
}