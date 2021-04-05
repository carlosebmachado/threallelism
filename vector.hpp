#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <omp.h>
#include <pthread.h>
#include <time.h>

typedef std::vector<int> vector;

vector randVector(size_t size, int limit = 100) {
    vector v = vector();
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        v.push_back(rand() % (limit + 1));
    }
    return v;
}

int nVectorSum(vector v) {
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
        res += v[i];
    }
    return res;
}

int pVectorSum(vector v) {
    int res = 0;

#pragma omp parallel shared(res)
    {
#pragma omp for
        for (int i = 0; i < v.size(); ++i) {
            res += v[i];
        }
    }

    return res;
}

vector vg;
int vresg;

void *vRunner(void *param) {

    pthread_exit(0);
}

int tVectorSum(vector v) {

}

#endif // VECTOR_HPP
