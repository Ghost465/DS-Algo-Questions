/*
https://www.geeksforgeeks.org/diameter-of-a-binary-tree/
*/

#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void addBinaryTreeEdge(vector<BinaryTreeNode*> &V, int i, int j, bool left) {
    if (V[i]==NULL) {
        V[i] = new BinaryTreeNode(i);
    }
    if (V[j]==NULL) {
        V[j] = new BinaryTreeNode(j);
    }
    if (left) {
        V[i]->left = V[j];
    } else {
        V[i]->right = V[j];
    }
}

pair<int,int> calculateDiameterInBinaryTree(BinaryTreeNode* node) {
    if (node==NULL) {
        return make_pair(0,0);
    }
    pair<int,int> leftSubTreeParams = calculateDiameterInBinaryTree(node->left);
    pair<int,int> rightSubTreeParams = calculateDiameterInBinaryTree(node->right);
    return make_pair(max(leftSubTreeParams.second + rightSubTreeParams.second + 1, max(leftSubTreeParams.first, rightSubTreeParams.first)), max(leftSubTreeParams.second, rightSubTreeParams.second) + 1);
}

int main() {
    int N = 12;
    vector<BinaryTreeNode*> V(N, NULL);
    addBinaryTreeEdge(V, 0, 1, true); // true -> left node
    addBinaryTreeEdge(V, 0, 2, false); // false -> right node
    addBinaryTreeEdge(V, 1, 3, true);
    addBinaryTreeEdge(V, 1, 4, false);
    addBinaryTreeEdge(V, 2, 5, true);
    addBinaryTreeEdge(V, 2, 6, false);
    addBinaryTreeEdge(V, 4, 7, false);
    addBinaryTreeEdge(V, 6, 8, true);
    addBinaryTreeEdge(V, 7, 9, true);
    addBinaryTreeEdge(V, 7, 10, false);
    addBinaryTreeEdge(V, 8, 11, true);
    
    // depth of tree
    cout<<calculateDiameterInBinaryTree(V[0]).first;

    return 0;
}
