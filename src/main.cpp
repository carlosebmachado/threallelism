#include <iostream>
#include <omp.h>
#include <list>

#include "watch.hpp"
#include "matrix.hpp"
#include "vector.hpp"

int main()
{
    int a1[][3] = {{1, 2, 3},
                   {6, 5, 4}};
    int a2[][3] = {{1, 2},
                   {3, 4},
                   {5, 6}};
    auto m1 = new Matrix((int**)a1, 3, 3);
    auto m2 = new Matrix((int**)a2, 3, 3);
    auto r = nMatrixMult(m1, m2);

    // for (size_t i = 0; i < r->rowNum; i++)
    // {
    //     for (size_t j = 0; j < r->colNum; j++)
    //     {
    //         std::cout << r->d[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    
    return 0;

    auto csw = ChronoStopwatch();

    csw.start();

#pragma omp parallel
    {
        std::cout << "Hello World!\n";
    }

    csw.stop();

    std::cout << csw.getElapsedFormatted() << std::endl;

    return EXIT_SUCCESS;
}
