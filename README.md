#EX01 - PhoneBook

A simple phonebook program in C++98 that stores up to 8 contacts.

## Features

- Store up to 8 contacts
- When full, oldest contact is automatically replaced
- Phone number validation (digits only)
- Input validation with helpful error messages
- EXIT command works anytime

## Compilation

```bash
make
```

## Usage

```bash
./phonebook
```

### Commands

- **ADD** - Add a new contact
- **SEARCH** - Search and display a contact
- **EXIT** - Quit the program (works anytime, even during index input)

### Fields

Each contact has:
- First name
- Last name
- Nickname
- Phone number (digits only)
- Darkest secret

All fields are required (non-empty).

## Example

```
=== WELCOME TO THE PHONEBOOK ===
Available commands: ADD, SEARCH, EXIT

Enter a command: ADD

First name: Alice
Last name: Smith
Nickname: Ally
Phone number: 0612345678
Darkest secret: Loves cats
Contact successfully added!

Enter a command: SEARCH

     Index|First name| Last name|  Nickname
---------------------------------------------
         0|     Alice|     Smith|      Ally

Enter the index of the contact to display (0-0) or EXIT to quit: 0

First name: Alice
Last name: Smith
Nickname: Ally
Phone number: 0612345678
Darkest secret: Loves cats

Enter a command: EXIT
Goodbye!
```

## Validation

- **Phone number**: Only digits (0-9) accepted
- **Index**: Keeps asking until valid index or EXIT
- **Commands**: Shows available commands if invalid input
- **Fields**: All fields must be non-empty

## Files

- `Contact.hpp/cpp` - Contact class
- `PhoneBook.hpp/cpp` - PhoneBook class
- `main.cpp` - Main program
- `Makefile` - Build configuration

## Technical Details

- C++98 standard
- No dynamic allocation
- Circular buffer for 8 contacts
- Compiles with `-Wall -Wextra -Werror`

By Meryl BITEE
