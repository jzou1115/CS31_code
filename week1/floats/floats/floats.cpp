//
//  main.cpp
//  floats
//
//  Created by Jennifer Zou on 10/1/18.
//  Copyright © 2018 ucla. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    //Delaring some variables of type float
    float myFirstFloat=5.5;
    float mySecondFloat=10.2;
    float myThirdFloat, myFourthFloat, myFifthFloat, mySixthFloat;
    
    //Adding, subtracting multiplying, and dividing work like a calculator.
    myThirdFloat = myFirstFloat + mySecondFloat;
    cout << "myFirstFloat + mySecondFloat = " << myThirdFloat << endl;
    
    myFourthFloat = myFirstFloat - mySecondFloat;
    cout << "myFirstFloat - mySecondFloat = " << myFourthFloat << endl;
    
    myFifthFloat = myFirstFloat * mySecondFloat;
    cout << "myFirstFloat * mySecondFloat = " << myFifthFloat << endl;
    
    mySixthFloat = myFirstFloat / mySecondFloat;
    cout << "myFirstFloat / mySecondFloat = " << mySixthFloat << endl;
    
    //Implicit assignment: assign type of int to float
    int myInt = 6;
    myFirstFloat = myInt;
    cout << "myFirstFloat = myInt = " << myFirstFloat << endl;
    
    //Implicit assignment: assign type of float to int
    //decimal chopped off
    //Usually not recommended.  Some compilers treat differently.
    myInt = mySecondFloat;
    cout << "myInt's new value is: " << myInt << endl;
    
    return 0;
}
