//
//  main.cpp
//  Lesson 10 - Task: Peaks
//
//  Created by Giovanni Faonte on 9/17/16.
//  Copyright © 2016 Giovanni Faonte. All rights reserved.
//
// you can use includes, for example:

// #include <algorithm>

#include <cmath>
#include <vector>
#include <deque>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> divisors(int N){
    
    vector<int> div;
    
    if(N==1){
        div.push_back(1);
    } else {
        
        int div_1, div_2;
        for(int i=floor(sqrt((double) N)); i>0; i--){
            if(N % i == 0){
                        div_1=i;
                        div_2=N/i;

                        if(div_1!=div_2){
                                            div.insert(div.begin(),div_2);
                                            div.push_back(div_1);
                        } else {
                                div.push_back(div_1);
                        }
            }
        }
    }
    return div;
}

int test(vector<int> p, int k){
    
    int pos=0;
    int t=p.size();
    int sol;
    int r=t/k;
    
    while((pos<t)&(pos!=-1)){
        
        if(p[pos+r-1]-p[pos]>0){
                                pos=pos+r;
        } else {pos=-1;}
    }
    
    if(pos==-1){
                sol=0;
    } else {sol=1;}
    
    return sol;
}

int solution(vector<int> &A) {

    int n=A.size();
    
    vector<int> peaks(n,0);
    vector<int> div=divisors(n);
    
    int m=div.size();
    int sol;
    
    if(n<=1){
            sol=0;
    } else {
        
        for(int k=1; k<(n-1); k++){
           
            if((A[k]>A[k-1])&(A[k]>A[k+1])){
                             peaks[k]=peaks[k-1]+1;
            } else {
                    peaks[k]=peaks[k-1];
            }
            
            peaks[n-1]=peaks[n-2];
        }
     
        int last_pos_T=-1;
        int last_pos_F=-1;
        int a=0;
        int b=(m-1);
        int mid= ((b-a)/2)+a;
        int pos=mid;
        int tes;
        int c_1=last_pos_F;
        int c_2=last_pos_T-1;
        
        while((c_1!=c_2)&&(last_pos_T!=0)&&(last_pos_F!=(m-1))){
         
            tes=test(peaks,div[pos]);
        
            if(tes==1){
        
                last_pos_T=pos;
                b=mid;
                mid= ((b-a)/2)+a;
                pos=mid;
        
            } else {
                last_pos_F=pos;
                a=mid;
                mid= ((b-a)/2)+a;
                if(mid==a){
    
                    mid=mid+1;
                    
                }
                pos=mid;
            }
            c_1=last_pos_F;
            c_2=last_pos_T-1;
        }
        sol=div[last_pos_T];
        
    }
    
    return sol;
    
}
        




