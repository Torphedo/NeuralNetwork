cmake_minimum_required(VERSION 3.16)
project(NeuralNetwork
	VERSION 0.2.0
	LANGUAGES C
)
enable_testing()

set(CMAKE_C_STANDARD 99)

add_subdirectory(src)
add_subdirectory(tests)
