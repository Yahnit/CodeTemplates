#include<iostream>
using namespace std;
#include<vector>
#include "/Users/yahnit/Documents/stdc++.h"

// Returns true if there is a rectangle with
// 1 as corners.
bool isRectangle(const vector<vector<int> >& matrix)
{
    // finding row and column size
    int rows = matrix.size();
    if (rows == 0)
        return false;

    int columns = matrix[0].size();

    // map for storing the index of combination of 2 1's
    unordered_map<int, unordered_set<int> > table;

    // scanning from top to bottom line by line
    for (int i = 0; i < rows; ++i) {

     for (int j = 0; j < columns - 1; ++j) {
        for (int k = j + 1; k < columns; ++k) {

          // if found two 1's in a column
          if (matrix[i][j] == 1 &&
              matrix[i][k] == 1) {

            // check if there exists 1's in same
            // row previously then return true
            if (table.find(j) != table.end() &&
                table[j].find(k) != table[j].end())
                        return true;

            if (table.find(k) != table.end() &&
                table[k].find(j) != table[k].end())
                        return true;

            // store the indexes in hashset
            table[j].insert(k);
            table[k].insert(j);
          }
        }
      }
    }
    return false;
}

// Driver code
int main()
{
    vector<vector<int> > mat = { { 1, 0, 0, 1, 0 },
                                 { 0, 0, 1, 0, 1 },
                                 { 0, 0, 0, 1, 0 },
                                { 1, 0, 1, 0, 1 } };
    if (isRectangle(mat))
        cout << "Yes";
    else
        cout << "No";
}
