// fasta_record.h                                                     -*-C++-*-

#ifndef INCLUDED_FASTA_RECORD
#define INCLUDED_FASTA_RECORD

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
//
//..
//  Name    Type         Default Value
//  ------  -----------  -------------
//  body    std::string  ""
//  name    std::string  ""
//..
//
///Usage
///-----
//
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

namespace fasta {

                                // ============
                                // class Record
                                // ============

class Record {
    // This attribute class...

    // DATA
    std::string d_body;  // the body of the sequence
    std::string d_name;  // the name of the record

    // FRIENDS
    friend std::istream& operator>>(std::istream&, Record&);

  public:
    // CREATORS
    explicit Record();
        // Create a new 'Record' object having the (default) attribute values:
        //..
        //  body() == "";
        //  name() == "";
        //..

    Record(const std::string& body, const std::string& name);
        // Create a new 'Record' object having the specified 'body' and 'name'
        // attribute values.

    Record(const Record& original);
        // Create a new 'Record' object having the same value as the specified
        // 'original' object.

    //! ~Record() = default;
        // Destroy this object.

    // MANIPULATORS
    Record& operator=(const Record& rhs);
        // Set the value of this object to the value of the specified 'rhs'
        // object, and return a reference providing modifiable access to this
        // object.

    void setBody(const std::string& value);
        // Set the 'body' attribute of this object to the specified 'value'.

    void setName(const std::string& value);
        // Set the 'name' attribute of this object to the specified 'value'.

    void swapBody(std::string *value);
        // Swap the contents of the body attribute of this object with the
        // contents of the specified 'value'.

                                  // Aspects

    // ACCESSORS
    const std::string& body() const;
        // Return a reference providing non-modifiable access to the 'body'
        // attribute of this object.

    const std::string& name() const;
        // Return a reference providing non-modifiable access to the 'name'
        // attribute of this object.

                                  // Aspects

    std::ostream& print(std::ostream& stream,
                        int           level = 0,
                        int           spacesPerLevel = 4) const;
};

// FREE OPERATORS
bool operator==(const Record& lhs, const Record& rhs);
    // Return 'true' if the specified 'lhs' and 'rhs' objects have the same
    // value and 'false' otherwise.  Two 'Record' objects have the same value
    // if the corresponding values of their 'body' and 'name' attributes have
    // the same value.

bool operator!=(const Record& lhs, const Record& rhs);
    // Return 'true' if the specified 'lhs' and 'rhs' objects do not have the
    // same value and 'false' otherwise.  Two 'Record' objects do not have the
    // same value if any the corresponding values of their 'body' and 'name'
    // attributes do not have the same value.

std::istream& operator>>(std::istream& stream, Record& rhs);
    // Assign to the specified 'rhs' object the value extracted from the
    // specified 'stream', and return a reference providing modifiable access
    // to 'stream'.

std::ostream& operator<<(std::ostream& stream, const Record& rhs);
    // Output the value of the specified 'rhs' object to the specified
    // 'stream', and return a reference providing modifiable access to
    // 'stream'.

// ============================================================================
//                        INLINE FUNCTION DEFINITIONS
// ============================================================================

                                // ------------
                                // class Record
                                // ------------

// CREATORS
inline
Record::Record()
: d_body()
, d_name()
{
}

inline
Record::Record(const std::string& body, const std::string& name)
: d_body(body)
, d_name(name)
{
}

inline
Record::Record(const Record& original)
: d_body(original.d_body)
, d_name(original.d_name)
{
}

// MANIPULATORS
inline
Record& Record::operator=(const Record& rhs)
{
    d_body = rhs.d_body;
    d_name = rhs.d_name;

    return *this;
}

inline
void Record::setBody(const std::string& value)
{
    d_body.assign(value.begin(), value.end());
}

inline
void Record::setName(const std::string& value)
{
    d_name.assign(value.begin(), value.end());
}

inline
void Record::swapBody(std::string *value)
{
    d_body.swap(*value);
}

// ACCESSORS
inline
const std::string& Record::body() const
{
    return d_body;
}

inline
const std::string& Record::name() const
{
    return d_name;
}


// FREE OPERATORS
inline
bool operator==(const Record& lhs, const Record& rhs)
{
    return lhs.name() == rhs.name()
        && lhs.body() == rhs.body();
}

inline
bool operator!=(const Record& lhs, const Record& rhs)
{
    return lhs.name() != rhs.name()
        || lhs.body() != rhs.body();
}

}  // close package namespace

#endif
