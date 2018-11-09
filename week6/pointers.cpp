#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


int main(){
	int *p1, *p2;
	
	//make p1 point to an int located on the heap
	p1=new int;

	//set the variable that p1 points to
	*p1=42;

	//Make p2 point to the same variable as p1
	p2 = p1;

	//Should both print 42
	cout << "*p1== " << *p1 << endl;
	cout << "*p2== " << *p2 << endl;

	//Set the variable that p2 points to
	*p2=53;

	//Should both print 53
	cout << "*p1== " << *p1 << endl;
        cout << "*p2== " << *p2 << endl;

	//Make p1 point to a new int located on the heap;
	p1 = new int;
	//Set the variable that p1 points to
	*p1=88;

	//p1 and p2 now point to different places in the heap
	//p1=88
	//p2=53
	cout << "*p1== " << *p1 << endl;
        cout << "*p2== " << *p2 << endl;

	return 0;
}

