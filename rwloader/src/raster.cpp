#include <rwloader/raster.hpp>
#include <rwloader/struct.hpp>
#include <stdexcept>

using namespace RWLoader;

Raster::Raster(std::istream& stream) : Chunk(stream)
{
    assert_type(RASTER);
    Struct data(stream);

    platform_id = read<int>(stream);
    // TODO: Full support for San Andreas (PC), PS2, and Xbox
    if (platform_id != 8)
        throw std::runtime_error("Unsupported platform ID");

    filter_mode = read<char>(stream);
    int uv_addressing = read<char>(stream);
    u_addressing = uv_addressing & 0x0F;
    v_addressing = uv_addressing >> 4;

    stream.seekg(2, std::ios::cur); // Skip padding
    char buffer[32];
    stream.read(buffer, 32);
    name = buffer;
    stream.read(buffer, 32);
    mask_name = buffer;
}
