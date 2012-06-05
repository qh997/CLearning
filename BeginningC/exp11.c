#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_WIDTH (65)
#define TITLE_LINE '-'

void print_title(char* title);
struct Node *create_node(long value);
struct Node *add_node(struct Node *pNode, long value);
void list_nodes(struct Node *pNode);

struct Node
{
    long item;
    int count;
    struct Node *pLeft;
    struct Node *pRight;
};

int main()
{
    print_title("exp11");

    print_title("bit");
    {
        struct
        {
            unsigned int flag1 : 1;
            unsigned int flag2 : 1;
            unsigned int flag3 : 2;
            unsigned int flag4 : 3;
        } indicators;
        indicators.flag4 = 5;
        printf("%X\n", indicators.flag4);
    }

    print_title("Binary tree");
    {
        struct Node *pRoot = NULL;

        pRoot = create_node(127L);
        add_node(pRoot, 56L);
        add_node(pRoot, 99L);
        add_node(pRoot, 335L);
        add_node(pRoot, 12L);
        add_node(pRoot, 79L);
        add_node(pRoot, 997L);
        list_nodes(pRoot);
    }

    return 0;
}

void print_title(char* title)
{
    if (strlen(title) >= TITLE_WIDTH)
    {
        printf("%s\n", title);
        return;
    }

    int side = (TITLE_WIDTH - strlen(title)), fill = 0;
    fill = side % 2 == 0 ? 0 : 1;
    side /= 2; side -= 1;

    char *title_string = malloc((TITLE_WIDTH + 1) * sizeof(char));
    char *p = title_string;

    for (int i = 0; i < side; i++)
        *(p++) = TITLE_LINE;
    *(p++) = ' ';
    for (int i = 0; i < strlen(title); i++)
        *(p++) = *(title + i);
    *(p++) = ' ';
    for (int i = 0; i < side + fill; i++)
        *(p++) = TITLE_LINE;
    *p = '\0';

    printf("%s\n", title_string);

    free(title_string);
}

struct Node *create_node(long value)
{
    struct Node *pNode = (struct Node *)malloc(sizeof(struct Node));
    pNode->item = value;
    pNode->count = 1;
    pNode->pLeft = pNode->pRight = NULL;
    return pNode;
}

struct Node *add_node(struct Node *pNode, long value)
{
    if (pNode == NULL)
    {
        return create_node(value);
    }
    else
    {
        if (value == pNode->item)
        {
            pNode->count++;
            return pNode;
        }
        else if (value < pNode->item)
        {
            if (NULL == pNode->pLeft)
            {
                pNode->pLeft = create_node(value);
                return pNode->pLeft;
            }
            else
            {
                return add_node(pNode->pLeft, value);
            }
        }
        else
        {
            if (NULL == pNode->pRight)
            {
                pNode->pRight = create_node(value);
                return pNode->pRight;
            }
            else
            {
                return add_node(pNode->pRight, value);
            }
        }
    }
}

void list_nodes(struct Node *pNode)
{
    if (NULL != pNode->pLeft)
    {
        list_nodes(pNode->pLeft);
    }

    for (int i = 0; i < pNode->count; i++)
    {
        printf("%10ld\n", pNode->item);
    }
    if (NULL != pNode->pRight)
    {
        list_nodes(pNode->pRight);
    }
}