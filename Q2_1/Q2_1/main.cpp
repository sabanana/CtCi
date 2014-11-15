//
//  main.cpp
//  Q2_1
//
//  Created by Ruoyun Daisy Pang on 7/3/14.
//  Copyright (c) 2014 ___RUOYUNPANG___. All rights reserved.
//

#include <iostream>
#include "LinkedListClass.h"

using namespace std;


void RemoveDuplicates(Node *head)
{
    if (head == NULL) return;
    
    else
    {
        Node *current = head;
        Node *runner = head;
        while (current != NULL) {
            runner = current;
            while (runner->next != NULL) {
                if (runner->next->data==current->data) {
                    Node *temp = runner->next;
                    runner->next = runner->next->next;
                    delete temp;
                }
                else
                {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }
}



int main(int argc, const char * argv[])
{
    LinkedList *myList = new LinkedList();
    
    myList->Insert(5);
    myList->Insert(7);
    myList->Insert(12);
    myList->Insert(7);
    myList->Insert(16);
    myList->Insert(16);
    myList->Insert(25);
    myList->Insert(11);
    myList->Insert(5);
    
    cout<<"The LinkedList is: "<<endl;
    myList->PrintOut();
    cout<<endl<<"Remove duplicates and the LinkedList is: "<<endl;
    RemoveDuplicates(myList->head);
    myList->PrintOut();
    
    delete myList;
    
    return 0;
}

