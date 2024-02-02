#pragma once
#include <rwloader/chunk.hpp>

namespace RWLoader
{
    class TextureDict : public Chunk
    {
    public:
        TextureDict(std::istream &);
    };
}
