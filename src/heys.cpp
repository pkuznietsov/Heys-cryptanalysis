#include "heys.h"

//namespace fs = filesystem;

namespace fs = std::filesystem;

std::vector<block> heys::txt2blocks(std::string path) {
    /*
    std::ifstream reader("text/text1.txt") ;        
    if( ! reader ) {
    std::cout << "Error opening input file" << std::endl;
  }
    std::vector<block> a = {1,2,3};
    return a;
    */
    std::cout << "Current path is " << fs::current_path() << '\n';
    std::vector<block> a = {1,2,3};
    return a;
}


heys::heys(/* args */)
{
}

heys::~heys()
{
}
