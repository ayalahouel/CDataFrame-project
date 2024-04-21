#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REALLOC_SIZE 256
//part 1

COLUMN *create_column(const char *title) {
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
    column->max_size = 1;
    column->data = calloc(column->max_size, sizeof(int));
    if (column->data == NULL) {
        free(column->title);
        free(column);
        return NULL;
    }

    return column;
}

int insert_value(Column *col, int value) {
if (col == NULL) {
fprintf(stderr, "Column is NULL\n");
return 0;
}
int insert_value(COLUMN *column, int value) {
    if (column->size == column->max_size) {
        column->max_size *= 2;
        column->data = realloc(column->data, column->max_size * sizeof(int));
        if (column->data == NULL) {
            return 0;
        }
    }

    column->data[column->size] = value;
    column->size++;
    return 1;
}

void delete_column(COLUMN *column) {
    free(column->title);
    free(column->data);
    free(column);
}

void print_column(COLUMN *column) {
    for (int i = 0; i < column->size; i++) {
        printf("%d ", column->data[i]);
    }
    printf("\n");
}

int count_occurrences(Column *col, int x) {
    int count = 0;
    for (int i = 0; i < col->logical_size; i++) {
        if (col->data[i] == x) {
            count++;
        }
    }
    return count;
}

int getValueAtIndex(Column *col, int index) {
	if (index < 0 || index >= col->logical_size) {
		fprintf(stderr, "Index out of bounds\n");
		exit(EXIT_FAILURE);
}
	return col->data[index];
}

        }
    }

    return count;
}
int count_greater_than(Column *col, int x) {
	int count = 0;
	for (int i = 0; i < col->logical_size; i++) {
		if (col->data[i] > x) {
			count++;
		}
	}
return count;
}

int count_less_than(Column *col, int x) {
	int count = 0;
	for (int i = 0; i < col->logical_size; i++) {
		if (col->data[i] < x) {
			count++;
		}
	}
return count;
}
int count_equal_to(Column *col, int x) {
	int count = 0;
	for (int i = 0; i < col->logical_size; i++) {
		if (col->data[i] == x) {
			count++;
		}
}
return count;
}
//part 2

COLUMN *create_column(ENUM_TYPE type, char *title) {
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
    column->max_size = 1;
    column->column_type = type;

    switch (type) {
        case INT_TYPE:
            column->data = calloc(column->max_size, sizeof(int));
            break;
        case FLOAT_TYPE:
            column->data = calloc(column->max_size, sizeof(float));
            break;
        case STRING_TYPE:
            column->data = calloc(column->max_size, sizeof(char *));
            break;
        default:
            free(column->title);
            free(column);
            return NULL;
    }

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
        case INT_TYPE:
            col->data[col->size] = *(int *)value;
            break;
        case FLOAT_TYPE:
            col->data[col->size] = *(float *)value;
            break;
        case STRING_TYPE:
            col->data[col->size] = strdup((char *)value);
            if (col->data[col->size] == NULL) {
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
        switch ((*col)->column_type) {
            case INT_TYPE:
                break;
            case FLOAT_TYPE:
                break;
            case STRING_TYPE:
                free((*col)->data[i]);
                break;
            default:
                break;
        }
    }
    free((*col)->data);
    free((*col)->index);
    free(*col);
    *col = NULL;
}

