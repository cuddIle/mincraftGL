# Copyright (C) 2018 Tomasz Gałaj

cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(OpenGLExample)

# Add .lib files
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Add source files
file(GLOB_RECURSE SOURCE_FILES
	${CMAKE_SOURCE_DIR}/src/*.c
	${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add header files
file(GLOB_RECURSE HEADER_FILES
	${CMAKE_SOURCE_DIR}/src/*.h
	${CMAKE_SOURCE_DIR}/src/*.hpp)

# Configure assets header file
# configure_file(src/helpers/RootDir.h.in src/helpers/RootDir.h)
# include_directories(${CMAKE_BINARY_DIR}/src)

# Define the include DIRs
include_directories(
	"${CMAKE_SOURCE_DIR}/src"
	"${CMAKE_SOURCE_DIR}/include"
	"${CMAKE_SOURCE_DIR}/include/glfw"
	"${CMAKE_SOURCE_DIR}/include/stb_image"
	"${CMAKE_SOURCE_DIR}/include/glad"
	"${CMAKE_SOURCE_DIR}/include/glm"
	"${CMAKE_SOURCE_DIR}/include/assimp"
)

link_directories(
	${CMAKE_SOURCE_DIR}/lib/assimp
	${CMAKE_SOURCE_DIR}/lib/glfw
)

# STB_IMAGE
# add_library(STB_IMAGE "thirdparty/stb_image.cpp")

# GLAD
add_library(GLAD "thirdParty/glad.c")

# Define the executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_link_libraries(${PROJECT_NAME} GLAD glfw assimp)
target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -g)

