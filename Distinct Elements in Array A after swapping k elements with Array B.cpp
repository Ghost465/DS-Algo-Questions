#include<bits/stdc++.h>
using namespace std;

int getMaximumDistinctCount(vector<int> a, vector<int> b, int k) {
    unordered_map<int, int> freqA;\
    int duplicates=0;
    for(int i=0 ; i<a.size() ; i++){
        if (freqA.find(a[i])==freqA.end()){
            freqA[a[i]]=0;
        } else{
            duplicates++;
        }
        freqA[a[i]]++;
    }
    if(duplicates==0){
        return a.size();
    }
    
    unordered_map<int, int> freqB;
    for(int i=0 ; i<b.size() && k!=0 && duplicates!=0 ; i++){
        if (freqA.find(b[i])==freqA.end()){
            freqA[b[i]]=1;
            k--;
            duplicates--;
        }
    }
    return freqA.size();
}
