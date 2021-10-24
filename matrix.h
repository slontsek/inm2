#include <iostream>
#include <vector>
using namespace std;

class Matrix{
private:
  double alpha;
  double eps;

public:
  void set_params(double a, double e){
    alpha = a;
    eps = e;
  }

  vector<double> iterations(vector<double> x_0, vector<vector<double>> A, vector<double> b){
    int N = A.size();
    vector<vector<double>> E(N, vector<double>(N));
    for (int i=0; i < N; i++)
      for (int j=0; j < N; j++)
        if (i==j)
          E[i][j] = 1 - alpha*A[i][j];
        else
          E[i][j] = -alpha*A[i][j];

    vector<double> y(N);
    
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
          y[i]+=(E[i][j]*x_0[j]);
      }
    }
    vector<double> x_k(N);
    for(int i = 0; i < N; i++)
      x_k[i] = y[i] + alpha*b[i];
    
    double C = abs(x_k[0] - x_0[0]);
    for (int i = 1; i < N; i++)
      C = max(C, abs(x_k[i] - x_0[i]));
    while(C > eps){
      for(int i=0;i<N;i++){
        y[i] = 0.0;
        for(int j=0;j<N;j++){
            y[i]+=(E[i][j]*x_k[j]);
        }
      }
      for(int i=0;i<N;i++)
        x_0[i] = x_k[i];
      for(int i = 0; i < N; i++)
        x_k[i] = y[i] + alpha*b[i];
      C = abs(x_k[0] - x_0[0]);
      for (int i = 1; i < N; i++)
        C = max(C, abs(x_k[i] - x_0[i]));
    }
    return x_k;
  }
};