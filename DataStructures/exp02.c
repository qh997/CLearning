#include "expxx.h"
#include "exp02/seqlist.h"
#include "exp02/linkedlist.h"

void print_sqlist(SqList L);
void print_llist(LinkList L);

int main(void)
{
    print_title("exp02");

    print_title("Sequential List");
    {
        SqList sq_list;
        show_var("%d", InitList_Sq(&sq_list));
        show_var("%d", ListInsert_Sq(&sq_list, 0, 23));
        show_var("%d", ListInsert_Sq(&sq_list, 0, 22));
        show_var("%d", ListInsert_Sq(&sq_list, 0, 21));
        show_var("%d", ListInsert_Sq(&sq_list, 0, 20));
        show_var("%d", ListInsert_Sq(&sq_list, 3, 55));
        show_var("%d", ListInsert_Sq(&sq_list, 4, 12));
        show_var("%d", *(sq_list.elem + 3));
        for (int i = 0; i < sq_list.length; i++)
            printf("%d ", *(sq_list.elem + i));
        printf("\n");

        int del_e;
        ListDelete_Sq(&sq_list, 1, &del_e);
        show_var("%d", del_e);
        ListDelete_Sq(&sq_list, 4, NULL);
        print_sqlist(sq_list);
    }

    print_title("Linked List");
    {
        LinkList l_list = NULL;
        ListAdd_L(&l_list, 41);
        print_llist(l_list);
        show_var("%d", l_list->data);
        int get_e;
        GetElem_L(l_list, 0, &get_e);
        show_var("%d", get_e);
        ListInsert_L(&l_list, 0, 223);
        ListInsert_L(&l_list, 2, 999);
        ListAdd_L(&l_list, 41);
        ListAdd_L(&l_list, 23);
        ListAdd_L(&l_list, 1);
        print_llist(l_list);
        ListInsert_L(&l_list, 4, 788);
        ListInsert_L(&l_list, 4, 255);
        print_llist(l_list);
        DestroyList_L(&l_list);
        show_var("%p", l_list);
    }

    return 0;
}

void print_sqlist(SqList L)
{
    for (int i = 0; i < L.length; i++)
        printf("%d ", *(L.elem + i));
    printf("\n");
}

void print_llist(LinkList L)
{
    while (NULL != L)
    {
        printf("%d ", L->data);
        L = L->next;
    }
    printf("\n");
}