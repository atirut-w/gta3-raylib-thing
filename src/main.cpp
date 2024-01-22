#include <fstream>
#include <rwloader/chunk.hpp>

int main()
{
    std::ifstream txd_file("models/menu.txd", std::ios::binary);
    if (!txd_file)
        return 1;
    
    RWLoader::Chunk chunk(txd_file);
    
    return 0;
}
