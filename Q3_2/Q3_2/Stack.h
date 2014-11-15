//
//  Stack.h
//  Q3_2
//
//  Created by Ruoyun Daisy Pang on 7/17/14.
//  Copyright (c) 2014 ___RUOYUNPANG___. All rights reserved.
//

#ifndef Q3_2_Stack_h
#define Q3_2_Stack_h

#define BIGNUM 10e+5
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack{
public:
    Stack();
    ~Stack();
    void Push(int value);
    int Pop();
    bool isEmpty();
    int Peek();
    int MinEle();
    
private:
    Node *top;
    int min;
};


Stack::Stack()
{
    this->top = NULL;
    this->min = BIGNUM;
}

Stack::~Stack()
{
    Node *temp = top;
    while(temp != NULL)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
    top = NULL;
    cout<<"Successfully delete the Stack from memory!"<<endl;
}

void Stack::Push(int value)
{
    Node *temp = new Node();
    temp->data = value;
    if (top == NULL) {
        top = temp;
        top->next = NULL;
        min = top->data;
    }
    else
    {
        temp->next = top;
        top = temp;
        if (top->data<min) {
            min = top->data;
        }
    }
}

int Stack::Pop()
{
    if (top == NULL)
    {
        cout<<"The Stack is EMPTY !!!"<<endl;
        return NULL;
    }
    
    Node *temp = top;
    top = top->next;
    return temp->data;
}

bool Stack::isEmpty()
{
    if (top == NULL) {
        return true;
    }
    return false;
}

int Stack::Peek()
{
    if (top == NULL) {
        cout<<"EMPTY !!!"<<endl;
        return NULL;
    }
    return top->data;
}

int Stack::MinEle()
{
    if (top == NULL) {
        cout<<"EMPTY !!!"<<endl;
        return NULL;
    }
    return min;
}


#endif
