include_directories(
	../src
)

add_executable(
	nn_tests_matrix_dot
	"nn_tests_matrix_dot.c"
	"../src/matrix.c"
	"../src/helpers.c"
)

add_executable(
	nn_tests_matrix_add
	"nn_tests_matrix_add.c"
	"../src/matrix.c"
	"../src/helpers.c"
)

add_executable(
	nn_tests_matrix_subtract
	"nn_tests_matrix_subtract.c"
	"../src/matrix.c"
	"../src/helpers.c"
)

add_executable(
	nn_tests_matrix_scale
	"nn_tests_matrix_scale.c"
	"../src/matrix.c"
	"../src/helpers.c"
)
