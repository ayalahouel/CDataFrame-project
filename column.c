#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REALLOC_SIZE 256

COLUMN *create_column(ENUM_TYPE type, const char *title) {
    COLUMN *column = (COLUMN *)malloc(sizeof(COLUMN));
    if (column == NULL) {
        return NULL;
    }

    column->title = strdup(title);
    if (column->title == NULL) {
        free(column);
        return NULL;
    }

    column->size = 0;
    column->max_size = REALLOC_SIZE;
    column->column_type = type;

    column->data = (COL_TYPE *)calloc(column->max_size, sizeof(COL_TYPE));
    if (column->data == NULL) {
        free(column->title);
        free(column);
        return NULL;
    }

    column->index = NULL;
    return column;
}

int insert_value(COLUMN *col, void *value) {
    if (col->size == col->max_size) {
        col->max_size += REALLOC_SIZE;
        COL_TYPE *temp = realloc(col->data, col->max_size * sizeof(COL_TYPE));
        if (temp == NULL) {
            return 0;
        }
        col->data = temp;
    }

    switch (col->column_type) {
        case INT:
            col->data[col->size].int_value = *(int *)value;
            break;
        case FLOAT:
            col->data[col->size].float_value = *(float *)value;
            break;
        case STRING:
            col->data[col->size].string_value = strdup((char *)value);
            if (col->data[col->size].string_value == NULL) {
                return 0;
            }
            break;
        default:
            return 0;
    }

    col->size++;
    return 1;
}

void delete_column(COLUMN **col) {
    if (*col == NULL) return;

    free((*col)->title);
    for (unsigned int i = 0; i < (*col)->size; i++) {
        if ((*col)->column_type == STRING) {
            free((*col)->data[i].string_value);
        }
    }
    free((*col)->data);
    free((*col)->index);
    free(*col);
    *col = NULL;
}

void print_column(COLUMN *col) {
    for (unsigned int i = 0; i < col->size; i++) {
        switch (col->column_type) {
            case INT:
                printf("%d ", col->data[i].int_value);
                break;
            case FLOAT:
                printf("%f ", col->data[i].float_value);
                break;
            case STRING:
                printf("%s ", col->data[i].string_value);
                break;
            default:
                break;
        }
    }
    printf("\n");
}

int count_occurrences(COLUMN *col, int x) {
    int count = 0;
    for (unsigned int i = 0; i < col->size; i++) {
        if (col->column_type == INT && col->data[i].int_value == x) {
            count++;
        }
    }
    return count;
}

int getValueAtIndex(COLUMN *col, int index) {
    if (index < 0 || index >= col->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return col->data[index].int_value;
}

int count_greater_than(COLUMN *col, int x) {
    int count = 0;
    for (unsigned int i = 0; i < col->size; i++) {
        if (col->column_type == INT && col->data[i].int_value > x) {
            count++;
        }
    }
    return count;
}

int count_less_than(COLUMN *col, int x) {
    int count = 0;
    for (unsigned int i = 0; i < col->size; i++) {
        if (col->column_type == INT && col->data[i].int_value < x) {
            count++;
        }
    }
    return count;
}

int count_equal_to(COLUMN *col, int x) {
    int count = 0;
    for (unsigned int i = 0; i < col->size; i++) {
        if (col->column_type == INT && col->data[i].int_value == x) {
            count++;
        }
    }
    return count;
}
