// leetcode
// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:

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

    bool setColorForNodes(DisjointSet* &dsjSet, vector<int> &color, int n1, int n2) {
        if (color[n1]==0 && color[n2]==0) {
            color[n1] = 1;
            color[n2] = -1;
        } else if (color[n1]!=0 && color[n2]==0) {
            color[n2] = -1 * color[n1];
        } else if (color[n1]==0 && color[n2]!=0) {
            color[n1] = -1 * color[n2];
        } else if (color[n1]*color[n2]==1) {
            if(dsjSet->doTheNodesBelongToSameDisjointSet(n1, n2)) {
                return false;
            } else{
                int j=n2;
                while(dsjSet->DS[j]!=n2) {
                    int t = j;
                    j = dsjSet->DS[j];
                    color[t]*=-1;
                }
            }
        }
        return true;
    }

    bool checkBipartiteGraph(vector<vector<int>>& graph) {
        int N = graph.size();
        DisjointSet* dsjSet = new DisjointSet(N);
        vector<int> color(N, 0);

        for(int i=0 ; i<N ; i++) {
            for(int j=0 ; j<graph[i].size() ; j++){
                if (i < graph[i][j]) {
                    if (!setColorForNodes(dsjSet, color, i, graph[i][j])) {
                        return false;
                    } else {
                        dsjSet->addConnectionBwNodes(i, graph[i][j]);
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        return checkBipartiteGraph(graph);
    }
};
