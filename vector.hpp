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

unsigned long long nVectorSum(vector v) {
    unsigned long long res = 0;
    for (int i = 0; i < v.size(); ++i) {
        res += v[i];
    }
    return res;
}

unsigned long long pVectorSum(vector v) {
    unsigned long long res = 0;

#pragma omp parallel reduction(+:res)
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
    // dividir pela quantidade de threads do pc

}

#endif // VECTOR_HPP
