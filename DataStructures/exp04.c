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
        printf(" abccabccabca\n");
        for (int i = 0; i < 12; i++)
            printf("%d", next[i]);
        printf("\n");

        int m = kmp_matching("abccasabccabceabccabccabcaxe", "abccabccabca");
        show_var("%d", m);

        next = get_kmp_next("aaaaaaab");
        printf(" aaaaaaab\n");
        for (int i = 0; i < 8; i++)
            printf("%d", next[i]);
        printf("\n");

        m = kmp_matching("aaaaaaaaacaaaaaaaaaaaaab", "aaaaaaab");
        show_var("%d", m);

        next = get_kmp_next1("abccabccabca");
        printf("\n abccabccabca\n");
        for (int i = 0; i < 12; i++)
            printf("%d", next[i]);
        printf("\n");

        m = kmp_matching1("abccasabccabceabccabccabcaxe", "abccabccabca");
        show_var("%d", m);

        next = get_kmp_next1("aaaaaaab");
        printf(" aaaaaaab\n");
        for (int i = 0; i < 8; i++)
            printf("%d", next[i]);
        printf("\n");

        m = kmp_matching1("aaaaaaaaacaaaaaaaaaaaaab", "aaaaaaab");
        show_var("%d", m);

        free(next);
    }

    return 0;
}