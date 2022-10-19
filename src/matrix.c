#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
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

void matrix_print(matrix_t* matrix)
{
    printf("Rows: %d\nColumns: %d\n", matrix->rows, matrix->columns);
    for (unsigned int i = 0; i < matrix->rows; i++)
    {
        for (unsigned int j = 0; j < matrix->columns; j++)
        {
            printf("%f ", matrix->data[i * matrix->columns + j]);
        }
        printf("\n");
    }
    printf("\n");
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

void matrix_random_fill(matrix_t* matrix)
{
    for (unsigned int i = 0; i < matrix->rows; i++)
    {
        for (unsigned int j = 0; j < matrix->columns; j++)
        {
            matrix->data[i * matrix->columns + j] = (float) init_weight();
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

unsigned int matrix_check_dimensions(matrix_t* m1, matrix_t* m2)
{
    return (m1->columns == m2->columns && m1->rows == m2->rows);
}

matrix_t* matrix_add(matrix_t* m1, matrix_t* m2)
{
    if (matrix_check_dimensions(m1, m2))
    {
        matrix_t* sum = matrix_create(m1->rows, m1->columns);
        for (unsigned int i = 0; i < m1->rows; i++)
        {
            for (unsigned int j = 0; j < m1->columns; j++)
            {
                // sum->data[i][j] = m1->data[i][j] + m2->data[i][j];
                sum->data[i * m1->columns + j] = m1->data[i * m1->columns + j] + m2->data[i * m1->columns + j];
            }
        }
        return sum;
    }
    else
    {
        printf("Matrix addition failed! (dimension mismatch): %dx%d + %dx%d", m1->rows, m1->columns, m2->rows, m2->columns);
        return NULL;
    }
}

matrix_t* matrix_subtract(matrix_t* m1, matrix_t* m2)
{
    if (matrix_check_dimensions(m1, m2))
    {
        matrix_t* sum = matrix_create(m1->rows, m1->columns);
        for (unsigned int i = 0; i < m1->rows; i++)
        {
            for (unsigned int j = 0; j < m1->columns; j++)
            {
                // sum->data[i][j] = m1->data[i][j] - m2->data[i][j];
                sum->data[i * m1->columns + j] = m1->data[i * m1->columns + j] - m2->data[i * m1->columns + j];
            }
        }
        return sum;
    }
    else
    {
        printf("Matrix subtraction failed! (dimension mismatch): %dx%d + %dx%d", m1->rows, m1->columns, m2->rows, m2->columns);
        return NULL;
    }
}

matrix_t* matrix_scale(matrix_t* matrix, float input)
{
    matrix_t* m = matrix_copy(matrix);
    for (unsigned int i = 0; i < m->rows; i++)
    {
        for (unsigned int j = 0; j < m->columns; j++)
        {
            m->data[i * m->columns + j] *= input;
        }
    }
    return m;
}

matrix_t* matrix_add_scalar(matrix_t* matrix, float input)
{
    matrix_t* m = matrix_copy(matrix);
    for (unsigned int i = 0; i < m->rows; i++)
    {
        for (unsigned int j = 0; j < m->columns; j++)
        {
            m->data[i * m->columns + j] += input;
        }
    }
    return m;
}

matrix_t* matrix_dot(matrix_t* m1, matrix_t* m2)
{
    if (m1->columns == m2->rows)
    {
        matrix_t* product = matrix_create(m1->rows, m2->columns);
        for (unsigned int i = 0; i < m1->rows; i++)
        {
            for (unsigned int j = 0; j < m2->columns; j++)
            {
                float sum = 0;
                for (unsigned int k = 0; k < m2->rows; k++)
                {
                    sum += m1->data[i * m1->columns + k] * m2->data[k * m2->columns + j];
                }
                product->data[i * m2->columns + j] = sum;
            }
        }
        return product;
    }
    else
    {
        printf("Matrix dot product failed! (dimension mismatch): %dx%d %dx%d", m1->rows, m1->columns, m2->rows, m2->columns);
        return NULL;
    }
}
