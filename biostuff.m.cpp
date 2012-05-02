#include <iostream>
#include <iterator>

#include <sequence_fasta.h>
#include <sequence_generic.h>
#include <bwt.h>

int main(void){
  
  std::istream_iterator<sequence::Fasta> b(std::cin), e;

  bwt::BWT trans;
    
  for(;b!=e;++b){
    //uppercase
    bwt::build(*b, &trans);
  }
}
