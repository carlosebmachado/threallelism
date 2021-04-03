#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

class Matrix
{
public:
    int **d;
    int rowNum;
    int colNum;

    Matrix(int **d, int rowNum, int colNum)
    {
        this->d = d;
        this->rowNum = rowNum;
        this->colNum = colNum;
    }
};

bool isCompatible(Matrix* m1, Matrix* m2)
{
    return m1->colNum == m2->rowNum;
}

int** createMatrix(int l, int c)
{
    int** m = new int*[l];
    for(size_t i = 0; i < l; i++)
    {
        m[i] = new int[c];
    }
    return m;
}

Matrix* nMatrixMult(Matrix* m1, Matrix* m2)
{
    if (!isCompatible(m1, m2)) return nullptr;

    int** res = createMatrix(m1->rowNum, m1->colNum);

    for(size_t i = 0; i < m1->rowNum; i++)
    {
        for (size_t j = 0; j < m1->colNum; j++)
        {
            res[i][j] = m1->d[i][j] * m2->d[j][i];
        }
    }

    return nullptr;
}

bool pMatrixMult()
{
    return false;
}

bool tMatrixMult()
{
    return false;
}

#endif // MATRIX_HPP
