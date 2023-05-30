#pragma once

#include <iostream>
#include <vector>
#include <cstdint>
#include <random>
#include <fstream>

std::vector<uint8_t> getRandomBytes (size_t number_of_bytes);

bool generateBytes (const std::string& fileName, size_t number_of_bytes);

