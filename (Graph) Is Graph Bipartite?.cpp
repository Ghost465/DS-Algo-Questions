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

// THIS IS A BETTER SOLUTION
// I'm a fool... I need not check for graph bipartitism as I'm constructing the graph. I can first construct the graph, and then start assigning colors by graph traversal.
// The solution is meant to consider graph as a disconnected graph.
// If the problem assumed the graph to be a connected graph, I can go ahead and remove the outer for loop.


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int> colorCode(N,-1); // 0->color1 ; 1->color2 ; -1->unvisited
        for(int n=0 ; n<N ; n++) {
            if (colorCode[n]==-1) {
                queue<int> Q;
                Q.push(n);
                colorCode[n]=0;
                while(!Q.empty()) {
                    int node = Q.front();
                    Q.pop();
                    for(int i=0 ; i<graph[node].size() ; i++) {
                        if (colorCode[graph[node][i]]==-1) {
                            Q.push(graph[node][i]);
                            colorCode[graph[node][i]]=1-colorCode[node];
                        } else if(colorCode[node] + colorCode[graph[node][i]]!=1) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
