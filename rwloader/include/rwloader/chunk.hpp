#pragma once
#include <istream>

namespace RWLoader
{
    class Chunk
    {
    protected:
        int library_id;

    public:
        Chunk(std::istream &);

        int type;
        int size;

        int get_version();
    };
}
