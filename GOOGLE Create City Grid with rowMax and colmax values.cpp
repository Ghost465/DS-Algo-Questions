interviewer : kush mishra

You are given a city where there are buildings of height (natural number)
The city is in grid form of size N*M
You are given two lists rowMax and colMax which tells you which is the max building height of that row / col


Build up the city such that sum of all heights of buildings is max, return 2d matrix cityGrid


Ex
rowMax [4,5,9], colMax [4,8,9]

Output
4 4 4
4 5 5
4 8 9


Part 1 : Solve for valid input

vector<vector<int>> createCityGridWithRowMaxAndColMaxLists(vector<int> rowMax, vector<int> colMax) {
  int N = rowMax.size();
  int M = colMax.size();
  vector<vector<int>> cityGrid(N, vector<int>(M,0));
  for(int i=0 ; i<N ; i++) {
    for(int j=0 ; j<M ; j++) {
      cityGrid = min(rowMax[i],colMax[j]);
    }
  }
  return cityGrid;
}


Part 2 : Solve for invalid input - lookup for whether our rowMax[i], colMax[j] has been used or not
if all values have been used, then its valid, otherwise invalid
(use inplace memory updation, multiply by -1 to mark whether a certain rowMax[i]/colMax[j] value has been used or not)


rowMax [4,5,9], colMax [4,8,6]
Output
4 4 4
4 5 5
4 8 6
--> 9 never gets used



vector<vector<int>> createCityGridWithRowMaxAndColMaxLists(vector<int> rowMax, vector<int> colMax) {
  int N = rowMax.size();
  int M = colMax.size();
  vector<vector<int>> cityGrid(N, vector<int>(M,0));
  for(int i=0 ; i<N ; i++) {
    for(int j=0 ; j<M ; j++) {
      if(abs(rowMax[i])<abs(colMax[j])) {
        cityGrid = abs(rowMax[i]);
        rowMax[i] = abs(rowMax[i]) * -1;
      } else if(abs(rowMax[i])>abs(colMax[j])) {
        cityGrid = abs(colMax[j]);
        colMax[j] = abs(colMax[j]) * -1;
      } else {
        cityGrid = abs(rowMax[i]);
        rowMax[i] = abs(rowMax[i]) * -1;
        colMax[j] = abs(colMax[j]) * -1;
      }
    }
  }
  for(int i=0 ; i<N ; i++) {
    if (rowMax[i]>0) {
      return vector<vector<int>>();
    }
  }
  for(int j=0 ; j<M ; j++) {
    if (colMax[j]]>0) {
      return vector<vector<int>>();
    }
  }
  return cityGrid;
}


Part 3 :
Optimize for space if sum is to be returned --> in that case cityGrid 2d array need not be used and int sum is enough

// did not code this in interview, just opinion was asked
vector<vector<int>> getCityGridBuildingsHeightSumWithRowMaxAndColMaxLists(vector<int> rowMax, vector<int> colMax) {
  int N = rowMax.size();
  int M = colMax.size();
  int sum=0;
  for(int i=0 ; i<N ; i++) {
    for(int j=0 ; j<M ; j++) {
      if(abs(rowMax[i])<abs(colMax[j])) {
        sum += abs(rowMax[i]);
        rowMax[i] = abs(rowMax[i]) * -1;
      } else if(abs(rowMax[i])>abs(colMax[j])) {
        sum += abs(colMax[j]);
        colMax[j] = abs(colMax[j]) * -1;
      } else {
        sum += abs(rowMax[i]);
        rowMax[i] = abs(rowMax[i]) * -1;
        colMax[j] = abs(colMax[j]) * -1;
      }
    }
  }
  for(int i=0 ; i<N ; i++) {
    if (rowMax[i]>0) {
      return -1;
    }
  }
  for(int j=0 ; j<M ; j++) {
    if (colMax[j]]>0) {
      return -1;
    }
  }
  return sum;
}



Follow up question -> optimize for time complexity to return sum
- how to optimize O(N*M) --> no way O(log) is used, so has to be O(N+M)

i optimize by not going to cells where i find repetitive values

How can i avoid unnecessary indexes (above ex, 4 is in row=0, col=0. Hence all other four places with 4 need not be checked)
I see that once i discard a row / column i need not go back to that row / column.

Greedy solution - use two variables left, top

Solve for rowMax[top], colMax[left]


// did not code this in interview, just opinion was asked
vector<vector<int>> getCityGridBuildingsHeightSumWithRowMaxAndColMaxLists(vector<int> rowMax, vector<int> colMax) {
  int N = rowMax.size();
  int M = colMax.size();
  int sum=0;
  int left=0;
  int top=0;
  while(top<N && left<M) {
    if(abs(rowMax[top])<abs(colMax[left])) {
      sum += abs(rowMax[top]) * (N-top);
      rowMax[i] = abs(rowMax[i]) * -1;
      top++;
    } else if (abs(rowMax[top])>abs(colMax[left])) {
      sum += abs(colMax[left]) * (M-left);
      colMax[j] = abs(colMax[j]) * -1;
      left++;
    } else {
      sum += abs(rowMax[top]) * (N-top) + abs(colMax[left]) * (M-left) - abs(rowMax[top]);
      rowMax[i] = abs(rowMax[i]) * -1;
      colMax[j] = abs(colMax[j]) * -1;
      top++;
      left++;
    }
  }
  for(int i=0 ; i<N ; i++) {
    if (rowMax[i]>0) {
      return -1;
    }
  }
  for(int j=0 ; j<M ; j++) {
    if (colMax[j]]>0) {
      return -1;
    }
  }
  return sum;
}




Verdict (SPECIAL!) : Outright told me he has given great feedback for me!! XD

