/*
Given an unsorted array arr[] with both positive and negative elements, the task is to find the smallest positive number missing from the array. (Consider duplicates as well)
Input:  arr[] = { 2, 3, -7, 6, 8, 1, -10, 15 }
Output: 4



{ 1, 2, -7, 5, 7, 0, -10, 14 }

{ 2,1, -7, 5, 7, 0, -10, 14 }

{ -7,1, 2, 5, 7, 0, -10, 14 }

{ 0,1, 2, -7, 14, 5, -10, 7 }

*/

bool indexNotMatchesValue(vector<int> &A, int idx){
    return (idx!=A[idx]);
}

bool isInRange(int N, int a){
    return (a>=0 && a<N);
}

void swapElements(vector<int> &A, int idx1, int idx2){
    A[idx1] = A[idx2] - A[idx1] + (A[idx2] = A[idx1]);
}

bool isValueAlreadyPresentInPlace(vector<int> &A, int j) {
    return A[j]==A[A[j]];
}

void solution2() {
    vector<int> A = {3, 3, 3, 6, 8, 2, 7, 5};
    int N=A.size();
    for(int i=0 ; i<A.size() ; i++){
        A[i]--;
    }
    for(int i=0 ; i<A.size() ; i++){
        int j=i;
        while(isInRange(N-1,A[j]) && indexNotMatchesValue(A, j) && !isValueAlreadyPresentInPlace(A, j))
        {
            swapElements(A, j, A[j]);
        }
    }
    for(int i=0 ; i<N ; i++){
        if (indexNotMatchesValue(A, i)) {
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<N+1<<endl;
    return;
}
