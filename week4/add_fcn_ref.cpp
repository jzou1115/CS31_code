// function example
#include <iostream>
using namespace std;

void addition (int& a, int& b)
{
	a = a + b;
}

int main ()
{
  int a = 5;
  int b =3;
  addition (a, b);

  cout << "A is " << a  << endl;
  cout << "B is " << b << endl;

  return 0;
}

