// sequence_fastq.h

#ifndef INCLUDED_SEQUENCE_FASTQ
#define INCLUDED_SEQUENCE_FASTQ

//@PURPOSE: Provide an attribute class characterizing a Fastq record.
//
//@CLASSES:
//  Fastq: attributes characterizing a Fastq record
//
//@AUTHOR: Tim Douglas (tdouglas)
//
//@SEE_ALSO:
//
//@DESCRIPTION: This component provides a (value-semantic) attribute class,
// 'Fastq', which characterizes a Fastq record.
//
///Attributes
///----------
//
//..
//  Name         Type         Default Value
//  ------       -----------  -------------
//  description  std::string  ""
//  name         std::string  ""
//  quality      std::string  ""
//  sequence     std::string  ""
//..
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

namespace sequence{

                                // ============
                                // class Fastq
                                // ============

  class Fastq : public Generic {
    // This attribute class...

    // DATA
    std::string d_description;  // the description of the sequence
    std::string d_name;         // the name of the record
    std::string d_quality;      // quality
    std::string d_sequence;     // genetic sequence

    // FRIENDS
    friend std::istream& operator>>(std::istream&, Fastq&);

  public:
    // CREATORS
    explicit Fastq();
        // Create a new 'Fastq' object having the (default) attribute values:
        //..
        //  body() == "";
        //  name() == "";
        //..

    Fastq(const std::string& description,
           const std::string& name,
           const std::string& quality,
           const std::string& sequence);
        // Create a new 'Fastq' object having the specified 'description',
        // 'name', 'quality', and 'sequence' attribute values.

    Fastq(const Fastq& original);
        // Create a new 'Fastq' object having the same value as the specified
        // 'original' object.

    //! ~Fastq() = default;
        // Destroy this object.

    // MANIPULATORS
    Fastq& operator=(const Fastq& rhs);
        // Set the value of this object to the value of the specified 'rhs'
        // object, and return a reference providing modifiable access to this
        // object.

    void setDescription(const std::string& value);
        // Set the 'description' attribute of this object to the specified
        // 'value'.

    void setName(const std::string& value);
        // Set the 'name' attribute of this object to the specified 'value'.

    void setQuality(const std::string& value);
        // Set the 'quality' attribute of this object to the specified 'value'.

    void setSequence(const std::string& value);
        // Set the 'sequence' attribute of this object to the specified
        // 'value'.

    void swapBody(std::string *value);
        // Swap the contents of the body attribute of this object with the
        // contents of the specified 'value'.

                                  // Aspects

    // ACCESSORS
    const std::string& description() const;
        // Return a reference providing non-modifiable access to the
        // 'description' attribute of this object.

    const std::string& name() const;
        // Return a reference providing non-modifiable access to the 'name'
        // attribute of this object.

    const std::string& quality() const;
        // Return a reference providing non-modifiable access to the 'quality'
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
bool operator==(const Fastq& lhs, const Fastq& rhs);
    // Return 'true' if the specified 'lhs' and 'rhs' objects have the same
    // value and 'false' otherwise.  Two 'Fastq' objects have the same value
    // if the corresponding values of their 'body' and 'name' attributes have
    // the same value.

bool operator!=(const Fastq& lhs, const Fastq& rhs);
    // Return 'true' if the specified 'lhs' and 'rhs' objects do not have the
    // same value and 'false' otherwise.  Two 'Fastq' objects do not have the
    // same value if any the corresponding values of their 'body' and 'name'
    // attributes do not have the same value.

std::istream& operator>>(std::istream& stream, Fastq& rhs);
    // Assign to the specified 'rhs' object the value extracted from the
    // specified 'stream', and return a reference providing modifiable access
    // to 'stream'.

std::ostream& operator<<(std::ostream& stream, const Fastq& rhs);
    // Output the value of the specified 'rhs' object to the specified
    // 'stream', and return a reference providing modifiable access to
    // 'stream'.

// ============================================================================
//                        INLINE FUNCTION DEFINITIONS
// ============================================================================

                                // ------------
                                // class Fastq
                                // ------------

// CREATORS
inline
Fastq::Fastq()
: d_description()
, d_name()
, d_quality()
, d_sequence()
{
}

inline
Fastq::Fastq(const std::string& description,
               const std::string& name,
               const std::string& quality,
               const std::string& sequence)
: d_description(description)
, d_name(name)
, d_quality(quality)
, d_sequence(sequence)
{
}

inline
Fastq::Fastq(const Fastq& original)
: d_description(original.d_description)
, d_name(original.d_name)
, d_quality(original.d_quality)
, d_sequence(original.d_sequence)
{
}

// MANIPULATORS
inline
Fastq& Fastq::operator=(const Fastq& rhs)
{
    d_description = rhs.d_description;
    d_name        = rhs.d_name;
    d_quality     = rhs.d_quality;
    d_sequence    = rhs.d_sequence;

    return *this;
}

inline
void Fastq::setDescription(const std::string& value)
{
    d_description.assign(value.begin(), value.end());
}

inline
void Fastq::setName(const std::string& value)
{
    d_name.assign(value.begin(), value.end());
}

inline
void Fastq::setQuality(const std::string& value)
{
    d_quality.assign(value.begin(), value.end());
}

inline
void Fastq::setSequence(const std::string& value)
{
    d_sequence.assign(value.begin(), value.end());
}

// ACCESSORS
inline
const std::string& Fastq::description() const
{
    return d_description;
}

inline
const std::string& Fastq::name() const
{
    return d_name;
}

inline
const std::string& Fastq::quality() const
{
    return d_quality;
}

inline
const std::string& Fastq::sequence() const
{
    return d_sequence;
}


// FREE OPERATORS
inline
bool operator==(const Fastq& lhs, const Fastq& rhs)
{
    return lhs.name()        == rhs.name()
        && lhs.description() == rhs.description()
        && lhs.quality()     == rhs.quality()
        && lhs.sequence()    == rhs.sequence();
}

inline
bool operator!=(const Fastq& lhs, const Fastq& rhs)
{
    return lhs.name()        != rhs.name()
        || lhs.description() != rhs.description()
        || lhs.quality()     != rhs.quality()
        || lhs.sequence()    != rhs.sequence();
}

}  // close package namespace

#endif
