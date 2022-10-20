#include <matrix.h>

matrix_t* m1;
matrix_t* m2;
matrix_t* m3;
matrix_t* sum;

void exit_test(int code)
{
    matrix_free(m1);
    matrix_free(m2);
    matrix_free(m3);
    matrix_free(sum);
    exit(code);
}

int main()
{
    m1 = matrix_create(4, 4);
    m2 = matrix_create(4, 4);
    m3 = matrix_create(3, 3);

    matrix_random_fill(m1);
    matrix_random_fill(m2);
    matrix_random_fill(m3);
    sum = matrix_add(m1, m2);

    if (matrix_add(m2, m3) != (void*) 0)
    {
        // Matrix add with mismatching dimensions should return NULL
        exit_test(1);
    }


    for (unsigned int i = 0; i < m1->rows; i++)
    {
        for (unsigned int j = 0; j < m1->columns; j++)
        {
            if (sum->data[i * m1->columns + j] != m1->data[i * m1->columns + j] + m2->data[i * m1->columns + j])
            {
                exit_test(1);
            }
        }
    }
    exit_test(0);
}
