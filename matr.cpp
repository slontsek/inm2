#include "matrix.h"
int main(){

    vector<vector<double>> A = {{10, -1, 0 ,1}, {0 ,12 ,1, -1}, {1 ,-2 ,16 ,0}, {0 ,2 ,0 ,16}};
    vector<double> b = {0, -28 , 31, 29};
    vector<double> x0 = {1, 0, 0, 0};
    Matrix mat;
    mat.set_params(0.1, 0.001);
    vector<double> x_k = mat.iterations(x0, A, b);
    for (int i = 0; i < x_k.size(); i++){
        cout<< x_k[i] << endl;
    }
    return 0;
}