#include <stdio.h>
#include "column.h"

int main() {
    
    COLUMN *ageColumn = create_column("Age");

    
    insert_value(ageColumn, 25);
    insert_value(ageColumn, 30);
    insert_value(ageColumn, 35);

    
    printf("Values in the 'Age' column: ");
    print_column(ageColumn);

    
    int countThirty = count_occurrences(ageColumn, 30);
    printf("Occurrences of value 30 in the 'Age' column: %d\n", countThirty);

    int valueAtIndexOne = getValueAtIndex(ageColumn, 1);
    printf("Value at index 1 in the 'Age' column: %d\n", valueAtIndexOne);

    int countGreaterThan28 = count_greater_than(ageColumn, 28);
    printf("Number of values greater than 28 in the 'Age' column: %d\n", countGreaterThan28);

    delete_column(&ageColumn);

    return 0;
}
