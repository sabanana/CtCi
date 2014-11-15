//
//  main.cpp
//  Q1_7
//
//  Created by Ruoyun Daisy Pang on 7/2/14.
//  Copyright (c) 2014 ___RUOYUNPANG___. All rights reserved.
//

#include <iostream>
#define MaxSize 100

using namespace std;

void SetZeros(int *matrix, int m, int n){
    // Assuming M,N <= 100
    
    int Mark_row[MaxSize] = {0,0,0};
    int Mark_col[MaxSize] = {0,0,0};
    
    for (int r=0; r<m; r++){
        for (int c=0; c<n; c++){
            if (matrix[r*n+c]==0){
                Mark_row[r]=1;
                Mark_col[c]=1;
            }
        }
    }
    
    for (int r=0; r<m; r++) {
        for (int c=0; c<n; c++) {
            if (Mark_row[r]==1 || Mark_col[c]==1){
                matrix[r*n+c]=0;
            }
        }
    }
}


void PrintMatrix(int *matrix, int m, int n){
    for (int r=0; r<m; r++) {
        for (int c=0; c<n; c++) {
            cout<<matrix[r*n+c]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[])
{

    int matrix[4][5] = {{1,6,7,5,4},
                        {8,3,0,2,9},
                        {0,1,4,5,7},
                        {2,0,1,3,1}};
    
    int *p_matrix = (int*)matrix;
    
    cout<<"The matrix is: "<<endl;
    PrintMatrix(p_matrix,4,5);
    cout<<endl<<"Set zeros and the matrix is: "<<endl;
    SetZeros(p_matrix, 4, 5);
    PrintMatrix(p_matrix,4,5);
    
    return 0;
}

