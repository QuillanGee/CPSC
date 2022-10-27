/// @brief Programming Project Vector3D
/// CPSC-298-6 Programming in C++ 3D vectors
/// @author qgee@chapman.edu Quillan Gee

#include <iostream>
#include "Vector3D.h"
using namespace std;

Vector3D::Vector3D()
{
  this->m_vector.at(0) = 0.0;
  this->m_vector.at(1) = 0.0;
  this->m_vector.at(2) = 0.0;
  return;
}

Vector3D::Vector3D(double dX, double dY, double dZ)
{
  this->m_vector.at(0) = dX;
  this->m_vector.at(1) = dY;
  this->m_vector.at(2) = dZ;
  return;
}

Vector3D::~Vector3D() {}

void Vector3D::display()
{
  cout << this->m_vector.at(0) << " x, " << this->m_vector.at(1) << " y, " << this->m_vector.at(2) << " z, " << endl;
}

double Vector3D::dot(Vector3D vec3d)
{
  double dotProduct;
  for(int i = 0;i<this->m_vector.size(); i++)
  {
    dotProduct += (this->m_vector.at(i) * vec3d.m_vector.at(i) );
  }
  return dotProduct;
}
