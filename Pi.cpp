#include <iostream>
#include <math.h>
#include <cfloat>
#include <cmath>
#include <iomanip>      // std::setprecision
using namespace std;
int main() {
  int upperBound;
  double pi = 0.0;
  cout << "Please enter a non-negative integer to be the upper limit of the summation for the Leibnitz formula to find pi: " << endl;
  cin >> upperBound;


  //computing for pi
  for (int k = 0;k<=upperBound;k++){
      pi += ((pow(-1,k)) / ((2*k)+1));
  }
  pi = pi*4;

  cout << "PI (approx): " << fixed << setprecision(15) << pi;
  cout << "; n: " << setw(7) << upperBound << endl;
  cout << "PI (actual): " << "3.141592653589793" << endl;

  cout << "Decimal digits of precision: " << DBL_DIG << endl;
  cout << "Number of base 2 mantissa digits of double precision floating point value: " <<  DBL_MANT_DIG << endl;
  cout << "Next representable number from 3.141592653589793: " << nextafter(3.141592653589793, 3.14) << endl;
}
