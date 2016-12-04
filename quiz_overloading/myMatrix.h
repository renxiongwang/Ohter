#ifndef DATE_H
#define DATE_H

#include<iostream>
using namespace std;

class myMatrix {

private:
  double* values;
  int m;
  int n;

public:

  //constructor
  myMatrix(int m, int n, double value);

  //operator overloading * and +
  myMatrix operator +(myMatrix &A);
  myMatrix operator *(myMatrix &A);

  //function get return value of Matrix[i][j];
  double get(int i, int j);
  
  //function set Matrix[i][j] as value;
  void set(int i, int j, double value);

  //get dimentsion
  int getm();
  int getn();

  //print out the matrix
  void print();
};

#endif
