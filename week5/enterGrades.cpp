#include <iostream>
using namespace std;

void fillUp(char a[], int size){
	cout << "Enter a grade: " << endl;
	for(int i=0; i < size; i ++){
		cin >> a[i];
	}

	return;
}

int main(){

	char grades[3];
	char g1; //temporary variable to store input

	//Ask for 3 grades and store them in the grades array
	for(int i =0; i<3; i++){
		cout << "Enter a grade: " << endl;
		cin >> g1;
		grades[i] = g1;
	}
	cout << "The grades are " << grades << endl;

	//Store 3 grades in grades_alt using the fillUp function
	char grades_alt[3];
	fillUp(grades_alt, 3);

	//Print the grades in grades_alt
	cout << "The new grades are ";
	for(int i=0; i<3; i++){
		cout << grades_alt[i];
	}
	cout << endl;
	return 0;
}
