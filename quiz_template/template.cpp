//templates
//function
#include <iostream>
#include <string>
using namespace std;

template<typename T>
inline void FAST_copy(T& dest, T& src)
{
  dest = src;
}

//TO_DO  ***********
//please write a template specilization for this template function with a class "special_class" 
template<> inline void FAST_copy<char> (char& dest, char& src) 
{
  dest = src;
}; 


//class
// file my2D.h
template<class X, class Y>
class my2D
{
protected:
	X x;
	Y y;
public:
	my2D(X x, Y y){
//TO_DO  ***********
//codes here to set the data member x and y  ************
	  this->x = x;
	  this->y = y;
	}
	X getX();
	Y getY();
};

//TO_DO  ***********
//create a new template class my2D_child which inherits from
//this template with new member function length(), 
template<class X, class Y, class T> 
class my2D_child:public my2D<X, Y> {
public:
  T length();
  my2D_child(X x, Y y):my2D<X, Y>(x, y){
  }
};
//write a template specilization of my2D_child for (X=string, Y=string)
// 	

//file my2D.cpp
//#include "my2D.h"
//TO_DO *********************
//impletment the function getX and getY in file my2D.cpp
template<class X, class Y> 
X my2D<X, Y>::getX() {
  return x;
}
template<class X, class Y>
Y my2D<X, Y>::getY() {
  return y;
}
//TO_DO *********************
//implement this length function of my2D_child to return x*x+y*y
//
template<class X, class Y, class T>
T my2D_child<X, Y, T>::length() {
  return (T) (my2D<X, Y>::x * my2D<X, Y>::x + my2D<X, Y>::y * my2D<X, Y>::y);
}
//add a main function in this cpp file with following
int main()
{
//TO_DO *******************
//to use this my2D template for cases (X=int(3), Y=int(4)), (X=float(5.5), Y=float(6.6), 
  my2D<int, int> case1(3, 4);
  cout << case1.getX() << " " << case1.getY() << endl;
  my2D<float, float> case2(5.5, 6.6);
  cout << case2.getX() << " " << case2.getY() << endl;
  
//TO_DO ********************
//print an output of my2D_child's length for (X="I need ", Y="Time to finish")
  my2D_child<int, int, int> case3(3, 4);
  cout << case3.getX() << " " << case3.getY() << " " << case3.length() << endl;
  return 0;
}
