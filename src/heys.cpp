#include "heys.h"

namespace fs = std::filesystem;

std::vector<block> heys::chars_to_blocks(std::vector<char> chars) {
    
    if ( chars.size() % 2 != 0 ) {
        chars.push_back('\0');
    }

    std::vector<block> result = {};

    for (int i = 0; i < chars.size(); i += 2){
        block r = chars[i];
        r <<= 8;
        r += chars[i+1];
        result.push_back(r);
    }
    return result;
}

std::vector<char> heys::blocks_to_chars(std::vector<block> blocks) {
    std::vector<char> result = {};
    for (int i = 0; i < blocks.size(); i++) {
        char l1 = (blocks[i] & 0xFF00) >> 8;
        char l2 = (blocks[i] & 0xFF);
        result.push_back(l1);
        result.push_back(l2);   
    }
    return result;
} 

int heys::txt_to_data(std::string text_name) {
    
    std::string current_path = fs::current_path();
    current_path += ("/text/" + text_name);
    
    char letter;

    int i;
    std::string line;

    std::ifstream reader( current_path );
    if( !reader ) {
        std::cout << "Error opening input file" << std::endl;
        return errors::INPUT_ERROR;
    }

    std::vector<char> chars = {};
    for( i = 0; ! reader.eof() ; i++ ) {
        reader.get( letter );
        chars.push_back(letter);
    }
    reader.close();

    input_data = chars_to_blocks(chars);

    std::vector<block> empty_vector(input_data.size(), 0);
    this->encrypted_data = empty_vector;
    this->decrypted_data = empty_vector;
    
    return 0;
}

int heys::data_to_txt(std::string text_name) {
    std::vector<block> data = encrypted_data;
    std::vector<char> chars = blocks_to_chars(data);

    std::string result(chars.begin(), chars.end());

    std::string current_path = fs::current_path();
    current_path += ("/text/" + text_name);

    std::ofstream out(current_path);
    if( !out ) {
        std::cout << "Error opening output file" << std::endl;
        return errors::OUTPUT_ERROR;
    }

    out << result;
    out.close();
    return 0;
}


block heys::e_round(block temp, int i){
    temp = temp ^ key[i];

    uint16_t mask = 0xF000;
    std::vector<nubbin> nubbins = {};
    for (int i = 3; i >= 0; i--){
        nubbins.push_back((temp & mask) >> 4 * i);
        mask = mask >> 4;
    }

    for (int i = 0; i < 4; i ++) {
        nubbins[i] = S_block[nubbins[i]];
    }

    nubbins[0] = (nubbins[0] & 0x8) | ((nubbins[1] & 0x8) >> 1) | ((nubbins[2] & 0x8) >> 2) | ((nubbins[3] & 0x8) >> 3);  
    nubbins[1] = ((nubbins[0] & 0x4) << 1) | (nubbins[1] & 0x4) | ((nubbins[2] & 0x4) >> 1) | ((nubbins[3] & 0x4) >> 2);
    nubbins[2] = ((nubbins[0] & 0x2) << 2) | ((nubbins[1] & 0x2) << 1) | (nubbins[2] & 0x2) | ((nubbins[3] & 0x2) >> 1);
    nubbins[3] = ((nubbins[0] & 0x1) << 3) | ((nubbins[1] & 0x1) << 2) | ((nubbins[2] & 0x1) << 1) | (nubbins[3] & 0x1);

    return ( nubbins[0] << 12 ) | ( nubbins[1] << 8 ) | ( nubbins[2] << 4 ) | ( nubbins[3] );
}  

block heys::enc(block x) {
    block result = x;
    for (int i = 0; i < 7; i++) {
       result = e_round(result,i);
    }
    return result;
} 

int heys::encrypt() {
    for (int i = 0; i < input_data.size(); i++) {
        encrypted_data[i] = enc(input_data[i]);
    }
    return 0;
}

block heys::d_round(block temp, int i){
    uint16_t mask = 0xF000;
    std::vector<nubbin> nubbins = {};
    for (int i = 3; i >= 0; i--){
        nubbins.push_back((temp & mask) >> 4 * i);
        mask = mask >> 4;
    }

    nubbins[0] = (nubbins[0] & 0x8) | ((nubbins[1] & 0x8) >> 1) | ((nubbins[2] & 0x8) >> 2) | ((nubbins[3] & 0x8) >> 3);  
    nubbins[1] = ((nubbins[0] & 0x4) << 1) | (nubbins[1] & 0x4) | ((nubbins[2] & 0x4) >> 1) | ((nubbins[3] & 0x4) >> 2);
    nubbins[2] = ((nubbins[0] & 0x2) << 2) | ((nubbins[1] & 0x2) << 1) | (nubbins[2] & 0x2) | ((nubbins[3] & 0x2) >> 1);
    nubbins[3] = ((nubbins[0] & 0x1) << 3) | ((nubbins[1] & 0x1) << 2) | ((nubbins[2] & 0x1) << 1) | (nubbins[3] & 0x1);

    for (int i = 0; i < 4; i ++) {
        nubbins[i] = S_block_inv[nubbins[i]];
    }

    temp = ( nubbins[0] << 12 ) | ( nubbins[1] << 8 ) | ( nubbins[2] << 4 ) | ( nubbins[3] );
    return temp ^ key[i];
}  

block heys::dec(block x) {
    block result = x;
    for (int i = 6; i >= 0; i--) {
       result = d_round(result,i);
    }
    return result;
}

int heys::decrypt() {
    for (int i = 0; i < encrypted_data.size(); i++) {
        decrypted_data[i] = dec(encrypted_data[i]);
    }
    return 0;
}

bool heys::verificator() {
    for (int i = 0; i < input_data.size(); i++) {
        std::cout << "input_data " << input_data[i] << ":::" << "decrypted_data " << decrypted_data[i] << std::endl;
    }
    return input_data == decrypted_data ? true : false;
}

heys::heys(/* args */)
{
}

heys::~heys()
{
}
