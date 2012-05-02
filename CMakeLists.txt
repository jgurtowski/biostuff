#cmake build file 
cmake_minimum_required(VERSION 2.6)

project (biostuff)

#compile subdirectories
add_subdirectory (sequence)
add_subdirectory (bwt)

#includes
include_directories ("${PROJECT_SOURCE_DIR}/sequence")
include_directories ("${PROJECT_SOURCE_DIR}/bwt")

#create executable
add_executable(biostuff biostuff.m.cpp)

#link libraries
target_link_libraries (biostuff sequence bwt)


