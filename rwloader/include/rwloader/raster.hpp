#pragma once
#include <rwloader/chunk.hpp>
#include <string>

namespace RWLoader
{
    class Raster : public Chunk
    {
    public:
        Raster(std::istream &);

        int platform_id;
        int filter_mode;
        int u_addressing;
        int v_addressing;
        std::string name;
        std::string mask_name;
    };
}
