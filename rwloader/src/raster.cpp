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

    filter_mode = (FilterMode)read<char>(stream);
    int uv_addressing = read<char>(stream);
    u_addressing = (UVAddressing)(uv_addressing & 0x0F);
    v_addressing = (UVAddressing)(uv_addressing >> 4);

    stream.seekg(2, std::ios::cur); // Skip padding
    char buffer[32];
    stream.read(buffer, 32);
    name = buffer;
    stream.read(buffer, 32);
    mask_name = buffer;

    raster_format = (RasterFormat)read<int>(stream);
    d3d_format = read<int>(stream);
    width = read<short>(stream);
    height = read<short>(stream);
    depth = read<char>(stream);
    num_mip_levels = read<char>(stream);
    raster_type = read<char>(stream);
    compression = read<char>(stream);
}
