#include "apc.h"

/* Validate command line arguments */
int cla_validation(int argc, char *argv[])
{
    int i, start;

    if (argc != 4)
    {
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        return FAILURE;
    }

    /* Validate Operand1 */
    start = 0;
    if (argv[1][0] == '-')
        start = 1;

    if (argv[1][start] == '\0')
    {
        printf("ERROR: Invalid Operand1\n");
        return FAILURE;
    }

    for (i = start; argv[1][i] != '\0'; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("ERROR: Invalid Operand1\n");
            return FAILURE;
        }
    }

    /* Validate Operator */
    if (!(strcmp(argv[2], "+") == 0 ||
          strcmp(argv[2], "-") == 0 ||
          strcmp(argv[2], "x") == 0 ||
          strcmp(argv[2], "X") == 0 ||
          strcmp(argv[2], "*") == 0 ||
          strcmp(argv[2], "/") == 0))
    {
        printf("ERROR: Invalid Operator\n");
        return FAILURE;
    }

    /* Validate Operand2 */
    start = 0;
    if (argv[3][0] == '-')
        start = 1;

    if (argv[3][start] == '\0')
    {
        printf("ERROR: Invalid Operand2\n");
        return FAILURE;
    }

    for (i = start; argv[3][i] != '\0'; i++)
    {
        if (argv[3][i] < '0' || argv[3][i] > '9')
        {
            printf("ERROR: Invalid Operand2\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}

/* Create linked list from operand */
void create_list(char *str, node **head, node **tail)
{
    int i = 0;

    /* Ignore the '-' sign */
    if (str[0] == '-')
    {
        i = 1;
    }

    while (str[i] != '\0')
    {
        insert_last(head, tail, str[i] - '0');
        i++;
    }
}

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL;
    node *head2 = NULL, *tail2 = NULL;
    node *headR = NULL, *tailR = NULL;

int sign1 = 0, sign2 = 0;
int result_negative = 0;

/* Check sign of operand1 */
if (argv[1][0] == '-')

    sign1 = 1;

/* Check sign of operand2 */
if (argv[3][0] == '-')
    sign2 = 1;

    int negative = 0;

    if (cla_validation(argc, argv) == FAILURE)
        return FAILURE;

    create_list(argv[1], &head1, &tail1);
    create_list(argv[3], &head2, &tail2);

    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);

    printf("Operand1 : ");
    print_list(head1);

    printf("Operand2 : ");
    print_list(head2);

   switch (argv[2][0])
{
    case '+':
    {
        /* + + */
        if (!sign1 && !sign2)
        {
            addition(tail1, tail2, &headR, &tailR);
        }

        /* + - */
        else if (!sign1 && sign2)
        {
            int ret = compare_list(head1, head2);

            if (ret == OPERAND1)
                subtraction(tail1, tail2, &headR, &tailR);
            else if (ret == OPERAND2)
            {
                subtraction(tail2, tail1, &headR, &tailR);
                result_negative = 1;
            }
            else
                insert_first(&headR, &tailR, 0);
        }

        /* - + */
        else if (sign1 && !sign2)
        {
            int ret = compare_list(head1, head2);

            if (ret == OPERAND1)
            {
                subtraction(tail1, tail2, &headR, &tailR);
                result_negative = 1;
            }
            else if (ret == OPERAND2)
            {
                subtraction(tail2, tail1, &headR, &tailR);
            }
            else
                insert_first(&headR, &tailR, 0);
        }

        /* - - */
        else
        {
            addition(tail1, tail2, &headR, &tailR);
            result_negative = 1;
        }

        break;
    }

    case '-':
    {
        /* + + */
        if (!sign1 && !sign2)
        {
            int ret = compare_list(head1, head2);

            if (ret == OPERAND1)
                subtraction(tail1, tail2, &headR, &tailR);
            else if (ret == OPERAND2)
            {
                subtraction(tail2, tail1, &headR, &tailR);
                result_negative = 1;
            }
            else
                insert_first(&headR, &tailR, 0);
        }

        /* + - */
        else if (!sign1 && sign2)
        {
            addition(tail1, tail2, &headR, &tailR);
        }

        /* - + */
        else if (sign1 && !sign2)
        {
            addition(tail1, tail2, &headR, &tailR);
            result_negative = 1;
        }

        /* - - */
        else
        {
            int ret = compare_list(head1, head2);

            if (ret == OPERAND1)
            {
                subtraction(tail1, tail2, &headR, &tailR);
                result_negative = 1;
            }
            else if (ret == OPERAND2)
            {
                subtraction(tail2, tail1, &headR, &tailR);
            }
            else
                insert_first(&headR, &tailR, 0);
        }

        break;
    }

    case 'x':
    case 'X':
    case '*':
    {
        multiplication(tail1, tail2, &headR, &tailR);

        if (sign1 != sign2)
            result_negative = 1;

        break;
    }

    case '/':
    {
        division(head1, head2, &headR, &tailR);

        if (sign1 != sign2)
            result_negative = 1;

        break;
    }

    default:
        printf("Invalid Operator\n");
        return FAILURE;
}

printf("Result : ");
if (result_negative && !(headR->data == 0 && headR->next == NULL))
{
    printf("-");
}

print_list(headR);

    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return SUCCESS;
}