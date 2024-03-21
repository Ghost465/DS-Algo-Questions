#include <bits/stdc++.h>
using namespace std;

int main() {
    // long num=198400873487; int k=3;
    long num=1432219; int k=3;
    // long num=10200; int k=1;
    // long num=10; int k=3;
    string numString = to_string(num);
    int length = numString.length();
    if (k>=numString.size()) {
        numString="0";
    } else {
        stack<int> S;
        for(int i=length-1 ; i>=1 ; i--) {
            if (numString[i]<numString[i-1]) {
                S.push(i);
            }
        }
        int elementsRemoved=0;
        while(!S.empty() && k>0){
            int i=S.top();
            S.pop();
            while(numString[i-elementsRemoved]<numString[i-elementsRemoved-1] && i>=1 && k>0) {
                numString = numString.substr(0,i-elementsRemoved-1) + numString.substr(i-elementsRemoved);
                elementsRemoved++;
                k--;
            }
        }
        if (k>0 && k>=numString.size()) {
            numString="0";
        } else {
            if (k>0) {
                numString = numString.substr(0, numString.length()-k);
            }
            while(numString[0]=='0' && numString.length()>1) {
                numString = numString.substr(1);
            }
        }
    }
    cout<<numString;

    return 0;
}
