
.PHONY: clean

fasta: fasta.m.cpp fasta_record.h fasta_record.cpp
	g++ -c -I. fasta*.cpp
	g++ -o fasta.tsk fasta*.o

clean:
	rm *.tsk *.o
