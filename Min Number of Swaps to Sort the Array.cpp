/*
Given an array of N distinct elements, find the minimum number of swaps required to sort the array.

Examples: 

Input: {4, 3, 2, 1}
Output: 2
*/

void solution1() {
    vector<int> A = {1,5,4,3,2};
    for(int i=0 ; i<A.size() ; i++){
        A[i]--;
    }
    int countSwaps = 0;
    for(int i=0 ; i<A.size() ; i++){
        if (A[i]!=-1){
            int j=i;
            int elementsInDisjointSet = 0;
            while(j!=i || A[j]!=-1){
                int temp = j;
                j = A[j];
                A[temp]=-1;
                elementsInDisjointSet++;
            }
            countSwaps+=(elementsInDisjointSet-1);
        }
    }
    cout<<countSwaps<<endl;
}
