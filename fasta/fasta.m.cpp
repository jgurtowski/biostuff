// fasta.m.cpp                                                        -*-C++-*-

#include <fasta_record.h>

#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char **argv)
{
    std::istream_iterator<fasta::Record> b(std::cin), e;
    std::vector<fasta::Record> records(b, e);

    std::ostream_iterator<fasta::Record> out(std::cout, "\n");
    std::copy(records.begin(), records.end(), out);
}
