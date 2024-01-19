// Given a string and a length (burst length) the objective is to remove all sequences of one repeating character that is of length greater or equal to burst length. 
// Continue doing this until the string cannot be reduced anymore. Return the most reduced string

#include <bits/stdc++.h>
using namespace std;

string reduceString(string S, int burstLength){
    string minString = S;
    for(int i=0 ; i<S.length() ; i++){
        int j=i;
        while(S[j+1]==S[i] && j<S.length()){
            j++;
        }
        if (j-i+1>=burstLength) {
            string reducedString = S.substr(0,i) + S.substr(j+1,S.length()+1);
            // cout<<reducedString<<",";
            reducedString = reduceString(reducedString, burstLength);
            if(minString.length()>reducedString.length()){
                minString = reducedString;
            }
        }
    }
    return minString;
}

int main() {
    vector<string> inputArray = {"a","b","b","b","c","c","c","c","b","b","d","d","e","e","e","e","d","d","d","k","l","t","s"};
    int burstLength=3;
    // vector<string> inputArray = {"a","b"};
    // int burstLength=1;
    string S="";
    for(int i=0 ; i<inputArray.size() ; i++){
        S += inputArray[i];
    }
    
    S = reduceString(S, burstLength);
    
    cout<<S<<endl;

    return 0;
}
