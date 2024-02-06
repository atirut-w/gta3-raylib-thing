#pragma once
#include <rwloader/chunk.hpp>

namespace RWLoader
{
    class TextureDict : public Chunk
    {
    public:
        TextureDict(std::istream &);

        int num_textures;
        int device_id = 0;
    };
}
