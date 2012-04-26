// fasta.m.cpp                                                        -*-C++-*-

#include <fstream>

#include <fasta_parser.h>

int main(int argc, char **argv)
{
    std::fstream fh("test.fa",in);

    fasta::Parser parser(fh);
    for (fasta::Parser::const_iterator it = parser.begin();
            parser.end() != it; ++it) {
        std::cout << *it << std::endl;
    }
}
