###fasta cmake file

include_directories(".")

add_library(sequence sequence_fasta.cpp sequence_fastq.cpp sequence_generic.cpp)




