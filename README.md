# Arbitrary Precision Calculator (APC) Using C

## Project Overview

The Arbitrary Precision Calculator is a command-line application developed using C programming. It performs arithmetic operations on large integers that exceed the storage capacity of standard C data types such as `int` and `long`.

The project uses a doubly linked list to store individual digits of large numbers and performs arithmetic operations through manual algorithms.

## Features

- Addition of large integers.
- Subtraction of large integers.
- Multiplication of large integers.
- Division of large integers.
- Support for positive and negative operands.
- Command-line argument validation.
- Division-by-zero checking.
- Leading-zero removal.
- Dynamic memory allocation using linked lists.

## Technologies Used

- Programming Language: C
- Compiler: GCC
- Data Structure: Doubly Linked List
- Memory Management: Dynamic Memory Allocation
- Concepts: Pointers, Structures, Functions, Command-Line Arguments, Arithmetic Algorithms.

## Project Structure

```text
Arbitrary-Precision-Calculator/
│
├── main.c
├── apc.c
├── apc.h
├── add.c
├── sub.c
├── mul.c
├── div.c
└── README.md
```

## Compilation

Compile all source files using GCC:

```bash
gcc main.c apc.c add.c sub.c mul.c div.c -o apc
```

## Execution

General syntax:

```bash
./apc operand1 operator operand2
```

### Examples

Addition:

```bash
./apc 123456789 + 987654321
```

Subtraction:

```bash
./apc 987654321 - 123456789
```

Multiplication:

```bash
./apc 12345 x 6789
```

Division:

```bash
./apc 987654321 / 12345
```

Negative numbers:

```bash
./apc -12345 + 6789
```

## Implementation Details

### 1. Doubly Linked List
Each digit of the operand is stored in an individual node containing:
- Previous node pointer.
- Digit data.
- Next node pointer.

### 2. Addition
Adds digits from right to left and handles carry propagation.

### 3. Subtraction
Subtracts digits from right to left and handles borrowing.

### 4. Multiplication
Uses digit-by-digit multiplication and adds partial products according to their place values.

### 5. Division
Uses repeated subtraction to calculate quotient digits.

## Learning Outcomes

- Implemented a doubly linked list in C.
- Improved understanding of dynamic memory allocation.
- Developed arithmetic algorithms using linked lists.
- Practiced pointer manipulation.
- Implemented modular programming using multiple C source files.
- Improved problem-solving skills in C programming.

## Author

Manupriya J

## Project Domain

C Programming | Data Structures | Doubly Linked List | Dynamic Memory Allocation
