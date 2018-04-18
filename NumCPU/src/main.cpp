#include <iostream>
#include <thread>

int main()
{
    std::size_t nthreads = std::thread::hardware_concurrency();
    std::cout << "NumCPU: " << nthreads << '\n';
}
