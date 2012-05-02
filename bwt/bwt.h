// bwt.h

#ifndef INCLUDED_BWT
#define INCLUDED_BWT

//@PURPOSE: Provide an attribute class characterizing a Burrows Wheeler Transform
//
//@CLASSES:
//  bwt: attributes characterizing a Burrows Wheeler Transform
//
//@AUTHOR: James Gurtowski (gurtowskij)
//
//@SEE_ALSO:
//
//@DESCRIPTION: This component provides a (value-semantic) attribute class,
// 'BWT', which characterizes a Burrows Wheeler transformed string.
//
///Attributes
///----------
//..
//  Name      Type         Default Value
//  ------    -----------  -------------
//  transform std::string  ""
//  sequence  std::string  ""
//..
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

#ifndef INCLUDED_MAP
#define INCLUDED_MAP
#include <map>
#endif

namespace sequence{
  class Generic; //forward declare Generic sequence class
}


namespace bwt {
  //STATIC CONSTANTS
  static const char END_SYMBOL = '$';
  
  // ============ // class BWT
  // ============

  class BWT {
    // This attribute class...

    // DATA
    std::string d_transform;      // Transformed Burrows Wheeler string
    std::map<char,int> d_alphabet_index;  //Maps a letter to its relative place in the BWT alphabet
    int *d_lcounts_p; //counts of left column letters, d_alphabet_index indexes these
    int *d_rcounts_p; //counts of previous occurences of letter in corresponding right column of BWT
    
    friend BWT *build(const sequence::Generic&, BWT *);

  public:
    // CREATORS
    explicit BWT();
    // Create a new 'BWT' object having the (default) attribute values:
    
    BWT(const BWT& original);
    // Create a new 'BWT' object having the same value as the specified
    // 'original' object.

    //! ~BWT();
    // Destroy this object.

    // MANIPULATORS
    BWT& operator=(const BWT& rhs);
    // Set the value of this object to the value of the specified 'rhs'
    // object, and return a reference providing modifiable access to this
    // object.
    
    // ACCESSORS
    const std::string& transform() const;
    // Return a reference providing non-modifiable access to the 'transform'
    // attribute of this object.
    
    
    // Aspects
    std::ostream& print(std::ostream& stream,
                        int           level = 0,
                        int           spacesPerLevel = 4) const;
  };

  // FREE OPERATORS
  bool operator==(const BWT& lhs, const BWT& rhs);
  // Return 'true' if the specified 'lhs' and 'rhs' objects have the same
  // value and 'false' otherwise.  Two 'BWT' objects have the same value
  // if the corresponding values of their 'sequence' and 'name' attributes have
  // the same value.

  bool operator!=(const BWT& lhs, const BWT& rhs);
  // Return 'true' if the specified 'lhs' and 'rhs' objects do not have the
  // same value and 'false' otherwise.  Two 'BWT' objects do not have the
  // same value if any the corresponding values of their 'sequence' and 'name'
  // attributes do not have the same value.

  BWT *build(const sequence::Generic& sequence, BWT *bwt);
  //Build a Burrows Wheeler Transformation from a generic sequence 'sequence'
  //Output is placed in 'bwt'

  int suffix_comparator( const void *a, const void *b);
  //Comparator used for sorting the suffixes in the transform string
  
  std::ostream& operator<<(std::ostream& stream, const BWT& rhs);
  // Output the value of the specified 'rhs' object to the specified
  // 'stream', and return a reference providing modifiable access to
  // 'stream'.


  // ============================================================================
  //                        INLINE FUNCTION DEFINITIONS
  // ============================================================================

  // ------------
  // class BWT
  // ------------

  // CREATORS
  inline
    BWT::BWT()
    : d_transform()
    , d_alphabet_index()
    {
    }
  
  // ACCESSORS
  inline
    const std::string& BWT::transform() const
  {
    return d_transform;
  }

  // FREE OPERATORS
  inline
    bool operator==(const BWT& lhs, const BWT& rhs)
  {
    return lhs.transform() == rhs.transform();
  }

  inline
    bool operator!=(const BWT& lhs, const BWT& rhs)
  {
    return lhs.transform() != rhs.transform();
  }

}  // close package namespace

#endif
