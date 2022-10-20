#include <matrix.h>

int nn_tests_matrix_add_scalar()
{
    matrix_t* m1 = matrix_create(2, 2);
    matrix_random_fill(m1);
    matrix_t* sum = matrix_add_scalar(m1, 5);

    for (unsigned int i = 0; i < m1->rows; i++)
    {
        for (unsigned int j = 0; j < m1->columns; j++)
        {
            if (m1->data[i * m1->columns + j] + 5 != sum->data[i * m1->columns + j])
            {
                matrix_free(m1);
                matrix_free(sum);
                return 1;
            }
        }
    }
    matrix_free(m1);
    matrix_free(sum);
    return 0;
}
