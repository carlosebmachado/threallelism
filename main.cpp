#include "watch.hpp"
#include "matrix.hpp"
#include "vector.hpp"

int main() {
    int op;
    auto csw = ChronoStopwatch();

    std::cout << "Loading matrix and vectors...\n";

    std::vector<matrix> m = {
            {{1, 2, 3},
             {6, 5, 4}},
            {{1, 2},
             {3, 4},
             {5, 6}},
            randMatrix(1000, 500),
            randMatrix(500, 1000),
            randMatrix(10000, 5000),
            randMatrix(5000, 10000)
    };

    std::vector<vector> v = {
            {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
            randVector(10000),
            randVector(150000),
            randVector(500000),
            randVector(1000000),
            randVector(5000000),
            randVector(50000000),
            randVector(500000000)
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

                if (op == 1 || op == 2 || op == 3) {
                    for (int i = 0; i < m.size(); i += 2) {
                        csw.start();
                        matrix r;
                        if (op == 1) {
                            r = nMatrixMult(m[i], m[i + 1]);
                        } else if (op == 2) {
                            r = pMatrixMult(m[i], m[i + 1]);
                        } else if (op == 3) {
                            r = tMatrixMult(m[i], m[i + 1]);
                        }
                        csw.stop();
                        if (i == 0) {
                            mPrint(r);
                        }
                        std::cout << "matrix(" << i << ")[" << m[i].size() << "][" << m[i][0].size() << "]\n";
                        std::cout << "matrix(" << i+1 << ")[" << m[i+1].size() << "][" << m[i+1][0].size() << "]\n";
                        std::cout << csw.getElapsedFormatted() << std::endl;
                    }
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

                if (op == 1 || op == 2 || op == 3) {
                    for (int i = 0; i < v.size(); ++i) {
                        csw.start();
                        unsigned long long r;
                        if (op == 1) {
                            r = nVectorSum(v[i]);
                        } else if (op == 2) {
                            r = pVectorSum(v[i]);
                        } else if (op == 3) {
                            r = tVectorSum(v[i]);
                        }
                        csw.stop();
                        std::cout << "vector(" << i << ")[" << v[i].size() << "]: " << r << std::endl;
                        std::cout << csw.getElapsedFormatted() << std::endl;
                    }
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
