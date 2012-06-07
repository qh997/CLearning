#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 0
#define PAGE_HEIGHT 20
#define PAGE_WIDTH 80
#define BAR_SPACE 1

#if DEBUG
#define show_var(fmt, var) printf("%s = "fmt"\n", #var, var)
#define show_log(var) printf("%s\n", var);
#else
#define show_var(fmt, var)
#define show_log(var)
#endif

typedef struct SingleChar
{
    unsigned char value;
    unsigned int count;
    struct SingleChar *p_left;
    struct SingleChar *p_right;
} s_char;

typedef struct CharList
{
    unsigned char value;
    unsigned int count;
    struct CharList *pnext;
} charlist;

void get_char_in_file(s_char *phead, FILE *pfile);
s_char *add_char(s_char *phead, char value);
s_char *creat_char(char value);
void list_chars(s_char *proot);
void bar_chart(int page_height, int width, s_char *proot);
int get_chars_count(s_char *proot);
int get_max(s_char *proot);
int get_min(s_char *proot);
charlist *get_char_list(s_char *proot);

int main(int argc, char *argv[])
{
    s_char *p_charlist = NULL;
    bool filefind = false;

    if (1 < argc)
    {
        p_charlist = creat_char(0);
        for (int i = 1; i < argc; ++i)
        {
            printf("Analyze - %s\n", argv[i]);
            show_var("%s", argv[i]);

            FILE *pfile = NULL;
            if (NULL == (pfile = fopen(argv[i], "r")))
            {
                printf("Can't open the file : %s\n", argv[i]);
            }
            else
            {
                get_char_in_file(p_charlist, pfile);
                filefind = true;

                fclose(pfile);
            }
        }
    }
    else
    {
        p_charlist = creat_char(0);
        char c = '\0', *filename = malloc(FILENAME_MAX + 1), *pfn = filename;
        fflush(stdout);
        while (EOF != (c = getchar()))
        {
            if ('\n' != c)
            {
                *pfn = c;
                *(++pfn) = '\0';
            }
            else
            {
                printf("Analyze - %s\n", filename);
                show_var("%s", filename);

                FILE *pfile = NULL;
                fflush(stdout);
                if (NULL == (pfile = fopen(filename, "r")))
                {
                    printf("Can't open the file : %s\n", filename);
                }
                else
                {
                    get_char_in_file(p_charlist, pfile);
                    filefind = true;

                    fclose(pfile);
                }
                pfn = filename;
                *pfn = '\0';
            }
        }

        free(filename);
    }

    if (filefind)
    {
        list_chars(p_charlist);
        bar_chart(PAGE_HEIGHT, PAGE_WIDTH, p_charlist);
    }

    return 0;
}

void get_char_in_file(s_char *proot, FILE *pfile)
{
    show_log("=> get_char_in_file");
    char current_char = '\0';
    while (EOF != (current_char = fgetc(pfile)))
    {
        if (isalpha(current_char))
        {
            //show_var("%c", current_char);
            add_char(proot, toupper(current_char));
        }
    }
    show_var("%p", proot);
    show_log("<= get_char_in_file");
}

s_char *add_char(s_char *proot, char value)
{
    if ('\0' == proot->value)
    {
        proot->value = value;
        proot->count = 1;
        return proot;
    }

    if (value == proot->value)
    {
        proot->count++;
        return proot;
    }
    else if (value < proot->value)
    {
        if (NULL == proot->p_left)
        {
            proot->p_left = creat_char(value);
            return proot->p_left;
        }
        else
        {
            return add_char(proot->p_left, value);
        }
    }
    else
    {
        if (NULL == proot->p_right)
        {
            proot->p_right = creat_char(value);
            return proot->p_right;
        }
        else
        {
            return add_char(proot->p_right, value);
        }
    }
}

s_char *creat_char(char value)
{
    show_log("=> creat_char");
    show_var("%c", value);
    s_char *pschar = (s_char *)malloc(sizeof(s_char));

    assert(NULL != pschar);

    if ('\0' == value)
    {
        pschar->value = '\0';
        pschar->count = 0;
    }
    else
    {
        pschar->value = value;
        pschar->count = 1;
    }
    pschar->p_left = NULL;
    pschar->p_right = NULL;
    show_log("<= creat_char");
    return pschar;
}

