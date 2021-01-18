#include "vojd.h"

void generator(int** matrix, int k, int m){
    srand(time(0));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j]=(rand()/181)-90;
        }
    }
    outer(matrix, k, m, "Generated matrix:");
}

void avarage(int** matrix, float * avar, int k, int m){
    int* min_pos=new int[k];
    for (int i = 0; i < k; ++i) {
        int min=100;
        int min_p=0;
        for(int j=0; j<m; j++){
            if(matrix[i][j]<min){
                min=matrix[i][j];
                min_p=j;
            }
        }
        min_pos[i]=min_p;
    }
    for (int i = 0; i<k ; ++i) {
        int sum=0;
        int count=0;
        for (int j = min_pos[i]+1; j < m; ++j) {
            if(matrix[i][j]<0){
                sum+=abs(matrix[i][j]);
                count++;
            }
        }
        if(count!=0) {
            avar[i] = float(sum / count);
        }
        else {
            avar[i] = 0;
        }
        cout<<"Avarage of row number "<<i<<" = "<<avar[i]<<endl;
    }
}

int** deleter(int** matrix, float * avar, int k, int m){
    int** changed=new int*[k-1];
    for (int i = 0; i < k - 1; ++i) {
        changed[i]=new int[m];
    }
    int max_pos=0;
    int max=0;
    for (int i = 0; i < k; ++i) {
        if(avar[i]>max){
            max=avar[i];
            max_pos=i;
        }
    }
    int pos=0;
    for (int i = 0; i < k; ++i) {
        if(i!=max_pos){
            changed[pos]=matrix[i];
            pos++;
        }
    }
    outer(changed, k-1, m, "Changed matrix: ");
    return changed;
}

void outer(int** matrix, int k, int m, string name){
    cout<<endl<<name<<endl;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<setw(4)<<matrix[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}