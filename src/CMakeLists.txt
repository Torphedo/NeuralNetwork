cmake_minimum_required(VERSION 3.16)
project(NeuralNetwork
	VERSION 0.1.0
	LANGUAGES C
)

set(CMAKE_C_STANDARD 99)

add_executable(NeuralNetwork
	"main.c"
	"helpers.h" "helpers.c"
	"network.h"
)
