//
//  main.cpp
//  io
//
//  Created by Jennifer Zou on 10/1/18.
//  Copyright © 2018 ucla. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    
    //Ask for favorite number input
    cout << "What is your favorite number?" << endl;
    float num;
    cin >> num;
    
    //Return 2*num
    float num2 = num *2;
    cout << "My favorite number is twice yours.  It is " << num2 << endl;
    
    return 0;
}
