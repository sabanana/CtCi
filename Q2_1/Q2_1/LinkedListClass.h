//
//  LinkedListClass.h
//  Q2_1
//
//  Created by Ruoyun Daisy Pang on 7/3/14.
//  Copyright (c) 2014 ___RUOYUNPANG___. All rights reserved.
//

#ifndef _LinkedListClass_h
#define _LinkedListClass_h

#include <iostream>

using namespace std;


struct Node
{
    int data;
    Node *next;
};


class LinkedList
{
public:
    Node *head;
    LinkedList();
    ~LinkedList();
    void PrintOut();
    void Insert(int value);
    void CreateCycle();
    
private:
    Node *tail;
};


LinkedList::LinkedList()
{
    this->head = NULL;
}


LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    
    head = NULL;
    cout<<"LinkedList deleted !!!"<<endl;
}


void LinkedList::Insert(int value)
{
    if (head == NULL) {
        head = new Node();
        head->next = NULL;
        head->data = value;
        tail = head;
    }
    
    else
    {
        tail->next = new Node();
        tail = tail->next;
        tail->data = value;
        tail->next = NULL;
    }
}


void LinkedList::PrintOut()
{
    Node *temp = head;
    if (head == NULL) {
        cout<<"The LinkedList is empty!!!"<<endl;
        return;
    }
    
    else
    {
        while (temp != NULL) {
            cout<<temp->data<<" - ";
            temp = temp->next;
        }
        cout<<endl;
    }
}


void LinkedList::CreateCycle()
{
    tail->next = head;
}



#endif
