#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, maxCats, x, y, ways = 0, child;
    vector<int>* nodes;
    bool* cats;
    bool* visited;
    int* consecutiveCats;
    stack<int> dfs;

    scanf("%i%i", &n, &maxCats);
    nodes = new vector<int>[n];
    cats = new bool[n];
    visited = new bool[n];
    consecutiveCats = new int[n];
    for(int i = 0; i < n; i++) visited[i] = 0;
    for(int i = 0; i < n; i++) scanf("%i", cats+i);
    for(int i = 0; i < n - 1; i++){
        scanf("%i%i", &x, &y);
        nodes[x - 1].push_back(y - 1);
        nodes[y - 1].push_back(x - 1);
    }

    dfs.push(0);
    visited[0] = 1;
    consecutiveCats[0] = cats[0];
    while(!dfs.empty()){
        n = dfs.top();
        dfs.pop();
        if(nodes[n].size() == 1 && n != 0) ways++;
        for(int i = 0; i < nodes[n].size(); i++) {
            child = nodes[n][i];
            consecutiveCats[child] = cats[child] ? consecutiveCats[n] + 1 : 0;
            if(consecutiveCats[child] <= maxCats && !visited[child]) dfs.push(child);
            visited[child] = 1;
        }
    }
    printf("%i\n", ways);
}
