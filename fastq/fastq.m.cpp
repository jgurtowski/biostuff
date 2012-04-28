// fastq.m.cpp                                                        -*-C++-*-

#include <fastq_record.h>

#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char **argv)
{
    std::istream_iterator<fastq::Record> b(std::cin), e;
    std::vector<fastq::Record> records(b, e);

    std::ostream_iterator<fastq::Record> out(std::cout, "\n");
    std::copy(records.begin(), records.end(), out);
}
