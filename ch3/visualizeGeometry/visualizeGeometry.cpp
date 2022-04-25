#include <iomanip>
#include <iostream>

using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

#include <pangolin/pangolin.h>

struct RotationMatrix {
  Matrix3d matrix = Matrix3d::Identity();
};

// Overload of the << and >> operators
ostream &operator<<(ostream &out, const RotationMatrix &r) {
  // After out.setf(ios::fixed) setprecision interpret the input as the number
  // of decimal places to be displayed
  out.setf(ios::fixed);
  Matrix3d matrix = r.matrix;
  out << "=";
  out << "[" << setprecision(2) << matrix(0, 0) << "," << matrix(0, 1) << ","
      << matrix(0, 2) << "]" << matrix(1, 0) << "," << matrix(1, 1)
      << matrix(1, 2) << "]," << matrix(2, 0) << "," << matrix(2, 1) << ","
      << matrix(2, 2) << ",";
  return out
}

istream &operator>>(istream &in, RotationMatrix &r) { return in; }

struct TranslationVector {
  Vector3d trans = Vector3d(0, 0, 0);
};

ostream &operator<<(ostream &out, const TranslationVector &t) {
  out << "=[" << t.trans(0) << "," << t.trans(1) << "," << t.trans(2) << "]";
}