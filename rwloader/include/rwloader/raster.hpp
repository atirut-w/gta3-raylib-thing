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

        int raster_format;
        union
        {
            int d3d_format;
            int has_alpha;
        };
        int width;
        int height;
        int depth;
        int num_mip_levels;
        int raster_type;
        union
        {
            char compression;
            struct
            {
                int alpha : 1;
                int cube_texture : 1;
                int auto_mip_maps : 1;
                int compressed : 1;
                int padding : 4;
            };
        };
    };
}
