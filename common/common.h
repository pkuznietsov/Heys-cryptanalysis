#pragma once

#include <typeinfo>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <array>

using block    = uint16_t; 
using nubbin   = uint16_t; 
using rkey     = uint16_t;

enum cipher_params { BLOCK_SIZE = 16, KEY_SIZE = 16, NUBBIN_SIZE = 4, ROUNDS_AMOUNT = 7 }; 
enum mode { ENCRYPT, DECRYPT };
enum errors { INPUT_ERROR = 1, OUTPUT_ERROR = 2 };