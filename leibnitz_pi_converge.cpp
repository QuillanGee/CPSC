#include <iostream>
#include <math.h>
#include <cfloat>
#include <cmath>
#include <iomanip>      // std::setprecision
using namespace std;
int main() {
  double pi = 0.0;

  for (int n = 2;n<=1048576;n*=2){
    pi = 0.0;
    for(int i=0;i<=n;i++){
      pi += ((pow(-1,i)) / ((2*i)+1));
    }
    pi*=4;
    cout << "PI: " << fixed << setprecision(15) << pi << "; n: "<< n << endl;

  }
}
