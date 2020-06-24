#include <fstream>
#include <iostream>
#include <iomanip>


int main(int argc, char const *argv[])
{
    
    std::string buffer;
    int N = 0, M = 0;

    std::ifstream read("input.txt");
    
    if(read.is_open()) {

        read >> N >> M;

        for (int i = 0; i < N; i++)
        {
            for (int i = 0; i < M; i++)
            {
                
            }
            
        }
    } 
    
    read.close();

    return 0;
}