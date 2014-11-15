//
//  main.cpp
//  Q1_2
//
//  Created by Ruoyun Daisy Pang on 6/13/14.
//  Copyright (c) 2014 ___RUOYUNPANG___. All rights reserved.
//


#include <iostream>

using namespace std;

void Reverse(char *str)
{
    char *Bstr = str;
    char temp;
    while (*str) {
        str++;
    }
    str--;
    while (str>Bstr) {
        temp = *str;
        *str = *Bstr;
        *Bstr = temp;
        str--;
        Bstr++;
    }
}

int main()
{
    char test_str[][30] = {"brilliant", "Ruoyun", "miffy"};
    for (int i = 0; i<3; i++) {
        cout<<"Test String: "<<test_str[i]<<endl;
        Reverse(test_str[i]);
        cout<<"Reverse of Test String :"<<test_str[i]<<endl;
    }
    
    return 0;
}


