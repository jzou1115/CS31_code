#include <iostream>
using namespace std;

//What does this program do?
int main(){
	int i;
	int sum = 0;
	int sum2 = 0;
	for( i=0 ; i <= 10; i++){
		//There are two ways to add a value i to a variable.  They are equivalent.
		sum += i;
		sum2 = sum2 + i;
	}
	cout << "sum=" <<sum << endl;
	cout << "sum2=" << sum2 << endl;
	return 0;
}

