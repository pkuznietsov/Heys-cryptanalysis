#pragma once

#include <iostream>
#include <stdint.h>
#include <array>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <functional>
#include <chrono>
#include <ctime>
#include <thread>
#include <stdexcept>

using block    = uint16_t; 
using rkey     = uint16_t;
 
const std::vector<rkey> key { 0x0011, 0x1012, 0x3001, 0x0004, 0x4121, 0x9422, 0xAA10 };