void list_chars(s_char *proot)
{
    if (NULL != proot->p_left)
    {
        list_chars(proot->p_left);
    }

#if DEBUG
    printf("%c : %3d\n", proot->value, proot->count);
#endif

    if (NULL != proot->p_right)
    {
        list_chars(proot->p_right);
    }
}

void bar_chart(int height, int width, s_char *proot)
{
    int max = get_max(proot);
    int vert_scale = (max - get_min(proot)) / height;
    int chars_count = get_chars_count(proot);
    show_var("%d", max);
    show_var("%d", vert_scale);
    show_var("%d", chars_count);

    int bar_width = (width / chars_count) - BAR_SPACE;
    bar_width = 0 >= bar_width ? 1 : bar_width;
    show_var("%d", bar_width);

    char *column = NULL, *blank = NULL;
    assert (NULL != (column = malloc((bar_width + BAR_SPACE + 1) * sizeof(char))));
    assert (NULL != (blank = malloc((bar_width + BAR_SPACE + 1) * sizeof(char))));

    for (int i = 0; i < bar_width; i++)
        *(column + i) = '#';
    for (int i = bar_width; i < bar_width + BAR_SPACE; i++)
        *(column + i) = ' ';
    *(column + bar_width + BAR_SPACE) = '\0';
    show_var("[%s]", column);

    for (int i = 0; i < bar_width + BAR_SPACE; i++)
        *(blank + i) = ' ';
    *(blank + bar_width + BAR_SPACE) = '\0';

    charlist *char_list = get_char_list(proot);
    show_var("%p", char_list);

    int position = max;

    printf(" ^\n");
    for (int i = height; height > 0; height--)
    {
        printf(" |");
        charlist *plast = char_list;
        while (NULL != plast->pnext)
        {
            printf("%s", position <= plast->count ? column : blank);
            plast = plast->pnext;
        }
        printf("\n");
        position -= vert_scale;
    }

    printf(" +");
    for (int i = 0; i <= width; i++)
        printf("-");
    printf(">\n");

    printf("  ");
    charlist *plast = char_list;
    while (NULL != plast)
    {
        printf("%c", plast->value);
        for (int i = 0; i < bar_width + BAR_SPACE - 1; i++)
            printf(" ");
        plast = plast->pnext;
    }
    printf("\n");
}

int get_chars_count(s_char *proot)
{
    int chars_count = 0;
    if ('\0' != proot->value && 0 < proot->count)
        chars_count++;

    if (proot->p_left)
    {
        chars_count += get_chars_count(proot->p_left);
    }
    if (proot->p_right)
    {
        chars_count += get_chars_count(proot->p_right);
    }

    return chars_count;
}

int get_max(s_char *proot)
{
    int max = proot->count;

    if (proot->p_left)
    {
        int max_tmp = get_max(proot->p_left);
        max = max_tmp > max ? max_tmp : max;
    }
    if (proot->p_right)
    {
        int max_tmp = get_max(proot->p_right);
        max = max_tmp > max ? max_tmp : max;
    }

    return max;
}

int get_min(s_char *proot)
{
    int min = proot->count;

    if (proot->p_left)
    {
        int min_tmp = get_min(proot->p_left);
        min = min_tmp < min ? min_tmp : min;
    }
    if(proot->p_right)
    {
        int min_tmp = get_min(proot->p_right);
        min = min_tmp < min ? min_tmp : min;
    }

    return min;
}

charlist *get_char_list(s_char *proot)
{
    charlist *clroot = NULL;

    if (NULL != proot->p_left)
    {
        clroot = get_char_list(proot->p_left);
    }

    if (NULL == clroot)
    {
        clroot = malloc(sizeof(charlist));
        clroot->value = proot->value;
        clroot->count = proot->count;
        clroot->pnext = NULL;
    }
    else
    {
        charlist *cllast = clroot;
        while (NULL != cllast->pnext)
            cllast = cllast->pnext;

        cllast->pnext = malloc(sizeof(charlist));
        cllast = cllast->pnext;
        cllast->value = proot->value;
        cllast->count = proot->count;
        cllast->pnext = NULL;
    }

    if (NULL != proot->p_right)
    {
        charlist *cllast = clroot;
        while (NULL != cllast->pnext)
            cllast = cllast->pnext;
        cllast->pnext = get_char_list(proot->p_right);
    }

    return clroot;
}