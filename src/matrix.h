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

// Applies a function to every element of a matrix. The function must return a float and take 1 float argument.
matrix_t* matrix_apply_function(matrix_t* input, float (*function)(float));

// Fills a matrix with a specified float value.
void matrix_fill(matrix_t* matrix, float value);

// Fills a matrix with randomly values between 0 and 1.
void matrix_random_fill(matrix_t* matrix);

// Creates & returns a copy of an existing matrix.
matrix_t* matrix_copy(matrix_t* source);

// Writes a matrix to a binary file at the specified path.
void matrix_save_binary(matrix_t* matrix, char* filepath);

// Writes a matrix to a human-readable text file at the specified path.
void matrix_save_text(matrix_t* matrix, char* filepath);

// Loads a matrix from a binary file at the spcified path and returns it.
matrix_t* matrix_load_binary(char* filepath);

// Loads a matrix from a text file at the spcified path and returns it.
matrix_t* matrix_load_text(char* filepath);

// Returns 1 if the 2 matrices have the same dimensions, and 0 if not.
unsigned int matrix_check_dimensions(matrix_t* m1, matrix_t* m2);

// Adds 2 matrices with the same dimensions together.
matrix_t* matrix_add(matrix_t* m1, matrix_t* m2);

// Subtracts a matrix from another matrix of the same size. m2 is subtracted from m1.
matrix_t* matrix_subtract(matrix_t* m1, matrix_t* m2);

// Multiplies every element in a matrix by the inputted value.
matrix_t* matrix_scale(matrix_t* matrix, float input);

// Increments every element in a matrix by the inputted value.
matrix_t* matrix_add_scalar(matrix_t* matrix, float input);

// Calculates and returns the dot product of 2 matrices.
matrix_t* matrix_dot(matrix_t* m1, matrix_t* m2);
