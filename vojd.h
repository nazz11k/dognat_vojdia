#include "iostream"
#include "iomanip"
#include "random"
#include "ctime"

using namespace std;

void generator(int** matrix, int k, int m);
void avarage(int** matrix, float * avar, int k, int m);
int** deleter(int** matrix, float * avar, int k, int m);
void outer(int** matrix, int k, int m, string name);