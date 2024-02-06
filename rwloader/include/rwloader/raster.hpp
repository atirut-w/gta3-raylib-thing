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
            int compression;
            struct
            {
                bool has_alpha : 1;
                bool is_cube : 1;
                bool auto_mip_maps : 1;
                bool compressed : 1;
                int pad : 4;
            };
        };
    };
}
