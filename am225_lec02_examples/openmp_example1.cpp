#include <cstdio>
#include "omp.h"
int main() {

#pragma omp parallel num_threads(8) 
    {
        // Since this is within a parallel block, each thread
        // will execute it
        printf("%d",omp_get_num_threads());
        puts("Hi");
    }
}
