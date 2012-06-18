#include "expxx.h"
#include "exp04/heap_string.h"
#include "exp04/KMP.h"

int main(void)
{
    print_title("exp04");

    print_title("heap String");
    {
        HString h_str;
        InitStr(&h_str);
        StrAssign(&h_str, "Hello world");
        show_var("%d", StrLength(&h_str));
        char *str = StrClone(&h_str);
        show_var("%s", str);
        free(str);

        Concat(&h_str, " changxy");
        Concat(&h_str, " xuejj");
        Concat(&h_str, " guona");
        str = StrClone(&h_str);
        show_var("%s", str);
        free(str);
    }

    print_title("KMP");
    {
        int *next = get_kmp_next("abccabccabca");
        printf("0123456789101112\n");
        printf("abccabccabca\n");
        for (int i = 0; i < 12; i++)
            printf("%d", next[i]);
        printf("\n");

        next = get_kmp_next1("abccabccabca");
        for (int i = 0; i < 12; i++)
            printf("%d", next[i]);
        printf("\n");

        next = get_kmp_next("abaabcac");
        for (int i = 0; i < 8; i++)
            printf("%d", next[i]);
        printf("\n");

        next = get_kmp_next1("abaabcac");
        for (int i = 0; i < 8; i++)
            printf("%d", next[i]);
        printf("\n");

        next = get_kmp_next("ababacb");
        for (int i = 0; i < 8; i++)
            printf("%d", next[i]);
        printf("\n");

        next = get_kmp_next1("ababacb");
        for (int i = 0; i < 8; i++)
            printf("%d", next[i]);
        printf("\n");

        //int m = kmp_matching("abccasabccabceabccabccabcase", "abccabccabca");
        //show_var("%d", m);

    }

    return 0;
}