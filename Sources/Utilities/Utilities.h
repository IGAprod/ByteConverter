#pragma once

#include <iostream>
#include <vector>
#include <cstdint>
#include <random>
#include <fstream>

bool writeBytesIntoFile(const std::vector<uint8_t> &data, const std::string& fileName);
std::string readConvertedFile(const std::string& fileName);
void eraseFile(const std::string& fileName);