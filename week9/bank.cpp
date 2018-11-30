#include <iostream>
using namespace std;

struct account{
 	double total;
 	double withdrawLimit;
};

//Doesn't work because this is a copy of a
void add_byValue(account a, double amount){
	if(amount >=0)
		a.total += amount;
	else{
		cout << amount << " is a negative number." << endl;
	}
}

void add_byReference(account& a, double amount){
	if(amount >=0)
                a.total += amount;
        else{
                cout << amount << " is a negative number." << endl;
        }
}

void subtract_pointer(account* a, double amount){
	if(amount >= a->withdrawLimit)
		cout << amount << " is greater than the withdraw limit of " << a->withdrawLimit << endl;
	else if (amount> a->total)
		cout << "Funds exceeded."  << endl;
	else
		a->total -= amount;
	}

void printTotal(account a){
	cout << a.total<< endl;
}

int main(){
	account a1;
	a1.total = 1000;
	a1.withdrawLimit = 100;

	//Add 1000 to a1 by value
	add_byValue(a1, 1000);
	printTotal(a1);


	//Add by reference
	add_byReference(a1, 1000);
	printTotal(a1);

	//Subtract 10
	account* p1 = &a1;
	subtract_pointer(p1, 10);
	printTotal(a1);
}
