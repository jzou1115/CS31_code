#include <iostream>
#include <string>

using namespace std;

int main(){
	string myName="Jennifer";
	string yourName;

	cout << "What is your name?" << endl;

	getline(cin, yourName);

	if (myName==yourName){
		cout << "We have the same name!" << endl;
	} else{
		cout << "My name is Jennifer." << endl;
	}

	return 0;
}
