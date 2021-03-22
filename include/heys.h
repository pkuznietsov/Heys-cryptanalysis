#include "common.h"

class heys
{
private:
    std::vector<block> data;
    std::array<rkey, cipher_params::ROUNDS_AMOUNT> key = { 0xABBA, 0xBABA, 0xAAAA, 0xBA02, 0x0BAC, 0x0CAB, 0x0011 };
    std::vector<block> S_block = { 0x2, 0x8, 0x9, 0x7, 0x5, 0xF, 0x0, 0xB, 0xC, 0x1, 0xD, 0xE, 0xA, 0x3, 0x6, 0x4 };

public:
    std::vector<char> blocks_to_chars(std::vector<block> blocks);
    std::vector<block> chars_to_blocks(std::vector<char> chars);

    int txt_to_data(std::string text_name);
    int data_to_txt(std::string text_name);

    int cihper();
    void heys::round(block &temp, int i);
    void heys::enc(block &x);

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
