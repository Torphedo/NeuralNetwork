#include <matrix.h>
#include <string.h>

int nn_tests_matrix_copy()
{
	matrix_t* src = matrix_create(4, 4);
	matrix_random_fill(src);

	matrix_t* dest = matrix_copy(src);
	if (src->rows != dest->rows || src->columns != dest->columns) {
		matrix_free(src);
		matrix_free(dest);
		return 1;
	}
	if (memcmp(src->data, dest->data, src->columns * src->rows * sizeof(float)) != 0)
	{
		matrix_free(src);
		matrix_free(dest);
		return 1;
	}
}
