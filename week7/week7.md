# Week 7: Pointers

## Announcements
- I mispoke last week for example of printing character arrays (A note has been made in the code)
  - The point of the double for loop example was to simply to show that 2D arrays of chars can be c strings
  - However, the positions after the sentinel are undetermined values.
  - Even though the code happened to work, under certain situations, it could have unintended behavior.
- Commonly missed midterm questions
  - Second written question
    -   return -1 if illegal symbols
        - Need two for loops to deal with this because the program could return 0 (negative number of widgets) if illegal symbol is at the end of the string

    - Not considering the empty string
  
## Review

| References | Pointers|
|------------|---------|
| a memory address | something that stores a memory address|
|like another name for the variable | needs to be dereferenced to access/change the variable|
|cannot be reassigned | can be reassigned|
| No special arithmetic operations | special arithmetic operations|

- Examples in pointerReferenceDifferences.cpp
```cpp

int main(){
        int i=56, j=23;
        int *p1 = &i;
        int *p2 = &j;

        //Both print out the location in memory
        //Ex from my computer: 0x7ffedfee1988
        //The first is using the address of operator '&'
        //The second is printing the pointer to i, which stores the address
        cout << "&i: " << &i << endl;
        cout << "p1: " << p1 << endl;

        //'&' is also used to create reference variables in C++
        //references hold a memory address and can be used interchangeably with the initial variable.
        //This is like another name for variables (i.e, pass by reference functions)
        int &ri = i;
        //To change value of i to j, reference can be changed directly
        ri = j;
        //Both i and ri change to j
        cout << "i: " << i << endl;
        cout << "ri: " << ri << endl;
        //Both i and ri change back to 56
        i = 56;
        cout << "i: " << i << endl;
        cout << "ri: " << ri << endl;

        //Cannot change which variable ri is referencing
        //if you do the following, you are really just changing the value of i to be j
        ri=j;
        cout << "ri: " << ri << endl;
        cout << "i: " << i << endl;

        ri=56;

        //pointers can be reassigned
        p1 = &j;
        cout << "*p1: " << *p1 << endl;

        //Pointers have special arithmetic operations
        const int MAXSIZE = 5;
        double da[MAXSIZE];
        double* p;
                
        for (double* p = da; p < da + MAXSIZE; p++)
                *p = 3.6;
        
        return 0;
}

```

- Functions with reference argument (passRef)
```cpp
void square(int &);

int main() {
   int number = 8;
   cout <<  "In main(): " << &number << endl;

   square(number);          // Implicit referencing (without '&')
   cout << number << endl;  // 64

   int &r = number;     //Explicit referencing (with '&')
   square(r);
   cout << number << endl;  // 64

}

void square(int & rNumber) {
   cout <<  "In square(): " << &rNumber << endl;
   rNumber *= rNumber;
}
```
- Functions with pointer argument
```cpp
void square(int *);

int main() {
   int number = 8;
   cout <<  "In main(): " << &number << endl;
   cout << number << endl;
   square(&number);          // Explicit referencing to pass an address
   cout << number << endl;   // 64
}

void square(int * pNumber) {
   cout <<  "In square(): " << pNumber << endl;
   *pNumber *= *pNumber;      // Explicit de-referencing to get the value pointed-to
}
```
## Question 4
- reverse character array in place
```cpp
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
```