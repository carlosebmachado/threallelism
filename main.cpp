#include "watch.hpp"
#include "matrix.hpp"
#include "vector.hpp"

int main() {
    int op;
    auto csw = ChronoStopwatch();

    matrix m1 = {{1, 2, 3},
                 {6, 5, 4}};
    matrix m2 = {{1, 2},
                 {3, 4},
                 {5, 6}};

    std::vector<vector> v = {
            {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
            randVector(10000, 100),
            randVector(150000, 100),
            randVector(500000, 100),
            randVector(1000000, 100),
            randVector(5000000, 100),
            randVector(50000000, 100),
            randVector(500000000, 100)
    };

    while (true) {
        std::cout << "Choose:" << std::endl;
        std::cout << "1 - Project 1" << std::endl;
        std::cout << "2 - Project 2" << std::endl;
        std::cout << "3 - Exit" << std::endl;
        std::cout << "Option: ";
        std::cin >> op;

        if (op == 1) {
            while (true) {
                std::cout << "Choose:" << std::endl;
                std::cout << "1 - Normal" << std::endl;
                std::cout << "2 - OpenMP" << std::endl;
                std::cout << "3 - PThread" << std::endl;
                std::cout << "4 - Back" << std::endl;
                std::cout << "Option: ";
                std::cin >> op;

                if (op == 1) {
                    csw.start();
                    auto r = nMatrixMult(m1, m2);
                    csw.stop();
                    mPrint(r);
                    std::cout << csw.getElapsedFormatted() << std::endl;
                } else if (op == 2) {
                    csw.start();
                    auto r = pMatrixMult(m1, m2);
                    csw.stop();
                    mPrint(r);
                    std::cout << csw.getElapsedFormatted() << std::endl;
                } else if (op == 3) {
                    csw.start();
                    auto r = tMatrixMult(m1, m2);
                    csw.stop();
                    mPrint(r);
                    std::cout << csw.getElapsedFormatted() << std::endl;
                } else if (op == 4) {
                    break;
                } else {
                    std::cout << op << " is not a valid option" << std::endl;
                }
            }
        } else if (op == 2) {
            while (true) {
                std::cout << "Choose:" << std::endl;
                std::cout << "1 - Normal" << std::endl;
                std::cout << "2 - OpenMP" << std::endl;
                std::cout << "3 - PThread" << std::endl;
                std::cout << "4 - Back" << std::endl;
                std::cout << "Option: ";
                std::cin >> op;

                if (op == 1) {
                    for (int i = 0; i < v.size(); ++i) {
                        csw.start();
                        auto r = nVectorSum(v[i]);
                        csw.stop();
                        std::cout << "v" << i << "(" << v[i].size() << "): " << r << std::endl;
                        std::cout << csw.getElapsedFormatted() << std::endl;
                    }
                } else if (op == 2) {
                    for (int i = 0; i < v.size(); ++i) {
                        csw.start();
                        auto r = pVectorSum(v[i]);
                        csw.stop();
                        std::cout << "v" << i << "(" << v[i].size() << "): " << r << std::endl;
                        std::cout << csw.getElapsedFormatted() << std::endl;
                    }
                } else if (op == 3) {

                } else if (op == 4) {
                    break;
                } else {
                    std::cout << op << " is not a valid option" << std::endl;
                }
            }
        } else if (op == 3) {
            break;
        } else {
            std::cout << op << " is not a valid option" << std::endl;
        }
    }
    std::cout << "Program finalized" << std::endl;

    return EXIT_SUCCESS;
}
