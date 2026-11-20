#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int sum, carry = 0;

    while (tail1 != NULL || tail2 != NULL || carry != 0)
    {
        sum = carry;

        if (tail1 != NULL)
        {
            sum += tail1->data;
            tail1 = tail1->prev;
        }

        if (tail2 != NULL)
        {
            sum += tail2->data;
            tail2 = tail2->prev;
        }

        carry = sum / 10;
        insert_first(headR, tailR, sum % 10);
    }
}