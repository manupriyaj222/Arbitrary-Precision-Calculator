#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp2 = tail2;
    int shift = 0;

    while (temp2 != NULL)
    {
        node *temp1 = tail1;

        node *headTemp = NULL, *tailTemp = NULL;
        node *headSum = NULL, *tailSum = NULL;

        int carry = 0;

        /* Add trailing zeros according to place value */
        for (int i = 0; i < shift; i++)
        {
            insert_last(&headTemp, &tailTemp, 0);
        }

        /* Multiply one digit of operand2 with operand1 */
        while (temp1 != NULL)
        {
            int product = (temp1->data * temp2->data) + carry;

            insert_first(&headTemp, &tailTemp, product % 10);

            carry = product / 10;

            temp1 = temp1->prev;
        }

        if (carry)
        {
            insert_first(&headTemp, &tailTemp, carry);
        }

        /* First partial product */
        if (*headR == NULL)
        {
            *headR = headTemp;
            *tailR = tailTemp;
        }
        else
        {
            addition(tailTemp, *tailR, &headSum, &tailSum);

            delete_list(&headTemp, &tailTemp);
            delete_list(headR, tailR);

            *headR = headSum;
            *tailR = tailSum;
        }

        temp2 = temp2->prev;
        shift++;
    }

    remove_pre_zeros(headR);
}