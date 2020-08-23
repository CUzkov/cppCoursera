#include <iostream>
#include <cstdint>
#include <vector>


int main(int argc, char** argv)
{
    uint32_t N = 0;
    int64_t acc = 0;

    std::cin >> N;
    std::vector<int> temps;

    for(uint32_t i = 0; i < N; i++)
    {   
        int buff = 0;
        std::cin >> buff;
        acc += buff;
        temps.push_back(buff);
    }

    int64_t avg = acc / static_cast<uint32_t>(temps.size());

    acc = 0;
    N = 0;

    std::vector<uint32_t> daysIndex;

    for(uint32_t temp : temps)
    {   
        if(static_cast<int>(temp) > avg) {
            N++;
            daysIndex.push_back(acc);
        }
        acc++;
    }

    std::cout << N << std::endl;

    for(uint32_t day : daysIndex)
    {
        std::cout << day << ' ';
    }

}