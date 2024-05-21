Sure! Here's the revised README with the output included in the example usage section:

---

# CDataFrame: Your Data Analysis Companion

Welcome to CDataFrame, your go-to library for efficient data analysis in C. This README provides essential information to get you started quickly.

## Quick Start

### Prerequisites
- Compiler (GCC recommended)
- Standard C library
- Clone repository to your project directory

### Installation
1. **Clone Repository:**
    ```sh
    git clone https://github.com/username/CDataFrame.git
    ```
2. **Compile:**
    ```sh
    gcc -o cdataframe main.c cdataframe.c -I .
    ```

## Usage Guide

### Part 1: Basic Operations

#### 1. Create DataFrame
```c
CDataFrame* createDataFrame(char* columns[], int colCount);
```
- **Description:** Create a new DataFrame.
- **Parameters:** Array of column names, number of columns.
- **Returns:** Pointer to DataFrame.

#### 2. Add Row
```c
void addRow(CDataFrame* df, void* values[]);
```
- **Description:** Add a row to the DataFrame.
- **Parameters:** DataFrame pointer, array of values.

#### 3. Get Value
```c
void* getValue(CDataFrame* df, int row, int col);
```
- **Description:** Retrieve value from a specific cell.
- **Parameters:** DataFrame pointer, row index, column index.
- **Returns:** Pointer to value.

### Part 2: Enhanced Functionality

#### 1. Filter Data
```c
CDataFrame* filter(CDataFrame* df, bool (*predicate)(void* value));
```
- **Description:** Create a new DataFrame with rows that match a condition.
- **Parameters:** DataFrame pointer, function pointer to predicate.
- **Returns:** Pointer to new DataFrame.

#### 2. Group By
```c
CDataFrame* groupBy(CDataFrame* df, int colIndex);
```
- **Description:** Group DataFrame by a column.
- **Parameters:** DataFrame pointer, column index.
- **Returns:** Pointer to grouped DataFrame.

### Example Usage
```c
#include "cdataframe.h"
#include <stdio.h>

int main() {
    char* columns[] = {"ID", "Name", "Age"};
    CDataFrame* df = createDataFrame(columns, 3);

    void* row1[] = { (void*)(intptr_t)1, "Alice", (void*)(intptr_t)30 };
    void* row2[] = { (void*)(intptr_t)2, "Bob", (void*)(intptr_t)25 };

    addRow(df, row1);
    addRow(df, row2);

    int age = (int)(intptr_t)getValue(df, 0, 2);
    printf("Age of first row: %d\n", age);

    return 0;
}
```

**Expected Output:**
```
Age of first row: 30
```

## Documentation
For detailed documentation, please visit [CDataFrame Wiki](https://github.com/username/CDataFrame/wiki).

---

This revised version includes the expected output of the example usage, providing a clearer picture of how the library works.