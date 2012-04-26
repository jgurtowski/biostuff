// fasta_parser.h                                                     -*-C++-*-

#ifndef INCLUDED_FASTA_PARSER
#define INCLUDED_FASTA_PARSER

//@PURPOSE: Provide a mechanism to decode Fasta formatted files.
//
//@CLASSES:
//  Parser: mechanism to decode Fasta formatted files
//
//@AUTHOR: Tim Douglas (tdouglas)
//
//@SEE_ALSO: fasta_record
//
//@DESCRIPTION: This component provides a mechanism, 'Parser', which may be
// used to decode Fasta formatted files, such as:
//..
//  >chrome1
//  ACGTACGT
//  >chrome2
//  TCGATCGA
//..
//
///Usage
///-----
//
// This section illustrates intended usage of this component.
//
///Example 1: TBD
/// - - - - - - -

#ifndef INCLUDED_FASTA_RECORD
#include <fasta_record.h>
#endif

#ifndef INCLUDED_OSTREAM
#define INCLUDED_OSTREAM
#include <ostream>
#endif

namespace fasta {

                                // ============
                                // class Parser
                                // ============

class Parser {
    // This class provides...

    // DATA
    std::istream *d_stream_p;  // Held, not owned
    Record        d_record;

  private:
    // NOT IMPLEMENTED
    Parser(const Parser& original);
    Parser& operator=(const Parser& rhs);

  public:
    // TYPES
    typedef RecordIterator const_iterator;

    // CREATORS
    explicit Parser(const std::istream& stream);
        // Create a new 'Parser' object which reads Fasta formatted input from
        // the specified 'stream'.

    //! ~Parser() = default;
        // Destroy this object.

    // MANIPULATORS
    void next();
        // Advance this object to the next Fasta record in the stream.

    const_iterator begin();

    const_iterator end();

    // ACCESSORS
    const Record& record() const;
        // Return a reference providing non-modifiable access to the most
        // recently parsed 'Record'.

    bool isDone() const;
        // Return 'true' if all records have been parsed and 'false' otherwise.
};

// ============================================================================
//                        INLINE FUNCTION DEFINITIONS
// ============================================================================

                                // ------------
                                // class Parser
                                // ------------

// MANIPULATORS
inline
Parser::const_iterator Parser::begin()
{
    return Parser::const_iterator(this);
}

inline
Parser::const_iterator Parser::end()
{
    return Parser::const_iterator();
}

// ACCESSORS
inline
bool Parser::isDone() const
{
    return d_stream_p->eof();
}

}  // close package namespace

#endif
