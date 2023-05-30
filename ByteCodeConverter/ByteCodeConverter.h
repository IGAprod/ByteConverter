#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <fstream>
#include <vector>
#include <random>
#include <bitset>

typedef enum
{
    WAITING_TO_START = 0,
    CONVERTING = 1,
    WAITING_TO_STOP = 2,
    EXIT = 3

} convert_state;

class SourceInterface
{
    public:
        virtual ~SourceInterface()= default;
        virtual bool getBytes(size_t begin, size_t end, std::vector<uint8_t> &data) const = 0;
};

class SinkInterface
{
    public:
        virtual ~SinkInterface()= default;
        virtual void saveData(const std::string& fileName, const std::string& start_convert_bytes) const = 0;
};

class Source : public SourceInterface
{
    public:
        void ReadBytes (const std::string& fileName);
        bool getBytes(size_t begin, size_t end, std::vector<uint8_t> &chunk) const override;

    private:
        std::vector<uint8_t> data;
};

class Sink : public SinkInterface
{
    public:
        void saveData (const std::string& fileName, const std::string& data) const override;
        ~Sink() override= default;
};

class ByteCodeConverter
{
    private:
        static std::string convert_bytes(std::vector<uint8_t> bytes_to_convert);
        void convert_bytes_thread(SourceInterface &source, SinkInterface &sink, const std::string& fileName);

    public:
        void start_convert_bytes(SourceInterface &source, SinkInterface &sink, const std::string& fileName);
        void stop_convert_bytes();

    private:
        convert_state state = WAITING_TO_START;
        std::mutex convert_mutex;
        std::condition_variable convert_cv;
};
