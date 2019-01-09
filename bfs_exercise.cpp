#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, x, a, b, sol = 0;
    queue<int> bfsqueue;
    pair<vector<int>, pair<int, bool>>* tree;
    scanf("%i", &N);
    tree = new pair<vector<int>, pair<int, bool>>[N+1];
    for(int i = 0; i < N-1; i++){
        scanf("%i%i", &a, &b);
        tree[a].first.push_back(b);
        tree[a].second.second = 0;
        tree[b].first.push_back(a);
        tree[b].second.second = 0;
    }
    scanf("%i", &x);
    tree[1].second.first = 1;
    bfsqueue.push(1);
    tree[1].second.second = 1;
    while(!bfsqueue.empty()) {
        N = bfsqueue.front();
        bfsqueue.pop();
        for(int i = 0; i < tree[N].first.size(); i++) {
            if(!tree[tree[N].first[i]].second.second) {
                tree[tree[N].first[i]].second.second = 1;
                tree[tree[N].first[i]].second.first = tree[N].second.first + 1;
                bfsqueue.push(tree[N].first[i]);
                if(tree[tree[N].first[i]].second.first == x) ++sol;
            }
        }
    }
    printf("%i\n", sol);
}
