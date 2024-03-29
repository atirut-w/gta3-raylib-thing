#include <rwloader/chunk.hpp>
#include <sstream>

using namespace RWLoader;

Chunk::Chunk(std::istream& stream)
{
    type = read<int>(stream);
    size = read<int>(stream);
    library_id = read<int>(stream);
}

void Chunk::assert_type(int expected)
{
    if (type != expected)
    {
        std::stringstream ss;
        ss << "invalid chunk type. expected " << expected << ", got " << type << ".";
        throw std::runtime_error(ss.str());
    }
}

int Chunk::get_version()
{
    int ver;
    int maj;
    int min;
    int rev;

    rev = (library_id >> 16) & 0b111111;
    min = (library_id >> 22) & 0b1111;
    maj = (library_id >> 26) & 0b1111;
    ver = (library_id >> 30) & 0b11;

    int version = 0;
    version |= ver << 16;
    version |= maj << 12;
    version |= min << 8;
    version |= rev;

    return version + 0x30000;
}
