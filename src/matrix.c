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

void matrix_fill(matrix_t* matrix, float value)
{
    for (unsigned int i = 0; i < matrix->rows; i++)
    {
        for (unsigned int j = 0; j < matrix->columns; j++)
        {
            matrix->data[i * matrix->columns + j] = value;
        }
    }
}

matrix_t* matrix_copy(matrix_t* source)
{
    matrix_t* destination = matrix_create(source->rows, source->columns);
    for (unsigned int i = 0; i < source->rows; i++)
    {
        for (unsigned int j = 0; j < source->columns; j++)
        {
            destination->data[i * destination->columns + j] = source->data[i * source->columns + j];
        }
    }
    return destination;
}
