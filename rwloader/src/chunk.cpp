#include <rwloader/chunk.hpp>

using namespace RWLoader;

template<typename T>
T read(std::istream& stream)
{
    T value;
    stream.read(reinterpret_cast<char*>(&value), sizeof(T));
    return value;
}

Chunk::Chunk(std::istream& stream)
{
    type = read<int>(stream);
    library_id = read<int>(stream);
    size = read<int>(stream);
}
