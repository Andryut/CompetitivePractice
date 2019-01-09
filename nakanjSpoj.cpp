#include <bits/stdc++.h>

using namespace std;

bool isValidPlace(int x, int y){
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main() {
    int T, min_moves, startCol, startRow, destinationCol, destinationRow;
    bool* visited = new bool[64];
    int* levels = new int[64];
    char charStartRow, charDestinationRow;
    queue<pair<int, int>> bfsqueue;
    pair<int, int> actual;
    pair<int, int>* mask = new pair<int, int>[8];
    mask[0] = pair<int, int>(-2, 1);
    mask[1] = pair<int, int>(-2, -1);
    mask[2] = pair<int, int>(2, 1);
    mask[3] = pair<int, int>(2, -1);
    mask[4] = pair<int, int>(1, -2);
    mask[5] = pair<int, int>(-1, -2);
    mask[6] = pair<int, int>(1, 2);
    mask[7] = pair<int, int>(-1, 2);
    scanf("%i", &T);
    for(int i = 0; i<T; i++){
        for(int j = 0; j < 64; j++) visited[j] = 0;
        min_moves = 0;
        cin.ignore();
        scanf("%c%i", &charStartRow, &startCol);
        cin.ignore();
        scanf("%c%i", &charDestinationRow, &destinationCol);
        startCol--;
        destinationCol--;
        startRow = (int) charStartRow - 'a';
        destinationRow = (int) charDestinationRow - 'a';
        bfsqueue.push(pair<int, int>(startRow, startCol));
        visited[startRow*8 + startCol] = 1;
        levels[startRow*8 + startCol] = 0;
        while(!bfsqueue.empty()) {
            actual = bfsqueue.front();
            bfsqueue.pop();
            for (int k = 0; k < 8; k++){
                if (isValidPlace(actual.first+mask[k].first, actual.second+mask[k].second) && !visited[(actual.first+mask[k].first)*8+actual.second+mask[k].second]){
                    bfsqueue.push(pair<int, int>(actual.first+mask[k].first, actual.second+mask[k].second));
                    visited[(actual.first+mask[k].first)*8+actual.second+mask[k].second] = 1;
                    levels[(actual.first+mask[k].first)*8+actual.second+mask[k].second] = levels[actual.first*8+actual.second] + 1;
                    if(actual.first+mask[k].first == destinationRow && actual.second+mask[k].second == destinationCol){
                        bfsqueue = queue<pair<int, int>>();
                        min_moves = levels[(actual.first+mask[k].first)*8+actual.second+mask[k].second];
                        break;
                    }
                }
            }
        }
        printf("%i\n", min_moves);
    }
}
