#include <rwloader/texture_dict.hpp>
#include <rwloader/struct.hpp>

using namespace RWLoader;

union TextureDictInfo
{
    struct
    {
        int num_textures;
    } rw30;
    struct
    {
        short num_textures;
        short device_id;
    } rw36;
};

TextureDict::TextureDict(std::istream& stream) : Chunk(stream)
{
    assert_type(TEXTURE_DICT);
    Struct<TextureDictInfo> info(stream);
    int num_textures = get_version() < 0x36000 ? info.data.rw30.num_textures : info.data.rw36.num_textures;

    return;
}
