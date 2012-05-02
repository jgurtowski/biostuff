// sequence_fastq.cpp

#include <sequence_fastq.h>

#include <cassert>
#include <iostream>

namespace sequence {

                                // ------------
                                // class Fastq
                                // ------------

// ACCESSORS

                                  // Aspects

std::ostream& Fastq::print(std::ostream& stream,
                            int           level,
                            int           spacesPerLevel) const
{
    return stream;
}

// FREE OPERATORS
std::istream& operator>>(std::istream& stream, Fastq& rhs)
{
    if (stream.good()) {

        // The expected format is:
        //..
        //  @NAME
        //  SEQUENCE
        //  +DESCRIPTION
        //  QUALITY
        //..

        bool success;
        std::string line;
        getline(stream, line);
        if (success = ('@' == line[0])) {
            rhs.d_name.assign(line.begin() + 1, line.end());

            getline(stream, rhs.d_sequence);
            getline(stream, line);
            if (success = ('+' == line[0])) {
                rhs.d_description.assign(line.begin() + 1, line.end());
                getline(stream, rhs.d_quality);

                success = rhs.d_quality.size() == rhs.d_sequence.size();
            }
        }

        if (!success) {
            stream.clear(std::ios_base::failbit);
        }
    }
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Fastq& rhs)
{
    stream << "[ "
           << rhs.name() << ", "
           << rhs.description() << ", "
           << rhs.sequence() << ", "
           << rhs.quality()
           << " ]";
    return stream;
}

}  // close package namespace
