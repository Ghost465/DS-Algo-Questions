#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    DisjointSet(int N){
        this->N = N;
        DS = vector<int>(N);
        for(int i=0 ; i<N  ; i++){
            DS[i]=i;
        }
    }
    int N; //capacity
    vector<int> DS;

    void printDS(){
        for(int i=0 ; i<N ; i++){
            cout<<DS[i]<<" ";
        }
        cout<<endl;
    }

    bool doTheNodesBelongToSameDisjointSet(int n1, int n2){
        int i=DS[n1];
        while(i!=n1){
            if(i==n2){
                return true;
            }
            i=DS[i];
        }
        return false;
    }

    void addConnectionBwNodes(int n1, int n2){
        if (!doTheNodesBelongToSameDisjointSet(n1,n2)) {
            swap(DS[n1],DS[n2]);
        }
        // printDS();
    }
    
    int countNumberOfSets(){
        int count=0;
        for(int i=0 ; i<N ; i++){
            if (DS[i]!=-1){
                int j=i;
                while(DS[j]!=-1){
                    int t = j;
                    j = DS[j];
                    DS[t] = -1;
                }
                count++;
            }
        }
        return count;
    }
};

int main() {
    DisjointSet* disjS = new DisjointSet(6);
    disjS->addConnectionBwNodes(0,1);
    disjS->addConnectionBwNodes(0,2);
    disjS->addConnectionBwNodes(0,3);
    disjS->addConnectionBwNodes(4,5);
    cout<<disjS->countNumberOfSets()<<endl;

    return 0;
}
