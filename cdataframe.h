#ifndef COLUMN_H
#define COLUMN_H

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

#endif /* COLUMN_H */

