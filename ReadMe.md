# CDataFrame: Your Data Analysis Companion

Welcome to CDataFrame, your gateway to efficient data management and analysis in C. This library is designed to simplify handling and manipulation of tabular data, akin to a DataFrame in Python's Pandas library. Whether you're crunching numbers or analyzing trends, CDataFrame has got you covered.

## Quick Start

**Prerequisites:**

- C compiler (GCC recommended)
- Basic understanding of C programming language
- Include "column.h" in your project directory

**Import Statements:**

1. **`#include "column.h"`**
    - **Purpose:** Includes the necessary header file for using the Column struct and related functions.
    - **Importance:** Essential for utilizing the functionalities provided by CDataFrame.
2. **`#include <stdio.h>`**
    - **Purpose:** Provides standard input/output functionalities.
    - **Importance:** Necessary for printing data and error messages to the console.
3. **`#include <stdlib.h>`**
    - **Purpose:** Enables dynamic memory allocation and other standard functions.
    - **Importance:** Required for memory management and standard functions used in the library.
4. **`#include <string.h>`**
    - **Purpose:** Supports string manipulation functions.
    - **Importance:** Essential for handling strings, particularly in column titles and data.

## Usage Guide

### Part 1: Basic Operations

**Functions Overview:**

1. `COLUMN *create_column(const char *title)`
    - **Description:** Creates a new column with the specified title.
    - **Parameters:** Title of the column.
    - **Returns:** Pointer to the created column.
2. `int insert_value(COLUMN *col, int value)`
    - **Description:** Inserts a value into the specified column.
    - **Parameters:** Pointer to the column, value to be inserted.
    - **Returns:** Status code indicating success or failure.
3. `void delete_column(COLUMN *column)`
    - **Description:** Deletes the specified column and frees memory.
    - **Parameters:** Pointer to the column to be deleted.
4. `void print_column(COLUMN *column)`
    - **Description:** Prints the values of the specified column to the console.
    - **Parameters:** Pointer to the column to be printed.
5. `int count_occurrences(COLUMN *col, int x)`
    - **Description:** Counts the occurrences of a specific value in the column.
    - **Parameters:** Pointer to the column, value to be counted.
    - **Returns:** Number of occurrences.
6. `int getValueAtIndex(COLUMN *col, int index)`
    - **Description:** Retrieves the value at the specified index in the column.
    - **Parameters:** Pointer to the column, index of the value.
    - **Returns:** Value at the specified index.
7. `int count_greater_than(COLUMN *col, int x)`
    - **Description:** Counts the number of values greater than a given value in the column.
    - **Parameters:** Pointer to the column, value for comparison.
    - **Returns:** Number of values greater than the given value.
8. `int count_less_than(COLUMN *col, int x)`
    - **Description:** Counts the number of values less than a given value in the column.
    - **Parameters:** Pointer to the column, value for comparison.
    - **Returns:** Number of values less than the given value.
9. `int count_equal_to(COLUMN *col, int x)`
    - **Description:** Counts the number of values equal to a given value in the column.
    - **Parameters:** Pointer to the column, value for comparison.
    - **Returns:** Number of values equal to the given value.

### Part 2: Enhanced Functionality

**Functions Overview:**

1. `COLUMN *create_column(ENUM_TYPE type, char *title)`
    - **Description:** Creates a new column with specified type and title.
    - **Parameters:** Type of data (INT_TYPE, FLOAT_TYPE, STRING_TYPE), title of the column.
    - **Returns:** Pointer to the created column.
2. `int insert_value(COLUMN *col, void *value)`
    - **Description:** Inserts a value of any type into the specified column.
    - **Parameters:** Pointer to the column, pointer to the value to be inserted.
    - **Returns:** Status code indicating success or failure.
3. `void delete_column(COLUMN **col)`
    - **Description:** Deletes the specified column and frees memory (enhanced version).
    - **Parameters:** Pointer to the pointer to the column to be deleted.

## Example Usage

```c
#include "column.h"
#include <stdio.h>

int main() {
    COLUMN *col = create_column("Age");

    insert_value(col, 25);
    insert_value(col, 30);
    insert_value(col, 35);

    printf("Column values: ");
    print_column(col);

    delete_column(col);

    return 0;
}

```
