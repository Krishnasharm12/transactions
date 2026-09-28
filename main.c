#include <stdio.h>
#include <string.h>

#include "transaction.h"

int main(void)
{
    Transaction transactions[MAX_TRANSACTIONS];

    int transaction_count = 0;

    char command[20];
    char id[MAX_ID_LENGTH];
    int amount;

    printf("=====================================\n");
    printf("     TRANSACTION STATE MANAGER\n");
    printf("=====================================\n");
    printf("Available commands:\n");
    printf("CREATE <id> <amount>\n");
    printf("START <id>\n");
    printf("SUCCESS <id>\n");
    printf("FAIL <id>\n");
    printf("STATUS <id>\n");
    printf("LIST\n");
    printf("EXIT\n");
    printf("=====================================\n");

    while (1)
    {
        printf("> ");

        if (scanf("%19s", command) != 1)
        {
            break;
        }

        if (strcmp(command, "CREATE") == 0)
        {
            if (scanf("%49s %d", id, &amount) != 2)
            {
                printf("Error: invalid CREATE command\n");

                int ch;

                while ((ch = getchar()) != '\n' && ch != EOF)
                {
                    /* Clear invalid input */
                }

                continue;
            }

            create_transaction(
                transactions,
                &transaction_count,
                id,
                amount
            );
        }

        else if (strcmp(command, "START") == 0)
        {
            if (scanf("%49s", id) != 1)
            {
                printf("Error: invalid START command\n");
                continue;
            }

            start_transaction(
                transactions,
                transaction_count,
                id
            );
        }

        else if (strcmp(command, "SUCCESS") == 0)
        {
            if (scanf("%49s", id) != 1)
            {
                printf("Error: invalid SUCCESS command\n");
                continue;
            }

            success_transaction(
                transactions,
                transaction_count,
                id
            );
        }

        else if (strcmp(command, "FAIL") == 0)
        {
            if (scanf("%49s", id) != 1)
            {
                printf("Error: invalid FAIL command\n");
                continue;
            }

            fail_transaction(
                transactions,
                transaction_count,
                id
            );
        }

        else if (strcmp(command, "STATUS") == 0)
        {
            if (scanf("%49s", id) != 1)
            {
                printf("Error: invalid STATUS command\n");
                continue;
            }

            show_status(
                transactions,
                transaction_count,
                id
            );
        }

        else if (strcmp(command, "LIST") == 0)
        {
            list_transactions(
                transactions,
                transaction_count
            );
        }

        else if (strcmp(command, "EXIT") == 0)
        {
            printf("Exiting program...\n");
            break;
        }

        else
        {
            printf("Error: invalid command\n");
        }
    }

    return 0;
}