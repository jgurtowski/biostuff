// sequence_fasta.h

#ifndef INCLUDED_SEQUENCE_FASTA
#define INCLUDED_SEQUENCE_FASTA

//@PURPOSE: Provide an attribute class characterizing a Fasta record.
//
//@CLASSES:
//  record: attributes characterizing a Fasta record
//
//@AUTHOR: Tim Douglas (tdouglas)
//
//@SEE_ALSO:
//
//@DESCRIPTION: This component provides a (value-semantic) attribute class,
// 'Record', which characterizes a Fasta record.
//
///Attributes
///----------
//..
//  Name      Type         Default Value
//  ------    -----------  -------------
//  name      std::string  ""
//  sequence  std::string  ""
//..
//
///Usage
///-----
// This section illustrates intended usage of this component.
//
///Example 1: TBD
/// - - - - - - -

#ifndef INCLUDED_IOSFWD
#define INCLUDED_IOSFWD
#include <iosfwd>
#endif

#ifndef INCLUDED_STRING
#define INCLUDED_STRING
#include <string>
#endif

#include <sequence_generic.h>

namespace sequence {

                                // ============
                                // class Fasta
                                // ============
  class Fasta : public Generic {
    // This attribute class...

    // DATA
    std::string d_name;      // name of the record
    std::string d_sequence;  // sequence of 'A', 'C', 'G', and 'T' characters

    // FRIENDS
    friend std::istream& operator>>(std::istream&, Fasta&);

  public:
    // CREATORS
    explicit Fasta();
        // Create a new 'Fasta' object having the (default) attribute values:
        //..
        //  name()     == "";
        //  sequence() == "";
        //..

    Fasta(const std::string& name, const std::string& sequence);
        // Create a new 'Fasta' object having the specified 'name' and
        // 'sequence' attribute values.

    Fasta(const Fasta& original);
        // Create a new 'Fasta' object having the same value as the specified
        // 'original' object.

    //! ~Fasta() = default;
        // Destroy this object.

    // MANIPULATORS
    Fasta& operator=(const Fasta& rhs);
        // Set the value of this object to the value of the specified 'rhs'
        // object, and return a reference providing modifiable access to this
        // object.

    void setName(const std::string& value);
        // Set the 'name' attribute of this object to the specified 'value'.

    void setSequence(const std::string& value);
        // Set the 'sequence' attribute of this object to the specified
        // 'value'.

    void swapSequence(std::string *value);
        // Swap the contents of the sequence attribute of this object with the
        // contents of the specified 'value'.

                                  // Aspects

    // ACCESSORS
    const std::string& name() const;
        // Return a reference providing non-modifiable access to the 'name'
        // attribute of this object.

    const std::string& sequence() const;
        // Return a reference providing non-modifiable access to the 'sequence'
        // attribute of this object.

                                  // Aspects

    std::ostream& print(std::ostream& stream,
                        int           level = 0,
                        int           spacesPerLevel = 4) const;
};

// FREE OPERATORS
bool operator==(const Fasta& lhs, const Fasta& rhs);
    // Return 'true' if the specified 'lhs' and 'rhs' objects have the same
    // value and 'false' otherwise.  Two 'Fasta' objects have the same value
    // if the corresponding values of their 'sequence' and 'name' attributes have
    // the same value.

bool operator!=(const Fasta& lhs, const Fasta& rhs);
    // Return 'true' if the specified 'lhs' and 'rhs' objects do not have the
    // same value and 'false' otherwise.  Two 'Fasta' objects do not have the
    // same value if any the corresponding values of their 'sequence' and 'name'
    // attributes do not have the same value.

std::istream& operator>>(std::istream& stream, Fasta& rhs);
    // Assign to the specified 'rhs' object the value extracted from the
    // specified 'stream', and return a reference providing modifiable access
    // to 'stream'.

std::ostream& operator<<(std::ostream& stream, const Fasta& rhs);
    // Output the value of the specified 'rhs' object to the specified
    // 'stream', and return a reference providing modifiable access to
    // 'stream'.

// ============================================================================
//                        INLINE FUNCTION DEFINITIONS
// ============================================================================

                                // ------------
                                // class Fasta
                                // ------------

// CREATORS
inline
Fasta::Fasta()
: d_name()
, d_sequence()
{
}

inline
Fasta::Fasta(const std::string& name, const std::string& sequence)
: d_name(name)
, d_sequence(sequence)
{
}

inline
Fasta::Fasta(const Fasta& original)
: d_name(original.d_name)
, d_sequence(original.d_sequence)
{
}

// MANIPULATORS
inline
Fasta& Fasta::operator=(const Fasta& rhs)
{
    d_name     = rhs.d_name;
    d_sequence = rhs.d_sequence;

    return *this;
}

inline
void Fasta::setName(const std::string& value)
{
    d_name.assign(value.begin(), value.end());
}

inline
void Fasta::setSequence(const std::string& value)
{
    d_sequence.assign(value.begin(), value.end());
}

inline
void Fasta::swapSequence(std::string *value)
{
    d_sequence.swap(*value);
}

// ACCESSORS
inline
const std::string& Fasta::name() const
{
    return d_name;
}

inline
const std::string& Fasta::sequence() const
{
    return d_sequence;
}


// FREE OPERATORS
inline
bool operator==(const Fasta& lhs, const Fasta& rhs)
{
    return lhs.name()     == rhs.name()
        && lhs.sequence() == rhs.sequence();
}

inline
bool operator!=(const Fasta& lhs, const Fasta& rhs)
{
    return lhs.name()     != rhs.name()
        || lhs.sequence() != rhs.sequence();
}

}  // close package namespace

#endif
