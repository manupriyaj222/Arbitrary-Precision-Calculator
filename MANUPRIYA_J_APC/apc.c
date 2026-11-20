#include "apc.h"

/* Insert at last */
int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }

    new->prev = *tail;
    (*tail)->next = new;
    *tail = new;

    return SUCCESS;
}

/* Insert at first */
int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head != NULL)
        (*head)->prev = new;
    else
        *tail = new;

    *head = new;

    return SUCCESS;
}

/* Print list */
void print_list(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n");
}

/* Compare two numbers */
int compare_list(node *head1, node *head2)
{
    int len1 = list_len(head1);
    int len2 = list_len(head2);

    if (len1 > len2)
        return OPERAND1;

    if (len2 > len1)
        return OPERAND2;

    while (head1 && head2)
    {
        if (head1->data > head2->data)
            return OPERAND1;

        if (head2->data > head1->data)
            return OPERAND2;

        head1 = head1->next;
        head2 = head2->next;
    }

    return SAME;
}

/* Remove leading zeros */
void remove_pre_zeros(node **head)
{
    if (*head == NULL)
        return;

    while ((*head)->data == 0 && (*head)->next != NULL)
    {
        node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

/* Find length of list */
int list_len(node *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

/* Delete complete list */
int delete_list(node **head, node **tail)
{
    if (*head == NULL)
        return FAILURE;

    node *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *tail = NULL;

    return SUCCESS;
}