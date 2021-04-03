#include <iostream>

#include "watch.hpp"

int main()
{
    auto csw = ChronoStopwatch();
    csw.start();
    getchar();
    csw.stop();
    std::cout << csw.getElapsedFormatted() << std::endl;
    
    return 0;
}
