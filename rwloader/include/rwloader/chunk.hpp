#pragma once
#include <istream>

namespace RWLoader
{
    class Chunk
    {
    public:
        Chunk(std::istream&);

        int type;
        int library_id;
        int size;
    };
}
