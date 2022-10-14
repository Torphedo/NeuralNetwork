#include <stdlib.h>
#include "matrix.h"

matrix_t* matrix_create(unsigned int rows, unsigned int columns)
{
    matrix_t* matrix = calloc(1, sizeof(matrix_t));
    if (matrix != NULL)
    {
        matrix->rows = rows;
        matrix->columns = columns;
        matrix->data = calloc((size_t)rows * columns, sizeof(float));
        return matrix;
    }
    else
    {
        printf("CRITICAL: Failed to allocate matrix buffer!\nRows: %d\nColumns: %d\nTotal Size: %d bytes\n", rows, columns, rows * columns * (unsigned int)sizeof(float));
        return -1;
    }
}

void matrix_free(matrix_t* matrix)
{
    free(matrix->data);
    free(matrix);
    matrix = NULL;
    return;
}
