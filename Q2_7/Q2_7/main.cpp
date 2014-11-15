//
//  main.cpp
//  Q2_7
//
//  Created by Ruoyun Daisy Pang on 7/11/14.
//  Copyright (c) 2014 ___RUOYUNPANG___. All rights reserved.
//

#include <iostream>
#include "LinkedListClass.h"

using namespace std;

Node * ReverseLinkedList(Node *head)
{
    Node *temp = head->next;
    Node *left = NULL;
    Node *right = head;
    
    while (temp != NULL) {
        right->next = left;
        left = right;
        right = temp;
        temp = temp->next;
    }
    right->next = left;
    
    return right;
}


bool isPalindrome(Node *head)
{
    int len = 0;
    LinkedList *revList = new LinkedList();
    Node *temp = head;
    
    while (temp != NULL) {
        revList->Insert(temp->data);
        temp = temp->next;
        len++;
    }
    
    revList->head = ReverseLinkedList(revList->head);
    revList->PrintOut();
    temp = head;
    Node *temp_r = revList->head;
    int k = 0;
    
    while (k<=len/2) {
        if (temp_r->data != temp->data) {
            return false;
        }
        temp_r = temp_r->next;
        temp = temp->next;
        k++;
    }
    
    return true;
}



int main(int argc, const char * argv[])
{

    LinkedList *myList = new LinkedList();
    
    myList->Insert(1);
    myList->Insert(2);
    myList->Insert(4);
    myList->Insert(5);
    myList->Insert(4);
    myList->Insert(3);
    myList->Insert(1);
    
    cout<<"The LinkedList is: "<<endl;
    myList->PrintOut();
    cout<<endl;
    if (isPalindrome(myList->head)==true) {
        cout<<"This is a Palindrome.";
    }
    else
    {
        cout<<"This is NOT a Palindrome.";
    }
    
    return 0;
}

