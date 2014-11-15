//
//  main.cpp
//  Q1_6
//
//  Created by Ruoyun Daisy Pang on 6/27/14.
//  Copyright (c) 2014 ___RUOYUNPANG___. All rights reserved.
//

#include <iostream>
#define MAX_SIZE 1000

using namespace std;

struct Img
{
    float mat[MAX_SIZE];
    int N;
};

void Rotate90(struct Img* M)
{
    int layer = M->N/2;
    for (int i=0; i<layer; i++)
    {
        int n_layer = M->N-2*i;
        int steps = n_layer-1;
        for (int k=0; k<steps; k++)
        {
            int Origin = i*M->N+i;
            int left = Origin+k*M->N;
            int up = Origin+n_layer-1-k;
            int right = Origin+(n_layer-1-k)*M->N+n_layer-1;
            int down = Origin+(n_layer-1)*M->N+k;
            float temp = M->mat[left];
            
            M->mat[left] = M->mat[up];
            M->mat[up] = M->mat[right];
            M->mat[right] = M->mat[down];
            M->mat[down] = temp;
        }
    }
}


void Print_Img(struct Img* M)
{
    for (int r=0; r<M->N; r++)
    {
        for (int c=0; c<M->N; c++) {
            cout<<M->mat[M->N*r+c]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[])
{

    struct Img M;
    M.N = 5;
    for (int i=0; i<M.N*M.N; i++)
    {
        M.mat[i] = i;
    }
    
    cout<<"The Matrix is: "<<endl;
    Print_Img(&M);
    cout<<endl<<"Rotate the matrix by 90 degree: "<<endl;
    Rotate90(&M);
    Print_Img(&M);
    
    return 0;
}

