#include <iostream>
using namespace std;

void reverse(char *arr){
	char *first = arr;
	char *second = arr;
	//Initialize a pointer to point to the last char before '\0'
	while (*second != '\0')
		second ++;
	second --;

	while (second > first){
		int temp = *first;
		*first = *second;
		*second = temp;
		second--;
		first++;
	}
}

int main(){
	char arr[7] = "kayak!";
	reverse(arr);
	int i=0; 

	while (arr[i]!= '\0'){
		cout << arr[i];
		i++;
	}

	cout << endl;
}
