#include <iostream>
using namespace std;

//Input: a list of ints (foo), the size of foo (size), and a number to compare with foo (n)
//Output: True if the list of ints in foo match the digits of n.  False otherwise
bool equality(int foo[], int size, int n){
	//compare each digit of array with digits of n, starting from the end
	for(int i = size -1; i>=0; i--){
		if(foo[i]!= (n%10) || (n<=0))
			return false;
		//remove last digit from n
		n /= 10;
	}

	if (n==0)
		return true; //All digits match and no extra digits 
	else
		return false;
}


int main(){
	int testCase[5] = {1,2,3,4,5};
	int n1 = 12345;

	bool e1 = equality(testCase, 5, n1);

	if (e1){
		cout << n1 << " matches" << endl;
	} else{
		cout << n1 << " doesn't match" << endl;
	}

	int n2 = 23456;
	bool e2 = equality(testCase, 5, n2);

	
	if (e2){
		cout << n2 << " matches " << endl;
	} else{
		cout << n2 << " doesn't match " << endl;
	}
	return 0;
}
