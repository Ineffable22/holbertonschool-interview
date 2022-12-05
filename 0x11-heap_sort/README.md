# 0x11-heap_sort

# Files

### 0. Heap sort
### [0-heap_sort.c](https://github.com/Ineffable22/holbertonschool-interview/blob/main/0x11-heap_sort/0-heap_sort.c) | [0-O](https://github.com/Ineffable22/holbertonschool-interview/blob/main/0x11-heap_sort/0-O)

```C
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

```

