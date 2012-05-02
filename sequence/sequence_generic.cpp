//sequence_generic.cpp

#include <sequence_generic.h>

#include <cassert>
#include <iostream>
#include <iomanip>

namespace sequence {

                                // ------------
                                // class Generic
                                // ------------

// ACCESSORS

                                  // Aspects

std::ostream& Generic::print(std::ostream& stream,
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
                   << "name = " << name() << ",\n";
            stream << std::setw(width + spacesPerLevel) << ' '
                   << "sequence = " << sequence() << "\n";
            stream << std::setw(width) << ' ' << "]\n";
        }
    }

    return stream;
}

// FREE OPERATORS

std::ostream& operator<<(std::ostream& stream, const Generic& rhs)
{
    stream << "[ " << rhs.name() << ", " << rhs.sequence() << " ]";
    return stream;
}

}  // close package namespace
