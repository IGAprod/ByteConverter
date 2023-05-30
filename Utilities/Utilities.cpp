#include "Utilities.h"

std::vector<uint8_t> getRandomBytes (size_t number_of_bytes)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 255);
    std::vector<uint8_t> result(number_of_bytes);
    for (uint8_t& val : result)
    {
        val = static_cast<uint8_t>(dist(rd) & 0xFF);
    }

    return result;
}

bool generateBytes (const std::string& fileName, size_t number_of_bytes)
{
    bool result = true;

    std::ofstream out;
    out.open(fileName, std::ios::binary | std::ios::out);
    if (out.is_open())
    {
        std::vector<uint8_t> data = getRandomBytes(number_of_bytes);

        for (size_t i = 0; i < data.size(); ++i)
        {
            out.write((char*) &data[i], sizeof(data[i]));
        }
    }
    else
    {
        result = false;
    }

    out.close();

    return result;
}