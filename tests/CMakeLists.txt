include_directories(
	../src
)

add_executable(
	nn_tests_matrixdot
	"nn_tests_matrixdot.c"
	"../src/matrix.c"
	"../src/helpers.c"
)

add_executable(
	nn_tests_matrixadd
	"nn_tests_matrixadd.c"
	"../src/matrix.c"
	"../src/helpers.c"
)

add_executable(
	nn_tests_matrixsubtract
	"nn_tests_matrixsubtract.c"
	"../src/matrix.c"
	"../src/helpers.c"
)

add_executable(
	nn_tests_matrixscale
	"nn_tests_matrixscale.c"
	"../src/matrix.c"
	"../src/helpers.c"
)
