#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../ByteCodeConverter/ByteCodeConverter.h"
#include "../Utilities/Utilities.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <bitset>

class MockByteCodeConverter : public ByteCodeConverter
{
    private:
    MOCK_METHOD1(convert_bytes, void(std::vector<uint8_t> bytes_to_convert));
    MOCK_METHOD3(convert_bytes_thread, void(SourceInterface &source, SinkInterface &sink, const std::string& fileName));

    public:
    MOCK_CONST_METHOD3(start_convert_bytes, void(SourceInterface &source, SinkInterface &sink, const std::string& fileName));
    MOCK_CONST_METHOD0(stop_convert_bytes, void());
};