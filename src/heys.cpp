#include "heys.h"

//namespace fs = filesystem;

namespace fs = std::filesystem;

std::vector<block> heys::txt2blocks(std::string text_name) {
    
    std::string current_path = fs::current_path();
    current_path.replace(current_path.find_last_of('/') + 1, 4, "text").pop_back();
    current_path += ("/" + text_name);
    
    char letter ;
    int i ;
    std::string line ;

    std::ifstream reader( current_path );

    if( !reader ) {
        std::cout << "Error opening input file" << std::endl;
        std::vector<block> a = {1,2,3};
        return a;
    }

    for( i = 0; ! reader.eof() ; i++ ) {
        reader.get( letter ) ;
        std::cout << letter ;
    }
	/*
    getline( reader , line ) ;
    cout << line << endl;
	*/
  //}

//  reader.close() ;


    std::vector<block> a = {1,2,3};
    return a;
}

heys::heys(/* args */)
{
}

heys::~heys()
{
}
