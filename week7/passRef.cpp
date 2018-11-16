#include <iostream>
using namespace std;
 
void square(int &);
 
int main() {
   int number = 8;
   cout <<  "In main(): " << &number << endl;  
   
   square(number);          // Implicit referencing (without '&')
   cout << number << endl;  // 64

   int &r = number;	//Explicit referencing (with '&')
   square(r);          
   cout << number << endl;  // 64

}
 
void square(int & rNumber) {  
   cout <<  "In square(): " << &rNumber << endl; 
   rNumber *= rNumber;       
}
