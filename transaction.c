#include <stdio.h>
#include <string.h>

#include "transaction.h"

int find_transaction(Transaction transactions[], int count,
                     const char *id)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(transactions[i].id, id) == 0)
        {
            return i;
        }
    }

    return -1;
}

const char *state_to_string(TransactionState state)
{
    switch (state)
    {
        case CREATED:
            return "CREATED";

        case PROCESSING:
            return "PROCESSING";

        case SUCCESS:
            return "SUCCESS";

        case FAILED:
            return "FAILED";

        default:
            return "UNKNOWN";
    }
}

void create_transaction(Transaction transactions[], int *count,
                        const char *id, int amount)
{
    if (id == NULL || id[0] == '\0')
    {
        printf("Error: invalid transaction ID\n");
        return;
    }

    if (amount <= 0)
    {
        printf("Error: amount must be greater than 0\n");
        return;
    }

    if (*count >= MAX_TRANSACTIONS)
    {
        printf("Error: transaction limit reached\n");
        return;
    }

    if (find_transaction(transactions, *count, id) != -1)
    {
        printf("Error: transaction ID already exists\n");
        return;
    }

    strncpy(transactions[*count].id, id, MAX_ID_LENGTH - 1);
    transactions[*count].id[MAX_ID_LENGTH - 1] = '\0';

    transactions[*count].amount = amount;
    transactions[*count].state = CREATED;

    (*count)++;

    printf("Transaction %s created\n", id);
}

void start_transaction(Transaction transactions[], int count,
                       const char *id)
{
    int index = find_transaction(transactions, count, id);

    if (index == -1)
    {
        printf("Error: transaction not found\n");
        return;
    }

    if (transactions[index].state != CREATED)
    {
        printf("Error: invalid state change\n");
        return;
    }

    transactions[index].state = PROCESSING;

    printf("Transaction %s is PROCESSING\n", id);
}

void success_transaction(Transaction transactions[], int count,
                         const char *id)
{
    int index = find_transaction(transactions, count, id);

    if (index == -1)
    {
        printf("Error: transaction not found\n");
        return;
    }

    if (transactions[index].state != PROCESSING)
    {
        printf("Error: invalid state change\n");
        return;
    }

    transactions[index].state = SUCCESS;

    printf("Transaction %s is SUCCESS\n", id);
}

void fail_transaction(Transaction transactions[], int count,
                      const char *id)
{
    int index = find_transaction(transactions, count, id);

    if (index == -1)
    {
        printf("Error: transaction not found\n");
        return;
    }

    if (transactions[index].state != PROCESSING)
    {
        printf("Error: invalid state change\n");
        return;
    }

    transactions[index].state = FAILED;

    printf("Transaction %s is FAILED\n", id);
}

void show_status(Transaction transactions[], int count,
                 const char *id)
{
    int index = find_transaction(transactions, count, id);

    if (index == -1)
    {
        printf("Error: transaction not found\n");
        return;
    }

    printf("%s | %d | %s\n",
           transactions[index].id,
           transactions[index].amount,
           state_to_string(transactions[index].state));
}

void list_transactions(Transaction transactions[], int count)
{
    if (count == 0)
    {
        printf("No transactions found\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%s | %d | %s\n",
               transactions[i].id,
               transactions[i].amount,
               state_to_string(transactions[i].state));
    }
}