#include <rwloader/texture_dict.hpp>
#include <rwloader/struct.hpp>

using namespace RWLoader;

class TXDInfo : public Struct
{
public:
    int num_textures;
    int device_id = 0;

    TXDInfo(std::istream& stream) : Struct(stream)
    {
        if (get_version() < 0x36000)
        {
            num_textures = read<int>(stream);
        }
        else
        {
            num_textures = read<short>(stream);
            device_id = read<short>(stream);
        }
    }
};

TextureDict::TextureDict(std::istream& stream) : Chunk(stream)
{
    assert_type(TEXTURE_DICT);
    TXDInfo info(stream);

    return;
}
