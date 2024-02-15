/*
(Like a Rummy Game)

There are 3 colors of tiles. Each tile has a number 1-9 on it. So the 27-tile set makes a deck. There are 4 decks. (Total = 108 tiles)
Tile Colors = {Red, Black, Green}

The tiles could be grouped together in patterns
Types of patterns :
1. The three tiles are identical (R2, R2, R2)
2. The three tiles are of same color and sequential (R2, R3, R4). Sequence cannot be overlapping (R8, R9, R1 is not a pattern)

Help : Tile Notations - R2 denotes Red tile having num 2

A player is given 12 tiles.
A winning hand is when you exclusively and exhaustively have tiles set up in groups. That is, you have to set all tiles in groups of 3.
Exclusive - A tile cannot be part of 2 groups
Exhaustive - No tile left out

You have been given 12 tiles. You should tell if this is a winning hand. (true / false)


MY APPROACH : 

1. Split the tiles based on the 3 colors - helps reduce our problem into 3 subproblems.
Reason : We dont need to bother with dealing with combinations of 3 that we pick to have multiple colors among them.

2. Once split apart, check if the count of tiles of each color is multiple of 3 or not.
Reason : Cannot be a winning hand if we cannot be exhaustive with our tiles.

3. Sort the color list based on numbers on tile.

4. We start traversing color list from left to right.
    - Check for triplet availability.
    - If triplet not found, check flush availability.
    - If both not present, return false.



Examples that came into my mind...
1,1,1,1,2,3
1,2,2,3,3,3,4,4,5



*/

struct Tile {
  char color;
  int val;
};

int getColorBasedListIndex(char color) {
  switch(color) {
    case 'r' : return 0;
    case 'b' : return 1;
    case 'g' : return 2;
  }
  return -1;
}

bool checkForTriplet(vector<int> &list, int i) {
  return (list[i]==list[i+1] && list[i]==list[i+2]);
}

bool checkForFlush(vector<int> &list, int i) {
  int val = list[i];
  int val1 = val;
  i++;
  while(i<list.size()) {
    if (list[i]!=0) {
      if (val1+1==list[i]) {
        val1++;
      } else if (val1+1<list[i]) {
        return false;
      }
      if (val1-val==2) {
        return true;
      }
    }
    i++;
  }
  return false;
}

int isWinningHand(vector<Tile*> &playerHand) {
  int numberOfColors = 3;
  vector<vector<int>> colorBasedList(numberOfColors, vector<int>());
  for(int i=0 ; i<playerHand.size() ; i++) {
    colorBasedList[getColorBasedListIndex(playerHand[i]->color)].push_back(playerHand[i]->val);
  }
  for(int i=0 ; i<numberOfColors ; i++) {
    if (colorBasedList[i].size()%3!=0) {
      return false;
    }
    sort(colorBasedList[i].begin(), colorBasedList[i].end());

    int left=0;
    while(left<colorBasedList[i].size()) {
      bool isTripletAvailable = checkForTriplet(colorBasedList[i], left);
      if (isTripletAvailable) {
        // cross off triplet (update to 0)
        // update left (left+3)
      } else {
        bool isFlushAvailable = checkForFlush(colorBasedList[i], left);
        if (isFlushAvailable) {
          // cross off flush (update to 0)
          // update left
        } else {
          return false;
        }
      }
      
    }
  }
  return true;
}
