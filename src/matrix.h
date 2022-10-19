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

// Prints the contents of a matrix to stdout.
void matrix_print(matrix_t* matrix);

// Fills a matrix with a specified float value.
void matrix_fill(matrix_t* matrix, float value);

// Fills a matrix with randomly values between 0 and 1.
void matrix_random_fill(matrix_t* matrix);

// Creates & returns a copy of an existing matrix.
matrix_t* matrix_copy(matrix_t* source);

// Calculates and returns the dot product of 2 matrices.
matrix_t* matrix_dot(matrix_t* m1, matrix_t* m2);
