/*
Given a string S, calculate the total number of distinct aibjck subsequences in the string such that i>=1, j>=1, k>=1

Ex. abbbacaabcc; Output: 17
    abbbac ; Output: 3
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    string S="abbbacaabcc";
    int N=S.length();
    vector<int> DP(N, 0);
    int countA=0;
    int countB=0;
    int countC=0;
    for(int i=0 ; i<N ; i++) {
        if(S[i]=='a') {
            countA++;
        } else if (S[i]=='b') {
            countB=countB + countA;
        } else if (S[i]=='c') {
            countC=countC + countB;
        }
    }
    cout<<countC;
    
    return 0;
}
