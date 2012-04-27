
.PHONY: clean

fasta: fasta.m.cpp fasta_record.h fasta_record.cpp
	g++ -g -I. -o fasta *cpp

clean:
	rm fasta *.o
