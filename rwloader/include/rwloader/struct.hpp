#pragma once
#include <rwloader/chunk.hpp>

namespace RWLoader
{
    template <typename T>
    class Struct : public Chunk
    {
    public:
        Struct(std::istream& stream) : Chunk(stream)
        {
            assert_type(STRUCT);
            data = read<T>(stream);
        }

        T data;
    };
}
