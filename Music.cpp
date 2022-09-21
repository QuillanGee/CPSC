/// @Music.cpp <Music>
/// @brief <This program computes musical note frequencies>
/// @author <Quillan Gee>
#include <iostream>
#include <math.h>
using namespace std;
int main() {

  double Fr = 16.35; //this is the reference frequency
  double dTwelfthRootOfTwo = 1.059463094359; //this is the twelth root of two
  long c = 34500; //speed of sound

  //calculating the power of two for each k value (the half tone offset)
  long twoPow0 = pow(2,0);
  long twoPow3 = pow(2,3);
  long twoPow4 = pow(2,4);
  long twoPow7 = pow(2,7);
  long twoPow8 = pow(2,8);

  //calculating the frequency of each note according to the k value and the v value (octave number)
  double Fkv1 = Fr * twoPow0 * pow(dTwelfthRootOfTwo,0);
  double Fkv2 = Fr * twoPow0 * pow(dTwelfthRootOfTwo,1);
  double Fkv3 = Fr * twoPow0 * pow(dTwelfthRootOfTwo,2);
  double Fkv4 = Fr * twoPow4 * pow(dTwelfthRootOfTwo,0);
  double Fkv5 = Fr * twoPow7 * pow(dTwelfthRootOfTwo,3);
  double Fkv6 = Fr * twoPow8 * pow(dTwelfthRootOfTwo,0);
  double Fkv7 = Fr * twoPow3 * pow(dTwelfthRootOfTwo,2);

  //calculating the wavelength corresponding to the frequency
  double wL1 = c/Fkv1;
  double wL2 = c/Fkv2;
  double wL3 = c/Fkv3;
  double wL4 = c/Fkv4;
  double wL5 = c/Fkv5;
  double wL6 = c/Fkv6;
  double wL7 = c/Fkv7;


  //displaying each of the frequency's, octave number, half tone offset, and wavelength
  cout << "Reference Frequency: " << Fr << " Hz" << endl;
  cout << "Speed of Sound 345m/s" << endl;
  cout << "Note: C0; nu: 0; k: 0; frequency: " << Fkv1 << " Hz; wavelength: " << wL1 << " cm" << endl;
  cout << "Note: C#0; nu: 0; k: 1; frequency: " << Fkv2 << " Hz; wavelength: " << wL2 << " cm" << endl;
  cout << "Note: D0; nu: 0; k: 2; frequency: " << Fkv3 << " Hz; wavelength: " << wL3 << " cm" << endl;
  cout << "Note: C4; nu: 4; k: 0; frequency: " << Fkv4 << " Hz; wavelength: " << wL4 << " cm" << endl;
  cout << "Note: D#7; nu: 7; k: 3; frequency: " << Fkv5 << " Hz; wavelength: " << wL5 << " cm" << endl;
  cout << "Note: C8; nu: 8; k: 0; frequency: " << Fkv6 << " Hz; wavelength: " << wL6 << " cm" << endl;
  cout << "Note: D3; nu: 3; k: 2; frequency: " << Fkv7 << " Hz; wavelength: " << wL7 << " cm" << endl;


}
