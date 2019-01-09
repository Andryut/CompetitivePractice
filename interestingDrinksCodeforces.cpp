#include <bits/stdc++.h>

#define ll long long

using namespace std;

int solve(ll value, int* a, int n){
    int start = 0, finish = n-1, mid;
    if(value >= a[finish]) return n;
    if(value < a[start]) return 0;
    while(finish - start > 1) {
        mid = start + (finish - start)/2;
        if(a[mid] <= value) start = mid;
        else if(a[mid] > value) finish = mid;
    }
    if(a[finish] <= value) return finish + 1;
    else return start + 1;
}

int main(){
    ll b;
    int *a, *out, n, m;
    scanf("%i", &n);
    a = new int[n];
    for(int i = 0; i < n; i++) scanf("%i", a + i);
    scanf("%i", &m);
    out = new int[m];
    sort(a, a+n);
    for(int i = 0; i < m; i++){
        cin >> b;
        out[i] = solve(b, a, n);
    }
    for(int i = 0; i < m; i++) printf("%i\n", out[i]);
}
