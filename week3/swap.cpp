#include <iostream>
using namespace std;

//This function takes 2 integers from cin and stores them at locations input1 and input2 in memory
void getNumbers(int& input1, int& input2){
	cout << "Ender two integers: " << endl; 
	cin >> input1 >> input2;
}

//This function takes two locations in memory and swaps their values
//What happens when we don't make a temp variable and just set:
//variable1 = variable2;
//variable2 = variable1;
void swapValues(int& variable1, int& variable2){
	int temp = variable1;
	variable1 = variable2;
	variable2 = temp;
}


//Prints values of two variables
//What happens if you pass parameters by reference?
void showResults(int output1, int output2){
	cout << "In reverse order, the numbers are " << output1 << " " << output2 << endl;
}



int main ()
{
	int firstNum;
	int secondNum;

	getNumbers(firstNum, secondNum);
	swapValues(firstNum, secondNum);
	showResults(firstNum, secondNum);
	return 0;
}


