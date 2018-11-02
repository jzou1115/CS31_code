#include <iostream>
using namespace std;

//This function takes an array of ints (foo), the size of foo (size), and an integer k
//It returns true if a pair of number in foo equals k and false otherwise.
bool isPair(int foo[], int size, int k){
	//compair unique pairs of integers in foo
	for(int i = 0; i < size ; i++){
		for(int j = i+1; j < size ; j++){
			if(foo[i]+foo[j]==k)
				return true;
		}
	}
	return false;
}

int main(){
	int possibleNums[] = { 2, 4, 6, 8, 10};
	int size = 5;

	int testSum = 3;
	cout << isPair(possibleNums, size, testSum)<< endl;

	int testSum2 = 14;
	cout << isPair(possibleNums, size, testSum2)<< endl;
	return 0;
}
