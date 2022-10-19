cmake_minimum_required(VERSION 3.16)
project(NeuralNetwork
	VERSION 0.1.0
	LANGUAGES C
)
enable_testing()

set(CMAKE_C_STANDARD 99)

add_subdirectory(src)
add_subdirectory(tests)

add_test(
	NAME nn_tests_matrix_dot
	COMMAND nn_tests_matrix_dot
)
add_test(
	NAME nn_tests_matrix_add
	COMMAND nn_tests_matrix_add
)
add_test(
	NAME nn_tests_matrix_subtract
	COMMAND nn_tests_matrix_subtract
)
add_test(
	NAME nn_tests_matrix_scale
	COMMAND nn_tests_matrix_scale
)
add_test(
	NAME nn_tests_matrix_add_scalar
	COMMAND nn_tests_matrix_add_scalar
)
