// fasta_record.cpp                                                   -*-C++-*-

#include <fasta_record.h>

#include <cassert>
#include <iostream>
#include <iomanip>

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
    if (stream.good()) {
        if (spacesPerLevel < 0) {
            stream << *this;
        }
        else {
            int width = level * spacesPerLevel;
            stream << std::setw(width) << ' ' << "[\n";
            stream << std::setw(width + spacesPerLevel) << ' '
                << "name = " << d_name << ",\n";
            stream << std::setw(width + spacesPerLevel) << ' '
                << "sequence = " << d_sequence << "\n";
            stream << std::setw(width) << ' ' << "]\n";
        }
    }

    return stream;
}

// FREE OPERATORS
std::istream& operator>>(std::istream& stream, Record& rhs)
{
    std::string line;
    if (getline(stream, line)) {
        if ('>' == line[0]) {
            rhs.d_name.assign(line.begin() + 1, line.end());

            std::string sequence;
            while (getline(stream, line) && '>' != stream.peek()) {
                sequence += line;
            }
            rhs.d_sequence.swap(sequence);

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
    stream << "[ " << rhs.name() << ", " << rhs.sequence() << " ]";
    return stream;
}

}  // close package namespace
