// Leetcode question
// https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:

    struct GraphNode{
        int val;
        unordered_map<int,GraphNode*> next;
        GraphNode(int val) : val(val), next(unordered_map<int,GraphNode*>()) {}
    };

    unordered_set<int> getSetFromQueue(queue<GraphNode*> &Q){
        unordered_set<int> S;
        int size = Q.size();
        while(size--){
            GraphNode* y = Q.front();
            Q.pop();
            S.insert(y->val);
            Q.push(y);
        }
        return S;
    }

    vector<int> getFinalNodes(queue<GraphNode*> &Q){
        unordered_set<int> S = getSetFromQueue(Q);
        int size=Q.size();
        while(size--){
            GraphNode* y = Q.front();
            Q.pop();
            for(auto IT=y->next.begin() ; IT!=y->next.end() ; IT++){
                GraphNode* connectedNode = IT->second;
                connectedNode->next.erase(y->val);
                if(connectedNode->next.size()<=1 && S.find(connectedNode->val)==S.end()){
                    Q.push(connectedNode);
                }
            }
        }
        if (Q.empty()){
            vector<int> RES;
            for(auto IT=S.begin() ; IT!=S.end() ; IT++){
                RES.push_back(*IT);
            }
            return RES;
        }
        return getFinalNodes(Q);
    }

    queue<GraphNode*> getLeafNodesFromList(vector<GraphNode*> graph){
        queue<GraphNode*> Q;
        for(int i=0 ; i<graph.size() ; i++){
            if(graph[i]->next.size()<=1){
                Q.push(graph[i]);
            }
        }
        return Q;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<GraphNode*> graph(n);
        for(int i=0 ; i<n ; i++){
            graph[i] = new GraphNode(i);
        }
        for(int i=0 ; i<edges.size() ; i++){
            int x = edges[i][0], y = edges[i][1];
            graph[x]->next[y]=graph[y];
            graph[y]->next[x]=graph[x];
        }
        queue<GraphNode*> Q = getLeafNodesFromList(graph);
        return getFinalNodes(Q);
    }
};
