#ifndef TRANSACTION_H
#define TRANSACTION_H

#define MAX_TRANSACTIONS 1000
#define MAX_ID_LENGTH 50

typedef enum {
    CREATED,
    PROCESSING,
    SUCCESS,
    FAILED
} TransactionState;

typedef struct {
    char id[MAX_ID_LENGTH];
    int amount;
    TransactionState state;
} Transaction;

/* Transaction operations */
void create_transaction(Transaction transactions[], int *count,
                        const char *id, int amount);

void start_transaction(Transaction transactions[], int count,
                       const char *id);

void success_transaction(Transaction transactions[], int count,
                         const char *id);

void fail_transaction(Transaction transactions[], int count,
                      const char *id);

void show_status(Transaction transactions[], int count,
                 const char *id);

void list_transactions(Transaction transactions[], int count);

/* Helper functions */
int find_transaction(Transaction transactions[], int count,
                     const char *id);

const char *state_to_string(TransactionState state);

#endif