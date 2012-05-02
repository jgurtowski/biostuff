// bwt.cpp

#include <bwt.h>
#include <sequence_generic.h>

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

namespace bwt{

  // ------------
  // class BWT
  // ------------

  // FREE OPERATORS
  BWT *build(const sequence::Generic& sequence, BWT *bwt){
    const std::string& sequence_data  = sequence.sequence();
    int seq_len = sequence_data.length();
    const char **ind = new const char *[seq_len];
    const char *sequence_c = sequence_data.c_str();
    
    bwt -> d_transform.clear();
    bwt -> d_transform.reserve(seq_len);

    //initialize pointers to each index of the sequence
    for(int i=0;i< seq_len;++i){
      ind[i] = sequence_c+i;      
    }
    
    //sort the suffixes
    qsort(ind,seq_len,sizeof(char *), suffix_comparator);
    
    for(int i=0;i<seq_len;++i){
      if( ind[i] == sequence_c )
        bwt -> d_transform.push_back( sequence_c[seq_len-1] );
      else
        bwt -> d_transform.push_back( *(ind[i]-1));
    }
    
    delete ind;

    return bwt;
  }

  int suffix_comparator( const void *a, const void *b){
    const char *a_p = *((const char **)a);
    const char *b_p = *((const char **)b);
    return strcmp(a_p, b_p);
  }

  std::ostream& operator<<(std::ostream& stream, const BWT& rhs)
  {
    stream << "[ "
           << rhs.transform()
           << " ]";
    return stream;
  }


}  // close package namespace
