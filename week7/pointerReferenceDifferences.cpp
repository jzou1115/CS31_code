#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


int main(){
	int i=56, j=23;
	int *p1 = &i;
	int *p2 = &j;

	//Both print out the location in memory
	//Ex from my computer: 0x7ffedfee1988
	//The first is using the address of operator '&'
	//The second is printing the pointer to i, which stores the address
	cout << "&i: " << &i << endl;
	cout << "p1: " << p1 << endl;

	//'&' is also used to create reference variables in C++
	//references hold a memory address and can be used interchangeably with the initial variable.
	//This is like another name for variables (i.e, pass by reference functions)
	int &ri = i;
	//To change value of i to j, reference can be changed directly
	ri = j;
	//Both i and ri change to j
	cout << "i: " << i << endl;
	cout << "ri: " << ri << endl;
	//Both i and ri change back to 56
	i = 56;	
	cout << "i: " << i << endl;
	cout << "ri: " << ri << endl;

	//Cannot change which variable ri is referencing
	//if you do the following, you are really just changing the value of i to be j
	ri=j;
	cout << "ri: " << ri << endl;
	cout << "i: " << i << endl;

	ri=56;

	//pointers can be reassigned
	p1 = &j;
	cout << "*p1: " << *p1 << endl;

	//Pointers have special arithmetic operations
	const int MAXSIZE = 5;
        double da[MAXSIZE];
        double* p;
         
        for (double* p = da; p < da + MAXSIZE; p++)
		*p = 3.6;

	return 0;
}

