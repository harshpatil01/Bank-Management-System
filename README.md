
# Bank Management System in C

This project is a **Bank Management System** implemented in C, designed to manage customer accounts, including adding records, updating information, and managing deposits. It is a console-based application with a menu-driven interface.

## Features
- **Create Accounts**: Add new customer records with details like name, age, address, phone number, and initial deposit.
- **Account Types**:
  - Saving Account
  - Current Account
  - Fixed Deposit (1, 2, or 3 years)
- **User-Friendly Menu**: Navigate through different options easily with numbered prompts.
- **Validation**: Ensures inputs like dates, ages, and account details are valid.

## Instructions

### Prerequisites

- [GCC (GNU Compiler Collection)](https://gcc.gnu.org/) installed on your system.

### Clone Repository

```bash
git https://github.com/harshpatil01/Bank-Management-System.git
cd Bank-Management-System
```

### Compile and Run

```bash
gcc main.c menu.c edit.c erase.c see.c interest.c new_acc.c view_list.c transact.c close_program.c -o banking_system
./banking_system
```

### Password

The default password is "password"

```plaintext
Enter the password to login:
Password: password
```

## Contributors

- [Harsh P](https://github.com/harshpatil01)


