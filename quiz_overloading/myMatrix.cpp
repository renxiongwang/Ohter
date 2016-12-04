#include"myMatrix.h"
#include<vector>
#include<assert.h>
using namespace std;

// myMatrix constructor
myMatrix::myMatrix(int m, int n, double value) {
  this->m = m;
  this->n = n;
  values = new double[m * n];
  for (int i = 0; i < m * n; ++i)
    values[i] = value;
}

// MYMATRIX GET: RETURN VALUE FOR ROW I, COL J
double myMatrix::get(int i, int j) {
  assert (i <= m  && i >= 1 && j <= n && j >= 1);
  return values[(i - 1) * n + j - 1];
}

// MYMATRIX SET: SET VALUE FOR ROW I, COL J
void myMatrix::set(int i, int j, double value) {
  values[(i - 1) * n + j - 1] = value;
}

// MYMATRIX GETM: RETURN NUMBER OF ROWS
int myMatrix::getm() {
  return m;
}

// MYMATRIX GETN: RETURN NUMBER OF COLS
int myMatrix::getn() {
  return n;
}

// OPERATOR +
myMatrix myMatrix::operator +(myMatrix &A) {
  assert(m == A.getm() && n == A.getn());
  myMatrix res(m, n, 0);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      res.set(i, j, get(i, j) + A.get(i, j));
    }
  }
  return res;
}
myMatrix operator +(myMatrix &A, myMatrix &B) {
  assert(A.getm() == B.getm() && A.getn() == B.getn());
  myMatrix res(A.getm(), A.getn(), 0);
  for (int i = 1; i <= A.getm(); ++i) {
    for (int j = 1; j <= A.getn(); ++j) {
     res.set(i, j, A.get(i, j) + B.get(i, j));
    }
  }
  return res;	      
}

// OPERATOR *
myMatrix myMatrix::operator *(myMatrix &A) {
  assert(n == A.getm());
  myMatrix res(m, A.getn(), 0);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= A.getn(); ++j) {
      int value = 0;
      for (int k = 1; k <= n; ++k)
	value += get(i, k) * A.get(k, j);
      res.set(i, j, value);
    }
  }
  return res;
}
myMatrix operator *(myMatrix &A, myMatrix &B) {
  assert(A.getn() == B.getm());
  myMatrix res(A.getm(), B.getn(), 0);
  for (int i = 1; i <= A.getm(); ++i) {
    for (int j = 1; j <= B.getn(); ++j) {
      int value = 0;
      for (int k = 1; k <= A.getn(); k++) 
	value += A.get(i, k) * B.get(k, j); 
      res.set(i, j, value);
    }
  }
  return res;	      
}

// print myMatrix
void myMatrix::print() {
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << values[(i - 1) * n + j - 1] << " ";
    }
    cout << endl;
  }
}

