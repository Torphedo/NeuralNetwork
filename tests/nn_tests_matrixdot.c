#include <matrix.h>

int main()
{
	matrix_t* m1 = matrix_create(4, 2);
	matrix_t* m2 = matrix_create(2, 4);

	matrix_random_fill(m1);
	matrix_random_fill(m2);

	matrix_t* dotproduct = matrix_dot(m1, m2);

    for (unsigned int i = 0; i < m1->rows; i++)
    {
        for (unsigned int j = 0; j < m2->columns; j++)
        {
            float sum = 0;
            for (unsigned int k = 0; k < m2->rows; k++)
            {
                sum += m1->data[i * m1->columns + k] * m2->data[k * m2->columns + j];
            }
            if (sum != dotproduct->data[i * m2->columns + j])
            {
                // Fail if the result from matrix_dot() doesn't match the dot product logic here
                return 1;
            }
        }
    }
	return 0;
}
