#include <stdio.h>
#include "column.h"

int main() {
    COLUMN *agesColumn = create_column("Ages");

    insert_value(agesColumn, 25);
    insert_value(agesColumn, 30);
    insert_value(agesColumn, 35);

    printf("Values in the 'Ages' column: ");
    print_column(agesColumn);

    int countThirty = count_occurrences(agesColumn, 30);
    printf("Occurrences of value 30 in the 'Ages' column: %d\n", countThirty);

    int valueAtIndexOne = getValueAtIndex(agesColumn, 1);
    printf("Value at index 1 in the 'Ages' column: %d\n", valueAtIndexOne);

    int countGreaterThan28 = count_greater_than(agesColumn, 28);
    printf("Number of values greater than 28 in the 'Ages' column: %d\n", countGreaterThan28);

    delete_column(agesColumn);


    COLUMN *heightColumn = create_column(FLOAT_TYPE, "Height");

    float heights[] = {1.75, 1.80, 1.65, 1.90};
    for (int i = 0; i < sizeof(heights) / sizeof(heights[0]); i++) {
        insert_value(heightColumn, &heights[i]);
    }

    printf("Values in the 'Height' column: ");
    print_column(heightColumn);

    delete_column(&heightColumn);

    return 0;
}
