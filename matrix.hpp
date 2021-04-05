#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <omp.h>
#include <pthread.h>

typedef std::vector<std::vector<int>> matrix;

bool isCompatible(matrix m1, matrix m2) {
    return m1.size() > 0 && m2.size() > 0 && m1.size() == m2[0].size() && m1[0].size() == m2.size();
}

void mPrint(matrix r) {
    for (size_t i = 0; i < r.size(); ++i) {
        for (size_t j = 0; j < r[0].size(); ++j) {
            std::cout << r[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

matrix nMatrixMult(matrix m1, matrix m2) {
    if (!isCompatible(m1, m2)) return matrix();

    auto res = m1;

    for (size_t i = 0; i < m1.size(); ++i) {
        for (size_t j = 0; j < m1[0].size(); ++j) {
            res[i][j] = m1[i][j] * m2[j][i];
        }
    }

    return res;
}

matrix pMatrixMult(matrix m1, matrix m2) {
    if (!isCompatible(m1, m2)) return matrix();

    auto res = m1;

#pragma omp parallel shared(res, m1, m2)
    {
#pragma omp for
        for (size_t i = 0; i < m1.size(); ++i) {
            for (size_t j = 0; j < m1[0].size(); ++j) {
                res[i][j] = m1[i][j] * m2[j][i];
            }
        }
    }

    return res;
}

matrix m1g, m2g, mresg;

void *mRunner(void *param) {
    int *i = (int *) param;
    for (size_t j = 0; j < m1g[0].size(); ++j) {
        mresg[*i][j] = m1g[*i][j] * m2g[j][*i];
    }

    pthread_exit(0);
}

matrix tMatrixMult(matrix m1, matrix m2) {
    if (!isCompatible(m1, m2)) return matrix();

    mresg = m1;
    m1g = m1;
    m2g = m2;

    pthread_t *tid = new pthread_t[m1.size()];
    pthread_attr_t *attr = new pthread_attr_t[m1.size()];

    for (size_t i = 0; i < m1g.size(); i++) {
        pthread_attr_init(&attr[i]);
        pthread_create(&tid[i], &attr[i], mRunner, &i);
        pthread_join(tid[i], NULL);
    }

    return mresg;
}

#endif // MATRIX_HPP
