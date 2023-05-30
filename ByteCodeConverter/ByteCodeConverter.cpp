#include "ByteCodeConverter.h"

void Source::ReadBytes (const std::string& fileName)
    {
        std::ifstream read;
        read.open(fileName, std::ios::binary);

        std::vector<uint8_t> bytes;

        if (read.is_open())
        {
            bytes = std::vector<uint8_t>(std::istreambuf_iterator<char>(read), {});
        }

        data = bytes;
    }

bool Source::getBytes(size_t begin, size_t end, std::vector<uint8_t> &chunk) const {
    if (!data.empty())
    {
        while(begin < end)
        {
            if (begin >= data.size())
            {
                return false;
            }

            chunk.push_back(data[begin]);
            begin++;
        }
    }
    else
    {
        return false;
    }

    return true;
};

void Sink::saveData (const std::string& fileName, const std::string& data) const
{
    std::cout << data << std::endl;

    std::ofstream out;
    out.open(fileName, std::ios::app);
    if (out.is_open())
    {
        out << data;
    }

    out.close();
};

std::string ByteCodeConverter::convert_bytes(std::vector<uint8_t> bytes_to_convert)
{
    std::string result;

    for (size_t i = 0; i < bytes_to_convert.size(); ++i)
    {
        int data_type = bytes_to_convert[i] >> 6;
        switch(data_type)
        {
            case 0x00:
                result += std::to_string(bytes_to_convert[i] << 2);
                break;
            case 0x01:
                if (0x1 & (bytes_to_convert[i] >> 5)) {result += '-';}
                result += std::to_string(bytes_to_convert[i] << 3);
                break;
            case 0x10:
                result +=  std::to_string(bytes_to_convert[i] + 97);
                break;
            default:
                break;
        }
    }

    return result;
}

void ByteCodeConverter::convert_bytes_thread(SourceInterface &source, SinkInterface &sink, const std::string& fileName)
{
    size_t chunk_size = 8; // 8 bytes
    size_t begin = 0;

    while(state == CONVERTING)
    {
        std::vector<uint8_t> chunk(8);
        if (source.getBytes(begin, begin + chunk_size, chunk))
        {
            std::string result = convert_bytes(chunk);
            sink.saveData(fileName, result);
        }
        else
        {
            state = EXIT;
            return;
        }

        begin += chunk_size;
    }

    {
        std::lock_guard<std::mutex> lck(convert_mutex);
        state = EXIT;
    }

    convert_cv.notify_one();
}

void ByteCodeConverter::start_convert_bytes(SourceInterface &source, SinkInterface &sink, const std::string& fileName)
{
    if (state == WAITING_TO_START || state == EXIT)
    {
        state = CONVERTING;
        std::thread start_convert(&ByteCodeConverter::convert_bytes_thread, this, std::ref(source), std::ref(sink), fileName);
        start_convert.detach();
    }
    else
    {
        std::cout << "Already converting" << std::endl;
    }
}

void ByteCodeConverter::stop_convert_bytes()
{
    if (state != EXIT)
    {
        state = WAITING_TO_STOP;
        std::unique_lock<std::mutex> lck(convert_mutex);
        convert_cv.wait(lck, [this]{return (state == EXIT);});
    }
}
