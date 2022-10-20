include_directories(
	../src
)

# Generate test driver with a list of all source files / functions
create_test_sourcelist (UnitTests
  "CommonCTests.c" # Test driver file that makes up the main() function and takes arguments to run unit tests
  "nn_tests_matrix_add.c"
  "nn_tests_matrix_add_scalar.c"
  "nn_tests_matrix_dot.c"
  "nn_tests_matrix_scale.c"
  "nn_tests_matrix_subtract.c"
)

# Single executable that contains all unit tests
add_executable (CommonCTests ${UnitTests} "../src/matrix.c" "../src/helpers.c")

# Don't include the test driver (CommonCTests.c) as a unit test
remove (UnitTests "CommonCTests.c")

# Add every source file as its own unit test
foreach (test ${UnitTests})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND CommonCTests ${TName})
endforeach ()
