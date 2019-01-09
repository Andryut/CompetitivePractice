#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>* graph, int x, int n){
    stack<int> s;
    stack<int> visited;
    vector<bool> visited_elements (n);
    int node;
    s.push(x);
    while(!s.empty()) {
        node = s.top();
        s.pop();
        if (!visited_elements[node]) {
            visited.push(node);
            visited_elements[node] = 1;
            for (int i = 0; i < graph[node].size(); i++) {
                s.push(graph[node][i]);
            }
        }
    }
    return visited.size();
}

void fill_graph(vector<int>* graph, int m){
    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        if(a != b){
            graph[a - 1].push_back(b - 1);
            graph[--b].push_back(--a);
        }else{
            graph[--a].push_back(--b);
        }
    }
}

int main(){
    int n, m, x, s;
    scanf("%d%d", &n, &m);
    vector<int>* graph = new vector<int> [n];
    fill_graph(graph, m);
    scanf("%d", &x);
    s = solve(graph, --x, n);
    s = n - s;
    printf("%d\n", s);
}
