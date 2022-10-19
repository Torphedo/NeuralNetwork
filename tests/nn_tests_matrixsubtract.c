#include <matrix.h>

int main()
{
    matrix_t* m1 = matrix_create(4, 4);
    matrix_t* m2 = matrix_create(4, 4);
    matrix_t* m3 = matrix_create(3, 3);

    matrix_random_fill(m1);
    matrix_random_fill(m2);
    matrix_random_fill(m3);
    matrix_t* sum = matrix_subtract(m1, m2);

    if (matrix_subtract(m2, m3) != (void*) 0)
    {
        // Matrix add with mismatching dimensions should return NULL
        matrix_free(m1);
        matrix_free(m2);
        matrix_free(m3);
        matrix_free(sum);
        return 1;
    }


    for (unsigned int i = 0; i < m1->rows; i++)
    {
        for (unsigned int j = 0; j < m1->columns; j++)
        {
            if (sum->data[i * m1->columns + j] != m1->data[i * m1->columns + j] - m2->data[i * m1->columns + j])
            {
                matrix_free(m1);
                matrix_free(m2);
                matrix_free(m3);
                matrix_free(sum);
                return 1;
            }
        }
    }
    matrix_free(m1);
    matrix_free(m2);
    matrix_free(m3);
    matrix_free(sum);
    return 0;
}
