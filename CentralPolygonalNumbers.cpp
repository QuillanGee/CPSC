/// @file CentralPolygonalNumbers.cpp
/// @brief Implementation for CentralPolygonalNumbers
/// @author Quillan Gee qgee@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++
#include <iostream>
#include <cmath>
#include <fstream>
#include <array>
#include <cstring>
using namespace std;

class CentralPolygonalNumbers
{
public:
  CentralPolygonalNumbers();
  CentralPolygonalNumbers(int nMax);
  ~CentralPolygonalNumbers();
  void display();
  bool save(string strFilename);
private:
  int m_nMax;
  int* mp_iNumbers;
  ofstream ofsNumbers;
};

CentralPolygonalNumbers :: CentralPolygonalNumbers(){
  m_nMax = 0;
  mp_iNumbers = new int[1 + m_nMax];
  mp_iNumbers[0] = 1;
}

CentralPolygonalNumbers :: CentralPolygonalNumbers(int maxNumber){
  m_nMax = maxNumber;
  mp_iNumbers = new int [m_nMax+1];
  int pieces;
  for (int i = 0; i < m_nMax + 1; i++){
    pieces = (pow(i,2)+i+2)/2;
    mp_iNumbers[i] = pieces;
  }
}

CentralPolygonalNumbers :: ~CentralPolygonalNumbers(){
  delete[] mp_iNumbers;
  cout << "~CentralPolygonalNumbers called" << endl;
}

void CentralPolygonalNumbers :: display(){
  for(int i = 0; i <= m_nMax; i++){
    cout << "n: " << i << " , max number of pieces: " << mp_iNumbers[i] << endl;
  }
}

bool CentralPolygonalNumbers :: save(string strFilename) {
  ofsNumbers.open("CPN");
  if (!ofsNumbers.is_open()){
    cout << "Failed to open file CPN" << endl;
  }
  for (int i = 0; i <= m_nMax; i++){
    ofsNumbers << mp_iNumbers[i] << endl;
  }
  ofsNumbers.close();
  return true;
}

int main(){
  CentralPolygonalNumbers cpn(10);
  cpn.display();
  cpn.save("CPN");
}
