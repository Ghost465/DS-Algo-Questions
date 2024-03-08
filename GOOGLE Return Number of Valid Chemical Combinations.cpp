/*
You are given a string S and a set of valid chemical formulae for elements in the periodic table (ex. {'H', 'He', 'Li', 'Be', 'B', 'C', 'N', 'O'...}).
Max length of chemical formula is 2. ('Uuw', 'Uuv', etc not included in the set)
Return the number of ways you can split your string into substrings such that all substrings are valid chemical formulae.

Ex. S="COCO", Combinations ==> {'C'+'O'+'C'+'O', 'CO'+'C'+'O', 'CO'+'C'+'O', 'CO'+'CO'} ; Output=4
    S="RaRa", Combinations ==> {'Ra'+'Ra'} ; Output=1

Follow-up question : Return all possible formulae combinations
*/

int getNumberOfCombinations(string S, vector<string> chemicalFormulae) {
  // convert vector to set

  // it is a DP problem
  // DP[i] represents number of combinations that are possible in substring S(0...i);
  // DP[i] can be calculated by adding up DP[i-2] (if substring S(i-1, i) is valid) and DP[i-1] (if substring S(i) is valid)
  // if DP[i-1] and DP[i] are both zero, we can stop execution immediately

  // return DP[N-1];
}
