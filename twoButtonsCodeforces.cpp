#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    int* colors = new int[2];
    int* visited = new int[20001];
    pair<int, int> actual;
    queue<pair<int, int>> bfs;
    for(int i = 0; i < 20001; i++) *(visited + i) = 0;
    scanf("%i%i", &n, &m);
    visited[n] = 1;
    bfs.push(pair<int, int>(n, 0));
    while(!bfs.empty()) {
        actual = bfs.front();
        bfs.pop();
        colors[0] = actual.first * 2;
        colors[1] = actual.first - 1;
        for(int i = 0; i < 2; i++){
            if(colors[i] == m) {
                bfs = queue<pair<int, int>>();
                printf("%i\n", actual.second + 1);
                break;
            }else if(colors[i] > 0 && colors[i] < 20001 && !visited[colors[i]]) {
                bfs.push(pair<int, int>(colors[i], actual.second + 1));
                visited[colors[i]] = 1;
            }
        }
    }
}
