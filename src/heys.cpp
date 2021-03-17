#include "heys.h"

//namespace fs = filesystem;

namespace fs = std::filesystem;

std::vector<block> heys::sub2blocks(std::vector<char> sub_blocks) {
    
    if ( sub_blocks.size() % 2 != 0 ) {
        sub_blocks.push_back('\0');
    }

    std::vector<block> result = {};

    for (int i = 0; i < sub_blocks.size(); i += 2){
        block r = sub_blocks[i];
        r <<= 8;
        r += sub_blocks[i+1];
        result.push_back(r);
    }
    return result;
}

std::vector<block> heys::txt2blocks(std::string text_name) {
    
    std::string current_path = fs::current_path();
    current_path.replace(current_path.find_last_of('/') + 1, 4, "text").pop_back();
    current_path += ("/" + text_name);
    
    char letter;

    int i;
    std::string line;

    std::ifstream reader( current_path );

    if( !reader ) {
        std::cout << "Error opening input file" << std::endl;
        std::vector<block> empty_vector = {0};
        return empty_vector;
    }

    std::vector<char> sub_blocks = {};
    for( i = 0; ! reader.eof() ; i++ ) {
        reader.get( letter );
        sub_blocks.push_back(letter);
    }
    reader.close() ;

    return sub2blocks(sub_blocks);
}

std::vector<char> heys::blocks2sub(std::vector<block> blocks){
    std::vector<char> result = {};
    for (int i = 0; i < blocks.size(); i++) {
        char l1 = (blocks[i] & 0xFF00) >> 8;
        char l2 = (blocks[i] & 0xFF);
        result.push_back(l1);
        result.push_back(l2);   
    }
    return result;
} 

heys::heys(/* args */)
{
}

heys::~heys()
{
}
