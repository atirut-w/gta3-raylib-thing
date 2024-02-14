#pragma once
#include <rwloader/chunk.hpp>
#include <string>

namespace RWLoader
{
    class Raster : public Chunk
    {
    public:
        Raster(std::istream &);

        enum FilterMode
        {
            FILTER_NONE,
            FILTER_NEAREST,
            FILTER_LINEAR,
            FILTER_MIP_NEAREST,
            FILTER_MIP_LINEAR,
            FILTER_LINEAR_MIP_NEAREST,
            FILTER_LINEAR_MIP_LINEAR
        };

        enum UVAddressing
        {
            WRAP_NONE,
            WRAP_WRAP,
            WRAP_MIRROR,
            WRAP_CLAMP
        };

        enum RasterFormat
        {
            FORMAT_DEFAULT = 0x0000,
            FORMAT_1555 = 0x0100,
            FORMAT_565 = 0x0200,
            FORMAT_4444 = 0x0300,
            FORMAT_LUM8 = 0x0400,
            FORMAT_8888 = 0x0500,
            FORMAT_888 = 0x0600,
            FORMAT_555 = 0x0a00,

            FORMAT_EXT_AUTO_MIPMAP = 0x1000,
            FORMAT_EXT_PAL8 = 0x2000,
            FORMAT_EXT_PAL4 = 0x4000,
            FORMAT_EXT_MIPMAP = 0x8000
        };

        int platform_id;
        FilterMode filter_mode;
        UVAddressing u_addressing;
        UVAddressing v_addressing;
        std::string name;
        std::string mask_name;

        RasterFormat raster_format;
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
                int auto_mipmaps : 1;
                int compressed : 1;
                int padding : 4;
            };
        };
    };
}
