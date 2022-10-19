#pragma once

typedef struct
{
	float* data;
	unsigned int rows;
	unsigned int columns;
}matrix_t;

// Creates a zero-initialized matrix.
matrix_t* matrix_create(unsigned int rows, unsigned int columns);

// Frees a matrix in memory by pointer.
void matrix_free(matrix_t* matrix);

// Fills an entire matrix with a specified float value
void matrix_fill(matrix_t* matrix, float value);

// Creates & returns a copy of an existing matrix
matrix_t* matrix_copy(matrix_t* source);
