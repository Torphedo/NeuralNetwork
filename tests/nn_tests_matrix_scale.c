#include <matrix.h>

#define FACTOR 4.0f

int nn_tests_matrix_scale()
{
    matrix_t* m1 = matrix_create(2, 2);
	matrix_random_fill(m1);
    matrix_t* scaled = matrix_scale(m1, FACTOR);

    for (unsigned int i = 0; i < m1->rows; i++)
    {
        for (unsigned int j = 0; j < m1->columns; j++)
        {
            if (m1->data[i * m1->columns + j] * FACTOR != scaled->data[i * m1->columns + j])
            {
                matrix_free(m1);
                matrix_free(scaled);
                return 1;
            }
        }
    }
    matrix_free(m1);
    matrix_free(scaled);
    return 0;
}
