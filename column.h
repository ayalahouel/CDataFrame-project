#ifndef COLUMN_H
#define COLUMN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char title[50];
    int *data;
    int max_size;
    int size;
} Column;

Column *create_column(char *title);
int insert_value(Column *col, int value);
void delete_column(Column **col);
void print_column(Column *col);
int count_occurrences(Column *col, int x);
int getValueAtIndex(Column *col, int index);
int count_greater_than(Column *col, int x);
int count_less_than(Column *col, int x);
int count_equal_to(Column *col, int x);



typedef enum {
    NULLVAL = 1,
    UINT,
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    STRING,
    STRUCTURE
} ENUM_TYPE;

typedef union {
    unsigned int uint_value;
    int int_value;
    char char_value;
    float float_value;
    double double_value;
    char *string_value;
    void *struct_value;
} COL_TYPE;

typedef struct {
    char *title;
    unsigned int size;
    unsigned int max_size;
    ENUM_TYPE column_type;
    COL_TYPE *data;
    unsigned long long int *index;
} COLUMN;

COLUMN *create_column(ENUM_TYPE type, char *title);
int insert_value(COLUMN *col, void *value);
void delete_column(COLUMN **col);

#endif /* COLUMN_H */


