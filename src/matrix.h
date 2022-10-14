#pragma once

typedef struct
{
	float* data;
	unsigned int rows;
	unsigned int columns;
}matrix_t;

matrix_t* matrix_create(unsigned int rows, unsigned int columns);
void matrix_free(matrix_t* matrix);
