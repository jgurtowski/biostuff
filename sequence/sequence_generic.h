// sequence_generic.h

#ifndef INCLUDED_SEQUENCE_GENERIC
#define INCLUDED_SEQUENCE_GENERIC

//@PURPOSE: Provide an interface characterizing a Generic sequence
//
//@CLASSES:
//  Generic: methods characterizing a Generic sequence
//
//@AUTHOR: James Gurtowski (gurtowskij)
//
//@SEE_ALSO:
//
//@DESCRIPTION: This component provides an interface from which other
//types can implement
//
///Usage
///-----
// This section illustrates intended usage of this component.
//
///Example 1: TBD
/// - - - - - - -


#ifndef INCLUDED_STRING
#define INCLUDED_STRING
#include <string>
#endif

namespace sequence {

  // ============
  // class Generic
  // ============

  class Generic {

  public:
  
    virtual ~Generic();
    //virtual destructor

    // ACCESSORS
    virtual const std::string& name() const = 0;
    // Return a reference providing non-modifiable access to the 'name'
    // attribute of this object.

    virtual const std::string& sequence() const = 0;
    // Return a reference providing non-modifiable access to the 'sequence'
    // attribute of this object.
    
    std::ostream& print(std::ostream& stream,
                        int           level = 0,
                        int           spacesPerLevel = 4) const;
    //pretty pring to stream
    
  };
  
  std::ostream& operator<<(std::ostream& stream, const Generic& rhs);
  // Output the value of the specified 'rhs' object to the specified
  // 'stream', and return a reference providing modifiable access to
  // 'stream'.

  // ============================================================================
  //                        INLINE FUNCTION DEFINITIONS
  // ============================================================================

  // ------------
  // class Generic
  // ------------

  inline
    Generic::~Generic()
  {
  }
  
  // FREE OPERATORS
  inline
  bool operator==(const Generic& lhs, const Generic& rhs)
  {
    return lhs.name()        == rhs.name()
      && lhs.sequence()    == rhs.sequence();
  }

  inline
  bool operator!=(const Generic& lhs, const Generic& rhs)
  {
    return lhs.name()        != rhs.name()
      || lhs.sequence()    != rhs.sequence();
  }

}  // close package namespace

#endif
