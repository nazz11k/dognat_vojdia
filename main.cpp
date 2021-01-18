#include "vojd.h"

int main() {
    int k, m;
    cin>>k>>m;
    int** matrix=new int*[k];
    for (int i = 0; i < k; ++i) {
        matrix[i]=new int[m];
    }
    float* avar= new float[k];
    generator(matrix, k, m);
    avarage(matrix, avar, k,m);
    matrix=deleter(matrix, avar, k, m);
}
