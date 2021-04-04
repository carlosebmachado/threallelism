#include "watch.hpp"
#include "matrix.hpp"
#include "vector.hpp"

int main()
{
	int op;
    auto csw = ChronoStopwatch();
	matrix m1 = {{1, 2, 3},
                 {6, 5, 4}};
	matrix m2 = {{1, 2},
                 {3, 4},
                 {5, 6}};

	while(true)
	{
		std::cout << "Choose and option:" << std::endl;
		std::cout << "1 - Project 1" << std::endl;
		std::cout << "2 - Project 2" << std::endl;
		std::cout << "3 - Exit" << std::endl;
		std::cout << "Option: ";
		std::cin >> op;

		if(op == 1)
		{
			while(true)
			{
				std::cout << "Choose and option:" << std::endl;
				std::cout << "1 - Normal" << std::endl;
				std::cout << "2 - OpenMP" << std::endl;
				std::cout << "3 - PThread" << std::endl;
				std::cout << "4 - Back" << std::endl;
				std::cout << "Option: ";
				std::cin >> op;

				if(op == 1)
				{
				    csw.start();
				    auto r = nMatrixMult(m1, m2);
				    csw.stop();
				    print(r);
				    std::cout << csw.getElapsedFormatted() << std::endl;
				}
				else if(op == 2)
				{
				    csw.start();
				    auto r = pMatrixMult(m1, m2);
				    csw.stop();
				    print(r);
				    std::cout << csw.getElapsedFormatted() << std::endl;
				}
				else if(op == 3)
				{
				    csw.start();
				    auto r = tMatrixMult(m1, m2);
				    csw.stop();
				    print(r);
				    std::cout << csw.getElapsedFormatted() << std::endl;
				}
				else if(op == 4)
				{
					break;
				}
			}
		    auto r = nMatrixMult(m1, m2);

		    print(r);
		}
		else if(op == 2)
		{

		}
		else if(op == 3)
		{
			break;
		}
		else
		{
			std::cout << op << " is not a valid option" << std::endl;
		}
	}

    return EXIT_SUCCESS;
}
