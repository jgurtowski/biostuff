// fasta_record.cpp                                                   -*-C++-*-

#include <fasta_record.h>

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
    if (stream.good() && '>' == stream.peek()) {
        std::string line;
        getline(stream, line);
        rhs.d_name.assign(line.begin() + 1, line.end());

        std::string body;
        while (stream.good() && '>' != stream.peek()) {
            getline(stream, line);
            body += line;
        }
        rhs.d_body.swap(body);
        stream.clear();
    }
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Record& rhs)
{
    stream << "[ " << rhs.name() << ", " << rhs.body() << " ]";
    return stream;
}

}  // close package namespace
