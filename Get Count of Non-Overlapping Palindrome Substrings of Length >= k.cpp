
// Given string get max count of non-overlapping palindrome substrings of length >= k

// Ex. aababaabce

// splitting like this - a ababa abce - gives you only 1 palindrome substrings
// whereas like this -   a aba bab ce - gives you 2 palindrome substrings

// So output 2


#include<bits/stdc++.h>
using namespace std;

int getPalindromeSubstringCount(vector<vector<bool>> &P, int start, int N, int k){
    int maxCount=0;
    for(int i=start ; i<N ; i++){
        if ((i-start+1)>=k){
            for(int j=start ; j<=i && (i-j+1)>=k ; j++){
                if(P[j][i]){
                    maxCount = max(maxCount, 1 + getPalindromeSubstringCount(P, i+1, N, k));
                }
            }
        }
    }
    return maxCount;
}

// .
// 1100001000
// 0101010000
// 0010100000
// 0001010000
// 0000100100
// 0000011000
// 0000001000
// 0000000100
// 0000000010
// 0000000001

int getMaxSubstrings(string s, int k) {
    int N = s.length();
    vector<vector<bool>> P(N, vector<bool>(N,false));
    for(int i=0 ; i<N ; i++){
        P[i][i]=true;
    }
    for(int i=1 ; i<N ; i++){
        if (s[i-1]==s[i]){
            P[i-1][i] = true;
        }
    }
    for(int L=3 ; L<=N ; L++){
        for(int i=L-1 ; i<N ; i++){
            if (s[i-L+1]==s[i] && P[i-L+2][i-1]){
                P[i-L+1][i]=true;
            }
        }
    }
    return getPalindromeSubstringCount(P, 0, N, k);
}
