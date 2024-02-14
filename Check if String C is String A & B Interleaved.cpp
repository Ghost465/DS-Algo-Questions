#include <bits/stdc++.h>
using namespace std;

int main() {
    string A="aabcc";
    string B="dbbca";
    string C="aadbbcbcad";
    int N = A.length();
    int M = B.length();
    vector<vector<bool>> DP(N+1, vector<bool>(M+1, false));
    DP[0][0]=true;
    for(int i=1 ; i<N+1 ; i++){
        if (A[i-1]!=C[i-1]){
            break;
        }
        DP[i][0]=true;
    }
    for(int j=1 ; j<M+1 ; j++){
        if (B[j-1]!=C[j-1]){
            break;
        }
        DP[0][j]=true;
    }
    for(int i=1 ; i<N+1 ; i++){
        for(int j=1 ; j<M+1 ; j++){
            int L = i+j;
            DP[i][j]=(DP[i-1][j]&&(A[i-1]==C[L-1]) || DP[i][j-1]&&(B[j-1]==C[L-1]));
        }
    }
    for(int i=0 ; i<N+1 ; i++){
        for(int j=0 ; j<M+1 ; j++){
            cout<<(DP[i][j]?1:0)<<" ";
        }
        cout<<endl;
    }
    cout<<DP[N][M]<<endl;

    return 0;
}
