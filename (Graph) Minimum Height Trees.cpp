// Leetcode question
// https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:

    struct GraphNode{
        int val;
        set<GraphNode*> next;
        GraphNode(int val) : val(val), next(set<GraphNode*>()) {}
    };

    vector<int> getFinalNodes(set<GraphNode*> &nodesToRemove){
        set<GraphNode*> newlyFormedLeafNodes;
        for(auto IT=nodesToRemove.begin() ; IT!=nodesToRemove.end() ; IT++){
            GraphNode* currNode = (*IT);
            if (currNode->next.size()>0) {
                GraphNode* connectedNode = *currNode->next.begin();
                connectedNode->next.erase(currNode);
                if(isGraphNodeALeafNode(connectedNode) && nodesToRemove.find(connectedNode)==nodesToRemove.end()){
                    newlyFormedLeafNodes.insert(connectedNode);
                }
            }
        }
        if (newlyFormedLeafNodes.empty()){
            vector<int> RES;
            for(auto IT1=nodesToRemove.begin() ; IT1!=nodesToRemove.end() ; IT1++){
                RES.push_back((*IT1)->val);
            }
            return RES;
        }
        return getFinalNodes(newlyFormedLeafNodes);
    }

    bool isGraphNodeALeafNode(GraphNode* &graphNode){
        return isGraphNodeHasLessThanOrEqualToOneConnection(graphNode);
    }

    bool isGraphNodeHasLessThanOrEqualToOneConnection(GraphNode* &graphNode){
        return graphNode->next.size()<=1;
    }

    void addGraphNodeToLeafNodeList(GraphNode* &graphNode, set<GraphNode*> &leafNodeList) {
        leafNodeList.insert(graphNode);
    }

    set<GraphNode*> getLeafNodesFromList(vector<GraphNode*> graph){
        set<GraphNode*> leafNodeList;
        for(int i=0 ; i<graph.size() ; i++){
            if(isGraphNodeALeafNode(graph[i])){
                addGraphNodeToLeafNodeList(graph[i], leafNodeList);
            }
        }
        return leafNodeList;
    }

    vector<GraphNode*> constructGraph(int n, vector<vector<int>>& edges){
        vector<GraphNode*> graph(n);
        for(int i=0 ; i<n ; i++){
            graph[i] = new GraphNode(i);
        }
        for(int i=0 ; i<edges.size() ; i++){
            int x = edges[i][0], y = edges[i][1];
            graph[x]->next.insert(graph[y]);
            graph[y]->next.insert(graph[x]);
        }
        return graph;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<GraphNode*> graph = constructGraph(n, edges);
        set<GraphNode*> leafNodeList = getLeafNodesFromList(graph);
        return getFinalNodes(leafNodeList);
    }

    // vector<int> getFinalNodes(vector<set<int>> &graph, set<int> &nodesToRemove){
    //     set<int> newlyFormedLeafNodes;
    //     for(auto IT=nodesToRemove.begin() ; IT!=nodesToRemove.end() ; IT++){
    //         int currGraphNode = *IT;
    //         if(graph[currGraphNode].size()>0) {
    //             int connectedNode = *(graph[currGraphNode].begin());
    //             if (nodesToRemove.find(connectedNode)==nodesToRemove.end()) {
    //                 graph[currGraphNode].erase(connectedNode);
    //                 graph[connectedNode].erase(currGraphNode);
    //                 if (isGraphNodeALeafNode(graph[connectedNode])) {
    //                     newlyFormedLeafNodes.insert(connectedNode);
    //                 }
    //             }
    //         }
    //     }
    //     if (newlyFormedLeafNodes.empty()){
    //         vector<int> RES;
    //         for(auto IT1=nodesToRemove.begin() ; IT1!=nodesToRemove.end() ; IT1++){
    //             RES.push_back(*IT1);
    //         }
    //         return RES;
    //     }
    //     return getFinalNodes(graph, newlyFormedLeafNodes);
    // }

    // bool isGraphNodeHasLessThanOrEqualToOneConnection(set<int> connectedNodes){
    //     return connectedNodes.size()<=1;
    // }

    // bool isGraphNodeALeafNode(set<int> connectedNodes){
    //     return isGraphNodeHasLessThanOrEqualToOneConnection(connectedNodes);
    // }

    // void addGraphNodeToLeafNodeList(int graphNode, set<int> &leafNodes) {
    //     leafNodes.insert(graphNode);
    // }

    // set<int> getLeafNodesFromList(vector<set<int>> &graph){
    //     set<int> leafNodes;
    //     for(int i=0 ; i<graph.size() ; i++){
    //         if(isGraphNodeALeafNode(graph[i])){
    //             addGraphNodeToLeafNodeList(i, leafNodes);
    //         }
    //     }
    //     return leafNodes;
    // }

    // vector<set<int>> constructGraph(int n, vector<vector<int>>& edges){
    //     vector<set<int>> graph(n, set<int>());
    //     for(int i=0 ; i<edges.size() ; i++){
    //         int x = edges[i][0], y = edges[i][1];
    //         graph[x].insert(y);
    //         graph[y].insert(x);
    //     }
    //     return graph;
    // }

    // vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    //     vector<set<int>> graph = constructGraph(n, edges);
    //     set<int> leafNodes = getLeafNodesFromList(graph);
    //     return getFinalNodes(graph, leafNodes);
    // }
};
