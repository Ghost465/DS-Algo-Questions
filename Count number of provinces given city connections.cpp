/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

class Solution {
public:

    bool doTheIndexesBelongToSameDisjointSet(int i, int j, vector<int> &DS){
        int ii=DS[i];
        while(ii!=i){
            if(ii==j){
                return true;
            }
            ii=DS[ii];
        }
        return false;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<int> DS(N); // disjoint set
        for(int i=0 ; i<N  ; i++){
            DS[i]=i;
        }
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<i ; j++){
                if (isConnected[i][j] && !doTheIndexesBelongToSameDisjointSet(i,j,DS)){
                    swap(DS[i],DS[j]);
                }
            }
        }
        int provinceCount=0;
        for(int i=0 ; i<N ; i++){
            if (DS[i]!=-1){
                int j=i;
                while(DS[j]!=-1){
                    int t = j;
                    j = DS[j];
                    DS[t] = -1;
                }
                provinceCount++;
            }
        }
        return provinceCount;
    }
};
