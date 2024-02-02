#include <rwloader/texture_dict.hpp>

using namespace RWLoader;

TextureDict::TextureDict(std::istream& stream) : Chunk(stream)
{
    assert_type(TEXTURE_DICT);
}
