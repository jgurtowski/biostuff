// fasta_record.cpp                                                   -*-C++-*-

#include <fasta_record.h>

#include <cassert>
#include <iostream>

namespace fasta {

                                // ------------
                                // class Record
                                // ------------

// ACCESSORS

                                  // Aspects

std::ostream& Record::print(std::ostream& stream,
                            int           level,
                            int           spacesPerLevel) const
{
    return stream;
}

// FREE OPERATORS
std::istream& operator>>(std::istream& stream, Record& rhs)
{
    std::string line;
    if (getline(stream, line)) {
        if ('>' == line[0]) {
            rhs.d_name.assign(line.begin() + 1, line.end());

            std::string body;
            while (getline(stream, line) && '>' != stream.peek()) {
                body += line;
            }
            rhs.d_body.swap(body);

            // We read a complete record; even if we hit EOF, mark 'stream'
            // good.

            stream.clear();
        }
        else {
            stream.clear(std::ios_base::failbit);
        }
    }
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Record& rhs)
{
    stream << "[ " << rhs.name() << ", " << rhs.body() << " ]";
    return stream;
}

}  // close package namespace
