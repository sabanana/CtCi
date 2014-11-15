//
//  main.cpp
//  Q2_4
//
//  Created by Ruoyun Daisy Pang on 7/7/14.
//  Copyright (c) 2014 ___RUOYUNPANG___. All rights reserved.
//

#include <iostream>
#include "LinkedListClass.h"

using namespace std;


void PartitionAroundX(Node *head, int x)
{
    if (head==NULL || head->next==NULL) {
        return ;
    }
    else
    {
        int FakeHead = 0;
        if (head->data >= x) {
            Node *temp = head;
            head = new Node();
            head->data = x-1;
            head->next = temp;
            FakeHead = 1;
        }
        
        Node *Mark = head;
        while (Mark->next != NULL) {
            if (Mark->next->data >= x) {
                Node *runner = Mark->next;
                while (runner->next != NULL) {
                    if (runner->next->data<x) {
                        Node *temp = Mark->next;
                        Mark->next = new Node();
                        Mark->next->data = runner->next->data;
                        Mark->next->next = temp;
                        Mark = Mark->next;
                        temp = runner->next;
                        runner->next = temp->next;
                        delete temp;
                    }
                    else
                    {
                        runner = runner->next;
                    }
                }
                if (FakeHead == 1) {
                    Node *temp = head;
                    head = temp->next;
                    delete temp;
                }
                LinkedList *tmpList = new LinkedList();
                tmpList->head = head;
                cout<<endl<<"tempList: "<<endl;
                tmpList->PrintOut();
                cout<<"Inside. head: "<<head<<endl;
                return ;
            }
            else
            {
                Mark = Mark->next;
            }
        }
        if (FakeHead == 1) {
            head = head->next;
        }
        return ;
    }
}



int main(int argc, const char * argv[])
{

    LinkedList *myList = new LinkedList();
    
    myList->Insert(8);
    myList->Insert(3);
    myList->Insert(4);
    myList->Insert(5);
    myList->Insert(7);
    myList->Insert(6);
    myList->Insert(3);
    myList->Insert(1);
    myList->Insert(2);
    myList->Insert(5);
    myList->Insert(9);
    myList->Insert(8);
    
    cout<<"The LinkedList is: "<<endl;
    myList->PrintOut();
    cout<<endl<<"Partition the LinkedList around x=5 and the LinkedList is: "<<endl;
    PartitionAroundX(myList->head, 5);
    myList->PrintOut();
    cout<<"myList->head: "<<myList->head<<endl;
    
    return 0;
}

