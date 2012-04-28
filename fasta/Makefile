
.PHONY: clean

fasta: fasta.m.cpp fasta_record.h fasta_record.cpp
	g++ -c -I. *.cpp
	g++ -o fasta *.o

clean:
	rm fasta *.o
