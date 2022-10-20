#include <matrix.h>

int nn_tests_matrix_fill()
{
	matrix_t* target = matrix_create(3, 3);
	matrix_fill(target, 5.0f);

    for (unsigned int i = 0; i < target->rows; i++)
    {
        for (unsigned int j = 0; j < target->columns; j++)
        {
            if (target->data[i * target->columns + j] != 5.0f)
            {
                matrix_free(target);
                return 1;
            }
        }
    }
    matrix_free(target);
    return 0;
}
