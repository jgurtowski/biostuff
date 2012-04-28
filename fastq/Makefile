
.PHONY: clean

fastq: fastq.m.cpp fastq_record.h fastq_record.cpp
	g++ -c -I. fastq*.cpp
	g++ -o fastq.tsk fastq*.o

clean:
	rm *.tsk *.o
