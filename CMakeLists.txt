#cmake build file 
cmake_minimum_required(VERSION 2.6)

project (biostuff)

#compile subdirectories
add_subdirectory (fasta)
add_subdirectory (fastq)


#includes
include_directories ("${PROJECT_SOURCE_DIR}/fasta")
include_directories ("${PROJECT_SOURCE_DIR}/fastq")

#create executable
add_executable(biostuff biostuff.m.cpp)

#link libraries
target_link_libraries (biostuff fasta fastq)


