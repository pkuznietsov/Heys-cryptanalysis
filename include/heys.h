#include "common.h"

class heys
{
private:

    std::vector<block> data;
    std::array<rkey, ROUNDS_AMOUNT> key;

public:

    std::vector<block> txt2blocks(std::string path);
    std::vector<block> sub2blocks(std::vector<char> sub_blocks);
    std::vector<char> blocks2sub(std::vector<block> blocks);


    heys(/* args */);
    ~heys();
};


/*

#include <string>
#include <fstream>
#include <iostream>
using namespace std ;

int main()
{
  char letter ;
  int i ;
  string line ;

  ifstream reader( "Shakespeare.txt" ) ;

  if( ! reader ) {
    cout << "Error opening input file" << endl ;
    return -1 ;
  }

  for( i = 0; ! reader.eof() ; i++ ) {
    reader.get( letter ) ;
    cout << letter ;

	/*
    getline( reader , line ) ;
    cout << line << endl ;
	*/
  //}

//  reader.close() ;
  
 // return 0 ;
//}
