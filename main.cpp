
#include <iostream>
#include "Utilities/Utilities.h"
#include "ByteCodeConverter/ByteCodeConverter.h"

int main() {

    ByteCodeConverter byteCodeConverter;

    std::string readFileName = "../files/data.bin";
    std::string saveFileName = "../files/save.bin";

    bool result = generateBytes (readFileName, 1000);

    Source source;
    source.ReadBytes(readFileName);

    Sink sink;

    ByteCodeConverter byteCodeConverter1;

    byteCodeConverter1.start_convert_bytes(source, sink, saveFileName);

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    byteCodeConverter1.stop_convert_bytes();

    return 0;
}
