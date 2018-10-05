//
//  main.cpp
//  integers
//
//  Created by Jennifer Zou on 10/1/18.
//  Copyright © 2018 ucla. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    //Declaring an variable of type int means that there are no decimals.
    int myFirstInt;
    
    //You can also declare multiple variables at once.
    int mySecondInt, myThirdInt, myFourthInt, myFifthInt;
    
    //Assign values to variables using =
    myFirstInt=10;
    mySecondInt=5;
    
    //Adding and multiplying work as expected.
    myThirdInt = myFirstInt + mySecondInt;
    cout << "myFirstInt + mySecondInt= " << myThirdInt << endl;
    
    myFourthInt = myFirstInt * mySecondInt;
    cout << "myFirstInt * mySecondInt= " << myFourthInt << endl;
    
    //Integer division does not have decimals.
    //Does not round, chops off decimal.
    myFifthInt = mySecondInt / myFirstInt;
    cout << "mySecondInt / myFirstInt = " << myFifthInt << endl;
    
    return 0;
}