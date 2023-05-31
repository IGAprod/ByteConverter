#include "Utilities.h"

std::string readConvertedFile(std::string fileName)
{
    std::string result_str;

    std::ifstream file(fileName);
    std::string buff;

    while(std::getline(file, buff))
    {
        result_str += buff;
    }

    return result_str;
}

bool writeBytesIntoFile(const std::vector<uint8_t>& bytes_to_write, const std::string& fileName)
{
    bool result = true;

    std::ofstream out;
    out.open(fileName, std::ios::binary | std::ios::app);
    if (out.is_open())
    {
        out.write((char*) bytes_to_write.data(), bytes_to_write.size());
    }
    else
    {
        result = false;
    }

    out.close();

    return result;
}

void eraseFile(const std::string& fileName)
{
    std::ofstream out;
    out.open(fileName, std::ios::trunc);
    out.close();
}