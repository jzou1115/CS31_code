//
//  main.cpp
//  doubles
//
//  Created by Jennifer Zou on 10/1/18.
//  Copyright © 2018 ucla. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    //Delaring some variables of type double
    double myFirst=5.5;
    double mySecond=10.2;
    double myThird, myFourth, myFifth, mySixth;
    
    //Adding, subtracting multiplying, and dividing work like a calculator.
    myThird = myFirst + mySecond;
    cout << "myFirst + mySecond = " << myThird << endl;
    
    myFourth = myFirst - mySecond;
    cout << "myFirst - mySecond = " << myFourth << endl;
    
    myFifth = myFirst * mySecond;
    cout << "myFirst * mySecond = " << myFifth << endl;
    
    mySixth = myFirst / mySecond;
    cout << "myFirst / mySecond = " << mySixth << endl;
    
    //Implicit assignment: assign type of int to double
    int myInt = 6;
    myFirst = myInt;
    cout << "myFirst = myInt = " << myFirst << endl;
    
    //Implicit assignment: assign type of double to int
    //decimal chopped off
    //Usually not recommended.  Some compilers treat differently.
    myInt = mySecond;
    cout << "myInt's new value is: " << myInt << endl;
    
    return 0;
}
