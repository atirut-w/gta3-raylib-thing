#include <rwloader/struct.hpp>

using namespace RWLoader;

Struct::Struct(std::istream& stream) : Chunk(stream)
{
    assert_type(STRUCT);
}
