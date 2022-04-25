#include <cmath>
#include <iostream>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

int main(int argc, char **argv) {
  Matrix3d rotation_matrix = Matrix3d::Identity();

  // AngleAxisd Represents a 3D rotation as a rotation angle around an arbitrary
  // 3D axis. "d" is for double. The AngleAxisd below rotate of pi / 4 around
  // the z axis.
  AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1));

  cout.precision(3);
  // .matrix() == .toRotationMatrix()
  cout << "rotation matrix =\n" << rotation_vector.matrix() << endl;

  rotation_matrix = rotation_vector.toRotationMatrix();

  Vector3d v(1, 0, 0);
  Vector3d v_rotated = rotation_vector * v;
  cout << "(1, 0, 0) after rotation (by angle axis) = " << v_rotated.transpose()
       << endl;
  v_rotated = rotation_matrix * v;
  cout << "(1, 0, 0) after rotation (by matrix) = " << v_rotated.transpose()
       << endl;

  // the Euler-angles of the rotation matrix *this using the convention defined
  // by the triplet (a0,a1,a2) Each of the three parameters a0,a1,a2 represents
  // the respective rotation axis as an integer in {0,1,2}. For instance, in:
  // Vector3f ea = mat.eulerAngles(2, 0, 2); * "2" represents the z axis and "0"
  // the x axis, etc.
  Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0);
  cout << "yaw pitch roll = " << euler_angles.transpose() << endl;

  // Euclidean transformation matrix using Eigen::Isometry
  Isometry3d T = Isometry3d::Identity(); // Although called 3d, it is 4*4
  T.rotate(rotation_vector);
  T.pretranslate(Vector3d(1, 3, 4));
  cout << "Transform matrix = \n" << T.matrix() << endl;

  Vector3d v_transformed = T * v;
  cout << "v transformed = " << v_transformed.transpose() << endl;

  Quaterniond q = Quaterniond(rotation_vector);
  cout << "quaternioin from rotation vector = " << q.coeffs().transpose()
       << endl;
  v_rotated = q * v;
  cout << "(1, 0, 0) after rotation = " << v_rotated.transpose() << endl;
  cout << "should be equal to "
       << (q * Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose()
       << endl;
  return 0;
}