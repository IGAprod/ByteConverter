
#include <iostream>
#include "Utilities/Utilities.h"
#include "ByteCodeConverter/ByteCodeConverter.h"

int main() {

    std::string inputFileName = "/home/igorkinev/Desktop/testing/repo/ByteConverter/resources/data.bin";
    std::string outputFileName = "/home/igorkinev/Desktop/testing/repo/ByteConverter/resources/save.bin";

    //Some unsigned integers
    std::vector<uint8_t> unsigned_integer_array;
    unsigned_integer_array.emplace_back(std::bitset<8>("00001101").to_ulong()); // 13
    unsigned_integer_array.emplace_back(std::bitset<8>("00011101").to_ulong()); // 29
    unsigned_integer_array.emplace_back(std::bitset<8>("00000000").to_ulong()); // 0
    unsigned_integer_array.emplace_back(std::bitset<8>("00111111").to_ulong()); // 63
    unsigned_integer_array.emplace_back(std::bitset<8>("00010101").to_ulong()); // 21

    writeBytesIntoFile(unsigned_integer_array, inputFileName);

    //Some integers
    std::vector<uint8_t> integer_array;
    integer_array.emplace_back(std::bitset<8>("01101111").to_ulong()); // -15
    integer_array.emplace_back(std::bitset<8>("01110011").to_ulong()); // -19
    integer_array.emplace_back(std::bitset<8>("01000000").to_ulong()); // 0
    integer_array.emplace_back(std::bitset<8>("01111111").to_ulong()); // -31
    integer_array.emplace_back(std::bitset<8>("01010101").to_ulong()); // 21

    writeBytesIntoFile(integer_array, inputFileName);

    //Some letters
    std::vector<uint8_t> letter_array;
    letter_array.emplace_back(std::bitset<8>("10000011").to_ulong()); // d
    letter_array.emplace_back(std::bitset<8>("10001011").to_ulong()); // l
    letter_array.emplace_back(std::bitset<8>("10001111").to_ulong()); // p
    letter_array.emplace_back(std::bitset<8>("10000000").to_ulong()); // a
    letter_array.emplace_back(std::bitset<8>("10011001").to_ulong()); // z

    writeBytesIntoFile(letter_array, inputFileName);

    Source source;
    source.ReadBytes(inputFileName);

    Sink sink;

    ByteCodeConverter byteCodeConverter;

//    EXPECT_CALL(byteCodeConverter, start_convert_bytes(std::ref(source), std::ref(sink), inputFileName));//.Times(1);

    byteCodeConverter.start_convert_bytes(source, sink, outputFileName);

    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    std::string result = readConvertedFile(outputFileName);

    std::string valid_str = "132906321-15-190-3121dlpaz";

    return 0;
}
