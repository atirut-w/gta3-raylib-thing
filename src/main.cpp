#include <fstream>
#include <rwloader/texture_dict.hpp>

int main()
{
    std::ifstream txd_file("models/menu.txd", std::ios::binary);
    if (!txd_file)
        return 1;
    
    RWLoader::TextureDict txd(txd_file);
    
    return 0;
}
