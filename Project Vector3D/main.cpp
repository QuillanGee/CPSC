#include <vector>
#include <iostream>
#include "Vector3D.h"
#include "Vector3D.cpp"
#include <cmath>
int main()
{
  double const PI = 3.14159265;

  double Fx = 10.0 * cos(45* PI/180.0); //Newtons
  double Fy = 10.0 * sin(45* PI/180.0); //Newtons
  double Fz = 0; //Newtons

  double Dx = 10.0; //Meters
  double Dy = 0.0;
  double Dz = 0.0; //Meters

  Vector3D vec3dForce(Fx,Fy,Fz);
  Vector3D vec3Displacement(Dx,Dy,Dz);

  std::cout << Fx << endl;
  vec3dForce.display();
  vec3Displacement.display();

  double dWork = vec3dForce.dot(vec3Displacement);
  std::cout << "Work: " << dWork << std::endl;

  return 0;
}
