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
    if (stream.good()) {
        std::string line;
        getline(stream, line);
        if ('>' == line[0]) {
            rhs.d_name.assign(line.begin() + 1, line.end());

            std::string body;
            while (stream && '>' != stream.peek()) {
                getline(stream, line);
                body += line;
            }
            rhs.d_body.swap(body);
            stream.clear();  // handle hitting EOF, 'stream' is still good here
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
