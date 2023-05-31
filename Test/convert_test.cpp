#include "convert_test.h"

void segFaultHandler(int signal)
{
    std::cout << "Segmentation fault" << std::endl;
    exit(signal);
}

TEST(ByteCodeConverterTest, Convert)
{
    std::string inputFileName = "/home/igorkinev/Desktop/testing/repo/ByteConverter/resources/data.bin";
    std::string outputFileName = "/home/igorkinev/Desktop/testing/repo/ByteConverter/resources/save.txt";

    eraseFile(inputFileName);
    eraseFile(outputFileName);

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
    byteCodeConverter.start_convert_bytes(source, sink, outputFileName);

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::string result = readConvertedFile(outputFileName);

    std::string valid_str = "132906321-15-190-3121dlpaz";

    EXPECT_EQ(valid_str, result);
}


TEST(ByteCodeConverterTest, ConvertWithBrokenBytes)
{
    std::string inputFileName = "/home/igorkinev/Desktop/testing/repo/ByteConverter/resources/data.bin";
    std::string outputFileName = "/home/igorkinev/Desktop/testing/repo/ByteConverter/resources/save.txt";

    eraseFile(inputFileName);
    eraseFile(outputFileName);

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
    letter_array.emplace_back(std::bitset<8>("10111111").to_ulong()); // broken_byte
    letter_array.emplace_back(std::bitset<8>("10000011").to_ulong()); // d
    letter_array.emplace_back(std::bitset<8>("10001011").to_ulong()); // l
    letter_array.emplace_back(std::bitset<8>("10001111").to_ulong()); // p
    letter_array.emplace_back(std::bitset<8>("10101111").to_ulong()); // broken_byte
    letter_array.emplace_back(std::bitset<8>("10000000").to_ulong()); // a
    letter_array.emplace_back(std::bitset<8>("10011001").to_ulong()); // z
    letter_array.emplace_back(std::bitset<8>("10111011").to_ulong()); // broken_byte

    writeBytesIntoFile(letter_array, inputFileName);

    Source source;
    source.ReadBytes(inputFileName);

    Sink sink;

    ByteCodeConverter byteCodeConverter;
    byteCodeConverter.start_convert_bytes(source, sink, outputFileName);

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::string result = readConvertedFile(outputFileName);

    std::string valid_str = "132906321-15-190-3121dlpaz";

    EXPECT_EQ(valid_str, result);
}

TEST(ByteCodeConverterTest, StopConvert)
{
    signal(SIGSEGV, segFaultHandler);

    std::string inputFileName = "/home/igorkinev/Desktop/testing/repo/ByteConverter/resources/data.bin";
    std::string outputFileName = "/home/igorkinev/Desktop/testing/repo/ByteConverter/resources/save.txt";

    eraseFile(inputFileName);
    eraseFile(outputFileName);

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
    byteCodeConverter.start_convert_bytes(source, sink, outputFileName);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    byteCodeConverter.stop_convert_bytes();

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}