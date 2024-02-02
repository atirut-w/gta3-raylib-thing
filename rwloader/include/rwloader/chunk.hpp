#pragma once
#include <istream>

namespace RWLoader
{
    enum ChunkType
    {
        TEXTURE_DICT = 0x16,
    };
    
    class Chunk
    {
    protected:
        int library_id;

        template<typename T>
        T read(std::istream& stream)
        {
            T value;
            stream.read(reinterpret_cast<char*>(&value), sizeof(T));
            return value;
        }

        void assert_type(int expected);

    public:
        Chunk(std::istream &);

        int type;
        int size;

        int get_version();
    };
}
