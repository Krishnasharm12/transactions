# Transaction State Manager

A command-line Transaction State Manager implemented in C11.

The program allows users to create transactions and manage their lifecycle using commands such as CREATE, START, SUCCESS, FAIL, STATUS, and LIST.

## Features

- Create transactions with unique IDs
- Validate transaction amount
- Manage transaction states
- Enforce valid state transitions
- Display individual transaction status
- Display all transactions
- Handle unknown transaction IDs
- Handle invalid commands
- Handle invalid state changes
- Supports up to 1000 transactions
- Uses C structures and enums
- Modular implementation using `.h` and `.c` files

---

## State Flow

Each transaction follows this lifecycle:

```text
                START
CREATED ------------------> PROCESSING
                                /    \
                               /      \
                          SUCCESS      FAIL
                             |           |
                             v           v
                          SUCCESS      FAILED