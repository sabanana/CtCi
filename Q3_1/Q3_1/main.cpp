//
//  main.cpp
//  Q3_1
//
//  Created by Ruoyun Daisy Pang on 7/11/14.
//  Copyright (c) 2014 ___RUOYUNPANG___. All rights reserved.
//

#include <iostream>
#define MAX_STACK 100
#define STACK_NUM 3

using namespace std;

class SingleArray3Stacks{
public:
    SingleArray3Stacks();
    void Push(int value, int StackNum);
    int Pop(int StackNum);
    bool isEmpty(int StackNum);
    int Peek(int StackNum);
    
private:
    int A[MAX_STACK*STACK_NUM];
    int pointers[STACK_NUM];
    int CalTop(int StackNum);
};

SingleArray3Stacks::SingleArray3Stacks()
{
    for (int i=0; i<MAX_STACK*STACK_NUM; i++) {
        this->A[i] = NULL;
    }
    this->pointers[0] = -1;
    this->pointers[1] = -1;
    this->pointers[2] = -1;
}

int SingleArray3Stacks::CalTop(int StackNum)
{
    return MAX_STACK*StackNum+pointers[StackNum];
}

void SingleArray3Stacks::Push(int value, int StackNum)
{
    if (pointers[StackNum]+1>=MAX_STACK) {
        cout<<"The Stack is FULL !!!"<<endl;
        return ;
    }
    
    pointers[StackNum]++;
    A[CalTop(StackNum)] = value;
}

int SingleArray3Stacks::Pop(int StackNum)
{
    if (pointers[StackNum]<0) {
        cout<<"This Stack is already EMPTY !!!"<<endl;
        return NULL;
    }
    
    int output = A[CalTop(StackNum)];
    A[CalTop(StackNum)]=NULL;
    pointers[StackNum]--;
    
    return output;
}

int SingleArray3Stacks::Peek(int StackNum)
{
    if (pointers[StackNum]<0) {
        cout<<"Empty Stack !!!"<<endl;
        return NULL;
    }
    
    return A[CalTop(StackNum)];
}

bool SingleArray3Stacks::isEmpty(int StackNum)
{
    if (pointers[StackNum]) {
        return true;
    }
    return false;
}



int main(int argc, const char * argv[])
{

    SingleArray3Stacks *myStack = new SingleArray3Stacks();
   
    myStack->Push(11, 1);
    myStack->Push(13, 0);
    myStack->Push(7, 2);
    
    cout<<myStack->Peek(1)<<endl;
    cout<<myStack->Pop(0)<<endl;
    myStack->Push(6, 0);
    myStack->Push(21, 0);
    
    cout<<endl<<myStack->Pop(0)<<endl;
    cout<<myStack->Peek(0)<<endl;
    
    return 0;
}

