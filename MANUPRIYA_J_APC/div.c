#include "apc.h"

void division(node *head1, node *head2, node **headR, node **tailR)
{
    /* Check division by zero */
    if (head2 == NULL || (head2->data == 0 && head2->next == NULL))
    {
        printf("ERROR: Division by zero\n");
        return;
    }

    node *headDividend = NULL, *tailDividend = NULL;
    node *headSub = NULL, *tailSub = NULL;

    node *temp = head1;

    /* Find tail of divisor */
    node *tail2 = head2;
    while (tail2->next != NULL)
    {
        tail2 = tail2->next;
    }

    while (temp != NULL)
    {
        int count = 0;

        /* Bring down one digit */
        insert_last(&headDividend, &tailDividend, temp->data);

        remove_pre_zeros(&headDividend);

        /* Update tail of dividend */
        tailDividend = headDividend;
        while (tailDividend && tailDividend->next)
        {
            tailDividend = tailDividend->next;
        }

        /* Repeated subtraction */
        while (compare_list(headDividend, head2) != OPERAND2)
        {
            subtraction(tailDividend, tail2, &headSub, &tailSub);

            delete_list(&headDividend, &tailDividend);

            headDividend = headSub;
            tailDividend = tailSub;

            headSub = NULL;
            tailSub = NULL;

            remove_pre_zeros(&headDividend);

            /* Update tail again */
            tailDividend = headDividend;
            while (tailDividend && tailDividend->next)
            {
                tailDividend = tailDividend->next;
            }

            count++;
        }

        insert_last(headR, tailR, count);

        temp = temp->next;
    }

    remove_pre_zeros(headR);

    delete_list(&headDividend, &tailDividend);
}