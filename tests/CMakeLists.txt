include_directories(
	../src
)

add_executable(
	nn_tests_matrixdot
	"nn_tests_matrixdot.c"
	"../src/matrix.c"
	"../src/helpers.c"
)
