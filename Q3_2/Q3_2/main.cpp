//
//  main.cpp
//  Q3_2
//
//  Created by Ruoyun Daisy Pang on 7/17/14.
//  Copyright (c) 2014 ___RUOYUNPANG___. All rights reserved.
//

#include <iostream>
#include "Stack.h"

using namespace std;

int main(int argc, const char * argv[])
{

    Stack *myStack = new Stack();
    
    myStack->Push(3);
    myStack->Push(6);
    myStack->Push(5);
    myStack->Push(2);
    myStack->Push(9);
    
    cout<<"The current minimum is: "<<myStack->MinEle()<<endl;
    
    return 0;
}

