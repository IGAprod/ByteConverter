#pragma once

#include <iostream>
#include <vector>
#include <cstdint>
#include <random>
#include <fstream>

bool generateBytes (const std::string& fileName, size_t number_of_bytes);

bool writeBytesIntoFile(const std::vector<uint8_t> &data, const std::string& fileName);
std::string readConvertedFile(std::string fileName);
