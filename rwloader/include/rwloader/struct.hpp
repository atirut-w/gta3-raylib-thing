#pragma once
#include <rwloader/chunk.hpp>

namespace RWLoader
{
    class Struct : public Chunk
    {
    public:
        Struct(std::istream& stream);
    };
}
