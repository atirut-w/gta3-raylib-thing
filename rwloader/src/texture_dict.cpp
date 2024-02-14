#include <rwloader/texture_dict.hpp>
#include <rwloader/struct.hpp>
#include <rwloader/raster.hpp>

using namespace RWLoader;

TextureDict::TextureDict(std::istream& stream) : Chunk(stream)
{
    assert_type(TEXTURE_DICT);
    Struct info(stream); // Make sure the following chunk is a Struct

    if (info.get_version() < 0x36000)
    {
        num_textures = read<int>(stream);
    }
    else
    {
        num_textures = read<short>(stream);
        device_id = read<short>(stream);
    }

    // TODO: Actually load *all* the textures
    Raster texture(stream);
}
