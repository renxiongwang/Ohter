#include<iostream>
#include"myMatrix.h"
using namespace std;

int main() {
  myMatrix A(3, 3, 1);
  A.print();
  myMatrix B(3, 3, 2);
  B.print();
  myMatrix C = A + B;
  C.print();
  myMatrix D = A * B;
  D.print();
  myMatrix E(3, 4, 2);
  E.print();
  myMatrix F = A * E;
  F.print();
  return 1;
}
