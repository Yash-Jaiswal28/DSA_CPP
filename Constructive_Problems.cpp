#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

int handlePieceL(const vector<int>& heights, int lowestHeight, int countLowest, int lowestIndex) {
    int minNonBaseHeight = numeric_limits<int>::max();

    for (int height : heights) {
        if (height != lowestHeight) {
            minNonBaseHeight = min(minNonBaseHeight, height);
        }
    }

    if (countLowest == 1 && heights[lowestIndex - 1] == 2) {
        return 0; // Placeholder for specific case handling
    } else if (countLowest == 1) {
        return 0; // Placeholder for specific case handling
    } else {
        return 0;
    }
}

int handlePieceJ(const vector<int>& heights, int lowestHeight, int countLowest, int lowestIndex) {
    if (countLowest == 2 && 
        (heights[lowestIndex + 1] == lowestHeight || heights[lowestIndex - 1] == lowestHeight)) {
        return 1;
    } else if (countLowest == 1) {
        int adjacentMinHeight = min(heights[lowestIndex - 1], heights[lowestIndex + 1]);
        int minNonBaseHeight = numeric_limits<int>::max();

        for (int height : heights) {
            if (height != lowestHeight) {
                minNonBaseHeight = min(minNonBaseHeight, height);
            }
        }

        return minNonBaseHeight >= adjacentMinHeight ? 1 : 0;
    } else {
        return 0;
    }
}

int handlePieceI(const vector<int>& heights, int lowestHeight, int countLowest) {
    if (countLowest == 1) {
        int minNonBaseHeight = numeric_limits<int>::max();

        for (int height : heights) {
            if (height != lowestHeight) {
                minNonBaseHeight = min(minNonBaseHeight, height);
            }
        }

        return minNonBaseHeight;
    } else {
        return 0;
    }
}

int evaluatePiece(const string& shape, const vector<int>& heights, int lowestHeight, int countLowest, int lowestIndex) {
    if (shape == "I") {
        return handlePieceI(heights, lowestHeight, countLowest);
    } else if (shape == "J") {
        return handlePieceJ(heights, lowestHeight, countLowest, lowestIndex);
    } else {
        return 0;
    }
}

string ArrayChallenge(string strArr[],int arrlength) {
    string shape = strArr[0];
    vector<int> heights;

    for (int i = 1; i < arrlength; ++i) {
        heights.push_back(stoi(strArr[i]));
    }

    int lowestHeight = *min_element(heights.begin(), heights.end());
    int countLowest = count(heights.begin(), heights.end(), lowestHeight);
    int lowestIndex = find(heights.begin(), heights.end(), lowestHeight) - heights.begin();

    if (countLowest >= 1 && countLowest < 3) {
        return to_string(evaluatePiece(shape, heights, lowestHeight, countLowest, lowestIndex));
    } else {
        return "0";
    }
}
int main(void){
  string A[] = 
}