#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <omp.h>
#include <pthread.h>
#include <ctime>
#include <thread>

typedef std::vector<int> vector;

vector randVector(size_t size, int limit = 100) {
    vector v = vector();
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        v.push_back(rand() % (limit + 1));
    }
    return v;
}

unsigned long long nVectorSum(const vector& v) {
    unsigned long long res = 0;
    for (int i : v) {
        res += i;
    }
    return res;
}

unsigned long long pVectorSum(const vector& v) {
    unsigned long long res = 0;

#pragma omp parallel shared(v) reduction(+:res) default(none)
    {
#pragma omp for
        for (int i : v) {
            res += i;
        }
    }

    return res;
}

vector vg;
unsigned long divisor;
unsigned long vdiv;
unsigned long long *ir;

void *vRunner(void *param) {
    int *i = (int *) param;
    unsigned long begin = *i * vdiv;
    unsigned long end = *i == divisor - 1 ? vg.size() : vdiv + begin;
    ir[*i]=0;
    for (unsigned long j = begin; j < end; ++j){
        ir[*i] += vg[j];
    }
    pthread_exit(nullptr);
}

unsigned long long tVectorSum(const vector& v) {
    divisor = (v.size() / 2) < std::thread::hardware_concurrency() ? (v.size() / 2) : std::thread::hardware_concurrency();
    vdiv = v.size() / divisor;
    vg = v;
    ir = new unsigned long long[divisor];
    unsigned long long vresg = 0;
    auto *tid = new pthread_t[divisor];

    for (size_t i = 0; i < divisor; ++i) {
        pthread_create(&tid[i], nullptr, vRunner, &i);
        pthread_join(tid[i], nullptr);
        vresg += ir[i];
    }

    delete ir;
    delete tid;
    return vresg;
}

#endif // VECTOR_HPP
