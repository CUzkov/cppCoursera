#include <iostream>
#include <cstdint>
#include <vector>


int main(int argc, char** argv)
{

    uint32_t N = 0;
    uint16_t R = 0;
    uint16_t massDim[3] = {0, 0, 0};
    uint64_t acc = 0;

    std::cin >> N >> R;

    for(uint32_t i = 0; i < N; i++)
    {
        std::cin >> massDim[0] >> massDim[1] >> massDim[2];
        acc += 
            static_cast<uint64_t>(massDim[0]) * 
            static_cast<uint64_t>(massDim[1]) * 
            static_cast<uint64_t>(massDim[2]) * 
            static_cast<uint64_t>(R);
    }

    std::cout << acc << std::endl;

}